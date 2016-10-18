/* 
 * File:   eeprom_events.h
 * Author: Christophe
 *
 * Created on 17 novembre 2015, 09:52
 */

#ifndef EEPROM_VARIABLES_H
#define	EEPROM_VARIABLES_H

void update_serial_u32(void);
void update_error_id_u32(void);

void eeprom_var_init(void);
void eeprom_var_reset_default(void);

//-----------------------------------------------------
//
// VARIABLES 8 BITS
//
//-----------------------------------------------------
typedef enum
{
   EEPROM_VAR8_SERIAL0,
   EEPROM_VAR8_SERIAL1,
   EEPROM_VAR8_SERIAL2,
   EEPROM_VAR8_SERIAL3,
           
    
   EEPROM_VAR8_ERROR,
   EEPROM_VAR8_MOTOR_TYPE,    
   EEPROM_VAR8_ERROR_MODEM, 
   EEPROM_VAR8_TEST,        
   
           
   EEPROM_VAR8_ERROR_ID0,
   EEPROM_VAR8_ERROR_ID1,
   EEPROM_VAR8_ERROR_ID2,
   EEPROM_VAR8_ERROR_ID3,
           
   EEPROM_VAR8_ERROR_LIGHT0,
   EEPROM_VAR8_ERROR_LIGHT1,
   EEPROM_VAR8_ERROR_LIGHT2,
   EEPROM_VAR8_ERROR_LIGHT3,
   EEPROM_VAR8_ERROR_LIGHT4,
           
           
    
   EEPROM_VAR8_COUNT,        
        
}eeprom_var8_enum;


typedef struct s_eeprom8_var
{
    u8  code;
    u8  bloc;
    u8  offset;
    u8  default_value;
    u8  *default_ptr;
    u8  *ptr;
    bool resetable;
}s_eeprom8_var;

extern struct s_eeprom8_var eeprom_var8_list[EEPROM_VAR8_COUNT];
i8 eeprom_var8_read(u8 code);
i8 eeprom_var8_update(u8 code);
i8 eeprom_var8_reset(u8 code);



//-----------------------------------------------------
//
// VARIABLES 16 BITS
//
//-----------------------------------------------------
typedef enum
{
         
   EEPROM_VAR16_CTN_MIN_TEMPERATURE,
   EEPROM_VAR16_CTN_MAX_TEMPERATURE,
   EEPROM_VAR16_PULSES_EXTREME_TAPE_H,
   EEPROM_VAR16_PULSES_EXTREME_TAPE_L,
   EEPROM_VAR16_PULSES_POSTER,
           
   EEPROM_VAR16_PULSES_POSTER0,
   EEPROM_VAR16_PULSES_POSTER1,
   EEPROM_VAR16_PULSES_POSTER2,
   EEPROM_VAR16_PULSES_POSTER3,
   EEPROM_VAR16_PULSES_POSTER4,
           
   EEPROM_VAR16_FIRMWARE_VERSION,
           
           
   EEPROM_VAR16_COUNT        
}eeprom_var16_enum;


typedef struct s_eeprom16_var
{
    u8  code;
    u8  bloc;
    u8  offset;
    u16  default_value;
    u16  *default_ptr;
    u16  *ptr;
    bool resetable;
}s_eeprom16_var;

extern struct s_eeprom16_var eeprom_var16_list[EEPROM_VAR16_COUNT];
i8 eeprom_var16_read(u8 code);
i8 eeprom_var16_update(u8 code);
i8 eeprom_var16_reset(u8 code);

#endif	/* EEPROM_EVENTS_H */

