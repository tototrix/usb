#ifndef MOTOR_PRISMA_H
#define	MOTOR_PRISMA_H


//extern struct struct_motor motor_prisma;

#define PRISMA_MINIMUM_SPEED                    0.0
#define PRISMA_MAXIMUM_SPEED                   95.0

#define PRISMA_ACCEL_MAX_SLOPE_TIME           800//800
#define PRISMA_DECEL_MAX_SLOPE_TIME          -1500//-1500

#define PRISMA_ACCEL_SLOPE_COEFF              (((PRISMA_MAXIMUM_SPEED - PRISMA_MINIMUM_SPEED)) / PRISMA_ACCEL_MAX_SLOPE_TIME)
#define PRISMA_DECEL_SLOPE_COEFF              (((PRISMA_MAXIMUM_SPEED - PRISMA_MINIMUM_SPEED)) / PRISMA_DECEL_MAX_SLOPE_TIME)

#define PRISMA_VBAT_VALUE0               2480
#define PRISMA_VBAT_COEFF0               1.0

#define PRISMA_VBAT_VALUE1               2600
#define PRISMA_VBAT_COEFF1               0.95

#define PRISMA_VBAT_VALUE2               2700
#define PRISMA_VBAT_COEFF2               0.92

#define PRISMA_VBAT_VALUE3               2800
#define PRISMA_VBAT_COEFF3               0.9

//---------------------------------------------------------------------------------------------------
// PRISMA ERREUR 
//---------------------------------------------------------------------------------------------------
#define ERROR_PRISMA_MOTORH_DIR            PWM_TABLE_DIRECT_STRONG    
#define ERROR_PRISMA_MOTORH_SPEED          7
#define ERROR_PRISMA_MOTORH_SLOPE          SLOPE100
#define ERROR_PRISMA_MOTORL_DIR            PWM_TABLE_OFF 
#define ERROR_PRISMA_MOTORL_SPEED          0
#define ERROR_PRISMA_MOTORL_SLOPE          SLOPE100


//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// PRISMA MODE MANUEL
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

//---------------------------------------------------------------------------------------------------
// ENRH
//---------------------------------------------------------------------------------------------------
#define MANUAL_PRISMA_ENRH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_PRISMA_ENRH_0_MOTORH_SPEED       0
#define MANUAL_PRISMA_ENRH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_ENRH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_PRISMA_ENRH_0_MOTORL_SPEED       0
#define MANUAL_PRISMA_ENRH_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_ENRH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRH_1_MOTORH_SPEED       7
#define MANUAL_PRISMA_ENRH_1_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRH_1_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_ENRH_1_MOTORL_SPEED       55
#define MANUAL_PRISMA_ENRH_1_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRH_2_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRH_2_MOTORH_SPEED       35
#define MANUAL_PRISMA_ENRH_2_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRH_2_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_ENRH_2_MOTORL_SPEED       55
#define MANUAL_PRISMA_ENRH_2_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRH_3_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRH_3_MOTORH_SPEED       12
#define MANUAL_PRISMA_ENRH_3_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRH_3_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_ENRH_3_MOTORL_SPEED       55
#define MANUAL_PRISMA_ENRH_3_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRH_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRH_4_MOTORH_SPEED       12
#define MANUAL_PRISMA_ENRH_4_MOTORH_SLOPE       SLOPE25
#define MANUAL_PRISMA_ENRH_4_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_PRISMA_ENRH_4_MOTORL_SPEED       12
#define MANUAL_PRISMA_ENRH_4_MOTORL_SLOPE       SLOPE25

