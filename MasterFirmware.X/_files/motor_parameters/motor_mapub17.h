#ifndef MOTOR_MAPUB17_H
#define	MOTOR_MAPUB17_H

// struct struct_motor motor_mapub17;

#define MAPUB17_FPWM                           9000L//9000L
#define MAPUB17_PWM_PHASE_SHIFT                (2*FCY)/(MAPUB17_FPWM*2)
#define MAPUB17_SINE_WAVE_ACCURACY               64L
#define MAPUB17_MINIMUM_FREQ                     10.0 // 0.1 Hz
#define MAPUB17_MAXIMUM_FREQ                    500.0 // 50 Hz
#define MAPUB17_VOLTAGE_MAX                     220

#define MAPUB17_POINT0_FREQ                      10
#define MAPUB17_POINT0_VOLT                      18
#define MAPUB17_POINT1_FREQ                     150
#define MAPUB17_POINT1_VOLT                      80
#define MAPUB17_POINT2_FREQ                     350
#define MAPUB17_POINT2_VOLT                     162
#define MAPUB17_POINT3_FREQ                     500
#define MAPUB17_POINT3_VOLT     MAPUB17_VOLTAGE_MAX



#define MAPUB17_ACCEL_MAX_SLOPE           800
#define MAPUB17_DECEL_MAX_SLOPE          -1500

#define MAPUB17_ACCEL_SLOPE_COEFF              (((MAPUB17_MAXIMUM_FREQ - MAPUB17_MINIMUM_FREQ)) / (MAPUB17_ACCEL_MAX_SLOPE*10))
#define MAPUB17_DECEL_SLOPE_COEFF              (((MAPUB17_MAXIMUM_FREQ - MAPUB17_MINIMUM_FREQ)) / (MAPUB17_DECEL_MAX_SLOPE*10))


#define MAPUB17_DIRECTH     ASYNC_INVERSE
#define MAPUB17_INVERSEH    ASYNC_DIRECT 

#define MAPUB17_DIRECTL     ASYNC_DIRECT
#define MAPUB17_INVERSEL    ASYNC_INVERSE


#define MAPUB17_ENRH_DOCK_SPEED_ADJUST      4
#define MAPUB17_ENRL_DOCK_SPEED_ADJUST      3




//---------------------------------------------------------------------------------------------------
// MAPUB17 ERREUR 
//---------------------------------------------------------------------------------------------------
#define ERROR_MAPUB17_MOTORH_DIR         MAPUB17_DIRECTH    
#define ERROR_MAPUB17_MOTORH_SPEED       1
#define ERROR_MAPUB17_MOTORH_SLOPE       100
#define ERROR_MAPUB17_MOTORL_DIR         MAPUB17_DIRECTL 
#define ERROR_MAPUB17_MOTORL_SPEED       0
#define ERROR_MAPUB17_MOTORL_SLOPE       100

//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// MAPUB MODE MANUEL
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

//---------------------------------------------------------------------------------------------------
// ENRH
//---------------------------------------------------------------------------------------------------
#define MANUAL_MAPUB17_ENRH_0_MOTORH_DIR         MAPUB17_DIRECTH   
#define MANUAL_MAPUB17_ENRH_0_MOTORH_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_ENRH_0_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_0_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_0_MOTORL_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_ENRH_0_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRH_1_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRH_1_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRH_1_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_1_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_1_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRH_1_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRH_2_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRH_2_MOTORH_SPEED       30
#define MANUAL_MAPUB17_ENRH_2_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_2_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_2_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRH_2_MOTORL_SLOPE       100
  
#define MANUAL_MAPUB17_ENRH_3_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRH_3_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRH_3_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_3_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_3_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRH_3_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRH_4_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRH_4_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRH_4_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_4_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_4_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRH_4_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRH_5_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRH_5_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRH_5_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRH_5_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRH_5_MOTORL_SPEED       0
#define MANUAL_MAPUB17_ENRH_5_MOTORL_SLOPE       100

