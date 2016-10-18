#include <_Global_Include.h>

typedef enum
{
  FORCE_KEEPALIVE_IDLE, 
  FORCE_KEEPALIVE_1,
      
}enum_force_keepalive_sm;

u8   keepalive_error_state        = 0x00;
u8   force_keepalive_error_state  = 0x00;
u8   force_keepalive_manual_state = 0x00;
u8   force_keepalive_adc_state    = 0x00;
u8   force_keepalive_temp_state   = 0x00;

u8   force_keepalive_state    = FORCE_KEEPALIVE_IDLE;
u8   force_keepalive_retry    = 0x00;

u16  force_keepalive_timer100_send = 0x00;
u16  force_keepalive_timer100_manual = 0x00;
u16  force_keepalive_timer100_adc = 0x00;
u16  force_keepalive_timer100_error = 0x00;
u16  force_keepalive_timer100_temp = 0x00;



bool force_keepalive_event_manual   = FALSE;
bool force_keepalive_event_adc      = FALSE;
bool force_keepalive_event_error    = FALSE;
bool force_keepalive_event_temp     = FALSE;
u16  force_keepalive_temp_save      = 0x00;

bool force_keepalive_event_manual_save   = FALSE;
bool force_keepalive_event_adc_save      = FALSE;
bool force_keepalive_event_error_save    = FALSE;
bool force_keepalive_event_temp_save     = FALSE;


void force_keepalive_init(void)
{
    
    
    timer100ms_register_variable((u16*)&force_keepalive_timer100_send);
    force_keepalive_retry    = 0x00;
    force_keepalive_state    = FORCE_KEEPALIVE_IDLE;
    force_keepalive_timer100_manual = 0x00;
    timer100ms_register_variable((u16*)&force_keepalive_timer100_manual);
    force_keepalive_timer100_adc = 0x00;
    timer100ms_register_variable((u16*)&force_keepalive_timer100_adc);
    force_keepalive_timer100_error = 0x00;
    timer100ms_register_variable((u16*)&force_keepalive_timer100_error);
    force_keepalive_event_temp = 0x00;
    timer100ms_register_variable((u16*)&force_keepalive_timer100_temp);
}

