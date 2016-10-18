#ifndef MOTOR_MAPUB110_H
#define	MOTOR_MAPUB110_H




#define MAPUB110_ENRH_DOCK_SPEED_ADJUST      6
#define MAPUB110_ENRL_DOCK_SPEED_ADJUST      5

//---------------------------------------------------------------------------------------------------
// MAPUB110 ERREUR 
//---------------------------------------------------------------------------------------------------


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

//---------------------------------------------------------------------------------------------------
// INIT - ARRET PREMIERE AFFICHE
//---------------------------------------------------------------------------------------------------

#define INIT_MAPUB110_ENRH_FULL_SPEED               50
#define INIT_MAPUB110_ENRH_DOCK_SPEED               14

// Rampe acceleration moteur haut
#define INIT_MAPUB110_9_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB110_9_MOTORH_SPEED                INIT_MAPUB110_ENRH_FULL_SPEED
#define INIT_MAPUB110_9_MOTORH_SLOPE                100
#define INIT_MAPUB110_9_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB110_9_MOTORL_SPEED                0.3
#define INIT_MAPUB110_9_MOTORL_SLOPE                100

// Pleine vitesse
#define INIT_MAPUB110_FULL_SPEED_TIME                250

// Rampe deceleration moteur haut vers petite vitesse - phase1
#define INIT_MAPUB110_10_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB110_10_MOTORH_SPEED                INIT_MAPUB110_ENRH_DOCK_SPEED
#define INIT_MAPUB110_10_MOTORH_SLOPE                75
#define INIT_MAPUB110_10_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB110_10_MOTORL_SPEED                1
#define INIT_MAPUB110_10_MOTORL_SLOPE                100


// Rampe deceleration moteur haut vers petite vitesse - phase2
#define INIT_MAPUB110_11_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB110_11_MOTORH_SPEED                INIT_MAPUB110_ENRH_DOCK_SPEED
#define INIT_MAPUB110_11_MOTORH_SLOPE                100
#define INIT_MAPUB110_11_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB110_11_MOTORL_SPEED                0.5
#define INIT_MAPUB110_11_MOTORL_SLOPE                50

// Rampe arret moteur haut sur cellule
#define INIT_MAPUB110_12_MOTORH_DIR                  MAPUB17_DIRECTH    
#define INIT_MAPUB110_12_MOTORH_SPEED                2
#define INIT_MAPUB110_12_MOTORH_SLOPE                100
#define INIT_MAPUB110_12_MOTORL_DIR                  MAPUB17_DIRECTL 
#define INIT_MAPUB110_12_MOTORL_SPEED                2
#define INIT_MAPUB110_12_MOTORL_SLOPE                100
#define INIT_MAPUB110_12_BRAKE_OVERRIDE              TRUE




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
#define AUTO_MAPUB110_ENRH_FULL_SPEED_TIME         1000
#define AUTO_MAPUB110_ENRL_FULL_SPEED_TIME         1000

#define AUTO_MAPUB110_ENRH_FULL_SPEED               50
#define AUTO_MAPUB110_ENRH_DOCK_SPEED               14
#define AUTO_MAPUB110_ENRL_FULL_SPEED               50
#define AUTO_MAPUB110_ENRL_DOCK_SPEED               14




// MAINTIEN 
#define AUTO_MAPUB110_1_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_1_MOTORH_SPEED                2
#define AUTO_MAPUB110_1_MOTORH_SLOPE                100
#define AUTO_MAPUB110_1_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_1_MOTORL_SPEED                2
#define AUTO_MAPUB110_1_MOTORL_SLOPE                100

