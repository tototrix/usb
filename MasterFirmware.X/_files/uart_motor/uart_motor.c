#include <_Global_Include.h>


u8   uart_motor_it_buffer[UART_MOTOR_ITRX_BUFFER_SIZE];
u16  uart_motor_it_ptr_read;
u16  uart_motor_it_ptr_write;



void uart_printf_init(void)
{
    volatile u32 uxbrg_calc = 0;
    volatile u32 calculated_baudrate;
    
    
    
    UART_BOARD_RX_TRIS = INPUT;
    UART_BOARD_RE_TRIS = OUTPUT;
    UART_BOARD_DE_TRIS = OUTPUT;
    UART_BOARD_TX_TRIS = OUTPUT;
    
    UART_BOARD_RE = 1;
    __delay_us(10000);
    UART_BOARD_DE = 1;
    __delay_us(10000);
    UART_BOARD_RE = 0;
    __delay_us(10000);
    UART_BOARD_DE = 0;
    __delay_us(10000);
    
    UART_BOARD_RE = 1;
    __delay_us(10000);
    UART_BOARD_DE = 1;
    __delay_us(10000);
    UART_BOARD_RE = 0;
    __delay_us(10000);
    UART_BOARD_DE = 0;
    __delay_us(10000);
    
    
    
#ifdef DEBUG_PRINTF
    UART_BOARD_RE = 1;
    UART_BOARD_DE = 1;
#else
    UART_BOARD_RE = 1;
    UART_BOARD_DE = 0;
#endif

    
    
    #ifdef BOARD_RELEASE_C
    RPINR19bits.U2RXR     = 51;   // 
    RPOR1bits.RP36R       = 0x03; // 
    #endif
    
    #ifdef BOARD_RELEASE_D
    RPINR19bits.U2RXR     = 18;   // 
    RPOR1bits.RP36R       = 0x03; // 
    #endif

    uxbrg_calc            = ((FP) / (4 * UART_MOTOR_BAUDRATE)) -1 ;  // UART_MOTOR_BAUDRATE
    calculated_baudrate   = (FP)/(4 * (uxbrg_calc+1));

    U2MODEbits.UARTEN     = FALSE;
    U2MODEbits.USIDL      = FALSE;
    U2MODEbits.UEN        = 0;
    U2MODEbits.BRGH       = TRUE;
    U2BRG                 = uxbrg_calc;    
    U2MODEbits.UARTEN     = TRUE; 
    U2MODEbits.LPBACK     = FALSE;
    U2STAbits.UTXEN       = TRUE;
    
    IEC1bits.U2RXIE       = FALSE;
    IFS1bits.U2RXIF       = FALSE;
       
}


//=========================================================================
// Function : Uart motor init
// Input(s) : -
// Output   : -
//=========================================================================
void uart_motor_init(void)
{
    volatile u32 uxbrg_calc = 0;
    volatile u32 calculated_baudrate;
    
    UART_MOTOR_RX_TRIS    = 1;
    UART_MOTOR_TX_TRIS    = 0;
      
    #ifdef BOARD_RELEASE_D
    RPINR18bits.U1RXR     = 39;   // RX on RP39
    RPOR3bits.RP40R       = 0x01; // TX on RP40
    #endif

    #ifdef BOARD_RELEASE_C
    RPINR18bits.U1RXR     = 37;   // RX on RP37
    RPOR2bits.RP38R       = 0x01; // TX on RP38
    #endif
    
    uxbrg_calc            = ((FP) / (4 * UART_MOTOR_BAUDRATE)) -1 ;
    calculated_baudrate   = (FP)/(4 * (uxbrg_calc+1));

    U1MODEbits.UARTEN     = FALSE;
    U1MODEbits.USIDL      = FALSE;
    U1MODEbits.UEN        = 0;
    U1MODEbits.BRGH       = TRUE;
    U1BRG                 = uxbrg_calc;    
    U1MODEbits.UARTEN     = TRUE; 
    U1MODEbits.LPBACK     = FALSE;
    U1STAbits.UTXEN       = TRUE;
    
    IEC0bits.U1RXIE       = TRUE;
    IFS0bits.U1RXIF       = FALSE;
    
    // Variables
    uart_motor_it_ptr_read   = 0x00;
    uart_motor_it_ptr_write  = 0x00;
    
}


