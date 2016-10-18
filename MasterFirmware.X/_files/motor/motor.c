#include <_Global_Include.h>


typedef enum
{
    MODE_SLOPE,
    MODE_SET_REG_PULSES,
    MODE_GET_SPEED,        
}enum_slope_function;



volatile u16 motor_save_enrh_dock_speed_incr      = 0x00;
volatile u16 motor_save_enrl_dock_speed_incr      = 0x00;
volatile u16 motor_save_timeout_init_cell_timeout;
volatile u16 motor_save_timeout_init_cell_inhib;
volatile u16 motor_save_timeout_auto_cell_timeout;
volatile u16 motor_save_timeout_auto_cell_inhib;



u8 motorh_switch = 0x00;// contient l'etat du switch du moteur haut
u8 motorl_switch = 0x00;// contient l'etat du switch du moteur bas

u8 motorh_type = 0x00;  // contient le type de moteur haut
u8 motorl_type = 0x00;  // contient le type de moteur bas



u8 motor_type_eeprom;   // type de moteur sauvegardé dans la mémoire EEPROM

//u8 motorh_shunt;
//u8 motorl_shunt;



u8 motor_direction;     // Permet de savoir dans quel sens on defile

volatile u16 motor_timer_ms = 0x00; // Compteur de temps générique pour les algo
volatile u16 motor_timer2_ms = 0x00;
volatile u16 motor_timer3_ms = 0x00;

struct struct_motor motor;

u8     motor_slope_mode;

bool   motor_slope_mode_get_speed;

bool   motor_slope_mode_pulses;
u8     motor_slope_pulses_valueH;
u8     motor_slope_pulses_valueL;
bool   motor_slope_pulses_motorH;
bool   motor_slope_pulses_motorL;
u16    motor_slope_pulses_maxH;
u16    motor_slope_pulses_maxL;

bool   motor_critical_drive = FALSE;

bool   motor_slope_force_mutex;

// Definition des états de la machine de gestion des rampes
typedef enum
{
  MOTOR_SLOPE_IDLE, 
  MOTOR_SLOPE_IDLE2,        
  MOTOR_SLOPE_WAIT_MUTEX,        
  MOTOR_SLOPE_1,
  MOTOR_SLOPE_2,
  MOTOR_SLOPE_3,
  MOTOR_FINAL_MODE_DIR_1,
  MOTOR_FINAL_MODE_DIR_2, 
  MOTOR_FINAL_MODE_DIR_3,    
          
  MOTOR_SLOPE_PULSES1,
  MOTOR_SLOPE_PULSES2,
  MOTOR_SLOPE_PULSES3,
          
  MOTOR_GET_SPEED1,
  MOTOR_GET_SPEED2,
  MOTOR_GET_SPEED3,
  
          
}enum_motor_slope_sm;


volatile u16 motorh_slope_timer_ms; // compteur de ms pour la rampe du moteur haut
volatile u16 motorl_slope_timer_ms; // compteur de ms pour la rampe du moteur bas

u8 motor_slope_state;            // etat en cours de la machine de gestion des rampes
u8 motorh_current_speed;         // vitesse actuelle du moteur haut
u8 motorl_current_speed;         // vitesse actuelle du moteur bas
u8 motorh_final_speed;           // vitesse finale du moteur haut
u8 motorl_final_speed;           // vitesse finale du moteur bas
u8 motorh_current_mode_dir;      // table de commutation actuelle du moteur haut
u8 motorl_current_mode_dir;      // table de commutation actuelle du moteur bas
u8 motorh_final_mode_dir;        // table de commutation finale du moteur haut
u8 motorl_final_mode_dir;        // table de commutation finale du moteur bas
u16 motorh_slope_time;           // durée de la rampe pour le moteur haut
u16 motorl_slope_time;           // durée de la rampe pour le moteur bas

u16 motorh_slope;
u16 motorl_slope;




double motorh_a;                 // coefficient a de la droite ax+b pour le moteur haut
u8 motorh_b;                     // coefficient b de la droite ax+b pour le moteur haut
double motorl_a;                 // coefficient a de la droite ax+b pour le moteur bas
u8 motorl_b;                     // coefficient b de la droite ax+b pour le moteur bas


void motorh_calc_axb(void);
void motorl_calc_axb(void);
void motorh_calc_time(void);
void motorl_calc_time(void);



