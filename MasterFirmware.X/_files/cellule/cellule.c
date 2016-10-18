#include <_Global_Include.h>


bool cell_event               = FALSE;
bool cell_counting            = FALSE;
u16  cell_event_time          = 0x00;
u16  cell_time                = 0x00;
volatile u16  cell_timer_ms   = 0x00;
u8   cell_ar_var              = 0x80;
bool cell                     = CELL_INACTIVE_LEVEL;
u16 cell_pulses               = 0x00;  // Contient ne nombre de pulses actifs de la cellule
u16 cell_pulses_start         = 0x00;
u16 cell_pulses_stop          = 0x00;



void cell_ar(void);

void cell_init(void)
{
    
    cell_event      = FALSE;
    cell_event_time = 0x00;
    cell_ar_var     = 0x80;
    cell            = CELL_INACTIVE_LEVEL;
    cell_counting   = FALSE;
    cell_timer_ms   = 0x00;
    cell_time       = 0x00;
    
    timer1ms_register_variable((u16*)&cell_timer_ms);   
    timer1ms_register_callback(cell_ar);
}

void cell_reset(void)
{
  cell_event      = FALSE;
  cell_event_time = 0x00;
  cell_counting   = FALSE;  
  cell_timer_ms   = CELL_TIMER_INIT;
  cell_time       = 0x00;
}

void cell_ar(void)
{
    cell_ar_var<<=1;
    cell_ar_var += CELLULE;
    if(cell_ar_var == 0xFF)
    {
        cell         = CELL_ACTIVE_LEVEL;
        cell_feature = TRUE;
    }
    else if(cell_ar_var == 0x00) cell = CELL_INACTIVE_LEVEL;
}

void cell_process(void)
{
    // Si un front montant sur la cellule est vu
    if((cell == CELL_ACTIVE_LEVEL) && (cell_counting == FALSE))
    {
        cell_pulses_start = timer_pulses_get_valueH();;
        cell_counting = TRUE;
        cell_timer_ms = CELL_TIMER_INIT;
        cell_event    = FALSE;
        cell_time     = 0x00;        
    }
    // Sinon si la cellule est active
    else if((cell == CELL_ACTIVE_LEVEL) && (cell_counting == TRUE))
    {
       cell_time =  (CELL_TIMER_INIT - cell_timer_ms);
    }
    // Sinon si un front descendant est vu
    else if( (cell == CELL_INACTIVE_LEVEL)&& (cell_counting == TRUE))
    {

        cell_pulses_stop = timer_pulses_get_valueH();
        cell_pulses = cell_pulses_stop - cell_pulses_start;

        cell_event_time = (CELL_TIMER_INIT - cell_timer_ms);
        cell_counting   = FALSE;
        cell_time       = 0x00;
        cell_event      = TRUE;  
    }
}




