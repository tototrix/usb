#include <_Global_Include.h>
#include <string.h>

int __C30_UART = 2;

_FSEC(BWRP_OFF & BSS_DISABLED & BSS2_ON & GWRP_OFF  & GSS_DISABLED & CWRP_OFF & CSS_DISABLED & AIVTDIS_ENABLE);
_FBSLIM(0x1FFC);
_FDMT(DMTEN_DISABLE);
_FOSCSEL(FNOSC_FRC & IESO_OFF);
_FOSC(FCKSM_CSECMD & IOL1WAY_OFF & OSCIOFNC_ON & FCKSM_CSECMD & POSCMD_NONE);
_FWDT(WDTPOST_PS32768 & WDTPRE_PR128  & FWDTEN_OFF & WINDIS_OFF & WDTWIN_WIN25);
_FPOR(BOREN0_ON);
_FDEVOPT(PWMLOCK_OFF & ALTI2C1_OFF);
_FICD(ICS_PGD1);



#undef PPS_TEST_ECLAIRAGE    


const u16 __attribute__((address(0xC00))) master_firmware=4110;

// Permet de savoir si le programme se trouve en mode test
bool test_mode      =FALSE;
// Variable qui permet de tester les accès à la mémoire eeprom en mode test
u8   test_flash_var = 0x00;
// Etat logiciel de la led moteur
bool led_motor_prog = FALSE;
// Etat logiciel de la led de defaut
bool led_default_prog = FALSE;

// Permet de stocker le numéro de série de la carte (mémoire eeprom)
u8 serial_number[4];
// Numero de série sur 32 bits
u32 serial_number_u32 = 0x0000;
// Version logiciel sauvegardée dans l'eeprom
u16 master_eeprom_firmware = 0x00;
// Flag permettant de savoir si il s'agit de l'USB qui heberge le modem
bool usb_with_modem = FALSE;
// Contient la version de firmware du pic esclave haut.
u16 slaveH_firmware = 0x0000;
// Contient la version de firmware du pic esclave bas.
u16 slaveL_firmware = 0x0000;
// Mode de fonctionnement du programme;
u8 motor_algo_mode = INIT_MODE;
// Permet d'arreter le defilement lorsque le modem prépare une mise à jour de firmware
bool btldr_stop_scrolling = FALSE;
// Indique si une cellule a été detectée
bool cell_feature         = FALSE;
// Indique si des pulses sont detectés
bool pulses_feature       = FALSE;

bool global_dt_sync_ok    = FALSE;
u8 global_dt_year         = 0x00;
u8 global_dt_month        = 0x00;
u8 global_dt_days         = 0x00;
u8 global_dt_hours        = 0x00;
u8 global_dt_minuts       = 0x00;
u8 global_dt_seconds      = 0x00;

u8 panel_size             = PANEL_SIZE_UNKNOWN;

volatile u16 state_btld_stop_timer = 0x00;
volatile u8  state_bltd_stop = 0;

volatile u8 main_state = S_MAIN_INIT;


/*----------------------------------------------------------------------------
 ** \function  : PLL_OSC_Setting
 **	\brief     The PFD Input Frequency (FPLLI) must be in the range of 0.8 MHz to 8.0 MHz
 **                The VCO Output Frequency (FVCO) must be in the range of 120 MHz to 340 MHz
 **                 N1 = PLLPRE<4:0> + 2; N2 = 2 x (PLLPOST<1:0> + 1); M = PLLDIV<8:0> + 2
 **                  Fvco = Fin*(M/N1); Fcy = Fin*M/(N1*N2); Fplli = Fin/N1
 **          for further details, please refer to the 'USB Technical Report'
 *******************************************************************************/

