#include <_Global_Include.h>


bool temporary_stop = FALSE;

void temporary_stop_process(void)
{
    // Si le mode "arret temporaire n'est pas activé"
    if(temporary_stop == FALSE)
    {
        if(
           (
            (slave_status_bridge_high_temp == TRUE) || 
            (slave_status_mcu_high_temp == TRUE) ||
            (adc_ctn_high_temp == TRUE)
           )&&
            (motor_auto_scrolling == 0x00)
           )
        {
            eeprom_ev_write1(EEPROM_EV_TEMPORARY_STOP);
            temporary_stop = TRUE;
        }         
    }
    else
    {
        if( 
           (
            (slave_status_bridge_high_temp == FALSE) &&
            (slave_status_mcu_high_temp == FALSE) &&
            (adc_ctn_high_temp == FALSE)
           )&&
            (motor_auto_scrolling == 0x00)
           )
        {
            eeprom_ev_write1(EEPROM_EV_RESTART_FROM_TEMPORARY_STOP);
            temporary_stop = FALSE;
        }
    }
}
