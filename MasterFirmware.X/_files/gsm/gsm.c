#include <_Global_Include.h>

typedef enum
{
    GSM_KP_START,
    GSM_KP_MANU1,
    GSM_KP_MANU2,    
    GSM_KP_ERROR_WAIT,        
    GSM_KP_SEND_GSM,
    GSM_KP_WAIT_GSM,        
            
}enum_gsm_keepalive_sm;

u8 gsm_error_code = ERROR_NONE;
u8 gsm_keepalive_state;
u16 gsm_timer100ms;
u8 gsm_retry;
bool gsm_tx_mutex;

void gsm_keepalive_init(void)
{
    gsm_tx_mutex = FALSE;
    gsm_retry = 0x00;
    gsm_keepalive_state = GSM_KP_START;
    timer100ms_register_variable((u16*)&gsm_timer100ms);
}

void gsm_keepalive_sm(void)
{
    
    if(motor_algo_mode ==  MANUAL_MODE)
    {
        if(gsm_tx_mutex == TRUE)
        {
            uarts_tx_mgmt_release_mutex();
            gsm_tx_mutex = FALSE;
        }
        gsm_keepalive_state = GSM_KP_MANU1;
    }
    
    u8 next_state = gsm_keepalive_state;
    switch(gsm_keepalive_state)
    {
        case GSM_KP_START:
            if(error_code != ERROR_NONE)
            {
                if(error_list[error_code].critical == TRUE)
                {
                    if(error_code != gsm_error_code)
                    {
                        gsm_timer100ms = 3000;
                        next_state = GSM_KP_ERROR_WAIT;
                    }
                }
            }
            break;
        
        case GSM_KP_ERROR_WAIT:
            if(gsm_timer100ms == 0x00)
            {
                gsm_retry = 0x00;
                next_state = GSM_KP_SEND_GSM;
            }
            break;
            
        case GSM_KP_MANU1:
            if(motor_algo_mode != MANUAL_MODE)
            {
                gsm_timer100ms = 3000;
                next_state = GSM_KP_MANU2;
            }
            break;
            
        case GSM_KP_MANU2:
            if(gsm_timer100ms == 0x00)
            {
                gsm_retry = 0x00;
                next_state = GSM_KP_SEND_GSM;
            }
            break;
            
            
        case GSM_KP_SEND_GSM:
            if(gsm_timer100ms == 0x00)
            {
                if(uarts_tx_mgmt_is_mutex_free() == TRUE)
                {
                    gsm_tx_mutex = TRUE;
                    uarts_tx_mgmt_get_mutex();
                    uarts_tx_mgmt_packet_tx_init(UARTS_TYPE_MODEM,0x00,UARTS_FIRMWARE_ORDER_TO_MODEM_FORCE_KEEPALIVE);
                    uarts_tx_mgmt_packet_tx_add_byte(usb_with_modem);
                    uarts_tx_mgmt_packet_tx_finalize();
                    uarts_tx_mgmt_go(3000);
                    next_state = GSM_KP_WAIT_GSM;
                }
            }
            break;
            
        case GSM_KP_WAIT_GSM:
            if(uarts_tx_mgmt_is_busy() == FALSE)
            {
                uarts_tx_mgmt_release_mutex();
                gsm_tx_mutex = FALSE;
                
                if(uarts_tx_mgmt_is_error() == TRUE)
                {
                   gsm_retry++;
                   if(gsm_retry < 4)
                   {
                       next_state = GSM_KP_SEND_GSM;
                       gsm_timer100ms = 50;
                   }
                   else
                   {
                       gsm_error_code = error_code;
                       eeprom_var8_update(EEPROM_VAR8_ERROR_MODEM);
                       next_state = GSM_KP_START;
                   }
                   
                }
                else
                {
                    gsm_error_code = error_code;
                    eeprom_var8_update(EEPROM_VAR8_ERROR_MODEM);
                    next_state = GSM_KP_START;
                }   
            }
            break;     
    }
    gsm_keepalive_state = next_state;
}
