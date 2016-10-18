#ifndef MOTOR_MCC_RM_H
#define	MOTOR_MCC_RM_H

//extern struct struct_motor motor_mcc;

#define MCC_RM_MINIMUM_SPEED                    0.0
#define MCC_RM_MAXIMUM_SPEED                    95.0


#define MCC_RM_ACCEL_MAX_SLOPE           500//800
#define MCC_RM_DECEL_MAX_SLOPE         -1000//-1500

#define MCC_RM_ACCEL_SLOPE_COEFF         (((MCC_RM_MAXIMUM_SPEED - MCC_RM_MINIMUM_SPEED)) / MCC_RM_ACCEL_MAX_SLOPE)
#define MCC_RM_DECEL_SLOPE_COEFF         (((MCC_RM_MAXIMUM_SPEED - MCC_RM_MINIMUM_SPEED)) / MCC_RM_DECEL_MAX_SLOPE)



#define MCC_RM_VBAT_VALUE0               2400
#define MCC_RM_VBAT_COEFF0               1.0

#define MCC_RM_VBAT_VALUE1               2600
#define MCC_RM_VBAT_COEFF1               0.95

#define MCC_RM_VBAT_VALUE2               2700
#define MCC_RM_VBAT_COEFF2               0.90

#define MCC_RM_VBAT_VALUE3               2800
#define MCC_RM_VBAT_COEFF3               0.88






//---------------------------------------------------------------------------------------------------
// MCC ERREUR 
//---------------------------------------------------------------------------------------------------
#define ERROR_MCC_RM_MOTORH_TABLE            PWM_TABLE_DIRECT_STRONG    
#define ERROR_MCC_RM_MOTORH_SPEED            5
#define ERROR_MCC_RM_MOTORH_SLOPE            SLOPE100
#define ERROR_MCC_RM_MOTORL_TABLE            PWM_TABLE_OFF 
#define ERROR_MCC_RM_MOTORL_SPEED            0
#define ERROR_MCC_RM_MOTORL_SLOPE            SLOPE100
#define ERROR_MCC_RM_BRAKE_OVERRIDE          FALSE


//---------------------------------------------------------------------------------------------------
// MCC MODE MANUEL 
//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
// ENRH
//---------------------------------------------------------------------------------------------------
#define MANUAL_MCC_RM_ENRH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_MCC_RM_ENRH_0_MOTORH_SPEED       0
#define MANUAL_MCC_RM_ENRH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_ENRH_0_MOTORL_SPEED       0
#define MANUAL_MCC_RM_ENRH_0_MOTORL_SLOPE       SLOPE100


#define MANUAL_MCC_RM_ENRH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRH_1_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRH_1_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRH_1_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRH_1_MOTORL_SPEED       2
#define MANUAL_MCC_RM_ENRH_1_MOTORL_SLOPE       SLOPE75


#define MANUAL_MCC_RM_ENRH_2_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRH_2_MOTORH_SPEED       55
#define MANUAL_MCC_RM_ENRH_2_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRH_2_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_ENRH_2_MOTORL_SPEED       0
#define MANUAL_MCC_RM_ENRH_2_MOTORL_SLOPE       SLOPE75

#define MANUAL_MCC_RM_ENRH_3_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRH_3_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRH_3_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRH_3_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRH_3_MOTORL_SPEED       2
#define MANUAL_MCC_RM_ENRH_3_MOTORL_SLOPE       SLOPE75

#define MANUAL_MCC_RM_ENRH_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRH_4_MOTORH_SPEED       10
#define MANUAL_MCC_RM_ENRH_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRH_4_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRH_4_MOTORL_SPEED       10
#define MANUAL_MCC_RM_ENRH_4_MOTORL_SLOPE       SLOPE100


