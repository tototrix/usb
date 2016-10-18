#include <_Global_Include.h>

struct s_event event_list[EEPROM_EV_COUNTS] = 
    {
        // Evenement                            Zone1   Zone2
        { EEPROM_EV_SYSTEM_START              , TRUE  , TRUE},  // 0
        { EEPROM_EV_ERROR_CRITICAL            , TRUE  , TRUE},  // 1
        { EEPROM_EV_ERROR_LIGHT               , FALSE , TRUE},  // 2
        { EEPROM_EV_MANUAL_ENTER              , TRUE  , TRUE},  // 3
        { EEPROM_EV_MANUAL_EXIT               , TRUE  , TRUE},  // 4
        { EEPROM_EV_INIT_START                , FALSE , TRUE},  // 5
        { EEPROM_EV_INIT_EXIT                 , FALSE , TRUE},  // 6
        { EEPROM_EV_PREAUTO1_START            , FALSE , TRUE},  // 7
        { EEPROM_EV_PREAUTO2_START            , FALSE , TRUE},  // 8
        { EEPROM_EV_PREAUTO3_START            , FALSE , TRUE},  // 9
        { EEPROM_EV_AUTO_START                , FALSE , TRUE},  // 10
        { EEPROM_EV_SYNCHRO_EXT_START         , TRUE  , TRUE},  // 11
        { EEPROM_EV_SYNCHRO_EXT_EXIT          , TRUE  , TRUE},  // 12
        { EEPROM_EV_CONFIG_MOTORH             , FALSE , TRUE},  // 13
        { EEPROM_EV_CONFIG_MOTORL             , FALSE , TRUE},  // 14
        { EEPROM_EV_POSTERS                   , FALSE , TRUE},  // 15
        { EEPROM_EV_AUTO_CYCLE_FIRST_INIT     , FALSE , TRUE},  // 16
        { EEPROM_EV_AUTO_CYCLE_COUNT_CELL     , FALSE , TRUE},  // 17
        { EEPROM_EV_NEW_PREAUTO               , FALSE , TRUE},  // 18
        { EEPROM_EV_CONFIG_SWITCH             , FALSE , TRUE},  // 19
        { EEPROM_EV_SLAVEH_FIRMWARE           , FALSE , TRUE},  // 20
        { EEPROM_EV_SLAVEL_FIRMWARE           , FALSE , TRUE},  // 21
        { EEPROM_EV_LOW_BATTERY               , TRUE  , TRUE},  // 22
        { EEPROM_EV_BATTERY_OK                , TRUE  , TRUE},  // 23   
        { EEPROM_EV_SLAVE_MCU_TEMP_OK         , TRUE  , TRUE},  // 24
        { EEPROM_EV_SLAVE_BRIDGE_TEMP_OK      , TRUE  , TRUE},  // 25
        { EEPROM_EV_SLAVE_MCUH_HIGH_TEMP      , TRUE  , TRUE},  // 26
        { EEPROM_EV_SLAVE_MCUL_HIGH_TEMP      , TRUE  , TRUE},  // 27
        { EEPROM_EV_SLAVE_BRIDGEH_HIGH_TEMP   , TRUE  , TRUE},  // 28
        { EEPROM_EV_SLAVE_BRIDGEL_HIGH_TEMP   , TRUE  , TRUE},  // 29
        { EEPROM_EV_MSTR_MCU_HIGH_TEMP        , TRUE  , TRUE},  // 30
        { EEPROM_EV_MSTR_MCU_TEMP_OK          , TRUE  , TRUE},  // 31
        { EEPROM_EV_DOOR_OPENED               , TRUE  , TRUE},  // 32
        { EEPROM_EV_DOOR_CLOSED               , TRUE  , TRUE},  // 33
        { EEPROM_EV_TEMPORARY_STOP            , TRUE  , TRUE},  // 34
        { EEPROM_EV_RESTART_FROM_TEMPORARY_STOP, TRUE  , TRUE},  // 35
        { EEPROM_EV_ERROR_LIGHT_STOP          , TRUE  , TRUE},   // 36
        { EEPROM_EV_AUTO_CYCLE_POSTER_ADJUST   , FALSE , TRUE},   // 37
        
    };


