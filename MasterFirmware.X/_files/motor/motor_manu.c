#include <_Global_Include.h>





// <editor-fold defaultstate="collapsed" desc="MODE MANU DECLARATIONS">
u8 motor_manu_sm_state;
u8 motor_manu_save_tele_byte;
bool motor_manu_stby;
u8 motor_manu_tele_previous_state;
volatile u16 manu_motor_time_ms;

bool motor_manu_adjust_pulses = FALSE;
struct struct_slope_phase motor_manu_phase_pulses_cell;

typedef enum
{
    TELE_IDLE,
    TELE_ENRH,
    TELE_ENRL,
    TELE_DERH,        
}enum_motor_manu_tele_states;

// Definition des états de la machine de gestion des rampes
typedef enum
{
  MOTOR_MANU_IDLE, 
  MOTOR_MANU_STBY,
  MOTOR_MANU_STBY2,
          
  MOTOR_MANU_START,
  MOTOR_MANU_PRESS,
  MOTOR_MANU_WAIT_SLOPE1,
  MOTOR_MANU_WAIT_SLOPE2,
  MOTOR_MANU_WAIT_RELEASE, 
  MOTOR_MANU_RELEASE_EVENT,        
  MOTOR_MANU_WAIT_SLOPE3,
  MOTOR_MANU_WAIT_SLOPE4,
  MOTOR_MANU_WAIT_4_5,
  MOTOR_MANU_WAIT_SLOPE5,
          
          
  MOTOR_MANU_WAIT_STBY_TIME,
  MOTOR_MANU_END,  
          
          
  MOTOR_MANU_ADJUST1,
  MOTOR_MANU_ADJUST2,
  MOTOR_MANU_ADJUST3,
          
  MOTOR_MANU_CLEAR_FLASH,        
  MOTOR_MANU_CLEAR_FLASH2,
  MOTOR_MANU_CLEAR_FLASH3, 
          
          
  MOTOR_MANU_ADJUST_PULSES1,
  MOTOR_MANU_ADJUST_PULSES2,
  MOTOR_MANU_ADJUST_PULSES3,
          
          
          
}enum_motor_manu_sm;

void start_of_manual_mode(void);
void end_of_manual_mode(void);
// </editor-fold>




// <editor-fold defaultstate="collapsed" desc="MODE MANU">
void motor_manu_init(void)
{
    
  
    timer1ms_register_variable((u16*)&manu_motor_time_ms);
    motor_manu_tele_previous_state = TELE_IDLE;
    motor_manu_sm_state = MOTOR_MANU_IDLE;   
}



void start_of_manual_mode(void)
{
    uarts_init_re_de();
    motor.manual_mode.manual_enrh_phase_list[4].brake_override = TRUE;
    motor.manual_mode.manual_enrl_phase_list[4].brake_override = TRUE;
    motor.manual_mode.manual_derh_phase_list[4].brake_override = TRUE;
    
    motor.manual_mode.manual_enrh_phase_list[5].brake_override = TRUE;
    motor.manual_mode.manual_enrl_phase_list[5].brake_override = TRUE;
    motor.manual_mode.manual_derh_phase_list[5].brake_override = TRUE;
    
    motor_critical_drive = FALSE;
    timer_pulses_clear();
   
    motor_manu_tele_previous_state = TELE_IDLE;
    motor_manu_stby                = FALSE;
   
    if(pulses_feature)
    {
        motor_slope_get_reg_speed();
        motor_manu_sm_state            = MOTOR_MANU_STBY;
    }
    else
    {
        motor_direction                = NO_DIRECTION;
        motor_manu_sm_state            = MOTOR_MANU_STBY2;
        motorh_slope_xx_xs(motor.minimum_speed_value,100);
        motorl_slope_xx_xs(motor.minimum_speed_value,100);
        motor_slope_run();
    }
    

    
    
}


