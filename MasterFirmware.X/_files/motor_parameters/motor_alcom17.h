#ifndef MOTOR_ALCOM17_H
#define	MOTOR_ALCOM17_H

// struct struct_motor motor_mapub17;

#define ALCOM17_FPWM                           9000L//9000L
#define ALCOM17_PWM_PHASE_SHIFT                (2*FCY)/(ALCOM17_FPWM*2)
#define ALCOM17_SINE_WAVE_ACCURACY               64L
#define ALCOM17_MINIMUM_FREQ                      1.0 // 0.1 Hz
#define ALCOM17_MAXIMUM_FREQ                    500.0 // 50 Hz
#define ALCOM17_VOLTAGE_MAX                     220

#define ALCOM17_POINT0_FREQ                      10
#define ALCOM17_POINT0_VOLT                      18
#define ALCOM17_POINT1_FREQ                     150
#define ALCOM17_POINT1_VOLT                      80
#define ALCOM17_POINT2_FREQ                     350
#define ALCOM17_POINT2_VOLT                     162
#define ALCOM17_POINT3_FREQ                     500
#define ALCOM17_POINT3_VOLT     ALCOM17_VOLTAGE_MAX



#define ALCOM17_ACCEL_MAX_SLOPE           800
#define ALCOM17_DECEL_MAX_SLOPE          -1500

#define ALCOM17_ACCEL_SLOPE_COEFF              (((ALCOM17_MAXIMUM_FREQ - ALCOM17_MINIMUM_FREQ)) / (ALCOM17_ACCEL_MAX_SLOPE*10))
#define ALCOM17_DECEL_SLOPE_COEFF              (((ALCOM17_MAXIMUM_FREQ - ALCOM17_MINIMUM_FREQ)) / (ALCOM17_DECEL_MAX_SLOPE*10))


#define ALCOM17_ENRH_DOCK_SPEED_ADJUST      4
#define ALCOM17_ENRL_DOCK_SPEED_ADJUST      3


//---------------------------------------------------------------------------------------------------
// ALCOM17 ERREUR 
//---------------------------------------------------------------------------------------------------
#define ERROR_ALCOM17_MOTORH_DIR         ASYNC_DIRECT    
#define ERROR_ALCOM17_MOTORH_SPEED       1
#define ERROR_ALCOM17_MOTORH_SLOPE       100
#define ERROR_ALCOM17_MOTORL_DIR         ASYNC_DIRECT 
#define ERROR_ALCOM17_MOTORL_SPEED       0
#define ERROR_ALCOM17_MOTORL_SLOPE       100

//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// ALCOM MODE MANUEL
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

//---------------------------------------------------------------------------------------------------
// ENRH
//---------------------------------------------------------------------------------------------------
#define MANUAL_ALCOM17_ENRH_0_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_0_MOTORH_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_ENRH_0_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_0_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_0_MOTORL_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_ENRH_0_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRH_1_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_1_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRH_1_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_1_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_1_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRH_1_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRH_2_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_2_MOTORH_SPEED       30
#define MANUAL_ALCOM17_ENRH_2_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_2_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_2_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRH_2_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRH_3_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_3_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRH_3_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_3_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_3_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRH_3_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRH_4_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_4_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRH_4_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_4_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_4_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRH_4_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRH_5_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRH_5_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRH_5_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRH_5_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRH_5_MOTORL_SPEED       0
#define MANUAL_ALCOM17_ENRH_5_MOTORL_SLOPE       100

//---------------------------------------------------------------------------------------------------
// ENRL
//---------------------------------------------------------------------------------------------------
#define MANUAL_ALCOM17_ENRL_0_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRL_0_MOTORH_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_ENRL_0_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_0_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRL_0_MOTORL_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_ENRL_0_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRL_1_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRL_1_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRL_1_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_1_MOTORL_DIR         ASYNC_DIRECT
#define MANUAL_ALCOM17_ENRL_1_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRL_1_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRL_2_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRL_2_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRL_2_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_2_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRL_2_MOTORL_SPEED       30
#define MANUAL_ALCOM17_ENRL_2_MOTORL_SLOPE       100
  
#define MANUAL_ALCOM17_ENRL_3_MOTORH_DIR         ASYNC_DIRECT  
#define MANUAL_ALCOM17_ENRL_3_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRL_3_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_3_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRL_3_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRL_3_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRL_4_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRL_4_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRL_4_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_4_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRL_4_MOTORL_SPEED       1
#define MANUAL_ALCOM17_ENRL_4_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_ENRL_5_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_ENRL_5_MOTORH_SPEED       1
#define MANUAL_ALCOM17_ENRL_5_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_ENRL_5_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_ENRL_5_MOTORL_SPEED       0
#define MANUAL_ALCOM17_ENRL_5_MOTORL_SLOPE       100

