#ifndef TIMER_100MS_H
#define	TIMER_100MS_H
#include "_Typedefs.h"

#define TIMER100MS_ARRAY_SIZE        32   
#define TIMER100MS_TICK_MS        100UL   // 100 ms
  

void timer100ms_init(void);
void timer100ms_register_variable(u16 *ptr);
void timer100ms_start(void);
void timer100ms_stop(void);



#endif	/* TIMER_1MS_H */

