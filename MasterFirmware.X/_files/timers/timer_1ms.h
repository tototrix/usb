#ifndef TIMER_1MS_H
#define	TIMER_1MS_H
#include "_Typedefs.h"

#define TIMER1MS_ARRAY_SIZE        32   
#define TIMER1MS_TICK_MS          1UL   // 1 ms
 

extern u32 seconds_counter;

void timer1ms_init(void);
void timer1ms_register_variable(u16 *ptr);
void timer1ms_start(void);
void timer1ms_stop(void);
void timer1ms_register_callback(void* cb);


#endif	/* TIMER_1MS_H */

