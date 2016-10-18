#include <_Global_Include.h>


void motor_set_model_mcc(void)
{
    motor.family = MOTOR_CC_FAMILY;
    motor.model  = MOTOR_MODEL_CC;
    motor.minimum_speed_value = MCC_MINIMUM_SPEED;
    motor.maximum_speed_value = MCC_MAXIMUM_SPEED;
    
    motor.maximum_accel_slope_coeff = MCC_ACCEL_SLOPE_COEFF;
    motor.maximum_decel_slope_coeff = MCC_DECEL_SLOPE_COEFF;
    
    motor.motor_vbat[0].vbat_value = MCC_VBAT_VALUE0;
    motor.motor_vbat[1].vbat_value = MCC_VBAT_VALUE1;
    motor.motor_vbat[2].vbat_value = MCC_VBAT_VALUE2;
    motor.motor_vbat[3].vbat_value = MCC_VBAT_VALUE3;
    
    motor.motor_vbat[1].coeff_a = (MCC_VBAT_COEFF0  - MCC_VBAT_COEFF1) / (MCC_VBAT_VALUE0-MCC_VBAT_VALUE1);
    motor.motor_vbat[1].coeff_b = (MCC_VBAT_COEFF0) - (motor.motor_vbat[1].coeff_a*MCC_VBAT_VALUE0);
    
    motor.motor_vbat[2].coeff_a = (MCC_VBAT_COEFF1  - MCC_VBAT_COEFF2) / (MCC_VBAT_VALUE1-MCC_VBAT_VALUE2);
    motor.motor_vbat[2].coeff_b = (MCC_VBAT_COEFF1) - (motor.motor_vbat[2].coeff_a*MCC_VBAT_VALUE1);
    
    motor.motor_vbat[3].coeff_a = (MCC_VBAT_COEFF2  - MCC_VBAT_COEFF3) / (MCC_VBAT_VALUE2-MCC_VBAT_VALUE3);
    motor.motor_vbat[3].coeff_b = (MCC_VBAT_COEFF2) - (motor.motor_vbat[3].coeff_a*MCC_VBAT_VALUE2);
    
    
    motor.error_mode.init_phase_list[0].motorh_mode_dir   = ERROR_MCC_MOTORH_TABLE;
    motor.error_mode.init_phase_list[0].motorh_speed      = ERROR_MCC_MOTORH_SPEED;
    motor.error_mode.init_phase_list[0].motorh_slope      = ERROR_MCC_MOTORH_SLOPE;
    motor.error_mode.init_phase_list[0].motorl_mode_dir   = ERROR_MCC_MOTORL_TABLE;
    motor.error_mode.init_phase_list[0].motorl_speed      = ERROR_MCC_MOTORL_SPEED;
    motor.error_mode.init_phase_list[0].motorl_slope      = ERROR_MCC_MOTORL_SLOPE;
    
    
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
    motor.manual_mode.manual_enrh_phase_list[0].motorh_mode_dir   = MANUAL_MCC_ENRH_0_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[0].motorh_speed      = MANUAL_MCC_ENRH_0_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[0].motorh_slope      = MANUAL_MCC_ENRH_0_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_mode_dir   = MANUAL_MCC_ENRH_0_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_speed      = MANUAL_MCC_ENRH_0_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[0].motorl_slope      = MANUAL_MCC_ENRH_0_MOTORL_SLOPE;
    
    // ENRH : 1 = STANDBY
    motor.manual_mode.manual_enrh_phase_list[1].motorh_mode_dir   = MANUAL_MCC_ENRH_1_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[1].motorh_speed      = MANUAL_MCC_ENRH_1_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[1].motorh_slope      = MANUAL_MCC_ENRH_1_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_mode_dir   = MANUAL_MCC_ENRH_1_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_speed      = MANUAL_MCC_ENRH_1_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[1].motorl_slope      = MANUAL_MCC_ENRH_1_MOTORL_SLOPE;
    
    // ENRH : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_enrh_phase_list[2].motorh_mode_dir   = MANUAL_MCC_ENRH_2_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[2].motorh_speed      = MANUAL_MCC_ENRH_2_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[2].motorh_slope      = MANUAL_MCC_ENRH_2_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_mode_dir   = MANUAL_MCC_ENRH_2_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_speed      = MANUAL_MCC_ENRH_2_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[2].motorl_slope      = MANUAL_MCC_ENRH_2_MOTORL_SLOPE;
    
    // ENRH : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_enrh_phase_list[3].motorh_mode_dir   = MANUAL_MCC_ENRH_3_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[3].motorh_speed      = MANUAL_MCC_ENRH_3_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[3].motorh_slope      = MANUAL_MCC_ENRH_3_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_mode_dir   = MANUAL_MCC_ENRH_3_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_speed      = MANUAL_MCC_ENRH_3_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[3].motorl_slope      = MANUAL_MCC_ENRH_3_MOTORL_SLOPE;
    
    // ENRH : 4 = TENSION AFFICHE
    motor.manual_mode.manual_enrh_phase_list[4].motorh_mode_dir   = MANUAL_MCC_ENRH_4_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[4].motorh_speed      = MANUAL_MCC_ENRH_4_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[4].motorh_slope      = MANUAL_MCC_ENRH_4_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_mode_dir   = MANUAL_MCC_ENRH_4_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_speed      = MANUAL_MCC_ENRH_4_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[4].motorl_slope      = MANUAL_MCC_ENRH_4_MOTORL_SLOPE;
    
    // ENRH : 5 = ARRET
    motor.manual_mode.manual_enrh_phase_list[5].motorh_mode_dir   = MANUAL_MCC_ENRH_5_MOTORH_TABLE;
    motor.manual_mode.manual_enrh_phase_list[5].motorh_speed      = MANUAL_MCC_ENRH_5_MOTORH_SPEED;
    motor.manual_mode.manual_enrh_phase_list[5].motorh_slope      = MANUAL_MCC_ENRH_5_MOTORH_SLOPE;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_mode_dir   = MANUAL_MCC_ENRH_5_MOTORL_TABLE;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_speed      = MANUAL_MCC_ENRH_5_MOTORL_SPEED;
    motor.manual_mode.manual_enrh_phase_list[5].motorl_slope      = MANUAL_MCC_ENRH_5_MOTORL_SLOPE;
    
    //-------------------------------------------------------------------------------------------------------------------
    // ENRL
    //-------------------------------------------------------------------------------------------------------------------
    
    // ENRL : 0 = OFF
    motor.manual_mode.manual_enrl_phase_list[0].motorh_mode_dir   = MANUAL_MCC_ENRL_0_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[0].motorh_speed      = MANUAL_MCC_ENRL_0_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[0].motorh_slope      = MANUAL_MCC_ENRL_0_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_mode_dir   = MANUAL_MCC_ENRL_0_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_speed      = MANUAL_MCC_ENRL_0_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[0].motorl_slope      = MANUAL_MCC_ENRL_0_MOTORL_SLOPE;
    
    // ENRL : 1 = STANDBY
    motor.manual_mode.manual_enrl_phase_list[1].motorh_mode_dir   = MANUAL_MCC_ENRL_1_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[1].motorh_speed      = MANUAL_MCC_ENRL_1_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[1].motorh_slope      = MANUAL_MCC_ENRL_1_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_mode_dir   = MANUAL_MCC_ENRL_1_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_speed      = MANUAL_MCC_ENRL_1_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[1].motorl_slope      = MANUAL_MCC_ENRL_1_MOTORL_SLOPE;
    
    // ENRL : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_enrl_phase_list[2].motorh_mode_dir   = MANUAL_MCC_ENRL_2_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[2].motorh_speed      = MANUAL_MCC_ENRL_2_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[2].motorh_slope      = MANUAL_MCC_ENRL_2_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_mode_dir   = MANUAL_MCC_ENRL_2_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_speed      = MANUAL_MCC_ENRL_2_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[2].motorl_slope      = MANUAL_MCC_ENRL_2_MOTORL_SLOPE;
    
    // ENRL : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_enrl_phase_list[3].motorh_mode_dir   = MANUAL_MCC_ENRL_3_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[3].motorh_speed      = MANUAL_MCC_ENRL_3_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[3].motorh_slope      = MANUAL_MCC_ENRL_3_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_mode_dir   = MANUAL_MCC_ENRL_3_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_speed      = MANUAL_MCC_ENRL_3_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[3].motorl_slope      = MANUAL_MCC_ENRL_3_MOTORL_SLOPE;
    
    // ENRL : 4 = TENSION AFFICHE
    motor.manual_mode.manual_enrl_phase_list[4].motorh_mode_dir   = MANUAL_MCC_ENRL_4_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[4].motorh_speed      = MANUAL_MCC_ENRL_4_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[4].motorh_slope      = MANUAL_MCC_ENRL_4_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_mode_dir   = MANUAL_MCC_ENRL_4_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_speed      = MANUAL_MCC_ENRL_4_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[4].motorl_slope      = MANUAL_MCC_ENRL_4_MOTORL_SLOPE;
    
    // ENRL : 5 = ARRET
    motor.manual_mode.manual_enrl_phase_list[5].motorh_mode_dir   = MANUAL_MCC_ENRL_5_MOTORH_TABLE;
    motor.manual_mode.manual_enrl_phase_list[5].motorh_speed      = MANUAL_MCC_ENRL_5_MOTORH_SPEED;
    motor.manual_mode.manual_enrl_phase_list[5].motorh_slope      = MANUAL_MCC_ENRL_5_MOTORH_SLOPE;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_mode_dir   = MANUAL_MCC_ENRL_5_MOTORL_TABLE;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_speed      = MANUAL_MCC_ENRL_5_MOTORL_SPEED;
    motor.manual_mode.manual_enrl_phase_list[5].motorl_slope      = MANUAL_MCC_ENRL_5_MOTORL_SLOPE;
    
    //-------------------------------------------------------------------------------------------------------------------
    // DERH
    //-------------------------------------------------------------------------------------------------------------------
    
    // DERH : 0 = OFF
    motor.manual_mode.manual_derh_phase_list[0].motorh_mode_dir   = MANUAL_MCC_DERH_0_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[0].motorh_speed      = MANUAL_MCC_DERH_0_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[0].motorh_slope      = MANUAL_MCC_DERH_0_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[0].motorl_mode_dir   = MANUAL_MCC_DERH_0_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[0].motorl_speed      = MANUAL_MCC_DERH_0_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[0].motorl_slope      = MANUAL_MCC_DERH_0_MOTORL_SLOPE;
    
    // DERH : 1 = STANDBY
    motor.manual_mode.manual_derh_phase_list[1].motorh_mode_dir   = MANUAL_MCC_DERH_1_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[1].motorh_speed      = MANUAL_MCC_DERH_1_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[1].motorh_slope      = MANUAL_MCC_DERH_1_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[1].motorl_mode_dir   = MANUAL_MCC_DERH_1_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[1].motorl_speed      = MANUAL_MCC_DERH_1_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[1].motorl_slope      = MANUAL_MCC_DERH_1_MOTORL_SLOPE;
    
    // DERH : 2 = RAMPE ACCELERATION
    motor.manual_mode.manual_derh_phase_list[2].motorh_mode_dir   = MANUAL_MCC_DERH_2_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[2].motorh_speed      = MANUAL_MCC_DERH_2_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[2].motorh_slope      = MANUAL_MCC_DERH_2_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[2].motorl_mode_dir   = MANUAL_MCC_DERH_2_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[2].motorl_speed      = MANUAL_MCC_DERH_2_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[2].motorl_slope      = MANUAL_MCC_DERH_2_MOTORL_SLOPE;
    
    // DERH : 3 = RAMPE DECELERATION
    motor.manual_mode.manual_derh_phase_list[3].motorh_mode_dir   = MANUAL_MCC_DERH_3_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[3].motorh_speed      = MANUAL_MCC_DERH_3_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[3].motorh_slope      = MANUAL_MCC_DERH_3_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[3].motorl_mode_dir   = MANUAL_MCC_DERH_3_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[3].motorl_speed      = MANUAL_MCC_DERH_3_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[3].motorl_slope      = MANUAL_MCC_DERH_3_MOTORL_SLOPE;
    
    // DERH : 4 = TENSION AFFICHE
    motor.manual_mode.manual_derh_phase_list[4].motorh_mode_dir   = MANUAL_MCC_DERH_4_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[4].motorh_speed      = MANUAL_MCC_DERH_4_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[4].motorh_slope      = MANUAL_MCC_DERH_4_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[4].motorl_mode_dir   = MANUAL_MCC_DERH_4_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[4].motorl_speed      = MANUAL_MCC_DERH_4_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[4].motorl_slope      = MANUAL_MCC_DERH_4_MOTORL_SLOPE;
    
    // DERH : 5 = ARRET
    motor.manual_mode.manual_derh_phase_list[5].motorh_mode_dir   = MANUAL_MCC_DERH_5_MOTORH_TABLE;
    motor.manual_mode.manual_derh_phase_list[5].motorh_speed      = MANUAL_MCC_DERH_5_MOTORH_SPEED;
    motor.manual_mode.manual_derh_phase_list[5].motorh_slope      = MANUAL_MCC_DERH_5_MOTORH_SLOPE;
    motor.manual_mode.manual_derh_phase_list[5].motorl_mode_dir   = MANUAL_MCC_DERH_5_MOTORL_TABLE;
    motor.manual_mode.manual_derh_phase_list[5].motorl_speed      = MANUAL_MCC_DERH_5_MOTORL_SPEED;
    motor.manual_mode.manual_derh_phase_list[5].motorl_slope      = MANUAL_MCC_DERH_5_MOTORL_SLOPE;
         
    
    
    
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    // MODE INIT
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    motor.init_mode.cell_inhib_time_bm                   = INIT_MCC_CELL_INHIB_TIME_BM;
    motor.init_mode.cell_inhib_time_pastille             = INIT_MCC_CELL_INHIB_TIME_PASTILLE;
    motor.init_mode.cell_timeout_time                    = INIT_MCC_CELL_TIMEOUT_TIME;
    motor.init_mode.init_cell_decr_speed                 = INIT_MCC_CELL_DECR_SPEED;
    motor.init_mode.init_cell_decr_slope                 = INIT_MCC_CELL_DECR_SLOPE;
    
    motor.init_mode.init_phase_list[0].motorh_mode_dir   = INIT_MCC_START_CELL_MOTORH_DIR;
    motor.init_mode.init_phase_list[0].motorh_speed      = INIT_MCC_START_CELL_MOTORH_SPEED;
    motor.init_mode.init_phase_list[0].motorh_slope      = INIT_MCC_START_CELL_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[0].motorh_adjust_vbat= INIT_MCC_START_CELL_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[0].motorl_mode_dir   = INIT_MCC_START_CELL_MOTORL_DIR;
    motor.init_mode.init_phase_list[0].motorl_speed      = INIT_MCC_START_CELL_MOTORL_SPEED;
    motor.init_mode.init_phase_list[0].motorl_slope      = INIT_MCC_START_CELL_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[0].motorl_adjust_vbat= INIT_MCC_START_CELL_MOTORL_ADJUST_VBAT;
    
    // 1: petite rampe vers tension affiche
    motor.init_mode.init_phase_list[1].motorh_mode_dir   = INIT_MCC_1_MOTORH_DIR;
    motor.init_mode.init_phase_list[1].motorh_speed      = INIT_MCC_1_MOTORH_SPEED;
    motor.init_mode.init_phase_list[1].motorh_slope      = INIT_MCC_1_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[1].motorh_adjust_vbat= INIT_MCC_1_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[1].motorl_mode_dir   = INIT_MCC_1_MOTORL_DIR;
    motor.init_mode.init_phase_list[1].motorl_speed      = INIT_MCC_1_MOTORL_SPEED;
    motor.init_mode.init_phase_list[1].motorl_slope      = INIT_MCC_1_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[1].motorl_adjust_vbat= INIT_MCC_1_MOTORL_ADJUST_VBAT;
    
    // 2: tension affiche pendant plusieurs secondes
    motor.init_mode.init_phase_list[2].motorh_mode_dir   = INIT_MCC_2_MOTORH_DIR;
    motor.init_mode.init_phase_list[2].motorh_speed      = INIT_MCC_2_MOTORH_SPEED;
    motor.init_mode.init_phase_list[2].motorh_slope      = INIT_MCC_2_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[2].motorh_adjust_vbat= INIT_MCC_2_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[2].motorl_mode_dir   = INIT_MCC_2_MOTORL_DIR;
    motor.init_mode.init_phase_list[2].motorl_speed      = INIT_MCC_2_MOTORL_SPEED;
    motor.init_mode.init_phase_list[2].motorl_slope      = INIT_MCC_2_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[2].motorl_adjust_vbat= INIT_MCC_2_MOTORL_ADJUST_VBAT;
    
    // 3: rampe acceleration sur moteur du haut pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[3].motorh_mode_dir   = INIT_MCC_3_MOTORH_DIR;
    motor.init_mode.init_phase_list[3].motorh_speed      = INIT_MCC_3_MOTORH_SPEED;
    motor.init_mode.init_phase_list[3].motorh_slope      = INIT_MCC_3_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[3].motorh_adjust_vbat= INIT_MCC_3_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[3].motorl_mode_dir   = INIT_MCC_3_MOTORL_DIR;
    motor.init_mode.init_phase_list[3].motorl_speed      = INIT_MCC_3_MOTORL_SPEED;
    motor.init_mode.init_phase_list[3].motorl_slope      = INIT_MCC_3_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[3].motorl_adjust_vbat= INIT_MCC_3_MOTORL_ADJUST_VBAT;
    
    // 4: rampe deceleration sur moteur du haut s'arreter sur la BM basse
    motor.init_mode.init_phase_list[4].motorh_mode_dir   = INIT_MCC_4_MOTORH_DIR;
    motor.init_mode.init_phase_list[4].motorh_speed      = INIT_MCC_4_MOTORH_SPEED;
    motor.init_mode.init_phase_list[4].motorh_slope      = INIT_MCC_4_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[4].motorh_adjust_vbat= INIT_MCC_4_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[4].motorl_mode_dir   = INIT_MCC_4_MOTORL_DIR;
    motor.init_mode.init_phase_list[4].motorl_speed      = INIT_MCC_4_MOTORL_SPEED;
    motor.init_mode.init_phase_list[4].motorl_slope      = INIT_MCC_4_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[4].motorl_adjust_vbat= INIT_MCC_4_MOTORL_ADJUST_VBAT;
    
    // 5: attente sur la BM basse
    motor.init_mode.init_phase_list[5].motorh_mode_dir   = INIT_MCC_5_MOTORH_DIR;
    motor.init_mode.init_phase_list[5].motorh_speed      = INIT_MCC_5_MOTORH_SPEED;
    motor.init_mode.init_phase_list[5].motorh_slope      = INIT_MCC_5_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[5].motorh_adjust_vbat= INIT_MCC_5_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[5].motorl_mode_dir   = INIT_MCC_5_MOTORL_DIR;
    motor.init_mode.init_phase_list[5].motorl_speed      = INIT_MCC_5_MOTORL_SPEED;
    motor.init_mode.init_phase_list[5].motorl_slope      = INIT_MCC_5_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[5].motorl_adjust_vbat= INIT_MCC_5_MOTORL_ADJUST_VBAT;
    
    // 6: rampe acceleration sur moteur du bas pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[6].motorh_mode_dir   = INIT_MCC_6_MOTORH_DIR;
    motor.init_mode.init_phase_list[6].motorh_speed      = INIT_MCC_6_MOTORH_SPEED;
    motor.init_mode.init_phase_list[6].motorh_slope      = INIT_MCC_6_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[6].motorh_adjust_vbat= INIT_MCC_6_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[6].motorl_mode_dir   = INIT_MCC_6_MOTORL_DIR;
    motor.init_mode.init_phase_list[6].motorl_speed      = INIT_MCC_6_MOTORL_SPEED;
    motor.init_mode.init_phase_list[6].motorl_slope      = INIT_MCC_6_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[6].motorl_adjust_vbat= INIT_MCC_6_MOTORL_ADJUST_VBAT;
    
    // 7: rampe deceleration sur moteur du bas s'arreter sur la BM haute
    motor.init_mode.init_phase_list[7].motorh_mode_dir   = INIT_MCC_7_MOTORH_DIR;
    motor.init_mode.init_phase_list[7].motorh_speed      = INIT_MCC_7_MOTORH_SPEED;
    motor.init_mode.init_phase_list[7].motorh_slope      = INIT_MCC_7_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[7].motorh_adjust_vbat= INIT_MCC_7_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[7].motorl_mode_dir   = INIT_MCC_7_MOTORL_DIR;
    motor.init_mode.init_phase_list[7].motorl_speed      = INIT_MCC_7_MOTORL_SPEED;
    motor.init_mode.init_phase_list[7].motorl_slope      = INIT_MCC_7_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[7].motorl_adjust_vbat= INIT_MCC_7_MOTORL_ADJUST_VBAT;
    
    // 8: attente sur la BM haute
    motor.init_mode.init_phase_list[8].motorh_mode_dir   = INIT_MCC_8_MOTORH_DIR;
    motor.init_mode.init_phase_list[8].motorh_speed      = INIT_MCC_8_MOTORH_SPEED;
    motor.init_mode.init_phase_list[8].motorh_slope      = INIT_MCC_8_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[8].motorh_adjust_vbat= INIT_MCC_8_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[8].motorl_mode_dir   = INIT_MCC_8_MOTORL_DIR;
    motor.init_mode.init_phase_list[8].motorl_speed      = INIT_MCC_8_MOTORL_SPEED;
    motor.init_mode.init_phase_list[8].motorl_slope      = INIT_MCC_8_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[8].motorl_adjust_vbat= INIT_MCC_8_MOTORL_ADJUST_VBAT;
    
    // 9: rampe acceleration sur moteur du haut pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[9].motorh_mode_dir   = INIT_MCC_9_MOTORH_DIR;
    motor.init_mode.init_phase_list[9].motorh_speed      = INIT_MCC_9_MOTORH_SPEED;
    motor.init_mode.init_phase_list[9].motorh_slope      = INIT_MCC_9_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[9].motorh_adjust_vbat= INIT_MCC_9_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[9].motorl_mode_dir   = INIT_MCC_9_MOTORL_DIR;
    motor.init_mode.init_phase_list[9].motorl_speed      = INIT_MCC_9_MOTORL_SPEED;
    motor.init_mode.init_phase_list[9].motorl_slope      = INIT_MCC_9_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[9].motorl_adjust_vbat= INIT_MCC_9_MOTORH_ADJUST_VBAT;
    
    // 10: grande vitesse
    motor.init_mode.init_full_speed_time                  = INIT_MCC_FULL_SPEED_TIME;     
    
    
    // 10: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase1
    motor.init_mode.init_phase_list[10].motorh_mode_dir   = INIT_MCC_10_MOTORH_DIR;
    motor.init_mode.init_phase_list[10].motorh_speed      = INIT_MCC_10_MOTORH_SPEED;
    motor.init_mode.init_phase_list[10].motorh_slope      = INIT_MCC_10_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[10].motorh_adjust_vbat= INIT_MCC_10_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[10].motorl_mode_dir   = INIT_MCC_10_MOTORL_DIR;
    motor.init_mode.init_phase_list[10].motorl_speed      = INIT_MCC_10_MOTORL_SPEED;
    motor.init_mode.init_phase_list[10].motorl_slope      = INIT_MCC_10_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[10].motorl_adjust_vbat= INIT_MCC_10_MOTORL_ADJUST_VBAT;
    
    // 11: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase2
    motor.init_mode.init_phase_list[11].motorh_mode_dir   = INIT_MCC_11_MOTORH_DIR;
    motor.init_mode.init_phase_list[11].motorh_speed      = INIT_MCC_11_MOTORH_SPEED;
    motor.init_mode.init_phase_list[11].motorh_slope      = INIT_MCC_11_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[11].motorh_adjust_vbat= INIT_MCC_11_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[11].motorl_mode_dir   = INIT_MCC_11_MOTORL_DIR;
    motor.init_mode.init_phase_list[11].motorl_speed      = INIT_MCC_11_MOTORL_SPEED;
    motor.init_mode.init_phase_list[11].motorl_slope      = INIT_MCC_11_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[11].motorl_adjust_vbat= INIT_MCC_11_MOTORL_ADJUST_VBAT;
    
    // 12: rampe deceleration sur moteur du haut pour s'arreter sur la pastille
    motor.init_mode.init_phase_list[12].motorh_mode_dir   = INIT_MCC_12_MOTORH_DIR;
    motor.init_mode.init_phase_list[12].motorh_speed      = INIT_MCC_12_MOTORH_SPEED;
    motor.init_mode.init_phase_list[12].motorh_slope      = INIT_MCC_12_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[12].motorh_adjust_vbat= INIT_MCC_12_MOTORH_ADJUST_VBAT;
    motor.init_mode.init_phase_list[12].motorl_mode_dir   = INIT_MCC_12_MOTORL_DIR;
    motor.init_mode.init_phase_list[12].motorl_speed      = INIT_MCC_12_MOTORL_SPEED;
    motor.init_mode.init_phase_list[12].motorl_slope      = INIT_MCC_12_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[12].motorl_adjust_vbat= INIT_MCC_12_MOTORL_ADJUST_VBAT;
    motor.init_mode.init_phase_list[12].brake_override    = INIT_MCC_12_BRAKE_OVERRIDE;
    
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
    motor.preauto_auto.preauto_enrh_full_speed_time       = AUTO_MCC_ENRH_FULL_SPEED_TIME;
    motor.preauto_auto.preauto_enrl_full_speed_time       = AUTO_MCC_ENRL_FULL_SPEED_TIME;
    
    motor.preauto_auto.cell_inhib_time_bm                 = AUTO_MCC_CELL_TIMEOUT_TIME;
    motor.preauto_auto.cell_inhib_time_pastille           = AUTO_MCC_CELL_INHIB_TIME_PASTILLE;
    motor.preauto_auto.cell_inhib_time_bm                 = AUTO_MCC_CELL_INHIB_TIME_BM;
    motor.preauto_auto.cell_timeout_time                  = AUTO_MCC_CELL_TIMEOUT_TIME;
    
    motor.preauto_auto.enrh_dock_speed                    = AUTO_MCC_ENRH_DOCK_SPEED;
    motor.preauto_auto.enrl_dock_speed                    = AUTO_MCC_ENRL_DOCK_SPEED;
    
    
    
    //ENRH
    motor.preauto_auto.enrh_phase_list[0].motorh_mode_dir    = AUTO_MCC_1_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorh_speed       = AUTO_MCC_1_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorh_slope       = AUTO_MCC_1_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorh_adjust_vbat = AUTO_MCC_1_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[0].motorl_mode_dir    = AUTO_MCC_1_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorl_speed       = AUTO_MCC_1_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorl_slope       = AUTO_MCC_1_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorl_adjust_vbat = AUTO_MCC_1_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrh_phase_list[1].motorh_mode_dir    = AUTO_MCC_ENRH_2_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorh_speed       = AUTO_MCC_ENRH_2_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorh_slope       = AUTO_MCC_ENRH_2_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorh_adjust_vbat = AUTO_MCC_ENRH_2_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[1].motorl_mode_dir    = AUTO_MCC_ENRH_2_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorl_speed       = AUTO_MCC_ENRH_2_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorl_slope       = AUTO_MCC_ENRH_2_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorl_adjust_vbat = AUTO_MCC_ENRH_2_MOTORL_ADJUST_VBAT;
    
    
    motor.preauto_auto.enrh_phase_list[2].motorh_mode_dir    = AUTO_MCC_ENRH_3_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorh_speed       = AUTO_MCC_ENRH_3_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorh_slope       = AUTO_MCC_ENRH_3_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorh_adjust_vbat = AUTO_MCC_ENRH_3_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[2].motorl_mode_dir    = AUTO_MCC_ENRH_3_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorl_speed       = AUTO_MCC_ENRH_3_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorl_slope       = AUTO_MCC_ENRH_3_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorl_adjust_vbat = AUTO_MCC_ENRH_3_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrh_phase_list[3].motorh_mode_dir    = AUTO_MCC_ENRH_4_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorh_speed       = AUTO_MCC_ENRH_4_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorh_slope       = AUTO_MCC_ENRH_4_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorh_adjust_vbat = AUTO_MCC_ENRH_4_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[3].motorl_mode_dir    = AUTO_MCC_ENRH_4_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorl_speed       = AUTO_MCC_ENRH_4_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorl_slope       = AUTO_MCC_ENRH_4_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorl_adjust_vbat = AUTO_MCC_ENRH_4_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrh_phase_list[4].motorh_mode_dir    = AUTO_MCC_ENRH_5_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorh_speed       = AUTO_MCC_ENRH_5_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorh_slope       = AUTO_MCC_ENRH_5_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorh_adjust_vbat = AUTO_MCC_ENRH_5_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[4].motorl_mode_dir    = AUTO_MCC_ENRH_5_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorl_speed       = AUTO_MCC_ENRH_5_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorl_slope       = AUTO_MCC_ENRH_5_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorl_adjust_vbat = AUTO_MCC_ENRH_5_MOTORL_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[4].brake_override     = AUTO_MCC_ENRH_5_BRAKE_OVERRIDE;
    
    
    motor.preauto_auto.enrh_phase_list[5].motorh_mode_dir    = AUTO_MCC_ENRH_6_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorh_speed       = AUTO_MCC_ENRH_6_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorh_slope       = AUTO_MCC_ENRH_6_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorh_adjust_vbat = AUTO_MCC_ENRH_6_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[5].motorl_mode_dir    = AUTO_MCC_ENRH_6_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorl_speed       = AUTO_MCC_ENRH_6_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorl_slope       = AUTO_MCC_ENRH_6_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorl_adjust_vbat = AUTO_MCC_ENRH_6_MOTORL_ADJUST_VBAT;
    motor.preauto_auto.enrh_phase_list[5].brake_override     = AUTO_MCC_ENRH_6_BRAKE_OVERRIDE;
    
    
    //ENRL
    motor.preauto_auto.enrl_phase_list[0].motorh_mode_dir    = AUTO_MCC_1_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorh_speed       = AUTO_MCC_1_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorh_slope       = AUTO_MCC_1_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorh_adjust_vbat = AUTO_MCC_1_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[0].motorl_mode_dir    = AUTO_MCC_1_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorl_speed       = AUTO_MCC_1_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorl_slope       = AUTO_MCC_1_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorl_adjust_vbat = AUTO_MCC_1_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrl_phase_list[1].motorh_mode_dir    = AUTO_MCC_ENRL_2_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorh_speed       = AUTO_MCC_ENRL_2_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorh_slope       = AUTO_MCC_ENRL_2_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorh_adjust_vbat = AUTO_MCC_ENRL_2_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[1].motorl_mode_dir    = AUTO_MCC_ENRL_2_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorl_speed       = AUTO_MCC_ENRL_2_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorl_slope       = AUTO_MCC_ENRL_2_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorl_adjust_vbat = AUTO_MCC_ENRL_2_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrl_phase_list[2].motorh_mode_dir    = AUTO_MCC_ENRL_3_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorh_speed       = AUTO_MCC_ENRL_3_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorh_slope       = AUTO_MCC_ENRL_3_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorh_adjust_vbat = AUTO_MCC_ENRL_3_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[2].motorl_mode_dir    = AUTO_MCC_ENRL_3_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorl_speed       = AUTO_MCC_ENRL_3_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorl_slope       = AUTO_MCC_ENRL_3_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorl_adjust_vbat = AUTO_MCC_ENRL_3_MOTORL_ADJUST_VBAT;
    
    motor.preauto_auto.enrl_phase_list[3].motorh_mode_dir    = AUTO_MCC_ENRL_4_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorh_speed       = AUTO_MCC_ENRL_4_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorh_slope       = AUTO_MCC_ENRL_4_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorh_adjust_vbat = AUTO_MCC_ENRL_4_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[3].motorl_mode_dir    = AUTO_MCC_ENRL_4_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorl_speed       = AUTO_MCC_ENRL_4_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorl_slope       = AUTO_MCC_ENRL_4_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorl_adjust_vbat = AUTO_MCC_ENRL_4_MOTORL_ADJUST_VBAT;
    
    
    motor.preauto_auto.enrl_phase_list[4].motorh_mode_dir    = AUTO_MCC_ENRL_5_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorh_speed       = AUTO_MCC_ENRL_5_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorh_slope       = AUTO_MCC_ENRL_5_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorh_adjust_vbat = AUTO_MCC_ENRL_5_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[4].motorl_mode_dir    = AUTO_MCC_ENRL_5_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorl_speed       = AUTO_MCC_ENRL_5_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorl_slope       = AUTO_MCC_ENRL_5_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorl_adjust_vbat = AUTO_MCC_ENRL_5_MOTORL_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[4].brake_override     = AUTO_MCC_ENRL_5_BRAKE_OVERRIDE;
    
    
    motor.preauto_auto.enrl_phase_list[5].motorh_mode_dir    = AUTO_MCC_ENRL_6_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorh_speed       = AUTO_MCC_ENRL_6_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorh_slope       = AUTO_MCC_ENRL_6_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorh_adjust_vbat = AUTO_MCC_ENRL_6_MOTORH_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[5].motorl_mode_dir    = AUTO_MCC_ENRL_6_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorl_speed       = AUTO_MCC_ENRL_6_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorl_slope       = AUTO_MCC_ENRL_6_MOTORL_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorl_adjust_vbat = AUTO_MCC_ENRL_6_MOTORL_ADJUST_VBAT;
    motor.preauto_auto.enrl_phase_list[5].brake_override     = AUTO_MCC_ENRL_6_BRAKE_OVERRIDE;
    
    
}