#define MANUAL_MCC_RM_ENRH_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRH_5_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRH_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRH_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_ENRH_5_MOTORL_SPEED       0
#define MANUAL_MCC_RM_ENRH_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// ENRL
//---------------------------------------------------------------------------------------------------
#define MANUAL_MCC_RM_ENRL_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_MCC_RM_ENRL_0_MOTORH_SPEED       0
#define MANUAL_MCC_RM_ENRL_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRL_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_ENRL_0_MOTORL_SPEED       0
#define MANUAL_MCC_RM_ENRL_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_ENRL_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRL_1_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRL_1_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRL_1_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRL_1_MOTORL_SPEED       2
#define MANUAL_MCC_RM_ENRL_1_MOTORL_SLOPE       SLOPE75

#define MANUAL_MCC_RM_ENRL_2_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_MCC_RM_ENRL_2_MOTORH_SPEED       0
#define MANUAL_MCC_RM_ENRL_2_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRL_2_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRL_2_MOTORL_SPEED       50
#define MANUAL_MCC_RM_ENRL_2_MOTORL_SLOPE       SLOPE75

#define MANUAL_MCC_RM_ENRL_3_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRL_3_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRL_3_MOTORH_SLOPE       SLOPE75
#define MANUAL_MCC_RM_ENRL_3_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRL_3_MOTORL_SPEED       2
#define MANUAL_MCC_RM_ENRL_3_MOTORL_SLOPE       SLOPE75

#define MANUAL_MCC_RM_ENRL_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRL_4_MOTORH_SPEED       10
#define MANUAL_MCC_RM_ENRL_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRL_4_MOTORL_TABLE       PWM_TABLE_DIRECT_STRONG 
#define MANUAL_MCC_RM_ENRL_4_MOTORL_SPEED       10
#define MANUAL_MCC_RM_ENRL_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_ENRL_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_ENRL_5_MOTORH_SPEED       5
#define MANUAL_MCC_RM_ENRL_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_ENRL_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_ENRL_5_MOTORL_SPEED       0
#define MANUAL_MCC_RM_ENRL_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// DERH
//---------------------------------------------------------------------------------------------------
#define MANUAL_MCC_RM_DERH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_MCC_RM_DERH_0_MOTORH_SPEED       0
#define MANUAL_MCC_RM_DERH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_DERH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_MCC_RM_DERH_0_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_DERH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_MCC_RM_DERH_1_MOTORH_SPEED       5
#define MANUAL_MCC_RM_DERH_1_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_DERH_1_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_1_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_1_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_DERH_2_MOTORH_TABLE       PWM_TABLE_INVERSE_STRONG    
#define MANUAL_MCC_RM_DERH_2_MOTORH_SPEED       30
#define MANUAL_MCC_RM_DERH_2_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_DERH_2_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_2_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_2_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_DERH_3_MOTORH_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_3_MOTORH_SPEED       0
#define MANUAL_MCC_RM_DERH_3_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_DERH_3_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_3_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_3_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_DERH_4_MOTORH_TABLE       PWM_TABLE_BRAKE    
#define MANUAL_MCC_RM_DERH_4_MOTORH_SPEED       0
#define MANUAL_MCC_RM_DERH_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_MCC_RM_DERH_4_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_4_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_MCC_RM_DERH_5_MOTORH_TABLE       PWM_TABLE_BRAKE    
#define MANUAL_MCC_RM_DERH_5_MOTORH_SPEED       0
#define MANUAL_MCC_RM_DERH_5_MOTORH_SLOPE       0
#define MANUAL_MCC_RM_DERH_5_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_MCC_RM_DERH_5_MOTORL_SPEED       0
#define MANUAL_MCC_RM_DERH_5_MOTORL_SLOPE       0





//---------------------------------------------------------------------------------------------------
// MCC MODE INIT
//---------------------------------------------------------------------------------------------------
#define INIT_MCC_RM_CELL_TIMEOUT_TIME             5000
#define INIT_MCC_RM_CELL_INHIB_TIME_PASTILLE      500      
#define INIT_MCC_RM_CELL_INHIB_TIME_BM            500
#define INIT_MCC_RM_CELL_DECR_SPEED               5
#define INIT_MCC_RM_CELL_DECR_SLOPE               SLOPE100

