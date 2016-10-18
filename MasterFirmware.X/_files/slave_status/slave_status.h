/* 
 * File:   slave_status.h
 * Author: Christophe
 *
 * Created on 18 août 2015, 13:38
 */

#ifndef SLAVE_STATUS_H
#define	SLAVE_STATUS_H

#define SLAVE_STATUS_RUN_SLOPE                      1
#define SLAVE_STATUS_POLLING_MS                   500
#define SLAVE_STATUS_SAMPLES                        5

#define SLAVE_STATUS_MCU_HIGH_TEMP                 80
#define SLAVE_STATUS_MCU_LOW_TEMP_THRESHOLD        65

#define SLAVE_STATUS_BRIDGE_EMERGENCY_TEMP        110
#define SLAVE_STATUS_BRIDGE_HIGH_TEMP             100
#define SLAVE_STATUS_BRIDGE_LOW_TEMP_THRESHOLD     80

#define SLAVE_STATUS_BRIDGE_EMERGENCY_CURRENT    8000 





typedef struct struct_motor_status
{
 
 i16 motorh_pic_min_temperature;
 i16 motorh_pic_max_temperature;
 i16 motorh_pic_temperature;
 
 i16 motorh_bridge_min_temperature;
 i16 motorh_bridge_max_temperature;
 i16 motorh_bridge_temperature;
 
 i16 motorh_bridge_min_current;
 i16 motorh_bridge_max_current;
 i16 motorh_bridge_current;
 
 i16 motorh_pic_temperature_array[SLAVE_STATUS_SAMPLES];
 i16 motorh_bridge_temperature_array[SLAVE_STATUS_SAMPLES];
 i16 motorh_bridge_current_array[SLAVE_STATUS_SAMPLES];
 
 
 i16 motorl_pic_min_temperature;
 i16 motorl_pic_max_temperature;
 i16 motorl_pic_temperature;
 i16 motorl_bridge_min_temperature;
 i16 motorl_bridge_max_temperature;
 i16 motorl_bridge_temperature;
 i16 motorl_bridge_min_current;
 i16 motorl_bridge_max_current;
 i16 motorl_bridge_current;
 
 i16 motorl_pic_temperature_array[SLAVE_STATUS_SAMPLES];
 i16 motorl_bridge_temperature_array[SLAVE_STATUS_SAMPLES];
 i16 motorl_bridge_current_array[SLAVE_STATUS_SAMPLES];
 
}struct_motor_status;





extern bool slave_status_extreme_change;
extern bool slave_status_mcu_high_temp;
extern bool slave_status_bridge_high_temp;
extern bool slave_status_bridge_emergency_temp;



void slave_status_init(void);
void slave_status_sm(void);
void slave_status_reset_sm(void);

#endif	/* SLAVE_STATUS_H */