//=========================================================================
// Function : Uart motor send byte
// Input(s) : u8 byte = byte to send
// Output   : -
//=========================================================================
void uart_motor_send_byte(u8 byte)
{
    while(U1STAbits.TRMT == 0)ClrWdt();
    __delay_us(30);
    U1TXREG = byte;
    Nop();
    Nop();
    
    while(U1STAbits.TRMT == 0)ClrWdt();
}

//=========================================================================
// Function : Efface le buffer dédié au stockage sur interruption
// Input(s) : -
// Output   : -
//=========================================================================
void uart_motor_it_clear(void)
{
    IEC0bits.U1RXIE         = FALSE;
    uart_motor_it_ptr_write = 0x00;
    uart_motor_it_ptr_read  = 0x00;
    IEC0bits.U1RXIE         = TRUE;
}

//=========================================================================
// Function : Permet d'obtenir le nombre d'octets stockés dans le buffer
//            de l'interruption
// Input(s) : -
// Output   : -
//=========================================================================
u16 uart_motor_get_it_count(void)
{
    
    if(uart_motor_it_ptr_read == uart_motor_it_ptr_write) return 0x00;
    else if(uart_motor_it_ptr_read < uart_motor_it_ptr_write) return (uart_motor_it_ptr_write-uart_motor_it_ptr_read);
    else return (UART_MOTOR_ITRX_BUFFER_SIZE - (uart_motor_it_ptr_read - uart_motor_it_ptr_write));
    
    //return (uart_motor_it_ptr_write - uart_motor_it_ptr_read);
}

//=========================================================================
// Function : Permet de lire le plus ancien octet reçu dans le buffer
//            de l'interruption (fonctionnement en FIFO)
// Input(s) : -
// Output   : u8 = octet lu
//=========================================================================
u8 uart_motor_it_read_byte(void)
{
    u8 value;
    if(uart_motor_get_it_count() > 0)
    {
        value =  uart_motor_it_buffer[uart_motor_it_ptr_read++];
        if(uart_motor_it_ptr_read >= UART_MOTOR_ITRX_BUFFER_SIZE)
        {
            uart_motor_it_ptr_read = 0x00;
        }
        return value;
    }
    else return 0x00;
}

//=========================================================================
// Function : Uart motor RX interrupt
// Input(s) : - 
// Output   : -
//=========================================================================
void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void) 
{
    volatile u8 value = 0x00;
    
    if(U1STAbits.PERR) 
    {
        U1STAbits.PERR = FALSE;
    }
    if(U1STAbits.OERR) 
    {
        U1STAbits.OERR = FALSE;
    }
    if(U1STAbits.FERR) 
    {
        U1STAbits.FERR = FALSE;
    }
    
    
    while(U1STAbits.URXDA)
    {
        value = U1RXREG;
        if(uart_motor_get_it_count() < (UART_MOTOR_ITRX_BUFFER_SIZE-1))
        {
            uart_motor_it_buffer[uart_motor_it_ptr_write++] = value;
            if(uart_motor_it_ptr_write >= UART_MOTOR_ITRX_BUFFER_SIZE) uart_motor_it_ptr_write = 0x00;
        }
        /*
        if(uart_motor_it_ptr_write < UART_MOTOR_ITRX_BUFFER_SIZE)
        {
            uart_motor_it_buffer[uart_motor_it_ptr_write++] = value;
        }*/
    }
    
    IFS0bits.U1RXIF = FALSE;
}