#define INIT_MCC_RM_START_CELL_MOTORH_DIR         PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_START_CELL_MOTORH_SPEED       35
#define INIT_MCC_RM_START_CELL_MOTORH_SLOPE       SLOPE50
#define INIT_MCC_RM_START_CELL_MOTORH_ADJUST_VBAT TRUE
#define INIT_MCC_RM_START_CELL_MOTORL_DIR         PWM_TABLE_OFF
#define INIT_MCC_RM_START_CELL_MOTORL_SPEED       0
#define INIT_MCC_RM_START_CELL_MOTORL_SLOPE       0
#define INIT_MCC_RM_START_CELL_MOTORL_ADJUST_VBAT TRUE

#define INIT_MCC_RM_1_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_1_MOTORH_SPEED                16
#define INIT_MCC_RM_1_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_1_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_1_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_1_MOTORL_SPEED                16
#define INIT_MCC_RM_1_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_1_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_2_MOTORH_SPEED                16
#define INIT_MCC_RM_2_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_2_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_2_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_2_MOTORL_SPEED                16
#define INIT_MCC_RM_2_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_2_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_3_MOTORH_SPEED                70
#define INIT_MCC_RM_3_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_3_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_3_MOTORL_DIR                  PWM_TABLE_OFF 
#define INIT_MCC_RM_3_MOTORL_SPEED                0
#define INIT_MCC_RM_3_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_3_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_4_MOTORH_SPEED                5
#define INIT_MCC_RM_4_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_4_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_4_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_4_MOTORL_SPEED                5
#define INIT_MCC_RM_4_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_4_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_5_MOTORH_SPEED                5
#define INIT_MCC_RM_5_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_5_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_5_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_5_MOTORL_SPEED                5
#define INIT_MCC_RM_5_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_5_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_6_MOTORH_DIR                  PWM_TABLE_OFF    
#define INIT_MCC_RM_6_MOTORH_SPEED                0
#define INIT_MCC_RM_6_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_6_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_6_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_6_MOTORL_SPEED                50
#define INIT_MCC_RM_6_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_6_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_7_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_7_MOTORH_SPEED                5
#define INIT_MCC_RM_7_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_7_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_7_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_7_MOTORL_SPEED                5
#define INIT_MCC_RM_7_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_7_MOTORL_ADJUST_VBAT          TRUE

#define INIT_MCC_RM_8_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_8_MOTORH_SPEED                5
#define INIT_MCC_RM_8_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_8_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_8_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_8_MOTORL_SPEED                5
#define INIT_MCC_RM_8_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_8_MOTORL_ADJUST_VBAT          TRUE
//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur haut
#define INIT_MCC_RM_9_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_9_MOTORH_SPEED                60
#define INIT_MCC_RM_9_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_9_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_9_MOTORL_DIR                  PWM_TABLE_OFF 
#define INIT_MCC_RM_9_MOTORL_SPEED                0
#define INIT_MCC_RM_9_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_9_MOTORL_ADJUST_VBAT          TRUE

// Pleine vitesse
#define INIT_MCC_RM_FULL_SPEED_TIME                2300

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_MCC_RM_10_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_10_MOTORH_SPEED                35
#define INIT_MCC_RM_10_MOTORH_SLOPE                SLOPE100
#define INIT_MCC_RM_10_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_10_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_MCC_RM_10_MOTORL_SPEED                20
#define INIT_MCC_RM_10_MOTORL_SLOPE                SLOPE100
#define INIT_MCC_RM_10_MOTORL_ADJUST_VBAT          TRUE
// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_MCC_RM_11_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_11_MOTORH_SPEED                35
#define INIT_MCC_RM_11_MOTORH_SLOPE                0
#define INIT_MCC_RM_11_MOTORH_ADJUST_VBAT          TRUE
#define INIT_MCC_RM_11_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_MCC_RM_11_MOTORL_SPEED                20
#define INIT_MCC_RM_11_MOTORL_SLOPE                0
#define INIT_MCC_RM_11_MOTORL_ADJUST_VBAT          TRUE
// Rampe arret moteur haut sur cellule
#define INIT_MCC_RM_12_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_MCC_RM_12_MOTORH_SPEED                12
#define INIT_MCC_RM_12_MOTORH_SLOPE                SLOPE50
#define INIT_MCC_RM_12_MOTORH_ADJUST_VBAT          FALSE
#define INIT_MCC_RM_12_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define INIT_MCC_RM_12_MOTORL_SPEED                8
#define INIT_MCC_RM_12_MOTORL_SLOPE                SLOPE50
#define INIT_MCC_RM_12_MOTORL_ADJUST_VBAT          FALSE
#define INIT_MCC_RM_12_BRAKE_OVERRIDE              TRUE


