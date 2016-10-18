#include <_Global_Include.h>

struct struct_motor_status motor_status;

bool slave_status_extreme_change;
volatile u16 slave_status_time_counter;
u8 slave_status_state;
bool slave_status_mcu_high_temp;
bool slave_status_bridge_high_temp;
bool slave_status_bridge_emergency_temp;

bool slave_status_mcuh_high_temp    = FALSE;
bool slave_status_mcul_high_temp    = FALSE;
bool slave_status_bridgeh_high_temp = FALSE;
bool slave_status_bridgel_high_temp = FALSE;


void slave_status_init(void)
{
    timer1ms_register_variable((u16*)&slave_status_time_counter);
    slave_status_state = 0x00;
    
    motor_status.motorh_bridge_max_current     = 0;
    motor_status.motorh_bridge_min_current     = 10000;
    motor_status.motorh_bridge_max_temperature = 0;
    motor_status.motorh_bridge_min_temperature = 10000;
    motor_status.motorh_pic_max_temperature    = 0;
    motor_status.motorh_pic_min_temperature    = 10000;
    
    motor_status.motorl_bridge_max_current     = 0;
    motor_status.motorl_bridge_min_current     = 10000;
    motor_status.motorl_bridge_max_temperature = 0;
    motor_status.motorl_bridge_min_temperature = 10000;
    motor_status.motorl_pic_max_temperature    = 0;
    motor_status.motorl_pic_min_temperature    = 10000;
    
    slave_status_extreme_change                = FALSE;
    slave_status_mcu_high_temp                 = FALSE;
    slave_status_bridge_high_temp              = FALSE;
    slave_status_bridge_emergency_temp         = FALSE;
}