//=========================================================================
// Function : Initialisation
// Input(s) : -
// Output   : -
//=========================================================================
void init_motor(void)
{
    u8 i = 0x00;
    u8 motorh_shunt = 0x00;
    u8 motorl_shunt = 0x00;
    
    LED_MOTOR_TRIS    = OUTPUT;
    LED_MOTOR         = LED_OFF;
    
    motor_direction = NO_DIRECTION;
    
    motor.family = MOTOR_UNKNOWN_FAMILY;
    motor.model  = MOTOR_MODEL_UNKNOWN;
    
    motorh_shunt = MOTOR_SHUNT_UNKNOWN;
    motorl_shunt = MOTOR_SHUNT_UNKNOWN;
    
    motor_critical_drive = FALSE;
    
    RELAY_TRIS     = INPUT;

    __delay_ms(10);
    
    
    #ifdef DEBUG_PRINTF  
    printf("--------------------------------------------------------\n");
    printf("Recuperation shunt moteur haut ... \n");    
    #endif
    
    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_SHUNT);
    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
    i = uart_motor_protocole_send_packet_blocking();
    if(i == UART_MOTOR_PROTOCOLE_ERROR)
    {
        error(ERROR_COMM_WITH_SLAVES_CRITICAL);
       #ifdef DEBUG_PRINTF  
       printf("Recuperation shunt moteur haut  : ERREUR \n");    
       #endif
    }
    else
    {
       motorh_shunt = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX); 
       //motorh_type ^= 0x07;
       eeprom_ev_write2(EEPROM_EV_CONFIG_MOTORH,motorh_shunt);
       #ifdef DEBUG_PRINTF  
       printf("Recuperation shunt moteur haut  : SUCCES , valeur = 0x%02x\n",motorh_type);    
       #endif
    }
    
    #ifdef DEBUG_PRINTF  
    printf("Recuperation shunt moteur bas ... \n");    
    #endif
    
    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_SHUNT);
    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
    i = uart_motor_protocole_send_packet_blocking();
    if(i == UART_MOTOR_PROTOCOLE_ERROR)
    {
        error(ERROR_COMM_WITH_SLAVES_CRITICAL);
       #ifdef DEBUG_PRINTF  
       printf("Recuperation shunt moteur bas  : ERREUR \n");    
       #endif
    }
    else
    {
       motorl_shunt = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX); 
       eeprom_ev_write2(EEPROM_EV_CONFIG_MOTORL,motorl_shunt);
       #ifdef DEBUG_PRINTF  
       printf("Recuperation shunt moteur vas  : SUCCES , valeur = 0x%02x\n",motorl_type);    
       #endif
    }
    

        

    /*if(RELAY) 
    {
        if(motorh_shunt != MOTOR_SHUNT_UNKNOWN) motorh_shunt += 0x10;
        if(motorl_shunt != MOTOR_SHUNT_UNKNOWN) motorl_shunt += 0x10;
    }*/
    /*
    motorh_shunt = MOTOR_SHUNT_BRUSHLESS_PRISMA;//MOTOR_SHUNT_BRUSHLESS_HITO;
    motorl_shunt = MOTOR_SHUNT_BRUSHLESS_PRISMA;//MOTOR_SHUNT_BRUSHLESS_HITO;
    */
    
    
    Set_Panel_Size(PANEL_SIZE_UNKNOWN);
    
    if(motorh_shunt == motorl_shunt)
    {
        
        
        
        
        if(motorh_shunt == MOTOR_SHUNT_ASYNC_ARCOMAT) 
        {
            motorh_shunt = MOTOR_SHUNT_ASYNC_ALCOM;
            motorl_shunt = MOTOR_SHUNT_ASYNC_ALCOM;
            
        }
        
        motorh_type = MOTOR_MODEL_UNKNOWN;
        motorl_type = MOTOR_MODEL_UNKNOWN;
        
        
        
        if(motorh_shunt == MOTOR_SHUNT_CC)
        {
            Set_Panel_Size(PANEL_SIZE_2M2);
            motor.family = MOTOR_CC_FAMILY;
            motor.model = MOTOR_MODEL_CC;
            motorh_type = MOTOR_MODEL_CC;
            motorl_type = MOTOR_MODEL_CC;         
        }
        if(motorh_shunt == MOTOR_SHUNT_CC_RM)
        {
            Set_Panel_Size(PANEL_SIZE_2M2);
            motor.family = MOTOR_CC_FAMILY;
            motor.model = MOTOR_MODEL_CC_RM;
            motorh_type = MOTOR_MODEL_CC_RM;
            motorl_type = MOTOR_MODEL_CC_RM;    
        }
        if(motorh_shunt == MOTOR_SHUNT_BRUSHLESS_HITO)
        {
            Set_Panel_Size(PANEL_SIZE_2M2);
            motor.family = MOTOR_BDLC_FAMILY;
            motor.model = MOTOR_MODEL_BRUSHLESS_HITO;
            motorh_type = MOTOR_MODEL_BRUSHLESS_HITO;
            motorl_type = MOTOR_MODEL_BRUSHLESS_HITO;   
        }
        if(motorh_shunt == MOTOR_SHUNT_BRUSHLESS_PRISMA)
        {
            Set_Panel_Size(PANEL_SIZE_2M2);
            motor.family = MOTOR_BDLC_FAMILY;
            motor.model = MOTOR_MODEL_BRUSHLESS_PRISMA;
            motorh_type = MOTOR_MODEL_BRUSHLESS_PRISMA;
            motorl_type = MOTOR_MODEL_BRUSHLESS_PRISMA;  
        }
        if(motorh_shunt == MOTOR_SHUNT_ASYNC_MAPUB)
        {
            Set_Panel_Size(PANEL_SIZE_8M2);
            motor.family = MOTOR_ASYNC_FAMILY;
            motor.model = MOTOR_MODEL_ASYNC_MAPUB17;
            motorh_type = MOTOR_MODEL_ASYNC_MAPUB17;
            motorl_type = MOTOR_MODEL_ASYNC_MAPUB17;  
        }
        if(motorh_shunt == MOTOR_SHUNT_ASYNC_ALCOM)
        {
            Set_Panel_Size(PANEL_SIZE_8M2);
            motor.family = MOTOR_ASYNC_FAMILY;
            motor.model = MOTOR_MODEL_ASYNC_ALCOM17;
            motorh_type = MOTOR_MODEL_ASYNC_ALCOM17;
            motorl_type = MOTOR_MODEL_ASYNC_ALCOM17;  
        }
        if(motorh_shunt == MOTOR_SHUNT_ASYNC_VENU)
        {
            Set_Panel_Size(PANEL_SIZE_8M2);
            motor.family = MOTOR_ASYNC_FAMILY;
            motor.model = MOTOR_MODEL_ASYNC_VENU17;
            motorh_type = MOTOR_MODEL_ASYNC_VENU17;
            motorl_type = MOTOR_MODEL_ASYNC_VENU17;  
        }
    }
    
    timer1ms_register_variable((u16*)&motor_timer_ms);
    timer1ms_register_variable((u16*)&motor_timer2_ms);
    timer1ms_register_variable((u16*)&motor_timer3_ms);
    timer1ms_register_variable((u16*)&motorh_slope_timer_ms);
    timer1ms_register_variable((u16*)&motorl_slope_timer_ms);
    motorh_current_speed    = 0x00;
    motorl_current_speed    = 0x00;
    motorh_current_mode_dir = PWM_TABLE_OFF;
    motorl_current_mode_dir = PWM_TABLE_OFF;
    motor_slope_state       = MOTOR_SLOPE_IDLE;
}