//---------------------------------------------------------------------------------------------------
// ENRL
//---------------------------------------------------------------------------------------------------
#define MANUAL_MAPUB17_ENRL_0_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRL_0_MOTORH_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_ENRL_0_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_0_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRL_0_MOTORL_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_ENRL_0_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRL_1_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRL_1_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRL_1_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_1_MOTORL_DIR         MAPUB17_DIRECTL
#define MANUAL_MAPUB17_ENRL_1_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRL_1_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRL_2_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRL_2_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRL_2_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_2_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRL_2_MOTORL_SPEED       30
#define MANUAL_MAPUB17_ENRL_2_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRL_3_MOTORH_DIR         MAPUB17_DIRECTL  
#define MANUAL_MAPUB17_ENRL_3_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRL_3_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_3_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRL_3_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRL_3_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRL_4_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRL_4_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRL_4_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_4_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRL_4_MOTORL_SPEED       1
#define MANUAL_MAPUB17_ENRL_4_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_ENRL_5_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_ENRL_5_MOTORH_SPEED       1
#define MANUAL_MAPUB17_ENRL_5_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_ENRL_5_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_ENRL_5_MOTORL_SPEED       0
#define MANUAL_MAPUB17_ENRL_5_MOTORL_SLOPE       100

//---------------------------------------------------------------------------------------------------
// DERH
//---------------------------------------------------------------------------------------------------
#define MANUAL_MAPUB17_DERH_0_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_DERH_0_MOTORH_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_DERH_0_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_0_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_DERH_0_MOTORL_SPEED       MAPUB17_MINIMUM_FREQ
#define MANUAL_MAPUB17_DERH_0_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_DERH_1_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_DERH_1_MOTORH_SPEED       1
#define MANUAL_MAPUB17_DERH_1_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_1_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_DERH_1_MOTORL_SPEED       1
#define MANUAL_MAPUB17_DERH_1_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_DERH_2_MOTORH_DIR         MAPUB17_INVERSEH    
#define MANUAL_MAPUB17_DERH_2_MOTORH_SPEED       30
#define MANUAL_MAPUB17_DERH_2_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_2_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_DERH_2_MOTORL_SPEED       0
#define MANUAL_MAPUB17_DERH_2_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_DERH_3_MOTORH_DIR         MAPUB17_INVERSEH 
#define MANUAL_MAPUB17_DERH_3_MOTORH_SPEED       1
#define MANUAL_MAPUB17_DERH_3_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_3_MOTORL_DIR         MAPUB17_DIRECTL   
#define MANUAL_MAPUB17_DERH_3_MOTORL_SPEED       0
#define MANUAL_MAPUB17_DERH_3_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_DERH_4_MOTORH_DIR         MAPUB17_INVERSEH    
#define MANUAL_MAPUB17_DERH_4_MOTORH_SPEED       1
#define MANUAL_MAPUB17_DERH_4_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_4_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_DERH_4_MOTORL_SPEED       0
#define MANUAL_MAPUB17_DERH_4_MOTORL_SLOPE       100

#define MANUAL_MAPUB17_DERH_5_MOTORH_DIR         MAPUB17_DIRECTH    
#define MANUAL_MAPUB17_DERH_5_MOTORH_SPEED       1
#define MANUAL_MAPUB17_DERH_5_MOTORH_SLOPE       100
#define MANUAL_MAPUB17_DERH_5_MOTORL_DIR         MAPUB17_DIRECTL 
#define MANUAL_MAPUB17_DERH_5_MOTORL_SPEED       0
#define MANUAL_MAPUB17_DERH_5_MOTORL_SLOPE       100
 
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// MAPUB MODE INIT
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define INIT_MAPUB17_CELL_TIMEOUT_TIME             5800
#define INIT_MAPUB17_CELL_INHIB_TIME_PASTILLE      500
#define INIT_MAPUB17_CELL_INHIB_TIME_BM            500
#define INIT_MAPUB17_CELL_DECR_SPEED               2
#define INIT_MAPUB17_CELL_DECR_SLOPE               50
#define INIT_MAPUB17_CELL_BETWEEN_TIME             3700



#define INIT_MAPUB17_START_CELL_MOTORH_DIR         MAPUB17_DIRECTH    
#define INIT_MAPUB17_START_CELL_MOTORH_SPEED       12
#define INIT_MAPUB17_START_CELL_MOTORH_SLOPE       50
#define INIT_MAPUB17_START_CELL_MOTORL_DIR         MAPUB17_DIRECTL 
#define INIT_MAPUB17_START_CELL_MOTORL_SPEED       1
#define INIT_MAPUB17_START_CELL_MOTORL_SLOPE       0

#define INIT_MAPUB17_1_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_1_MOTORH_SPEED                3
#define INIT_MAPUB17_1_MOTORH_SLOPE                100
#define INIT_MAPUB17_1_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_1_MOTORL_SPEED                3
#define INIT_MAPUB17_1_MOTORL_SLOPE                100

