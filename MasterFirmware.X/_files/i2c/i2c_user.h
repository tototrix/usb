/* 
 * File:   i2c_user.h
 * Author: Christophe
 *
 * Created on 9 novembre 2015, 10:30
 */

#ifndef I2C_USER_H
#define	I2C_USER_H

#define I2C_EVENT_INFO_MAX_COUNT  700000
#define I2C_EVENT_INFO_SIGNATURE  0x0001

#define I2C_EVENT_INFO_BLOCK1_Z1     128
#define I2C_EVENT_INFO_BLOCK2_Z1     136
#define I2C_EVENT_INFO_BLOCK3_Z1     144
#define I2C_EVENT_BLOCK_START_Z1     152
#define I2C_EVENT_BLOCK_STOP_Z1      344
#define I2C_EVENT_MAX_COUNT_Z1       ((I2C_EVENT_BLOCK_STOP_Z1-I2C_EVENT_BLOCK_START_Z1)+1)

#define I2C_EVENT_INFO_BLOCK1_Z2     408
#define I2C_EVENT_INFO_BLOCK2_Z2     416
#define I2C_EVENT_INFO_BLOCK3_Z2     424
#define I2C_EVENT_BLOCK_START_Z2     432
#define I2C_EVENT_BLOCK_STOP_Z2      944
#define I2C_EVENT_MAX_COUNT_Z2      ((I2C_EVENT_BLOCK_STOP_Z2-I2C_EVENT_BLOCK_START_Z2)+1)




typedef struct eeprom_read_event
{
    u32 id;
    u32 alive_counter;
    u8  ts_year;
    u8  ts_month;
    u8  ts_day;
    u8  ts_hour;
    u8  ts_minuts;
    u8  ts_seconds;
    u8  payload[I2C_PACKET_PAYLOAD_SIZE-14];
}eeprom_read_event;

extern bool eeprom_error;

void eeprom_ev_init(void);


// Fonctions relatives aux evenements
u32 eeprom_evz1_get_idf(void);
u32 eeprom_evz1_get_idl(void);
u16 eeprom_evz1_get_count(void);

u32 eeprom_evz2_get_idf(void);
u32 eeprom_evz2_get_idl(void);
u16 eeprom_evz2_get_count(void);

i8 eeprom_read(u32 addr,u8 *ptr,u8 count);
i8 eeprom_write(u32 addr,u8 *ptr,u8 count);

i8 eeprom_evz1_read(u32 id,eeprom_read_event *ptr);
i8 eeprom_evz2_read(u32 id,eeprom_read_event *ptr);

void eeprom_ev_write_init_code(u8 code);
void eeprom_ev_write_add_byte(u8 b);
i8   eeprom_ev_write(void);
i8 eeprom_ev_write1(u8 code);
i8 eeprom_ev_write2(u8 code,u8 val1);
i8 eeprom_ev_write3(u8 code,u8 val1,u8 val2);




#endif	/* I2C_USER_H */

