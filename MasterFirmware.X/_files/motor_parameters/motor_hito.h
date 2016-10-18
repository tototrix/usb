#ifndef MOTOR_HITO_H
#define	MOTOR_HITO_H

//extern struct struct_motor motor_hito;

#define HITO_MINIMUM_SPEED                    0.0
#define HITO_MAXIMUM_SPEED                    95.0

#define HITO_ACCEL_MAX_SLOPE                   300// 300//  
#define HITO_DECEL_MAX_SLOPE                   -500// 

#define HITO_ACCEL_SLOPE_COEFF              (((HITO_MAXIMUM_SPEED - HITO_MINIMUM_SPEED)) / HITO_ACCEL_MAX_SLOPE)
#define HITO_DECEL_SLOPE_COEFF              (((HITO_MAXIMUM_SPEED - HITO_MINIMUM_SPEED)) / HITO_DECEL_MAX_SLOPE)



#define HITO_VBAT_VALUE0               2400
#define HITO_VBAT_COEFF0               1.0

#define HITO_VBAT_VALUE1               2550
#define HITO_VBAT_COEFF1               0.85

#define HITO_VBAT_VALUE2               2700
#define HITO_VBAT_COEFF2               0.82

#define HITO_VBAT_VALUE3               2800
#define HITO_VBAT_COEFF3               0.8



//---------------------------------------------------------------------------------------------------
// HITO ERREUR 
//---------------------------------------------------------------------------------------------------
#define ERROR_HITO_MOTORH_TABLE               PWM_TABLE_DIRECT_STRONG    
#define ERROR_HITO_MOTORH_SPEED               7
#define ERROR_HITO_MOTORH_SLOPE               SLOPE100
#define ERROR_HITO_MOTORL_TABLE               PWM_TABLE_OFF 
#define ERROR_HITO_MOTORL_SPEED               0
#define ERROR_HITO_MOTORL_SLOPE               SLOPE100

//---------------------------------------------------------------------------------------------------
// HITO MODE MANUEL 
//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
// ENRH
//---------------------------------------------------------------------------------------------------
#define MANUAL_HITO_ENRH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_HITO_ENRH_0_MOTORH_SPEED       0
#define MANUAL_HITO_ENRH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_HITO_ENRH_0_MOTORL_SPEED       0
#define MANUAL_HITO_ENRH_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRH_1_MOTORH_SPEED       7
#define MANUAL_HITO_ENRH_1_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_1_MOTORL_TABLE       PWM_TABLE_BRAKE
#define MANUAL_HITO_ENRH_1_MOTORL_SPEED       100
#define MANUAL_HITO_ENRH_1_MOTORL_SLOPE       0

#define MANUAL_HITO_ENRH_2_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRH_2_MOTORH_SPEED       55
#define MANUAL_HITO_ENRH_2_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_2_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_ENRH_2_MOTORL_SPEED       100
#define MANUAL_HITO_ENRH_2_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRH_3_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRH_3_MOTORH_SPEED       12
#define MANUAL_HITO_ENRH_3_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_3_MOTORL_TABLE       PWM_TABLE_INVERSE_WEAK//PWM_TABLE_BRAKE 
#define MANUAL_HITO_ENRH_3_MOTORL_SPEED       50
#define MANUAL_HITO_ENRH_3_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRH_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRH_4_MOTORH_SPEED       12
#define MANUAL_HITO_ENRH_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_4_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_HITO_ENRH_4_MOTORL_SPEED       12
#define MANUAL_HITO_ENRH_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRH_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRH_5_MOTORH_SPEED       7
#define MANUAL_HITO_ENRH_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRH_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_HITO_ENRH_5_MOTORL_SPEED       0
#define MANUAL_HITO_ENRH_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// ENRL
//---------------------------------------------------------------------------------------------------
#define MANUAL_HITO_ENRL_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_HITO_ENRL_0_MOTORH_SPEED       0
#define MANUAL_HITO_ENRL_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_HITO_ENRL_0_MOTORL_SPEED       0
#define MANUAL_HITO_ENRL_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRL_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRL_1_MOTORH_SPEED       7
#define MANUAL_HITO_ENRL_1_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_1_MOTORL_TABLE       PWM_TABLE_BRAKE
#define MANUAL_HITO_ENRL_1_MOTORL_SPEED       100
#define MANUAL_HITO_ENRL_1_MOTORL_SLOPE       0

