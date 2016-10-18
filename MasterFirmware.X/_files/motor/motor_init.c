#include <_Global_Include.h>

/*volatile u16 dbg1;
volatile u16 dbg2;
volatile u16 dbg3;
volatile u16 dbg4;*/


#define INIT_PULSE_EXTREME_STOP        15


volatile u8 motor_init_count = 0x00;
// Contient l'état en cours de la ME
u8 motor_init_state = MOTOR_INIT_NOP;

// Permet le comptage des affiches en mode init
u8 motor_init_poster_count = 0x00;

// Variables utilisée pour inhiber la cellule
u8   motor_init_phase;

u8 motor_init_cnt1;
u8 motor_init_cnt2;

u16 motor_init_vcc_ref;


bool motor_init_cell_detection;

// Permet de compter le temps entre deux pastilles
u16 motor_init_time_between_panel = 0x00;

// Remap des timers
volatile u16 *motor_init_timer_timeout_ms;
volatile u16 *motor_init_timer_inhib_ms;
volatile u16 *motor_init_timer_tempo_ms;


// Varibles relatives à la gestion des pulses
bool motor_init_pulses_start_cell_save;
u16 motor_init_cell_pulses[5];
u16 motor_init_pulses_cnt1;
u16 motor_init_pulses_cnt2;
u16 motor_init_pulses_cnt1_save;
u16 motor_init_pulses_cnt2_save;

u16 motor_init_pulses_save;
float motor_init_max_comp_pulse_speed;
struct struct_slope_phase motor_init_phase_pulses_cell;


u16 motor_pulses_count_extreme_tape_H = 0x00;
u16 motor_pulses_count_extreme_tape_L = 0x00;
u16 motor_pulses_count_poster;
u16 motor_pulses_poster[5];

u16 motor_pulses_total_count = 0x00;

#define TEST_A_FULL   9300
#define TEST_A_STOP   9600
#define TEST_B_FULL   1300
#define TEST_B_STOP   1000


void motor_init_init_with_clear_params(void)
{
    motor.enrh_dock_speed_incr = 0;
    motor.enrl_dock_speed_incr = 0;
    motor_timeout_restore();
    
    motor_init_init();
    
    if(  (motor.model == MOTOR_MODEL_ASYNC_MAPUB110) ||
         (motor.model == MOTOR_MODEL_ASYNC_ALCOM110)
      )
    {
        if(motor.model == MOTOR_MODEL_ASYNC_MAPUB110)
        {
            motor.model = MOTOR_MODEL_ASYNC_MAPUB17;
        }
        if(motor.model == MOTOR_MODEL_ASYNC_ALCOM110)
        {
            motor.model = MOTOR_MODEL_ASYNC_ALCOM17;
        }
        
        motor_init_state = MOTOR_INIT_RESET_MOTOR_PARAMS1;
    }

}

void motor_init_init(void)
{
    uarts_init_re_de();
    
   
    motor_init_count++;
    motor_auto_scrolling    = FALSE;
    motor_critical_drive    = FALSE;
    //cell_feature            = FALSE;
    //pulses_feature          = FALSE;
    //motor_init_poster_count = 0x00;
    motor_algo_mode         = INIT_MODE;
    motor_init_state        = MOTOR_INIT_START; 
}

