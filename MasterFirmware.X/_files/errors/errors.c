#include <_Global_Include.h>



u8 error_id[4];
u32 error_id_u32 = 0x00;


bool slave_com_authorization   = TRUE;
bool motor_drive_authorization = TRUE;


void error_callkack_error_slaves_firmware(void);
void error_callkack_error_struct_different(void);
void error_callkack_error_com_slaves_critical(void);
void error_callkack_error_sticker_during_full_speed(void);
void error_callkack_error_no_poster_detected(void);
void error_callkack_error_extreme_tape_in_auto(void);
void error_callkack_error_start_on_extreme_band(void);
void error_callkack_error_motor_shunt(void);
void error_callkack_error_sticker_timeout_full_speed(void);
void error_callkack_error_bridge_current(void);
void error_callkack_error_com_slaves_light(void);
void error_callkack_error_eeprom(void);
void error_callkack_error_sticker_during_slope_to_docking(void);
void error_callkack_error_timeout_during_docking(void);
void error_callkack_error_many_small_errors(void);
void error_callkack_error_motor_pulses(void);
void error_callkack_error_pulses_timeout(void);
void error_callkack_error_pulses_light(void);
void error_callkack_vcc_ripple_light(void);



struct s_error error_list[ERRORS_ARRAY_COUNT] = 
    {
          // Description                               // Critique?  // Valeur   // New software reset ,
        { ERROR_NONE                                   , FALSE      , FALSE       , FALSE             ,0x00},
        { ERROR_SLAVES_FIRMWARE                        , TRUE       , FALSE       , TRUE              ,error_callkack_error_slaves_firmware},
        { ERROR_STRUCT_MOTOR_DIFFERENT                 , TRUE       , FALSE       , TRUE              ,error_callkack_error_struct_different},
        { ERROR_COMM_WITH_SLAVES_CRITICAL              , TRUE       , FALSE       , TRUE              ,error_callkack_error_com_slaves_critical},
        { ERROR_ERASABLE_BLTDR_DUMMY1                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY2                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY3                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY4                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY5                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY6                  , FALSE      , FALSE       , TRUE              ,0x00},
        { ERROR_ERASABLE_BLTDR_DUMMY7                  , FALSE      , FALSE       , TRUE              ,0x00},

        { ERROR_STICKER_DURING_FULL_SPEED              , FALSE      , FALSE       , TRUE              ,error_callkack_error_sticker_during_full_speed},     
        { ERROR_NO_POSTER_DETECTED                     , TRUE       , FALSE       , TRUE              ,error_callkack_error_no_poster_detected},
        { ERROR_EXTREME_TAPE_IN_AUTO                   , TRUE       , FALSE       , TRUE              ,error_callkack_error_extreme_tape_in_auto},
        { ERROR_INIT_START_ON_EXTREME_BAND             , TRUE       , FALSE       , TRUE              ,error_callkack_error_start_on_extreme_band},
        { ERROR_MOTOR_SHUNT                            , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_shunt},
        { ERROR_STICKER_TIMEOUT_FULL_SPEED             , TRUE       , FALSE       , TRUE              ,error_callkack_error_sticker_timeout_full_speed},
        { ERROR_BRIDGE_H_CURRENT                       , TRUE       , FALSE       , TRUE              ,error_callkack_error_bridge_current},
        { ERROR_BRIDGE_L_CURRENT                       , TRUE       , FALSE       , TRUE              ,error_callkack_error_bridge_current},      
        { ERROR_COMM_WITH_SLAVES_LIGHT                 , FALSE      , FALSE       , TRUE              ,error_callkack_error_com_slaves_light},
        { ERROR_EEPROM                                 , TRUE       , FALSE       , TRUE              ,error_callkack_error_eeprom},
        { ERROR_STICKER_DURING_SLOPE_TO_DOCKING_SPEED  , FALSE      , FALSE       , TRUE              ,error_callkack_error_sticker_during_slope_to_docking},
        { ERROR_STICKER_TIMEOUT_DURING_DOCKING_SPEED   , FALSE      , FALSE       , TRUE              ,error_callkack_error_timeout_during_docking},
        { ERROR_TOO_MANY_SMALL_ERRORS                  , TRUE       , FALSE       , TRUE              ,error_callkack_error_many_small_errors},
        { ERROR_MOTOR_PULSES                           , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_PULSES_TIMEOUT                         , FALSE      , FALSE       , TRUE              ,error_callkack_error_pulses_timeout},
        { ERROR_MOTOR_PULSES_LIGHT                     , FALSE      , FALSE       , TRUE              ,error_callkack_error_pulses_light},
        { ERROR_MOTOR_PULSES_LIGHT2                    , FALSE      , FALSE       , TRUE              ,error_callkack_error_pulses_light},
        { ERROR_MOTOR_PULSES2                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_PULSES3                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_PULSES4                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_PULSES5                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_PULSES6                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_PULSES7                          , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        
        { ERROR_MOTOR_HALL_H                           , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_HALL_L                           , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_MOTOR_HALL_H_L                         , TRUE       , FALSE       , TRUE              ,error_callkack_error_motor_pulses},
        { ERROR_VCC_RIPPLE_LIGHT                       , FALSE      , FALSE       , TRUE              ,error_callkack_vcc_ripple_light},
    };



void (*error_callback)(void);

u8 error_light[5];
// Compteur permettant de compter les erreurs légères.
u8 error_light_count;
u8 error_light_global_counter = 0x00;

// Compteur de temps
volatile u16 error_time_counter;
volatile u16 error_time_counter_led;
volatile u16 error_time_counter_raz;


// Permet de gerer le clignotement de la LED d'erreur
u8 error_led_state = 0;

// Contient l'état en cours de la SM
u8 error_sm_state;

// Flag d'erreur
u8 error_flags[ERRORS_ARRAY_COUNT];

// Ordres vers les autres SM
u8 error_order_preauto = 0;


// Type d'erreur
u8 error_type         = NO_ERROR;


u8 error_mode         = 0x00;
u8 error_direction    = 0x00;
u8 error_poster       = 0x00;
u8 error_state        = 0x00;
u16 error_pulsesH     = 0x00;
u16 error_pulsesL     = 0x00;

// Code erreur dans l'EEPROM
u8 error_code         = 0x00;


u16 error_light1_state = 0x00;
u16 error_light2_state = 0x00;

// 
u8 error_code_pending = 0x00;
u8 error_led_counter  = 0x00;


bool error_hallH;
bool error_hallL;


typedef enum
{
    SM_ERROR_IDLE,
    SM_ERROR_STOP1,
    SM_ERROR_STOP2,
    SM_ERROR_STOP3,
    SM_ERROR_STOP4,
    SM_ERROR_STOP5,
    SM_ERROR_STOP6,
    SM_ERROR_STOP7,
    SM_ERROR_STOP8,
    SM_ERROR_STOP9,
    SM_ERROR_STOP10,
    SM_ERROR_STOP11,
            
            
            
    SM_ERROR_NOP,     
            
}error_state_list;





void error_callkack_error_slaves_firmware(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_struct_different(void)
{
    motor_drive_authorization = FALSE;
}
void error_callkack_error_com_slaves_critical(void)
{
    slave_com_authorization = FALSE;
    motor_drive_authorization = FALSE;
    MCLR_SLAVE = 1;
    __delay_ms(30);
    MCLR_SLAVE = 0;     
}

void error_callkack_error_sticker_during_full_speed(void)
{
    motor_init_init_with_clear_params();
}

void error_callkack_error_no_poster_detected(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_extreme_tape_in_auto(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_start_on_extreme_band(void)
{
    
    
    
    
    
    
    motor_drive_authorization = FALSE;
}

void error_callkack_error_motor_shunt(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_sticker_timeout_full_speed(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_bridge_current(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_com_slaves_light(void)
{
    motor_init_init();
}

void error_callkack_error_eeprom(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_sticker_during_slope_to_docking(void)
{
    
    if(motor_algo_mode == AUTO_MODE)
    {
        if(error_order_preauto == 0)
        {
            error_order_preauto = 1;
        } 
    }
}

void error_callkack_error_timeout_during_docking(void)
{
    motor_init_init();
    if((motor.family == MOTOR_ASYNC_FAMILY) && (pulses_feature == FALSE) )
    {
        if(motor.enrh_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrh_speed_adjust))
        {
            motor.enrh_dock_speed_incr += motor.enrh_speed_adjust;
        }
        if(motor.enrl_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrl_speed_adjust))
        {
            motor.enrl_dock_speed_incr += motor.enrl_speed_adjust;
        }
    }
}

void error_callkack_error_many_small_errors(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_motor_pulses(void)
{
    motor_drive_authorization = FALSE;
}

void error_callkack_error_pulses_timeout(void)
{
    motor_init_init();
}

void error_callkack_error_pulses_light(void)
{
    motor_init_init();
}

void error_callkack_vcc_ripple_light(void)
{
    motor_init_init();
}

void error_init(void)
{
    u8 i=0;
    LED_DEFAULT_TRIS    = OUTPUT;
    LED_DEFAULT         = LED_OFF;
    
    motor_drive_authorization = TRUE;
    slave_com_authorization   = TRUE;
    
    for(i=0 ;i < ERRORS_ARRAY_COUNT ;i++)
    {
        error_list[i].active = FALSE;
    }
    error_light_global_counter = 0x00;
    
    error_code         = ERROR_NONE;
    error_code_pending = ERROR_NONE;
    error_light_count  = 0;  
    error_sm_state     = SM_ERROR_IDLE;
    error_type         = NO_ERROR;

    //error_mode = 0x00;
    //error_direction = 0x00;
    //error_poster = 0x00;
    //error_state = 0x00;

    timer100ms_register_variable((u16*)&error_time_counter);   
    timer100ms_register_variable((u16*)&error_time_counter_raz);      
    timer100ms_register_variable((u16*)&error_time_counter_led); 
}


void error(u8 code)
{
    u8 i=0x00;
    if(code == 0) return;
    motor_critical_drive = FALSE;
    error_code_pending = code;
    
    bool critical = error_list[code].critical;
    error_list[code].active = TRUE;

    /*if(error_list[code].callback != 0x00)
    {
        error_callback =(void *) error_list[code].callback;
        error_callback();
    }*/
    // ENREGISTREMENT DANS LA MEMOIRE 
    if(critical)
    {
        
        if(code == ERROR_INIT_START_ON_EXTREME_BAND)
        {
            if(motor.enrh_dock_speed_incr == 0 && motor.enrl_dock_speed_incr==0x00 && (motor_save_enrh_dock_speed_incr != 0 || motor_save_enrl_dock_speed_incr != 0x00))
            {
                motor.enrh_dock_speed_incr = motor_save_enrh_dock_speed_incr;
                motor.enrl_dock_speed_incr = motor_save_enrl_dock_speed_incr;
                motor_timeout_adjust_by_speed_incr();
                motor_save_enrh_dock_speed_incr = 0x00;
                motor_save_enrl_dock_speed_incr = 0x00;
                motor_init_init();
                return;
            }
        }
        
        error_mode      = motor_algo_mode;
        error_direction = motor_direction;
        error_poster    = motor_auto_poster_index;

        if(motor_algo_mode == INIT_MODE) error_state = motor_init_state;
        else if(motor_algo_mode >= PREAUTO_MODE) error_state = motor_auto_state; 
        else error_state = 0x00;
    
  
        error_pulsesH = timer_pulses_get_valueH();
        error_pulsesL = timer_pulses_get_valueL();
                    
        error_type     = CRITICAL_ERROR;
        error_sm_state = SM_ERROR_STOP1;
    }
    else
    {
        
        //error_mode      = 0x00;
        //error_direction = 0x00;
        //error_poster    = 0x00;
        //error_state     = 0x00;
        
        error_light_global_counter++;
        
        for(i=1;i<5;i++) error_light[i-1] = error_light[i];
        error_light[4] = code;
        
        eeprom_ev_write2(EEPROM_EV_ERROR_LIGHT,code);
        
        error_time_counter_raz = 18000;     
        error_light_count++;
        if(error_light_count >= 5)
        {
            error_mode      = motor_algo_mode;
            error_direction = motor_direction;
            error_poster    = motor_auto_poster_index;

            if(motor_algo_mode == INIT_MODE)         error_state = motor_init_state;
            else if(motor_algo_mode >= PREAUTO_MODE) error_state = motor_auto_state; 
            else error_state = 0x00;
            
            
            error_code_pending = ERROR_TOO_MANY_SMALL_ERRORS;
            eeprom_ev_write1(EEPROM_EV_ERROR_LIGHT_STOP);
            error_led_state = 0x00;
            error_type      = LIGHT_ERROR;
            error_sm_state  = SM_ERROR_STOP1;
            
            error_list[ERROR_TOO_MANY_SMALL_ERRORS].active = TRUE;
            if(error_list[ERROR_TOO_MANY_SMALL_ERRORS].callback != 0x00)
            {
                error_callback =(void *) error_list[ERROR_TOO_MANY_SMALL_ERRORS].callback;
                error_callback();
            }
           
        }
        else
        {
            error_code = ERROR_NONE;
            error_type = NO_ERROR;
        }
    }
    
    if(error_list[code].callback != 0x00)
    {
        error_callback =(void *) error_list[code].callback;
        error_callback();
    }
}



void error_reset_light_error(void)
{
    u8 i;
    error_light_count = 0x00;
    
    for(i=0;i<ERRORS_ARRAY_COUNT;i++)
    {
        if(error_list[i].critical == FALSE) error_list[i].active = FALSE;
    }
    
    error_light_count = 0;
    for(i=0;i<5;i++)
    {
        if(error_light[i] != 0x00) error_light_count= 1;
    }
    
    for(i=0;i<5;i++) error_light[i] = 0x00;
    
    /*if(error_code == ERROR_TOO_MANY_SMALL_ERRORS && error_light_count == 0x01)
    {
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT0);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT1);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT2);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT3);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT4);
    }*/
    
 
    error_light_count = 0x00;
    
    
    
    
    
    
    
    #ifdef DEBUG_PRINTF_ERROR
    printf("Erreurs legeres: RAZ\n");
    #endif

}

void error_start_of_manual_mode(void)
{
    
}



void error_end_of_manual_mode(void)
{
    u8 error_save = error_type;
    u8 i=0;
    error_light_count = 0x00;
    error_light_global_counter = 0x00;
    
    for(i=0;i<ERRORS_ARRAY_COUNT;i++)
    {
        error_list[i].active = FALSE;
    }
    
    error_reset_light_error();
    
    
    if(error_type != NO_ERROR)
    {
        if(error_id_u32 < 10000000) error_id_u32++;
        
        error_id[0] = (u8)(error_id_u32>>24);
        error_id[1] = (u8)(error_id_u32>>16);
        error_id[2] = (u8)(error_id_u32>>8);
        error_id[3] = (u8)(error_id_u32 & 0x00FF);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID0);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID1);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID2);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID3);
        update_error_id_u32(); 
        
        if(error_code == ERROR_TOO_MANY_SMALL_ERRORS)
        {
            
            eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT0);
            eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT1);
            eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT2);
            eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT3);
            eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT4);
        }
        
    }
    
    
    error_code         = ERROR_NONE;
    error_code_pending = ERROR_NONE;
    error_type         = NO_ERROR;
    error_sm_state     = SM_ERROR_IDLE;
    error_mode      = 0x00;
    error_direction = 0x00;
    error_poster    = 0x00;
    error_state     = 0x00;
    motor_drive_authorization = TRUE;
    slave_com_authorization   = TRUE; 
    #ifdef DEBUG_PRINTF  
    printf("Sortie du mode manuel: RAZ de toutes les erreurs \n");    
    #endif

    eeprom_var8_update(EEPROM_VAR8_ERROR); // MAJ de la variable dans l'eeprom.

    if(error_save != NO_ERROR) main_reset(S_MAIN_INIT);
    else                       main_reset(S_MAIN_PRE_PROCESS);
    
}