//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// ALCOM MODE PREAUTO ET AUTO
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define AUTO_MCC_RM_ENRH_FULL_SPEED_TIME          1000
#define AUTO_MCC_RM_ENRL_FULL_SPEED_TIME           900
        
#define AUTO_MCC_RM_CELL_TIMEOUT_TIME             4000
#define AUTO_MCC_RM_CELL_INHIB_TIME_PASTILLE      1000
#define AUTO_MCC_RM_CELL_INHIB_TIME_BM             200


#define AUTO_MCC_RM_ENRH_FULL_SPEED               90
#define AUTO_MCC_RM_ENRH_DOCK_SPEED               35
#define AUTO_MCC_RM_ENRL_FULL_SPEED               88
#define AUTO_MCC_RM_ENRL_DOCK_SPEED               33




// MAINTIEN 
#define AUTO_MCC_RM_1_MOTORH_DIR                       PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_1_MOTORH_SPEED                     12
#define AUTO_MCC_RM_1_MOTORH_SLOPE                     100
#define AUTO_MCC_RM_1_MOTORH_ADJUST_VBAT               FALSE
#define AUTO_MCC_RM_1_MOTORL_DIR                       PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_1_MOTORL_SPEED                     8
#define AUTO_MCC_RM_1_MOTORL_SLOPE                     100
#define AUTO_MCC_RM_1_MOTORL_ADJUST_VBAT               FALSE

//ENRH 
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MCC_RM_ENRH_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRH_2_MOTORH_SPEED                AUTO_MCC_RM_ENRH_FULL_SPEED
#define AUTO_MCC_RM_ENRH_2_MOTORH_SLOPE                100
#define AUTO_MCC_RM_ENRH_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRH_2_MOTORL_DIR                  PWM_TABLE_OFF
#define AUTO_MCC_RM_ENRH_2_MOTORL_SPEED                0
#define AUTO_MCC_RM_ENRH_2_MOTORL_SLOPE                0
#define AUTO_MCC_RM_ENRH_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MCC_RM_ENRH_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRH_3_MOTORH_SPEED                AUTO_MCC_RM_ENRH_DOCK_SPEED
#define AUTO_MCC_RM_ENRH_3_MOTORH_SLOPE                100
#define AUTO_MCC_RM_ENRH_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRH_3_MOTORL_DIR                  PWM_TABLE_OFF 
#define AUTO_MCC_RM_ENRH_3_MOTORL_SPEED                0
#define AUTO_MCC_RM_ENRH_3_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRH_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MCC_RM_ENRH_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRH_4_MOTORH_SPEED                AUTO_MCC_RM_ENRH_DOCK_SPEED
#define AUTO_MCC_RM_ENRH_4_MOTORH_SLOPE                0
#define AUTO_MCC_RM_ENRH_4_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRH_4_MOTORL_DIR                  PWM_TABLE_OFF 
#define AUTO_MCC_RM_ENRH_4_MOTORL_SPEED                0
#define AUTO_MCC_RM_ENRH_4_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRH_4_MOTORL_ADJUST_VBAT          TRUE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MCC_RM_ENRH_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRH_5_MOTORH_SPEED                (AUTO_MCC_RM_ENRH_DOCK_SPEED/2)
#define AUTO_MCC_RM_ENRH_5_MOTORH_SLOPE                18
#define AUTO_MCC_RM_ENRH_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRH_5_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRH_5_MOTORL_SPEED                (AUTO_MCC_RM_ENRH_DOCK_SPEED/2)
#define AUTO_MCC_RM_ENRH_5_MOTORL_SLOPE                18
#define AUTO_MCC_RM_ENRH_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRH_5_BRAKE_OVERRIDE              TRUE



