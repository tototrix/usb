#ifndef MOTOR_H
#define	MOTOR_H
#include "_Typedefs.h"

extern u8 motorh_current_speed;            // vitesse actuelle du moteur haut
extern u8 motorl_current_speed;            // vitesse actuelle du moteur bas
extern u8 motorh_current_mode_dir;         // table de commutation actuelle du moteur haut
extern u8 motorl_current_mode_dir;         // table de commutation actuelle du moteur bas

#define ASYNC_ADJUST_SPEED_STEPS         2
#define PREAUTO_SECURITY_TIME          500




extern u8 motorh_switch;
extern u8 motorl_switch;

extern u8 motorh_type;
extern u8 motorl_type;

extern u8 motor_type_eeprom;

extern bool motor_critical_drive;

extern u16 motor_pulses_count_extreme_tape_H;
extern u16 motor_pulses_count_extreme_tape_L;
extern u16 motor_pulses_count_poster;
extern u16 motor_pulses_poster[5];
extern u16 motor_pulses_total_count;

//extern u8 motorh_shunt;
//extern u8 motorl_shunt;

// Permet de savoir dans quel sens on defile
typedef enum
{
    ENRH,
    ENRL,
    NO_DIRECTION,        
}enum_motor_direction;






extern u8 motor_direction;


extern struct struct_motor_status motor_status;
extern struct struct_motor motor;

extern volatile u16 motor_timer_ms;
extern volatile u16 motor_timer2_ms;
extern volatile u16 motor_timer3_ms;


extern volatile u16 motor_save_enrh_dock_speed_incr;
extern volatile u16 motor_save_enrl_dock_speed_incr;
extern volatile u16 motor_save_timeout_init_cell_timeout;
extern volatile u16 motor_save_timeout_init_cell_inhib;
extern volatile u16 motor_save_timeout_auto_cell_timeout;
extern volatile u16 motor_save_timeout_auto_cell_inhib;
void motor_timeout_save(void);
void motor_timeout_restore(void);
void motor_timeout_adjust_by_speed_incr(void);





void init_motor(void);

void motor_copy_phase_slope(struct struct_slope_phase *src,struct struct_slope_phase *dest,u8 new_slope);
void motor_copy_phase_slope_div(struct struct_slope_phase *src,struct struct_slope_phase *dest,u8 div);
bool motor_is_phase_equal(struct struct_slope_phase p1,struct struct_slope_phase p2);
void motor_slope_calc_phase(struct struct_slope_phase dest_phase);
bool motor_slope_is_idle(void);
void motor_slope_run(void);
void motor_slope_pulses_H(u8 value,u16 max_value);
void motor_slope_pulses_L(u8 value,u16 max_value);
void motor_slope_pulses_H_L(u8 valueH,u16 max_valueH,u8 valueL,u16 max_valueL);
void motor_slope_get_reg_speed(void);


void motor_slope_sm(void);



u8  motorh_get_current_mode_dir(void);
u16 motorh_get_current_speed(void);
u8  motorl_get_current_mode_dir(void);
u16 motorl_get_current_speed(void);

void motorh_slope_xx_xs(u16 end_speed,u16 slope);
void motorl_slope_xx_xs(u16 end_speed,u16 slope);
void motorh_slope_mx_xs(u8 start_dir,u16 end_speed,u16 slope);
void motorl_slope_mx_xs(u8 start_dir,u16 end_speed,u16 slope);
void motorh_slope_xx_ms(u8 end_dir,u16 end_speed,u16 slope);
void motorl_slope_xx_ms(u8 end_dir,u16 end_speed,u16 slope);
void motorh_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 slope);
void motorl_slope_mx_ms(u8 start_dir,u8 end_dir,u16 end_speed,u16 slope);
void motorh_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 slope);
void motorl_slope_ms_ms(u8 start_dir,u16 start_speed,u8 end_dir,u16 end_speed,u16 slope);

void motor_set_model_mcc(void);
void motor_set_model_mcc_rm(void);
void motor_set_model_hito(void);
void motor_set_model_prisma(void);
void motor_set_model_mapub17(void);
void motor_set_model_mapub110(void);
void motor_set_model_alcom17(void);
void motor_set_model_alcom110(void);
void motor_set_model_venu17(void);



#endif

