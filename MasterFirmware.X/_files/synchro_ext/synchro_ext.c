#include <_Global_Include.h>



u16 synchro_ext_ar = 0x00;
bool synchro_ext_long_pulse = FALSE;
bool synchro_ext_short_pulse = FALSE;
bool synchro_ext_mode = FALSE;

u8 synchro_ext_sm = 0;
bool synchro_ext;

volatile u16 synchro_ext_timer;

void synchro_ext_init(void)
{
    BIT_SYNC_TRIS           = INPUT;
    synchro_ext_long_pulse  = FALSE;
    synchro_ext_short_pulse = FALSE;
    synchro_ext_mode        = FALSE;
    
    synchro_ext_ar          = 0x00;
    synchro_ext_sm          = 0x00;
    synchro_ext             = SYNC_EXT_INACTIVE_LEVEL;
    
    timer1ms_register_variable((u16*)&synchro_ext_timer);
}

void synchro_ext_process(void)
{
    u16 temp16;
    
    if(BIT_SYNC == SYNC_EXT_ACTIVE_LEVEL && synchro_ext_ar < 512) synchro_ext_ar++;
    else if(BIT_SYNC == SYNC_EXT_INACTIVE_LEVEL && synchro_ext_ar >0) synchro_ext_ar--;
    
    if(synchro_ext_ar == 512) synchro_ext = SYNC_EXT_ACTIVE_LEVEL;
    else if(synchro_ext_ar == 0) synchro_ext = SYNC_EXT_INACTIVE_LEVEL;
    
    
    switch(synchro_ext_sm)
    {
        // Attente de front actif
        case 0:
            if(synchro_ext_mode == FALSE)
            {
                if(synchro_ext == SYNC_EXT_ACTIVE_LEVEL)
                {
                  eeprom_ev_write1(EEPROM_EV_SYNCHRO_EXT_START);  
                  synchro_ext_mode  = TRUE;  
                  synchro_ext_timer = SYNC_EXT_TIMER_INIT;
                  synchro_ext_sm    = 1;
                }
            }
            else
            {
                if(synchro_ext_timer == 0x00)
                {
                    eeprom_ev_write1(EEPROM_EV_SYNCHRO_EXT_EXIT);  
                    synchro_ext_mode = FALSE;
                }
                else if(synchro_ext == SYNC_EXT_ACTIVE_LEVEL)
                {
                  synchro_ext_timer = SYNC_EXT_TIMER_INIT;
                  synchro_ext_sm = 1;
                }
                
            }
            break;
            
        case 1:
           
            if(synchro_ext_timer == 0x00)
            {
              synchro_ext_sm    = 0; 
              synchro_ext_timer = 0;
              synchro_ext_mode  = FALSE;
            }
            
            else if(synchro_ext == SYNC_EXT_ACTIVE_LEVEL)
            {
                temp16 = (SYNC_EXT_TIMER_INIT - synchro_ext_timer);
                if(temp16>SYNC_EXT_LONG_PULSE_MIN)
                {
                    
                    synchro_ext_long_pulse = TRUE;
                    synchro_ext_short_pulse = FALSE;
                    synchro_ext_sm = 2;
                    synchro_ext_timer = 200;
                }
            }
            
            
            else if(synchro_ext == SYNC_EXT_INACTIVE_LEVEL)
            {
                temp16 = (SYNC_EXT_TIMER_INIT - synchro_ext_timer);
                
                if(temp16>SYNC_EXT_LONG_PULSE_MIN)
                {
                    
                    synchro_ext_long_pulse = TRUE;
                    synchro_ext_short_pulse = FALSE;
                    synchro_ext_sm = 2;
                    synchro_ext_timer = 200;
                }
                else if(temp16>SYNC_EXT_SHORT_PULSE_MIN)
                {
                    
                    synchro_ext_long_pulse = FALSE;
                    synchro_ext_short_pulse = TRUE;
                    synchro_ext_sm = 2;
                    synchro_ext_timer = 200;
                }
                else
                {
                    synchro_ext_timer = SYNC_EXT_DISABLE_TIME;
                    synchro_ext_sm = 0;
                }
                
            }
            break;
            
        case 2:
            if(synchro_ext_timer == 0x00)
            {
                if(synchro_ext_long_pulse == TRUE) synchro_ext_sm = 3;
                else synchro_ext_sm = 0;
                
                synchro_ext_long_pulse  = FALSE;
                synchro_ext_short_pulse = FALSE;
                synchro_ext_timer = SYNC_EXT_DISABLE_TIME; 
            }
            break;
            
        case 3:
            if(synchro_ext == SYNC_EXT_INACTIVE_LEVEL)
            {
                synchro_ext_sm = 0;
                synchro_ext_timer = SYNC_EXT_DISABLE_TIME;
            }
            break;
    }
    
    
}