void PLL_OSC_Setting(void) {

    // Configure PLL prescaler, PLL postscaler, PLL divisor
    // Fplli = 3.685 Mhz, Fvco = 235.84 Mhz, Fcy = 7.37 Mhz,
    /*   */

#if FOSC == FOSC_60000000
    PLLFBD = 96; 
    CLKDIVbits.PLLPRE = 1; 
    CLKDIVbits.PLLPOST = 1;
#elif FOSC == FOSC_30000000
    PLLFBD = 96; 
    CLKDIVbits.PLLPRE = 1; 
    CLKDIVbits.PLLPOST = 3;
#elif FOSC == FOSC_15000000
    PLLFBD = 30; 
    CLKDIVbits.PLLPRE = 0; 
    CLKDIVbits.PLLPOST = 3; 
#else
    while(1);
    return;
#endif
    
    
    
   
    // Configure FRC postscaler, FRC tuning
    //CLKDIVbits.FRCDIV = 1; // FRC divided by 1
    //OSCTUNbits.TUN = 0x00; // Center frequency (7.37 MHz nominal)

    // Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);

    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);

    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1);

} // End PLL_OSC_Setting




u16 get_master_firmware(void)
{
    u16 temp16 = Pic33EV_Read_Word(0xC00);
    return temp16;
}

void Init_IO(void)
{
    PPS_TRIS            = INPUT;
    PPS_CNPD            = TRUE;
    
    
    CELLULE_TRIS        = INPUT;
    CELLULE_CNPD        = TRUE; 
    CAPTEUR_PORTE_TRIS  = INPUT;
    CAPTEUR_PORTE_CNPD  = TRUE;
    SW1_TRIS            = INPUT;
    SW1_CNPU            = 1;
    SW2_TRIS            = INPUT;
    SW2_CNPU            = 1;
    MCLR_SLAVE_TRIS     = OUTPUT;
    MCLR_SLAVE          = 0;
    DETECT_MODEM_TRIS   = INPUT;
    SPARE_M_TRIS        = INPUT;
    PGC_TRIS            = OUTPUT;
    PGC                 = 1;
    PGD_TRIS            = OUTPUT;
    PGD                 = 1;
    
    ClrWdt(); 
    __delay_ms(100);
    MCLR_SLAVE          = 0;
    ClrWdt(); 
    __delay_ms(100);
    ClrWdt(); 
    if(DETECT_MODEM == 0) usb_with_modem = TRUE;
    else usb_with_modem = FALSE;  
    
    #ifdef PPS_TEST_ECLAIRAGE
    if(usb_with_modem)
    {
        PPS_TRIS            = OUTPUT;
        PPS_CNPD            = FALSE;
        PPS_LAT             = 0;
    }
    #endif
}


void
lockIO ()
{
   
     asm volatile ("mov #OSCCON,w1 \n"
                 "mov #0x46, w2 \n"
                 "mov #0x57, w3 \n"
                 "mov.b w2,[w1] \n"
                 "mov.b w3,[w1] \n"
                 "bset OSCCON, #6":: : "w1", "w2", "w3");
    
}

void
unlockIO ()
{
   
     asm volatile ("mov #OSCCON,w1 \n"
                 "mov #0x46, w2 \n"
                 "mov #0x57, w3 \n"
                 "mov.b w2,[w1] \n"
                 "mov.b w3,[w1] \n"
                 "bclr OSCCON, #6":: : "w1", "w2", "w3");
    
}


void Init_Panel_Size(void)
{
    panel_size = PANEL_SIZE_UNKNOWN;
}
void Set_Panel_Size(u8 type)
{
    panel_size = type;
}

void set_btldr_stop_scrolling(u16 time)
{
    state_bltd_stop = 0;
    state_btld_stop_timer = time;
    btldr_stop_scrolling = TRUE;
}


void main_reset(u8 state)
{
    main_state  = state;
}

/*----------------------------------------------------------------------------
 ** \function  : Main_Program
 **	\brief		Call differents routines
 **                        PRE_INIT Mode, MANU Mode, INIT Mode, PRE_AUTO and AUTO Mode
 **          for further details, please refer to the 'USB Technical Report'
 *******************************************************************************/
