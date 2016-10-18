#include <_Global_Include.h>

u16 *timer100ms_array_pointer[TIMER100MS_ARRAY_SIZE];
u16 timer100ms_index=0x00;

u8 timer100ms_seconds;
//=========================================================================
// Function : Initialisation
// Input(s) : -
// Output   : -
//=========================================================================
void timer100ms_init(void)
{
    for(timer100ms_index=0;timer100ms_index<TIMER100MS_ARRAY_SIZE;timer100ms_index++)
    {
        timer100ms_array_pointer[timer100ms_index] = 0x00;
    } 
    timer100ms_index = 0x00;
    timer100ms_seconds = 10;
    
    TMR4 = 0x00;
    T4CONbits.TCKPS = 2; 
    PR4 = 23400;
    T4CONbits.TON = FALSE;
    IEC1bits.T4IE = TRUE;
    IFS1bits.T4IF = FALSE;
}


//=========================================================================
// Function : Ajoute une variable à gérer
// Input(s) : u16 *ptr = pointeur de la variable à ajouter
// Output   : -
//=========================================================================
void timer100ms_register_variable(u16 *ptr)
{
    u16 i;
    bool exist = FALSE;
    if(timer100ms_index >= TIMER100MS_ARRAY_SIZE) return;
    else
    {
      for(i=0;i<timer100ms_index;i++)
        {
            if(timer100ms_array_pointer[i] == ptr)
            {
                exist = TRUE;
            }
        }
        if(exist == FALSE)
        {
            timer100ms_array_pointer[timer100ms_index++] = ptr;   
        }
    }
}

//=========================================================================
// Function : Demarre le timer
// Input(s) : -
// Output   : -
//=========================================================================
void timer100ms_start(void)
{
    T4CONbits.TON = TRUE;
}

//=========================================================================
// Function : Arrete le timer
// Input(s) : -
// Output   : -
//=========================================================================
void timer100ms_stop(void)
{
    T4CONbits.TON = FALSE;
}

//=========================================================================
// Function : Routine d'interruption
// Input(s) : -
// Output   : -
//=========================================================================
void __attribute__((interrupt, auto_psv)) _T4Interrupt(void) 
{
    volatile u8 i;
    volatile bool bisextile;
    volatile u16 temp16;
    
    for(i=0;i<timer100ms_index;i++)
    {
        if(timer100ms_array_pointer[i] != 0x00)
        {
            if(*(timer100ms_array_pointer[i]) >0)
            {
                *(timer100ms_array_pointer[i]) = (*(timer100ms_array_pointer[i])) -1;
            }
        }
    }
    
    
    if(timer100ms_seconds == 0x00)
    {
        timer100ms_seconds = 10;
        
        if(global_dt_sync_ok)
        {
            global_dt_seconds++;
            if(global_dt_seconds>=60)
            {
                global_dt_seconds = 0x00;
                global_dt_minuts++;
                if(global_dt_minuts>=60)
                {
                    global_dt_minuts = 0x00;
                    global_dt_hours++;
                    if(global_dt_hours >= 24)
                    {
                        global_dt_hours = 0x00;
                        
                        bisextile = FALSE;
                        temp16 = 2000 + global_dt_year;
                        
                        if( ((temp16%4) == 0) &&
                            ((temp16%100)>0 && (temp16%400) == 0x00) 
                           )
                        {
                            bisextile = TRUE;
                        }
                        
                        if(global_dt_month == 1) i = 31;
                        else if(global_dt_month == 2)
                        {
                            if(bisextile) i =29;
                            else i=28;
                        }
                        else if(global_dt_month == 3) i = 31;
                        else if(global_dt_month == 4) i = 30;
                        else if(global_dt_month == 5) i = 31;
                        else if(global_dt_month == 6) i = 30;
                        else if(global_dt_month == 7) i = 31;
                        else if(global_dt_month == 8) i = 31;
                        else if(global_dt_month == 9) i = 30;
                        else if(global_dt_month == 10) i = 31;
                        else if(global_dt_month == 11) i = 30;
                        else if(global_dt_month == 12) i = 31;
                        
                               
                        global_dt_days++;
                        if(global_dt_days > i)
                        {
                            global_dt_days = 0x01;
                            global_dt_month++;
                            if(global_dt_month > 12)
                            {
                                global_dt_month = 0x01;
                                global_dt_year++;
                            }
                        }  
                    }
                }
            }
        }
        
    }
    

    IFS1bits.T4IF = FALSE;
}