void motor_timeout_save(void)
{
    motor_save_timeout_init_cell_timeout = motor.init_mode.cell_timeout_time;
    motor_save_timeout_init_cell_inhib   = motor.init_mode.cell_inhib_time_pastille;
    motor_save_timeout_auto_cell_timeout = motor.preauto_auto.cell_timeout_time;
    motor_save_timeout_auto_cell_inhib   = motor.preauto_auto.cell_inhib_time_pastille;
}

void motor_timeout_restore(void)
{
    motor.init_mode.cell_timeout_time           = motor_save_timeout_init_cell_timeout;
    motor.init_mode.cell_inhib_time_pastille    = motor_save_timeout_init_cell_inhib;
    motor.preauto_auto.cell_timeout_time        = motor_save_timeout_auto_cell_timeout;
    motor.preauto_auto.cell_inhib_time_pastille = motor_save_timeout_auto_cell_inhib; 
}

void motor_timeout_adjust_by_speed_incr(void)
{
    if(motor.enrh_dock_speed_incr != 0 || motor.enrl_dock_speed_incr != 0)
    {
        motor.init_mode.cell_timeout_time           = motor_save_timeout_init_cell_timeout * 1.3;
        motor.init_mode.cell_inhib_time_pastille    = motor_save_timeout_init_cell_inhib * 1.3;
        motor.preauto_auto.cell_timeout_time        = motor_save_timeout_auto_cell_timeout * 1.3;
        motor.preauto_auto.cell_inhib_time_pastille = motor_save_timeout_auto_cell_inhib * 1.3;    
    }
}


//=========================================================================
// Function : Retourne l'état de la machine de gestion des rampes
// Input(s) : -
// Output   : bool : TRUE = au repos
//                   FALSE = en cours de travail
//=========================================================================
bool motor_slope_is_idle(void)
{
    if(motor_slope_state == MOTOR_SLOPE_IDLE2) return TRUE;
    else return FALSE;
}


void motor_slope_get_reg_speed(void)
{
    motor_slope_mode = MODE_GET_SPEED;
    if(motor_slope_state > MOTOR_SLOPE_WAIT_MUTEX) uart_motor_protocole_release_mutex();
    motor_slope_state = MOTOR_SLOPE_WAIT_MUTEX;   
}


void motor_slope_pulses_H_L(u8 valueH,u16 max_valueH,u8 valueL,u16 max_valueL)
{
    motor_slope_mode = MODE_SET_REG_PULSES;
    motor_slope_pulses_valueH = valueH;
    motor_slope_pulses_maxH = max_valueH*10;
    motor_slope_pulses_valueH = valueL;
    motor_slope_pulses_maxL = max_valueL*10;
    
    motor_slope_pulses_motorH = TRUE;
    motor_slope_pulses_motorL = TRUE;
    
    if(motor_slope_state > MOTOR_SLOPE_WAIT_MUTEX) uart_motor_protocole_release_mutex();
    motor_slope_state = MOTOR_SLOPE_WAIT_MUTEX;   
}
void motor_slope_pulses_H(u8 value,u16 max_value)
{
    motor_slope_mode = MODE_SET_REG_PULSES;
    motor_slope_pulses_valueH = value;
    motor_slope_pulses_maxH = max_value*10;
    motor_slope_pulses_motorH = TRUE;
    //motor_slope_pulses_motorL = FALSE;
    
    if(motor_slope_state > MOTOR_SLOPE_WAIT_MUTEX) uart_motor_protocole_release_mutex();
    motor_slope_state = MOTOR_SLOPE_WAIT_MUTEX;   
}
void motor_slope_pulses_L(u8 value,u16 max_value)
{
    motor_slope_mode = MODE_SET_REG_PULSES;
    motor_slope_pulses_valueL = value;
    motor_slope_pulses_maxL = max_value*10;
    //motor_slope_pulses_motorH = FALSE;
    motor_slope_pulses_motorL = TRUE;
    
    if(motor_slope_state > MOTOR_SLOPE_WAIT_MUTEX) uart_motor_protocole_release_mutex();
    motor_slope_state = MOTOR_SLOPE_WAIT_MUTEX;   
}
//=========================================================================
// Function : Lancement d'un cycle dans la machine de gestion des rampes.
// Input(s) : -
// Output   : -
//=========================================================================
void motor_slope_run(void)
{
    motor_slope_mode = MODE_SLOPE;
    
    if(motor_slope_state > MOTOR_SLOPE_WAIT_MUTEX) uart_motor_protocole_release_mutex();
    motor_slope_state = MOTOR_SLOPE_WAIT_MUTEX;   
}

u8  motorh_get_current_mode_dir(void)
{
    return motorh_current_mode_dir;
}
u16 motorh_get_current_speed(void)
{
    return motorh_current_speed;
}
u8  motorl_get_current_mode_dir(void)
{
    return motorl_current_mode_dir;
}
u16 motorl_get_current_speed(void)
{
    return motorl_current_speed;
}

void motorh_calc_axb(void)
{
    motorh_a = (motorh_final_speed - motorh_current_speed);
    motorh_a = motorh_a/motorh_slope_time;
    motorh_b = motorh_current_speed;    
}
void motorl_calc_axb(void)
{
    motorl_a = (motorl_final_speed - motorl_current_speed);
    motorl_a = motorl_a/motorl_slope_time;
    motorl_b = motorl_current_speed;      
}