void error_sm(void)
{
    u8 next_state = error_sm_state;
    switch(error_sm_state)
    {
        case SM_ERROR_IDLE:
            
            break;
            
        case SM_ERROR_STOP1:
            if(motor.model != MOTOR_MODEL_UNKNOWN)
            {
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                motor_slope_run();
                next_state = SM_ERROR_STOP2;
            }
            else
            {
                next_state = SM_ERROR_STOP4;
            }
            break;
            
        case SM_ERROR_STOP2:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_slope_calc_phase(motor.error_mode.init_phase_list[0]);
                motor_slope_run();
                next_state = SM_ERROR_STOP3;   
            }
            break;      
        case SM_ERROR_STOP3:
            if(motor_slope_is_idle() == TRUE)
            {
                next_state = SM_ERROR_STOP4;
            }
            break;
            
        case SM_ERROR_STOP4:
            error_time_counter = 50;
            
            if(  (error_code_pending == ERROR_MOTOR_PULSES) ||
                 (error_code_pending == ERROR_MOTOR_PULSES2) ||
                 (error_code_pending == ERROR_MOTOR_PULSES3) ||
                 (error_code_pending == ERROR_MOTOR_PULSES4) ||
                 (error_code_pending == ERROR_MOTOR_PULSES5) ||
                 (error_code_pending == ERROR_MOTOR_PULSES6) ||
                 (error_code_pending == ERROR_MOTOR_PULSES7) ||
                 ( (error_code_pending == ERROR_TOO_MANY_SMALL_ERRORS) &&
                   (error_light[4] == ERROR_MOTOR_PULSES_LIGHT || error_light[4] == ERROR_MOTOR_PULSES_LIGHT2)   
                 )     
              )
            {
                next_state = SM_ERROR_STOP5; 
            }   
            else next_state = SM_ERROR_STOP11; 
            break;   
       
            
        case SM_ERROR_STOP5:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                error_hallH = FALSE;
                error_hallL = FALSE;
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_HALL_STATUS);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = SM_ERROR_STOP6;
            }
            break;
            
        case SM_ERROR_STOP6:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    
                    error_hallH  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    next_state = SM_ERROR_STOP7;
                }
                else
                {
                    uart_motor_protocole_release_mutex();
                    next_state  = SM_ERROR_STOP11;   
                }
            }
            break;
        
        case SM_ERROR_STOP7: 
            com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_HALL_STATUS);
            com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
            uart_motor_protocole_send_packet();
            next_state = SM_ERROR_STOP8;
            break;
            
        case SM_ERROR_STOP8:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    
                    error_hallL  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    next_state = SM_ERROR_STOP9;
                    uart_motor_protocole_release_mutex();
                }
                else
                {
                    uart_motor_protocole_release_mutex();
                    next_state  = SM_ERROR_STOP11;   
                }
            }
            break;    
       
            
        case SM_ERROR_STOP9:
            if(error_hallH && !error_hallL)
            {
                error_code_pending = ERROR_MOTOR_HALL_H;
            }
            else if(!error_hallH && error_hallL)
            {
                error_code_pending = ERROR_MOTOR_HALL_L;
            }
            else if(error_hallH && error_hallL)
            {
                error_code_pending = ERROR_MOTOR_HALL_H_L;
            }
            
            next_state = SM_ERROR_STOP11;
            
            break;
            
            
        case SM_ERROR_STOP11:
            if(error_time_counter == 0x00)
            {
                if(error_code != error_code_pending)
                {
                    error_code = error_code_pending;
                    eeprom_ev_write2(EEPROM_EV_ERROR_CRITICAL,error_code); 
                    eeprom_var8_update(EEPROM_VAR8_ERROR); 
                    
                    if(error_code == ERROR_TOO_MANY_SMALL_ERRORS)
                    {
                        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT0);
                        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT1);
                        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT2);
                        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT3);
                        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT4);
                    } 
                }
                error_led_state = 0x00;
                next_state      = SM_ERROR_NOP;   
            }
            break;   
            
        case SM_ERROR_NOP:
            
            break;
            
        
            
    }
    error_sm_state = next_state;
    
    
    
    if((error_light_count>0) &&  (error_time_counter_raz == 0x00) && error_code == ERROR_NONE)
    {
        error_reset_light_error();
    }
    
    
    if(error_type == NO_ERROR) led_default_prog = LED_OFF;
    else if(error_type == CRITICAL_ERROR)
    {
      
        
        switch(error_led_state)
        {
            case 0:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_ON;
                    error_time_counter_led = 10;
                    error_led_state = 1;
                }
                break;
                
            case 1:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_OFF;
                    error_time_counter_led = 10;
                    error_led_state = 2;
                    error_led_counter = 0x00;
                }
                break;
                
            case 2:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_ON;
                    error_time_counter_led = 3;
                    error_led_state = 3;
                }
                break;
                
            case 3:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_OFF;
                    error_time_counter_led = 3;
                    error_led_state = 4;
                }
                break;
                
            case 4:
                if(error_time_counter_led == 0x00)
                {
                    error_led_counter++;
                    if(error_led_counter >= error_code)
                    {
                        error_time_counter_led = 10;
                        error_led_state = 0;
                    }
                    else
                    {
                        error_led_state = 2;
                    }
                }
                break;
                
            
        }
        
        
    }
    else if(error_type == CRITICAL_TEMPORARY_ERROR)
    {
        
    }
    else if(error_type == LIGHT_ERROR)
    {
        switch(error_led_state)
        {
            case 0:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_ON;
                    error_time_counter_led = 3;
                    error_led_state = 1;
                }
                break;
            case 1:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_OFF;
                    error_time_counter_led = 3;
                    error_led_state = 2;
                }
                break;   
            case 2:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_ON;
                    error_time_counter_led = 3;
                    error_led_state = 3;
                }
                break;
            case 3:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_OFF;
                    error_time_counter_led = 3;
                    error_led_state = 4;
                }
                break;     
            case 4:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_ON;
                    error_time_counter_led = 3;
                    error_led_state = 5;
                }
                break;
            case 5:
                if(error_time_counter_led == 0x00)
                {
                    led_default_prog = LED_OFF;
                    error_time_counter_led = 15;
                    error_led_state = 0;
                }
                break;  
              
        } 
    }
    
