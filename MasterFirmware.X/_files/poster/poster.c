#include <_Global_Include.h>

volatile struct struct_poster poster[5];



void poster_init(u16 enrh_full_speed_time,u16 enrl_full_speed_time,u16 showtime)
{
    u8 i;
    
    for(i=0;i<5;i++)
    {
        poster[i].show_time = showtime;
        poster[i].enrh_full_speed_time = enrh_full_speed_time;
        poster[i].enrl_full_speed_time = enrl_full_speed_time;
        
        poster[i]._enrh_T1  = 0x00;
        poster[i]._enrh_T2  = 0x00;
        poster[i]._enrh_T3  = 0x00;
        poster[i]._enrh_TS1_1 = 0x00;
        poster[i]._enrh_TS1_2 = 0x00;
        poster[i]._enrh_TS1_3 = 0x00;
        poster[i]._enrh_TS2_1 = 0x00;
        poster[i]._enrh_TS2_2 = 0x00;
        poster[i]._enrh_TS2_3 = 0x00;
        
        poster[i]._enrl_T1  = 0x00;
        poster[i]._enrl_T2  = 0x00;
        poster[i]._enrl_T3  = 0x00;
        poster[i]._enrl_TS1_1 = 0x00;
        poster[i]._enrl_TS1_2 = 0x00;
        poster[i]._enrl_TS1_3 = 0x00;
        poster[i]._enrl_TS2_1 = 0x00;
        poster[i]._enrl_TS2_2 = 0x00;
        poster[i]._enrl_TS2_3 = 0x00;
        
        
    }
}


