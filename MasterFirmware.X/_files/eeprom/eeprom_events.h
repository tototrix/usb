/* 
 * File:   eeprom_events.h
 * Author: Christophe
 *
 * Created on 17 novembre 2015, 09:52
 */

#ifndef EEPROM_EVENTS_H
#define	EEPROM_EVENTS_H

typedef enum
{
    EEPROM_EV_SYSTEM_START,         // 0
    EEPROM_EV_ERROR_CRITICAL,       // 1
    EEPROM_EV_ERROR_LIGHT,          // 2
    EEPROM_EV_MANUAL_ENTER,         // 3
    EEPROM_EV_MANUAL_EXIT,          // 4 
    EEPROM_EV_INIT_START,           // 5
    EEPROM_EV_INIT_EXIT,            // 6
    EEPROM_EV_PREAUTO1_START,       // 7
    EEPROM_EV_PREAUTO2_START,       // 8
    EEPROM_EV_PREAUTO3_START,       // 9
    EEPROM_EV_AUTO_START,           // 10
    EEPROM_EV_SYNCHRO_EXT_START,    // 11
    EEPROM_EV_SYNCHRO_EXT_EXIT,     // 12
    EEPROM_EV_CONFIG_MOTORH,        // 13
    EEPROM_EV_CONFIG_MOTORL,        // 14
    EEPROM_EV_POSTERS,              // 15
    EEPROM_EV_AUTO_CYCLE_FIRST_INIT,// 16
    EEPROM_EV_AUTO_CYCLE_COUNT_CELL,// 17
    EEPROM_EV_NEW_PREAUTO,          // 18
    EEPROM_EV_CONFIG_SWITCH,        // 19
    EEPROM_EV_SLAVEH_FIRMWARE,      // 20
    EEPROM_EV_SLAVEL_FIRMWARE,      // 21
    EEPROM_EV_LOW_BATTERY    ,      // 22
    EEPROM_EV_BATTERY_OK     ,      // 23   
    EEPROM_EV_SLAVE_MCU_TEMP_OK  ,  // 24
    EEPROM_EV_SLAVE_BRIDGE_TEMP_OK, // 25
    EEPROM_EV_SLAVE_MCUH_HIGH_TEMP, // 26
    EEPROM_EV_SLAVE_MCUL_HIGH_TEMP, // 27
    EEPROM_EV_SLAVE_BRIDGEH_HIGH_TEMP, // 28
    EEPROM_EV_SLAVE_BRIDGEL_HIGH_TEMP, // 29
    EEPROM_EV_MSTR_MCU_HIGH_TEMP     , // 30
    EEPROM_EV_MSTR_MCU_TEMP_OK       , // 31
    EEPROM_EV_DOOR_OPENED            , // 32
    EEPROM_EV_DOOR_CLOSED            , // 33
    EEPROM_EV_TEMPORARY_STOP         , // 34
    EEPROM_EV_RESTART_FROM_TEMPORARY_STOP  , // 35
    EEPROM_EV_ERROR_LIGHT_STOP       , // 36
    EEPROM_EV_AUTO_CYCLE_POSTER_ADJUST, // 37     
    EEPROM_EV_COUNTS,
} enum_events;

typedef struct s_event
{
    u8 code;
    bool zone1;
    bool zone2;
} s_event;

extern struct s_event event_list[EEPROM_EV_COUNTS];












#endif	/* EEPROM_EVENTS_H */