/*
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_xx_xs(u16 end_speed,u16 time)
{
    motorh_final_mode_dir       = motorh_current_mode_dir;
    motorh_slope_time           = time;
    motorh_final_speed          = end_speed;
    motorh_slope_timer_ms       = motorh_slope_time;
    motorh_calc_axb();
}
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_xx_xs(u16 end_speed,u16 time)
{
    motorl_final_mode_dir       = motorl_current_mode_dir;
    motorl_slope_time           = time;
    motorl_final_speed          = end_speed;
    motorl_slope_timer_ms       = motorl_slope_time;
    motorl_calc_axb();
}
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_speed     : vitesse de fin
//            u16               : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_mx_xs(u8 start_dir,u16 end_speed,u16 time)
{
    motorh_current_mode_dir = start_dir;
    motorh_final_mode_dir   = motorh_current_mode_dir;
    motorh_slope_time       = time;
    motorh_final_speed      = end_speed;
    motorh_slope_timer_ms   = motorh_slope_time;
    motorh_calc_axb();
}
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_mx_xs(u8 start_dir,u16 end_speed,u16 time)
{
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = motorl_current_mode_dir;
    motorl_slope_time       = time;
    motorl_final_speed      = end_speed;
    motorl_slope_timer_ms   = motorl_slope_time;
    motorl_calc_axb();
}
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_xx_ms(u8 end_dir,u16 end_speed,u16 time)
{
    motorh_final_mode_dir   = end_dir;
    motorh_slope_time       = time;
    motorh_final_speed      = end_speed;
    motorh_slope_timer_ms   = motorh_slope_time;
    motorh_calc_axb();
}
//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_xx_ms(u8 end_dir,u16 end_speed,u16 time)
{
    motorl_final_mode_dir   = end_dir;
    motorl_slope_time       = time;
    motorl_final_speed      = end_speed;
    motorl_slope_timer_ms   = motorl_slope_time;
    motorl_calc_axb();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 time)
{
    motorh_current_mode_dir = start_dir;
    motorh_final_mode_dir   = end_dir;
    motorh_slope_time       = time;
    motorh_final_speed      = end_speed; 
    motorh_slope_timer_ms   = motorh_slope_time;
    motorh_calc_axb();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 time)
{
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = end_dir;
    motorl_slope_time       = time;
    motorl_final_speed      = end_speed; 
    motorl_slope_timer_ms   = motorl_slope_time;
    motorl_calc_axb();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : Y
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 start_speed   : vitesse de départ
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 time)
{
    motorh_current_speed    = start_speed;
    motorh_current_mode_dir = start_dir;
    motorh_final_mode_dir   = end_dir;
    motorh_slope_time       = time;
    motorh_final_speed      = end_speed;
    motorh_slope_timer_ms   = motorh_slope_time;  
    motorh_calc_axb();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : Y
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 start_speed   : vitesse de départ
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 time)
{
    motorl_current_speed    = start_speed;
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = end_dir;
    motorl_slope_time       = time;
    motorl_final_speed      = end_speed;
    motorl_slope_timer_ms   = motorl_slope_time;
    motorl_calc_axb();
}
*/


void motorh_calc_time(void)
{
    if(motorh_a != 0)
    {
        double d = (motorh_final_speed - motorh_current_speed);
        d = d/motorh_a;

        motorh_slope_time     = d;
    }
    else motorh_slope_time = 0;
    motorh_slope_timer_ms = motorh_slope_time; 
}

void motorl_calc_time(void)
{
    if(motorl_a != 0)
    {
        double d = (motorl_final_speed - motorl_current_speed);
        d = d/motorl_a;

        motorl_slope_time     = d;
    }
    else motorl_slope_time = 0x0;
        
    motorl_slope_timer_ms = motorl_slope_time; 
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_xx_xs(u16 end_speed,u16 slope)
{
    
    if(motorh_current_speed < end_speed) motorh_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorh_current_speed > end_speed) motorh_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorh_a = 0;
    
    motorh_a = motorh_a/100;  
    motorh_b = motorh_current_speed;
 
    motorh_final_mode_dir       = motorh_current_mode_dir;
    motorh_final_speed          = end_speed;
    motorh_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_xx_xs(u16 end_speed,u16 slope)
{
    if(motorl_current_speed < end_speed) motorl_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorl_current_speed > end_speed) motorl_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorl_a = 0;
    motorl_a = motorl_a/100;  
    motorl_b = motorl_current_speed;
 
    motorl_final_mode_dir       = motorl_current_mode_dir;
    motorl_final_speed          = end_speed;
    motorl_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_speed     : vitesse de fin
//            u16               : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_mx_xs(u8 start_dir,u16 end_speed,u16 slope)
{
    if(motorh_current_speed < end_speed) motorh_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorh_current_speed > end_speed) motorh_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorh_a = 0;
    motorh_a = motorh_a/100;  
    motorh_b = motorh_current_speed;
    motorh_current_mode_dir = start_dir;
    motorh_final_mode_dir   = motorh_current_mode_dir;
    motorh_final_speed      = end_speed;
    motorh_calc_time();
}


//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : -
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_mx_xs(u8 start_dir,u16 end_speed,u16 slope)
{
    if(motorl_current_speed < end_speed) motorl_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorl_current_speed > end_speed) motorl_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorl_a = 0;
    motorl_a = motorl_a/100;  
    motorl_b = motorl_current_speed;
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = motorl_current_mode_dir;
    motorl_final_speed      = end_speed;
    motorl_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_xx_ms(u8 end_dir,u16 end_speed,u16 slope)
{
    if(motorh_current_speed < end_speed) motorh_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorh_current_speed > end_speed) motorh_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorh_a = 0;
    motorh_a = motorh_a/100;  
    motorh_b = motorh_current_speed;
    
    motorh_final_mode_dir   = end_dir;
    motorh_final_speed      = end_speed;
    motorh_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : - 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_xx_ms(u8 end_dir,u16 end_speed,u16 slope)
{
    if(motorl_current_speed < end_speed) motorl_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorl_current_speed > end_speed) motorl_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorl_a = 0;
    motorl_a = motorl_a/100;  
    motorl_b = motorl_current_speed;
    
    motorl_final_mode_dir   = end_dir;
    motorl_final_speed      = end_speed;
    motorl_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 slope)
{
    if(motorh_current_speed < end_speed) motorh_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorh_current_speed > end_speed) motorh_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorh_a = 0;
    motorh_a = motorh_a/100;  
    motorh_b = motorh_current_speed;
    
    motorh_current_mode_dir = start_dir;
    motorh_final_mode_dir   = end_dir;
    motorh_final_speed      = end_speed; 
    motorh_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : -
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 slope)
{
    if(motorl_current_speed < end_speed) motorl_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorl_current_speed > end_speed) motorl_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorl_a = 0;
    motorl_a = motorl_a/100;  
    motorl_b = motorl_current_speed;
    
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = end_dir;
    motorl_final_speed      = end_speed; 
    motorl_calc_time();
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur haut
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : Y
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 start_speed   : vitesse de départ
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorh_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 slope)
{
    motorh_current_speed    = start_speed;
    motorh_current_mode_dir = start_dir; 
    motorh_final_mode_dir   = end_dir;
    motorh_final_speed      = end_speed;
    
    if(motorh_current_speed < end_speed) motorh_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorh_current_speed > end_speed) motorh_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorh_a = 0;
    motorh_a = motorh_a/100;  
    motorh_b = motorh_current_speed;
    
    
    motorh_calc_time();
}


