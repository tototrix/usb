

#ifndef MAIN_H
#define	MAIN_H


typedef enum
{
    PANEL_SIZE_UNKNOWN,
    PANEL_SIZE_2M2,
    PANEL_SIZE_8M2,        
}enum_panel_size;
 
extern u8 panel_size;


typedef enum
{
  S_MAIN_INIT, 
  S_MAIN_INIT_SLAVE,
  S_MAIN_INIT_SLAVE2,          
  S_MAIN_SWITCH,       
  S_MAIN_INIT_GET_SLAVEH_FIRMWARE,
  S_MAIN_INIT_GET_SLAVEL_FIRMWARE,
  S_MAIN_INIT_MOTOR,        
  S_MAIN_INIT_CONFIG_SLAVEH,
  s_MAIN_INIT_CONFIG_SLAVEL,    
  S_MAIN_PRE_PROCESS,        
  S_MAIN_PROCESS,
  S_MAIN_PROCESS2,
          
}enum_main_sm;


typedef enum
{
    UNKNOWN_MODE,
    MANUAL_MODE,
    INIT_MODE,
    PREAUTO_MODE,
    PREAUTO2_MODE,
    PREAUTO3_MODE,
    AUTO_MODE,
}enum_algo_mode;



extern bool led_motor_prog;
extern bool led_default_prog;


extern bool test_mode;
extern u8   test_flash_var;

extern u16 master_eeprom_firmware;
extern u16 slaveH_firmware;
extern u16 slaveL_firmware;

extern u8 serial_number[4];
extern u32 serial_number_u32;

extern bool usb_with_modem;

extern bool global_dt_sync_ok;
extern u8 global_dt_year;
extern u8 global_dt_month;
extern u8 global_dt_days;
extern u8 global_dt_hours;
extern u8 global_dt_minuts;
extern u8 global_dt_seconds;


extern u8 motor_algo_mode;

extern bool cell_feature;
extern bool pulses_feature;

extern bool btldr_stop_scrolling;



void Init_Panel_Size(void);
void Set_Panel_Size(u8 type);



u16 get_master_firmware(void);
void set_btldr_stop_scrolling(u16 time);

void main_reset(u8 state);
void lockIO();
void unlockIO ();
#endif	/* MAIN_H */

