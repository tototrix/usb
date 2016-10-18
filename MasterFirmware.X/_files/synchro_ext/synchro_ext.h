
#ifndef SYNCHRO_EXT_H
#define	SYNCHRO_EXT_H

#define SYNC_EXT_TIMER_INIT       60000
#define SYNC_EXT_ACTIVE_LEVEL         1
#define SYNC_EXT_INACTIVE_LEVEL       0


#define SYNC_EXT_LONG_PULSE_MIN     700
#define SYNC_EXT_SHORT_PULSE_MIN    100
#define SYNC_EXT_DISABLE_TIME     30000


extern bool synchro_ext_mode;
extern bool synchro_ext_long_pulse;
extern bool synchro_ext_short_pulse;

void synchro_ext_init(void);
void synchro_ext_process(void);


#endif	/* SYNCHRO_EXT_H */