#ifdef DEBUG_PRINTF_ERROR
    if(error_type != NO_ERROR)
    {
        if(error_time_counter == 0x00)
        {
           error_time_counter = 10;  
           
                 if(error_code == ERROR_STICKER_DURING_FULL_SPEED)        printf("Erreur critique : pastille pleine vitesse\n");
            else if(error_code == ERROR_NO_POSTER_DETECTED)        printf("Erreur critique : aucune affiche detectée\n");
            else if(error_code == ERROR_EXTREME_TAPE_IN_AUTO)      printf("Erreur critique : detection BM en preauto ou auto\n");
            else if(error_code == ERROR_MOTOR_SHUNT)                   printf("Erreur critique : erreur shunt moteur\n");
            else if(error_code == ERROR_STICKER_TIMEOUT_FULL_SPEED) printf("Erreur critique : timeout cellule pleine vitesse\n");
            else if(error_code == ERREUR_UART_MAITRE_ESCLAVE)            printf("Erreur critique reset: erreur de com entre le maitre et les esclaves\n");
            else if(error_code == ERROR_STICKER_DURING_SLOPE_TO_DOCKING_SPEED)  printf("Erreur legere: pastille pendant deceleration\n");
            else if(error_code == ERROR_STICKER_TIMEOUT_DURING_DOCKING_SPEED) printf("Erreur legere: timeout cellule petite vitesse\n");
        }
    }
#endif
    
    
    
}
