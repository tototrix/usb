#ifndef MOTOR_MANU_H
#define	MOTOR_MANU_H
#include "_Typedefs.h"


extern bool motor_manu_adjust_pulses;


void manu_security_on(void);
void manu_security_off(void);

void motor_manu_init(void);
void motor_manu_sm(void);

void start_of_manual_mode(void);
void end_of_manual_mode(void);

#endif	/* MOTOR_MANU_H */

