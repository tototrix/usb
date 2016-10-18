#include <_Global_Include.h>

volatile u16 auto_dbg1;
volatile u16 auto_dbg2;

bool motor_auto_cycle_reset = TRUE;
bool motor_auto_cycle_init_param = FALSE;


volatile u8 motor_auto_init_count = 0x00;
volatile u8 motor_auto_tweak_count = 0x00;
volatile u32 motor_auto_cycle_count_total = 0x00;
volatile u8 motor_auto_tweak_order_start_cnt = 0x00;
volatile u8 motor_auto_tweak_order_end_cnt   = 0x00;



// Indique aux autres machines si on est en affichage ou en cours de defilement
u8 motor_auto_scrolling = 0;
// Permet de savoir sur quelle affiche on se trouve
u8 motor_auto_poster_index = 0;
// Etat en cours de la ME
u8 motor_auto_state = MOTOR_AUTO_NOP;

// Permet de mesurer le durée de la petite vitesse lors de la phase de préauto
u16 motor_preauto_timestamp1;
u16 motor_preauto_timestamp2;
u16 motor_preauto_timestamp3;


// Remap des timers
volatile u16 *motor_auto_timer_timeout_ms;
volatile u16 *motor_auto_timer_inhib_ms;
volatile u16 *motor_auto_timer_tempo_ms;


u16 motor_auto_vcc_ref;

// Gestion des preauto automatique (1000 cycles après sortie du mode manuel , tous les 6000 cycles après)
typedef enum 
{
    MOTOR_CYCLE_START,
    MOTOR_CYCLE_WAIT_COUNT_1,
    MOTOR_CYCLE_WRITE_1,
            
    MOTOR_CYCLE_WAIT_PREAUTO_1,
    MOTOR_CYCLE_WAIT_AUTO_2,
    MOTOR_CYCLE_WAIT_COUNT_2,
    MOTOR_CYCLE_WRITE_2,
    MOTOR_CYCLE_WRITE_3,
    MOTOR_CYCLE_WRITE_4,
            
    MOTOR_CYCLE_WAIT_PREAUTO_2,  
            
            
    MOTOR_CYCLE_WAIT_FIRST_INIT1,        
    MOTOR_CYCLE_WAIT_FIRST_INIT2,    
            
    MOTOR_CYCLE_WAIT_COUNT,
    MOTOR_CYCLE_WAIT_CELL,
    MOTOR_CYCLE_WAIT_NO_CELL,
            
            
            
            
}motor_auto_cycle_list;


u16 motor_auto_cycle_count; // permet de compter les cycles

u8  motor_auto_cycle_state; // contient l'état en cours de la machine de gestion des cycles
void motor_auto_cycle_sm(void); // ME de gestion des cycles

// Variables relatives aux pulses
struct struct_slope_phase motor_auto_phase_pulses_cell;
u16 motor_auto_pulses_cnt1;
u16 motor_auto_pulses_cnt2;

u16 motor_auto_phase;
u16 motor_auto_pulses_save;
bool motor_auto_pulses_comp;
bool motor_auto_pulses_adjust;

bool motor_auto_pulses_tweak = FALSE;

u8 motor_auto_cell_phase;



void motor_auto_process_pulses_poster(void)
{
    u16 i;
    u16 temp16;
    
    if(motor_init_poster_count>1)
    {
        for(i=0;i<=3;i++)
        {
            if(poster[i+1].cell_pulses >=  poster[i].cell_pulses)
            {
                temp16 = poster[i+1].cell_pulses - poster[i].cell_pulses;
            }
            else
            {
                temp16 = 0;
            }
            
            if(temp16 < (motor_pulses_count_poster/2) )
            {
                poster[i+1].cell_pulses += (motor_pulses_count_poster/2);
            }
        }
        
        
        
        for(i=1;i<5;i++)
        {
            temp16 = poster[i].cell_pulses - poster[i-1].cell_pulses;
            //temp16>>=1;
            temp16 = temp16/3;
            poster[i]._enrh_TGV_AUTO = poster[i-1].cell_pulses+temp16; //poster[i-1].cell_pulses + ((poster[i].cell_pulses - poster[i-1].cell_pulses)>>1);   
            poster[i]._enrh_TS1_AUTO = 0x00;
            poster[i]._enrh_TS2_AUTO = 0x00;
            
        }

        for(i=0;i<4;i++)
        {
            temp16 = poster[i+1].cell_pulses - poster[i].cell_pulses;
            //temp16>>=1;
            temp16 = temp16/3;
            
            poster[i]._enrl_TGV_AUTO =  poster[i+1].cell_pulses - temp16;//poster[i+1].cell_pulses - ((poster[i+1].cell_pulses - poster[i].cell_pulses)>>1);
            poster[i]._enrl_TS1_AUTO = 0x00;
            poster[i]._enrl_TS2_AUTO = 0x00;
        }  
    }
}



void motor_auto_init(void)
{
    

    /*
    motor.preauto_auto.enrh_phase_list[1].motorh_speed = 68;
    motor.preauto_auto.enrh_phase_list[1].motorh_slope = 25;
    motor.preauto_auto.enrl_phase_list[1].motorl_speed = 65;
    motor.preauto_auto.enrl_phase_list[1].motorl_slope = 25;
    
    motor.preauto_auto.enrh_phase_list[2].motorh_slope = 25;
    motor.preauto_auto.enrl_phase_list[2].motorl_slope = 25;
    
    
            
    motor.preauto_auto.enrh_phase_list[5].motorh_speed = 12;
    motor.preauto_auto.enrh_phase_list[5].motorh_slope = 0;
    motor.preauto_auto.enrh_phase_list[5].motorl_speed = 0;
    motor.preauto_auto.enrh_phase_list[5].motorl_slope = 0;
    
            
    motor.preauto_auto.enrl_phase_list[5].motorh_speed = 0;
    motor.preauto_auto.enrl_phase_list[5].motorh_slope = 0;
    motor.preauto_auto.enrl_phase_list[5].motorl_speed = 6;
    motor.preauto_auto.enrl_phase_list[5].motorl_slope = 0;*/
    
    
    
    uarts_init_re_de();
    
    motor_auto_init_count++;
    motor_auto_tweak_count = 0x00;
    motor_auto_scrolling   = 0x00;
    motor_auto_poster_index           = 0x00;
    motor_direction        = ENRH;
    motor_algo_mode        = PREAUTO_MODE;
    motor_auto_state       = MOTOR_AUTO_START;
    error_order_preauto    = FALSE;
    
    motor_auto_cycle_state = MOTOR_CYCLE_START;
    
    motor_auto_cycle_count = 0x00;
    motor_auto_pulses_tweak  = FALSE;
    motor_auto_pulses_adjust = FALSE;
    
    if(!cell_feature)
    {
        if(motor_init_poster_count>1)
        {
            
            poster[0].cell_pulses = motor_pulses_poster[0];
            poster[1].cell_pulses = motor_pulses_poster[1];
            poster[2].cell_pulses = motor_pulses_poster[2];
            poster[3].cell_pulses = motor_pulses_poster[3];
            poster[4].cell_pulses = motor_pulses_poster[4];

            

            motor_auto_process_pulses_poster();
        }
        
        //motor.docking_pulses_security = 100;
    }
    
    
    
}

