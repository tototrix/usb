
#ifndef MOTOR_AUTO_H
#define	MOTOR_AUTO_H

#define MOTOR_AUTO_CYCLE_COUNT_FIRST_INIT        1000//1000//1000//10//1000   // Nombre de cycles pour faire un preauto la premiere fois
#define MOTOR_AUTO_CYCLE_COUNT_WITH_CELL         6000//6000       // Nombre de cycles pour faire un préauto ensuite
#define MOTOR_AUTO_CYCLE_COUNT_WITHOUT_CELL      3000//3000             // Nombre de cycles pour faire un ajustement en mode sans pastille


typedef enum
{
    MOTOR_AUTO_NOP,
    MOTOR_AUTO_ERROR_STOP,
    MOTOR_AUTO_ERROR_STOP2,
    MOTOR_AUTO_ERROR_STOP3,
    MOTOR_AUTO_START,
            
    MOTOR_AUTO_DISPLAY,
    
    MOTOR_AUTO_INIT_STOP1,
    MOTOR_AUTO_INIT_STOP2,
    MOTOR_AUTO_INIT_STOP3,
                   
    MOTOR_AUTO_SLOPE_TO_FULL_SPEED,
    MOTOR_AUTO_FULL_SPEED,//10
    MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED1,
    MOTOR_AUTO_SLOPE_TO_DOCKING_SPEED2,
    MOTOR_AUTO_DOCKING_SPEED,
    MOTOR_AUTO_POSTER_STOP_STICKER1, 
    MOTOR_AUTO_POSTER_STOP_STICKER2, 
    MOTOR_AUTO_POSTER_STOP_GET_REG_SPEED,
    MOTOR_AUTO_POSTER_STOP_STICKER3,
           
    MOTOR_AUTO_NO_CELL_SLOPE_TO_FULL_SPEED,//18
    MOTOR_AUTO_NO_CELL_FULL_SPEED,
    MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED1,
    MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED2,
    MOTOR_AUTO_NO_CELL_SLOPE_TO_DOCKING_SPEED3,        
    MOTOR_AUTO_NO_CELL_DOCKING_SPEED1, // 23
    MOTOR_AUTO_NO_CELL_DOCKING_SPEED2,
            
    MOTOR_AUTO_NO_CELL_POSTER_STOP_STICKER1, 
    MOTOR_AUTO_NO_CELL_POSTER_STOP_STICKER2, 
    MOTOR_AUTO_NO_CELL_POSTER_ADJUST,     
                   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK1,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK2,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK3,//30
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK4,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK5,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK6,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK7,
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK8,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK9, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK10, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK11, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK12, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK13, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK14, 
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK15, 
            
            
            
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON1,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON2,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_ON3,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF1,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF2,   
    MOTOR_AUTO_NO_CELL_AUTO_TWEAK_FILTER_OFF3,   
            
            
            
            
    MOTOR_AUTO_NO_CELL_NO_PULSES_1,
    MOTOR_AUTO_NO_CELL_NO_PULSES_2,
    MOTOR_AUTO_NO_CELL_NO_PULSES_3,
            
            
            
    MOTOR_AUTO_ANALYSE_BRAKE,        
    MOTOR_AUTO_BRAKE,        
            
}enum_motor_auto_sm;


extern volatile u8 motor_auto_init_count;
extern volatile u8 motor_auto_tweak_count;
extern volatile u32 motor_auto_cycle_count_total;
extern volatile u8 motor_auto_tweak_order_start_cnt;
extern volatile u8 motor_auto_tweak_order_end_cnt;


extern u8 motor_auto_poster_index;

extern u16 motor_auto_pulses_cnt1;
extern u16 motor_auto_pulses_cnt2;

extern bool motor_auto_cycle_reset;
extern bool motor_auto_cycle_init_param;
// Indique si le mobilier est en cours de defilement ou en affichage
extern u8 motor_auto_scrolling;


extern u8  motor_auto_cycle_state;
// Etat en cours de la ME
extern u8 motor_auto_state;

extern u16 motor_auto_cycle_count;


void motor_auto_init(void);
void motor_auto_sm(void);

#endif	/* MOTOR_AUTO_H */