#define MANUAL_HITO_ENRL_2_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK//PWM_TABLE_BRAKE    
#define MANUAL_HITO_ENRL_2_MOTORH_SPEED       35//100
#define MANUAL_HITO_ENRL_2_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_2_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_HITO_ENRL_2_MOTORL_SPEED       50
#define MANUAL_HITO_ENRL_2_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRL_3_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK//PWM_TABLE_BRAKE  
#define MANUAL_HITO_ENRL_3_MOTORH_SPEED       50
#define MANUAL_HITO_ENRL_3_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_3_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_HITO_ENRL_3_MOTORL_SPEED       12
#define MANUAL_HITO_ENRL_3_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRL_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRL_4_MOTORH_SPEED       12
#define MANUAL_HITO_ENRL_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_4_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_HITO_ENRL_4_MOTORL_SPEED       12
#define MANUAL_HITO_ENRL_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_ENRL_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_ENRL_5_MOTORH_SPEED       7
#define MANUAL_HITO_ENRL_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_ENRL_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_HITO_ENRL_5_MOTORL_SPEED       0
#define MANUAL_HITO_ENRL_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// DERH
//---------------------------------------------------------------------------------------------------
#define MANUAL_HITO_DERH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_HITO_DERH_0_MOTORH_SPEED       0
#define MANUAL_HITO_DERH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_DERH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_HITO_DERH_0_MOTORL_SPEED       0
#define MANUAL_HITO_DERH_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_DERH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_HITO_DERH_1_MOTORH_SPEED       7
#define MANUAL_HITO_DERH_1_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_DERH_1_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_DERH_1_MOTORL_SPEED       55
#define MANUAL_HITO_DERH_1_MOTORL_SLOPE       0

#define MANUAL_HITO_DERH_2_MOTORH_TABLE       PWM_TABLE_INVERSE_STRONG    
#define MANUAL_HITO_DERH_2_MOTORH_SPEED       40
#define MANUAL_HITO_DERH_2_MOTORH_SLOPE       SLOPE75
#define MANUAL_HITO_DERH_2_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_DERH_2_MOTORL_SPEED       55
#define MANUAL_HITO_DERH_2_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_DERH_3_MOTORH_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_HITO_DERH_3_MOTORH_SPEED       0
#define MANUAL_HITO_DERH_3_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_DERH_3_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_DERH_3_MOTORL_SPEED       100
#define MANUAL_HITO_DERH_3_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_DERH_4_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK    
#define MANUAL_HITO_DERH_4_MOTORH_SPEED       50
#define MANUAL_HITO_DERH_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_HITO_DERH_4_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_DERH_4_MOTORL_SPEED       100
#define MANUAL_HITO_DERH_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_HITO_DERH_5_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK    
#define MANUAL_HITO_DERH_5_MOTORH_SPEED       50
#define MANUAL_HITO_DERH_5_MOTORH_SLOPE       0
#define MANUAL_HITO_DERH_5_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_HITO_DERH_5_MOTORL_SPEED       100
#define MANUAL_HITO_DERH_5_MOTORL_SLOPE       0





//---------------------------------------------------------------------------------------------------
// HITO MODE INIT
//---------------------------------------------------------------------------------------------------
#define INIT_HITO_CELL_TIMEOUT_TIME             4500
#define INIT_HITO_CELL_INHIB_TIME_PASTILLE      500
#define INIT_HITO_CELL_INHIB_TIME_BM            500
#define INIT_HITO_CELL_DECR_SPEED               5
#define INIT_HITO_CELL_DECR_SLOPE               SLOPE100

#define INIT_HITO_START_CELL_MOTORH_DIR         PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_START_CELL_MOTORH_SPEED       25
#define INIT_HITO_START_CELL_MOTORH_SLOPE       SLOPE50
#define INIT_HITO_START_CELL_MOTORH_ADJUST_VBAT TRUE
#define INIT_HITO_START_CELL_MOTORL_DIR         PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_START_CELL_MOTORL_SPEED       0
#define INIT_HITO_START_CELL_MOTORL_SLOPE       0
#define INIT_HITO_START_CELL_MOTORL_ADJUST_VBAT TRUE

#define INIT_HITO_1_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_1_MOTORH_SPEED                13
#define INIT_HITO_1_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_1_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_1_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_1_MOTORL_SPEED                13
#define INIT_HITO_1_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_1_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_2_MOTORH_SPEED                13
#define INIT_HITO_2_MOTORH_SLOPE                10000
#define INIT_HITO_2_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_2_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_2_MOTORL_SPEED                13
#define INIT_HITO_2_MOTORL_SLOPE                10000
#define INIT_HITO_2_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_3_MOTORH_SPEED                60
#define INIT_HITO_3_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_3_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_3_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define INIT_HITO_3_MOTORL_SPEED                35
#define INIT_HITO_3_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_3_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_4_MOTORH_SPEED                7
#define INIT_HITO_4_MOTORH_SLOPE                SLOPE50
#define INIT_HITO_4_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_4_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG
#define INIT_HITO_4_MOTORL_SPEED                7
#define INIT_HITO_4_MOTORL_SLOPE                SLOPE50
#define INIT_HITO_4_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_5_MOTORH_SPEED                9
#define INIT_HITO_5_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_5_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_5_MOTORL_SPEED                9
#define INIT_HITO_5_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_5_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_6_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK   
#define INIT_HITO_6_MOTORH_SPEED                35
#define INIT_HITO_6_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_6_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_6_MOTORL_SPEED                60
#define INIT_HITO_6_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_6_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_7_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_7_MOTORH_SPEED                7
#define INIT_HITO_7_MOTORH_SLOPE                SLOPE75
#define INIT_HITO_7_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_7_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_7_MOTORL_SPEED                7
#define INIT_HITO_7_MOTORL_SLOPE                SLOPE75
#define INIT_HITO_7_MOTORL_ADJUST_VBAT          TRUE

