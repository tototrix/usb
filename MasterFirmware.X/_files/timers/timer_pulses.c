
#include "_Global_Include.h"


 u16 timer_pulse_global_counterH;
 u16 timer_pulse_global_counterL;
 
 
 u16 timer_pulses_H;
 u16 timer_pulses_L;
 
 
void timer_pulses_init(void)
{
    PULSE_H_DIR_TRIS = INPUT;
    PULSE_L_DIR_TRIS = INPUT;
    timer_pulse_global_counterH = 0x00;
    timer_pulse_global_counterL = 0x00;
    
    PULSE_H_TRIS = INPUT;
    PULSE_L_TRIS = INPUT;   
    //SPARE_M_TRIS = INPUT;
   

    T1CONbits.TGATE = 1;
    TMR1 = 0x00;   
    PR1 = 1000;
    IEC0bits.T1IE = TRUE;
    IFS0bits.T1IF = FALSE; 
    T1CONbits.TON = TRUE;
    
    
    RPINR3bits.T2CKR = 51;
    /*T2CONbits.TON = TRUE;
    T2CONbits.TCS = 1;
    TMR2 = 0x00; */
    
    
    T2CONbits.TGATE = 1;
    TMR2 = 0x00;   
    PR2 = 1000;
    IEC0bits.T2IE = TRUE;
    IFS0bits.T2IF = FALSE; 
    T2CONbits.TON = TRUE;
    
}

void timer_pulses_clear(void)
{
    timer_pulses_H = 0x00;
    timer_pulses_L = 0x00;
}


u16 timer_pulses_get_valueH(void)
{
    return timer_pulses_H;
}

u16 timer_pulses_get_valueL(void)
{
    return timer_pulses_L;
}
u16  timer_pulses_get_globalH(void)
{
    return timer_pulse_global_counterH;
}
void timer_pulses_set_globalH(u16 value)
{
    timer_pulse_global_counterH = value;
}

u16  timer_pulses_get_globalL(void)
{
    return timer_pulse_global_counterL;
}
void timer_pulses_set_globalL(u16 value)
{
    timer_pulse_global_counterL = value;
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) 
{

    timer_pulses_L++;
    
    if(PULSE_L_DIR == 0) // ENRH sens normal
    {
        timer_pulse_global_counterL++;
    }
    else
    {
        if(timer_pulse_global_counterL >0) timer_pulse_global_counterL--;
    }
    IFS0bits.T1IF = FALSE;
}

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void) 
{

    timer_pulses_H++;
    
    if(PULSE_H_DIR == 0) // ENRH sens normal
    {
        timer_pulse_global_counterH++;
    }
    else
    {
        if(timer_pulse_global_counterH >0) timer_pulse_global_counterH--;
    }
    IFS0bits.T2IF = FALSE;
}