#define MANUAL_PRISMA_ENRH_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRH_5_MOTORH_SPEED       5
#define MANUAL_PRISMA_ENRH_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_ENRH_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_PRISMA_ENRH_5_MOTORL_SPEED       0
#define MANUAL_PRISMA_ENRH_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// ENRL
//---------------------------------------------------------------------------------------------------
#define MANUAL_PRISMA_ENRL_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_PRISMA_ENRL_0_MOTORH_SPEED       0
#define MANUAL_PRISMA_ENRL_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_ENRL_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_PRISMA_ENRL_0_MOTORL_SPEED       0
#define MANUAL_PRISMA_ENRL_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_ENRL_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRL_1_MOTORH_SPEED       5
#define MANUAL_PRISMA_ENRL_1_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRL_1_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG
#define MANUAL_PRISMA_ENRL_1_MOTORL_SPEED       5
#define MANUAL_PRISMA_ENRL_1_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRL_2_MOTORH_TABLE       PWM_TABLE_BRAKE    
#define MANUAL_PRISMA_ENRL_2_MOTORH_SPEED       55
#define MANUAL_PRISMA_ENRL_2_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRL_2_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_PRISMA_ENRL_2_MOTORL_SPEED       35
#define MANUAL_PRISMA_ENRL_2_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRL_3_MOTORH_TABLE       PWM_TABLE_BRAKE  
#define MANUAL_PRISMA_ENRL_3_MOTORH_SPEED       55
#define MANUAL_PRISMA_ENRL_3_MOTORH_SLOPE       SLOPE75
#define MANUAL_PRISMA_ENRL_3_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_PRISMA_ENRL_3_MOTORL_SPEED       12
#define MANUAL_PRISMA_ENRL_3_MOTORL_SLOPE       SLOPE75

#define MANUAL_PRISMA_ENRL_4_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRL_4_MOTORH_SPEED       12
#define MANUAL_PRISMA_ENRL_4_MOTORH_SLOPE       SLOPE25
#define MANUAL_PRISMA_ENRL_4_MOTORL_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_PRISMA_ENRL_4_MOTORL_SPEED       12
#define MANUAL_PRISMA_ENRL_4_MOTORL_SLOPE       SLOPE25

#define MANUAL_PRISMA_ENRL_5_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_ENRL_5_MOTORH_SPEED       5
#define MANUAL_PRISMA_ENRL_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_ENRL_5_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_PRISMA_ENRL_5_MOTORL_SPEED       0
#define MANUAL_PRISMA_ENRL_5_MOTORL_SLOPE       SLOPE100

//---------------------------------------------------------------------------------------------------
// DERH
//---------------------------------------------------------------------------------------------------
#define MANUAL_PRISMA_DERH_0_MOTORH_TABLE       PWM_TABLE_OFF    
#define MANUAL_PRISMA_DERH_0_MOTORH_SPEED       0
#define MANUAL_PRISMA_DERH_0_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_0_MOTORL_TABLE       PWM_TABLE_OFF 
#define MANUAL_PRISMA_DERH_0_MOTORL_SPEED       0
#define MANUAL_PRISMA_DERH_0_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_DERH_1_MOTORH_TABLE       PWM_TABLE_DIRECT_STRONG    
#define MANUAL_PRISMA_DERH_1_MOTORH_SPEED       5
#define MANUAL_PRISMA_DERH_1_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_1_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_DERH_1_MOTORL_SPEED       55
#define MANUAL_PRISMA_DERH_1_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_DERH_2_MOTORH_TABLE       PWM_TABLE_INVERSE_STRONG    
#define MANUAL_PRISMA_DERH_2_MOTORH_SPEED       30
#define MANUAL_PRISMA_DERH_2_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_2_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_DERH_2_MOTORL_SPEED       55
#define MANUAL_PRISMA_DERH_2_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_DERH_3_MOTORH_TABLE       PWM_TABLE_INVERSE_STRONG 
#define MANUAL_PRISMA_DERH_3_MOTORH_SPEED       0
#define MANUAL_PRISMA_DERH_3_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_3_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_DERH_3_MOTORL_SPEED       100
#define MANUAL_PRISMA_DERH_3_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_DERH_4_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK    
#define MANUAL_PRISMA_DERH_4_MOTORH_SPEED       30
#define MANUAL_PRISMA_DERH_4_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_4_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_DERH_4_MOTORL_SPEED       100
#define MANUAL_PRISMA_DERH_4_MOTORL_SLOPE       SLOPE100

#define MANUAL_PRISMA_DERH_5_MOTORH_TABLE       PWM_TABLE_DIRECT_WEAK    
#define MANUAL_PRISMA_DERH_5_MOTORH_SPEED       30
#define MANUAL_PRISMA_DERH_5_MOTORH_SLOPE       SLOPE100
#define MANUAL_PRISMA_DERH_5_MOTORL_TABLE       PWM_TABLE_BRAKE 
#define MANUAL_PRISMA_DERH_5_MOTORL_SPEED       100
#define MANUAL_PRISMA_DERH_5_MOTORL_SLOPE       SLOPE100



