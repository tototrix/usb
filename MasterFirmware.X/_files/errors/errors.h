
#ifndef ERRORS_H
#define	ERRORS_H


typedef enum
{
    NO_ERROR,
    CRITICAL_ERROR,
    LIGHT_ERROR,
    CRITICAL_TEMPORARY_ERROR,        
}enum_error_type;


typedef enum
{
    ERROR_NONE,                                  // 0
    ERROR_SLAVES_FIRMWARE,                       // 1
    ERROR_STRUCT_MOTOR_DIFFERENT,                // 2  
    ERROR_COMM_WITH_SLAVES_CRITICAL,             // 3
    ERROR_ERASABLE_BLTDR_DUMMY1,                 // 4
    ERROR_ERASABLE_BLTDR_DUMMY2,                 // 5
    ERROR_ERASABLE_BLTDR_DUMMY3,                 // 6
    ERROR_ERASABLE_BLTDR_DUMMY4,                 // 7
    ERROR_ERASABLE_BLTDR_DUMMY5,                 // 8
    ERROR_ERASABLE_BLTDR_DUMMY6,                 // 9
    ERROR_ERASABLE_BLTDR_DUMMY7,                 // 10
            
    ERROR_STICKER_DURING_FULL_SPEED,             // 11
    ERROR_NO_POSTER_DETECTED,                    // 12
    ERROR_EXTREME_TAPE_IN_AUTO,                  // 13
    ERROR_INIT_START_ON_EXTREME_BAND,            // 14
    ERROR_MOTOR_SHUNT,                           // 15
    ERROR_STICKER_TIMEOUT_FULL_SPEED,            // 16
    ERROR_BRIDGE_H_CURRENT,                      // 17
    ERROR_BRIDGE_L_CURRENT,                      // 18
    
    ERROR_COMM_WITH_SLAVES_LIGHT,                // 19        
    ERROR_EEPROM,                                // 20
    ERROR_STICKER_DURING_SLOPE_TO_DOCKING_SPEED, // 21
    ERROR_STICKER_TIMEOUT_DURING_DOCKING_SPEED,  // 22
    ERROR_TOO_MANY_SMALL_ERRORS,                 // 23
    ERROR_MOTOR_PULSES,                          // 24      
    ERROR_PULSES_TIMEOUT,                        // 25      
    ERROR_MOTOR_PULSES_LIGHT,                    // 26      
    ERROR_MOTOR_PULSES_LIGHT2,                   // 27        

    ERROR_MOTOR_PULSES2,                         // 28
    ERROR_MOTOR_PULSES3,                         // 29
    ERROR_MOTOR_PULSES4,                         // 30
    ERROR_MOTOR_PULSES5,                         // 31
    ERROR_MOTOR_PULSES6,                         // 32
    ERROR_MOTOR_PULSES7,                         // 33
    ERROR_MOTOR_HALL_H,                          // 34 
    ERROR_MOTOR_HALL_L,                          // 35
    ERROR_MOTOR_HALL_H_L,                        // 36
            
    ERROR_VCC_RIPPLE_LIGHT,                      // 37
            
            
    ERRORS_ARRAY_COUNT,                            
}enum_error;
    

typedef struct s_error
{
    u8    code;
    bool  critical;
    bool  active;
    bool  new_firmware_reset;
    void (*callback);
} s_error;




extern u8 error_id[4];
extern u32 error_id_u32;


//
extern bool slave_com_authorization;
extern bool motor_drive_authorization;


extern u8 error_light_global_counter;
extern u8 error_light[5];

extern struct s_error error_list[ERRORS_ARRAY_COUNT];

// Type d'erreur
extern u8 error_type;

extern u8 error_mode;
extern u8 error_direction;
extern u8 error_poster;
extern u8 error_state;

extern u16 error_pulsesH;
extern u16 error_pulsesL;

// Ordres vers les autres SM
extern u8 error_order_preauto;

// Code d'erreur
extern u8 error_code;


extern u16 error_light1_state;
extern u16 error_light2_state;


void error_init(void);
void error(u8 code);
void error_sm(void);

void error_start_of_manual_mode(void);
void error_end_of_manual_mode(void);
void error_reset_light_error(void);




#endif	/* ERRORS_H */