int main(void) {

    volatile u16 i = 0;
    volatile u8  state_test = 0;
    volatile u16 temp16;
    volatile u8  *ptr_struct_motor;
    volatile u8  slave_com_return;
    volatile u16 test_timer1ms = 1000;
    
    
    
    #ifdef PPS_TEST_ECLAIRAGE
    volatile u16 pps_timer = 0x00;
    #endif
  
    IEC0 = 0;
    IEC1 = 0;
    IEC2 = 0;
    IEC3 = 0;
    IEC4 = 0;
    IEC5 = 0;
    IEC6 = 0;
    IEC8 = 0;

    IFS0 = 0;
    IFS1 = 0;
    IFS2 = 0;
    IFS3 = 0;
    IFS4 = 0;
    IFS5 = 0;
    IFS6 = 0;
    IFS8 = 0;
      
    INTCON2bits.AIVTEN = 1;
    
    PLL_OSC_Setting(); 
    INTCON2bits.GIE = 1;
    ClrWdt(); 
    INTCON1bits.NSTDIS = 0; // Nested interrupt
    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    
    CNPDA = 0x00;
    CNPDB = 0x00;
    CNPDC = 0x00;
    CNPUA = 0x00;
    CNPUB = 0x00;
    CNPUC = 0x00;

    
    
    
    


       
    motor_algo_mode = INIT_MODE;//MANUAL_MODE;
    test_mode=FALSE;
    led_motor_prog = FALSE;
    led_default_prog = FALSE;
    state_test = 0;

    // Initialisations des differentes fonctions
    timer1ms_init();
    timer100ms_init();
    timer1ms_start();
    timer100ms_start();
    timer_pulses_init();
    timer1ms_register_variable((u16*)&test_timer1ms);
    timer100ms_register_variable((u16*)&state_btld_stop_timer);
    state_bltd_stop = 0x00;
    btldr_stop_scrolling = FALSE;
    
 
   
    
    Init_IO();   
    adc_init();     
    i2c_init();
    ClrWdt(); 
    eeprom_ev_init();
    eeprom_var_init();      // Lecture des différentes variables présentes en mémoire
    ClrWdt(); 
    //gsm_keepalive_init();
    update_serial_u32();    // MAJ du numero de série en fonction de ce qui est lu en mémoire.
    ClrWdt(); 
    force_keepalive_init();
    
    
    #ifdef PPS_TEST_ECLAIRAGE
    if(usb_with_modem)
    {
        timer100ms_register_variable((u16*)&pps_timer);
    }
    #endif
    
    
    
    // Au demarrage on verifie la version logicielle
    // avec celle stockée dans la mémoire externe
    if(master_eeprom_firmware != get_master_firmware())
    {
        
        for(i=0;i<5;i++) error_light[i] = 0x00;
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT0);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT1);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT2);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT3);
        eeprom_var8_update(EEPROM_VAR8_ERROR_LIGHT4);
        
        error_id[0] = 0x00;
        error_id[1] = 0x00;
        error_id[2] = 0x00;
        error_id[3] = 0x01;
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID0);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID1);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID2);
        eeprom_var8_update(EEPROM_VAR8_ERROR_ID3);
        update_error_id_u32(); 
        
        if(error_list[error_code].new_firmware_reset == TRUE)
        {
            ClrWdt(); 
            error_code = ERROR_NONE;
            error_type = NO_ERROR;
            eeprom_var8_update(EEPROM_VAR8_ERROR);   
        }
        master_eeprom_firmware = get_master_firmware();
        eeprom_var16_update(EEPROM_VAR16_FIRMWARE_VERSION);
    }
    ClrWdt(); 
    
    state_btld_stop_timer = 30;
    
    while(1)
    {
        ClrWdt(); 
 
        
        if(test_mode == FALSE)
        {
            LED_MOTOR   = led_motor_prog;
            LED_DEFAULT = led_default_prog;
        }
        else
        {
            if(main_state == S_MAIN_PROCESS)
            {
                switch(state_test)
                {
                    case 0:
                        if(test_timer1ms == 0x00)
                        {
                            LED_MOTOR     = LED_ON;
                            LED_DEFAULT   = LED_OFF;
                            test_timer1ms = 500;
                            state_test    = 0x01;
                        }
                        break;
                        
                    case 1:
                        if(test_timer1ms == 0x00)
                        {
                            LED_MOTOR     = LED_OFF;
                            LED_DEFAULT   = LED_ON;
                            test_timer1ms = 500;
                            state_test    = 0x00;
                        }
                        break; 
                }
            }
        }
        
        switch(state_bltd_stop)
        {
            case 0:
                if(btldr_stop_scrolling == TRUE)
                {
                    state_bltd_stop = 1;
                }
                else if(state_btld_stop_timer == 0x00)
                {
                    PGC = 0;
                    PGD = 0;
                }
                break;
                
            case 1:
                if(state_btld_stop_timer == 0x00)
                {
                    btldr_stop_scrolling = FALSE;
                    state_bltd_stop = 0;
                }
                break;
        }
        
        ClrWdt(); 
        switch(main_state)
        {
            case S_MAIN_INIT:
                led_motor_prog = LED_ON;
                motor.family = MOTOR_UNKNOWN_FAMILY;
                motor.model  = MOTOR_MODEL_UNKNOWN;
                cell_init();
                error_init();
                uarts_init();
                
               
                uart_motor_init();  
                //uart_printf_init();
                uart_motor_protocole_init();
                init_telecommande();
                motor_manu_init();
                poster_init(0,0,0);
                door_security_init();
                synchro_ext_init();
                slave_status_init();
  
                slaveH_firmware = 0x0000;
                slaveL_firmware = 0x0000;
                                
                eeprom_ev_write1(EEPROM_EV_SYSTEM_START); // Ecriture de l'evenement "demarrage" en mémoire.
                eeprom_var_init();                        // Lecture des différentes variables présentes en mémoire
                error(error_code);                        // Prise en compte du code d'erreur lu dans la mémoire.
                
                
                
                
                // Passage à l'état suivant
                main_state = S_MAIN_INIT_SLAVE;
                
                
                
                update_serial_u32();
                
                /*temp32 = 200006;
                
                
                serial_number[0] = (u8)(temp32>>24);
                serial_number[1] = (u8)(temp32>>16);
                serial_number[2] = (u8)(temp32>>8);
                serial_number[3] = (u8)(temp32 & 0x00FF);
                
                
                eeprom_var8_update(EEPROM_VAR8_SERIAL0);
                eeprom_var8_update(EEPROM_VAR8_SERIAL1);
                eeprom_var8_update(EEPROM_VAR8_SERIAL2);
                eeprom_var8_update(EEPROM_VAR8_SERIAL3);

                update_serial_u32();*/
               
                
                
                
                
                
                
                
                
                break;
            
            case S_MAIN_INIT_SLAVE:
                test_timer1ms     = 3;
                main_state        = S_MAIN_INIT_SLAVE2;
                break;
            
            case S_MAIN_INIT_SLAVE2:
                if(test_timer1ms == 0x00)
                {
                    main_state = S_MAIN_SWITCH;
                }
                break;
                
            case S_MAIN_SWITCH:
                if(test_timer1ms == 0x00)
                {
                    //=================================================================================
                    // RECUPERATION DE LA CONFIGURATION DES SWITCHS
                    //=================================================================================

                    

                    // Temporisation pendant laquelle on applique un antirebonds sur les switch
                    test_timer1ms = 10;
                    while(test_timer1ms > 0)
                    {
                        ClrWdt(); 
                    }
 
                    if(SW1) motorh_switch = 0;
                    else    motorh_switch = 1;
                    if(SW2) motorl_switch = 0;
                    else    motorl_switch = 1;
                    
                    

                    // Enregistrement de l'evenement dans la mémoire.
                    eeprom_ev_write3(EEPROM_EV_CONFIG_SWITCH,motorh_switch,motorl_switch);
                    // Passage à l'état suivant.
                    main_state = S_MAIN_INIT_GET_SLAVEH_FIRMWARE;
                }
                
                break;
                
                
            case S_MAIN_INIT_GET_SLAVEH_FIRMWARE:
                #ifdef DEBUG_PRINTF  
                printf("Firmware master: 0x%04x\r\n",version);
                #endif
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_FIRMWARE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                slave_com_return = uart_motor_protocole_send_packet_blocking();
                if(slave_com_return == UART_MOTOR_PROTOCOLE_ERROR)
                {
                    slaveH_firmware = 0x0000;
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    main_state = S_MAIN_PROCESS;
                }
                else
                {
                    slaveH_firmware = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX); 
                    slaveH_firmware <<=8;
                    slaveH_firmware += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1); 
                    eeprom_ev_write3(EEPROM_EV_SLAVEH_FIRMWARE,slaveH_firmware>>8,slaveH_firmware & 0x00FF);
                    #ifdef DEBUG_PRINTF  
                    printf("Firmware esclaveH 0x%04x \r\n",slaveH_firmware);
                    #endif

                    main_state = S_MAIN_INIT_GET_SLAVEL_FIRMWARE;
                }
                break;
                
            case S_MAIN_INIT_GET_SLAVEL_FIRMWARE:
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_FIRMWARE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                slave_com_return = uart_motor_protocole_send_packet_blocking();
                if(slave_com_return == UART_MOTOR_PROTOCOLE_ERROR)
                {
                    slaveL_firmware = 0x0000;
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    main_state = S_MAIN_PROCESS;
                }
                else
                {
                    slaveL_firmware = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX); 
                    slaveL_firmware <<=8;
                    slaveL_firmware += com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+1); 
                    eeprom_ev_write3(EEPROM_EV_SLAVEL_FIRMWARE,slaveL_firmware>>8,slaveL_firmware & 0x00FF);
                    #ifdef DEBUG_PRINTF  
                    printf("Firmware esclaveL 0x%04x \r\n",slaveL_firmware);
                    #endif

                    if(slaveH_firmware == 0x0000 || slaveH_firmware == 0xFFFF ||
                       slaveL_firmware == 0x0000 || slaveL_firmware == 0xFFFF || 
                       (slaveH_firmware != slaveL_firmware) )     
                    {
                        error(ERROR_SLAVES_FIRMWARE);
                        main_state = S_MAIN_PROCESS;
                    }
                    else
                    {
                        main_state = S_MAIN_INIT_MOTOR;
                    } 
                }
                break;  
                
                
            case S_MAIN_INIT_MOTOR:
                init_motor(); 
                if(slave_com_authorization == FALSE)
                {
                    main_state = S_MAIN_PROCESS;
                }
                else
                {
                    if(motor.model != MOTOR_MODEL_UNKNOWN)
                    {
                        main_state = S_MAIN_INIT_CONFIG_SLAVEH;
                    }
                    else
                    {
                        error(ERROR_MOTOR_SHUNT);
                        main_state = S_MAIN_PROCESS;
                    }  
                }
                break;
            
                
                
            case S_MAIN_INIT_CONFIG_SLAVEH:
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_TYPE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                slave_com_return = uart_motor_protocole_send_packet_blocking();
                if(slave_com_return == UART_MOTOR_PROTOCOLE_ERROR)
                {
                    error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                    main_state = S_MAIN_PROCESS;
                }
                else
                {
                    
                    // Récupération de la structure contenant les informations de pilotage du moteur
                    temp16 = com_packet_get_byte(&uart_motor_protocole_packet_rx,COM_PACKET_SIZEH_INDEX);
                    temp16 <<=8;
                    temp16 += com_packet_get_byte(&uart_motor_protocole_packet_rx,COM_PACKET_SIZEL_INDEX);
                    temp16-=8;
                    
                    // Si la structure reçue à la même taille que la structure attendue
                    // Alors il n'y a pas de risque de débordement de la mémoire.
                    if(temp16 == sizeof(struct_motor))
                    {
                        ptr_struct_motor = (u8*)&motor;
                        
                        for(i=0;i<temp16;i++)
                        {
                            *(ptr_struct_motor+i) = com_packet_get_byte(&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX+i);
                        }
                        motor_timeout_save();
                        main_state = s_MAIN_INIT_CONFIG_SLAVEL;   
                    }
                    // Sinon si la structure reçue diffère au niveau de la taille
                    else
                    {
                        i=0;
                        error(ERROR_STRUCT_MOTOR_DIFFERENT);
                        main_state = S_MAIN_PROCESS;
                    }
                   
                }
                break;
                
            case s_MAIN_INIT_CONFIG_SLAVEL:
                #ifdef DEBUG_PRINTF  
                printf("Configuration pic esclave moteur haut 0x%02X... \r\n",motor.model);    
                #endif

                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_TYPE);
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,motor.model);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                slave_com_return = uart_motor_protocole_send_packet_blocking();
                if(slave_com_return == UART_MOTOR_PROTOCOLE_ERROR)
                {
                   error(ERROR_COMM_WITH_SLAVES_CRITICAL);
                   #ifdef DEBUG_PRINTF  
                   printf("Configuration pic esclave moteur haut  : ERREUR \r\n");    
                   #endif
                    main_state = S_MAIN_PROCESS;
                }
                else
                {
                    if((motor_type_eeprom != motorh_type) && (motorh_type != MOTOR_MODEL_UNKNOWN ) )
                    {              
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_EXTREME_TAPE_H);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_EXTREME_TAPE_L);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER);
                        
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER0);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER1);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER2);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER3);
                        eeprom_var16_reset(EEPROM_VAR16_PULSES_POSTER4);
                        
                        eeprom_var16_update(EEPROM_VAR16_PULSES_EXTREME_TAPE_H);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_EXTREME_TAPE_L);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER0);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER1);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER2);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER3);
                        eeprom_var16_update(EEPROM_VAR16_PULSES_POSTER4);
                        

                        motor_type_eeprom = motorh_type;
                        eeprom_var8_update(EEPROM_VAR8_MOTOR_TYPE);  
                    }
                    
                    
                   #ifdef DEBUG_PRINTF  
                   printf("Configuration pic esclave moteur haut  : SUCCES \r\n");    
                   #endif
                   main_state = S_MAIN_PRE_PROCESS;
                }
                break; 
                
            case S_MAIN_PRE_PROCESS:      
                uarts_init_re_de();
                motor_init_init(); // Par defaut on commence en mode init
                main_state = S_MAIN_PROCESS;
                temp16=0x00;
                
                
                
               /* motor.init_mode.init_phase_list[3].motorh_speed = 40;
                motor.init_mode.init_phase_list[3].motorl_speed = 40;
                motor.init_mode.init_phase_list[3].motorl_mode_dir = PWM_TABLE_INVERSE_WEAK;
                
                motor.init_mode.init_phase_list[6].motorh_speed = 40;
                motor.init_mode.init_phase_list[6].motorh_mode_dir = PWM_TABLE_DIRECT_WEAK;
                motor.init_mode.init_phase_list[6].motorl_speed = 38;
                motor.init_mode.init_phase_list[6].motorl_mode_dir = PWM_TABLE_INVERSE_STRONG;*/
                
                
                
                
                
                
                break;
            
                
            case S_MAIN_PROCESS:
                
                
            case S_MAIN_PROCESS2:
                if(test_mode == FALSE && btldr_stop_scrolling == TRUE)
                {
                    if(test_timer1ms== 0x00)
                    {
                        test_timer1ms = 250;
                        if(led_motor_prog == LED_ON ) led_motor_prog = LED_OFF;
                        else led_motor_prog = LED_ON;
                    }
                }
                else
                {
                    
                    if(adc_low_battery)
                    {
                        if(test_timer1ms== 0x00)
                        {
                            if(temp16 >=2)
                            {
                                temp16=0x00;
                                test_timer1ms = 1000;
                            }
                            else
                            {
                                test_timer1ms = 250;
                                if(led_motor_prog == LED_ON )
                                {
                                    led_motor_prog = LED_OFF;
                                    temp16++;
                                }
                                else
                                {
                                    if(temp16<2) led_motor_prog = LED_ON;
                                    else led_motor_prog = LED_OFF;
                                    
                                }
                            }
                        } 
                    }
                    else if(temporary_stop)
                    {
                        if(test_timer1ms== 0x00)
                        {             
                            if(temp16 >=3)
                            {
                                temp16=0x00;
                                test_timer1ms = 1000;
                            }
                            else
                            {
                                test_timer1ms = 250;
                                if(led_motor_prog == LED_ON )
                                {
                                    led_motor_prog = LED_OFF;
                                    temp16++;
                                }
                                else
                                {
                                    if(temp16<3) led_motor_prog = LED_ON;
                                    else led_motor_prog = LED_OFF;
                                    
                                }
                            }
                        } 
                    }
                    else led_motor_prog = LED_ON;
                }
                
                
                ClrWdt(); 
                
                #ifdef PPS_TEST_ECLAIRAGE
                if(usb_with_modem && pps_timer == 0x00)
                {
                    if(PPS == 0x0)
                    {
                        PPS_LAT = 1;
                    }
                    else
                    {
                        PPS_LAT = 0;
                    }
                    pps_timer = 100;
                }
                #endif
                
                
                telecommande_AR();         // Antirebonds sur la telecommande 
                synchro_ext_process();     // Gestion de la synchro externe
                
                if(motor_critical_drive == FALSE) 
                {
                    uarts_sm_construct_rx();   // UART systeme: construction d'un paquet 
                    uarts_sm_treatment_rx();   // UART systeme: analyse du paquet reçu
                    uarts_tx_mgmt_sm();        // UART système: gestion de la communication en mode maitre.
                    //gsm_keepalive_sm();        // Machine de gestion des demandes de keepalive 
                    
                    adc_sm();                  // Gestion des conversion ADC (temperature, niveau batterie)
                    error_sm();                // Gestion des erreurs 
                    force_keepalive_sm();      // Gestion des évènements à l'origine d'un keepalive
                }
                
                if(panel_size == PANEL_SIZE_8M2)
                {
                    door_security_sm();    // Gestion de la sécurité porte pour les version 8m²
                }

                if(slave_com_authorization == TRUE)
                {
                    motor_manu_sm();           // Machine d'états de gestion du mode manuel 
                    slave_status_sm();         // Machine d'états de recupération des températures et des courants sur les esclaves.     
                    uart_motor_protocole_sm(); // Machine d'états de gestion de la communication maitre <--> esclaves.
                    motor_slope_sm();          // Machine d'états de gestion des rampes moteurs
                  
                    if(motor_drive_authorization == TRUE)
                    {                    
                        if((motor_algo_mode !=  MANUAL_MODE) && (door_opened == FALSE) && (slave_status_bridge_emergency_temp == FALSE))     
                        {
                            cell_process(); // Routine de traitement de la cellule
                            if(motor_algo_mode == INIT_MODE) // Si le programme est en mode init
                            {
                                motor_init_sm();
                            }
                            else 
                            {
                                motor_auto_sm();   
                            }
                        }
                    }
                }

                /*switch(state)
                {
                    case 0:
                        if(test_timer1ms == 0x00)
                        {
                            if(uarts_tx_mgmt_is_mutex_free())
                            {
                                uarts_tx_mgmt_get_mutex();
                                
                                
                                if(usb_with_modem)
                                {
                                    uarts_tx_mgmt_packet_tx_init(0x03,0x00000000,0x01);

                                         if(led_chauff == 0x00) led_chauff = 0x01;
                                    else if(led_chauff == 0x01) led_chauff = 0x10;
                                    else if(led_chauff == 0x10) led_chauff = 0x11;
                                    else if(led_chauff == 0x11) led_chauff = 0x00;
                                    uarts_tx_mgmt_packet_tx_add_byte(led_chauff);
                                }
                                else
                                {
                                    uarts_tx_mgmt_packet_tx_init(0x04,0x00000000,0x01);

                                         if(led_chauff == 0x00) led_chauff = 0x01;
                                    else if(led_chauff == 0x01) led_chauff = 0x00;
                                    uarts_tx_mgmt_packet_tx_add_byte(led_chauff);
                                }
                                uarts_tx_mgmt_packet_tx_finalize();
                                uarts_tx_mgmt_go(250);
                                state = 1;
                            }
                        }
                        break;
                        
                    case 1:
                        if(uarts_tx_mgmt_is_busy() == FALSE)
                        {
                            if(uarts_tx_mgmt_is_error() == FALSE)
                            {
                                i = 0;
                                i=1;
                            }
                            state = 2;
                        }
                        break;
                        
                    case 2:
                        uarts_tx_mgmt_release_mutex();
                        state = 0;
                        test_timer1ms = 500;
                        break;
                }*/
                
                
                
                
                
                break;
                
                
                
        }
    }
    return 0;

} //0 End main