//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// PRISMA MODE INIT
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

#define INIT_PRISMA_CELL_TIMEOUT_TIME             6000//4600
#define INIT_PRISMA_CELL_INHIB_TIME_PASTILLE      500
#define INIT_PRISMA_CELL_INHIB_TIME_BM            30
#define INIT_PRISMA_CELL_DECR_SPEED               5
#define INIT_PRISMA_CELL_DECR_SLOPE               SLOPE100
#define INIT_PRISMA_FULL_SPEED_TIME               1500

#define INIT_PRISMA_ENRH_FULL_SPEED               30
#define INIT_PRISMA_ENRL_FULL_SPEED               30

//---------------------------------------------------------------------------------------------------
// INIT - DEMARRAGE SUR CELLULE
//---------------------------------------------------------------------------------------------------

#define INIT_PRISMA_START_CELL_MOTORH_DIR         PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_START_CELL_MOTORH_SPEED       30
#define INIT_PRISMA_START_CELL_MOTORH_SLOPE       SLOPE50
#define INIT_PRISMA_START_CELL_MOTORH_ADJUST_VBAT TRUE
#define INIT_PRISMA_START_CELL_MOTORL_DIR         PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_START_CELL_MOTORL_SPEED       0
#define INIT_PRISMA_START_CELL_MOTORL_SLOPE       0
#define INIT_PRISMA_START_CELL_MOTORL_ADJUST_VBAT TRUE

//---------------------------------------------------------------------------------------------------
// INIT - RECHERCHE BANDE MERE BASSE
//---------------------------------------------------------------------------------------------------

// Petite rampe pour atteindre la tension d'affiche
#define INIT_PRISMA_1_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_1_MOTORH_SPEED                13
#define INIT_PRISMA_1_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_1_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_1_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_1_MOTORL_SPEED                15
#define INIT_PRISMA_1_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_1_MOTORL_ADJUST_VBAT          TRUE

// Tension d'affiche
#define INIT_PRISMA_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_2_MOTORH_SPEED                13
#define INIT_PRISMA_2_MOTORH_SLOPE                10000
#define INIT_PRISMA_2_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_2_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_2_MOTORL_SPEED                15
#define INIT_PRISMA_2_MOTORL_SLOPE                10000
#define INIT_PRISMA_2_MOTORL_ADJUST_VBAT          TRUE

// Rampe acceleration moteur haut
#define INIT_PRISMA_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_3_MOTORH_SPEED                INIT_PRISMA_ENRH_FULL_SPEED
#define INIT_PRISMA_3_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_3_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_3_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_PRISMA_3_MOTORL_SPEED                55
#define INIT_PRISMA_3_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_3_MOTORL_ADJUST_VBAT          TRUE

// Rampe deceleration moteur haut
#define INIT_PRISMA_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_4_MOTORH_SPEED                7
#define INIT_PRISMA_4_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_4_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_4_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_4_MOTORL_SPEED                10
#define INIT_PRISMA_4_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_4_MOTORL_ADJUST_VBAT          TRUE

// Arret
#define INIT_PRISMA_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_5_MOTORH_SPEED                9
#define INIT_PRISMA_5_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_5_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_5_MOTORL_SPEED                9
#define INIT_PRISMA_5_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_5_MOTORL_ADJUST_VBAT          TRUE
//---------------------------------------------------------------------------------------------------
// INIT - RECHERCHE BANDE MERE HAUTE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur bas
#define INIT_PRISMA_6_MOTORH_DIR                  PWM_TABLE_BRAKE    
#define INIT_PRISMA_6_MOTORH_SPEED                55
#define INIT_PRISMA_6_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_6_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_6_MOTORL_SPEED                INIT_PRISMA_ENRL_FULL_SPEED
#define INIT_PRISMA_6_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_6_MOTORL_ADJUST_VBAT          TRUE

// Rampe deceleration moteur bas
#define INIT_PRISMA_7_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_7_MOTORH_SPEED                10
#define INIT_PRISMA_7_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_7_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_7_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_7_MOTORL_SPEED                7
#define INIT_PRISMA_7_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_7_MOTORL_ADJUST_VBAT          TRUE