void force_keepalive_sm(void)
{
    u8 next_state= 0x00;
 
    
          
        
    
    // Machine de detection de sortie du mode manuel
    next_state = force_keepalive_manual_state;
    switch(force_keepalive_manual_state)
    {
        case 0x00:
            if(motor_algo_mode ==  MANUAL_MODE)
            {
                next_state = 0x01;
            }
            break;
            
        case 0x01:
            if(motor_algo_mode !=  MANUAL_MODE)
            {
                force_keepalive_timer100_manual = 3000;
                next_state = 0x02;
            }
            break;
            
        case 0x02:
            if(motor_algo_mode ==  MANUAL_MODE)
            {
                next_state = 0x01;
            }
            else if(force_keepalive_timer100_manual == 0x00)
            {
                force_keepalive_event_manual = 0x01;
                next_state = 0x03;
            }
            break;
            
        case 0x03:
            if(force_keepalive_event_manual == 0x00)
            {
                next_state = 0x00;
            }
            break;
    }
    force_keepalive_manual_state = next_state;
    
    if(motor_algo_mode ==  MANUAL_MODE) force_keepalive_error_state = 0x00;
    next_state = force_keepalive_error_state;
    switch(force_keepalive_error_state)
    {
        case 0x00:
            if(error_code != ERROR_NONE)
            {
                if(error_list[error_code].critical == TRUE)
                {
                    if(error_code != keepalive_error_state)
                    {
                        force_keepalive_timer100_error = 3000;
                        next_state = 0x01;
                    }
                }
            }
            break;
            
        case 0x01:
            if(force_keepalive_timer100_error == 0x00)
            {
                force_keepalive_event_error = 0x01;
                next_state = 0x02;
            }
            break;
            
        case 0x02:
            if(force_keepalive_event_error == 0x00)
            {
                keepalive_error_state = error_code;
                eeprom_var8_update(EEPROM_VAR8_ERROR_MODEM);
                next_state = 0x0;
            }
            break;
    }
    force_keepalive_error_state = next_state;  
    
    // Machine de detection de batterie basse
    if(motor_algo_mode ==  MANUAL_MODE ) force_keepalive_adc_state = 0x00;
    next_state = force_keepalive_adc_state;
    switch(force_keepalive_adc_state)
    {
        case 0x00:
            if(adc_low_battery == TRUE)
            {
                force_keepalive_timer100_adc = 3000;
                next_state = 0x01;
            }
            break;
            
        case 0x01:
            if(adc_low_battery == FALSE) next_state = 0x00;
            else if(force_keepalive_timer100_adc == 0x00)
            {
                force_keepalive_event_adc = 0x01;
                next_state = 0x02;
            }
            break;
        
        case 0x02:
            if(force_keepalive_event_adc == 0x00)
            {
                next_state = 0x03;
            }
            break;
            
        case 0x03:
            if(adc_low_battery == FALSE)
            {
                force_keepalive_timer100_adc = 3000;
                next_state = 0x04;
            }
            break;
            
        case 0x04:
            if(adc_low_battery == TRUE) next_state = 0x02;
            else if(force_keepalive_timer100_adc == 0x00)
            {
                force_keepalive_event_adc = 0x01;
                next_state = 0x05;
            }
            break;    
            
        case 0x05:
            if(force_keepalive_event_adc == 0x00)
            {
                next_state = 0x00;
            }
            break;
    }
    force_keepalive_adc_state = next_state;
    
    
    
    
    // Machine de detection de batterie basse
    if(motor_algo_mode ==  MANUAL_MODE ) force_keepalive_temp_state = 0x00;
    next_state = force_keepalive_temp_state;
    switch(force_keepalive_temp_state)
    {
        case 0x00:
            if(temporary_stop)
            {
                force_keepalive_temp_save = adc_ctn;
                force_keepalive_timer100_temp = 3000;
                next_state = 0x01;
            }
            break;
            
        case 0x01:
            if(temporary_stop == FALSE) next_state = 0x00;
            else if(force_keepalive_timer100_temp == 0x00)
            {
                force_keepalive_event_temp = 0x01;
                next_state = 0x02;
            }
            break;
            
        case 0x02:
            if(force_keepalive_event_temp == 0x00)
            {
                next_state = 0x03;
            }
            break;
            
        case 0x03:
            if(temporary_stop == FALSE)
            {
                force_keepalive_timer100_temp = 3000;
                next_state = 0x04;
            }
            else if(adc_ctn > (force_keepalive_temp_save+3))
            {
                force_keepalive_temp_save = adc_ctn;
                next_state = 0x01;
            }
            break;
            
        case 0x04:
            if(temporary_stop == TRUE) next_state = 0x02;
            else if(force_keepalive_timer100_temp == 0x00)
            {
                force_keepalive_event_temp = 0x01;
                next_state = 0x05;
            }
            break;
            
        case 0x05:
            if(force_keepalive_event_temp == 0x00)
            {
                next_state = 0x00;
            }
            break;
    }
    force_keepalive_temp_state = next_state;
    
    
    next_state =force_keepalive_state;
    switch(force_keepalive_state)
    {
        case 0x00:
            if(force_keepalive_timer100_send == 0x00)
            {
                if(force_keepalive_event_manual || force_keepalive_event_adc || force_keepalive_event_error || force_keepalive_event_temp)
                {
                    force_keepalive_event_manual_save = force_keepalive_event_manual;
                    force_keepalive_event_adc_save = force_keepalive_event_adc;
                    force_keepalive_event_error_save = force_keepalive_event_error;        
                    force_keepalive_event_temp_save = force_keepalive_event_temp;

                    force_keepalive_retry = 0x00;
                    next_state            = 0x01;
                }
            }
            break;
            
        case 0x01:
            if((uarts_tx_mgmt_is_mutex_free() == TRUE))
            {
        
                uarts_tx_mgmt_get_mutex();
                uarts_tx_mgmt_packet_tx_init(UARTS_TYPE_MODEM,0x00,UARTS_FIRMWARE_ORDER_TO_MODEM_FORCE_KEEPALIVE);
                uarts_tx_mgmt_packet_tx_add_byte(usb_with_modem);
                uarts_tx_mgmt_packet_tx_finalize();
                uarts_tx_mgmt_go(3000);
                next_state = 0x02;
            }
            break;
            
        case 0x02:
            if(uarts_tx_mgmt_is_busy() == FALSE)
            {
                uarts_tx_mgmt_release_mutex();
          
                if(uarts_tx_mgmt_is_error() == TRUE)
                {
                   force_keepalive_retry++;
                   if(force_keepalive_retry < 4)
                   {
                       next_state = 0x01;
                   }
                   else
                   {
                       force_keepalive_timer100_send = 6000; // 10 minutes
                       next_state = 0x00;
                   }
                   
                }
                else
                {
                    
                    next_state = 0x03;
                }   
            }
            break;
            
            case 0x03:
                if(force_keepalive_event_manual_save) force_keepalive_event_manual = 0x00;
                if(force_keepalive_event_adc_save) force_keepalive_event_adc = 0x00;
                if(force_keepalive_event_error_save) force_keepalive_event_error = 0x00;
                if(force_keepalive_event_temp_save) force_keepalive_event_temp = 0x00;
                next_state = 0x00;
            break;
    }
    force_keepalive_state = next_state;
}