void motor_init_sm(void)
{
    volatile u8 *ptr_struct_motor;
    u16 i;
    u8 next_state = motor_init_state;
    u16 temp16_1,temp16_2;
    
   
    if(timer_pulses_get_valueH() > 2 ||
       timer_pulses_get_valueL() > 2) 
    {
        pulses_feature = TRUE;
    }

    
    // Surveillance de variation rapide de tension batterie.
    // Si la tension batterie augmente rapidement alors erreur légère.
    if(motor_init_state >= MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED && 
       motor_init_state <  MOTOR_INIT_FINAL)
    { 
        temp16_1 = motor_init_vcc_ref  /20;
        if( (adc_vbat > (motor_init_vcc_ref + temp16_1)) 
          )
        {
            error(ERROR_VCC_RIPPLE_LIGHT);
            return;
        }
    }
    
    switch(motor_init_state)
    {
        case MOTOR_INIT_NOP:
            
            break;
            
        case MOTOR_INIT_ERROR_STOP:
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                motor_slope_run();
                next_state = MOTOR_INIT_ERROR_STOP2;     
            break;
            
        case MOTOR_INIT_ERROR_STOP2:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_slope_calc_phase(motor.error_mode.init_phase_list[0]);
                motor_slope_run();
                next_state = MOTOR_INIT_ERROR_STOP3; 
            }
            break; 
            
        case MOTOR_INIT_ERROR_STOP3:
            if(motor_slope_is_idle() == TRUE)
            {
                next_state = MOTOR_INIT_NOP;
            }
            break;
         
        case MOTOR_INIT_RESET_MOTOR_PARAMS1:
            if(uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_TYPE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_INIT_RESET_MOTOR_PARAMS2;
            }
            break;
            
        case MOTOR_INIT_RESET_MOTOR_PARAMS2:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    ptr_struct_motor = (u8*)&motor;
                    for(i=0;i<sizeof(struct_motor);i++)
                    {
                        *(ptr_struct_motor+i) = com_packet_get_byte(&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+i);
                    }
                    next_state = MOTOR_INIT_RESET_MOTOR_PARAMS3;
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;
            
        case MOTOR_INIT_RESET_MOTOR_PARAMS3:
            if(uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_TYPE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_INIT_RESET_MOTOR_PARAMS4;
            }
            break;
            
        case MOTOR_INIT_RESET_MOTOR_PARAMS4:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    motor_timeout_save();
                    next_state = MOTOR_INIT_START;
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;    
            
            
            
        case MOTOR_INIT_START:
            
           
            if(motor_slope_is_idle() == TRUE)
            {
                motor_init_phase = 0x00;
                
                eeprom_ev_write1(EEPROM_EV_INIT_START);
                
                motor_init_timer_timeout_ms = &motor_timer_ms;
                motor_init_timer_inhib_ms = &motor_timer2_ms;
                motor_init_timer_tempo_ms = &motor_timer3_ms;
                
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                next_state = MOTOR_INIT_OFF; 

                motor_direction = NO_DIRECTION;                
            }
            break;
        
            
            
            
            
            
        case MOTOR_INIT_WAIT_BLTDR_STOP_SCROLLING:
            if(btldr_stop_scrolling == FALSE)
            {
               motor_init_init();
               return;
            }
            break;
            
        case MOTOR_INIT_OFF:
            if(btldr_stop_scrolling == TRUE)
            {
                
                //cell_feature     = FALSE;
                //pulses_feature   = FALSE;
                
                motor_slope_calc_phase(motor.error_mode.init_phase_list[0]);
                motor_slope_run();
                next_state = MOTOR_INIT_WAIT_BLTDR_STOP_SCROLLING;
            }
            else if(motor_slope_is_idle() == TRUE)
            {
                // RAZ des compteurs de pulses
                /*timer_pulses_clear();
                
                motor_init_poster_count = 0x00;
                motor_slope_calc_phase(motor.init_mode.init_phase_list[1]);
                motor_slope_run();*/
                next_state = MOTOR_INIT_SLAVE_FILTER_ON1;//MOTOR_INIT_TAUTNESS_SLOPE;    
            }
            break;
            
        case MOTOR_INIT_SLAVE_FILTER_ON1:
            if( uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x01);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_INIT_SLAVE_FILTER_ON2;
            }
            break;
            
        case MOTOR_INIT_SLAVE_FILTER_ON2:
            if(uart_motor_protocole_is_ready())
            {
                
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x01);
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    uart_motor_protocole_send_packet();
                    next_state = MOTOR_INIT_SLAVE_FILTER_ON3;
                
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;
        
        case MOTOR_INIT_SLAVE_FILTER_ON3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    timer_pulses_clear();

                    //motor_init_poster_count = 0x00;
                    motor_slope_calc_phase(motor.init_mode.init_phase_list[1]);
                    motor_slope_run();
                    next_state = MOTOR_INIT_TAUTNESS_SLOPE;    
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;
            
        // Petite rampe d'acceleration vers tension d'affiche    
        case MOTOR_INIT_TAUTNESS_SLOPE:
            if(motor_slope_is_idle() == TRUE)
            {
                cell_feature   = FALSE;
                pulses_feature = FALSE;
                motor_timeout_adjust_by_speed_incr();
                
                (*motor_init_timer_timeout_ms) = 11500;
                next_state = MOTOR_INIT_TAUTNESS_TIME;                     
            }
            break;
            
            
        // Tension d'affiche pendant quelques secondes    
        case MOTOR_INIT_TAUTNESS_TIME:
            if(btldr_stop_scrolling == TRUE)
            {
                (*motor_init_timer_timeout_ms) = 11500;
            }
            else if((*motor_init_timer_timeout_ms) == 0x00 && btldr_stop_scrolling == FALSE)
            {

                if(motor.family == MOTOR_ASYNC_FAMILY)
                {
                    // Compensation des petites vitesses en fonction de la temperature de la CTN au démarrage
                    if(adc_ctn <=0)
                    {
                        if(motor.enrh_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrh_speed_adjust))
                        {
                            motor.enrh_dock_speed_incr = ASYNC_ADJUST_SPEED_STEPS*motor.enrh_speed_adjust;
                        }
                        if(motor.enrl_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrl_speed_adjust))
                        {
                            motor.enrl_dock_speed_incr = ASYNC_ADJUST_SPEED_STEPS*motor.enrl_speed_adjust;
                        }
                    }
                    else if(adc_ctn < 10)
                    {
                        if(motor.enrh_dock_speed_incr < (1*motor.enrh_speed_adjust))
                        {
                            motor.enrh_dock_speed_incr = 1*motor.enrh_speed_adjust;
                        }
                        if(motor.enrl_dock_speed_incr < (1*motor.enrl_speed_adjust))
                        {
                            motor.enrl_dock_speed_incr = 1*motor.enrl_speed_adjust;
                        }
                    }
                }
                
                
                // Sauvegarde de la valeur d'alimentation
                motor_init_vcc_ref = adc_vbat;
                
                // RAZ des compteurs de pulses
                timer_pulses_clear();
                motor_init_pulses_cnt1 = 0x00;
                motor_init_pulses_cnt2 = 0x00;
                motor_init_pulses_cnt1_save = 0x00;
                motor_init_pulses_cnt2_save = 0x00;
                (*motor_init_timer_tempo_ms) = 30000;
                
                motor_direction = ENRH;
                if(cell == CELL_ACTIVE_LEVEL)
                {
                    motor_init_pulses_start_cell_save = FALSE;
                    motor_init_phase = 0x00;
                    motor_slope_calc_phase(motor.init_mode.init_phase_list[0]);
                    motor_slope_run();
                    next_state = MOTOR_INIT_START_ON_CELL_SLOPE;   
                }
                else
                {
                    (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                    motor_slope_calc_phase(motor.init_mode.init_phase_list[3]);
                    motor_slope_run();
                    next_state = MOTOR_INIT_ENRH_ACCEL_TO_FS_SLOPE;      
                }
            }
            break;
        
 
            
        // Levée de doute si demarrage sur cellule    
        case MOTOR_INIT_START_ON_CELL_SLOPE:
        case MOTOR_INIT_START_ON_CELL_TEMPO:    
            if(cell == CELL_INACTIVE_LEVEL)
            {
                 (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                 motor_slope_calc_phase(motor.init_mode.init_phase_list[3]);
                 motor_slope_run();
                 next_state = MOTOR_INIT_ENRH_ACCEL_TO_FS_SLOPE;  
            }
            else if(motor_slope_is_idle() == TRUE)
            {
                if(motor_init_state == MOTOR_INIT_START_ON_CELL_SLOPE)
                {
                    if(pulses_feature) (*motor_init_timer_timeout_ms) = 3000;
                    else (*motor_init_timer_timeout_ms) = 1250;
                    if(motor.enrh_dock_speed_incr != 0x00 || motor.enrl_dock_speed_incr != 0x00) (*motor_init_timer_timeout_ms) = (*motor_init_timer_timeout_ms)*1.5;
                    
                    
                    next_state = MOTOR_INIT_START_ON_CELL_TEMPO;
                }
                else
                {
                    if(pulses_feature && motor_init_pulses_start_cell_save == FALSE)
                    {
                        motor_init_pulses_start_cell_save = TRUE;
                        motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                    }
                    if((*motor_init_timer_timeout_ms) == 0x00)
                    {
                        if(cell == CELL_ACTIVE_LEVEL)
                        {
                            error(ERROR_INIT_START_ON_EXTREME_BAND);
                            if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                            return;
                        }
                        else
                        {
                            (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                            motor_slope_calc_phase(motor.init_mode.init_phase_list[3]);
                            motor_slope_run();
                            next_state = MOTOR_INIT_ENRH_ACCEL_TO_FS_SLOPE;
                        }
                    }
                }
            }
            break;
        
        // Acceleration moteur haut    
        case MOTOR_INIT_ENRH_ACCEL_TO_FS_SLOPE:
            if(cell_time > CELLULE_BANDE_MERE_MS)
            {
                motor_slope_calc_phase(motor.init_mode.init_phase_list[4]);
                motor_slope_run();
                next_state = MOTOR_INIT_ENRH_DECEL_TO_STOP_SLOPE;    
            }
            else if(motor_slope_is_idle() == TRUE)
            {
                motor_init_phase = 0x00;
                motor_init_cnt1  = 0x00;
                motor_init_cnt2  = 0x00;
                (*motor_init_timer_inhib_ms) = 2000;
                next_state = MOTOR_INIT_ENRH_FS;
            }
            break;
        
        // Pleine vitesse moteur haut (recherche bande mere basse)    
        case MOTOR_INIT_ENRH_FS:

            if((*motor_init_timer_tempo_ms) == 0x00 && pulses_feature && !cell_feature)
            {
                error(ERROR_MOTOR_PULSES2);
                if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                return;
            }
            
            
            if(pulses_feature && !cell_feature)
            {
               if((*motor_init_timer_timeout_ms) == 0x00)
               {
                    if(motor_init_phase == 0x00)
                    {
                        motor_init_phase = 0x01;
                        
                        if(motor.model != MOTOR_MODEL_BRUSHLESS_HITO)
                        {
                            motor_slope_pulses_H(motor.docking_pulses*3,(u16)(motor.maximum_speed_value/2));
                        }
                        
                        
                    }
               }
               
               
               if((*motor_init_timer_inhib_ms) == 0x00)
               {
                   (*motor_init_timer_inhib_ms) = 1000;
                   
                   
                    motor_init_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_init_pulses_cnt2 = timer_pulses_get_valueL();
                    
                    if(motor_init_pulses_cnt1 > motor_init_pulses_cnt1_save)
                    {
                        temp16_1 = motor_init_pulses_cnt1-motor_init_pulses_cnt1_save;
                    }
                    else temp16_1 = motor_init_pulses_cnt1_save-motor_init_pulses_cnt1;
                    
                    if(motor_init_pulses_cnt2 > motor_init_pulses_cnt2_save)
                    {
                        temp16_2 = motor_init_pulses_cnt2-motor_init_pulses_cnt2_save;
                    }
                    else temp16_2 = motor_init_pulses_cnt2_save-motor_init_pulses_cnt2;
                    
                    if(temp16_1 > INIT_PULSE_EXTREME_STOP)
                    {
                        
                        if(temp16_2 > INIT_PULSE_EXTREME_STOP)
                        {
                            // RAS les moteurs tournent
                            // Peut être penser à gérer un autre timer
                        }
                        else
                        {
                            motor_init_cnt2++;
                            if(motor_init_cnt2 >=10)
                            {
                               error(ERROR_MOTOR_PULSES3);
                               if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                               return;
                            }
                        }
                    }
                    else
                    {
                        
                        if(temp16_2<INIT_PULSE_EXTREME_STOP)
                        {
                            motor_init_cnt2++;
                            if(motor_init_cnt2 >= 3)
                            {
                                motor_init_phase = 0x00;
                                motor_slope_calc_phase(motor.init_mode.init_phase_list[4]);
                                motor_slope_run();
                                next_state = MOTOR_INIT_ENRH_DECEL_TO_STOP_SLOPE;  
                            }
                        }
                        else
                        {
                            motor_init_cnt2++;
                            if(motor_init_cnt2 >=10)
                            {
                               error(ERROR_MOTOR_PULSES4);
                               if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                               return;
                            }
                        }
                    }
                    
                    motor_init_pulses_cnt1_save = motor_init_pulses_cnt1;
                    motor_init_pulses_cnt2_save = motor_init_pulses_cnt2;
                   
               }
            }
            
            
            else if(!pulses_feature && !cell_feature)
            {
                if((*motor_init_timer_timeout_ms) == 0x00)
                {
                   error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                   if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                   return;    
                }
            }
            else if(cell_feature)
            {
                if((*motor_init_timer_timeout_ms) == 0x00)
                {
                   error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                   if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                   return;    
                }
                else
                {
                    if(cell_time != 0x00)
                    {
                       (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                    }

                    if(cell_time > CELLULE_BANDE_MERE_MS)
                    {
                        motor_slope_calc_phase(motor.init_mode.init_phase_list[4]);
                        motor_slope_run();
                        next_state = MOTOR_INIT_ENRH_DECEL_TO_STOP_SLOPE;    
                    }
                    else if(motor_slope_is_idle() == TRUE)  
                    {
                        if( (cell_time > CELLULE_PASTILLE_MIN_MS) &&
                            (motorh_get_current_speed() >= (motor.init_mode.init_phase_list[4].motorh_speed+motor.init_mode.init_cell_decr_speed))
                          )
                        {
                            motorh_slope_xx_xs(motorh_get_current_speed()-motor.init_mode.init_cell_decr_speed,motor.init_mode.init_cell_decr_slope);
                            motor_slope_run();
                        }
                        else if((cell_time == 0) &&
                                (motorh_get_current_speed() <= (motor.init_mode.init_phase_list[3].motorh_speed-motor.init_mode.init_cell_decr_speed))
                               )

                        {
                            motorh_slope_xx_xs(motorh_get_current_speed()+motor.init_mode.init_cell_decr_speed,motor.init_mode.init_cell_decr_slope);
                            motor_slope_run();
                        } 
                    }   
                }
            }
        break;
        
        // Deceleration moteur haut
        case MOTOR_INIT_ENRH_DECEL_TO_STOP_SLOPE:
            
            motor_init_phase = 0x00;
            motor_init_cnt1  = 0x00;
            motor_init_cnt2  = 0x00;
            
            if(motor_slope_is_idle() == TRUE)  
            {
                motor_slope_calc_phase(motor.init_mode.init_phase_list[5]);
                motor_slope_run();
                next_state = MOTOR_INIT_ENRH_STOP1;    
            }
            break;
        
        // Arret    
        case MOTOR_INIT_ENRH_STOP1:
            if(motor_slope_is_idle() == TRUE)  
            {
                
                // Sauvegarde de la valeur d'alimentation
                motor_init_vcc_ref = adc_vbat;
                
                timer_pulses_clear();
               (*motor_init_timer_timeout_ms) = 1500;
               next_state = MOTOR_INIT_ENRH_STOP2;
            }
            break;
        
        // TEMPO     
        case MOTOR_INIT_ENRH_STOP2:
            if((*motor_init_timer_timeout_ms) == 0x00)
            {
                
                motor_timeout_adjust_by_speed_incr();
                
                // RAZ du compteur d'affiches
                motor_init_poster_count = 0x00;
                // Effacement des compteurs de pulses.
                timer_pulses_clear();
                motor_init_pulses_cnt1_save = 0;
                motor_init_pulses_cnt2_save = 0;
                
                
                motor_direction = ENRL;
                motor_init_phase = 0;
                motor_init_cell_detection = FALSE;
                
                (*motor_init_timer_tempo_ms)   = 65000;
                motor_slope_calc_phase(motor.init_mode.init_phase_list[6]);
                motor_slope_run();
                motor_init_vcc_ref = adc_vbat;
                next_state = MOTOR_INIT_ENRL_ACCEL_TO_FS_SLOPE;    
                
                if(cell_feature) 
                {
                    (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
           
                }
                else if(pulses_feature && !cell_feature)
                {
                    (*motor_init_timer_timeout_ms) = 1000;
                }
                
            }
            break;
            
        // Acceleration moteur bas
        case MOTOR_INIT_ENRL_ACCEL_TO_FS_SLOPE:
            
            
            if(cell_feature)
            {
                if(motor_init_phase == 0 && (*motor_init_timer_timeout_ms) == 0x00)
                {
                    error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
                else if(motor_init_phase == 0 && cell_time == 0x00)
                {
                   motor_init_phase = 1; 
                   (*motor_init_timer_inhib_ms) = motor.init_mode.cell_inhib_time_bm; 
                }   
                else if(motor_init_phase == 1 && ((*motor_init_timer_inhib_ms) == 0x00))
                {
                    (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                    motor_init_cell_detection = TRUE;
                }
            }
            else if(pulses_feature && !cell_feature)
            {
                
            }
            
            if(motor_slope_is_idle() == TRUE)  
            {
               next_state = MOTOR_INIT_ENRL_FS; 
               
               if(motor.model == MOTOR_MODEL_BRUSHLESS_PRISMA)
               {
                   if(pulses_feature && !cell_feature) motor_slope_pulses_L(motor.docking_pulses*3,(u16)(motor.maximum_speed_value/4));
               }
               else if(motor.model == MOTOR_MODEL_BRUSHLESS_HITO)
               {
                   if(pulses_feature && !cell_feature)
                   { 
                       motor_slope_pulses_L(motor.docking_pulses*2,(u16)(motor.maximum_speed_value/2));
                       motor_slope_pulses_H(motor.docking_pulses*3,(u16)(motor.init_mode.init_phase_list[6].motorh_speed*1.15));
                   }
               } 
               else
               {
                   if(pulses_feature && !cell_feature) motor_slope_pulses_L(motor.docking_pulses*2,(u16)(motor.maximum_speed_value/3));
               }  
            }
            break;
           
        // Pleine vitesse moteur bas (comptage cellules)    
        case MOTOR_INIT_ENRL_FS:
            
            if(cell_feature)
            {
                if(motor_init_phase == 0 && (*motor_init_timer_timeout_ms) == 0x00)
                {
                    error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
                else if(motor_init_phase == 0 && cell_time == 0x00)
                {
                   motor_init_phase = 1; 
                   (*motor_init_timer_inhib_ms) = motor.init_mode.cell_inhib_time_bm; 
                }   
                else if(motor_init_phase == 1 && ((*motor_init_timer_inhib_ms) == 0x00) && (motor_init_cell_detection == FALSE))
                {
                    (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                    
                    
                    
                    motor_init_cell_detection = TRUE;
                }



                if(motor_init_cell_detection)
                {
                    if((*motor_init_timer_timeout_ms) == 0x00)
                    {
                        error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                        if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                        return;
                    }
                    if(cell_time > CELLULE_BANDE_MERE_MS)
                    {
                        motor_slope_calc_phase(motor.init_mode.init_phase_list[7]);
                        motor_slope_run();
                        next_state = MOTOR_INIT_ENRL_DECEL_TO_STOP_SLOPE;    
                    }
                    else if(motor_slope_is_idle() == TRUE)  
                    {
                        if( (cell_time > CELLULE_PASTILLE_MIN_MS) &&
                            (motorl_get_current_speed() >= (motor.init_mode.init_phase_list[7].motorl_speed+motor.init_mode.init_cell_decr_speed))
                          )
                        {
                            motorl_slope_xx_xs(motorl_get_current_speed()-motor.init_mode.init_cell_decr_speed,motor.init_mode.init_cell_decr_slope);
                            motor_slope_run();
                        }
                        else if((cell_time == 0) &&
                                (motorl_get_current_speed() <= (motor.init_mode.init_phase_list[6].motorl_speed-motor.init_mode.init_cell_decr_speed))
                               )

                        {
                            motorl_slope_xx_xs(motorl_get_current_speed()+motor.init_mode.init_cell_decr_speed,motor.init_mode.init_cell_decr_slope);
                            motor_slope_run();
                        }

                        if(cell_event && ((*motor_init_timer_inhib_ms) == 0x00))
                        {
                            cell_event = 0x0;

                            if((cell_event_time > CELLULE_PASTILLE_MIN_MS) && 
                              (cell_event_time < CELLULE_PASTILLE_MAX_MS))
                            {
                                motor_init_cell_pulses[motor_init_poster_count] = cell_pulses;
                                motor_init_poster_count++;

                                if(motor_init_poster_count ==1) motor_init_time_between_panel = 0x00;
                                else if(motor_init_poster_count ==2)
                                {
                                    motor_init_time_between_panel = (motor.init_mode.cell_timeout_time)-(*motor_init_timer_timeout_ms);                            
                                }

                                (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;   
                                (*motor_init_timer_inhib_ms)   = motor.init_mode.cell_inhib_time_pastille;
                            }           
                        }
                    }
                }
            }
            else if(pulses_feature && !cell_feature)
            {
                if((*motor_init_timer_tempo_ms) == 0x00)
                {
                    error(ERROR_MOTOR_PULSES5);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
                else if((*motor_init_timer_timeout_ms) == 0x00)
                {
                    (*motor_init_timer_timeout_ms) = 1000;
                    
                    motor_init_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_init_pulses_cnt2 = timer_pulses_get_valueL();

                    
                    if(motor_init_pulses_cnt1 > motor_init_pulses_cnt1_save)
                    {
                        temp16_1 = motor_init_pulses_cnt1-motor_init_pulses_cnt1_save;
                    }
                    else temp16_1 = motor_init_pulses_cnt1_save-motor_init_pulses_cnt1;
                    
                    if(motor_init_pulses_cnt2 > motor_init_pulses_cnt2_save)
                    {
                        temp16_2 = motor_init_pulses_cnt2-motor_init_pulses_cnt2_save;
                    }
                    else temp16_2 = motor_init_pulses_cnt2_save-motor_init_pulses_cnt2;
                    
                    
                    if(temp16_1 > INIT_PULSE_EXTREME_STOP)
                    {
                        
                        if(temp16_2 > INIT_PULSE_EXTREME_STOP)
                        {
                            // RAS les moteurs tournent
                            // Peut être penser à gérer un autre timer
                        }
                        else
                        {
                            motor_init_cnt2++;
                            if(motor_init_cnt2 >= 10)
                            {
                               error(ERROR_MOTOR_PULSES6);
                               if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                               return;
                            }
                        }
                    }
                    else
                    {
                        if(temp16_2 <INIT_PULSE_EXTREME_STOP)
                        {
                            motor_init_cnt1++;
                            if(motor_init_cnt1>=3)
                            {
                                next_state = MOTOR_INIT_ENRL_DECEL_GET_PULSES; 
                                motor_slope_get_reg_speed();
                            }
                        }
                        else
                        {
                            motor_init_cnt2++;
                            if(motor_init_cnt2 >= 10)
                            {
                               error(ERROR_MOTOR_PULSES6);
                               if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                               return;
                            }
                        }
                    }

                    motor_init_pulses_cnt1_save = motor_init_pulses_cnt1;
                    motor_init_pulses_cnt2_save = motor_init_pulses_cnt2;  
                }
            }
            break;
         
        case MOTOR_INIT_ENRL_DECEL_GET_PULSES:
            motor_init_cnt1 = 0x00;
            motor_init_cnt2 = 0x00;
            
            if(motor_slope_is_idle() == TRUE)  
            {
                motor_slope_calc_phase(motor.init_mode.init_phase_list[7]);
                motor_slope_run();
                next_state = MOTOR_INIT_ENRL_DECEL_TO_STOP_SLOPE;      
            }
            break;
            
         // Deceleration moteur bas   
         case MOTOR_INIT_ENRL_DECEL_TO_STOP_SLOPE:
            if(motor_slope_is_idle() == TRUE)  
            { 
               motor_slope_calc_phase(motor.init_mode.init_phase_list[8]);
               motor_slope_run();
               next_state = MOTOR_INIT_ENRL_STOP;    
            }
            break;
         
             
        // Arret    
        case MOTOR_INIT_ENRL_STOP:
            if(motor_slope_is_idle() == TRUE)  
            {
                // Sauvegarde de la valeur d'alimentation
                motor_init_vcc_ref = adc_vbat;

                if(pulses_feature == TRUE)
                {
                    motor_init_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_init_pulses_cnt2 = timer_pulses_get_valueL();

                    if( (motor_init_pulses_cnt1 < (motor_pulses_count_extreme_tape_H*0.8)) ||
                        (motor_init_pulses_cnt2 < (motor_pulses_count_extreme_tape_H*0.8)) ||
                        (motor_init_pulses_cnt1 < (motor_init_pulses_cnt2>>1)) ||
                        (motor_init_pulses_cnt1 > (motor_init_pulses_cnt2<<1)) ||
                        (motor_init_pulses_cnt2 < (motor_init_pulses_cnt1>>1)) ||
                        (motor_init_pulses_cnt2 > (motor_init_pulses_cnt1<<1))
                      )
                    {
                        error(ERROR_MOTOR_PULSES7);
                        if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                        return;
                    }
                    if(!cell_feature)
                    {     
                        if(motor_pulses_count_extreme_tape_H == 0x00)
                        {
                            eeprom_var16_reset(EEPROM_VAR16_PULSES_EXTREME_TAPE_H);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_EXTREME_TAPE_H);
                        }
                        if(motor_pulses_count_extreme_tape_L == 0x00)
                        {
                            eeprom_var16_reset(EEPROM_VAR16_PULSES_EXTREME_TAPE_L);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_EXTREME_TAPE_L);
                        }
                        if(motor_pulses_count_poster == 0x00)
                        {
                            eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER);
                        }

                        motor_pulses_total_count = motor_init_pulses_cnt1;
                        timer_pulses_set_globalH(0);
                        temp16_1 = motor_pulses_total_count;
                        if(temp16_1 >=motor_pulses_count_extreme_tape_H) temp16_1-=motor_pulses_count_extreme_tape_H;
                        else temp16_1 = 0x00;
                        if(temp16_1 >=motor_pulses_count_extreme_tape_L) temp16_1-=motor_pulses_count_extreme_tape_L;
                        else temp16_1 = 0x00;

                        if(motor_pulses_count_poster > 0)
                        {
                            
                            motor_init_poster_count = ((float)(temp16_1) / (float)(motor_pulses_count_poster)) + 0.5f;
                            if(motor_init_poster_count >0)  motor_init_poster_count++;     
                            else
                            {
                               if(motor_pulses_total_count >= (motor_pulses_count_extreme_tape_H*0.9)) motor_init_poster_count = 1;   
                            }
                        }
                        else
                        {
                            motor_init_poster_count = 0;
                        }
                        
                        if(motor_pulses_poster[0] == 0x0000 || motor_pulses_poster[0] == 0xFFFF)
                        {
                            motor_pulses_poster[0] = motor_pulses_count_extreme_tape_H;
                            motor_pulses_poster[1] = motor_pulses_poster[0]+(motor_pulses_count_poster*0.85);
                            motor_pulses_poster[2] = motor_pulses_poster[1]+(motor_pulses_count_poster*0.85);
                            motor_pulses_poster[3] = motor_pulses_poster[2]+(motor_pulses_count_poster*0.85);
                            motor_pulses_poster[4] = motor_pulses_poster[3]+(motor_pulses_count_poster*0.85);
                            
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER0);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER1);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER2);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER3);
                            eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER4);  
                        }
                        temp16_2 = 1;
                        for(i=0;i<motor_init_poster_count;i++)
                        {
                            if(motor_pulses_poster[i]>= motor_pulses_total_count)
                            {
                                temp16_2 = 0;
                            }
                        }
                        
                        if(temp16_2 == 0)
                        {
                            motor_pulses_poster[0] = motor_pulses_count_extreme_tape_H;
                            motor_pulses_poster[1] = motor_pulses_poster[0]+motor_pulses_count_poster*0.85;
                            motor_pulses_poster[2] = motor_pulses_poster[1]+motor_pulses_count_poster*0.85;
                            motor_pulses_poster[3] = motor_pulses_poster[2]+motor_pulses_count_poster*0.85;
                            motor_pulses_poster[4] = motor_pulses_poster[3]+motor_pulses_count_poster*0.85;
                        }
                    }   
                }   
                // Effacement des compteurs de pulses.
                timer_pulses_clear();
                
                motor_init_pulses_cnt1 = 0x00;
                motor_init_phase = 0x00;
               
                (*motor_init_timer_timeout_ms) = 250;
                (*motor_init_timer_tempo_ms)   = 1500;
                next_state = MOTOR_INIT_BLINK_LED;
                
                for(i=0;i<motor_init_poster_count;i++)
                {
                    poster[i].cell_pulses = motor_init_cell_pulses[motor_init_poster_count-1-i];
                } 
            }
            break;
       
        case MOTOR_INIT_BLINK_LED:
            if( (cell_feature && (*motor_init_timer_tempo_ms) == 0x00) ||
                (!cell_feature && pulses_feature))
            {
                if(motor.family == MOTOR_ASYNC_FAMILY && !pulses_feature)
                {
                    if(motor.model == MOTOR_MODEL_ASYNC_MAPUB17)
                    {
                        if(motor_init_time_between_panel > motor.init_mode.init_cell_between_time)
                        {
                            motor.model = MOTOR_MODEL_ASYNC_MAPUB110;
                            next_state = MOTOR_INIT_NEW_STRUCT_WAIT_MUTEX;
                        }
                        else
                        {
                            next_state = MOTOR_INIT_TEST_POSTER_COUNT;
                        }
                    }
                    else if(motor.model == MOTOR_MODEL_ASYNC_ALCOM17)
                    {
                        if(motor_init_time_between_panel > motor.init_mode.init_cell_between_time)
                        {
                            motor.model = MOTOR_MODEL_ASYNC_ALCOM110;
                            next_state = MOTOR_INIT_NEW_STRUCT_WAIT_MUTEX;
                        }
                        else
                        {
                           next_state = MOTOR_INIT_TEST_POSTER_COUNT;
                        }
                    }
                    else
                    {
                        next_state = MOTOR_INIT_TEST_POSTER_COUNT;
                    }
                    
                }
                else next_state = MOTOR_INIT_TEST_POSTER_COUNT; 
            }           
            break;
            
            
        case MOTOR_INIT_NEW_STRUCT_WAIT_MUTEX:
            if(uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_TYPE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_INIT_NEW_STRUCT;
            }
            break;
            
        case MOTOR_INIT_NEW_STRUCT:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    ptr_struct_motor = (u8*)&motor;
                    for(i=0;i<sizeof(struct_motor);i++)
                    {
                        *(ptr_struct_motor+i) = com_packet_get_byte(&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+i);
                    }
                    next_state = MOTOR_INIT_TEST_POSTER_COUNT;
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
        break;

        case MOTOR_INIT_TEST_POSTER_COUNT:
            if(motor_init_poster_count >0)
            {
                /*motor_direction = ENRH;
                if(cell_feature)
                {
                    if(motor.family == MOTOR_ASYNC_FAMILY)
                    {
                        (*motor_init_timer_timeout_ms) = (motor.init_mode.cell_timeout_time*2);  
                    }
                    else
                    {
                        (*motor_init_timer_timeout_ms) = (motor.init_mode.cell_timeout_time);  
                    }
                    next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED;
                }
                else if(pulses_feature && !cell_feature)
                {
                    timer_pulses_clear();
                    (*motor_init_timer_timeout_ms) = 2000;
                    (*motor_init_timer_tempo_ms) = (motor.init_mode.cell_timeout_time*2); 
                    next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED;
                }
                motor_init_phase = 0;
                motor_init_cell_detection = FALSE;
                motor_slope_calc_phase(motor.init_mode.init_phase_list[9]);
                motor_slope_run();*/
                
                next_state = MOTOR_INIT_SLAVE_FILTER_OFF1;
       
            }
            else
            {
                error(ERROR_NO_POSTER_DETECTED);
                if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                return;
            }
            break;
            
        
            
        case MOTOR_INIT_SLAVE_FILTER_OFF1:
            if( uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x00);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_INIT_SLAVE_FILTER_OFF2;
            }
            break;
            
        case MOTOR_INIT_SLAVE_FILTER_OFF2:
            if(uart_motor_protocole_is_ready())
            {
                
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x00);
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    uart_motor_protocole_send_packet();
                    next_state = MOTOR_INIT_SLAVE_FILTER_OFF3;
                
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;
        
        case MOTOR_INIT_SLAVE_FILTER_OFF3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    motor_direction = ENRH;
                    if(cell_feature)
                    {
                        if(motor.family == MOTOR_ASYNC_FAMILY)
                        {
                            (*motor_init_timer_timeout_ms) = (motor.init_mode.cell_timeout_time*2);  
                        }
                        else
                        {
                            (*motor_init_timer_timeout_ms) = (motor.init_mode.cell_timeout_time);  
                        }
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED;
                    }
                    else if(pulses_feature && !cell_feature)
                    {
                        timer_pulses_clear();
                        (*motor_init_timer_timeout_ms) = 2000;
                        (*motor_init_timer_tempo_ms) = (motor.init_mode.cell_timeout_time*2); 
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED;
                    }
                    motor_init_phase = 0;
                    motor_init_cell_detection = FALSE;
                    motor_slope_calc_phase(motor.init_mode.init_phase_list[9]);
                    motor_slope_run();
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
            }
            break;
            
       
        case MOTOR_INIT_FIRST_PULSES1:
            if(motor_slope_is_idle() == TRUE)  
            {
                motor_critical_drive = FALSE;
                motor_init_phase = 0x00;
                next_state = MOTOR_INIT_FIRST_PULSES2;
            }
            break;
         
        case MOTOR_INIT_FIRST_PULSES2:
            if((*motor_init_timer_timeout_ms) == 0x00)
            {
                if(motor_init_phase == 0x01)
                { 
                    motor_init_phase = 0x00;
                    motor_pulses_poster[0] = timer_pulses_get_globalH();
                    eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER0);
                }
                else
                {
                    
                }
                next_state = MOTOR_INIT_ANALYSE_BRAKE;
            }
            
            if(motor_manu_adjust_pulses)
            {
                (*motor_init_timer_timeout_ms) = 3500;
                motor_init_phase = 0x01;
            }
            break;
            
        case MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED:
        case MOTOR_INIT_FIRST_POSTER_FULL_SPEED:  
        case MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED1:
        case MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED2:    
        case MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED3:
            
            if(cell_feature)
            {
                if(motor_init_phase == 0 && (*motor_init_timer_timeout_ms) == 0x00)
                {
                    error(ERROR_STICKER_TIMEOUT_FULL_SPEED);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
                else if(motor_init_phase == 0 && cell_time == 0x00)
                {
                    cell_reset();
                    motor_init_phase = 1; 
                   (*motor_init_timer_inhib_ms) = motor.init_mode.cell_inhib_time_bm; 
                }   
                else if(motor_init_phase == 1 && ((*motor_init_timer_inhib_ms) == 0x00))
                {
                    
                    (*motor_init_timer_timeout_ms) = motor.init_mode.cell_timeout_time;
                     motor_init_cell_detection = TRUE;
                }


                if(motor_init_phase == 1)
                {
                    if(cell_time > (CELLULE_BANDE_MERE_MS))
                    {
                        error(ERROR_EXTREME_TAPE_IN_AUTO);
                        if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                        return;
                    }
                }
                
                
                if(motor_init_cell_detection)
                {
                    if((cell_event == TRUE))
                    {
                        cell_event = FALSE;
                        if((cell_event_time > CELLULE_PASTILLE_MIN_MS) && 
                                      (cell_event_time < (CELLULE_BANDE_MERE_MS*2)))
                        {
                            error(ERROR_STICKER_DURING_FULL_SPEED);    
                            if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                            return;
                        }   
                    }  
                }


                if(motor_slope_is_idle() == TRUE)  
                {
                    if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED)
                    {
                        (*motor_init_timer_tempo_ms) = motor.init_mode.init_full_speed_time;

                        //motor_slope_calc_phase(motor.init_mode.init_phase_list[10]);
                        //motor_slope_run();
                        next_state = MOTOR_INIT_FIRST_POSTER_FULL_SPEED; 
                    }
                    else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_FULL_SPEED && ((*motor_init_timer_tempo_ms) == 0x00))
                    {
                        motor_slope_calc_phase(motor.init_mode.init_phase_list[10]);
                        motor_slope_run();

                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED1; 
                    } 
                    else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED1)
                    {
                        motor_slope_calc_phase(motor.init_mode.init_phase_list[11]);
                        motor_slope_run();
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED2;
                    }
                    else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED2)
                    {
                        if(pulses_feature)
                        {
                            //dbg1 = timer_pulses_get_valueH();
                            next_state = MOTOR_INIT_FIRST_POSTER_SET_SLAVE_DOCKING_PULSES1;
                            (*motor_init_timer_timeout_ms)  = (motor.init_mode.cell_timeout_time*2);
                        }
                        else
                        {
                            (*motor_init_timer_timeout_ms)  = motor.init_mode.cell_timeout_time;
                            next_state = MOTOR_INIT_FIRST_POSTER_DOCKING_SPEED;
                        }
                    }
                }
            }
            else if(pulses_feature && !cell_feature)
            {
                
                if((*motor_init_timer_tempo_ms) == 0x00)
                {
                    error(ERROR_PULSES_TIMEOUT);
                    if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                    return;
                }
                
                if((*motor_init_timer_timeout_ms) == 0x00)
                {
                    (*motor_init_timer_timeout_ms) = 1000;
                    // Comparaison des pulses des deux moteurs
                    motor_init_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_init_pulses_cnt2 = timer_pulses_get_valueL();

                  
                    if( (motor_init_pulses_cnt1 == 0x00) || 
                        (motor_init_pulses_cnt2 == 0x00) || 
                        (motor_init_pulses_cnt1 < (motor_init_pulses_cnt2>>1)) ||
                        (motor_init_pulses_cnt1 > (motor_init_pulses_cnt2<<1)) ||
                        (motor_init_pulses_cnt2 < (motor_init_pulses_cnt1>>1)) ||
                        (motor_init_pulses_cnt2 > (motor_init_pulses_cnt1<<1)))
                    {
                        error(ERROR_MOTOR_PULSES_LIGHT);error_light1_state = 0x100 + motor_init_state;
                        if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                        return;
                    }
                    else
                    {
                        motor_init_pulses_cnt1 = 0x00;
                        motor_init_pulses_cnt2 = 0x00;
                        timer_pulses_clear();
                    }
                }

                
                if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_FULL_SPEED)
                {
                    if(motor_slope_is_idle() == TRUE)  
                    {
                        next_state = MOTOR_INIT_FIRST_POSTER_FULL_SPEED;
                    }
                }
                else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_FULL_SPEED)
                {
                    if(timer_pulses_get_globalH() > (motor_pulses_poster[0]*0.8) )
                    {
                        (*motor_init_timer_tempo_ms) = (motor.init_mode.cell_timeout_time*2); 
                        motor_slope_calc_phase(motor.init_mode.init_phase_list[10]);
                        motor_slope_run();
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED1;
                    }
                }
                else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED1)
                {
                    if(motor_slope_is_idle() == TRUE)  
                    {
                        motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED2;
                    }
                }
                else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED2)
                {
                    if(timer_pulses_get_globalH() > (motor_pulses_poster[0]*0.96) )
                    {
                        (*motor_init_timer_tempo_ms) = (motor.init_mode.cell_timeout_time*2); 
                        motor_critical_drive = TRUE;
                        motor_slope_get_reg_speed();
                        next_state = MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED3;
                    } 
                }
                else if(motor_init_state == MOTOR_INIT_FIRST_POSTER_SLOPE_TO_DOCKING_SPEED3)
                {
                    if(motor_slope_is_idle() == TRUE)  
                    {
                        if(timer_pulses_get_globalH() >= ((motor_pulses_poster[0])) )
                        {
                            (*motor_init_timer_tempo_ms) = (motor.init_mode.cell_timeout_time*2); 
                            motor_copy_phase_slope(&motor.init_mode.init_phase_list[12],&motor_init_phase_pulses_cell,0);
                            // Préparation de la rampe de deceleration 
                            motor_slope_calc_phase(motor_init_phase_pulses_cell);
                            // Ordre de rampe.
                            motor_slope_run();
                            
                            (*motor_init_timer_timeout_ms) = 3500;
                            next_state = MOTOR_INIT_FIRST_PULSES1;
                        }
                    }
                } 
            }
            break;
        
            
        case MOTOR_INIT_FIRST_POSTER_SET_SLAVE_DOCKING_PULSES1:
            motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
            next_state = MOTOR_INIT_FIRST_POSTER_SET_SLAVE_DOCKING_PULSES2;
            break;
            
        case MOTOR_INIT_FIRST_POSTER_SET_SLAVE_DOCKING_PULSES2:
            if(motor_slope_is_idle() == TRUE)
            {
                next_state = MOTOR_INIT_FIRST_POSTER_DOCKING_SPEED;
            }
            break;
            
            
            
            
        case MOTOR_INIT_FIRST_POSTER_DOCKING_SPEED:
            
            if((*motor_init_timer_timeout_ms) == 0x00)
            {
                error(ERROR_STICKER_TIMEOUT_DURING_DOCKING_SPEED);
                if(motor_init_state != MOTOR_INIT_START) motor_init_state = MOTOR_INIT_NOP;
                return;  
            }
            
            if((cell_time > CELLULE_PASTILLE_MIN_MS))
            {
                if(pulses_feature)
                {
                    /*dbg2 = timer_pulses_get_valueH();
                    dbg3 = dbg2-dbg1;
                    dbg4 = motor.init_mode.cell_timeout_time - (*motor_init_timer_timeout_ms);*/
                    
                    //
                    motor_init_phase = 0 ;
                    // RAZ des compteurs de pulses
                    timer_pulses_clear();
                    
                    
                    
                    // Préparation d'un rampe vers la vitesse actuelle divisée par 2
                    //motorh_slope_xx_xs(motorh_get_current_speed()/2,25);
                    
                    // Calcul du nombre de points à compter
                    motor_init_pulses_cnt1 = (poster[0].cell_pulses>>1)  - (poster[0].cell_pulses>>3);
                    
                    
                    motor_init_pulses_save = timer_pulses_get_valueH();
                    // Initialisation du compteur de temps pour gérer la vitesse en mode points
                    // Utile si le mobilier s'arrete avant d'arriver sur la pastille
                    (*motor_init_timer_timeout_ms) = 100;
                }
                else
                {
                    motor_slope_calc_phase(motor.init_mode.init_phase_list[12]);
                    motor_slope_run();
                }
                next_state = MOTOR_INIT_FIRST_POSTER_STOP_STICKER; 
            }
            break;
        
            
                
        case MOTOR_INIT_FIRST_POSTER_STOP_STICKER:
            if(pulses_feature)
            {
                if((timer_pulses_get_valueH() >= motor_init_pulses_cnt1) && (motor_init_phase == 0x00))
                {
                    motor_init_phase = 1;
                    // On copie la rampe dans une structure locale
                    motor_copy_phase_slope_div(&motor.init_mode.init_phase_list[12],&motor_init_phase_pulses_cell,0);
                    // Préparation de la rampe de deceleration 
                    motor_slope_calc_phase(motor_init_phase_pulses_cell);
                    // Ordre de rampe.
                    motor_slope_run();
                }
                else if(motor_slope_is_idle() == TRUE && motor_init_phase == 0x01)
                {
                    next_state = MOTOR_INIT_ANALYSE_BRAKE;
                }
            }
            else
            {
                // Si la rampe est terminée
                if(motor_slope_is_idle() == TRUE)
                {
                    next_state = MOTOR_INIT_ANALYSE_BRAKE;
                }
            }
            break;
            
        case MOTOR_INIT_ANALYSE_BRAKE:
            if(motor_slope_is_idle() == TRUE)
            {
                if(motorl_switch == TRUE)
                {
                    // Désactivation du moteur bas
                    motorl_slope_mx_xs(PWM_TABLE_OFF,0,0);
                    // Ordre de rampe
                    motor_slope_run();
                    // Passage à l'état suivant.
                    next_state = MOTOR_INIT_SLOPE_BRAKE;
                }
                else
                {
                    // Passage à l'état suivant.
                    next_state = MOTOR_INIT_SLOPE_BRAKE;
                }  
            }
            break;
            
        case MOTOR_INIT_SLOPE_BRAKE:
            // Si la rampe est terminée
            if(motor_slope_is_idle() == TRUE)  
            {
                // Compteur de temps armé à 1000ms
                (*motor_init_timer_timeout_ms) = 1000;
                // Passage à l'état suivant
                next_state = MOTOR_INIT_FINAL;  
            }
            break;
            
        case MOTOR_INIT_FINAL:
            // Si le compteur de temps est terminé
            if((*motor_init_timer_timeout_ms) == 0x00)
            {
                // Passage à l'état inactif
                next_state = MOTOR_INIT_NOP; 
                // Passage dans le mode auto
                
                if((motor_init_poster_count > 1) && (btldr_stop_scrolling == FALSE))
                {
                   motor_auto_init();
                }
            }
            break;
            
            
            
    }
    motor_init_state = next_state;
}
