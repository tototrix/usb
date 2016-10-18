#include <_Global_Include.h>


u32 eeprom_var_addr;
i8  eeprom_var_ret;

void eeprom_var_calc_addr(u8 bloc,u8 offset);




void update_serial_u32(void)
{
    serial_number_u32 = 0x0000;
    serial_number_u32 = serial_number[0];
    serial_number_u32 <<=8;
    serial_number_u32 += serial_number[1];
    serial_number_u32 <<=8;
    serial_number_u32 += serial_number[2];
    serial_number_u32 <<=8;
    serial_number_u32 += serial_number[3]; 
}

void update_error_id_u32(void)
{
    error_id_u32 = 0x00;
    error_id_u32 = error_id[0];
    error_id_u32 <<= 8;
    error_id_u32 += error_id[1];
    error_id_u32 <<= 8;
    error_id_u32 += error_id[2];
    error_id_u32 <<= 8;
    error_id_u32 += error_id[3];
}


void eeprom_var_init(void)
{
   u8 i;
   for(i=0;i<EEPROM_VAR8_COUNT;i++)
   {
       eeprom_var8_read(eeprom_var8_list[i].code);
   }
   
   
   
   
   
   for(i=0;i<EEPROM_VAR16_COUNT;i++)
   {
       eeprom_var16_read(eeprom_var16_list[i].code);
   }
   
   
   update_serial_u32();
   update_error_id_u32();
}


void eeprom_var_reset_default(void)
{
    u8 i;
    for(i=0;i<EEPROM_VAR8_COUNT;i++)
    {
        if(eeprom_var8_list[i].resetable) 
        {
            
            if(eeprom_var8_list[i].default_ptr != 0x00)
            {
                *eeprom_var8_list[i].ptr = *eeprom_var8_list[i].default_ptr;
            }
            else
            {
                *eeprom_var8_list[i].ptr = eeprom_var8_list[i].default_value;
            }
            
            
            eeprom_var8_update(eeprom_var8_list[i].code);
        }
    }
    
    for(i=0;i<EEPROM_VAR16_COUNT;i++)
    {
        if(eeprom_var16_list[i].resetable) 
        {
            if(eeprom_var16_list[i].default_ptr != 0x00)
            {
                *eeprom_var16_list[i].ptr = *eeprom_var16_list[i].default_ptr;
            }
            else
            {
                *eeprom_var16_list[i].ptr = eeprom_var16_list[i].default_value;
            }
            eeprom_var16_update(eeprom_var16_list[i].code);
        }
    }
}


//-----------------------------------------------------
//
// VARIABLES 8 BITS
//
//-----------------------------------------------------
struct s_eeprom8_var eeprom_var8_list[EEPROM_VAR8_COUNT] = 
    {
          // Variable                             bloc   offset       default                 default ptr         *ptr                          telecommand init
        { EEPROM_VAR8_SERIAL0                  ,    0  ,    0   ,    0x00                ,      0              ,(u8*)&serial_number[0]  ,                 FALSE  },
        { EEPROM_VAR8_SERIAL1                  ,    0  ,    1   ,    0x00                ,      0              ,(u8*)&serial_number[1]  ,                 FALSE  },
        { EEPROM_VAR8_SERIAL2                  ,    0  ,    2   ,    0x00                ,      0              ,(u8*)&serial_number[2]  ,                 FALSE  },
        { EEPROM_VAR8_SERIAL3                  ,    0  ,    3   ,    0x00                ,      0              ,(u8*)&serial_number[3]  ,                 FALSE  },
        { EEPROM_VAR8_ERROR                    ,    1  ,    0   ,    ERROR_NONE          ,      0              ,(u8*)&error_code        ,                 TRUE   },    
        { EEPROM_VAR8_MOTOR_TYPE               ,    1  ,    1   ,    MOTOR_SHUNT_UNKNOWN ,      0              ,(u8*)&motor_type_eeprom ,                 TRUE   },    
        { EEPROM_VAR8_ERROR_MODEM              ,    1  ,    2   ,    ERROR_NONE          ,      0              ,(u8*)&gsm_error_code    ,                 FALSE  },
        { EEPROM_VAR8_TEST                     ,    1  ,    3   ,    0x00                ,      0              ,(u8*)&test_flash_var    ,                 FALSE  },
        
        { EEPROM_VAR8_ERROR_ID0                ,    1  ,    4   ,    0x00                ,      0              ,(u8*)&error_id[0]         ,                TRUE   },
        { EEPROM_VAR8_ERROR_ID1                ,    1  ,    5   ,    0x00                ,      0              ,(u8*)&error_id[1]        ,                 TRUE   },
        { EEPROM_VAR8_ERROR_ID2                ,    1  ,    6   ,    0x00                ,      0              ,(u8*)&error_id[2]        ,                 TRUE   },
        { EEPROM_VAR8_ERROR_ID3                ,    1  ,    7   ,    0x00                ,      0              ,(u8*)&error_id[3]        ,                 TRUE   },   
        
        { EEPROM_VAR8_ERROR_LIGHT0             ,    1  ,    8   ,    0x00                ,      0              ,(u8*)&error_light[0]     ,                 TRUE   },
        { EEPROM_VAR8_ERROR_LIGHT1             ,    1  ,    9   ,    0x00                ,      0              ,(u8*)&error_light[1]     ,                 TRUE   },
        { EEPROM_VAR8_ERROR_LIGHT2             ,    1  ,    10  ,    0x00                ,      0              ,(u8*)&error_light[2]     ,                 TRUE   },
        { EEPROM_VAR8_ERROR_LIGHT3             ,    1  ,    11  ,    0x00                ,      0              ,(u8*)&error_light[3]     ,                 TRUE   }, 
        { EEPROM_VAR8_ERROR_LIGHT4             ,    1  ,    12  ,    0x00                ,      0              ,(u8*)&error_light[4]     ,                 TRUE   },   
        
        
        
    };

