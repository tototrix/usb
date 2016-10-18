#include <_Global_Include.h>





typedef enum 
{
    DOOR_IDLE,
    DOOR_TEMPO,        
    DOOR_STOP_MOTOR1,
    DOOR_STOP_MOTOR2,
    DOOR_STOP_MOTOR3,
    DOOR_WAIT_CLOSE,
            
            
}door_security_sm_list;

bool door_opened_error = FALSE;
u8 door_state;
u8 door_opened = FALSE;
u32 door_ar = 1000;
u8 door = DOOR_INACTIVE_LEVEL;
volatile u16 door_timer1ms;
volatile u16 door_timer100ms;

void door_security_init(void)
{
    CAPTEUR_PORTE_TRIS  = INPUT;
    CAPTEUR_PORTE_CNPD  = TRUE;
    door_opened_error = FALSE;
    door_state = DOOR_IDLE;
    door_opened = FALSE;
    door_ar = 1000;
    door = DOOR_INACTIVE_LEVEL;
    timer1ms_register_variable((u16*)&door_timer1ms);
    timer1ms_register_variable((u16*)&door_timer100ms);
    
}


void door_security_sm(void)
{
    u8 next_state = door_state;
    

         
    if(CAPTEUR_PORTE == DOOR_ACTIVE_LEVEL && door_ar <1000) door_ar++;
    else if(CAPTEUR_PORTE == DOOR_INACTIVE_LEVEL && door_ar > 0) door_ar--;
    
    if(door_ar == 1000) door = DOOR_ACTIVE_LEVEL;
    else if(door_ar == 0x00) door = DOOR_INACTIVE_LEVEL;
    
    switch(door_state)
    {
        case DOOR_IDLE:
            door_opened_error = FALSE;
            door_opened = FALSE; 
            if(door == DOOR_INACTIVE_LEVEL)
            {
               door_timer1ms = 550;
               next_state = DOOR_TEMPO;
            }
            break;
        
        case DOOR_TEMPO:
            if(door == DOOR_ACTIVE_LEVEL)
            {
                next_state = DOOR_IDLE;
            }
            else if(door_timer1ms == 0x00)
            {
                door_timer100ms = 36000;
                door_opened = TRUE; 
                next_state = DOOR_STOP_MOTOR1;
            }
            break;
            
        case DOOR_STOP_MOTOR1:
                motorh_slope_xx_xs(motor.minimum_speed_value,100);
                motorl_slope_xx_xs(motor.minimum_speed_value,100);
                motor_slope_run();
                next_state = DOOR_STOP_MOTOR2;     
            break;
            
        case DOOR_STOP_MOTOR2:
            if(motor_slope_is_idle() == TRUE)
            {
                motor_slope_calc_phase(motor.error_mode.init_phase_list[0]);
                motor_slope_run();
                next_state = DOOR_STOP_MOTOR3;   
            }
            break;      
            
        case DOOR_STOP_MOTOR3:
            if(motor_slope_is_idle() == TRUE)
            {
                next_state = DOOR_WAIT_CLOSE;
            }
            
        case DOOR_WAIT_CLOSE:
            if(door_timer100ms == 0x00 && door_opened_error == FALSE)
            {
                door_opened_error = TRUE;
            }
            if(door == DOOR_ACTIVE_LEVEL)
            {
                motor_init_init();
                next_state = DOOR_IDLE;
            }
            break;
    }
    
    door_state = next_state;
}