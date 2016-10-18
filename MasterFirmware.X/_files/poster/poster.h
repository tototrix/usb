/* 
 * File:   poster.h
 * Author: Christophe
 *
 * Created on 27 juillet 2015, 17:04
 */

#ifndef POSTER_H
#define	POSTER_H


#include "_Typedefs.h"

typedef struct struct_poster
{
    u16 enrh_full_speed_time;
    u16 enrl_full_speed_time;
    
    u16 _enrh_T1;
    u16 _enrh_T2;
    u16 _enrh_T3;
    u16 _enrh_T_AUTO;
    u16 _enrh_TS1_1;
    u16 _enrh_TS1_2;
    u16 _enrh_TS1_3;
    u16 _enrh_TS1_AUTO;
    u16 _enrh_TS2_1;
    u16 _enrh_TS2_2;
    u16 _enrh_TS2_3;
    u16 _enrh_TS2_AUTO;
    
    
    u16 _enrl_T1;
    u16 _enrl_T2;
    u16 _enrl_T3;
    u16 _enrl_T_AUTO;
    u16 _enrl_TS1_1;
    u16 _enrl_TS1_2;
    u16 _enrl_TS1_3;
    u16 _enrl_TS1_AUTO;
    u16 _enrl_TS2_1;
    u16 _enrl_TS2_2;
    u16 _enrl_TS2_3;
    u16 _enrl_TS2_AUTO;
     
    u16 enrh_comp1;
    u16 enrh_comp2;
    u16 enrl_comp1;
    u16 enrl_comp2;
    
    u16 show_time;
    u16 cell_pulses;
    
    u16 _enrh_poster_pulses;
    u16 _enrl_poster_pulses;
    
    
    u16 _enrh_TGV1;
    u16 _enrh_TGV2;
    u16 _enrh_TGV3;
    u16 _enrh_TGV_AUTO;
    
    u16 _enrl_TGV1;
    u16 _enrl_TGV2;
    u16 _enrl_TGV3;
    u16 _enrl_TGV_AUTO;
    
    
    
}struct_poster;


extern volatile struct struct_poster poster[5];

void poster_init(u16 enrh_full_speed_time,u16 enrl_full_speed_time,u16 showtime);


#endif	/* POSTER_H */