#define INIT_HITO_8_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_8_MOTORH_SPEED                9
#define INIT_HITO_8_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_8_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_8_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_8_MOTORL_SPEED                9
#define INIT_HITO_8_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_8_MOTORL_ADJUST_VBAT          TRUE


//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur haut
#define INIT_HITO_9_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_9_MOTORH_SPEED                60
#define INIT_HITO_9_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_9_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_9_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define INIT_HITO_9_MOTORL_SPEED                30
#define INIT_HITO_9_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_9_MOTORL_ADJUST_VBAT          TRUE

// Pleine vitesse
#define INIT_HITO_FULL_SPEED_TIME               2000

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_HITO_10_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_10_MOTORH_SPEED                35
#define INIT_HITO_10_MOTORH_SLOPE                SLOPE100
#define INIT_HITO_10_MOTORH_ADJUST_VBAT          FALSE
#define INIT_HITO_10_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define INIT_HITO_10_MOTORL_SPEED                40
#define INIT_HITO_10_MOTORL_SLOPE                SLOPE100
#define INIT_HITO_10_MOTORL_ADJUST_VBAT          FALSE

// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_HITO_11_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_11_MOTORH_SPEED                35
#define INIT_HITO_11_MOTORH_SLOPE                100
#define INIT_HITO_11_MOTORH_ADJUST_VBAT          TRUE
#define INIT_HITO_11_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define INIT_HITO_11_MOTORL_SPEED                35
#define INIT_HITO_11_MOTORL_SLOPE                100
#define INIT_HITO_11_MOTORL_ADJUST_VBAT          FALSE

// Rampe arret moteur haut sur cellule
#define INIT_HITO_12_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_HITO_12_MOTORH_SPEED                (35/2)
#define INIT_HITO_12_MOTORH_SLOPE                15
#define INIT_HITO_12_MOTORH_ADJUST_VBAT          FALSE
#define INIT_HITO_12_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_HITO_12_MOTORL_SPEED                (35/2)
#define INIT_HITO_12_MOTORL_SLOPE                15
#define INIT_HITO_12_MOTORL_ADJUST_VBAT          FALSE
#define INIT_HITO_12_BRAKE_OVERRIDE              TRUE


//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// HITO MODE PREAUTO ET AUTO
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define AUTO_HITO_ENRH_FULL_SPEED_TIME               600
#define AUTO_HITO_ENRL_FULL_SPEED_TIME               700

#define AUTO_HITO_CELL_TIMEOUT_TIME                  4000
#define AUTO_HITO_CELL_INHIB_TIME_PASTILLE           1000
#define AUTO_HITO_CELL_INHIB_TIME_BM                 50


#define AUTO_HITO_ENRH_FULL_SPEED                    95 
#define AUTO_HITO_ENRH_DOCK_SPEED                    35
#define AUTO_HITO_ENRL_FULL_SPEED                    93
#define AUTO_HITO_ENRL_DOCK_SPEED                    35

// MAINTIEN 
#define AUTO_HITO_1_MOTORH_DIR                       PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_1_MOTORH_SPEED                     10
#define AUTO_HITO_1_MOTORH_SLOPE                     SLOPE100
#define AUTO_HITO_1_MOTORH_ADJUST_VBAT               FALSE
#define AUTO_HITO_1_MOTORL_DIR                       PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_1_MOTORL_SPEED                     10
#define AUTO_HITO_1_MOTORL_SLOPE                     SLOPE100
#define AUTO_HITO_1_MOTORL_ADJUST_VBAT               FALSE

//ENRH