//---------------------------------------------------------------------------------------------------
// DERH
//---------------------------------------------------------------------------------------------------
#define MANUAL_ALCOM17_DERH_0_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_DERH_0_MOTORH_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_DERH_0_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_0_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_DERH_0_MOTORL_SPEED       ALCOM17_MINIMUM_FREQ
#define MANUAL_ALCOM17_DERH_0_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_DERH_1_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_DERH_1_MOTORH_SPEED       1
#define MANUAL_ALCOM17_DERH_1_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_1_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_DERH_1_MOTORL_SPEED       1
#define MANUAL_ALCOM17_DERH_1_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_DERH_2_MOTORH_DIR         ASYNC_INVERSE    
#define MANUAL_ALCOM17_DERH_2_MOTORH_SPEED       30
#define MANUAL_ALCOM17_DERH_2_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_2_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_DERH_2_MOTORL_SPEED       0
#define MANUAL_ALCOM17_DERH_2_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_DERH_3_MOTORH_DIR         ASYNC_INVERSE 
#define MANUAL_ALCOM17_DERH_3_MOTORH_SPEED       1
#define MANUAL_ALCOM17_DERH_3_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_3_MOTORL_DIR         ASYNC_DIRECT   
#define MANUAL_ALCOM17_DERH_3_MOTORL_SPEED       0
#define MANUAL_ALCOM17_DERH_3_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_DERH_4_MOTORH_DIR         ASYNC_INVERSE    
#define MANUAL_ALCOM17_DERH_4_MOTORH_SPEED       1
#define MANUAL_ALCOM17_DERH_4_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_4_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_DERH_4_MOTORL_SPEED       0
#define MANUAL_ALCOM17_DERH_4_MOTORL_SLOPE       100

#define MANUAL_ALCOM17_DERH_5_MOTORH_DIR         ASYNC_DIRECT    
#define MANUAL_ALCOM17_DERH_5_MOTORH_SPEED       1
#define MANUAL_ALCOM17_DERH_5_MOTORH_SLOPE       100
#define MANUAL_ALCOM17_DERH_5_MOTORL_DIR         ASYNC_DIRECT 
#define MANUAL_ALCOM17_DERH_5_MOTORL_SPEED       0
#define MANUAL_ALCOM17_DERH_5_MOTORL_SLOPE       100

//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
// ALCOM MODE INIT
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
#define INIT_ALCOM17_CELL_TIMEOUT_TIME             5800
#define INIT_ALCOM17_CELL_INHIB_TIME_PASTILLE      500
#define INIT_ALCOM17_CELL_INHIB_TIME_BM            500
#define INIT_ALCOM17_CELL_DECR_SPEED               2
#define INIT_ALCOM17_CELL_DECR_SLOPE               100
#define INIT_ALCOM17_CELL_BETWEEN_TIME             4500

#define INIT_ALCOM17_ENRH_DOCK_SPEED               15

#define INIT_ALCOM17_START_CELL_MOTORH_DIR         ASYNC_DIRECT    
#define INIT_ALCOM17_START_CELL_MOTORH_SPEED       15
#define INIT_ALCOM17_START_CELL_MOTORH_SLOPE       50
#define INIT_ALCOM17_START_CELL_MOTORL_DIR         ASYNC_DIRECT 
#define INIT_ALCOM17_START_CELL_MOTORL_SPEED       1
#define INIT_ALCOM17_START_CELL_MOTORL_SLOPE       0

#define INIT_ALCOM17_1_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_1_MOTORH_SPEED                3
#define INIT_ALCOM17_1_MOTORH_SLOPE                100
#define INIT_ALCOM17_1_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_1_MOTORL_SPEED                3
#define INIT_ALCOM17_1_MOTORL_SLOPE                100

#define INIT_ALCOM17_2_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_2_MOTORH_SPEED                3
#define INIT_ALCOM17_2_MOTORH_SLOPE                10000
#define INIT_ALCOM17_2_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_2_MOTORL_SPEED                3
#define INIT_ALCOM17_2_MOTORL_SLOPE                10000

#define INIT_ALCOM17_3_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_3_MOTORH_SPEED                30
#define INIT_ALCOM17_3_MOTORH_SLOPE                100
#define INIT_ALCOM17_3_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_3_MOTORL_SPEED                1
#define INIT_ALCOM17_3_MOTORL_SLOPE                100

#define INIT_ALCOM17_4_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_4_MOTORH_SPEED                1
#define INIT_ALCOM17_4_MOTORH_SLOPE                100
#define INIT_ALCOM17_4_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_4_MOTORL_SPEED                1
#define INIT_ALCOM17_4_MOTORL_SLOPE                0