void motor_copy_phase_slope(struct struct_slope_phase *src,struct struct_slope_phase *dest,u8 new_slope)
{
   dest->brake_override = src->brake_override;
   dest->motorh_adjust_vbat = src->motorh_adjust_vbat;
   dest->motorh_mode_dir = src->motorh_mode_dir;
   dest->motorh_slope = (new_slope);
   dest->motorh_speed = src->motorh_speed;
   dest->motorl_adjust_vbat = src->motorl_adjust_vbat;
   dest->motorl_mode_dir = src->motorl_mode_dir;
   dest->motorl_slope = (new_slope);
   dest->motorl_speed = src->motorl_speed;
}
void motor_copy_phase_slope_div(struct struct_slope_phase *src,struct struct_slope_phase *dest,u8 div)
{
   dest->brake_override = src->brake_override;
   dest->motorh_adjust_vbat = src->motorh_adjust_vbat;
   dest->motorh_mode_dir = src->motorh_mode_dir;
   if(div == 0) dest->motorh_slope = 0;
   else         dest->motorh_slope = (src->motorh_slope>>div);
   dest->motorh_speed = src->motorh_speed;
   dest->motorl_adjust_vbat = src->motorl_adjust_vbat;
   dest->motorl_mode_dir = src->motorl_mode_dir;
   if(div == 0) dest->motorl_slope = 0;
   else         dest->motorl_slope = (src->motorl_slope>>div);
   dest->motorl_speed = src->motorl_speed;
}

//=========================================================================
// Function : Paramétrage d'un rampe pour le moteur bas
//            MODE DE DEPART    : Y 
//            VITESSE DE DEPART : Y
//            MODE DE FIN       : Y
//            VITESSE DE FIN    : Y
// Input(s) : u16 start_dir     : mode de départ du moteur
//            u16 start_speed   : vitesse de départ
//            u16 end_dir       : mode de fin du moteur
//            u16 end_speed     : vitesse de fin
//            u16 time          : durée de la rampe en ms
// Output   : -
//=========================================================================
void motorl_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 slope)
{
    
    
    motorl_current_speed    = start_speed;
    motorl_current_mode_dir = start_dir;
    motorl_final_mode_dir   = end_dir;
    motorl_final_speed      = end_speed;
    
    
    if(motorl_current_speed < end_speed) motorl_a = (motor.maximum_accel_slope_coeff) * slope;
    else if(motorl_current_speed > end_speed) motorl_a = (motor.maximum_decel_slope_coeff) * slope;
    else motorl_a = 0;
    motorl_a = motorl_a/100;  
    motorl_b = motorl_current_speed;
    
    motorl_calc_time();
}


bool motor_is_phase_equal(struct struct_slope_phase p1,struct struct_slope_phase p2)
{
    if( (p1.motorh_mode_dir == p2.motorh_mode_dir) &&
        (p1.motorh_slope    == p2.motorh_slope) &&
        (p1.motorh_speed    == p2.motorh_speed) &&
        (p1.motorl_mode_dir == p2.motorl_mode_dir) &&
        (p1.motorl_slope    == p2.motorl_slope) &&
        (p1.motorl_speed    == p2.motorl_speed)
      )
    {
        return TRUE;
    }else return FALSE;     
}