void end_of_manual_mode(void)
{
    uarts_init_re_de();
    motor_auto_cycle_reset = TRUE;
    motor_auto_cycle_init_param = FALSE;
    motor_init_init_with_clear_params();
    motor_manu_adjust_pulses = FALSE;
    eeprom_ev_write1(EEPROM_EV_MANUAL_EXIT);
    error_end_of_manual_mode();
}


void motor_manu_sm(void)
{
    u16 temp16;
    u16 temp16_2;
    u8 next_state;
    
    
    //motor_manu_security_sm();
    next_state = motor_manu_sm_state;
    
    //if(motor_manu_security_active) return;
    
    switch(motor_manu_sm_state)  
    {
        case MOTOR_MANU_IDLE:
            if(tele_auto == FALSE)
            {
                if(cell_feature)
                {
                    if(tele_enroulement_bas == FALSE && tele_enroulement_haut == TRUE )
                    {
                        // Si petite vitesse
                        if( (motor.family == MOTOR_ASYNC_FAMILY) &&
                            ((motor_algo_mode == INIT_MODE && motor_init_state == MOTOR_INIT_FIRST_POSTER_DOCKING_SPEED) ||
                            ( motor_algo_mode >= PREAUTO_MODE && motor_algo_mode <= PREAUTO3_MODE && motor_auto_state == MOTOR_AUTO_DOCKING_SPEED))
                          )
                        {

                            if(motor_direction == ENRH)
                            {
                                if(motor.enrh_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrh_speed_adjust))
                                {
                                    motor.enrh_dock_speed_incr += motor.enrh_speed_adjust;
                                    //motor.enrl_dock_speed_incr += motor.enrl_speed_adjust;
                                    next_state = MOTOR_MANU_ADJUST1;
                                }
                            }
                            else
                            {
                                if(motor.enrl_dock_speed_incr < (ASYNC_ADJUST_SPEED_STEPS*motor.enrl_speed_adjust))
                                {
                                    motor.enrl_dock_speed_incr += motor.enrl_speed_adjust;
                                    //motor.enrl_dock_speed_incr += motor.enrl_speed_adjust;
                                    next_state = MOTOR_MANU_ADJUST1;
                                }
                            }



                        }
                        // Si affichage en mode auto
                        else if(motor_algo_mode > INIT_MODE && motor_auto_state == MOTOR_AUTO_DISPLAY)
                        {

                        }


                    }
                    else if(tele_enroulement_bas == TRUE && tele_enroulement_haut == FALSE )
                    {
                        // Si petite vitesse
                        if( (motor.family == MOTOR_ASYNC_FAMILY) &&
                            ((motor_algo_mode == INIT_MODE && motor_init_state == MOTOR_INIT_FIRST_POSTER_DOCKING_SPEED) ||
                            ( motor_algo_mode >= PREAUTO_MODE && motor_algo_mode <= PREAUTO3_MODE && motor_auto_state == MOTOR_AUTO_DOCKING_SPEED))
                          )
                        {

                            if(motor_direction == ENRH)
                            {
                                if(motor.enrh_dock_speed_incr > 0)
                                {
                                    motor.enrh_dock_speed_incr -= motor.enrh_speed_adjust;
                                    //motor.enrl_dock_speed_incr -= motor.enrl_speed_adjust;
                                    next_state = MOTOR_MANU_ADJUST1;
                                }
                            }
                            else
                            {
                                if(motor.enrl_dock_speed_incr > 0)
                                {
                                    motor.enrl_dock_speed_incr -= motor.enrl_speed_adjust;
                                    //motor.enrl_dock_speed_incr -= motor.enrl_speed_adjust;
                                    next_state = MOTOR_MANU_ADJUST1;
                                }
                            }



                        }
                        // Si affichage en mode auto
                        else if(motor_algo_mode > INIT_MODE && motor_auto_state == MOTOR_AUTO_DISPLAY)
                        {

                        } 
                    }
                    else if(tele_enroulement_bas == TRUE && tele_enroulement_haut == TRUE )
                    {

                    }
                }
                else if(pulses_feature && !cell_feature)
                {
                    if(tele_enroulement_bas == FALSE && tele_enroulement_haut == TRUE )
                    {
                        if( 
                            (motor_algo_mode == INIT_MODE && motor_init_state == MOTOR_INIT_FIRST_PULSES2) ||   
                            (motor_algo_mode == PREAUTO_MODE && (motor_auto_state == MOTOR_AUTO_NO_CELL_POSTER_ADJUST || motor_auto_state == MOTOR_AUTO_NO_CELL_AUTO_TWEAK9))
                          )
                        {
                            motor_manu_adjust_pulses = TRUE;
                            
                            motorh_slope_ms_ms(motor.pulse_adjust_enrh.motorh_mode_dir,
                                               motor.pulse_adjust_enrh.motorh_speed,
                                               motor.pulse_adjust_enrh.motorh_mode_dir,
                                               motor.pulse_adjust_enrh.motorh_speed,0);
                            motorl_slope_ms_ms(motor.pulse_adjust_enrh.motorl_mode_dir,
                                               motor.pulse_adjust_enrh.motorl_speed,
                                               motor.pulse_adjust_enrh.motorl_mode_dir,
                                               motor.pulse_adjust_enrh.motorl_speed,0);
                            motor_slope_run();
                            next_state = MOTOR_MANU_ADJUST_PULSES1;
                            
                        }
                    }
                    else if(tele_enroulement_bas == TRUE && tele_enroulement_haut == FALSE )
                    {
                        if( 
                            (motor_algo_mode == INIT_MODE && motor_init_state == MOTOR_INIT_FIRST_PULSES2) ||   
                            (motor_algo_mode == PREAUTO_MODE && (motor_auto_state == MOTOR_AUTO_NO_CELL_POSTER_ADJUST || motor_auto_state == MOTOR_AUTO_NO_CELL_AUTO_TWEAK9))
                          )
                        {
                            motor_manu_adjust_pulses = TRUE;
                            
                            next_state = MOTOR_MANU_ADJUST_PULSES1;
                            
                            motorh_slope_ms_ms(motor.pulse_adjust_enrl.motorh_mode_dir,
                                               motor.pulse_adjust_enrl.motorh_speed,
                                               motor.pulse_adjust_enrl.motorh_mode_dir,
                                               motor.pulse_adjust_enrl.motorh_speed,0);
                            motorl_slope_ms_ms(motor.pulse_adjust_enrl.motorl_mode_dir,
                                               motor.pulse_adjust_enrl.motorl_speed,
                                               motor.pulse_adjust_enrl.motorl_mode_dir,
                                               motor.pulse_adjust_enrl.motorl_speed,0);
                          
                            motor_slope_run(); 
                            
                            
                        }
                    }
                    else
                    {
                        
                    }
                }
            }
            else
            {
                next_state = MOTOR_MANU_START;
            }
            break;
      
        case MOTOR_MANU_ADJUST_PULSES1:
            if(motor_slope_is_idle() == TRUE)
            {
                   if(tele_enroulement_bas == FALSE && tele_enroulement_haut == TRUE )
                   {
                       motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                       next_state = MOTOR_MANU_ADJUST_PULSES2;
                   }
                   else if(tele_enroulement_bas == TRUE && tele_enroulement_haut == FALSE )
                   {
                       motor_slope_pulses_L(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                       next_state = MOTOR_MANU_ADJUST_PULSES2;
                   }
                   else
                   {
                       next_state = MOTOR_MANU_ADJUST_PULSES2;
                   }
            }
            break;
            
        case MOTOR_MANU_ADJUST_PULSES2:
            if(motor_slope_is_idle() == TRUE)
            {
                if(tele_enroulement_bas == FALSE && tele_enroulement_haut == FALSE )
                {
                    
                    motor_copy_phase_slope(&motor.preauto_auto.enrh_phase_list[0],&motor_manu_phase_pulses_cell,0);
                    // Préparation de la rampe de deceleration 
                    motor_slope_calc_phase(motor_manu_phase_pulses_cell);
                    // Ordre de rampe.
                    motor_slope_run();
                    next_state = MOTOR_MANU_ADJUST_PULSES3;
                }
            }
            break;
            
        case MOTOR_MANU_ADJUST_PULSES3:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_manu_adjust_pulses = FALSE;
                next_state = MOTOR_MANU_IDLE;
            }
            break;
            
            
        case MOTOR_MANU_ADJUST1:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                
                if( (motor_algo_mode == INIT_MODE ) || (motor_algo_mode > INIT_MODE && motor_direction == ENRH))
                {
                    if(motor_algo_mode == INIT_MODE )
                    {
                        temp16 = motor.init_mode.init_phase_list[11].motorh_speed + motor.enrh_dock_speed_incr;
                        temp16_2 = motor.init_mode.init_phase_list[11].motorh_mode_dir;
                    }
                    else 
                    {
                        temp16 = motor.preauto_auto.enrh_phase_list[3].motorh_speed + motor.enrh_dock_speed_incr;
                        temp16_2 = motor.preauto_auto.enrh_phase_list[3].motorh_mode_dir;
                    }
                    
                    #ifdef DEBUG_PRINTF  
                    printf("Envoi vitesse moteur haut %4d \n",temp16);    
                    #endif

                    
                    // Construction du paquet
                    temp16 = (temp16*10);
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_CONTROL_V2);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,temp16_2);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(temp16>>8));
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(temp16 & 0x00FF));   
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);                   
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                }  
                else if(motor_algo_mode > INIT_MODE && motor_direction == ENRL)
                {
                    temp16 = motor.preauto_auto.enrl_phase_list[3].motorl_speed + motor.enrl_dock_speed_incr;
                    temp16_2 = motor.preauto_auto.enrl_phase_list[3].motorl_mode_dir;
                    
                    #ifdef DEBUG_PRINTF  
                    printf("Envoi vitesse moteur bas %4d \n",temp16);    
                    #endif

                    // Construction du paquet
                    temp16 = (temp16*10);
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_CONTROL_V2);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,temp16_2);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(temp16>>8));
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,(temp16 & 0x00FF)); 
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                }
                // Envoi du paquet
                uart_motor_protocole_send_packet();
                next_state = MOTOR_MANU_ADJUST2;
                
            }
        break;
        
        case MOTOR_MANU_ADJUST2:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                }
                uart_motor_protocole_release_mutex();
                next_state = MOTOR_MANU_ADJUST3;
            }
            break;
            
            
        case MOTOR_MANU_ADJUST3:
            if(tele_enroulement_bas == FALSE && tele_enroulement_haut == FALSE )
            {
                next_state = MOTOR_MANU_IDLE;
            }
            break;
        
        
           
        case MOTOR_MANU_STBY:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_direction = NO_DIRECTION;
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                motor_slope_run();
                next_state = MOTOR_MANU_STBY2;
            }
            break;
            
        case MOTOR_MANU_STBY2:
               if(motor_slope_is_idle() == TRUE)
               {
                     //motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[1]);
                     motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[5]);
                     motor_slope_run();
                     next_state = MOTOR_MANU_START;   
               }
            break;
            
            
            
        case MOTOR_MANU_START:
            if(motor_slope_is_idle() == TRUE)
            {
                if(tele_auto == TRUE) // Si on est toujours en mode manuel
                {
                    motor_manu_tele_previous_state = TELE_IDLE;
                    next_state = MOTOR_MANU_PRESS;
                }
                else
                {
                    next_state = MOTOR_MANU_END;
                }
            }
            break;
        
        case MOTOR_MANU_PRESS:
            if(tele_auto == TRUE) // Si on est toujours en mode manuel
            {
                motor_manu_save_tele_byte = telecommande_byte(); // Sauvegarde de l'état de la télécommande
                if(tele_enroulement_bas == TRUE && tele_enroulement_haut == FALSE ) // Si enroulement bas
                {
                    motor_direction = ENRL;
                    motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[1]);
                    motor_slope_run();
                    motor_manu_tele_previous_state = TELE_ENRL;
                    next_state                     = MOTOR_MANU_WAIT_SLOPE1;
                    
                }
                else if(tele_enroulement_haut == TRUE && tele_deroulement_haut == TRUE) // Si déroulement haut
                {
                    motor_direction = NO_DIRECTION;
                    motor_manu_tele_previous_state = TELE_DERH;
                    next_state                     = MOTOR_MANU_WAIT_SLOPE1;
                    motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[1]);
                    motor_slope_run();
                }
                else if(tele_enroulement_bas == FALSE && tele_enroulement_haut == TRUE && tele_deroulement_haut == FALSE) // Si enroulement haut
                {
                    motor_direction = ENRH;
                    motor_manu_tele_previous_state = TELE_ENRH;
                    next_state                     = MOTOR_MANU_WAIT_SLOPE1;
                    motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[1]);
                    motor_slope_run();
                }
                else if(tele_enroulement_bas == TRUE && tele_enroulement_haut == TRUE && tele_deroulement_haut == FALSE)
                {
                    motor_direction = NO_DIRECTION;
                    manu_motor_time_ms = 5000;
                    next_state = MOTOR_MANU_CLEAR_FLASH;
                }
                else
                {
                    if(motor_manu_tele_previous_state != TELE_IDLE)
                    {
                        next_state = MOTOR_MANU_WAIT_SLOPE5;
                        if(motor_manu_tele_previous_state == TELE_ENRH)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[5]); 
                        }
                        else if(motor_manu_tele_previous_state == TELE_ENRL)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[5]);
                        }
                        else
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[5]);
                        }
                        motor_slope_run();


                        next_state = MOTOR_MANU_START;   
                    }
                }
                    
            }
            else
            {
                next_state = MOTOR_MANU_END;
            }
            break;
            
        case MOTOR_MANU_CLEAR_FLASH:
            if(tele_auto == TRUE) // Si on est toujours en mode manuel
            {
                if(tele_enroulement_bas == TRUE && tele_enroulement_haut == TRUE && tele_deroulement_haut == FALSE)
                {
                    if(manu_motor_time_ms == 0x00)
                    {
                        
                        eeprom_var_reset_default();  // RAZ des variables concernées dans la mémoire.
        
                        
                        for(temp16=0;temp16<5;temp16++)
                        {
                           led_motor_prog = LED_ON;
                           led_default_prog = LED_ON;
                           manu_motor_time_ms = 100;
                           while(manu_motor_time_ms > 0);
                           led_motor_prog = LED_OFF;
                           led_default_prog = LED_OFF;
                           manu_motor_time_ms = 100;
                           while(manu_motor_time_ms > 0);
                        }
                        
                        next_state = MOTOR_MANU_PRESS;
                    }
                }
                else
                {
                    next_state = MOTOR_MANU_PRESS;
                }
            }
            else next_state = MOTOR_MANU_END ;
            break;
        
       
            
          case MOTOR_MANU_WAIT_SLOPE1:
                motor.enrh_dock_speed_incr = 0;
                motor.enrl_dock_speed_incr = 0; 
                
                if(telecommande_byte() != motor_manu_save_tele_byte)
                { 
                    next_state = MOTOR_MANU_WAIT_SLOPE3;
                    if(motor_manu_tele_previous_state == TELE_ENRH)
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[3]);
                    }
                    else if(motor_manu_tele_previous_state == TELE_ENRL)
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[3]);
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[3]);
                    }
                    motor_slope_run();
                }
                else if(motor_slope_is_idle() == TRUE)
                {
                    next_state = MOTOR_MANU_WAIT_SLOPE2;
                    if(motor_manu_tele_previous_state == TELE_ENRH)
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[2]);
                    }
                    else if(motor_manu_tele_previous_state == TELE_ENRL)
                    {
                        //motor_slope_calc_phase(motor.pulse_adjust_enrl);
                        motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[2]);
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[2]);
                    }
                    motor_slope_run();
                }
              break;
              
              
        case MOTOR_MANU_WAIT_SLOPE2:
                if(telecommande_byte() != motor_manu_save_tele_byte)
                { 
                    next_state = MOTOR_MANU_WAIT_SLOPE3;
                    if(motor_manu_tele_previous_state == TELE_ENRH)
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[3]);
                    }
                    else if(motor_manu_tele_previous_state == TELE_ENRL)
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[3]);
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[3]);
                    }
                    
                }
                else if(motor_slope_is_idle() == TRUE)
                {
                    next_state = MOTOR_MANU_WAIT_RELEASE;
                }
              break;
              
        case MOTOR_MANU_WAIT_RELEASE:
            if(telecommande_byte() != motor_manu_save_tele_byte)
            { 
               next_state = MOTOR_MANU_RELEASE_EVENT; 
                
            }
            break;
            
        case MOTOR_MANU_RELEASE_EVENT:
            next_state = MOTOR_MANU_WAIT_SLOPE3;
            if(motor_manu_tele_previous_state == TELE_ENRH)
            {
                 motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[3]);
            }
            else if(motor_manu_tele_previous_state == TELE_ENRL)
            {
                motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[3]);
            }
            else
            {
                motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[3]);
            }
            motor_slope_run();
            
            break;
            
        case MOTOR_MANU_WAIT_SLOPE3:
            if(motor_slope_is_idle() == TRUE)
            {
                if(tele_auto == TRUE)
                {
                   if(tele_enroulement_bas || tele_enroulement_haut)// || tele_deroulement_haut)     
                   {
                     next_state = MOTOR_MANU_PRESS; 
                   }
                   else
                   {
                        next_state = MOTOR_MANU_WAIT_SLOPE4;
                        if(motor_manu_tele_previous_state == TELE_ENRH)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[4]);
                        }
                        else if(motor_manu_tele_previous_state == TELE_ENRL)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[4]);
                        }
                        else
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[4]);
                        }
                        motor_slope_run();
                    }
                }
                else
                {
                    next_state = MOTOR_MANU_END; 
                }
               
            }
            break;
            
            
        case MOTOR_MANU_WAIT_SLOPE4:
        case MOTOR_MANU_WAIT_4_5:
            if(tele_auto == TRUE)
            {
                if(tele_enroulement_bas || tele_enroulement_haut)// || tele_deroulement_haut)     
                {       
                   next_state = MOTOR_MANU_PRESS;
                }
                else if(motor_slope_is_idle() == TRUE && motor_timer_ms == 0x00)
                {
                    
                    if(motor_manu_sm_state == MOTOR_MANU_WAIT_SLOPE4)
                    {
                      motor_timer_ms = 0;  
                      next_state = MOTOR_MANU_WAIT_4_5;
                    }
                    else
                    {
                        next_state = MOTOR_MANU_WAIT_SLOPE5;
                        if(motor_manu_tele_previous_state == TELE_ENRH)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrh_phase_list[5]); 
                        }
                        else if(motor_manu_tele_previous_state == TELE_ENRL)
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_enrl_phase_list[5]);
                        }
                        else
                        {
                            motor_slope_calc_phase(motor.manual_mode.manual_derh_phase_list[5]);
                        }
                        motor_slope_run();
                    }
                }
                    
            }
            else
            { 
                next_state = MOTOR_MANU_END; 
            }
            
            
            break;

            
            
        case MOTOR_MANU_WAIT_SLOPE5:
            if(motor_slope_is_idle() == TRUE)
            {
                if(tele_auto == TRUE)
                {
                   if(tele_enroulement_bas || tele_enroulement_haut)
                   {
                     next_state = MOTOR_MANU_PRESS; 
                   }
                   else
                   {
                     next_state = MOTOR_MANU_END; 
                   }
                }
                else
                {
                    next_state = MOTOR_MANU_END; 
                }
               
            }
            break;
            
        case MOTOR_MANU_END:
            if(motor_slope_is_idle() == TRUE)
            {
               next_state      = MOTOR_MANU_IDLE;
            }
            break;
    }
    motor_manu_sm_state = next_state;
}
// </editor-fold>