#define INIT_MAPUB17_2_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_2_MOTORH_SPEED                3
#define INIT_MAPUB17_2_MOTORH_SLOPE                10000
#define INIT_MAPUB17_2_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_2_MOTORL_SPEED                3
#define INIT_MAPUB17_2_MOTORL_SLOPE                10000

#define INIT_MAPUB17_3_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_3_MOTORH_SPEED                35
#define INIT_MAPUB17_3_MOTORH_SLOPE                100
#define INIT_MAPUB17_3_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_3_MOTORL_SPEED                1
#define INIT_MAPUB17_3_MOTORL_SLOPE                100

#define INIT_MAPUB17_4_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_4_MOTORH_SPEED                1
#define INIT_MAPUB17_4_MOTORH_SLOPE                100
#define INIT_MAPUB17_4_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_4_MOTORL_SPEED                1
#define INIT_MAPUB17_4_MOTORL_SLOPE                0

#define INIT_MAPUB17_5_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_5_MOTORH_SPEED                1
#define INIT_MAPUB17_5_MOTORH_SLOPE                100
#define INIT_MAPUB17_5_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_5_MOTORL_SPEED                1
#define INIT_MAPUB17_5_MOTORL_SLOPE                100

#define INIT_MAPUB17_6_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_6_MOTORH_SPEED                1
#define INIT_MAPUB17_6_MOTORH_SLOPE                100
#define INIT_MAPUB17_6_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_6_MOTORL_SPEED                35
#define INIT_MAPUB17_6_MOTORL_SLOPE                100

#define INIT_MAPUB17_7_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_7_MOTORH_SPEED                1
#define INIT_MAPUB17_7_MOTORH_SLOPE                100
#define INIT_MAPUB17_7_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_7_MOTORL_SPEED                1
#define INIT_MAPUB17_7_MOTORL_SLOPE                100

#define INIT_MAPUB17_8_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_8_MOTORH_SPEED                1
#define INIT_MAPUB17_8_MOTORH_SLOPE                100
#define INIT_MAPUB17_8_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_8_MOTORL_SPEED                1
#define INIT_MAPUB17_8_MOTORL_SLOPE                100

//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur haut
#define INIT_MAPUB17_9_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_9_MOTORH_SPEED                35
#define INIT_MAPUB17_9_MOTORH_SLOPE                100
#define INIT_MAPUB17_9_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_9_MOTORL_SPEED                1
#define INIT_MAPUB17_9_MOTORL_SLOPE                100

// Pleine vitesse
#define INIT_MAPUB17_FULL_SPEED_TIME                1300

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_MAPUB17_10_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_10_MOTORH_SPEED                12
#define INIT_MAPUB17_10_MOTORH_SLOPE                100
#define INIT_MAPUB17_10_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_10_MOTORL_SPEED                3
#define INIT_MAPUB17_10_MOTORL_SLOPE                100


// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_MAPUB17_11_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_11_MOTORH_SPEED                12
#define INIT_MAPUB17_11_MOTORH_SLOPE                100
#define INIT_MAPUB17_11_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_11_MOTORL_SPEED                1
#define INIT_MAPUB17_11_MOTORL_SLOPE                100

// Rampe arret moteur haut sur cellule
#define INIT_MAPUB17_12_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB17_12_MOTORH_SPEED                2
#define INIT_MAPUB17_12_MOTORH_SLOPE                100
#define INIT_MAPUB17_12_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB17_12_MOTORL_SPEED                2
#define INIT_MAPUB17_12_MOTORL_SLOPE                100
#define INIT_MAPUB17_12_BRAKE_OVERRIDE              TRUE



//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// MAPUB MODE PREAUTO ET AUTO
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define AUTO_MAPUB17_ENRH_FULL_SPEED_TIME          1000
#define AUTO_MAPUB17_ENRL_FULL_SPEED_TIME          1000

#define AUTO_MAPUB17_CELL_TIMEOUT_TIME             8000

#define AUTO_MAPUB17_CELL_INHIB_TIME_PASTILLE      1000
#define AUTO_MAPUB17_CELL_INHIB_TIME_BM            1000


#define AUTO_MAPUB17_ENRH_FULL_SPEED               42
#define AUTO_MAPUB17_ENRH_DOCK_SPEED               12
#define AUTO_MAPUB17_ENRL_FULL_SPEED               42
#define AUTO_MAPUB17_ENRL_DOCK_SPEED               10




