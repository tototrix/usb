#include <_Global_Include.h>


void motor_set_model_alcom110(void)
{
    
     motor.enrh_speed_adjust = ALCOM110_ENRH_DOCK_SPEED_ADJUST;
     motor.enrl_speed_adjust = ALCOM110_ENRL_DOCK_SPEED_ADJUST;
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

    
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
    // MODE INIT
    //===================================================================================================================
    //===================================================================================================================
    //===================================================================================================================
     
     // 9: rampe acceleration sur moteur du haut pour atteindre la grande vitesse
    motor.init_mode.init_phase_list[9].motorh_mode_dir   = INIT_ALCOM110_9_MOTORH_DIR;
    motor.init_mode.init_phase_list[9].motorh_speed      = INIT_ALCOM110_9_MOTORH_SPEED;
    motor.init_mode.init_phase_list[9].motorh_slope      = INIT_ALCOM110_9_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[9].motorl_mode_dir   = INIT_ALCOM110_9_MOTORL_DIR;
    motor.init_mode.init_phase_list[9].motorl_speed      = INIT_ALCOM110_9_MOTORL_SPEED;
    motor.init_mode.init_phase_list[9].motorl_slope      = INIT_ALCOM110_9_MOTORL_SLOPE;
    
    // 10: grande vitesse
    motor.init_mode.init_full_speed_time                 = INIT_ALCOM110_FULL_SPEED_TIME;
    
    
    
    // 10: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase1
    motor.init_mode.init_phase_list[10].motorh_mode_dir   = INIT_ALCOM110_10_MOTORH_DIR;
    motor.init_mode.init_phase_list[10].motorh_speed      = INIT_ALCOM110_10_MOTORH_SPEED;
    motor.init_mode.init_phase_list[10].motorh_slope      = INIT_ALCOM110_10_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[10].motorl_mode_dir   = INIT_ALCOM110_10_MOTORL_DIR;
    motor.init_mode.init_phase_list[10].motorl_speed      = INIT_ALCOM110_10_MOTORL_SPEED;
    motor.init_mode.init_phase_list[10].motorl_slope      = INIT_ALCOM110_10_MOTORL_SLOPE;
    
    
    // 11: rampe deceleration sur moteur du haut pour atteindre la petite vitesse - phase2
    motor.init_mode.init_phase_list[11].motorh_mode_dir   = INIT_ALCOM110_11_MOTORH_DIR;
    motor.init_mode.init_phase_list[11].motorh_speed      = INIT_ALCOM110_11_MOTORH_SPEED;
    motor.init_mode.init_phase_list[11].motorh_slope      = INIT_ALCOM110_11_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[11].motorl_mode_dir   = INIT_ALCOM110_11_MOTORL_DIR;
    motor.init_mode.init_phase_list[11].motorl_speed      = INIT_ALCOM110_11_MOTORL_SPEED;
    motor.init_mode.init_phase_list[11].motorl_slope      = INIT_ALCOM110_11_MOTORL_SLOPE;
    
    
    // 12: rampe deceleration sur moteur du haut pour s'arreter sur la pastille
    motor.init_mode.init_phase_list[12].motorh_mode_dir   = INIT_ALCOM110_12_MOTORH_DIR;
    motor.init_mode.init_phase_list[12].motorh_speed      = INIT_ALCOM110_12_MOTORH_SPEED;
    motor.init_mode.init_phase_list[12].motorh_slope      = INIT_ALCOM110_12_MOTORH_SLOPE;
    motor.init_mode.init_phase_list[12].motorl_mode_dir   = INIT_ALCOM110_12_MOTORL_DIR;
    motor.init_mode.init_phase_list[12].motorl_speed      = INIT_ALCOM110_12_MOTORL_SPEED;
    motor.init_mode.init_phase_list[12].motorl_slope      = INIT_ALCOM110_12_MOTORL_SLOPE;
    motor.init_mode.init_phase_list[12].brake_override    = INIT_ALCOM110_12_BRAKE_OVERRIDE;
    
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
    motor.preauto_auto.preauto_enrh_full_speed_time       = AUTO_ALCOM110_ENRH_FULL_SPEED_TIME;
    motor.preauto_auto.preauto_enrl_full_speed_time       = AUTO_ALCOM110_ENRL_FULL_SPEED_TIME;
    
    
    //ENRH
    motor.preauto_auto.enrh_phase_list[0].motorh_mode_dir = AUTO_ALCOM110_1_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorh_speed    = AUTO_ALCOM110_1_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorh_slope    = AUTO_ALCOM110_1_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[0].motorl_mode_dir = AUTO_ALCOM110_1_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[0].motorl_speed    = AUTO_ALCOM110_1_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[0].motorl_slope    = AUTO_ALCOM110_1_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[1].motorh_mode_dir = AUTO_ALCOM110_ENRH_2_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorh_speed    = AUTO_ALCOM110_ENRH_2_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorh_slope    = AUTO_ALCOM110_ENRH_2_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[1].motorl_mode_dir = AUTO_ALCOM110_ENRH_2_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[1].motorl_speed    = AUTO_ALCOM110_ENRH_2_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[1].motorl_slope    = AUTO_ALCOM110_ENRH_2_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[2].motorh_mode_dir = AUTO_ALCOM110_ENRH_3_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorh_speed    = AUTO_ALCOM110_ENRH_3_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorh_slope    = AUTO_ALCOM110_ENRH_3_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[2].motorl_mode_dir = AUTO_ALCOM110_ENRH_3_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[2].motorl_speed    = AUTO_ALCOM110_ENRH_3_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[2].motorl_slope    = AUTO_ALCOM110_ENRH_3_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[3].motorh_mode_dir = AUTO_ALCOM110_ENRH_4_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorh_speed    = AUTO_ALCOM110_ENRH_4_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorh_slope    = AUTO_ALCOM110_ENRH_4_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[3].motorl_mode_dir = AUTO_ALCOM110_ENRH_4_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[3].motorl_speed    = AUTO_ALCOM110_ENRH_4_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[3].motorl_slope    = AUTO_ALCOM110_ENRH_4_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[4].motorh_mode_dir = AUTO_ALCOM110_ENRH_5_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorh_speed    = AUTO_ALCOM110_ENRH_5_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorh_slope    = AUTO_ALCOM110_ENRH_5_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[4].motorl_mode_dir = AUTO_ALCOM110_ENRH_5_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[4].motorl_speed    = AUTO_ALCOM110_ENRH_5_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[4].motorl_slope    = AUTO_ALCOM110_ENRH_5_MOTORL_SLOPE;
    
    motor.preauto_auto.enrh_phase_list[5].motorh_mode_dir = AUTO_ALCOM110_ENRH_6_MOTORH_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorh_speed    = AUTO_ALCOM110_ENRH_6_MOTORH_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorh_slope    = AUTO_ALCOM110_ENRH_6_MOTORH_SLOPE;
    motor.preauto_auto.enrh_phase_list[5].motorl_mode_dir = AUTO_ALCOM110_ENRH_6_MOTORL_DIR;
    motor.preauto_auto.enrh_phase_list[5].motorl_speed    = AUTO_ALCOM110_ENRH_6_MOTORL_SPEED;
    motor.preauto_auto.enrh_phase_list[5].motorl_slope    = AUTO_ALCOM110_ENRH_6_MOTORL_SLOPE;
    
    //ENRL
    motor.preauto_auto.enrl_phase_list[0].motorh_mode_dir = AUTO_ALCOM110_1_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorh_speed    = AUTO_ALCOM110_1_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorh_slope    = AUTO_ALCOM110_1_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[0].motorl_mode_dir = AUTO_ALCOM110_1_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[0].motorl_speed    = AUTO_ALCOM110_1_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[0].motorl_slope    = AUTO_ALCOM110_1_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[1].motorh_mode_dir = AUTO_ALCOM110_ENRL_2_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorh_speed    = AUTO_ALCOM110_ENRL_2_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorh_slope    = AUTO_ALCOM110_ENRL_2_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[1].motorl_mode_dir = AUTO_ALCOM110_ENRL_2_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[1].motorl_speed    = AUTO_ALCOM110_ENRL_2_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[1].motorl_slope    = AUTO_ALCOM110_ENRL_2_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[2].motorh_mode_dir = AUTO_ALCOM110_ENRL_3_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorh_speed    = AUTO_ALCOM110_ENRL_3_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorh_slope    = AUTO_ALCOM110_ENRL_3_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[2].motorl_mode_dir = AUTO_ALCOM110_ENRL_3_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[2].motorl_speed    = AUTO_ALCOM110_ENRL_3_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[2].motorl_slope    = AUTO_ALCOM110_ENRL_3_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[3].motorh_mode_dir = AUTO_ALCOM110_ENRL_4_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorh_speed    = AUTO_ALCOM110_ENRL_4_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorh_slope    = AUTO_ALCOM110_ENRL_4_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[3].motorl_mode_dir = AUTO_ALCOM110_ENRL_4_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[3].motorl_speed    = AUTO_ALCOM110_ENRL_4_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[3].motorl_slope    = AUTO_ALCOM110_ENRL_4_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[4].motorh_mode_dir = AUTO_ALCOM110_ENRL_5_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorh_speed    = AUTO_ALCOM110_ENRL_5_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorh_slope    = AUTO_ALCOM110_ENRL_5_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[4].motorl_mode_dir = AUTO_ALCOM110_ENRL_5_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[4].motorl_speed    = AUTO_ALCOM110_ENRL_5_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[4].motorl_slope    = AUTO_ALCOM110_ENRL_5_MOTORL_SLOPE;
    
    motor.preauto_auto.enrl_phase_list[5].motorh_mode_dir = AUTO_ALCOM110_ENRL_6_MOTORH_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorh_speed    = AUTO_ALCOM110_ENRL_6_MOTORH_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorh_slope    = AUTO_ALCOM110_ENRL_6_MOTORH_SLOPE;
    motor.preauto_auto.enrl_phase_list[5].motorl_mode_dir = AUTO_ALCOM110_ENRL_6_MOTORL_DIR;
    motor.preauto_auto.enrl_phase_list[5].motorl_speed    = AUTO_ALCOM110_ENRL_6_MOTORL_SPEED;
    motor.preauto_auto.enrl_phase_list[5].motorl_slope    = AUTO_ALCOM110_ENRL_6_MOTORL_SLOPE;
    
}