#define INIT_ALCOM17_5_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_5_MOTORH_SPEED                1
#define INIT_ALCOM17_5_MOTORH_SLOPE                100
#define INIT_ALCOM17_5_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_5_MOTORL_SPEED                1
#define INIT_ALCOM17_5_MOTORL_SLOPE                100

#define INIT_ALCOM17_6_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_6_MOTORH_SPEED                1
#define INIT_ALCOM17_6_MOTORH_SLOPE                100
#define INIT_ALCOM17_6_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_6_MOTORL_SPEED                30
#define INIT_ALCOM17_6_MOTORL_SLOPE                100

#define INIT_ALCOM17_7_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_7_MOTORH_SPEED                1
#define INIT_ALCOM17_7_MOTORH_SLOPE                100
#define INIT_ALCOM17_7_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_7_MOTORL_SPEED                1
#define INIT_ALCOM17_7_MOTORL_SLOPE                100

#define INIT_ALCOM17_8_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_8_MOTORH_SPEED                1
#define INIT_ALCOM17_8_MOTORH_SLOPE                100
#define INIT_ALCOM17_8_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_8_MOTORL_SPEED                1
#define INIT_ALCOM17_8_MOTORL_SLOPE                100

//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

// Rampe acceleration moteur haut
#define INIT_ALCOM17_9_MOTORH_DIR                   ASYNC_DIRECT    
#define INIT_ALCOM17_9_MOTORH_SPEED                 30
#define INIT_ALCOM17_9_MOTORH_SLOPE                 100
#define INIT_ALCOM17_9_MOTORL_DIR                   ASYNC_DIRECT 
#define INIT_ALCOM17_9_MOTORL_SPEED                 1
#define INIT_ALCOM17_9_MOTORL_SLOPE                 100

// Pleine vitesse
#define INIT_ALCOM17_FULL_SPEED_TIME                1500

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_ALCOM17_10_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_10_MOTORH_SPEED                INIT_ALCOM17_ENRH_DOCK_SPEED
#define INIT_ALCOM17_10_MOTORH_SLOPE                75
#define INIT_ALCOM17_10_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_10_MOTORL_SPEED                1
#define INIT_ALCOM17_10_MOTORL_SLOPE                100


// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_ALCOM17_11_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_11_MOTORH_SPEED                INIT_ALCOM17_ENRH_DOCK_SPEED
#define INIT_ALCOM17_11_MOTORH_SLOPE                75
#define INIT_ALCOM17_11_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_11_MOTORL_SPEED                1
#define INIT_ALCOM17_11_MOTORL_SLOPE                100

// Rampe arret moteur haut sur cellule
#define INIT_ALCOM17_12_MOTORH_DIR                  ASYNC_DIRECT    
#define INIT_ALCOM17_12_MOTORH_SPEED                3
#define INIT_ALCOM17_12_MOTORH_SLOPE                75
#define INIT_ALCOM17_12_MOTORL_DIR                  ASYNC_DIRECT 
#define INIT_ALCOM17_12_MOTORL_SPEED                2
#define INIT_ALCOM17_12_MOTORL_SLOPE                75
#define INIT_ALCOM17_12_BRAKE_OVERRIDE              TRUE



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
#define AUTO_ALCOM17_ENRH_FULL_SPEED_TIME          800
#define AUTO_ALCOM17_ENRL_FULL_SPEED_TIME          800
        
#define AUTO_ALCOM17_CELL_TIMEOUT_TIME             8000
#define AUTO_ALCOM17_CELL_INHIB_TIME_PASTILLE      1000
#define AUTO_ALCOM17_CELL_INHIB_TIME_BM            1000


#define AUTO_ALCOM17_ENRH_FULL_SPEED               42
#define AUTO_ALCOM17_ENRH_DOCK_SPEED               15
#define AUTO_ALCOM17_ENRL_FULL_SPEED               42
#define AUTO_ALCOM17_ENRL_DOCK_SPEED               15




// MAINTIEN 
#define AUTO_ALCOM17_1_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_1_MOTORH_SPEED                1.3
#define AUTO_ALCOM17_1_MOTORH_SLOPE                100
#define AUTO_ALCOM17_1_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_1_MOTORL_SPEED                1
#define AUTO_ALCOM17_1_MOTORL_SLOPE                100