void slave_status_reset_sm(void)
{
    slave_status_state = 0;
    slave_status_time_counter = SLAVE_STATUS_POLLING_MS;
    uart_motor_protocole_release_mutex(); 
}
void slave_status_sm(void)
{
    volatile double d      = 0.0;
    double d1,d2,d3;
    u16 temp16    = 0x00;
    u8 next_state = slave_status_state;
    switch(slave_status_state)
    {
        case 0:
#ifdef SLAVE_STATUS_RUN_SLOPE
            if(slave_status_time_counter == 0x00 && uart_motor_protocole_is_mutex_free() == TRUE)
#else
            if(motor_slope_is_idle() == TRUE && slave_status_time_counter == 0x00 && uart_motor_protocole_is_mutex_free() == TRUE)
#endif
            {
                uart_motor_protocole_take_mutex();
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_STATUS);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = 1;
            }
            break;
            
        case 1:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                { 
                    // Recuperation de la temperature du PIC
                    temp16  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    temp16<<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1);
                    
                    d = (temp16 * 5.0) / 4096.0;
                    d = (0.630 - d);
                    d = (d/0.00256);
                    d += 25;

                    /*if(d> SLAVE_STATUS_MCU_HIGH_TEMP)
                    {
                        slave_status_mcu_high_temp = TRUE;
                    }*/
                    
                    if(d>-30.0 && d<150.0)
                    {
                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorh_pic_temperature_array[temp16] = motor_status.motorh_pic_temperature_array[temp16+1];
                        motor_status.motorh_pic_temperature_array[SLAVE_STATUS_SAMPLES-1] = d;
                        motor_status.motorh_pic_temperature = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorh_pic_temperature+=motor_status.motorh_pic_temperature_array[temp16];
                        motor_status.motorh_pic_temperature = (motor_status.motorh_pic_temperature/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorh_pic_temperature > motor_status.motorh_pic_max_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_pic_max_temperature = motor_status.motorh_pic_temperature;
                        }
                        else if(motor_status.motorh_pic_temperature < motor_status.motorh_pic_min_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_pic_min_temperature = motor_status.motorh_pic_temperature;
                        }
                    }
                    
                    // Recuperation du courant du pont
                    temp16  = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+2);
                    temp16<<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+3);
                    
                    d = (temp16 * 5.0) / 4096.0;
                    d = (d/11.0);
                    d = (d/0.04);
                    if(motor.family != MOTOR_ASYNC_FAMILY) d = d*0.85;
                    d = d*1000;
                    
                    if(d>0.0 && d< 20000.0)
                    {
                        if(d > SLAVE_STATUS_BRIDGE_EMERGENCY_CURRENT)
                        {
                            error(ERROR_BRIDGE_H_CURRENT);
                        }

                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorh_bridge_current_array[temp16] = motor_status.motorh_bridge_current_array[temp16+1];
                        motor_status.motorh_bridge_current_array[SLAVE_STATUS_SAMPLES-1] = d;
                        motor_status.motorh_bridge_current = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorh_bridge_current+=motor_status.motorh_bridge_current_array[temp16];
                        motor_status.motorh_bridge_current = (motor_status.motorh_bridge_current/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorh_bridge_current > motor_status.motorh_bridge_max_current)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_bridge_max_current = motor_status.motorh_bridge_current;
                        }
                        else if(motor_status.motorh_bridge_current < motor_status.motorh_bridge_min_current)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_bridge_min_current = motor_status.motorh_bridge_current;
                        }
                    }

                    // Recuperation de la temperature du pont
                    temp16 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+4);
                    temp16 <<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+5);
                    d = (temp16 * 5.0) / 4096.0;
                    d1 = (d * 100000.0)/(5.0-d);
                    d2 = ((log(d1/85000.0))/4200.0);
                    d2 += (1/298.15);
                    d2 = (1.0/d2);
                    d3 = d2-272.15;
                    
                    if(d3 > -30.0 && d3< 150.0)
                    {
                        if(d3 > SLAVE_STATUS_BRIDGE_EMERGENCY_TEMP)
                        {
                            slave_status_bridge_emergency_temp = TRUE;
                            //slave_status_bridge_high_temp      = TRUE;

                            motorh_slope_xx_xs(motor.minimum_speed_value,100);
                            motorl_slope_xx_xs(motor.minimum_speed_value,100);
                            motor_slope_run();

                        }
                        else if(d3 > SLAVE_STATUS_BRIDGE_HIGH_TEMP)
                        {
                            //slave_status_bridge_high_temp      = TRUE;
                        }




                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorh_bridge_temperature_array[temp16] = motor_status.motorh_bridge_temperature_array[temp16+1];
                        motor_status.motorh_bridge_temperature_array[SLAVE_STATUS_SAMPLES-1] = d3;
                        motor_status.motorh_bridge_temperature = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorh_bridge_temperature+=motor_status.motorh_bridge_temperature_array[temp16];
                        motor_status.motorh_bridge_temperature = (motor_status.motorh_bridge_temperature/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorh_bridge_temperature > motor_status.motorh_bridge_max_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_bridge_max_temperature = motor_status.motorh_bridge_temperature;
                        }
                        else if(motor_status.motorh_bridge_temperature < motor_status.motorh_bridge_min_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorh_bridge_min_temperature = motor_status.motorh_bridge_temperature;
                        }
                    }
                    
                    next_state = 2;
                }
                else
                {
                    uart_motor_protocole_release_mutex();
                    slave_status_time_counter = SLAVE_STATUS_POLLING_MS;
                    next_state = 0;
                }
                
                
            }
            break;
            
        case 2:
            com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_STATUS);
            com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
            uart_motor_protocole_send_packet();
            next_state = 3;
        break;
        
        case 3:
            if(uart_motor_protocole_get_status() != UART_MOTOR_PROTOCOLE_IN_PROGRESS)
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    // Recuperation de la temperature du PIC
                    temp16 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    temp16<<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1);
                    
                    d = (temp16 * 5.0) / 4096.0;
                    d = (0.630 - d);
                    d = (d/0.00256);
                    d += 25;

                    
                    if(d> -30.0 && d< 150.0)
                    {
                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorl_pic_temperature_array[temp16] = motor_status.motorl_pic_temperature_array[temp16+1];
                        motor_status.motorl_pic_temperature_array[SLAVE_STATUS_SAMPLES-1] = d;
                        motor_status.motorl_pic_temperature = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorl_pic_temperature+=motor_status.motorl_pic_temperature_array[temp16];
                        motor_status.motorl_pic_temperature = (motor_status.motorl_pic_temperature/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorl_pic_temperature > motor_status.motorl_pic_max_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_pic_max_temperature = motor_status.motorl_pic_temperature;
                        }
                        else if(motor_status.motorl_pic_temperature < motor_status.motorl_pic_min_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_pic_min_temperature = motor_status.motorl_pic_temperature;
                        }
                    }
                    
                    // Recuperation du courant du pont
                    temp16 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+2);
                    temp16<<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+3);
                    d = (temp16 * 5.0) / 4096.0;
                    d = (d/11.0);
                    d = (d/0.04);
                    if(motor.family != MOTOR_ASYNC_FAMILY) d = d*0.85;
                    d = d*1000;
                    
                    if(d>0.0 && d<20000.0)
                    {
                        if(d > SLAVE_STATUS_BRIDGE_EMERGENCY_CURRENT)
                        {
                            error(ERROR_BRIDGE_L_CURRENT);
                        }

                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorl_bridge_current_array[temp16] = motor_status.motorl_bridge_current_array[temp16+1];
                        motor_status.motorl_bridge_current_array[SLAVE_STATUS_SAMPLES-1] = d;
                        motor_status.motorl_bridge_current = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorl_bridge_current+=motor_status.motorl_bridge_current_array[temp16];
                        motor_status.motorl_bridge_current = (motor_status.motorl_bridge_current/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorl_bridge_current > motor_status.motorl_bridge_max_current)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_bridge_max_current = motor_status.motorl_bridge_current;
                        }
                        else if(motor_status.motorl_bridge_current < motor_status.motorl_bridge_min_current)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_bridge_min_current = motor_status.motorl_bridge_current;
                        }
                    }
                    
                    
                   
                    // Recuperation de la temperature du pont
                    temp16 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+4);
                    temp16 <<=8;
                    temp16 += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+5);
                    d = (temp16 * 5.0) / 4096.0;
                    d1 = (d * 100000.0)/(5.0-d);
                    d2 = ((log(d1/85000.0))/4200.0);
                    d2 += (1/298.15);
                    d2 = (1.0/d2);
                    d3 = d2-272.15;
                    
                    if(d3 > -30.0 && d3< 150.0)
                    {
                        if(d3 > SLAVE_STATUS_BRIDGE_EMERGENCY_TEMP)
                        {
                            slave_status_bridge_emergency_temp = TRUE;
                            //slave_status_bridge_high_temp      = TRUE;

                            motorh_slope_xx_xs(motor.minimum_speed_value,100);
                            motorl_slope_xx_xs(motor.minimum_speed_value,100);
                            motor_slope_run();
                        }
                        else if(d3 > SLAVE_STATUS_BRIDGE_HIGH_TEMP)
                        {
                            //slave_status_bridge_high_temp      = TRUE;
                        }
     
                    
                    
                        for(temp16=0;temp16<(SLAVE_STATUS_SAMPLES-1);temp16++) motor_status.motorl_bridge_temperature_array[temp16] = motor_status.motorl_bridge_temperature_array[temp16+1];
                        motor_status.motorl_bridge_temperature_array[SLAVE_STATUS_SAMPLES-1] = d3;
                        motor_status.motorl_bridge_temperature = 0;
                        for(temp16=0;temp16<SLAVE_STATUS_SAMPLES;temp16++) motor_status.motorl_bridge_temperature+=motor_status.motorl_bridge_temperature_array[temp16];
                        motor_status.motorl_bridge_temperature = (motor_status.motorl_bridge_temperature/SLAVE_STATUS_SAMPLES);

                        if(motor_status.motorl_bridge_temperature > motor_status.motorl_bridge_max_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_bridge_max_temperature = motor_status.motorl_bridge_temperature;
                        }
                        else if(motor_status.motorl_bridge_temperature < motor_status.motorl_bridge_min_temperature)
                        {
                            slave_status_extreme_change = TRUE;
                            motor_status.motorl_bridge_min_temperature = motor_status.motorl_bridge_temperature;
                        }
                    }
                    
                    uart_motor_protocole_release_mutex();
                    slave_status_time_counter = SLAVE_STATUS_POLLING_MS;
                    next_state = 0;
                }
                else
                {
                    uart_motor_protocole_release_mutex();
                    slave_status_time_counter = SLAVE_STATUS_POLLING_MS;
                    next_state = 0;
                    //error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    //next_state = 100;
                }
                
            }
            break;
            
        case 100:
            
            break;
    }
    slave_status_state = next_state;
    
    
    if(motor_status.motorh_pic_temperature > SLAVE_STATUS_MCU_HIGH_TEMP)
    {
        if(slave_status_mcuh_high_temp == FALSE && motor_auto_scrolling == 0x00)
        {
            /*eeprom_ev_write3(EEPROM_EV_SLAVE_MCUH_HIGH_TEMP,
                             (u8)(motor_status.motorh_pic_temperature>>8),
                             (u8)(motor_status.motorh_pic_temperature & 0x00FF));*/
            slave_status_mcuh_high_temp = TRUE;
        }      
    }
    else
    {
        slave_status_mcuh_high_temp = FALSE;
    }
    
    if(motor_status.motorl_pic_temperature > SLAVE_STATUS_MCU_HIGH_TEMP)
    {
        if(slave_status_mcul_high_temp == FALSE && motor_auto_scrolling == 0x00)
        {
            /*eeprom_ev_write3(EEPROM_EV_SLAVE_MCUL_HIGH_TEMP,
                             (u8)(motor_status.motorl_pic_temperature>>8),
                             (u8)(motor_status.motorl_pic_temperature & 0x00FF));*/
            slave_status_mcul_high_temp = TRUE;
        }
    }
    else
    {
        slave_status_mcul_high_temp = FALSE;
    }
    
    if(slave_status_mcuh_high_temp || slave_status_mcul_high_temp) slave_status_mcu_high_temp = TRUE;
    
    
    
    if(motor_status.motorh_bridge_temperature > SLAVE_STATUS_BRIDGE_HIGH_TEMP)
    {
        if( slave_status_bridgeh_high_temp == FALSE && motor_auto_scrolling == 0x00)
        {
            /*eeprom_ev_write3(EEPROM_EV_SLAVE_BRIDGEH_HIGH_TEMP,
                             (u8)(motor_status.motorh_bridge_temperature>>8),
                             (u8)(motor_status.motorh_bridge_temperature & 0x00FF));*/
            slave_status_bridgeh_high_temp = TRUE;
        }
    }
    else
    {
        slave_status_bridgeh_high_temp = FALSE;
    }
    
    if(motor_status.motorl_bridge_temperature > SLAVE_STATUS_BRIDGE_HIGH_TEMP)
    {
        if( slave_status_bridgel_high_temp == FALSE && motor_auto_scrolling == 0x00)
        {
            /*eeprom_ev_write3(EEPROM_EV_SLAVE_BRIDGEL_HIGH_TEMP,
                             (u8)(motor_status.motorl_bridge_temperature>>8),
                             (u8)(motor_status.motorl_bridge_temperature & 0x00FF));*/
            slave_status_bridgel_high_temp = TRUE;
        }
    }
    else
    {
        slave_status_bridgel_high_temp = FALSE;
    }
    if(slave_status_bridgeh_high_temp || slave_status_bridgel_high_temp) slave_status_bridge_high_temp = TRUE;
    
    if(slave_status_mcu_high_temp == TRUE)
    {
        if( (motor_status.motorh_pic_temperature < SLAVE_STATUS_MCU_LOW_TEMP_THRESHOLD) &&
            (motor_status.motorl_pic_temperature < SLAVE_STATUS_MCU_LOW_TEMP_THRESHOLD) &&
            (motor_auto_scrolling == 0x00)    
          )
        {
            /*eeprom_ev_write_init_code(EEPROM_EV_SLAVE_MCU_TEMP_OK);
            eeprom_ev_write_add_byte((u8)(motor_status.motorh_pic_temperature>>8));
            eeprom_ev_write_add_byte((u8)(motor_status.motorh_pic_temperature & 0x00FF));
            eeprom_ev_write_add_byte((u8)(motor_status.motorl_pic_temperature>>8));
            eeprom_ev_write_add_byte((u8)(motor_status.motorl_pic_temperature & 0x00FF));
            eeprom_ev_write();*/
            slave_status_mcu_high_temp = FALSE;
        }
    }
    
    
    
    if(slave_status_bridge_emergency_temp == TRUE)
    {
        if( (motor_status.motorl_bridge_temperature < SLAVE_STATUS_BRIDGE_HIGH_TEMP) &&
            (motor_status.motorh_bridge_temperature < SLAVE_STATUS_BRIDGE_HIGH_TEMP))
        {
            slave_status_bridge_emergency_temp = FALSE;
        }
    }
    
    if(slave_status_bridge_high_temp == TRUE)
    {
        if( (motor_status.motorl_bridge_temperature < SLAVE_STATUS_BRIDGE_LOW_TEMP_THRESHOLD) &&
            (motor_status.motorh_bridge_temperature < SLAVE_STATUS_BRIDGE_LOW_TEMP_THRESHOLD) &&
            (motor_auto_scrolling == 0x00)     
          )
        {
            /*eeprom_ev_write_init_code(EEPROM_EV_SLAVE_BRIDGE_TEMP_OK);
            eeprom_ev_write_add_byte((u8)(motor_status.motorh_bridge_temperature>>8));
            eeprom_ev_write_add_byte((u8)(motor_status.motorh_bridge_temperature & 0x00FF));
            eeprom_ev_write_add_byte((u8)(motor_status.motorl_bridge_temperature>>8));
            eeprom_ev_write_add_byte((u8)(motor_status.motorl_bridge_temperature & 0x00FF));
            eeprom_ev_write();*/
            
            if(slave_status_bridge_emergency_temp)
            {
                motor_init_init();
            }
            slave_status_bridge_high_temp      = FALSE;
        }
    }
    
    
    temporary_stop_process();
    
}
