#include <_Global_Include.h>


void motor_set_model_alcom17(void)
{
    motor.family = MOTOR_ASYNC_FAMILY;
    motor.model  = MOTOR_MODEL_ASYNC_ALCOM;
    motor.minimum_speed_value = (ALCOM17_MINIMUM_FREQ/10);
    motor.maximum_speed_value = (ALCOM17_MAXIMUM_FREQ/10);
    
    motor.maximum_accel_slope_coeff = ALCOM17_ACCEL_SLOPE_COEFF;
    motor.maximum_decel_slope_coeff = ALCOM17_DECEL_SLOPE_COEFF;
    
    motor.enrh_speed_adjust = ALCOM17_ENRH_DOCK_SPEED_ADJUST;
    motor.enrl_speed_adjust = ALCOM17_ENRL_DOCK_SPEED_ADJUST;
            
    motor.error_mode.init_phase_list[0].motorh_mode_dir   = ERROR_ALCOM17_MOTORH_DIR;
    motor.error_mode.init_phase_list[0].motorh_speed      = ERROR_ALCOM17_MOTORH_SPEED;
    motor.error_mode.init_phase_list[0].motorh_slope      = ERROR_ALCOM17_MOTORH_SLOPE;
    motor.error_mode.init_phase_list[0].motorl_mode_dir   = ERROR_ALCOM17_MOTORL_DIR;
    motor.error_mode.init_phase_list[0].motorl_speed      = ERROR_ALCOM17_MOTORL_SPEED;
    motor.error_mode.init_phase_list[0].motorl_slope      = ERROR_ALCOM17_MOTORL_SLOPE;
    
    
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    // MODE MANUEL
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    
    //-------------------------------------------------------------------------------------------------------------------
    // ENRH
    //-------------------------------------------------------------------------------------------------------------------
    
    // ENRH : 0 = OFF
    motor.manual_mode.manual_enrh_phase_list[0].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_0_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[0].motorh_speed      = MANUAL_ALCOM17_ENRH_0_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[0].motorh_slope      = MANUAL_ALCOM17_ENRH_0_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_0_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_speed      = MANUAL_ALCOM17_ENRH_0_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_slope      = MANUAL_ALCOM17_ENRH_0_MOTORL_SLOPE;
    
    // ENRH : 1 = STANDBY
    motor.manual_mode.manual_enrh_phase_list[1].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_1_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[1].motorh_speed      = MANUAL_ALCOM17_ENRH_1_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[1].motorh_slope      = MANUAL_ALCOM17_ENRH_1_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_1_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_speed      = MANUAL_ALCOM17_ENRH_1_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_slope      = MANUAL_ALCOM17_ENRH_1_MOTORL_SLOPE;
    
    // ENRH : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_enrh_phase_list[2].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_2_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[2].motorh_speed      = MANUAL_ALCOM17_ENRH_2_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[2].motorh_slope      = MANUAL_ALCOM17_ENRH_2_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_2_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_speed      = MANUAL_ALCOM17_ENRH_2_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_slope      = MANUAL_ALCOM17_ENRH_2_MOTORL_SLOPE;
    
    // ENRH : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_enrh_phase_list[3].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_3_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[3].motorh_speed      = MANUAL_ALCOM17_ENRH_3_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[3].motorh_slope      = MANUAL_ALCOM17_ENRH_3_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_3_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_speed      = MANUAL_ALCOM17_ENRH_3_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_slope      = MANUAL_ALCOM17_ENRH_3_MOTORL_SLOPE;
    
    // ENRH : 4 = TENSION AFFICHE
    motor.manual_mode.manual_enrh_phase_list[4].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_4_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[4].motorh_speed      = MANUAL_ALCOM17_ENRH_4_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[4].motorh_slope      = MANUAL_ALCOM17_ENRH_4_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_4_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_speed      = MANUAL_ALCOM17_ENRH_4_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_slope      = MANUAL_ALCOM17_ENRH_4_MOTORL_SLOPE;
    
    // ENRH : 5 = ARRET
    motor.manual_mode.manual_enrh_phase_list[5].motorh_mode_dir   = MANUAL_ALCOM17_ENRH_5_MOTORH_DIR;
    motor.manual_mode.manual_enrh_phase_list[5].motorh_speed      = MANUAL_ALCOM17_ENRH_5_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[5].motorh_slope      = MANUAL_ALCOM17_ENRH_5_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_mode_dir   = MANUAL_ALCOM17_ENRH_5_MOTORL_DIR;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_speed      = MANUAL_ALCOM17_ENRH_5_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_slope      = MANUAL_ALCOM17_ENRH_5_MOTORL_SLOPE;
    
    //-------------------------------------------------------------------------------------------------------------------
    // ENRL
    //-------------------------------------------------------------------------------------------------------------------
    
    // ENRL : 0 = OFF
    motor.manual_mode.manual_enrl_phase_list[0].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_0_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[0].motorh_speed      = MANUAL_ALCOM17_ENRL_0_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[0].motorh_slope      = MANUAL_ALCOM17_ENRL_0_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_0_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_speed      = MANUAL_ALCOM17_ENRL_0_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_slope      = MANUAL_ALCOM17_ENRL_0_MOTORL_SLOPE;
    
    // ENRL : 1 = STANDBY
    motor.manual_mode.manual_enrl_phase_list[1].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_1_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[1].motorh_speed      = MANUAL_ALCOM17_ENRL_1_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[1].motorh_slope      = MANUAL_ALCOM17_ENRL_1_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_1_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_speed      = MANUAL_ALCOM17_ENRL_1_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_slope      = MANUAL_ALCOM17_ENRL_1_MOTORL_SLOPE;
    
    // ENRL : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_enrl_phase_list[2].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_2_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[2].motorh_speed      = MANUAL_ALCOM17_ENRL_2_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[2].motorh_slope      = MANUAL_ALCOM17_ENRL_2_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_2_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_speed      = MANUAL_ALCOM17_ENRL_2_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_slope      = MANUAL_ALCOM17_ENRL_2_MOTORL_SLOPE;
    
    // ENRL : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_enrl_phase_list[3].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_3_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[3].motorh_speed      = MANUAL_ALCOM17_ENRL_3_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[3].motorh_slope      = MANUAL_ALCOM17_ENRL_3_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_3_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_speed      = MANUAL_ALCOM17_ENRL_3_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_slope      = MANUAL_ALCOM17_ENRL_3_MOTORL_SLOPE;
    
    // ENRL : 4 = TENSION AFFICHE
    motor.manual_mode.manual_enrl_phase_list[4].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_4_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[4].motorh_speed      = MANUAL_ALCOM17_ENRL_4_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[4].motorh_slope      = MANUAL_ALCOM17_ENRL_4_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_4_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_speed      = MANUAL_ALCOM17_ENRL_4_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_slope      = MANUAL_ALCOM17_ENRL_4_MOTORL_SLOPE;
    
    // ENRL : 5 = ARRET
    motor.manual_mode.manual_enrl_phase_list[5].motorh_mode_dir   = MANUAL_ALCOM17_ENRL_5_MOTORH_DIR;
    motor.manual_mode.manual_enrl_phase_list[5].motorh_speed      = MANUAL_ALCOM17_ENRL_5_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[5].motorh_slope      = MANUAL_ALCOM17_ENRL_5_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_mode_dir   = MANUAL_ALCOM17_ENRL_5_MOTORL_DIR;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_speed      = MANUAL_ALCOM17_ENRL_5_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_slope      = MANUAL_ALCOM17_ENRL_5_MOTORL_SLOPE;
    
    //-------------------------------------------------------------------------------------------------------------------
    // DERH
    //-------------------------------------------------------------------------------------------------------------------
    
    // DERH : 0 = OFF
    motor.manual_mode.manual_derh_phase_list[0].motorh_mode_dir   = MANUAL_ALCOM17_DERH_0_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[0].motorh_speed      = MANUAL_ALCOM17_DERH_0_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[0].motorh_slope      = MANUAL_ALCOM17_DERH_0_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[0].motorl_mode_dir   = MANUAL_ALCOM17_DERH_0_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[0].motorl_speed      = MANUAL_ALCOM17_DERH_0_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[0].motorl_slope      = MANUAL_ALCOM17_DERH_0_MOTORL_SLOPE;
    
    // DERH : 1 = STANDBY
    motor.manual_mode.manual_derh_phase_list[1].motorh_mode_dir   = MANUAL_ALCOM17_DERH_1_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[1].motorh_speed      = MANUAL_ALCOM17_DERH_1_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[1].motorh_slope      = MANUAL_ALCOM17_DERH_1_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[1].motorl_mode_dir   = MANUAL_ALCOM17_DERH_1_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[1].motorl_speed      = MANUAL_ALCOM17_DERH_1_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[1].motorl_slope      = MANUAL_ALCOM17_DERH_1_MOTORL_SLOPE;
    
    // DERH : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_derh_phase_list[2].motorh_mode_dir   = MANUAL_ALCOM17_DERH_2_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[2].motorh_speed      = MANUAL_ALCOM17_DERH_2_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[2].motorh_slope      = MANUAL_ALCOM17_DERH_2_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[2].motorl_mode_dir   = MANUAL_ALCOM17_DERH_2_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[2].motorl_speed      = MANUAL_ALCOM17_DERH_2_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[2].motorl_slope      = MANUAL_ALCOM17_DERH_2_MOTORL_SLOPE;
    
    // DERH : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_derh_phase_list[3].motorh_mode_dir   = MANUAL_ALCOM17_DERH_3_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[3].motorh_speed      = MANUAL_ALCOM17_DERH_3_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[3].motorh_slope      = MANUAL_ALCOM17_DERH_3_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[3].motorl_mode_dir   = MANUAL_ALCOM17_DERH_3_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[3].motorl_speed      = MANUAL_ALCOM17_DERH_3_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[3].motorl_slope      = MANUAL_ALCOM17_DERH_3_MOTORL_SLOPE;
    
    // DERH : 4 = TENSION AFFICHE
    motor.manual_mode.manual_derh_phase_list[4].motorh_mode_dir   = MANUAL_ALCOM17_DERH_4_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[4].motorh_speed      = MANUAL_ALCOM17_DERH_4_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[4].motorh_slope      = MANUAL_ALCOM17_DERH_4_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[4].motorl_mode_dir   = MANUAL_ALCOM17_DERH_4_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[4].motorl_speed      = MANUAL_ALCOM17_DERH_4_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[4].motorl_slope      = MANUAL_ALCOM17_DERH_4_MOTORL_SLOPE;
    
    // DERH : 5 = ARRET
    motor.manual_mode.manual_derh_phase_list[5].motorh_mode_dir   = MANUAL_ALCOM17_DERH_5_MOTORH_DIR;
    motor.manual_mode.manual_derh_phase_list[5].motorh_speed      = MANUAL_ALCOM17_DERH_5_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[5].motorh_slope      = MANUAL_ALCOM17_DERH_5_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[5].motorl_mode_dir   = MANUAL_ALCOM17_DERH_5_MOTORL_DIR;
    motor.manual_mode.manual_derh_phase_list[5].motorl_speed      = MANUAL_ALCOM17_DERH_5_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[5].motorl_slope      = MANUAL_ALCOM17_DERH_5_MOTORL_SLOPE;
         
    
    
    
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    // MODE INIT
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    motor.init_mode.cell_inhib_time_bm                   = INIT_ALCOM17_CELL_INHIB_TIME_BM;
    motor.init_mode.cell_inhib_time_pastille             = INIT_ALCOM17_CELL_INHIB_TIME_PASTILLE;
    motor.init_mode.cell_timeout_time                    = INIT_ALCOM17_CELL_TIMEOUT_TIME;
    motor.init_mode.init_cell_decr_speed                 = INIT_ALCOM17_CELL_DECR_SPEED;
    motor.init_mode.init_cell_decr_slope                 = INIT_ALCOM17_CELL_DECR_SLOPE;
    motor.init_mode.init_cell_between_time               = INIT_ALCOM17_CELL_BETWEEN_TIME;
    motor.init_mode.enrh_dock_speed                      = INIT_ALCOM17_ENRH_DOCK_SPEED;
    
    motor.init_mode.init_phase_list[0].motorh_mode_dir   = INIT_ALCOM17_START_CELL_MOTORH_DIR;
    motor.init_mode.init_phase_list[0].motorh_speed      = INIT_ALCOM17_START_CELL_MOTORH_SPEED;
    motor.init_mode.init_phase_list[0].motorh_slope      = INIT_ALCOM17_START_CELL_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[0].motorl_mode_dir   = INIT_ALCOM17_START_CELL_MOTORL_DIR;
    motor.init_mode.init_phase_list[0].motorl_speed      = INIT_ALCOM17_START_CELL_MOTORL_SPEED;
    motor.init_mode.init_phase_list[0].motorl_slope      = INIT_ALCOM17_START_CELL_MOTORL_SLOPE;
    
    // 1: petite rampe vers tension affiche
    motor.init_mode.init_phase_list[1].motorh_mode_dir   = INIT_ALCOM17_1_MOTORH_DIR;
    motor.init_mode.init_phase_list[1].motorh_speed      = INIT_ALCOM17_1_MOTORH_SPEED;
    motor.init_mode.init_phase_list[1].motorh_slope      = INIT_ALCOM17_1_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[1].motorl_mode_dir   = INIT_ALCOM17_1_MOTORL_DIR;
    motor.init_mode.init_phase_list[1].motorl_speed      = INIT_ALCOM17_1_MOTORL_SPEED;
    motor.init_mode.init_phase_list[1].motorl_slope      = INIT_ALCOM17_1_MOTORL_SLOPE;
    
    // 2: tension affiche pendant plusieurs secondes
    motor.init_mode.init_phase_list[2].motorh_mode_dir   = INIT_ALCOM17_2_MOTORH_DIR;
    motor.init_mode.init_phase_list[2].motorh_speed      = INIT_ALCOM17_2_MOTORH_SPEED;
    motor.init_mode.init_phase_list[2].motorh_slope      = INIT_ALCOM17_2_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[2].motorl_mode_dir   = INIT_ALCOM17_2_MOTORL_DIR;
    motor.init_mode.init_phase_list[2].motorl_speed      = INIT_ALCOM17_2_MOTORL_SPEED;
    motor.init_mode.init_phase_list[2].motorl_slope      = INIT_ALCOM17_2_MOTORL_SLOPE;
    
    // 3: rampe acceleration sur moteur du haut pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[3].motorh_mode_dir   = INIT_ALCOM17_3_MOTORH_DIR;
    motor.init_mode.init_phase_list[3].motorh_speed      = INIT_ALCOM17_3_MOTORH_SPEED;
    motor.init_mode.init_phase_list[3].motorh_slope      = INIT_ALCOM17_3_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[3].motorl_mode_dir   = INIT_ALCOM17_3_MOTORL_DIR;
    motor.init_mode.init_phase_list[3].motorl_speed      = INIT_ALCOM17_3_MOTORL_SPEED;
    motor.init_mode.init_phase_list[3].motorl_slope      = INIT_ALCOM17_3_MOTORL_SLOPE;
    
    // 4: rampe deceleration sur moteur du haut s'arreter sur la BM basse
    motor.init_mode.init_phase_list[4].motorh_mode_dir   = INIT_ALCOM17_4_MOTORH_DIR;
    motor.init_mode.init_phase_list[4].motorh_speed      = INIT_ALCOM17_4_MOTORH_SPEED;
    motor.init_mode.init_phase_list[4].motorh_slope      = INIT_ALCOM17_4_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[4].motorl_mode_dir   = INIT_ALCOM17_4_MOTORL_DIR;
    motor.init_mode.init_phase_list[4].motorl_speed      = INIT_ALCOM17_4_MOTORL_SPEED;
    motor.init_mode.init_phase_list[4].motorl_slope      = INIT_ALCOM17_4_MOTORL_SLOPE;
    
    // 5: attente sur la BM basse
    motor.init_mode.init_phase_list[5].motorh_mode_dir   = INIT_ALCOM17_5_MOTORH_DIR;
    motor.init_mode.init_phase_list[5].motorh_speed      = INIT_ALCOM17_5_MOTORH_SPEED;
    motor.init_mode.init_phase_list[5].motorh_slope      = INIT_ALCOM17_5_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[5].motorl_mode_dir   = INIT_ALCOM17_5_MOTORL_DIR;
    motor.init_mode.init_phase_list[5].motorl_speed      = INIT_ALCOM17_5_MOTORL_SPEED;
    motor.init_mode.init_phase_list[5].motorl_slope      = INIT_ALCOM17_5_MOTORL_SLOPE;
    
    // 6: rampe acceleration sur moteur du bas pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[6].motorh_mode_dir   = INIT_ALCOM17_6_MOTORH_DIR;
    motor.init_mode.init_phase_list[6].motorh_speed      = INIT_ALCOM17_6_MOTORH_SPEED;
    motor.init_mode.init_phase_list[6].motorh_slope      = INIT_ALCOM17_6_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[6].motorl_mode_dir   = INIT_ALCOM17_6_MOTORL_DIR;
    motor.init_mode.init_phase_list[6].motorl_speed      = INIT_ALCOM17_6_MOTORL_SPEED;
    motor.init_mode.init_phase_list[6].motorl_slope      = INIT_ALCOM17_6_MOTORL_SLOPE;
    
    // 7: rampe deceleration sur moteur du bas s'arreter sur la BM haute
    motor.init_mode.init_phase_list[7].motorh_mode_dir   = INIT_ALCOM17_7_MOTORH_DIR;
    motor.init_mode.init_phase_list[7].motorh_speed      = INIT_ALCOM17_7_MOTORH_SPEED;
    motor.init_mode.init_phase_list[7].motorh_slope      = INIT_ALCOM17_7_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[7].motorl_mode_dir   = INIT_ALCOM17_7_MOTORL_DIR;
    motor.init_mode.init_phase_list[7].motorl_speed      = INIT_ALCOM17_7_MOTORL_SPEED;
    motor.init_mode.init_phase_list[7].motorl_slope      = INIT_ALCOM17_7_MOTORL_SLOPE;
    
    // 8: attente sur la BM haute
    motor.init_mode.init_phase_list[8].motorh_mode_dir   = INIT_ALCOM17_8_MOTORH_DIR;
    motor.init_mode.init_phase_list[8].motorh_speed      = INIT_ALCOM17_8_MOTORH_SPEED;
    motor.init_mode.init_phase_list[8].motorh_slope      = INIT_ALCOM17_8_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[8].motorl_mode_dir   = INIT_ALCOM17_8_MOTORL_DIR;
    motor.init_mode.init_phase_list[8].motorl_speed      = INIT_ALCOM17_8_MOTORL_SPEED;
    motor.init_mode.init_phase_list[8].motorl_slope      = INIT_ALCOM17_8_MOTORL_SLOPE;
    
    // 9: rampe acceleration sur moteur du haut pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[9].motorh_mode_dir   = INIT_ALCOM17_9_MOTORH_DIR;
    motor.init_mode.init_phase_list[9].motorh_speed      = INIT_ALCOM17_9_MOTORH_SPEED;
    motor.init_mode.init_phase_list[9].motorh_slope      = INIT_ALCOM17_9_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[9].motorl_mode_dir   = INIT_ALCOM17_9_MOTORL_DIR;
    motor.init_mode.init_phase_list[9].motorl_speed      = INIT_ALCOM17_9_MOTORL_SPEED;
    motor.init_mode.init_phase_list[9].motorl_slope      = INIT_ALCOM17_9_MOTORL_SLOPE;
    
    // 10: grande vitesse
    motor.init_mode.init_full_speed_time                 = INIT_ALCOM17_FULL_SPEED_TIME;
    
    
    
    // 10: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase1
    motor.init_mode.init_phase_list[10].motorh_mode_dir   = INIT_ALCOM17_10_MOTORH_DIR;
    motor.init_mode.init_phase_list[10].motorh_speed      = INIT_ALCOM17_10_MOTORH_SPEED;
    motor.init_mode.init_phase_list[10].motorh_slope      = INIT_ALCOM17_10_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[10].motorl_mode_dir   = INIT_ALCOM17_10_MOTORL_DIR;
    motor.init_mode.init_phase_list[10].motorl_speed      = INIT_ALCOM17_10_MOTORL_SPEED;
    motor.init_mode.init_phase_list[10].motorl_slope      = INIT_ALCOM17_10_MOTORL_SLOPE;
    
    
    // 11: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase2
    motor.init_mode.init_phase_list[11].motorh_mode_dir   = INIT_ALCOM17_11_MOTORH_DIR;
    motor.init_mode.init_phase_list[11].motorh_speed      = INIT_ALCOM17_11_MOTORH_SPEED;
    motor.init_mode.init_phase_list[11].motorh_slope      = INIT_ALCOM17_11_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[11].motorl_mode_dir   = INIT_ALCOM17_11_MOTORL_DIR;
    motor.init_mode.init_phase_list[11].motorl_speed      = INIT_ALCOM17_11_MOTORL_SPEED;
    motor.init_mode.init_phase_list[11].motorl_slope      = INIT_ALCOM17_11_MOTORL_SLOPE;
    
    
    // 12: rampe deceleration sur moteur du haut pour s'arreter sur la pastille
    motor.init_mode.init_phase_list[12].motorh_mode_dir   = INIT_ALCOM17_12_MOTORH_DIR;
    motor.init_mode.init_phase_list[12].motorh_speed      = INIT_ALCOM17_12_MOTORH_SPEED;
    motor.init_mode.init_phase_list[12].motorh_slope      = INIT_ALCOM17_12_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[12].motorl_mode_dir   = INIT_ALCOM17_12_MOTORL_DIR;
    motor.init_mode.init_phase_list[12].motorl_speed      = INIT_ALCOM17_12_MOTORL_SPEED;
    motor.init_mode.init_phase_list[12].motorl_slope      = INIT_ALCOM17_12_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[12].brake_override    = INIT_ALCOM17_12_BRAKE_OVERRIDE;
    
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
    motor.preauto_auto.preauto_enrh_full_speed_time       = AUTO_ALCOM17_ENRH_FULL_SPEED_TIME;
    motor.preauto_auto.preauto_enrl_full_speed_time       = AUTO_ALCOM17_ENRL_FULL_SPEED_TIME;
    
    motor.preauto_auto.cell_inhib_time_bm                 = AUTO_ALCOM17_CELL_TIMEOUT_TIME;
    motor.preauto_auto.cell_inhib_time_pastille           = AUTO_ALCOM17_CELL_INHIB_TIME_PASTILLE;
    motor.preauto_auto.cell_inhib_time_bm                 = AUTO_ALCOM17_CELL_INHIB_TIME_BM;
    motor.preauto_auto.cell_timeout_time                  = AUTO_ALCOM17_CELL_TIMEOUT_TIME;
    
    motor.preauto_auto.enrh_dock_speed                    = AUTO_ALCOM17_ENRH_DOCK_SPEED;
    motor.preauto_auto.enrl_dock_speed                    = AUTO_ALCOM17_ENRL_DOCK_SPEED;
    
    
    
    //ENRH
    motor.preauto_auto.enrh_phase_list[0].motorh_mode_dir = AUTO_ALCOM17_1_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorh_speed    = AUTO_ALCOM17_1_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorh_slope    = AUTO_ALCOM17_1_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorl_mode_dir = AUTO_ALCOM17_1_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorl_speed    = AUTO_ALCOM17_1_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorl_slope    = AUTO_ALCOM17_1_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[1].motorh_mode_dir = AUTO_ALCOM17_ENRH_2_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorh_speed    = AUTO_ALCOM17_ENRH_2_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorh_slope    = AUTO_ALCOM17_ENRH_2_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorl_mode_dir = AUTO_ALCOM17_ENRH_2_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorl_speed    = AUTO_ALCOM17_ENRH_2_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorl_slope    = AUTO_ALCOM17_ENRH_2_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[2].motorh_mode_dir = AUTO_ALCOM17_ENRH_3_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorh_speed    = AUTO_ALCOM17_ENRH_3_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorh_slope    = AUTO_ALCOM17_ENRH_3_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorl_mode_dir = AUTO_ALCOM17_ENRH_3_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorl_speed    = AUTO_ALCOM17_ENRH_3_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorl_slope    = AUTO_ALCOM17_ENRH_3_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[3].motorh_mode_dir = AUTO_ALCOM17_ENRH_4_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorh_speed    = AUTO_ALCOM17_ENRH_4_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorh_slope    = AUTO_ALCOM17_ENRH_4_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorl_mode_dir = AUTO_ALCOM17_ENRH_4_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorl_speed    = AUTO_ALCOM17_ENRH_4_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorl_slope    = AUTO_ALCOM17_ENRH_4_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[4].motorh_mode_dir = AUTO_ALCOM17_ENRH_5_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorh_speed    = AUTO_ALCOM17_ENRH_5_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorh_slope    = AUTO_ALCOM17_ENRH_5_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorl_mode_dir = AUTO_ALCOM17_ENRH_5_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorl_speed    = AUTO_ALCOM17_ENRH_5_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorl_slope    = AUTO_ALCOM17_ENRH_5_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].brake_override  = AUTO_ALCOM17_ENRH_5_BRAKE_OVERRIDE;
    
    motor.preauto_auto.enrh_phase_list[5].motorh_mode_dir = AUTO_ALCOM17_ENRH_6_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorh_speed    = AUTO_ALCOM17_ENRH_6_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorh_slope    = AUTO_ALCOM17_ENRH_6_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorl_mode_dir = AUTO_ALCOM17_ENRH_6_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorl_speed    = AUTO_ALCOM17_ENRH_6_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorl_slope    = AUTO_ALCOM17_ENRH_6_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].brake_override  = AUTO_ALCOM17_ENRH_6_BRAKE_OVERRIDE;
    
    //ENRL
    motor.preauto_auto.enrl_phase_list[0].motorh_mode_dir = AUTO_ALCOM17_1_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorh_speed    = AUTO_ALCOM17_1_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorh_slope    = AUTO_ALCOM17_1_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[0].motorl_mode_dir = AUTO_ALCOM17_1_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorl_speed    = AUTO_ALCOM17_1_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorl_slope    = AUTO_ALCOM17_1_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[1].motorh_mode_dir = AUTO_ALCOM17_ENRL_2_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorh_speed    = AUTO_ALCOM17_ENRL_2_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorh_slope    = AUTO_ALCOM17_ENRL_2_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[1].motorl_mode_dir = AUTO_ALCOM17_ENRL_2_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorl_speed    = AUTO_ALCOM17_ENRL_2_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorl_slope    = AUTO_ALCOM17_ENRL_2_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[2].motorh_mode_dir = AUTO_ALCOM17_ENRL_3_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorh_speed    = AUTO_ALCOM17_ENRL_3_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorh_slope    = AUTO_ALCOM17_ENRL_3_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[2].motorl_mode_dir = AUTO_ALCOM17_ENRL_3_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorl_speed    = AUTO_ALCOM17_ENRL_3_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorl_slope    = AUTO_ALCOM17_ENRL_3_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[3].motorh_mode_dir = AUTO_ALCOM17_ENRL_4_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorh_speed    = AUTO_ALCOM17_ENRL_4_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorh_slope    = AUTO_ALCOM17_ENRL_4_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[3].motorl_mode_dir = AUTO_ALCOM17_ENRL_4_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorl_speed    = AUTO_ALCOM17_ENRL_4_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorl_slope    = AUTO_ALCOM17_ENRL_4_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[4].motorh_mode_dir = AUTO_ALCOM17_ENRL_5_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorh_speed    = AUTO_ALCOM17_ENRL_5_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorh_slope    = AUTO_ALCOM17_ENRL_5_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[4].motorl_mode_dir = AUTO_ALCOM17_ENRL_5_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorl_speed    = AUTO_ALCOM17_ENRL_5_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorl_slope    = AUTO_ALCOM17_ENRL_5_MOTORL_SLOPE;
    motor.preauto_auto.enrl_phase_list[4].brake_override  = AUTO_ALCOM17_ENRL_5_BRAKE_OVERRIDE;
    
    motor.preauto_auto.enrl_phase_list[5].motorh_mode_dir = AUTO_ALCOM17_ENRL_6_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorh_speed    = AUTO_ALCOM17_ENRL_6_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorh_slope    = AUTO_ALCOM17_ENRL_6_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[5].motorl_mode_dir = AUTO_ALCOM17_ENRL_6_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorl_speed    = AUTO_ALCOM17_ENRL_6_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorl_slope    = AUTO_ALCOM17_ENRL_6_MOTORL_SLOPE;
    motor.preauto_auto.enrl_phase_list[5].brake_override  = AUTO_ALCOM17_ENRL_6_BRAKE_OVERRIDE;
    
    
    
    
    
}

