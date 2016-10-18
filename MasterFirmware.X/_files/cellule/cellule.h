#ifndef CELLULE_H
#define	CELLULE_H


#define CELL_TIMER_INIT        10000
#define CELL_ACTIVE_LEVEL      1
#define CELL_INACTIVE_LEVEL    0

extern bool cell_event;
extern u16  cell_event_time;
extern u16  cell_time ;
extern bool cell;
extern u16 cell_pulses;

void cell_init(void);
void cell_process(void);
void cell_reset(void);





#endif	/* CELLULE_H */