void eeprom_var_calc_addr(u8 bloc,u8 offset)
{
    eeprom_var_addr = bloc;
    eeprom_var_addr = eeprom_var_addr * I2C_PACKET_PAYLOAD_SIZE;
    eeprom_var_addr += offset;   
}

i8 eeprom_var8_read(u8 code)
{
    if(eeprom_var8_list[code].ptr == 0x00) return -2;
    eeprom_var_calc_addr(eeprom_var8_list[code].bloc,eeprom_var8_list[code].offset);
    eeprom_var_ret = eeprom_read(eeprom_var_addr,eeprom_var8_list[code].ptr,1);
    if(eeprom_var_ret <= 0) 
    {
        *eeprom_var8_list[code].ptr = eeprom_var8_list[code].default_value;
        return eeprom_var_ret;
    }
    return 1;
}

i8 eeprom_var8_update(u8 code)
{
    if(eeprom_var8_list[code].ptr == 0x00) return -2;
    eeprom_var_calc_addr(eeprom_var8_list[code].bloc,eeprom_var8_list[code].offset);
    eeprom_var_ret = eeprom_write(eeprom_var_addr,eeprom_var8_list[code].ptr,1);
    if(eeprom_var_ret <= 0) 
    {
        return eeprom_var_ret;
    }
    return 1;
}

i8 eeprom_var8_reset(u8 code)
{
    if(eeprom_var8_list[code].default_ptr != 0x00)
    {
        *eeprom_var8_list[code].ptr = *eeprom_var8_list[code].default_ptr;
    }
    else
    {
        *eeprom_var8_list[code].ptr = eeprom_var8_list[code].default_value;
    }
    return eeprom_var8_update(eeprom_var8_list[code].code);
}


//-----------------------------------------------------
//
// VARIABLES 16 BITS
//
//-----------------------------------------------------
struct s_eeprom16_var eeprom_var16_list[EEPROM_VAR16_COUNT] = 
    {
          // Variable                             bloc   offset       default    default ptr                                        *ptr                              telecommand init
        { EEPROM_VAR16_CTN_MIN_TEMPERATURE      ,    2  ,    0   ,       100 ,        0                                      ,(u16*)&ctn_min_temperature               ,      TRUE  },
        { EEPROM_VAR16_CTN_MAX_TEMPERATURE      ,    2  ,    2   ,         0 ,        0                                      ,(u16*)&ctn_max_temperature               ,      TRUE  },
        { EEPROM_VAR16_PULSES_EXTREME_TAPE_H    ,    3  ,    0   ,         0 ,   (u16*)&motor.pulses_count_extreme_tape_H    ,(u16*)&motor_pulses_count_extreme_tape_H ,      TRUE  },
        { EEPROM_VAR16_PULSES_EXTREME_TAPE_L    ,    3  ,    2   ,         0 ,   (u16*)&motor.pulses_count_extreme_tape_L    ,(u16*)&motor_pulses_count_extreme_tape_L ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER            ,    3  ,    4   ,         0 ,   (u16*)&motor.pulses_count_poster            ,(u16*)&motor_pulses_count_poster         ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER0           ,    3  ,    6   ,         0 ,        0                                      ,(u16*)&motor_pulses_poster[0]            ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER1           ,    3  ,    8   ,         0 ,        0                                      ,(u16*)&motor_pulses_poster[1]            ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER2           ,    3  ,    10  ,         0 ,        0                                      ,(u16*)&motor_pulses_poster[2]            ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER3           ,    3  ,    12  ,         0 ,        0                                      ,(u16*)&motor_pulses_poster[3]            ,      TRUE  },
        { EEPROM_VAR16_PULSES_POSTER4           ,    3  ,    14  ,         0 ,        0                                      ,(u16*)&motor_pulses_poster[4]            ,      TRUE  },
        { EEPROM_VAR16_FIRMWARE_VERSION         ,    3  ,    16  ,         0 ,        0                                      ,(u16*)&master_eeprom_firmware            ,      FALSE },   
    };


i8 eeprom_var16_read(u8 code)
{
    if(eeprom_var16_list[code].ptr == 0x00) return -2;
    eeprom_var_calc_addr(eeprom_var16_list[code].bloc,eeprom_var16_list[code].offset);
    eeprom_var_ret = eeprom_read(eeprom_var_addr,(u8*)eeprom_var16_list[code].ptr,2);
    if(eeprom_var_ret <= 0) 
    {
        *eeprom_var16_list[code].ptr = eeprom_var16_list[code].default_value;
        return eeprom_var_ret;
    }
    return 1;
}

i8 eeprom_var16_update(u8 code)
{
    if(eeprom_var16_list[code].ptr == 0x00) return -2;
    eeprom_var_calc_addr(eeprom_var16_list[code].bloc,eeprom_var16_list[code].offset);
    eeprom_var_ret = eeprom_write(eeprom_var_addr,(u8*)eeprom_var16_list[code].ptr,2);
    if(eeprom_var_ret <= 0) 
    {
        return eeprom_var_ret;
    }
    return 1;
}

i8 eeprom_var16_reset(u8 code)
{
    if(eeprom_var16_list[code].default_ptr != 0x00)
    {
        *eeprom_var16_list[code].ptr = *eeprom_var16_list[code].default_ptr;
    }
    else
    {
        *eeprom_var16_list[code].ptr = eeprom_var16_list[code].default_value;
    }
    return eeprom_var16_update(eeprom_var16_list[code].code);
}