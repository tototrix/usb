#include <_Global_Include.h>

u16 tele_auto_ar = 0x80;
u16 tele_der_haut_ar = 0x80;
u16 tele_enr_haut_ar = 0x80;
u16 tele_enr_bas_ar = 0x80;

bool tele_auto             = FALSE;
bool tele_deroulement_haut = FALSE;
bool tele_enroulement_haut = FALSE;
bool tele_enroulement_bas  = FALSE;


//=========================================================================
// Function : Initialisation
// Input(s) : -
// Output   : -
//=========================================================================
void init_telecommande(void)
{
    TELE_AUTO_TRIS = INPUT;
    TELE_DEROULEMENT_HAUT_TRIS = INPUT;
    TELE_ENROULEMENT_HAUT_TRIS = INPUT;
    TELE_ENROULEMENT_BAS_TRIS = INPUT;
}

//=========================================================================
// Function : Antirebonds
// Input(s) : -
// Output   : -
//=========================================================================
void telecommande_AR(void)
{
   
    if(TELE_AUTO == 1 && tele_auto_ar < 128) tele_auto_ar++;
    else if(TELE_AUTO == 0 && tele_auto_ar > 0) tele_auto_ar--;
    
    if(TELE_DEROULEMENT_HAUT == 1 && tele_der_haut_ar < 128) tele_der_haut_ar++;
    else if(TELE_DEROULEMENT_HAUT == 0 && tele_der_haut_ar > 0) tele_der_haut_ar--;
    
    if(TELE_ENROULEMENT_HAUT == 1 && tele_enr_haut_ar < 128) tele_enr_haut_ar++;
    else if(TELE_ENROULEMENT_HAUT == 0 && tele_enr_haut_ar > 0) tele_enr_haut_ar--;
    
    if(TELE_ENROULEMENT_BAS == 1 && tele_enr_bas_ar < 128) tele_enr_bas_ar++;
    else if(TELE_ENROULEMENT_BAS == 0 && tele_enr_bas_ar > 0) tele_enr_bas_ar--;
    
    if(tele_auto_ar == 128)        tele_auto = TRUE;
    if(tele_auto_ar == 0)          tele_auto = FALSE;
    
    if(tele_der_haut_ar == 128)    tele_deroulement_haut = TRUE;
    if(tele_der_haut_ar == 0)      tele_deroulement_haut = FALSE;
    
    if(tele_enr_haut_ar == 128)    tele_enroulement_haut = TRUE;
    if(tele_enr_haut_ar == 0)      tele_enroulement_haut = FALSE;
    
    if(tele_enr_bas_ar == 128)     tele_enroulement_bas = TRUE;
    if(tele_enr_bas_ar == 0)       tele_enroulement_bas = FALSE;
    
    
    
    if( (motor_algo_mode != MANUAL_MODE) && (tele_auto == TRUE))
    {
        // Enregistrement de l'évènement dans la mémoire.
        eeprom_ev_write1(EEPROM_EV_MANUAL_ENTER);
    
        motor_algo_mode = MANUAL_MODE;
        start_of_manual_mode();
        error_start_of_manual_mode();
        
    }
    else if((motor_algo_mode == MANUAL_MODE) && (tele_auto == FALSE))
    { 
        motor_algo_mode = INIT_MODE;
        end_of_manual_mode();
        motor_init_init();
    }
    
    
    
}

u8   telecommande_byte(void)
{
    u8 value = 0x00;
    if(tele_auto) value++;
    value<<=1;
    if(tele_deroulement_haut) value++;
    value<<=1;
    if(tele_enroulement_haut) value++;
    value<<=1;
    if(tele_enroulement_bas) value++;
    return value;
}