// ARRET SUR PASTILLE - PHASE2
#define AUTO_MCC_RM_ENRH_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRH_6_MOTORH_SPEED                12
#define AUTO_MCC_RM_ENRH_6_MOTORH_SLOPE                100
#define AUTO_MCC_RM_ENRH_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRH_6_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRH_6_MOTORL_SPEED                8
#define AUTO_MCC_RM_ENRH_6_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRH_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRH_6_BRAKE_OVERRIDE              TRUE

//ENRL
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MCC_RM_ENRL_2_MOTORH_DIR                  PWM_TABLE_OFF    
#define AUTO_MCC_RM_ENRL_2_MOTORH_SPEED                0
#define AUTO_MCC_RM_ENRL_2_MOTORH_SLOPE                0
#define AUTO_MCC_RM_ENRL_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRL_2_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRL_2_MOTORL_SPEED                AUTO_MCC_RM_ENRL_FULL_SPEED
#define AUTO_MCC_RM_ENRL_2_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRL_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MCC_RM_ENRL_3_MOTORH_DIR                  PWM_TABLE_OFF    
#define AUTO_MCC_RM_ENRL_3_MOTORH_SPEED                0
#define AUTO_MCC_RM_ENRL_3_MOTORH_SLOPE                0
#define AUTO_MCC_RM_ENRL_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRL_3_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRL_3_MOTORL_SPEED                AUTO_MCC_RM_ENRL_DOCK_SPEED
#define AUTO_MCC_RM_ENRL_3_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRL_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MCC_RM_ENRL_4_MOTORH_DIR                  PWM_TABLE_OFF    
#define AUTO_MCC_RM_ENRL_4_MOTORH_SPEED                0
#define AUTO_MCC_RM_ENRL_4_MOTORH_SLOPE                0
#define AUTO_MCC_RM_ENRL_4_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_MCC_RM_ENRL_4_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRL_4_MOTORL_SPEED                AUTO_MCC_RM_ENRL_DOCK_SPEED
#define AUTO_MCC_RM_ENRL_4_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRL_4_MOTORL_ADJUST_VBAT          TRUE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MCC_RM_ENRL_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRL_5_MOTORH_SPEED                (AUTO_MCC_RM_ENRL_DOCK_SPEED/2)
#define AUTO_MCC_RM_ENRL_5_MOTORH_SLOPE                25
#define AUTO_MCC_RM_ENRL_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRL_5_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRL_5_MOTORL_SPEED                (AUTO_MCC_RM_ENRL_DOCK_SPEED/2)
#define AUTO_MCC_RM_ENRL_5_MOTORL_SLOPE                25
#define AUTO_MCC_RM_ENRL_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRL_5_BRAKE_OVERRIDE              TRUE


// ARRET SUR PASTILLE - PHASE2
#define AUTO_MCC_RM_ENRL_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_MCC_RM_ENRL_6_MOTORH_SPEED                12
#define AUTO_MCC_RM_ENRL_6_MOTORH_SLOPE                100
#define AUTO_MCC_RM_ENRL_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRL_6_MOTORL_DIR                  PWM_TABLE_DIRECT_STRONG 
#define AUTO_MCC_RM_ENRL_6_MOTORL_SPEED                8
#define AUTO_MCC_RM_ENRL_6_MOTORL_SLOPE                100
#define AUTO_MCC_RM_ENRL_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_MCC_RM_ENRL_6_BRAKE_OVERRIDE              TRUE



#endif	/* MOTOR_MCC_RM_H */

