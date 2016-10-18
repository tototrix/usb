#ifndef TIMER_PULSES_H
#define	TIMER_PULSES_H
#include "_Typedefs.h"

void timer_pulses_init(void);
void timer_pulses_clear(void);
u16  timer_pulses_get_valueH(void);
u16  timer_pulses_get_valueL(void);

u16  timer_pulses_get_globalH(void);
void timer_pulses_set_globalH(u16 value);
u16  timer_pulses_get_globalL(void);
void timer_pulses_set_globalL(u16 value);



#endif	/* TIMER_1MS_H */