// Arret
#define INIT_PRISMA_8_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_8_MOTORH_SPEED                9
#define INIT_PRISMA_8_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_8_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_8_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define INIT_PRISMA_8_MOTORL_SPEED                9
#define INIT_PRISMA_8_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_8_MOTORL_ADJUST_VBAT          TRUE

//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur haut
#define INIT_PRISMA_9_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_9_MOTORH_SPEED                40
#define INIT_PRISMA_9_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_9_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_9_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_PRISMA_9_MOTORL_SPEED                30
#define INIT_PRISMA_9_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_9_MOTORL_ADJUST_VBAT          TRUE

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_PRISMA_10_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_10_MOTORH_SPEED                20
#define INIT_PRISMA_10_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_10_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_10_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_PRISMA_10_MOTORL_SPEED                10
#define INIT_PRISMA_10_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_10_MOTORL_ADJUST_VBAT          TRUE

// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_PRISMA_11_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_11_MOTORH_SPEED                20
#define INIT_PRISMA_11_MOTORH_SLOPE                0
#define INIT_PRISMA_11_MOTORH_ADJUST_VBAT          TRUE
#define INIT_PRISMA_11_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define INIT_PRISMA_11_MOTORL_SPEED                10
#define INIT_PRISMA_11_MOTORL_SLOPE                0
#define INIT_PRISMA_11_MOTORL_ADJUST_VBAT          TRUE

// Rampe arret moteur haut sur cellule
#define INIT_PRISMA_12_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define INIT_PRISMA_12_MOTORH_SPEED                11
#define INIT_PRISMA_12_MOTORH_SLOPE                SLOPE100
#define INIT_PRISMA_12_MOTORH_ADJUST_VBAT          FALSE
#define INIT_PRISMA_12_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG
#define INIT_PRISMA_12_MOTORL_SPEED                11
#define INIT_PRISMA_12_MOTORL_SLOPE                SLOPE100
#define INIT_PRISMA_12_MOTORL_ADJUST_VBAT          FALSE
#define INIT_PRISMA_12_BRAKE_OVERRIDE              TRUE


//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// PRISMA MODE PREAUTO ET AUTO
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define AUTO_PRISMA_ENRH_FULL_SPEED_TIME           300
#define AUTO_PRISMA_ENRL_FULL_SPEED_TIME           600

#define AUTO_PRISMA_CELL_TIMEOUT_TIME             5000
#define AUTO_PRISMA_CELL_INHIB_TIME_PASTILLE      500
#define AUTO_PRISMA_CELL_INHIB_TIME_BM            50


#define AUTO_PRISMA_ENRH_FULL_SPEED               58
#define AUTO_PRISMA_ENRH_DOCK_SPEED               25
#define AUTO_PRISMA_ENRL_FULL_SPEED               53
#define AUTO_PRISMA_ENRL_DOCK_SPEED               22

// MAINTIEN 
#define AUTO_PRISMA_1_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_1_MOTORH_SPEED                11
#define AUTO_PRISMA_1_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_1_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_1_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_1_MOTORL_SPEED                11
#define AUTO_PRISMA_1_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_1_MOTORL_ADJUST_VBAT          FALSE

//ENRH