//ENRH 
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MAPUB110_ENRH_2_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRH_2_MOTORH_SPEED                AUTO_MAPUB110_ENRH_FULL_SPEED
#define AUTO_MAPUB110_ENRH_2_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRH_2_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRH_2_MOTORL_SPEED                0.3
#define AUTO_MAPUB110_ENRH_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MAPUB110_ENRH_3_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRH_3_MOTORH_SPEED                AUTO_MAPUB110_ENRH_DOCK_SPEED
#define AUTO_MAPUB110_ENRH_3_MOTORH_SLOPE                75
#define AUTO_MAPUB110_ENRH_3_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRH_3_MOTORL_SPEED                1
#define AUTO_MAPUB110_ENRH_3_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MAPUB110_ENRH_4_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRH_4_MOTORH_SPEED                AUTO_MAPUB110_ENRH_DOCK_SPEED
#define AUTO_MAPUB110_ENRH_4_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRH_4_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRH_4_MOTORL_SPEED                0.5
#define AUTO_MAPUB110_ENRH_4_MOTORL_SLOPE                50

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MAPUB110_ENRH_5_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRH_5_MOTORH_SPEED                (AUTO_MAPUB110_ENRH_DOCK_SPEED/2)
#define AUTO_MAPUB110_ENRH_5_MOTORH_SLOPE                50
#define AUTO_MAPUB110_ENRH_5_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRH_5_MOTORL_SPEED                (AUTO_MAPUB110_ENRH_DOCK_SPEED/2)
#define AUTO_MAPUB110_ENRH_5_MOTORL_SLOPE                50

// ARRET SUR PASTILLE - PHASE2
#define AUTO_MAPUB110_ENRH_6_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRH_6_MOTORH_SPEED                2
#define AUTO_MAPUB110_ENRH_6_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRH_6_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRH_6_MOTORL_SPEED                2
#define AUTO_MAPUB110_ENRH_6_MOTORL_SLOPE                100


//ENRL
        
// ACCELERATION VERS GRANDE VITESSE
#define AUTO_MAPUB110_ENRL_2_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRL_2_MOTORH_SPEED                0.3
#define AUTO_MAPUB110_ENRL_2_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRL_2_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRL_2_MOTORL_SPEED                AUTO_MAPUB110_ENRL_FULL_SPEED
#define AUTO_MAPUB110_ENRL_2_MOTORL_SLOPE                100

// DECELERATION VERS PETITE VITESSE - PHASE1
#define AUTO_MAPUB110_ENRL_3_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRL_3_MOTORH_SPEED                1
#define AUTO_MAPUB110_ENRL_3_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRL_3_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRL_3_MOTORL_SPEED                AUTO_MAPUB110_ENRL_DOCK_SPEED
#define AUTO_MAPUB110_ENRL_3_MOTORL_SLOPE                75

// DECELERATION VERS PETITE VITESSE - PHASE2
#define AUTO_MAPUB110_ENRL_4_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRL_4_MOTORH_SPEED                0.5
#define AUTO_MAPUB110_ENRL_4_MOTORH_SLOPE                50
#define AUTO_MAPUB110_ENRL_4_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRL_4_MOTORL_SPEED                AUTO_MAPUB110_ENRL_DOCK_SPEED
#define AUTO_MAPUB110_ENRL_4_MOTORL_SLOPE                100

// ARRET SUR PASTILLE - PHASE1
#define AUTO_MAPUB110_ENRL_5_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRL_5_MOTORH_SPEED                (AUTO_MAPUB110_ENRH_DOCK_SPEED/2)
#define AUTO_MAPUB110_ENRL_5_MOTORH_SLOPE                75
#define AUTO_MAPUB110_ENRL_5_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRL_5_MOTORL_SPEED                (AUTO_MAPUB110_ENRH_DOCK_SPEED/2)
#define AUTO_MAPUB110_ENRL_5_MOTORL_SLOPE                75



// ARRET SUR PASTILLE - PHASE2
#define AUTO_MAPUB110_ENRL_6_MOTORH_DIR                  MAPUB17_DIRECTH    
#define AUTO_MAPUB110_ENRL_6_MOTORH_SPEED                2
#define AUTO_MAPUB110_ENRL_6_MOTORH_SLOPE                100
#define AUTO_MAPUB110_ENRL_6_MOTORL_DIR                  MAPUB17_DIRECTL 
#define AUTO_MAPUB110_ENRL_6_MOTORL_SPEED                2
#define AUTO_MAPUB110_ENRL_6_MOTORL_SLOPE                100

#endif	/* MOTOR_MAPUB110_H */