// ACCELERATION VERS GRANDE VITESSE
#define AUTO_HITO_ENRH_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRH_2_MOTORH_SPEED                AUTO_HITO_ENRH_FULL_SPEED
#define AUTO_HITO_ENRH_2_MOTORH_SLOPE                SLOPE100
#define AUTO_HITO_ENRH_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_HITO_ENRH_2_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK
#define AUTO_HITO_ENRH_2_MOTORL_SPEED                10
#define AUTO_HITO_ENRH_2_MOTORL_SLOPE                0
#define AUTO_HITO_ENRH_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_HITO_ENRH_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRH_3_MOTORH_SPEED                AUTO_HITO_ENRH_FULL_SPEED//AUTO_HITO_ENRH_DOCK_SPEED
#define AUTO_HITO_ENRH_3_MOTORH_SLOPE                0
#define AUTO_HITO_ENRH_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_HITO_ENRH_3_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define AUTO_HITO_ENRH_3_MOTORL_SPEED                35
#define AUTO_HITO_ENRH_3_MOTORL_SLOPE                50
#define AUTO_HITO_ENRH_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_HITO_ENRH_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRH_4_MOTORH_SPEED                AUTO_HITO_ENRH_DOCK_SPEED
#define AUTO_HITO_ENRH_4_MOTORH_SLOPE                50
#define AUTO_HITO_ENRH_4_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_HITO_ENRH_4_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define AUTO_HITO_ENRH_4_MOTORL_SPEED                35
#define AUTO_HITO_ENRH_4_MOTORL_SLOPE                0
#define AUTO_HITO_ENRH_4_MOTORL_ADJUST_VBAT          FALSE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_HITO_ENRH_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRH_5_MOTORH_SPEED                (AUTO_HITO_ENRH_DOCK_SPEED/2)
#define AUTO_HITO_ENRH_5_MOTORH_SLOPE                15
#define AUTO_HITO_ENRH_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRH_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRH_5_MOTORL_SPEED                (AUTO_HITO_ENRH_DOCK_SPEED/2)//60
#define AUTO_HITO_ENRH_5_MOTORL_SLOPE                15
#define AUTO_HITO_ENRH_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRH_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_HITO_ENRH_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRH_6_MOTORH_SPEED                10
#define AUTO_HITO_ENRH_6_MOTORH_SLOPE                0//100
#define AUTO_HITO_ENRH_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRH_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRH_6_MOTORL_SPEED                10
#define AUTO_HITO_ENRH_6_MOTORL_SLOPE                0
#define AUTO_HITO_ENRH_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRH_6_BRAKE_OVERRIDE              TRUE


//ENRL

// ACCELERATION VERS GRANDE VITESSE
#define AUTO_HITO_ENRL_2_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_HITO_ENRL_2_MOTORH_SPEED                15
#define AUTO_HITO_ENRL_2_MOTORH_SLOPE                0
#define AUTO_HITO_ENRL_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_HITO_ENRL_2_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRL_2_MOTORL_SPEED                AUTO_HITO_ENRL_FULL_SPEED
#define AUTO_HITO_ENRL_2_MOTORL_SLOPE                SLOPE100
#define AUTO_HITO_ENRL_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_HITO_ENRL_3_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_HITO_ENRL_3_MOTORH_SPEED                45
#define AUTO_HITO_ENRL_3_MOTORH_SLOPE                30
#define AUTO_HITO_ENRL_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_HITO_ENRL_3_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRL_3_MOTORL_SPEED                AUTO_HITO_ENRL_FULL_SPEED
#define AUTO_HITO_ENRL_3_MOTORL_SLOPE                0
#define AUTO_HITO_ENRL_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_HITO_ENRL_4_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_HITO_ENRL_4_MOTORH_SPEED                40
#define AUTO_HITO_ENRL_4_MOTORH_SLOPE                100
#define AUTO_HITO_ENRL_4_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRL_4_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRL_4_MOTORL_SPEED                AUTO_HITO_ENRL_DOCK_SPEED
#define AUTO_HITO_ENRL_4_MOTORL_SLOPE                50
#define AUTO_HITO_ENRL_4_MOTORL_ADJUST_VBAT          TRUE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_HITO_ENRL_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG   
#define AUTO_HITO_ENRL_5_MOTORH_SPEED                (AUTO_HITO_ENRL_DOCK_SPEED/2)
#define AUTO_HITO_ENRL_5_MOTORH_SLOPE                18
#define AUTO_HITO_ENRL_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRL_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRL_5_MOTORL_SPEED                (AUTO_HITO_ENRL_DOCK_SPEED/2)
#define AUTO_HITO_ENRL_5_MOTORL_SLOPE                18
#define AUTO_HITO_ENRL_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRL_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_HITO_ENRL_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_HITO_ENRL_6_MOTORH_SPEED                10
#define AUTO_HITO_ENRL_6_MOTORH_SLOPE                0
#define AUTO_HITO_ENRL_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRL_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_HITO_ENRL_6_MOTORL_SPEED                10
#define AUTO_HITO_ENRL_6_MOTORL_SLOPE                0
#define AUTO_HITO_ENRL_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_HITO_ENRL_6_BRAKE_OVERRIDE              TRUE






#endif	/* MOTOR_HITO_H */

