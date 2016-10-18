#ifndef MOTOR_STRUCT_PARAMETERS_H
#define	MOTOR_STRUCT_PARAMETERS_H
#include "_Typedefs.h"




typedef struct struct_slope_phase
{
    u8       motorh_mode_dir;
    double   motorh_speed;
    u16      motorh_slope;
    bool     motorh_adjust_vbat;
    u8       motorl_mode_dir;
    double   motorl_speed;
    u16      motorl_slope;  
    bool     motorl_adjust_vbat;
    bool     brake_override;
}struct_slope_phase;

typedef struct struct_motor_manual
{
    struct struct_slope_phase manual_enrh_phase_list[6];
    struct struct_slope_phase manual_enrl_phase_list[6];
    struct struct_slope_phase manual_derh_phase_list[6];  
}struct_motor_manual;


typedef struct struct_motor_init
{
    u16    cell_timeout_time;
    u16    cell_inhib_time_pastille;
    u16    cell_inhib_time_bm;
    u16    init_cell_decr_speed;
    u16    init_cell_decr_slope;
    u16    init_full_speed_time;
    u16    init_cell_between_time;
    u16    enrh_dock_speed;
    struct struct_slope_phase init_phase_list[13];  
}struct_motor_init;


typedef struct struct_motor_preauto_auto
{
    u16 preauto_enrh_full_speed_time;
    u16 preauto_enrl_full_speed_time;
    
    u16 cell_timeout_time;
    u16 cell_inhib_time_pastille;
    u16 cell_inhib_time_bm; 
    
    u16 enrh_dock_speed;
    u16 enrl_dock_speed;
    
    struct struct_slope_phase enrh_phase_list[7];
    struct struct_slope_phase enrl_phase_list[7]; 
}struct_motor_preauto_auto;


typedef struct struct_motor_error
{
    struct struct_slope_phase init_phase_list[1];  
}struct_motor_error;


typedef struct struct_motor_vbat_coeff
{
    u16 vbat_value;
    double coeff_a;
    double coeff_b;  
}struct_motor_vbat_coeff;

typedef struct struct_motor
{
    // GENERIQUE
    u8      family;
    u8      model;

    double  minimum_speed_value;       // vitesse maximum
    double  maximum_speed_value;       // vitesse minimum
      
    double  maximum_accel_slope_coeff; // coefficient maxi d'acceleration
    double  maximum_decel_slope_coeff; // coefficient maxi de deceleration
    
    struct  struct_motor_vbat_coeff motor_vbat[4]; // coefficients de correction en fonction de la tension batterie

    //
    u16     enrh_speed_adjust;         // palier de correction de la vitesse en montée
    u16     enrl_speed_adjust;         // palier de correction de la vitesse en descente
    
    
    // INCREMENTS VITESSES ASYNC (AVEC TELECOMMANDE)
    u16     enrh_dock_speed_incr;      // vitesse de correction à ajouter à la petite vitesse en montée
    u16     enrl_dock_speed_incr;      // vitesse de correction à ajouter à la petite vitesse en descente
    
    
    // AJUSTEMENT POSITION AFFICHE AVEC PULSES
    struct struct_slope_phase pulse_adjust_enrh;
    struct struct_slope_phase pulse_adjust_enrl;
   
    // ETAT EN CAS D'ARRET SUR ERREUR
    struct struct_motor_error error_mode; 
    // MANUEL
    struct struct_motor_manual manual_mode;

    // INIT
    struct struct_motor_init init_mode;
    // PREAUTO_AUTO
    struct struct_motor_preauto_auto preauto_auto;
    
    
    // PULSES
    u8  docking_pulses;               // nombre de pulses / 100ms pour l'accostage
    u8  docking_pulses_security;      // nombre de points de securite
    u16 pulses_count_extreme_tape_H;  // taille en points de la bande mère haute
    u16 pulses_count_extreme_tape_L;  // taille en points de la bande mère basse
    u16 pulses_count_poster;          // taille en points d'une affiche
    u16 pulses_no_cell_tweak_count;   // 
    
}struct_motor;

#endif