// ACCELERATION VERS GRANDE VITESSE
#define AUTO_PRISMA_ENRH_2_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRH_2_MOTORH_SPEED                AUTO_PRISMA_ENRH_FULL_SPEED
#define AUTO_PRISMA_ENRH_2_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRH_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRH_2_MOTORL_DIR                  PWM_TABLE_BRAKE 
#define AUTO_PRISMA_ENRH_2_MOTORL_SPEED                100
#define AUTO_PRISMA_ENRH_2_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRH_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_PRISMA_ENRH_3_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRH_3_MOTORH_SPEED                AUTO_PRISMA_ENRH_DOCK_SPEED
#define AUTO_PRISMA_ENRH_3_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRH_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRH_3_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define AUTO_PRISMA_ENRH_3_MOTORL_SPEED                25
#define AUTO_PRISMA_ENRH_3_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRH_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_PRISMA_ENRH_4_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRH_4_MOTORH_SPEED                AUTO_PRISMA_ENRH_DOCK_SPEED
#define AUTO_PRISMA_ENRH_4_MOTORH_SLOPE                0
#define AUTO_PRISMA_ENRH_4_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRH_4_MOTORL_DIR                  PWM_TABLE_INVERSE_WEAK 
#define AUTO_PRISMA_ENRH_4_MOTORL_SPEED                10
#define AUTO_PRISMA_ENRH_4_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRH_4_MOTORL_ADJUST_VBAT          TRUE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_PRISMA_ENRH_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRH_5_MOTORH_SPEED                (AUTO_PRISMA_ENRH_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRH_5_MOTORH_SLOPE                0
#define AUTO_PRISMA_ENRH_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRH_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRH_5_MOTORL_SPEED                (AUTO_PRISMA_ENRH_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRH_5_MOTORL_SLOPE                0
#define AUTO_PRISMA_ENRH_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRH_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_PRISMA_ENRH_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRH_6_MOTORH_SPEED                (AUTO_PRISMA_ENRH_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRH_6_MOTORH_SLOPE                0
#define AUTO_PRISMA_ENRH_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRH_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRH_6_MOTORL_SPEED                (AUTO_PRISMA_ENRH_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRH_6_MOTORL_SLOPE                0
#define AUTO_PRISMA_ENRH_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRH_6_BRAKE_OVERRIDE              TRUE


//ENRL

// ACCELERATION VERS GRANDE VITESSE
#define AUTO_PRISMA_ENRL_2_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_PRISMA_ENRL_2_MOTORH_SPEED                25
#define AUTO_PRISMA_ENRL_2_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRL_2_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRL_2_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRL_2_MOTORL_SPEED                AUTO_PRISMA_ENRL_FULL_SPEED
#define AUTO_PRISMA_ENRL_2_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRL_2_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_PRISMA_ENRL_3_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_PRISMA_ENRL_3_MOTORH_SPEED                40
#define AUTO_PRISMA_ENRL_3_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRL_3_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRL_3_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRL_3_MOTORL_SPEED                AUTO_PRISMA_ENRL_DOCK_SPEED
#define AUTO_PRISMA_ENRL_3_MOTORL_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRL_3_MOTORL_ADJUST_VBAT          TRUE

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_PRISMA_ENRL_4_MOTORH_DIR                  PWM_TABLE_DIRECT_WEAK    
#define AUTO_PRISMA_ENRL_4_MOTORH_SPEED                35
#define AUTO_PRISMA_ENRL_4_MOTORH_SLOPE                SLOPE100
#define AUTO_PRISMA_ENRL_4_MOTORH_ADJUST_VBAT          TRUE
#define AUTO_PRISMA_ENRL_4_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRL_4_MOTORL_SPEED                AUTO_PRISMA_ENRL_DOCK_SPEED
#define AUTO_PRISMA_ENRL_4_MOTORL_SLOPE                0
#define AUTO_PRISMA_ENRL_4_MOTORL_ADJUST_VBAT          TRUE

// ARRET SUR PASTILLE - PHASE1
#define AUTO_PRISMA_ENRL_5_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRL_5_MOTORH_SPEED                (AUTO_PRISMA_ENRL_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRL_5_MOTORH_SLOPE                0
#define AUTO_PRISMA_ENRL_5_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRL_5_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRL_5_MOTORL_SPEED                (AUTO_PRISMA_ENRL_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRL_5_MOTORL_SLOPE                0
#define AUTO_PRISMA_ENRL_5_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRL_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_PRISMA_ENRL_6_MOTORH_DIR                  PWM_TABLE_DIRECT_STRONG    
#define AUTO_PRISMA_ENRL_6_MOTORH_SPEED                (AUTO_PRISMA_ENRL_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRL_6_MOTORH_SLOPE                0
#define AUTO_PRISMA_ENRL_6_MOTORH_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRL_6_MOTORL_DIR                  PWM_TABLE_INVERSE_STRONG 
#define AUTO_PRISMA_ENRL_6_MOTORL_SPEED                (AUTO_PRISMA_ENRL_DOCK_SPEED/2)
#define AUTO_PRISMA_ENRL_6_MOTORL_SLOPE                0
#define AUTO_PRISMA_ENRL_6_MOTORL_ADJUST_VBAT          FALSE
#define AUTO_PRISMA_ENRL_6_BRAKE_OVERRIDE              TRUE



#endif	/* MOTOR_PRISMA_H */