void motor_auto_cycle_sm(void)
{
    u8 next_state = 0x00;
    
    
    if(motor_algo_mode != AUTO_MODE)
    {
        motor_auto_cycle_state = MOTOR_CYCLE_START;
    }
    next_state = motor_auto_cycle_state;
    
    
    switch(motor_auto_cycle_state)
    {
        case MOTOR_CYCLE_START:
            if(motor_algo_mode == AUTO_MODE)
            {
                motor_auto_cycle_count = 0x00;
                
                if(motor_auto_cycle_reset == TRUE)
                {
                   next_state = MOTOR_CYCLE_WAIT_FIRST_INIT1;
                }
                else
                {
                   next_state =  MOTOR_CYCLE_WAIT_COUNT;
                }
                
            }
            break;
       
            
        case MOTOR_CYCLE_WAIT_FIRST_INIT1:
            /*if( ((motorh_type == MOTOR_MODEL_BRUSHLESS_HITO) && (motor_auto_cycle_count == 10)) ||
                (motor_auto_cycle_count == MOTOR_AUTO_CYCLE_COUNT_FIRST_INIT)
              )*/
            if(motor_auto_cycle_count >= MOTOR_AUTO_CYCLE_COUNT_FIRST_INIT)
            {
                eeprom_ev_write1(EEPROM_EV_AUTO_CYCLE_FIRST_INIT);
                motor_auto_cycle_reset      = FALSE;
                motor_auto_cycle_init_param = TRUE;
                next_state = MOTOR_CYCLE_WAIT_FIRST_INIT2;
            }
            break;
            
        case MOTOR_CYCLE_WAIT_FIRST_INIT2:
            break;
            
        case MOTOR_CYCLE_WAIT_COUNT:
            if(cell_feature)
            {
                if(motor_auto_cycle_count >= MOTOR_AUTO_CYCLE_COUNT_WITH_CELL)
                {
                    eeprom_ev_write1(EEPROM_EV_AUTO_CYCLE_COUNT_CELL);
                    error_order_preauto = TRUE;   
                    next_state = MOTOR_CYCLE_WAIT_CELL;
                }
            }
            else if(motor_auto_cycle_count >= motor.pulses_no_cell_tweak_count)   
            {
                eeprom_ev_write1(EEPROM_EV_AUTO_CYCLE_POSTER_ADJUST);
                motor_auto_pulses_tweak = TRUE;
                motor_auto_tweak_order_start_cnt++;
                next_state = MOTOR_CYCLE_WAIT_NO_CELL;
            }
            break;
       
        case MOTOR_CYCLE_WAIT_CELL:
            
            break;
            
        case MOTOR_CYCLE_WAIT_NO_CELL:
            if(motor_auto_pulses_tweak == FALSE)
            {
                motor_auto_tweak_order_end_cnt++;
                motor_auto_cycle_count = 0x00;
                next_state = MOTOR_CYCLE_WAIT_COUNT;
            }
            break;
            
     
    }
    motor_auto_cycle_state = next_state;
}
void motor_auto_sm(void)
{
    u16 temp16;
    u32 temp32;
    float temp_float;
    u8 next_state = motor_auto_state;
    
    motor_auto_cycle_sm(); // ME de gestion des cycles
    
    
    
    if(motor_auto_state > MOTOR_AUTO_DISPLAY && 
       motor_auto_state <  MOTOR_AUTO_ANALYSE_BRAKE)
    {
        
        temp16 = motor_auto_vcc_ref  /20;
        
        //if(motor_init_vcc_ref = adc_vbat;
        if( (adc_vbat > (motor_auto_vcc_ref + temp16)) 
            //||(adc_vbat < (motor_auto_vcc_ref - temp16))
          )
        {
            error(ERROR_VCC_RIPPLE_LIGHT);
            motor_auto_state = MOTOR_AUTO_NOP;
            return;
        }
    }
    
    
    switch(motor_auto_state)
    {
        case MOTOR_AUTO_NOP:
            motor_auto_scrolling = 0;
            break;
        
            
        case MOTOR_AUTO_ERROR_STOP:
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                motor_slope_run();
                next_state = MOTOR_AUTO_ERROR_STOP2;     
            break;
            
        case MOTOR_AUTO_ERROR_STOP2:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_slope_calc_phase(motor.error_mode.init_phase_list[0]);
                motor_slope_run();
                next_state = MOTOR_AUTO_ERROR_STOP3;   
            }
            break;
            
        case MOTOR_AUTO_ERROR_STOP3:
            if(motor_slope_is_idle() == TRUE)
            {
                next_state = MOTOR_AUTO_NOP;
            }
            break;
        
            
        case MOTOR_AUTO_START:
            if(motor_slope_is_idle() == TRUE)
            {
                eeprom_ev_write1(EEPROM_EV_PREAUTO1_START);
                
                // Map des timers
                motor_auto_timer_timeout_ms = &motor_timer_ms;
                motor_auto_timer_inhib_ms = &motor_timer2_ms;
                motor_auto_timer_tempo_ms = &motor_timer3_ms;
                
                // Les moteurs sont placés en tension d'affiche
                motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[0]);
                motor_slope_run();
                  
                // Initialisation de la structure qui contient les paramètres des affiches
                poster_init(motor.preauto_auto.preauto_enrh_full_speed_time,motor.preauto_auto.preauto_enrl_full_speed_time,1000);
                    
                // Initialisation du sens de défilement
                motor_direction = ENRH;
                // RAZ du compteur d'affiche
                motor_auto_poster_index = 0x00;
                
                // On se prépare à attendre sur la première affiche
                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].show_time;
                
                // Passage dans un autre état.
                next_state = MOTOR_AUTO_DISPLAY; 
                
            }
            break;
            
        case MOTOR_AUTO_INIT_STOP1:
            if(motor_slope_is_idle() == TRUE)
            {
               motor_auto_cycle_init_param = FALSE; 
               motorh_slope_xx_xs(motor.minimum_speed_value,100);
               motorl_slope_xx_xs(motor.minimum_speed_value,100);
               next_state = MOTOR_AUTO_INIT_STOP2;
            }
            break;
        
                 
        case MOTOR_AUTO_INIT_STOP2:
            motor_init_init_with_clear_params();
            next_state = MOTOR_AUTO_NOP;
            break;
        
            
        case MOTOR_AUTO_DISPLAY: // AFFICHAGE 
            motor_auto_scrolling = FALSE;
            motor_critical_drive = FALSE;
            
            if(btldr_stop_scrolling == FALSE)
            {
                if( motor.family != MOTOR_ASYNC_FAMILY && motor_auto_cycle_init_param==TRUE)
                {
                    motor_auto_cycle_init_param = FALSE;
                    motor_auto_state = MOTOR_AUTO_INIT_STOP1;
                    return;
                }


                // Si demande de preauto suite à une erreur legère
                if((motor_slope_is_idle() == TRUE) && (motor_auto_poster_index == 0x00) && (error_order_preauto==TRUE) && (motor_algo_mode == AUTO_MODE))
                {

                    error_order_preauto = 0;

                    if(cell_feature)
                    {
                        if(motor.family == MOTOR_ASYNC_FAMILY)
                        {
                            if(motor.enrh_dock_speed_incr != 0 || motor.enrl_dock_speed_incr != 0)
                            {
                               motor_auto_cycle_init_param = TRUE;
                            }
                            else
                            {
                                eeprom_ev_write1(EEPROM_EV_NEW_PREAUTO);
                                motor_algo_mode     = PREAUTO_MODE;
                                next_state          = MOTOR_AUTO_START;
                            }
                        }
                        else
                        {
                            eeprom_ev_write1(EEPROM_EV_NEW_PREAUTO);
                            motor_algo_mode     = PREAUTO_MODE;
                            next_state          = MOTOR_AUTO_START;
                        }
                    }
                    

                }

                else if(
                        (motor_slope_is_idle() == TRUE) && (motor_algo_mode == AUTO_MODE) && (synchro_ext_mode == TRUE) && 
                        (temporary_stop == FALSE) &&
                        (adc_low_battery == FALSE)

                        )
                {
                    if( 
                        ((motor_auto_poster_index == 0x00) && (synchro_ext_long_pulse == TRUE)) ||
                        ((motor_auto_poster_index >  0x00) && ((synchro_ext_short_pulse == TRUE) || (synchro_ext_long_pulse == TRUE)))
                      )    
                    {
                        synchro_ext_short_pulse = FALSE;
                        synchro_ext_long_pulse = FALSE;

                        if(motor_direction == ENRH)
                        {
                            // Si on est sur la dernière affiche en mode montée
                            if(motor_auto_poster_index == (motor_init_poster_count-1)) motor_direction = ENRL;
                            // Passage dans un autre état.
                            next_state = MOTOR_AUTO_SLOPE_TO_FULL_SPEED; 
                        }
                        else
                        {
                            if(motor_auto_poster_index == 0)  motor_direction = ENRH;
                            next_state = MOTOR_AUTO_SLOPE_TO_FULL_SPEED; 
                        }
                    }
                }


                // Si le temps d'affichage est terminé
                else if( ((*motor_auto_timer_tempo_ms) == 0x00) && (motor_slope_is_idle() == TRUE) ) 
                {  
                    if(motor_direction == ENRH) // si on défile vers le haut (vers bande mère basse)
                    {
                        // Si on est sur la dernière affiche en mode montée
                        if(motor_auto_poster_index == (motor_init_poster_count-1))
                        {
                            // On place maintenant la ME en descente
                            motor_direction         = ENRL;

                            if(motor_init_poster_count >2)
                            {
                                // On attend à nouveau sur cette affiche là car il s'agit d'une affiche extreme
                                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].show_time;
                            }
                            else
                            {
                                // On attend à nouveau sur cette affiche là car il s'agit d'une affiche extreme
                                (*motor_auto_timer_tempo_ms) = 0x00;
                            }
                        }
                        else
                        {
                            // Passage dans un autre état.
                            if((temporary_stop == FALSE))
                            {
                               next_state = MOTOR_AUTO_SLOPE_TO_FULL_SPEED; 
                            }
                        }
                    }
                    else // Si on est en descente
                    {
                        // Si on est sur la première affiche en mode descente
                        if(motor_auto_poster_index == 0)
                        {
                            if( (adc_low_battery == FALSE) && (temporary_stop == FALSE))
                            {
                                // On place la ME en mode montée
                                motor_direction         = ENRH;

                                if(motor_init_poster_count >2)
                                {
                                    // On attend à nouveau sur cette affiche là car il s'agit d'une affiche extreme
                                    (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].show_time;
                                }
                                else
                                {
                                    // On attend à nouveau sur cette affiche là car il s'agit d'une affiche extreme
                                    (*motor_auto_timer_tempo_ms) = 0x00;
                                }


                                // En fonction du mode dans lequel on se trouve on passe au mode suivant
                                if(motor_algo_mode == PREAUTO_MODE) 
                                {

                                    eeprom_ev_write1(EEPROM_EV_PREAUTO2_START);
                                    motor_algo_mode = PREAUTO2_MODE;
                                }
                                else if(motor_algo_mode == PREAUTO2_MODE) 
                                {
                                    eeprom_ev_write1(EEPROM_EV_PREAUTO3_START);
                                    motor_algo_mode = PREAUTO3_MODE;
                                }
                                else if(motor_algo_mode == PREAUTO3_MODE)  
                                {
                                    
                        
                                    
                                    eeprom_ev_write1(EEPROM_EV_AUTO_START);
                                    // Passage en mode AUTO
                                    motor_algo_mode = AUTO_MODE;

                                    // Initialisation des durées d'affichage
                                    for(temp16=0;temp16<5;temp16++) poster[temp16].show_time = POSTER_SHOWTIME;


                                    if(motor_auto_pulses_adjust)
                                    {
                                        motor_auto_pulses_adjust = FALSE;
                                        motor_pulses_poster[0] = poster[0].cell_pulses;
                                        motor_pulses_poster[1] = poster[1].cell_pulses;
                                        motor_pulses_poster[2] = poster[2].cell_pulses;
                                        motor_pulses_poster[3] = poster[3].cell_pulses;
                                        motor_pulses_poster[4] = poster[4].cell_pulses;
                                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER0);
                                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER1);
                                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER2);
                                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER3);
                                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER4);
                                    }
                                    
                                    // Sauvegarde des ajustements de vitesses pour les moteurs asynchrones
                                    motor_save_enrh_dock_speed_incr = motor.enrh_dock_speed_incr;
                                    motor_save_enrl_dock_speed_incr = motor.enrl_dock_speed_incr;
                                    

                                } 

                            }


                        }
                        else
                        {
                            if((temporary_stop == FALSE))
                            {
                               next_state = MOTOR_AUTO_SLOPE_TO_FULL_SPEED; 
                            }
                        } 
                    }
                }


                if(next_state == MOTOR_AUTO_SLOPE_TO_FULL_SPEED)
                {
                    
                    
                    motor_timeout_adjust_by_speed_incr();
                    
                    motor_auto_vcc_ref = adc_vbat;
                            
                    motor_auto_cell_phase = 0x00;
                    
                    motor_auto_pulses_comp = FALSE;
                    // RAZ du compteur de pulses
                    timer_pulses_clear();
                    //
                    motor_auto_scrolling = 1;
                    //
                    if(cell_feature)
                    {
                        (*motor_auto_timer_tempo_ms) = 0x00;
                        // On reinitialise le compteur de temps qui gère le timeout cellule
                        (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                        
                        
                    }
                    else
                    {
                        
                        next_state = MOTOR_AUTO_NO_CELL_SLOPE_TO_FULL_SPEED;
                        (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                        (*motor_auto_timer_tempo_ms) = 2000;
                        timer_pulses_clear();
                    }
                    //
                    cell_reset();

                    // On reinitialise le compteur de temps qui gère l'inhibition de la celule
                    (*motor_auto_timer_inhib_ms) = motor.preauto_auto.cell_inhib_time_pastille;
                   


                    if(motor_direction == ENRH)
                    {
                        // on decrement le compteur d'affiche
                        motor_auto_poster_index++;
                        // on se prépare à faire une rampe vers la grande vitesse
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[1]);  
                        motor_slope_run();

                        poster[motor_auto_poster_index]._enrh_poster_pulses = poster[motor_auto_poster_index].cell_pulses;

                    }
                    else
                    {
                        // on decrement le compteur d'affiche
                        motor_auto_poster_index--;
                        // on se prépare à faire une rampe vers la grande vitesse
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[1]);  
                        motor_slope_run();

                        poster[motor_auto_poster_index]._enrl_poster_pulses = poster[motor_auto_poster_index].cell_pulses;
                    }
                    
                    motor_preauto_timestamp1 = (*motor_auto_timer_timeout_ms);



                }
            }
            
            
            break;
        
        // <editor-fold defaultstate="collapsed" desc="SANS PASTILLE - REMONTEE SUITE A ERREUR DE PULSES > 85% DERNI7RE AFFICHE">           
        case MOTOR_AUTO_NO_CELL_NO_PULSES_1:
       
            motorh_slope_ms_ms(motor.preauto_auto.enrl_phase_list[1].motorh_mode_dir,
                               motor.preauto_auto.enrl_phase_list[1].motorh_speed,
                               motor.preauto_auto.enrl_phase_list[1].motorh_mode_dir,
                               motor.preauto_auto.enrl_phase_list[1].motorh_speed,100);
            motorl_slope_ms_ms(motor.preauto_auto.enrl_phase_list[1].motorl_mode_dir,
                               motor.preauto_auto.enrl_phase_list[1].motorl_speed,
                               motor.preauto_auto.enrl_phase_list[1].motorl_mode_dir,
                               motor.preauto_auto.enrl_phase_list[1].motorl_speed,100);
            
            motor_slope_run();
            motor_auto_phase = 0x00;
            
            next_state = MOTOR_AUTO_NO_CELL_NO_PULSES_2;
            break;
            
        
        case MOTOR_AUTO_NO_CELL_NO_PULSES_2:
            if(motor_slope_is_idle() == TRUE)
            {
                if(motor_auto_phase == 0x00)
                {
                    motor_auto_phase = 0x01;
                    (*motor_auto_timer_tempo_ms) = 200;
                }
                else if(motor_auto_phase == 0x01)
                {
                    if((*motor_auto_timer_tempo_ms) == 0x00)
                    {
                        motorh_slope_xx_xs(motor.minimum_speed_value,100);
                        motorl_slope_xx_xs(motor.minimum_speed_value,100);
                        motor_slope_run();
                        
                        error(ERROR_MOTOR_PULSES_LIGHT2);
                        motor_auto_state = MOTOR_AUTO_NOP;
                        return;
                    }
                }
            }
            break;
        // </editor-fold>     
     
        // <editor-fold defaultstate="collapsed" desc="SANS PASTILLE - CALAGE AUTO">     
            
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON1:
            if( uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x01);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON2;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON2:
            if(uart_motor_protocole_is_ready())
            {
                
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x01);
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    uart_motor_protocole_send_packet();
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON3;
                
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    return;
                }
            }
            break;
        
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    timer_pulses_clear();
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK1;    
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    return;
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK1:
            motorh_slope_ms_ms(motor.pulse_adjust_enrh.motorh_mode_dir,
                               motor.pulse_adjust_enrh.motorh_speed,
                               motor.pulse_adjust_enrh.motorh_mode_dir,
                               motor.pulse_adjust_enrh.motorh_speed,0);
            motorl_slope_ms_ms(motor.pulse_adjust_enrh.motorl_mode_dir,
                               motor.pulse_adjust_enrh.motorl_speed,
                               motor.pulse_adjust_enrh.motorl_mode_dir,
                               motor.pulse_adjust_enrh.motorl_speed,0);
            motor_slope_run();
            next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK2;
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK2:
            if(motor_slope_is_idle() == TRUE)
            {
               motor_auto_phase = 0x00;
               (*motor_auto_timer_timeout_ms) = 15000;
               (*motor_auto_timer_inhib_ms) = 2000;
                
                
                
               if(motor.model == MOTOR_MODEL_BRUSHLESS_PRISMA)
               {
                   if(pulses_feature && !cell_feature) motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/4));
               }
               else if(motor.model == MOTOR_MODEL_BRUSHLESS_HITO)
               {
                   if(pulses_feature && !cell_feature) motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/3));
               }
               else
               {
                   if(pulses_feature && !cell_feature) motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
               }
                
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK3;
            }
            break;
        
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK3:
            if(motor_slope_is_idle() == TRUE)
            {
                if((*motor_auto_timer_timeout_ms) == 0x00)
                {
                    error(ERROR_PULSES_TIMEOUT);
                    motor_auto_state = MOTOR_AUTO_NOP;
                    return;
                }
                else if((*motor_auto_timer_inhib_ms) == 0x00)
                {
                    (*motor_auto_timer_inhib_ms) = 1000;
                    motor_auto_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_auto_pulses_cnt2 = timer_pulses_get_valueL();
                    
                    if((motor_auto_pulses_cnt1 <10) && (motor_auto_pulses_cnt2 <10))
                    {
                        motor_auto_phase++;
                        if(motor_auto_phase >= 3)
                        {
                           motor_slope_calc_phase(motor.init_mode.init_phase_list[4]);
                           motor_slope_run();
                           next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK4;
                        }
                    }
                    
                    motor_auto_pulses_cnt1 = 0x00;
                    motor_auto_pulses_cnt2 = 0x00;
                    timer_pulses_clear(); 
                    timer_pulses_set_globalL(10000);
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK4:
            if(motor_slope_is_idle() == TRUE)
            {
                timer_pulses_clear(); 
                motorh_slope_ms_ms(motor.pulse_adjust_enrl.motorh_mode_dir,
                                   motor.pulse_adjust_enrl.motorh_speed,
                                   motor.pulse_adjust_enrl.motorh_mode_dir,
                                   motor.pulse_adjust_enrl.motorh_speed,100);
                motorl_slope_ms_ms(motor.pulse_adjust_enrl.motorl_mode_dir,
                                   motor.pulse_adjust_enrl.motorl_speed,
                                   motor.pulse_adjust_enrl.motorl_mode_dir,
                                   motor.pulse_adjust_enrl.motorl_speed,100);

                motor_slope_run();
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK5;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK5:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_slope_pulses_L(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                
                if(motor.model == MOTOR_MODEL_BRUSHLESS_HITO)
                {
                    motor_slope_pulses_H(motor.docking_pulses*2,(u16)(motor.pulse_adjust_enrl.motorh_speed*1.15));
                }
                
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK6;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK6:
            if(motor_slope_is_idle() == TRUE)
            {
                if(timer_pulses_get_valueL() == motor_pulses_count_extreme_tape_L)//motor.pulses_count_extreme_tape_L)
                {
                    motor_critical_drive = TRUE;
                    motor_slope_get_reg_speed();
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK7;
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK7:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_critical_drive = FALSE;
                motor_copy_phase_slope(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,0); 
                motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                motor_slope_run();
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK8;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK8:
            if(motor_slope_is_idle() == TRUE)
            {
                
                
                if(motor_algo_mode == PREAUTO_MODE)
                {
                    motor_auto_phase = 0x00;
                    (*motor_auto_timer_tempo_ms) = 3500;
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK9;
                }
                else
                {
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK15;
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK9:
            if((*motor_auto_timer_tempo_ms) == 0x00)
            {
                //next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK1;
                
                if(motor_auto_phase == 0x01)
                {
                    if(timer_pulses_get_globalL() < 10000)
                    {
                        motor_pulses_count_extreme_tape_L = (10000 - timer_pulses_get_globalL());
                    }
                    else
                    {
                        motor_pulses_count_extreme_tape_L = 0x00;
                    }
                    
                    eeprom_var16_update(EEPROM_VAR16_PULSES_EXTREME_TAPE_L);
                    motor_auto_phase = 0x00;   
                }
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK15;
            }
            else if(motor_manu_adjust_pulses)
            {
                (*motor_auto_timer_tempo_ms) = 3500;
                motor_auto_phase = 0x01;
            }
            break;
            
        
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK15:
            if(motor_slope_is_idle() == TRUE)
            {
                timer_pulses_set_globalH(poster[motor_init_poster_count-1].cell_pulses);
                timer_pulses_set_globalL(poster[motor_init_poster_count-1].cell_pulses);
                timer_pulses_clear(); 
                
                motor_auto_cycle_count++;
                motor_auto_cycle_count_total++;
                
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF1;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF1:
            if( uart_motor_protocole_is_mutex_free())
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x00);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF2;
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF2:
            if(uart_motor_protocole_is_ready())
            {
                
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_FILTER_MODE);
                    com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,0x00);
                    com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                    uart_motor_protocole_send_packet();
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF3;
                
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    return;
                }
            }
            break;
        
        case MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    (*motor_auto_timer_tempo_ms) = 1000;
                    timer_pulses_clear();
                    next_state = MOTOR_AUTO_DISPLAY;
                }
                else
                {
                    error(ERROR_COMM_WITH_SLAVES_LIGHT);
                    return;
                }
            }
            break;    
            
            
        // </editor-fold>     

        // <editor-fold defaultstate="collapsed" desc="SANS PASTILLE">      
        case MOTOR_AUTO_NO_CELL_SLOPE_TO_FULL_SPEED: // RAMPE VERS GRANDE VITESSE
        case MOTOR_AUTO_NO_CELL_FULL_SPEED: // MAINTIEN GRANDE VITESSE  
            if((*motor_auto_timer_timeout_ms) == 0x00)
            {
                if(motor_auto_poster_index == (motor_init_poster_count-1) &&
                  (timer_pulses_get_globalH() > (poster[motor_auto_poster_index].cell_pulses * 0.85)))      
                {
                    error_light2_state = motor_auto_state;
                    
                    next_state = MOTOR_AUTO_NO_CELL_NO_PULSES_1;
                }
                else
                {
                    error(ERROR_PULSES_TIMEOUT);
                    motor_auto_state = MOTOR_AUTO_NOP;
                    return;
                }
            }
            
            
            
            
            if((*motor_auto_timer_tempo_ms) == 0x00)
            {
                (*motor_auto_timer_tempo_ms) = 1000;
                // Comparaison des pulses des deux moteurs
                motor_auto_pulses_cnt1 = timer_pulses_get_valueH();
                motor_auto_pulses_cnt2 = timer_pulses_get_valueL();

                if( (motor_auto_pulses_cnt1 == 0x00) || 
                    (motor_auto_pulses_cnt2 == 0x00) || 
                    (motor_auto_pulses_cnt1 < (motor_auto_pulses_cnt2>>1)) ||
                    (motor_auto_pulses_cnt1 > (motor_auto_pulses_cnt2<<1)) ||
                    (motor_auto_pulses_cnt2 < (motor_auto_pulses_cnt1>>1)) ||
                    (motor_auto_pulses_cnt2 > (motor_auto_pulses_cnt1<<1)))
                {
                    
                    if(motor_auto_poster_index == (motor_init_poster_count-1) &&
                      (timer_pulses_get_globalH() > (poster[motor_auto_poster_index].cell_pulses * 0.85)))      
                    {
                        error_light2_state = motor_auto_state;
                        next_state = MOTOR_AUTO_NO_CELL_NO_PULSES_1;
                    }
                    else
                    {
                       error(ERROR_MOTOR_PULSES_LIGHT); error_light1_state = motor_auto_state;
                       motor_auto_state = MOTOR_AUTO_NOP;
                       return;
                    }
                }
                else
                {
                    
                    motor_auto_pulses_cnt1 = 0x00;
                    motor_auto_pulses_cnt2 = 0x00;
                    timer_pulses_clear();
                }
            }
            else
            {
                if(motor_direction == ENRH)
                {
                    if(timer_pulses_get_globalH() >= poster[motor_auto_poster_index]._enrh_TGV_AUTO)
                    {
                        (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                        poster[motor_auto_poster_index]._enrh_poster_pulses = poster[motor_auto_poster_index].cell_pulses - poster[motor_auto_poster_index]._enrh_TS2_AUTO;
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[2]);  
                        motor_slope_run();
                        next_state = MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED1;
                    }
                }
                else
                {
                    if(timer_pulses_get_globalH() <= poster[motor_auto_poster_index]._enrl_TGV_AUTO)
                    {
                        (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                        poster[motor_auto_poster_index]._enrl_poster_pulses = poster[motor_auto_poster_index].cell_pulses + poster[motor_auto_poster_index]._enrl_TS2_AUTO;
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[2]); 
                        motor_slope_run();
                        next_state = MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED1;
                    }
                }
            }
            
            break;
            
        case MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED1:
        case MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED2:
        case MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED3:    
            
            if(motor_slope_is_idle() == TRUE)
            {
                //motor_auto_vcc_ref = adc_vbat;
                if(motor_auto_state == MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED1)
                {
                    if(motor_direction == ENRH)
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[3]);  
                        motor_slope_run();
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[3]);  
                        motor_slope_run();
                    }
                    next_state = MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED2;
                }
                else if(motor_auto_state == MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED2)
                {
                    // SAUVEGARDE DE LA DUREE DE LA RAMPE
                    if(motor_direction == ENRH)
                    {
                        poster[motor_auto_poster_index]._enrh_TS1_AUTO = timer_pulses_get_globalH() - poster[motor_auto_poster_index]._enrh_TGV_AUTO;
                        motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                    }
                    else
                    {
                        poster[motor_auto_poster_index]._enrl_TS1_AUTO = poster[motor_auto_poster_index]._enrl_TGV_AUTO -  timer_pulses_get_globalH();
                        
                        motor_slope_pulses_L(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                    }
                    
                    next_state = MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED3;
                    
                    
                }
                else
                {
                    if(motor_direction == ENRH)
                    {
                        motor_auto_pulses_save = poster[motor_auto_poster_index]._enrh_poster_pulses;// - (motor.docking_pulses_security/5);
                    }
                    else
                    {
                        motor_auto_pulses_save = poster[motor_auto_poster_index]._enrl_poster_pulses;// + (motor.docking_pulses_security/5);
                    }
                    (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                    (*motor_auto_timer_tempo_ms) = 2000;
                    timer_pulses_clear();
                    next_state = MOTOR_AUTO_NO_CELL_DOCKING_SPEED1;
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_DOCKING_SPEED1:
        case MOTOR_AUTO_NO_CELL_DOCKING_SPEED2:    
            if((*motor_auto_timer_timeout_ms) == 0x00)
            {
                if(motor_auto_poster_index == (motor_init_poster_count-1) &&
                  (timer_pulses_get_globalH() > (poster[motor_auto_poster_index].cell_pulses * 0.85)))      
                {
                    error_light2_state = motor_auto_state;
                    next_state = MOTOR_AUTO_NO_CELL_NO_PULSES_1;
                }
                else
                {
                    error(ERROR_PULSES_TIMEOUT);
                    motor_auto_state = MOTOR_AUTO_NOP;
                    return;
                }
            }
            
            if((*motor_auto_timer_tempo_ms) == 0x00)
            {
                (*motor_auto_timer_tempo_ms) = 1000;
                // Comparaison des pulses des deux moteurs
                motor_auto_pulses_cnt1 = timer_pulses_get_valueH();
                motor_auto_pulses_cnt2 = timer_pulses_get_valueL();

                
                if( (motor_auto_pulses_cnt1 == 0x00) || 
                    (motor_auto_pulses_cnt2 == 0x00) || 
                    (motor_auto_pulses_cnt1 < (motor_auto_pulses_cnt2>>1)) ||
                    (motor_auto_pulses_cnt1 > (motor_auto_pulses_cnt2<<1)) ||
                    (motor_auto_pulses_cnt2 < (motor_auto_pulses_cnt1>>1)) ||
                    (motor_auto_pulses_cnt2 > (motor_auto_pulses_cnt1<<1)))
                {
                    if(motor_auto_poster_index == (motor_init_poster_count-1) &&
                      (timer_pulses_get_globalH() > (poster[motor_auto_poster_index].cell_pulses * 0.85)))      
                    {
                        error_light2_state = motor_auto_state;
                        next_state = MOTOR_AUTO_NO_CELL_NO_PULSES_1;
                    }
                    else
                    {
                       error(ERROR_MOTOR_PULSES_LIGHT); error_light1_state = motor_auto_state;
                       motor_auto_state = MOTOR_AUTO_NOP;
                       return;
                    }
                }
                else
                {
                    motor_auto_pulses_cnt1 = 0x00;
                    motor_auto_pulses_cnt2 = 0x00;
                    timer_pulses_clear();

                }
            }
            else
            {
                if(motor_auto_state == MOTOR_AUTO_NO_CELL_DOCKING_SPEED1)
                {
                    if(motor_direction == ENRH)
                    {
                        if(timer_pulses_get_globalH() >= motor_auto_pulses_save)
                        {
                            motor_critical_drive = TRUE;
                            motor_slope_get_reg_speed();
                            next_state = MOTOR_AUTO_NO_CELL_DOCKING_SPEED2;
                        }
                    }
                    else
                    {
                        if(timer_pulses_get_globalH() <= motor_auto_pulses_save)
                        {
                            motor_critical_drive = TRUE;
                            motor_slope_get_reg_speed();
                            next_state = MOTOR_AUTO_NO_CELL_DOCKING_SPEED2;
                        }
                    }
                }
                else
                {
                    if(motor_slope_is_idle() == TRUE)
                    {
                        temp16 = timer_pulses_get_globalH();
                        if(motor_direction == ENRH)
                        {
                            
                            if(temp16 >= (poster[motor_auto_poster_index]._enrh_poster_pulses))
                            {
                                if(motor_algo_mode == PREAUTO_MODE)
                                {
                                   motor_copy_phase_slope(&motor.preauto_auto.enrh_phase_list[5],&motor_auto_phase_pulses_cell,0); 
                                }
                                else
                                {
                                    if(motor.model == MOTOR_MODEL_BRUSHLESS_HITO) motor_copy_phase_slope(&motor.preauto_auto.enrh_phase_list[5],&motor_auto_phase_pulses_cell,0);
                                    else motor_copy_phase_slope(&motor.preauto_auto.enrh_phase_list[5],&motor_auto_phase_pulses_cell,50);
                                   
                                }
                                
                                // Préparation de la rampe de deceleration 
                                motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                                // Ordre de rampe.
                                motor_slope_run();
                                (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                                next_state = MOTOR_AUTO_NO_CELL_POSTER_STOP_STICKER1;
                            }
                        }
                        else
                        {
                            if(temp16 <= (poster[motor_auto_poster_index]._enrl_poster_pulses))
                            {
                                if(motor_algo_mode == PREAUTO_MODE)
                                {
                                    motor_copy_phase_slope(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,0);
                                }
                                else
                                {
                                    if(motor.model == MOTOR_MODEL_BRUSHLESS_HITO) motor_copy_phase_slope(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,0);
                                    else motor_copy_phase_slope(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,50);
                                }
                                // Préparation de la rampe de deceleration 
                                motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                                // Ordre de rampe.
                                motor_slope_run();
                                (*motor_auto_timer_timeout_ms) = (motor.preauto_auto.cell_timeout_time*2);
                                next_state = MOTOR_AUTO_NO_CELL_POSTER_STOP_STICKER1;
                            }
                        }
                    }
                }
            }
            break;
            
            
            
        case MOTOR_AUTO_NO_CELL_POSTER_STOP_STICKER1:
            if((*motor_auto_timer_timeout_ms) == 0x00)
            {
                error(ERROR_PULSES_TIMEOUT);
                motor_auto_state = MOTOR_AUTO_NOP;
                return;
            }
            
            if(motor_slope_is_idle() == TRUE)
            {
                //motor_auto_vcc_ref = adc_vbat;
                
                motor_critical_drive = FALSE;
                temp16 = timer_pulses_get_globalH();
                
                if(motor_algo_mode != PREAUTO_MODE)
                {
                    if(motor_direction == ENRH)
                    {

                        if(poster[motor_auto_poster_index]._enrh_TS2_AUTO == 0)
                        {
                            if(temp16>=poster[motor_auto_poster_index].cell_pulses) poster[motor_auto_poster_index]._enrh_TS2_AUTO = (temp16-poster[motor_auto_poster_index].cell_pulses);
                        }
                        else
                        {
                            if(temp16>=poster[motor_auto_poster_index].cell_pulses)
                            {
                                poster[motor_auto_poster_index]._enrh_TS2_AUTO+=(temp16-poster[motor_auto_poster_index].cell_pulses);
                            }
                            else
                            {
                                if(poster[motor_auto_poster_index]._enrh_TS2_AUTO >= (poster[motor_auto_poster_index].cell_pulses-temp16))
                                {
                                    poster[motor_auto_poster_index]._enrh_TS2_AUTO-=(poster[motor_auto_poster_index].cell_pulses-temp16);
                                }
                                else poster[motor_auto_poster_index]._enrh_TS2_AUTO = 0x00;
                            }
                        }

                        poster[motor_auto_poster_index]._enrh_TGV_AUTO = poster[motor_auto_poster_index].cell_pulses - 
                                                              poster[motor_auto_poster_index]._enrh_TS2_AUTO - 
                                                              poster[motor_auto_poster_index]._enrh_TS1_AUTO -
                                                              motor.docking_pulses_security;
                    }
                    else
                    {
                        if(poster[motor_auto_poster_index]._enrl_TS2_AUTO == 0)
                        {
                            if(temp16<=poster[motor_auto_poster_index].cell_pulses) poster[motor_auto_poster_index]._enrl_TS2_AUTO = (poster[motor_auto_poster_index].cell_pulses - temp16);
                        }
                        else
                        {
                            if(temp16<=poster[motor_auto_poster_index].cell_pulses)
                            {
                                poster[motor_auto_poster_index]._enrl_TS2_AUTO += (poster[motor_auto_poster_index].cell_pulses-temp16);
                            }
                            else
                            {
                                if(poster[motor_auto_poster_index]._enrl_TS2_AUTO >=(temp16-poster[motor_auto_poster_index].cell_pulses))
                                {
                                    poster[motor_auto_poster_index]._enrl_TS2_AUTO -= (temp16-poster[motor_auto_poster_index].cell_pulses);
                                }
                                else poster[motor_auto_poster_index]._enrl_TS2_AUTO = 0x00;
                            }
                        }

                        poster[motor_auto_poster_index]._enrl_TGV_AUTO = poster[motor_auto_poster_index].cell_pulses + 
                                                              poster[motor_auto_poster_index]._enrl_TS2_AUTO + 
                                                              poster[motor_auto_poster_index]._enrl_TS1_AUTO +
                                                              motor.docking_pulses_security;
                    }
                }
                
                
                if(motor_algo_mode > PREAUTO_MODE)
                {
                    motor_auto_cycle_count++;
                    motor_auto_cycle_count_total++;
                    
                    (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].show_time;
                    if((motor_auto_pulses_tweak == TRUE) && (motor_auto_poster_index == (motor_init_poster_count-1)))
                    {
                        motor_auto_tweak_count++;
                        motor_auto_pulses_tweak = FALSE;
                        next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON1;
                    }
                    else 
                    {
                        if((motor_algo_mode == PREAUTO3_MODE) &&
                           ((motor_auto_poster_index == (motor_init_poster_count-1)))
                        )
                        {
                            next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON1;
                        }
                        else
                        {
                            //next_state = MOTOR_AUTO_DISPLAY;  
                            
                            next_state = MOTOR_AUTO_ANALYSE_BRAKE;
                        }
                    }
                }
                else if(motor_algo_mode == PREAUTO_MODE)
                {
                    motor_auto_phase = 0x00;
                    (*motor_auto_timer_tempo_ms) = 3500;
                    next_state = MOTOR_AUTO_NO_CELL_POSTER_ADJUST;
                }
            }
            break;
            
        case MOTOR_AUTO_NO_CELL_POSTER_ADJUST:
            if((*motor_auto_timer_tempo_ms) == 0x00)
            {
                if(motor_auto_phase == 0x01)
                {
                    poster[motor_auto_poster_index].cell_pulses = timer_pulses_get_globalH();   
                    motor_auto_process_pulses_poster();
                    motor_auto_phase = 0x00;   
                    motor_auto_pulses_adjust = TRUE;
                }
                
                
                if(motor_auto_poster_index == (motor_init_poster_count-1))
                {
                    next_state = MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON1;
                }
                else
                {
                    (*motor_auto_timer_tempo_ms) = 1000;
                    next_state = MOTOR_AUTO_DISPLAY;
                }
                
            }
            else if(motor_manu_adjust_pulses)
            {
                (*motor_auto_timer_tempo_ms) = 3500;
                motor_auto_phase = 0x01;
            }
            break;
            // </editor-fold> 
    
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        
            
            
            
            
            
            
            
            
            
            
        case MOTOR_AUTO_SLOPE_TO_FULL_SPEED: // RAMPE VERS GRANDE VITESSE
        case MOTOR_AUTO_FULL_SPEED: // MAINTIEN GRANDE VITESSE  
            if(motor_auto_cell_phase == 0x00)
            {
                if((*motor_auto_timer_inhib_ms) == 0x00)
                {
                    error(ERROR_EXTREME_TAPE_IN_AUTO);
                    motor_auto_state = MOTOR_AUTO_NOP;
                    return;
                }
                else if(cell == CELL_INACTIVE_LEVEL)
                {
                    cell_event = FALSE;
                    cell_time = 0x00;
                    motor_auto_cell_phase = 1;
                    (*motor_auto_timer_inhib_ms) = motor.preauto_auto.cell_inhib_time_pastille;
                }
            }
            else if(motor_auto_cell_phase == 0x01)
            {
                if((*motor_auto_timer_inhib_ms) == 0x00)
                {
                    cell_event = FALSE;
                    cell_time  = 0x00;
                    motor_auto_cell_phase = 2;
                }
            }
            else
            {
                if((cell_event == TRUE))
                {
                    cell_event = FALSE;
                    if((cell_event_time > CELLULE_PASTILLE_MIN_MS) && 
                                  (cell_event_time < (CELLULE_BANDE_MERE_MS)))
                    {
                        error(ERROR_STICKER_DURING_FULL_SPEED);
                        motor_auto_state = MOTOR_AUTO_NOP;
                        return;
                    }   
                } 
            }
            
            if(motor_auto_cell_phase >= 0x01)
            {
                if(cell_time > (CELLULE_BANDE_MERE_MS))
                {
                    error(ERROR_EXTREME_TAPE_IN_AUTO);
                    motor_auto_state = MOTOR_AUTO_NOP;
                    return;
                }
            }

           
            
            
            if(motor_auto_state == MOTOR_AUTO_SLOPE_TO_FULL_SPEED)
            {
                if(motor_slope_is_idle() == TRUE)
                {
                    //motor_auto_vcc_ref = adc_vbat;
                        if(pulses_feature == FALSE)
                        {
                            // Sauvegarde du timestamp
                            motor_preauto_timestamp2 = (*motor_auto_timer_timeout_ms);
                            // Calcul du delta par rapport au timestamp précédent
                            temp16 = (motor_preauto_timestamp1 - motor_preauto_timestamp2);
                        }
                        else
                        {
                            // Sauvegarde du compteur de pulses
                            if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                            else                        temp16 = timer_pulses_get_valueL();
                            // RAZ du compteur de pulses
                            //timer_pulses_clear();
                        }

                        // Si phase de préauto
                        if(motor_algo_mode != AUTO_MODE)
                        {
                            // En fonction du mode et du sens on sauvegarde le résultat dans le tableau dédié
                            if(motor_direction == ENRH)
                            {
                                    if(motor_algo_mode == PREAUTO_MODE) poster[motor_auto_poster_index]._enrh_TS1_1  = temp16;
                               else if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrh_TS1_2 = temp16;
                               else if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrh_TS1_3 = temp16;

                            }
                            else
                            {
                                    if(motor_algo_mode == PREAUTO_MODE) poster[motor_auto_poster_index]._enrl_TS1_1  = temp16;
                               else if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrl_TS1_2 = temp16;
                               else if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrl_TS1_3 = temp16;
                            }
                        }
                        // Si mode de fonctionnement "auto"
                        else
                        {
                            // Stockage de la valeur dans le tableau dédié en fonction du sens
                            if(motor_direction == ENRH)
                            {
                                poster[motor_auto_poster_index]._enrh_TS1_AUTO = temp16;
                            }
                            else
                            {
                                poster[motor_auto_poster_index]._enrl_TS1_AUTO = temp16;
                            }
                        }

                        // Si mode de fonctionnement sans points
                        if(pulses_feature == FALSE)
                        {
                            // En fonction du sens et de l'affiche on maintient cette grande vitesse pendant un certain temps.
                            if(motor_direction == ENRH)
                            {
                                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrh_full_speed_time;
                            }
                            else
                            {
                                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrl_full_speed_time;
                            }
                        }
                        // Si fonctionnement avec points
                        else
                        {
                            // Si mode "preauto phase 1"
                            if(motor_algo_mode == PREAUTO_MODE)
                            {
                                // nous ne connaissons pas encore le nombre de points de la grande vitesse
                                // Donc dans ce mode on commence par compter du temps.
                                // initialisation du compteur de temps en fonction du sens de défilement.
                                if(motor_direction == ENRH)
                                {
                                    (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrh_full_speed_time;
                                }
                                else
                                {
                                    (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrl_full_speed_time;
                                }
                            }
                            // Sinon nous connaissons le nombre de points et nous utilisons le compteur de temps
                            // pour gérer des erreurs (utilisation en timeout)
                            else (*motor_auto_timer_tempo_ms) = motor.preauto_auto.cell_timeout_time;
                        }
                        // Passage à l'état suivant
                        next_state = MOTOR_AUTO_FULL_SPEED;  
                        
                        
                        
                        if( motor.family == MOTOR_ASYNC_FAMILY && motor_auto_cycle_init_param==TRUE)
                        {
                            if(motor_direction == ENRH)
                            {
                                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrh_full_speed_time * 0.7 ;
                            }
                            else
                            {
                                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].enrl_full_speed_time * 0.7 ;
                            }
                        }    
                }
            }
            else if(motor_auto_state == MOTOR_AUTO_FULL_SPEED)
            {
                if( motor.family == MOTOR_ASYNC_FAMILY && motor_auto_cycle_init_param==TRUE )
                {
                    if((*motor_auto_timer_tempo_ms) == 0x00)
                    {
                        motor_auto_cycle_init_param = FALSE;
                        motor_auto_state = MOTOR_AUTO_INIT_STOP1;
                        return;
                    } 
                }
                else
                {
                    // Si mode de fonctionnement sans points
                    if(pulses_feature == FALSE)
                    {
                        // Si le compteur de temps est écoulé
                        if(((*motor_auto_timer_tempo_ms)==0x00))
                        {

                            
                            if(cell_time > (CELLULE_BANDE_MERE_MS))
                            {
                                error(ERROR_EXTREME_TAPE_IN_AUTO);
                                motor_auto_state = MOTOR_AUTO_NOP;
                                return;
                            }
                            

                            // Reinitialisation du compteur de temps pour le timeout
                            (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                            // On fait un cliché du timer.
                            // Cela permet de mesurer le temps de deceleration de la rampe
                            motor_preauto_timestamp1 = (*motor_auto_timer_timeout_ms);
                            // En fonction du sens on prépare une rampe de deceleration vers la petite vitesse
                            if(motor_direction == ENRH)
                            {
                                motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[2]);  
                            }
                            else
                            {
                                motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[2]); 
                            }
                            motor_slope_run();
                            // Passage à l'état suivant
                            next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1;
                        }
                    }
                    // Si mode de fonctionnement avec points
                    else
                    {
                        // Si première phase de préauto
                        if(motor_algo_mode == PREAUTO_MODE)
                        {
                            // Si le compteur de temps est écoulé (fin de la GV)
                            if(((*motor_auto_timer_tempo_ms)==0x00))
                            {
                                // Comparaison des pulses des deux moteurs
                                motor_auto_pulses_cnt1 = timer_pulses_get_valueH();
                                motor_auto_pulses_cnt2 = timer_pulses_get_valueL();

                                if( motor_auto_pulses_cnt1 == 0x00 ||
                                    motor_auto_pulses_cnt2 == 0x00 ||    
                                    (motor_auto_pulses_cnt1 < (motor_auto_pulses_cnt2>>1)) ||
                                    (motor_auto_pulses_cnt1 > (motor_auto_pulses_cnt2<<1)) ||
                                    (motor_auto_pulses_cnt2 < (motor_auto_pulses_cnt1>>1)) ||
                                    (motor_auto_pulses_cnt2 > (motor_auto_pulses_cnt1<<1)))

                                {
                                    error(ERROR_MOTOR_PULSES_LIGHT); error_light1_state = motor_auto_state;
                                    motor_auto_state = MOTOR_AUTO_NOP;
                                    return;
                                }

                                // Sauvegarde du compteur de pulses
                                if(motor_direction == ENRH) temp16 = motor_auto_pulses_cnt1;
                                else                        temp16 = motor_auto_pulses_cnt2;
                                // RAZ du compteur de pulses
                                //timer_pulses_clear();

                                // Sauvegarde du nombre de points en fonction du sens de défilement.
                                if(motor_direction == ENRH)
                                {
                                    poster[motor_auto_poster_index]._enrh_TGV1 = temp16;
                                    poster[motor_auto_poster_index]._enrh_TGV_AUTO = temp16;
                                    motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[2]);  
                                }
                                else
                                {
                                    poster[motor_auto_poster_index]._enrl_TGV1 = temp16;
                                    poster[motor_auto_poster_index]._enrl_TGV_AUTO = temp16;
                                    motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[2]); 
                                }
                                motor_slope_run();
                                // Passage à l'état suivant
                                next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1;
                            }
                        }
                        // Sinon 
                        else
                        {
                            if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                            else                        temp16 = timer_pulses_get_valueL();

                            // Si le bon nombre de points à été detecté.
                            if( (motor_direction == ENRH && temp16>=poster[motor_auto_poster_index]._enrh_TGV_AUTO) ||
                                (motor_direction == ENRL && temp16>=poster[motor_auto_poster_index]._enrl_TGV_AUTO))
                            {

                                if(motor_direction == ENRH && motor_algo_mode == PREAUTO2_MODE) 
                                    poster[motor_auto_poster_index]._enrh_TGV2 = poster[motor_auto_poster_index]._enrh_TGV_AUTO;
                                if(motor_direction == ENRH && motor_algo_mode == PREAUTO3_MODE) 
                                    poster[motor_auto_poster_index]._enrh_TGV3 = poster[motor_auto_poster_index]._enrh_TGV_AUTO;
                                if(motor_direction == ENRL && motor_algo_mode == PREAUTO2_MODE) 
                                    poster[motor_auto_poster_index]._enrl_TGV2 = poster[motor_auto_poster_index]._enrl_TGV_AUTO;
                                if(motor_direction == ENRL && motor_algo_mode == PREAUTO3_MODE) 
                                    poster[motor_auto_poster_index]._enrl_TGV3 = poster[motor_auto_poster_index]._enrl_TGV_AUTO;


                                // RAZ des compteurs de points.
                                //timer_pulses_clear();

                                // Préparation de la rampe de deceleration en fonction du ses de défilement.
                                if(motor_direction == ENRH)
                                {
                                    motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[2]);  
                                }
                                else
                                {
                                    motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[2]); 
                                }
                                motor_slope_run();
                                // Passage à l'état suivant
                                next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1;
                            }
                            // Sinon si le compteur de temps est écoulé
                            else if((*motor_auto_timer_tempo_ms) == 0x00)
                            {
                                // Le bon nombre de pulses n'a pas été détécté.
                                error(ERROR_MOTOR_PULSES_LIGHT); error_light1_state = motor_auto_state;
                                motor_auto_state = MOTOR_AUTO_NOP;
                                return;            
                            }
                        }
                    }
                }
            }
           
            break;
            
        case MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1: // DECELERATION VERS PETITE VITESSE - PHASE1
        case MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2: // DECELERATION VERS PETITE VITESSE - PHASE2
            
            // Si une pastille est vue pendant la rampe de décélération.
            if((cell_time > CELLULE_PASTILLE_MIN_MS))
            {
                // Si mode de fonctionnement sans points.
                if(pulses_feature == FALSE)
                {
                    // Si mode de fonctionnement "auto"
                    //PREAUTO_MODEif(motor_algo_mode == AUTO_MODE)
                    if(motor_algo_mode == AUTO_MODE || motor_algo_mode == PREAUTO_MODE)
                    {
                        // Ajustement du temps de grande vitesse à 90%
                        if(motor_direction == ENRH)
                        {
                            temp16 = poster[motor_auto_poster_index].enrh_full_speed_time;
                            temp16 = (temp16 / 100);
                            temp16 = temp16 * 80;
                            poster[motor_auto_poster_index].enrh_full_speed_time = temp16;
                        }
                        else
                        {
                            temp16 = poster[motor_auto_poster_index].enrl_full_speed_time;
                            temp16 = (temp16 / 100);
                            temp16 = temp16 * 80;
                            poster[motor_auto_poster_index].enrl_full_speed_time = temp16;
                        }
                    }

                    // Préparation de la rampe d'arret sur pastille en fonction du ses de défilement.
                    if(motor_direction == ENRH)
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[4]);  
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[4]); 
                    }  
                    
                    // Initialisation du compteur de temps pour gérer les timeouts.
                    (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                    
                    // Ordre de rampe
                    motor_slope_run();
                }
                // Si mode de fonctionnement avec points
                else
                {
                    
                    // 
                    if(motor_direction == ENRH)
                    {
                        temp16 = timer_pulses_get_valueH();
                        // Ajustement des points de la GV
                        poster[motor_auto_poster_index]._enrh_TGV_AUTO -= (motor.docking_pulses_security);
                        // Préparation de la rampe de décélération sur pastille
                        //motor_copy_phase_slope_div(&motor.preauto_auto.enrh_phase_list[3],&motor_auto_phase_pulses_cell,2);
                        motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                        
                    }
                    else
                    {
                        temp16 = timer_pulses_get_valueL();
                        // Ajustement des points de la GV
                        poster[motor_auto_poster_index]._enrl_TGV_AUTO -= (motor.docking_pulses_security);
                        // Préparation de la rampe de décélération sur pastille
                        //motor_copy_phase_slope_div(&motor.preauto_auto.enrl_phase_list[3],&motor_auto_phase_pulses_cell,2);
                        motor_slope_pulses_L(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                    }
                    // RAZ des compteurs de points
                    //timer_pulses_clear();
                    motor_auto_phase = 0x00;
                    motor_auto_pulses_save = temp16;
                    
                    // Calcul du nombre de points à atteindre avec de faire un arret brutal du mobilier
                    // Il s'agit de la moitié des points de la pastille moins quelques points de sécurité.
                    // Calcul du nombre de points à compter
                    motor_auto_pulses_cnt1 = poster[motor_auto_poster_index].cell_pulses/3;//(poster[motor_auto_poster_index].cell_pulses>>1) - (poster[motor_auto_poster_index].cell_pulses>>3);
                    
                    // Initialisation du compteur de temps pour gérer les timeouts.
                    (*motor_auto_timer_timeout_ms) = 100;
                }
                
                
                
                next_state = MOTOR_AUTO_POSTER_STOP_STICKER1;
            }
            else 
            {
                 if(pulses_feature && (motor_algo_mode != PREAUTO_MODE) && motor_auto_pulses_comp == FALSE)
                 {
                    // En fonction du sens on sauvegarde le compteur de pulses
                    if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                    else                        temp16 = timer_pulses_get_valueL();
                    
                    
                    if(motor_direction == ENRH)
                    {
                        if( (poster[motor_auto_poster_index]._enrh_poster_pulses - temp16) <= (motor.docking_pulses_security))
                        {
                            motor_auto_pulses_comp = TRUE;
                            motor_copy_phase_slope_div(&motor.preauto_auto.enrh_phase_list[3],&motor_auto_phase_pulses_cell,0);
                            motor_slope_run();
                            next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2;
                            // On reinitialise le compteur de temsp qui gère le timeout
                            (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                            // Sauvegarde d'une image du compteur de temps (celui du timeout par exemple)
                            // Cela permet de mesurer le temps passé à petite vitesse avant de voir la pastille
                            // Cette valeur sera utilisé après avoir vue la pastille.
                            motor_preauto_timestamp1 = (*motor_auto_timer_timeout_ms);
                            motor_auto_pulses_save = temp16;
                        }
                    }
                    else if(motor_direction == ENRL)
                    {
                        if( (poster[motor_auto_poster_index]._enrl_poster_pulses - temp16) <= (motor.docking_pulses_security))
                        {
                            motor_auto_pulses_comp = TRUE;
                            motor_copy_phase_slope_div(&motor.preauto_auto.enrl_phase_list[3],&motor_auto_phase_pulses_cell,0);
                            motor_slope_run();
                            next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2;
                            // On reinitialise le compteur de temsp qui gère le timeout
                            (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                            // Sauvegarde d'une image du compteur de temps (celui du timeout par exemple)
                            // Cela permet de mesurer le temps passé à petite vitesse avant de voir la pastille
                            // Cette valeur sera utilisé après avoir vue la pastille.
                            motor_preauto_timestamp1 = (*motor_auto_timer_timeout_ms);
                            
                            motor_auto_pulses_save = temp16;
                        }
                    }
                 }
            }
            
            if(motor_slope_is_idle() == TRUE)
            {
                //motor_auto_vcc_ref = adc_vbat;
                
                // Si la première phase de la rampe est terminée
                if(motor_auto_state == MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1)
                {
                    // on fonction du sens on prépare la seconde phase de deceleration
                    if(motor_direction == ENRH)
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[3]);  
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[3]); 
                    }
                    motor_slope_run();
                    
                    // Passage à l'état suivant (seconde phase de deceleration)
                    next_state = MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2;
                }
                // Si la seconde phase est terminée
                else if(motor_auto_state == MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2)
                {
                    if(pulses_feature == FALSE)
                    {
                        temp16 = (motor_preauto_timestamp1 - (*motor_auto_timer_timeout_ms));
                    }
                    else
                    {
                        // En fonction du sens on sauvegarde le compteur de pulses
                        if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                        else                        temp16 = timer_pulses_get_valueL();
                        // RAZ des compteurs de pulses
                        //timer_pulses_clear();
                        motor_auto_pulses_save = temp16;
                        
                        // Envoi d'une consigne au moteur esclave qui entraine
                        if(motor_direction == ENRH) motor_slope_pulses_H(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                        else motor_slope_pulses_L(motor.docking_pulses,(u16)(motor.maximum_speed_value/2));
                        
                    }
                    
                    
                    // Si on est en PREAUTO
                    if(motor_algo_mode == PREAUTO_MODE || motor_algo_mode == PREAUTO2_MODE || motor_algo_mode == PREAUTO3_MODE)
                    {
                        // En fonction du sens et de la passe de préauto on mémorise le temps de deceleration des deux rampes vers la petite vitesse
                        if(motor_direction == ENRH)
                        {
                            if(motor_algo_mode == PREAUTO_MODE) poster[motor_auto_poster_index]._enrh_TS2_1 = temp16;
                            if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrh_TS2_2 = temp16;
                            if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrh_TS2_3 = temp16;
                            
                        }
                        else
                        {
                            if(motor_algo_mode == PREAUTO_MODE) poster[motor_auto_poster_index]._enrl_TS2_1 = temp16;
                            if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrl_TS2_2 = temp16;
                            if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrl_TS2_3 = temp16;
                        }
                    }
                    else
                    {
                        if(motor_direction == ENRH)
                        {
                            poster[motor_auto_poster_index]._enrh_TS2_AUTO = temp16;
                        }
                        else
                        {
                            poster[motor_auto_poster_index]._enrl_TS2_AUTO = temp16;
                        }
                    }
                    
                    if(pulses_feature)
                    {
                        if(motor_algo_mode == PREAUTO_MODE) (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time*2;
                        else (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                    }
                    else
                    {
                        (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                        
                        
                    }
                    
                    // On reinitialise le compteur de temsp qui gère le timeout
                    //(*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                    // Sauvegarde d'une image du compteur de temps (celui du timeout par exemple)
                    // Cela permet de mesurer le temps passé à petite vitesse avant de voir la pastille
                    // Cette valeur sera utilisé après avoir vue la pastille.
                    motor_preauto_timestamp1 = (*motor_auto_timer_timeout_ms);
                    
                    
                    // Passage à l'état suivant
                    next_state =  MOTOR_AUTO_DOCKING_SPEED;
                    
                }
            }
            break;
            
        case MOTOR_AUTO_DOCKING_SPEED: // PETITE VITESSE
            // Si pas de pastille pendant un certain temps
            if((*motor_auto_timer_timeout_ms) == 0x00)
            {
                error(ERROR_STICKER_TIMEOUT_DURING_DOCKING_SPEED);
                motor_auto_state = MOTOR_AUTO_NOP;
                return;
                //next_state = MOTOR_AUTO_ERROR_STOP;
            }

            // Si une pastille est vue
            if(cell_time > CELLULE_PASTILLE_MIN_MS)
            {
                // Si mode de fonctionnement avec points.
                if(pulses_feature == TRUE)
                {
                    
                    // Comparaison des pulses des deux moteurs
                    motor_auto_pulses_cnt1 = timer_pulses_get_valueH();
                    motor_auto_pulses_cnt2 = timer_pulses_get_valueL();

                    if( (motor_auto_pulses_cnt1 < (motor_auto_pulses_cnt2>>1)) ||
                        (motor_auto_pulses_cnt1 > (motor_auto_pulses_cnt2<<1)) ||
                        (motor_auto_pulses_cnt2 < (motor_auto_pulses_cnt1>>1)) ||
                        (motor_auto_pulses_cnt2 > (motor_auto_pulses_cnt1<<1)))                   
                    {
                        error(ERROR_MOTOR_PULSES_LIGHT); error_light1_state = motor_auto_state;
                        motor_auto_state = MOTOR_AUTO_NOP;
                        return;
                    }
                            
                    // Leture du compteur de point en fonction du sens.
                    if(motor_direction == ENRH) temp16 = motor_auto_pulses_cnt1;
                    else                        temp16 = motor_auto_pulses_cnt2;
                    
                    // Si nous sommes en mode preauto alors on sauvegarde la taille de l'affiche en pulse.
                    if(motor_algo_mode == PREAUTO_MODE)
                    {
                        if(motor_direction == ENRH) poster[motor_auto_poster_index]._enrh_poster_pulses = temp16;
                        else poster[motor_auto_poster_index]._enrl_poster_pulses = temp16;
                    }
                    
                    // Soustraction des pulses à la fin de la rampe de deceleration
                    // Pour obtenir la duree de la petite vitesse
                    temp16-=motor_auto_pulses_save;
                    
                    // RAZ des compteurs de points.
                    timer_pulses_clear();
                    
                    // Sauvegarde et ajustement des points en fonction du sens.
                    if(motor_direction == ENRH)
                    {
                             if(motor_algo_mode == PREAUTO_MODE)  poster[motor_auto_poster_index]._enrh_T1 = temp16;
                        else if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrh_T2 = temp16;
                        else if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrh_T3 = temp16;
                        else if(motor_algo_mode == AUTO_MODE)     poster[motor_auto_poster_index]._enrh_T_AUTO = temp16;
                        
                        
                        // Compensation des points de la GV en fonction des points de la PV
                        if(temp16 > motor.docking_pulses_security)
                        {
                            poster[motor_auto_poster_index]._enrh_TGV_AUTO += (temp16-motor.docking_pulses_security);
                        }
                        else 
                        {
                            poster[motor_auto_poster_index]._enrh_TGV_AUTO -= (motor.docking_pulses_security-temp16);
                        }
                        
                             
                    }
                    else
                    {
                        if(motor_algo_mode == PREAUTO_MODE)  poster[motor_auto_poster_index]._enrl_T1 = temp16;
                        else if(motor_algo_mode == PREAUTO2_MODE) poster[motor_auto_poster_index]._enrl_T2 = temp16;
                        else if(motor_algo_mode == PREAUTO3_MODE) poster[motor_auto_poster_index]._enrl_T3 = temp16;
                        else if(motor_algo_mode == AUTO_MODE)     poster[motor_auto_poster_index]._enrl_T_AUTO = temp16;
                        
                        // Compensation des points de la GV en fonction des points de la PV
                        if(temp16 > motor.docking_pulses_security)
                        {
                            poster[motor_auto_poster_index]._enrl_TGV_AUTO += (temp16-motor.docking_pulses_security);
                        }
                        else 
                        {
                            poster[motor_auto_poster_index]._enrl_TGV_AUTO -= (motor.docking_pulses_security-temp16);
                        }
                        
                    }
                }
                // Si mode fonctionnement sans points
                else
                {
                    // Sauvegarde d'une image du compteur de temps (celui du timeout par exemple)
                    motor_preauto_timestamp2 = (*motor_auto_timer_timeout_ms);
                    temp16 = (motor_preauto_timestamp1 - motor_preauto_timestamp2); 
                    if(motor_algo_mode == PREAUTO_MODE || motor_algo_mode == PREAUTO2_MODE || motor_algo_mode == PREAUTO3_MODE)
                    {                
                        if(motor_direction == ENRH)
                        {
                            if(motor_algo_mode == PREAUTO_MODE)
                            {
                                poster[motor_auto_poster_index]._enrh_T1 = temp16;
                                if(temp16 > PREAUTO_SECURITY_TIME) poster[motor_auto_poster_index].enrh_comp1 = (temp16/6);
                                else poster[motor_auto_poster_index].enrh_comp1 = 0x00;

                                poster[motor_auto_poster_index].enrh_full_speed_time += poster[motor_auto_poster_index].enrh_comp1;
                            }
                            else if(motor_algo_mode == PREAUTO2_MODE)
                            {
                                poster[motor_auto_poster_index]._enrh_T2 = temp16;
                                if(poster[motor_auto_poster_index].enrh_comp1 == 0x00) poster[motor_auto_poster_index].enrh_comp2 = 0x00;
                                else
                                {
                                    if(temp16>PREAUTO_SECURITY_TIME)
                                    {
                                         temp32 = (poster[motor_auto_poster_index].enrh_comp1);
                                         temp32 = temp32*((u32)(poster[motor_auto_poster_index]._enrh_T2-PREAUTO_SECURITY_TIME));
                                         temp32 = temp32 / (poster[motor_auto_poster_index]._enrh_T1 - poster[motor_auto_poster_index]._enrh_T2); 
                                         poster[motor_auto_poster_index].enrh_comp2 = (u16)(temp32); 
                                         poster[motor_auto_poster_index].enrh_full_speed_time += poster[motor_auto_poster_index].enrh_comp2;
                                    }
                                    else if(temp16<PREAUTO_SECURITY_TIME)
                                    { 

                                         temp32 = (poster[motor_auto_poster_index].enrh_comp1);
                                         temp32 = temp32*((u32)(PREAUTO_SECURITY_TIME-poster[motor_auto_poster_index]._enrh_T2));
                                         temp32 = temp32 / (poster[motor_auto_poster_index]._enrh_T1 - poster[motor_auto_poster_index]._enrh_T2);
                                         poster[motor_auto_poster_index].enrh_comp2 = (u16)(temp32); 
                                         poster[motor_auto_poster_index].enrh_full_speed_time -= poster[motor_auto_poster_index].enrh_comp2;
                                    }
                                }
                            }
                            else if(motor_algo_mode == PREAUTO3_MODE)
                            {
                                poster[motor_auto_poster_index]._enrh_T3 = temp16;
                            }
                        }
                        else
                        {
                            if(motor_algo_mode == PREAUTO_MODE)
                            {
                                poster[motor_auto_poster_index]._enrl_T1 = temp16;

                                if(temp16 > PREAUTO_SECURITY_TIME) poster[motor_auto_poster_index].enrl_comp1 = (temp16/6);
                                else poster[motor_auto_poster_index].enrl_comp1 = 0x00;
                                poster[motor_auto_poster_index].enrl_full_speed_time += poster[motor_auto_poster_index].enrl_comp1;
                            }
                            else if(motor_algo_mode == PREAUTO2_MODE)
                            {
                                poster[motor_auto_poster_index]._enrl_T2 = temp16;

                                if(poster[motor_auto_poster_index].enrl_comp1 == 0x00) poster[motor_auto_poster_index].enrl_comp2 = 0x00;
                                else
                                {
                                    if(temp16>PREAUTO_SECURITY_TIME)
                                    {
                                         temp32 = (poster[motor_auto_poster_index].enrl_comp1);
                                         temp32 = temp32*((u32)(poster[motor_auto_poster_index]._enrl_T2-PREAUTO_SECURITY_TIME));
                                         temp32 = temp32 / (poster[motor_auto_poster_index]._enrl_T1 - poster[motor_auto_poster_index]._enrl_T2); 
                                         poster[motor_auto_poster_index].enrl_comp2 = (u16)(temp32); 
                                         poster[motor_auto_poster_index].enrl_full_speed_time += poster[motor_auto_poster_index].enrl_comp2;
                                    }
                                    else if(temp16<PREAUTO_SECURITY_TIME)
                                    { 

                                         temp32 = (poster[motor_auto_poster_index].enrl_comp1);
                                         temp32 = temp32*((u32)(PREAUTO_SECURITY_TIME-poster[motor_auto_poster_index]._enrl_T2));
                                         temp32 = temp32 / (poster[motor_auto_poster_index]._enrl_T1 - poster[motor_auto_poster_index]._enrl_T2);
                                         poster[motor_auto_poster_index].enrl_comp2 = (u16)(temp32); 
                                         poster[motor_auto_poster_index].enrl_full_speed_time -= poster[motor_auto_poster_index].enrl_comp2;
                                    }
                                }
                            }
                            else if(motor_algo_mode == PREAUTO3_MODE)
                            {
                                poster[motor_auto_poster_index]._enrl_T3 = temp16;

                            }  
                        }  
                    }
                    else
                    {
                        if(temp16>(PREAUTO_SECURITY_TIME*1.20))
                        {
                            if(motor_direction == ENRH)
                            {
                                temp16 = poster[motor_auto_poster_index].enrh_full_speed_time;
                                temp_float = temp16;
                                temp_float = temp_float*1.05;
                                //temp16 = temp16 / 100;
                                //temp16 = temp16 * 102;
                                poster[motor_auto_poster_index].enrh_full_speed_time  = (u16)temp_float;//temp16;
                            }   
                            else
                            {
                                temp16 = poster[motor_auto_poster_index].enrl_full_speed_time;
                                temp_float = temp16;
                                temp_float = temp_float*1.05;
                                //temp16 = temp16 / 100;
                                //temp16 = temp16 * 102;
                                poster[motor_auto_poster_index].enrl_full_speed_time  = (u16)temp_float;//temp16;
                            }
                        }
                        else if(temp16<(PREAUTO_SECURITY_TIME*0.8))
                        {
                            if(motor_direction == ENRH)
                            {
                                temp16 = poster[motor_auto_poster_index].enrh_full_speed_time;
                                temp_float = temp16;
                                temp_float = temp_float*0.95;
                                //temp16 = temp16 / 100;
                                //temp16 = temp16 * 102;
                                poster[motor_auto_poster_index].enrh_full_speed_time = (u16)temp_float;//temp16;
                            }   
                            else
                            {
                                temp16 = poster[motor_auto_poster_index].enrl_full_speed_time;
                                temp_float = temp16;
                                temp_float = temp_float*0.95;
                                //temp16 = temp16 / 100;
                                //temp16 = temp16 * 102;
                                poster[motor_auto_poster_index].enrl_full_speed_time = (u16)temp_float;//temp16;
                            }
                        }
                        if(motor_direction == ENRH)
                        {
                            poster[motor_auto_poster_index]._enrh_T_AUTO = temp16;
                        }
                        else
                        {
                            poster[motor_auto_poster_index]._enrl_T_AUTO = temp16;
                        }
                    }    
                }
                
                if(pulses_feature == TRUE)
                {
                    if(motor_direction == ENRH)
                    {
                        
                    }
                    else
                    {
                        
                    }
                    //motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                    // Calcul du nombre de points à compter
                    
                    if(motor.family == MOTOR_ASYNC_FAMILY)
                    {
                        motor_auto_pulses_cnt1 = poster[motor_auto_poster_index].cell_pulses/3;//(poster[motor_auto_poster_index].cell_pulses>>1) - (poster[motor_auto_poster_index].cell_pulses>>3);
                    }
                    else
                    {
                        motor_auto_pulses_cnt1 = poster[motor_auto_poster_index].cell_pulses/2 - (poster[motor_auto_poster_index].cell_pulses/10);
                    }
                    
                    
                    motor_auto_phase               = 0x00;
                    (*motor_auto_timer_timeout_ms) = 200;
                }
                else 
                {
                    if(motor_direction == ENRH)
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[4]);  
                    }
                    else
                    {
                        motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[4]); 
                    }
                    (*motor_auto_timer_timeout_ms) = motor.preauto_auto.cell_timeout_time;
                    motor_slope_run();
                }
                
                next_state = MOTOR_AUTO_POSTER_STOP_STICKER1;
            }
       
            break;
            
            
        
        case MOTOR_AUTO_POSTER_STOP_STICKER1:
        case MOTOR_AUTO_POSTER_STOP_STICKER2:   
            
            if(pulses_feature)
            {
                if(motor_auto_phase == 0x00) // Attente du bon nombre de points
                {
                    if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                    else                        temp16 = timer_pulses_get_valueL();

                    if(temp16 >= motor_auto_pulses_cnt1)
                    {
                        motor_auto_phase = 0x01;
                        
                        
                        
                        
                        /*motorh_slope_xx_xs(motor.minimum_speed_value,0);
                        motorl_slope_xx_xs(motor.minimum_speed_value,0);
                        motor_slope_run();*/
                        
                        motor_slope_get_reg_speed();
                    }
                }
                else if(motor_auto_phase == 0x01) // Attent de l'acquisition de la vitesse régulée
                {
                    if(motor_slope_is_idle() == TRUE)
                    {
                        motor_auto_phase = 0x02;

                        
                        
                        if(motor_direction == ENRH)
                        {
                            // On copie la rampe dans une structure locale
                            motor_copy_phase_slope(&motor.preauto_auto.enrh_phase_list[5],&motor_auto_phase_pulses_cell,100);
                        }
                        else
                        {
                            // On copie la rampe dans une structure locale
                            motor_copy_phase_slope(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,100);
                        }

                        // Préparation de la rampe de deceleration 
                        motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                        // Ordre de rampe.
                        motor_slope_run();
                    }
                }
                else if(motor_auto_phase == 0x02) // Attende de la fin de la rampe d'arret sur la pastille
                {
                    if(motor_slope_is_idle() == TRUE)
                    {
                        //motor_auto_vcc_ref = adc_vbat;
                    
                        next_state = MOTOR_AUTO_ANALYSE_BRAKE;
                    }
                }
                
                /*
                if(motor_direction == ENRH) temp16 = timer_pulses_get_valueH();
                else                        temp16 = timer_pulses_get_valueL();

                if((temp16 >= motor_auto_pulses_cnt1) && (motor_auto_phase == 0x00))
                {
                    motor_auto_phase = 1;

                    //motor_slope_get_reg_speed();
                    
                    
                    
                    if(motor_direction == ENRH)
                    {
                        // On copie la rampe dans une structure locale
                        motor_copy_phase_slope_div(&motor.preauto_auto.enrh_phase_list[5],&motor_auto_phase_pulses_cell,1);
                    }
                    else
                    {
                        // On copie la rampe dans une structure locale
                        motor_copy_phase_slope_div(&motor.preauto_auto.enrl_phase_list[5],&motor_auto_phase_pulses_cell,1);
                    }
                    
                    motor_auto_phase_pulses_cell.motorh_slope = 100;
                    motor_auto_phase_pulses_cell.motorl_slope = 100;
                    
                    
                    // Préparation de la rampe de deceleration 
                    motor_slope_calc_phase(motor_auto_phase_pulses_cell);
                    // Ordre de rampe.
                    motor_slope_run();
                }
                else if(motor_slope_is_idle() == TRUE && motor_auto_phase == 0x01)
                {
                    next_state = MOTOR_AUTO_ANALYSE_BRAKE;
                }*/
                    
                
            }
            else
            {
                if(motor_slope_is_idle() == TRUE )
                {
                    //motor_auto_vcc_ref = adc_vbat;
                    
                    if(motor_auto_state == MOTOR_AUTO_POSTER_STOP_STICKER1)
                    {
                        next_state = MOTOR_AUTO_POSTER_STOP_STICKER2;
                        if(motor_direction == ENRH)
                        {
                            motor_slope_calc_phase(motor.preauto_auto.enrh_phase_list[5]);  
                        }
                        else
                        {
                            motor_slope_calc_phase(motor.preauto_auto.enrl_phase_list[5]); 
                        }   
                        motor_slope_run();
                    }
                    else if(motor_auto_state == MOTOR_AUTO_POSTER_STOP_STICKER2)
                    {                    
                        next_state = MOTOR_AUTO_ANALYSE_BRAKE;
                    }
                }
            }
           
            break;
       
            
      
            
            
        case MOTOR_AUTO_ANALYSE_BRAKE:
            if(motor_slope_is_idle() == TRUE )
            {
                //motor_auto_vcc_ref = adc_vbat;
                
                if(motor_direction == ENRH && motorl_switch == TRUE)
                {
                    motorl_slope_mx_xs(PWM_TABLE_OFF,0,0);
                    motor_slope_run();

                }
                else if(motor_direction == ENRL && motorh_switch == TRUE)
                {
                    motorh_slope_mx_xs(PWM_TABLE_OFF,0,0);
                    motor_slope_run();
                }

                next_state = MOTOR_AUTO_BRAKE;
            }
            break;
         
        case MOTOR_AUTO_BRAKE: 
            if(motor_slope_is_idle() == TRUE )
            {
                // Incremantation du compteur de cycles pour la gestion des preauto forces.
                if(motor_algo_mode == AUTO_MODE)
                {
                    motor_auto_cycle_count++;
                    motor_auto_cycle_count_total++;
                }
                (*motor_auto_timer_tempo_ms) = poster[motor_auto_poster_index].show_time;
                next_state = MOTOR_AUTO_DISPLAY; 
            }
            break;
            
            
            
    }
    motor_auto_state = next_state;
        
}
