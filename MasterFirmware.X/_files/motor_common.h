/* 
 * File:   uart_motor_common.h
 * Author: Christophe
 *
 * Created on 10 juillet 2015, 09:18
 */

#ifndef MOTOR_COMMON_H
#define	MOTOR_COMMON_H
#include "_Typedefs.h"


typedef enum
{
    MOTOR_UNKNOWN_FAMILY,
    MOTOR_CC_FAMILY,                
    MOTOR_BDLC_FAMILY,                 
    MOTOR_ASYNC_FAMILY,     
}enum_motor_family;



typedef enum
{
    MOTOR_SHUNT_UNKNOWN          =  0xFF,
    MOTOR_SHUNT_CC               =  0x0A,
    MOTOR_SHUNT_CC_RM            =  0x0C,
    MOTOR_SHUNT_BRUSHLESS_HITO   =  0x09,
    MOTOR_SHUNT_BRUSHLESS_PRISMA =  0x0D,            
    MOTOR_SHUNT_ASYNC_MAPUB      =  0x04,//0x0C, // 0b1100
    MOTOR_SHUNT_ASYNC_ALCOM      =  0x02,//0x0A, // 0b1010
    MOTOR_SHUNT_ASYNC_VENU       =  0x03,//0x0B, // 0b1011
    MOTOR_SHUNT_ASYNC_ARCOMAT    =  0x01,//0x09, // 0b1001
}enum_motor_shunt;

typedef enum
{
    MOTOR_MODEL_UNKNOWN          ,
    MOTOR_MODEL_CC               ,
    MOTOR_MODEL_CC_RM            ,
    MOTOR_MODEL_BRUSHLESS_HITO   ,
    MOTOR_MODEL_BRUSHLESS_PRISMA ,            
    MOTOR_MODEL_ASYNC_MAPUB17    ,
    MOTOR_MODEL_ASYNC_MAPUB110   ,
    MOTOR_MODEL_ASYNC_ALCOM17    ,
    MOTOR_MODEL_ASYNC_ALCOM110   ,
    MOTOR_MODEL_ASYNC_VENU17     ,
    MOTOR_MODEL_ASYNC_ARCOMAT17  ,
    MOTOR_MODEL_ASYNC_ARCOMAT110 ,       
}enum_motor_model;

typedef enum
{
    PWM_TABLE_OFF,
    PWM_TABLE_DIRECT_STRONG,
    PWM_TABLE_DIRECT_WEAK,
    PWM_TABLE_INVERSE_STRONG,
    PWM_TABLE_INVERSE_WEAK, 
    PWM_TABLE_BRAKE,        
       
            
    ASYNC_DIRECT,
    ASYNC_INVERSE, 
    PWM_TABLE_COUNT,       
}enum_motor_table_cc_bdlc;

/*
typedef enum
{
    ASYNC_DIRECT,
    ASYNC_INVERSE,           
}enum_motor_direction_async;
*/

#define PWM_MOTOR_MAX_DUTY_CYCLE          95  // rapport cyclique maximum applicable sur les moteurs


#define MOD_INDEX_MAX   32767L
#define _0_DEGREES      0L        // Offset for Phase B (0 electrical degrees)
#define _120_DEGREES    21845L    // 0x5555 // Offset for Phase A (120 electrical degrees)
#define _240_DEGREES    43690L    // 0xAAAA // Offset for Phase C (240 electrical degrees)

#define POSTER_SHOWTIME           3500

#define CELLULE_TIMEOUT_INIT      8000
#define CELLULE_PASTILLE_MIN_MS     10
#define CELLULE_PASTILLE_MAX_MS    300
#define CELLULE_BANDE_MERE_MS      600

        

#endif	/* MOTOR_COMMON_H */