void motor_slope_calc_phase(struct struct_slope_phase dest_phase)
{
    volatile double s;
    double coeff;
    
    u8  motorh_c_mode  = motorh_get_current_mode_dir();
    u16 motorh_c_speed = motorh_get_current_speed();
    u8  motorl_c_mode  = motorl_get_current_mode_dir();
    u16 motorl_c_speed = motorl_get_current_speed();
    
    u8  motorh_p_mode  = dest_phase.motorh_mode_dir;
    u16 motorh_p_speed = dest_phase.motorh_speed;
    u16 motorh_p_slope = dest_phase.motorh_slope;
    u8  motorl_p_mode  = dest_phase.motorl_mode_dir;
    u16 motorl_p_speed = dest_phase.motorl_speed;
    u16 motorl_p_slope = dest_phase.motorl_slope;
    
    
    // Gestion des freins
    // Si on enroule vers le haut et que le frein du moteur bas est actif
    if(dest_phase.brake_override == FALSE)
    {
        if(motor_direction == ENRH && motorl_switch == 0x01 )
        {
            motorl_p_mode  = PWM_TABLE_OFF;
            motorl_p_speed = 0x00;
            motorl_p_slope = 0x00;
        }
        // Si on enroule vers le bas et que le frein du moteur haut est actif
        if(motor_direction == ENRL && motorh_switch == 0x01 )
        {
            motorh_p_mode  = PWM_TABLE_OFF;
            motorh_p_speed = 0x00;
            motorh_p_slope = 0x00;
        }
    }
    
   
    if((motor.family != MOTOR_ASYNC_FAMILY) && adc_vbat>motor.motor_vbat[0].vbat_value)
    {
        if(dest_phase.motorh_adjust_vbat || dest_phase.motorh_adjust_vbat)
        {
            if(adc_vbat < motor.motor_vbat[1].vbat_value)
            {
               coeff =  (adc_vbat * motor.motor_vbat[1].coeff_a) + motor.motor_vbat[1].coeff_b;
            }
            else if(adc_vbat < motor.motor_vbat[2].vbat_value)
            {
                coeff =  (adc_vbat * motor.motor_vbat[2].coeff_a) + motor.motor_vbat[2].coeff_b;
            }
            else
            {
                coeff =  (adc_vbat * motor.motor_vbat[3].coeff_a) + motor.motor_vbat[3].coeff_b;
            }

            if(dest_phase.motorh_adjust_vbat)
            {
                s = motorh_p_speed * coeff;
                motorh_p_speed = s;  
            }
            if(dest_phase.motorl_adjust_vbat)
            {  
                s = motorl_p_speed * coeff;
                motorl_p_speed = s;
            }
        }
    }
    // AJUSTEMENT VITESSES ASYNC (TELECOMMANDE)
    if(motor.family == MOTOR_ASYNC_FAMILY && cell_feature)
    {
        // Si tentative de demarrage sur pastille
        if(motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[0] ))
        {
            motorh_p_speed += (motor.enrh_dock_speed_incr);
        }
         // Si pleine vitesse (recherche BM basse) en mode init
        else if(  motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[4] ))
        {
            motorh_p_speed += (motor.enrh_dock_speed_incr);
        }
        // Si phase accostage en mode init
        else if(  motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[4] ) ||
             motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[10] ) ||
             motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[11] )
          )
        { 
            // Si la vitesse de la phase est égale à la vitesse d'accostage alors on aplique l'increment
            //if(motorh_p_speed == motor.init_mode.enrh_dock_speed) motorh_p_speed += motor.enrh_dock_speed_incr;
            motorh_p_speed += motor.enrh_dock_speed_incr;
        }
        // Si pleine vitesse (recherche BM haute) en mode init
        else if( motor_is_phase_equal(dest_phase,motor.init_mode.init_phase_list[6] ))
        {
            motorl_p_speed += (motor.enrl_dock_speed_incr);
        }
        // Si phase accostage en mode preauto ou auto (enrh)
        else if( motor_is_phase_equal(dest_phase,motor.preauto_auto.enrh_phase_list[2]) ||
                 motor_is_phase_equal(dest_phase,motor.preauto_auto.enrh_phase_list[3])
               )
        {
            // Si la vitesse de la phase est égale à la vitesse d'accostage alors on aplique l'increment
            //if(motorh_p_speed == motor.preauto_auto.enrh_dock_speed) motorh_p_speed += motor.enrh_dock_speed_incr;
            motorh_p_speed += motor.enrh_dock_speed_incr;
        }
        // Si phase accostage en mode preauto ou auto (enrl)
        else if( motor_is_phase_equal(dest_phase,motor.preauto_auto.enrl_phase_list[2]) ||
                 motor_is_phase_equal(dest_phase,motor.preauto_auto.enrl_phase_list[3])
               )
        {
            // Si la vitesse de la phase est égale à la vitesse d'accostage alors on aplique l'increment
            //if(motorl_p_speed == motor.preauto_auto.enrl_dock_speed) motorl_p_speed += motor.enrl_dock_speed_incr;
            motorl_p_speed += motor.enrl_dock_speed_incr;
        }
    }
    
    
    
    if(motor.family == MOTOR_ASYNC_FAMILY)
    {
       // moteur haut
        
        
       
       
       if(motorh_c_mode == motorh_p_mode)
       {
         motorh_slope_xx_xs(motorh_p_speed,motorh_p_slope);  
       }
       else
       {
           if(motorh_c_mode == PWM_TABLE_OFF)
           {
               if(motorh_p_mode == PWM_TABLE_OFF)
               {
                   
               }
               else
               {
                   motorh_slope_ms_ms(motorh_p_mode,motor.minimum_speed_value,motorh_p_mode,motorh_p_speed,motorh_p_slope);  
               }
           }
           else
           {
               motorh_slope_ms_ms(motorh_p_mode,motorh_c_speed,motorh_p_mode,motorh_p_speed,motorh_p_slope);
           }    
       }
       
       
       
       // moteur bas
       if(motorl_c_mode == motorl_p_mode)
       {
         motorl_slope_xx_xs(motorl_p_speed,motorl_p_slope);  
       }
       else
       {
         if(motorl_c_mode == PWM_TABLE_OFF)
           {
               if(motorl_p_mode == PWM_TABLE_OFF)
               {
                   
               }
               else
               {
                   motorl_slope_ms_ms(motorl_p_mode,motor.minimum_speed_value,motorl_p_mode,motorl_p_speed,motorl_p_slope);  
               }
               
           }
           else
           {
               motorl_slope_ms_ms(motorl_p_mode,motorl_c_speed,motorl_p_mode,motorl_p_speed,motorl_p_slope);
           }
       }
    }
    else
    {
        // moteur haut
        if(motorh_c_mode == motorh_p_mode)
        {
            motorh_slope_xx_xs(motorh_p_speed,motorh_p_slope);
        }
        else
        {
            switch(motorh_c_mode)
            {
                case PWM_TABLE_BRAKE:
                    if( (motorh_p_mode == PWM_TABLE_OFF) ||
                        (motorh_p_mode == PWM_TABLE_BRAKE))    
                    {
                       motorh_slope_xx_ms(motorh_p_mode,motorh_p_speed,motorh_p_slope);   
                    }
                    else
                    {  
                       motorh_slope_ms_ms(motorh_p_mode,motor.minimum_speed_value,motorh_p_mode,motorh_p_speed,motorh_p_slope); 
                       //motorh_slope_ms_ms(motorh_p_mode,motorh_p_speed,motorh_p_mode,motorh_p_speed,motorh_p_time); 
                    }
                    break;
                    
                case PWM_TABLE_OFF:
                        if(motorh_p_mode == PWM_TABLE_BRAKE) motorh_slope_ms_ms(motorh_p_mode,motorh_p_speed,motorh_p_mode,motorh_p_speed,motorh_p_slope); 
                        else motorh_slope_mx_xs(motorh_p_mode,motorh_p_speed,motorh_p_slope);
                    break;
                    
                default:
                    if(motorh_p_mode == PWM_TABLE_BRAKE)
                    {
                       motorh_slope_mx_ms(motorh_p_mode,motorh_p_mode,motorh_p_speed,motorh_p_slope);  
                    }
                    else if(
                             (motorh_p_mode == PWM_TABLE_OFF) || 
                             (motorh_p_mode == motorh_c_mode))    
                    {
                       motorh_slope_xx_ms(motorh_p_mode,motorh_p_speed,motorh_p_slope); 
                    }
                    else
                    {
                        if(motorh_p_slope == 0) motorh_slope_ms_ms(motorh_p_mode,motorh_p_speed,motorh_p_mode,motorh_p_speed,0);
                        else                    motorh_slope_ms_ms(motorh_p_mode,0,motorh_p_mode,motorh_p_speed,motorh_p_slope);
                        
                       
                        
                        
                    }
                    break; 
            };
        }
        
        // moteur bas
        if(motorl_c_mode == motorl_p_mode)
        {
            motorl_slope_xx_xs(motorl_p_speed,motorl_p_slope);
        }
        else
        {
            switch(motorl_c_mode)
            {
                case PWM_TABLE_BRAKE:
                    if( (motorl_p_mode == PWM_TABLE_OFF) ||
                        (motorl_p_mode == PWM_TABLE_BRAKE))    
                    {
                       motorl_slope_xx_ms(motorl_p_mode,motorl_p_speed,motorl_p_slope);   
                    }
                    else
                    {  
                       motorl_slope_ms_ms(motorl_p_mode,motor.minimum_speed_value,motorl_p_mode,motorl_p_speed,motorl_p_slope); 
                       //motorl_slope_ms_ms(motorl_p_mode,motorl_p_speed,motorl_p_mode,motorl_p_speed,motorl_p_time); 
                    }
                    break;
                    
                case PWM_TABLE_OFF:
                        if(motorl_p_mode == PWM_TABLE_BRAKE) motorl_slope_ms_ms(motorl_p_mode,motorl_p_speed,motorl_p_mode,motorl_p_speed,motorl_p_slope); 
                        else motorl_slope_mx_xs(motorl_p_mode,motorl_p_speed,motorl_p_slope);
                    break;
                    
                default:
                    if(motorl_p_mode == PWM_TABLE_BRAKE)
                    {
                       motorl_slope_mx_ms(motorl_p_mode,motorl_p_mode,motorl_p_speed,motorl_p_slope);  
                    }
                    else if(
                             (motorl_p_mode == PWM_TABLE_OFF) || 
                             (motorl_p_mode == motorl_c_mode))    
                    {
                       motorl_slope_xx_ms(motorl_p_mode,motorl_p_speed,motorl_p_slope); 
                    }
                    else
                    {
                       if(motorl_p_slope == 0) motorl_slope_ms_ms(motorl_p_mode,motorl_p_speed,motorl_p_mode,motorl_p_speed,0);  
                       else                    motorl_slope_ms_ms(motorl_p_mode,0,motorl_p_mode,motorl_p_speed,motorl_p_slope); 
                       
                       
                         
                    }
                    break; 
            };
        }
    }
}


