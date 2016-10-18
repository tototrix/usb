#include <_Global_Include.h>

u16 *timer1ms_array_pointer[TIMER1MS_ARRAY_SIZE];
u16 timer1ms_index=0x00;

void (*timer1ms_array_callback[TIMER1MS_ARRAY_SIZE])(void);
u16 timer1ms_index_callback=0x00;


u16 loc_s10 = 1000;
u32 seconds_counter = 0x00;

//=========================================================================
// Function : Initialisation
// Input(s) : -
// Output   : -
//=========================================================================
void timer1ms_init(void)
{
    for(timer1ms_index=0;timer1ms_index<TIMER1MS_ARRAY_SIZE;timer1ms_index++)
    {
        timer1ms_array_pointer[timer1ms_index] = 0x00;
    }
    timer1ms_index = 0x00;
    
    for(timer1ms_index_callback=0;timer1ms_index_callback<TIMER1MS_ARRAY_SIZE;timer1ms_index_callback++)
    {
        timer1ms_array_callback[timer1ms_index_callback] = 0x00;
    }
    timer1ms_index_callback = 0x00;
    
    TMR3 = 0x00;
    T3CONbits.TCKPS = 0;  
    PR3 = 15000;
    T3CONbits.TON = FALSE;
    IFS0bits.T3IF = FALSE; 
    IEC0bits.T3IE = TRUE;
    
}

void timer1ms_register_callback(void* cb)
{
    u16 i;
    bool exist = FALSE;
    if(timer1ms_index_callback >= TIMER1MS_ARRAY_SIZE) return;
    else
    {
        for(i=0;i<timer1ms_index_callback;i++)
        {
            if(timer1ms_array_callback[i] == cb)
            {
                exist = TRUE;
            }
        }
        if(exist == FALSE)
        {
            timer1ms_array_callback[timer1ms_index_callback++] = cb;   
        }
    }   
}
//=========================================================================
// Function : Ajoute une variable à gérer
// Input(s) : u16 *ptr = pointeur de la variable à ajouter
// Output   : -
//=========================================================================
void timer1ms_register_variable(u16 *ptr)
{
    u16 i;
    bool exist = FALSE;
    if(timer1ms_index >= TIMER1MS_ARRAY_SIZE) return;
    else
    {
        for(i=0;i<timer1ms_index;i++)
        {
            if(timer1ms_array_pointer[i] == ptr)
            {
                exist = TRUE;
            }
        }
        if(exist == FALSE)
        {
            timer1ms_array_pointer[timer1ms_index++] = ptr;   
        }
    }   
}

//=========================================================================
// Function : Demarre le timer
// Input(s) : -
// Output   : -
//=========================================================================
void timer1ms_start(void)
{
    T3CONbits.TON = TRUE;
}

//=========================================================================
// Function : Arrete le timer
// Input(s) : -
// Output   : -
//=========================================================================
void timer1ms_stop(void)
{
    T3CONbits.TON = FALSE;
}

//=========================================================================
// Function : Routine d'interruption
// Input(s) : -
// Output   : -
//=========================================================================
void __attribute__((interrupt, auto_psv)) _T3Interrupt(void) 
{
    volatile u8 i;

    for(i=0;i<timer1ms_index;i++)
    {
        if(timer1ms_array_pointer[i] != 0x00)
        {
            if(*(timer1ms_array_pointer[i]) >0)
            {
                *(timer1ms_array_pointer[i]) = (*(timer1ms_array_pointer[i])) -1;
            }
        }
    }
    
    if(loc_s10 > 0) loc_s10--;
    else
    {
        loc_s10 = 1000;
        seconds_counter++;
    }
    
    
    for(i=0;i<timer1ms_index_callback;i++)
    {
        if(timer1ms_array_callback[i] != 0x00)
        {
            timer1ms_array_callback[i]();
        }
    }
    
    IFS0bits.T3IF = FALSE;
}