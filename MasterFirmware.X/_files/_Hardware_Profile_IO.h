#ifndef _HARDWARE_PROFILE_IO_H
#define	_HARDWARE_PROFILE_IO_H
 
#ifdef BOARD_RELEASE_D

#define PGC_TRIS TRISBbits.TRISB2
#define PGC      LATBbits.LATB2

#define PGD_TRIS TRISBbits.TRISB3
#define PGD      LATBbits.LATB3
//----------------------------------------------------------------------------
// PPS
//----------------------------------------------------------------------------
#define PPS_TRIS          TRISCbits.TRISC7
#define PPS               PORTCbits.RC7
#define PPS_LAT           LATCbits.LATC7

#define PPS_CNPD          CNPDCbits.CNPDC7

//----------------------------------------------------------------------------
// SIGNAL RELAIS
//----------------------------------------------------------------------------
#define RELAY_TRIS        TRISBbits.TRISB12
#define RELAY             PORTBbits.RB12
#define RELAY_CNPU        CNPUBbits.CNPUB12

//----------------------------------------------------------------------------
// LED
//----------------------------------------------------------------------------
#define LED_MOTOR_TRIS      TRISCbits.TRISC8
#define LED_MOTOR           LATCbits.LATC8


#define LED_DEFAULT_TRIS    TRISCbits.TRISC9
#define LED_DEFAULT         LATCbits.LATC9

//----------------------------------------------------------------------------
// UART BOARD
//----------------------------------------------------------------------------
#define UART_BOARD_RX_TRIS    TRISAbits.TRISA2
#define UART_BOARD_RX         PORTAbits.RA2

#define UART_BOARD_TX_TRIS    TRISBbits.TRISB4
#define UART_BOARD_TX         LATBbits.LATB4

#define UART_BOARD_DE_TRIS    TRISAbits.TRISA8
#define UART_BOARD_DE         LATAbits.LATA8

#define UART_BOARD_RE_TRIS    TRISAbits.TRISA3
#define UART_BOARD_RE         LATAbits.LATA3

//----------------------------------------------------------------------------
// UART MOTOR
//----------------------------------------------------------------------------
#define UART_MOTOR_RX_TRIS    TRISBbits.TRISB7
#define UART_MOTOR_RX         PORTBbits.RB7

#define UART_MOTOR_TX_TRIS    TRISBbits.TRISB8
#define UART_MOTOR_TX         LATBbits.LATB8

//----------------------------------------------------------------------------
// TELECOMMANDE
//----------------------------------------------------------------------------
#define TELE_AUTO_TRIS             TRISBbits.TRISB15
#define TELE_AUTO                  PORTBbits.RB15

#define TELE_DEROULEMENT_HAUT_TRIS TRISBbits.TRISB13
#define TELE_DEROULEMENT_HAUT      PORTBbits.RB13

#define TELE_ENROULEMENT_HAUT_TRIS TRISAbits.TRISA10
#define TELE_ENROULEMENT_HAUT      PORTAbits.RA10

#define TELE_ENROULEMENT_BAS_TRIS TRISBbits.TRISB14
#define TELE_ENROULEMENT_BAS      PORTBbits.RB14

//----------------------------------------------------------------------------
// CELLULE PORTE BIT_SYNCHRO
//----------------------------------------------------------------------------
#define CELLULE_TRIS              TRISAbits.TRISA0
#define CELLULE                   PORTAbits.RA0
#define CELLULE_CNPD              CNPDAbits.CNPDA0

#define CAPTEUR_PORTE_TRIS        TRISBbits.TRISB0
#define CAPTEUR_PORTE             PORTBbits.RB0
#define CAPTEUR_PORTE_CNPD        CNPDBbits.CNPDB0

#define BIT_SYNC_TRIS             TRISCbits.TRISC0
#define BIT_SYNC                  PORTCbits.RC0


//----------------------------------------------------------------------------
// SWITCH
//----------------------------------------------------------------------------
#define SW1_TRIS                 TRISCbits.TRISC1
#define SW1                      PORTCbits.RC1
#define SW1_CNPU                 CNPUCbits.CNPUC1

#define SW2_TRIS                 TRISCbits.TRISC2
#define SW2                      PORTCbits.RC2
#define SW2_CNPU                 CNPUCbits.CNPUC2

//----------------------------------------------------------------------------
// VBAT
//----------------------------------------------------------------------------
#define VBAT_TRIS                 TRISBbits.TRISB1
#define VBAT                      PORTBbits.RB1
#define VBAT_AN                   ANSELBbits.ANSB1

//----------------------------------------------------------------------------
// CTN 10K
//----------------------------------------------------------------------------
#define CTN_TRIS                  TRISCbits.TRISC5
#define CTN                       PORTCbits.RC5
#define CTN_AN                    ANSELCbits.ANSC5



//----------------------------------------------------------------------------
// PULSE MOTEURS
//----------------------------------------------------------------------------
#define PULSE_H_TRIS            TRISAbits.TRISA4
#define PULSE_H                 PORTAbits.RA4

#define PULSE_L_TRIS            TRISCbits.TRISC3
#define PULSE_L                 PORTCbits.RC3

//----------------------------------------------------------------------------
// DIR PULSE MOTEURS
//----------------------------------------------------------------------------
#define PULSE_H_DIR_TRIS       TRISCbits.TRISC6
#define PULSE_H_DIR            PORTCbits.RC6

#define PULSE_L_DIR_TRIS       TRISBbits.TRISB9
#define PULSE_L_DIR            PORTBbits.RB9

//----------------------------------------------------------------------------
// MCLR ESCLAVES
//----------------------------------------------------------------------------
#define MCLR_SLAVE_TRIS         TRISAbits.TRISA9
#define MCLR_SLAVE              LATAbits.LATA9

//----------------------------------------------------------------------------
// I2C
//----------------------------------------------------------------------------
#define I2C_SDA_TRIS            TRISBbits.TRISB5
#define I2C_SDA                 LATBbits.LATB5
#define I2C_SDA_IN              PORTBbits.RB5

#define I2C_SCL_TRIS            TRISBbits.TRISB6
#define I2C_SCL                 LATBbits.LATB6

//----------------------------------------------------------------------------
// DETECT MODEM
//----------------------------------------------------------------------------
#define DETECT_MODEM_TRIS       TRISBbits.TRISB10
#define DETECT_MODEM            PORTBbits.RB10


//----------------------------------------------------------------------------
// SPARE M
//----------------------------------------------------------------------------
#define SPARE_M_TRIS            TRISCbits.TRISC4
#define SPARE_M                 LATCbits.LATC4




#endif

#endif	