//=========================================================================
// Function : Machine d'états de gestion des pentes
// Input(s) : -
// Output   : -
//=========================================================================
void motor_slope_sm(void)
{
    u8 next_state = motor_slope_state;
    u16 speedh,speedl;
    double temp_double;
    switch(motor_slope_state)
    {
        case MOTOR_SLOPE_IDLE:
            if(motor_slope_force_mutex)
            {
                
                slave_status_reset_sm();
                
            }
            next_state = MOTOR_SLOPE_IDLE2;
            break;
            
        case MOTOR_SLOPE_IDLE2:   
            
            break;
            
        case MOTOR_SLOPE_WAIT_MUTEX:
            if( uart_motor_protocole_is_mutex_free())
            /*if( (motor_critical_drive == FALSE && uart_motor_protocole_is_mutex_free()) ||
                 (motor_critical_drive == TRUE))*/   
            {
                
                /*if(motor_critical_drive == TRUE && uart_motor_protocole_is_mutex_free() == FALSE)
                {
                    motor_slope_force_mutex = TRUE;
                    slave_status_reset_sm();
                }
                else motor_slope_force_mutex = FALSE;*/
                
                uart_motor_protocole_take_mutex();
                
                
                if(motor_slope_mode == MODE_SLOPE)
                {
                    next_state = MOTOR_SLOPE_1;
                }
                else if(motor_slope_mode == MODE_SET_REG_PULSES)
                {
                    next_state = MOTOR_SLOPE_PULSES1;
                }
                else if(motor_slope_mode == MODE_GET_SPEED)
                {
                    next_state = MOTOR_GET_SPEED1;
                }
                else
                {
                    next_state = MOTOR_SLOPE_IDLE;
                }
                
                
            }
            break;
        
            
        case MOTOR_GET_SPEED1:
            if(uart_motor_protocole_is_ready())
            {
                
                uart_motor_protocole_take_mutex();   
                if(motor_direction == ENRH) 
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_SPEED);
                }
                else
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_SPEED);
                }
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_GET_SPEED2;
            }
            break;
            
        case MOTOR_GET_SPEED2:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();

                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                    if(motor_direction == ENRH) 
                    {
                        speedh  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1);
                        speedh <<= 8;
                        speedh  += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+2);
                        motorh_current_speed = (speedh/10);
                    }
                    else
                    {
                        speedl  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1);
                        speedl <<= 8;
                        speedl  += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+2);
                        motorl_current_speed = (speedl/10);
                    }
                    
                    next_state = MOTOR_SLOPE_IDLE; 
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    next_state = MOTOR_SLOPE_IDLE;
                }
            }
            break;
            
        case MOTOR_SLOPE_PULSES1:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_take_mutex();   
                
                if(motor_slope_pulses_motorH)
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_PULSES);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_valueH);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_maxH>>8);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_maxH & 0x00FF);
                }
                else
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_PULSES);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_valueL);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_maxL>>8);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor_slope_pulses_maxL & 0x00FF);
                }
                       
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_SLOPE_PULSES2;
                
            }
            break;
            
        case MOTOR_SLOPE_PULSES2:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                    if(motor_slope_pulses_motorH == TRUE)
                    {
                        motor_slope_pulses_motorH = FALSE;
                        if(motor_slope_pulses_motorL == TRUE)
                        {
                            next_state = MOTOR_SLOPE_PULSES1;
                        }
                        else
                        {
                            next_state = MOTOR_SLOPE_IDLE; 
                        }
                    }
                    else if(motor_slope_pulses_motorL == TRUE)
                    {
                        motor_slope_pulses_motorH = FALSE;
                        next_state = MOTOR_SLOPE_IDLE; 
                    }
                    
                    //next_state = MOTOR_SLOPE_IDLE; 
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    next_state = MOTOR_SLOPE_IDLE;
                }
            }
            break;
            
        case MOTOR_SLOPE_1:
            if(uart_motor_protocole_is_ready())
            {
                if(motorh_slope_timer_ms == 0x00) // Si la durée de la rampe du moteur haut est terminée
                {
                    
                    motorh_current_speed = motorh_final_speed; 
                    motorh_current_mode_dir = motorh_final_mode_dir;
                    // Construction du paquet
                    speedh = (motorh_current_speed*10);
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_CONTROL);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorh_current_mode_dir);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh>>8));
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh & 0x00FF));                       
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    // Envoi du paquet
                    uart_motor_protocole_send_packet();
                    // Changement d'état
                    next_state = MOTOR_SLOPE_2;
                    
                    
                }
                else // Si la rampe n'est pas encore finie
                {
                    // Calcul de la nouvelle vitesse à appliquer
                    temp_double = (double)((motorh_a)*(motorh_slope_time - motorh_slope_timer_ms));
                    temp_double += motorh_b;
                    motorh_current_speed  = temp_double;
                    
                    // Construction du paquet
                    speedh = (motorh_current_speed*10);
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_CONTROL);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorh_current_mode_dir);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh>>8));
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh & 0x00FF)); 
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    // Envoi du paquet
                    uart_motor_protocole_send_packet();
                    // Changement d'état
                    next_state = MOTOR_SLOPE_2; 
                }
            }
            break;
            
            case MOTOR_SLOPE_2:
            if(uart_motor_protocole_is_ready())
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    if(motorl_slope_timer_ms == 0x00) // Si la durée de la rampe du moteur haut est terminée
                    {

                        motorl_current_speed = motorl_final_speed; 
                        motorl_current_mode_dir = motorl_final_mode_dir;
                        // Construction du paquet
                        speedl = (motorl_current_speed*10);
                        com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_CONTROL);
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorl_current_mode_dir);
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl>>8));
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl & 0x00FF)); 
                        com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                        // Envoi du paquet
                        uart_motor_protocole_send_packet();
                        // Changement d'état
                        next_state = MOTOR_SLOPE_3; 
                    }
                    else // Si la rampe n'est pas encore finie
                    {
                        // Calcul de la nouvelle vitesse à appliquer
                        temp_double = (double)((motorl_a)*(motorl_slope_time - motorl_slope_timer_ms));
                        temp_double += motorl_b;
                        motorl_current_speed = temp_double;
                        // Construction du paquet
                        speedl = (motorl_current_speed*10);
                        com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_CONTROL);
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorl_current_mode_dir);
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl>>8));
                        com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl & 0x00FF)); 
                        com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                        // Envoi du paquet
                        uart_motor_protocole_send_packet();
                        // Changement d'état
                        next_state = MOTOR_SLOPE_3; 
                    }
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    next_state = MOTOR_SLOPE_IDLE;
                }
            }
            break;
            
        case MOTOR_SLOPE_3:
               if(uart_motor_protocole_is_ready())
               {
                   if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                   {
                       // Si les durées sont terminées et que les vitesses sont bonnes
                       if( (motorl_current_speed == motorl_final_speed) &&
                           (motorl_slope_timer_ms == 0x00) &&    
                           (motorh_current_speed == motorh_final_speed) &&
                           (motorh_slope_timer_ms == 0x00))
                       {
                           next_state =MOTOR_FINAL_MODE_DIR_1;

                       }
                       else
                       {
                           next_state = MOTOR_SLOPE_1; // Sinon on continue.
                       }
                   }
                   else
                    {
                        error(ERROR_COMM_WITH_SLAVES_LIGHT);
                        next_state = MOTOR_SLOPE_IDLE;
                    }
                           
               }
            break;
            
        case MOTOR_FINAL_MODE_DIR_1:
            if(uart_motor_protocole_is_ready())
            {     
                motorh_current_speed = motorh_final_speed; 
                motorh_current_mode_dir = motorh_final_mode_dir;
                // Construction du paquet
                speedh = (motorh_current_speed*10);
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_CONTROL);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorh_current_mode_dir);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh>>8));
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedh & 0x00FF)); 
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                // Envoi du paquet
                uart_motor_protocole_send_packet();
                // Changement d'état      
                next_state = MOTOR_FINAL_MODE_DIR_2;
            }
            break;
            
        case MOTOR_FINAL_MODE_DIR_2:
            if(uart_motor_protocole_is_ready())
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    motorl_current_speed    = motorl_final_speed; 
                    motorl_current_mode_dir = motorl_final_mode_dir;
                    // Construction du paquet
                    speedl = (motorl_current_speed*10);
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_CONTROL);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motorl_current_mode_dir);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl>>8));
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(speedl & 0x00FF)); 
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    // Envoi du paquet
                    uart_motor_protocole_send_packet();
                    // Changement d'état      
                    next_state = MOTOR_FINAL_MODE_DIR_3;
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    next_state = MOTOR_SLOPE_IDLE;
                }
            }
            break;
            
        case MOTOR_FINAL_MODE_DIR_3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                }
                next_state = MOTOR_SLOPE_IDLE; 
            }
            break;
            
            
            
            
            
    }
    motor_slope_state = next_state;
}