//ENRH 
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_ALCOM17_ENRH_2_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRH_2_MOTORH_SPEED                AUTO_ALCOM17_ENRH_FULL_SPEED
#define AUTO_ALCOM17_ENRH_2_MOTORH_SLOPE                100
#define AUTO_ALCOM17_ENRH_2_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRH_2_MOTORL_SPEED                1
#define AUTO_ALCOM17_ENRH_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_ALCOM17_ENRH_3_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRH_3_MOTORH_SPEED                AUTO_ALCOM17_ENRH_FULL_SPEED
#define AUTO_ALCOM17_ENRH_3_MOTORH_SLOPE                100
#define AUTO_ALCOM17_ENRH_3_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRH_3_MOTORL_SPEED                2
#define AUTO_ALCOM17_ENRH_3_MOTORL_SLOPE                50

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_ALCOM17_ENRH_4_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRH_4_MOTORH_SPEED                AUTO_ALCOM17_ENRH_DOCK_SPEED
#define AUTO_ALCOM17_ENRH_4_MOTORH_SLOPE                50
#define AUTO_ALCOM17_ENRH_4_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRH_4_MOTORL_SPEED                1 // 2
#define AUTO_ALCOM17_ENRH_4_MOTORL_SLOPE                50

// ARRET SUR PASTILLE - PHASE1
#define AUTO_ALCOM17_ENRH_5_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRH_5_MOTORH_SPEED                (AUTO_ALCOM17_ENRH_DOCK_SPEED/2)//3
#define AUTO_ALCOM17_ENRH_5_MOTORH_SLOPE                100
#define AUTO_ALCOM17_ENRH_5_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRH_5_MOTORL_SPEED                (AUTO_ALCOM17_ENRH_DOCK_SPEED/2)//2
#define AUTO_ALCOM17_ENRH_5_MOTORL_SLOPE                100
#define AUTO_ALCOM17_ENRH_5_BRAKE_OVERRIDE              FALSE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_ALCOM17_ENRH_6_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRH_6_MOTORH_SPEED                1.3
#define AUTO_ALCOM17_ENRH_6_MOTORH_SLOPE                0
#define AUTO_ALCOM17_ENRH_6_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRH_6_MOTORL_SPEED                1
#define AUTO_ALCOM17_ENRH_6_MOTORL_SLOPE                0
#define AUTO_ALCOM17_ENRH_6_BRAKE_OVERRIDE              FALSE


//ENRL
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_ALCOM17_ENRL_2_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRL_2_MOTORH_SPEED                1
#define AUTO_ALCOM17_ENRL_2_MOTORH_SLOPE                100
#define AUTO_ALCOM17_ENRL_2_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRL_2_MOTORL_SPEED                AUTO_ALCOM17_ENRL_FULL_SPEED
#define AUTO_ALCOM17_ENRL_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_ALCOM17_ENRL_3_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRL_3_MOTORH_SPEED                2
#define AUTO_ALCOM17_ENRL_3_MOTORH_SLOPE                50
#define AUTO_ALCOM17_ENRL_3_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRL_3_MOTORL_SPEED                AUTO_ALCOM17_ENRL_FULL_SPEED
#define AUTO_ALCOM17_ENRL_3_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_ALCOM17_ENRL_4_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRL_4_MOTORH_SPEED                2
#define AUTO_ALCOM17_ENRL_4_MOTORH_SLOPE                50
#define AUTO_ALCOM17_ENRL_4_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRL_4_MOTORL_SPEED                AUTO_ALCOM17_ENRL_DOCK_SPEED
#define AUTO_ALCOM17_ENRL_4_MOTORL_SLOPE                50

// ARRET SUR PASTILLE - PHASE1
#define AUTO_ALCOM17_ENRL_5_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRL_5_MOTORH_SPEED                (AUTO_ALCOM17_ENRL_DOCK_SPEED/2)//3
#define AUTO_ALCOM17_ENRL_5_MOTORH_SLOPE                100
#define AUTO_ALCOM17_ENRL_5_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRL_5_MOTORL_SPEED                (AUTO_ALCOM17_ENRL_DOCK_SPEED/2)//2
#define AUTO_ALCOM17_ENRL_5_MOTORL_SLOPE                100
#define AUTO_ALCOM17_ENRL_5_BRAKE_OVERRIDE              TRUE

// ARRET SUR PASTILLE - PHASE2
#define AUTO_ALCOM17_ENRL_6_MOTORH_DIR                  ASYNC_DIRECT    
#define AUTO_ALCOM17_ENRL_6_MOTORH_SPEED                1.3
#define AUTO_ALCOM17_ENRL_6_MOTORH_SLOPE                0
#define AUTO_ALCOM17_ENRL_6_MOTORL_DIR                  ASYNC_DIRECT 
#define AUTO_ALCOM17_ENRL_6_MOTORL_SPEED                1
#define AUTO_ALCOM17_ENRL_6_MOTORL_SLOPE                0
#define AUTO_ALCOM17_ENRL_6_BRAKE_OVERRIDE              TRUE

#endif	/* MOTOR_ALCOM17_H */