// MAINTIEN 
#define AUTO_MAPUB17_1_MOTORH_DIR                      MAPUB17_DIRECTH    
#define AUTO_MAPUB17_1_MOTORH_SPEED                    2
#define AUTO_MAPUB17_1_MOTORH_SLOPE                    100
#define AUTO_MAPUB17_1_MOTORL_DIR                      MAPUB17_DIRECTL 
#define AUTO_MAPUB17_1_MOTORL_SPEED                    2
#define AUTO_MAPUB17_1_MOTORL_SLOPE                    100



// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MAPUB17_ENRH_2_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRH_2_MOTORH_SPEED                AUTO_MAPUB17_ENRH_FULL_SPEED
#define AUTO_MAPUB17_ENRH_2_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRH_2_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRH_2_MOTORL_SPEED                1
#define AUTO_MAPUB17_ENRH_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MAPUB17_ENRH_3_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRH_3_MOTORH_SPEED                AUTO_MAPUB17_ENRH_DOCK_SPEED
#define AUTO_MAPUB17_ENRH_3_MOTORH_SLOPE                75
#define AUTO_MAPUB17_ENRH_3_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRH_3_MOTORL_SPEED                1
#define AUTO_MAPUB17_ENRH_3_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MAPUB17_ENRH_4_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRH_4_MOTORH_SPEED                AUTO_MAPUB17_ENRH_DOCK_SPEED
#define AUTO_MAPUB17_ENRH_4_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRH_4_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRH_4_MOTORL_SPEED                1
#define AUTO_MAPUB17_ENRH_4_MOTORL_SLOPE                100

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MAPUB17_ENRH_5_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRH_5_MOTORH_SPEED                2
#define AUTO_MAPUB17_ENRH_5_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRH_5_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRH_5_MOTORL_SPEED                2
#define AUTO_MAPUB17_ENRH_5_MOTORL_SLOPE                100
#define AUTO_MAPUB17_ENRH_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_MAPUB17_ENRH_6_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRH_6_MOTORH_SPEED                2
#define AUTO_MAPUB17_ENRH_6_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRH_6_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRH_6_MOTORL_SPEED                2
#define AUTO_MAPUB17_ENRH_6_MOTORL_SLOPE                100
#define AUTO_MAPUB17_ENRH_6_BRAKE_OVERRIDE              TRUE

//ENRL
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MAPUB17_ENRL_2_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRL_2_MOTORH_SPEED                1
#define AUTO_MAPUB17_ENRL_2_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRL_2_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRL_2_MOTORL_SPEED                AUTO_MAPUB17_ENRL_FULL_SPEED
#define AUTO_MAPUB17_ENRL_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MAPUB17_ENRL_3_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRL_3_MOTORH_SPEED                1
#define AUTO_MAPUB17_ENRL_3_MOTORH_SLOPE                50
#define AUTO_MAPUB17_ENRL_3_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRL_3_MOTORL_SPEED                AUTO_MAPUB17_ENRL_DOCK_SPEED
#define AUTO_MAPUB17_ENRL_3_MOTORL_SLOPE                75

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MAPUB17_ENRL_4_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRL_4_MOTORH_SPEED                1
#define AUTO_MAPUB17_ENRL_4_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRL_4_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRL_4_MOTORL_SPEED                AUTO_MAPUB17_ENRL_DOCK_SPEED
#define AUTO_MAPUB17_ENRL_4_MOTORL_SLOPE                100

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MAPUB17_ENRL_5_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRL_5_MOTORH_SPEED                2
#define AUTO_MAPUB17_ENRL_5_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRL_5_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRL_5_MOTORL_SPEED                2
#define AUTO_MAPUB17_ENRL_5_MOTORL_SLOPE                100
#define AUTO_MAPUB17_ENRL_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_MAPUB17_ENRL_6_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB17_ENRL_6_MOTORH_SPEED                2
#define AUTO_MAPUB17_ENRL_6_MOTORH_SLOPE                100
#define AUTO_MAPUB17_ENRL_6_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB17_ENRL_6_MOTORL_SPEED                2
#define AUTO_MAPUB17_ENRL_6_MOTORL_SLOPE                100
#define AUTO_MAPUB17_ENRL_6_BRAKE_OVERRIDE              TRUE

#endif	/* MOTOR_MAPUB17_H */

