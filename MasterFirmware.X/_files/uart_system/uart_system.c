#include <_Global_Include.h>






// <editor-fold defaultstate="collapsed" desc="Declarations">

// <editor-fold defaultstate="collapsed" desc="IT">
u16  uarts_it_timer;
volatile u8   uarts_reset[15];

u16 uarts_it_index_tx = 0x00;
u16 uarts_it_index_rx = 0x00;
u8  uarts_it_buffer[UARTS_IT_BUFFER_SIZE];
u16 uarts_it_get_count(void);
u8  uarts_it_read_byte(void);
void uarts_it_clear(void);
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="RX construct">
typedef enum
{
  UARTS_CONSTRUCT_RX_INIT,  
  UARTS_CONSTRUCT_RX_IDLE,
  UARTS_CONSTRUCT_RX_SIZEH,
  UARTS_CONSTRUCT_RX_SIZEL,
  UARTS_CONSTRUCT_RX_PACKET,
  UARTS_CONSTRUCT_RX_ANALYSE,
  UARTS_CONSTRUCT_RX_SEND1,
  UARTS_CONSTRUCT_RX_SEND2,
  UARTS_CONSTRUCT_RX_WAIT_TREATMENT,   
  UARTS_CONSTRUCT_RX_NO_BROADCAST,        
  UARTS_CONSTRUCT_RX_BROADCAST,   
  UARTS_CONSTRUCT_ERROR_WAIT_TREATMENT,         
  UARTS_CONSTRUCT_RX_NOP,   
  
  UARTS_CONSTRUCT_RX_INIT_CHECK_BTLD,   
  
          
}enum_uarts_construct_rx_sm;

u16  uarts_construct_rx_timer;
u16  uarts_construct_rx_timer_busy;

u8   uarts_construct_rx_state;
u16  uarts_construct_rx_packet_size;
bool uarts_construct_rx_busy;
u8   uarts_construct_rx_busy_src_type;
u32  uarts_construct_rx_busy_src_addr;
u8   uarts_construct_rx_busy_id;
s_uart_packet_system uarts_construct_rx_packet;
s_uart_packet_system* uarts_construct_send_packet_ptr;
bool uarts_construct_rx_error_mode;



void uarts_construct_desactive(void);
void uarts_construct_active(void);


// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="RX treatment">
typedef enum
{
  UARTS_TREATMENT_RX_INIT,    
  UARTS_TREATMENT_RX_IDLE,    
  UARTS_TREATMENT_RX_GO,  
  UARTS_TREATMENT_RX_GET_STATUS,  
          
  UARTS_TREATMENT_RX_GET_SENSORS1,
  UARTS_TREATMENT_RX_GET_SENSORS2,
  UARTS_TREATMENT_RX_GET_SENSORS3,      
          
  UARTS_TREATMENT_RX_GET_SHUNT1,
  UARTS_TREATMENT_RX_GET_SHUNT2,
  UARTS_TREATMENT_RX_GET_SHUNT3,  
          
  UARTS_TREATMENT_RX_FORCE_MOTOR1,
  UARTS_TREATMENT_RX_FORCE_MOTOR2,
  UARTS_TREATMENT_RX_FORCE_MOTOR3,    
          
  UARTS_TREATMENT_RX_INIT_PULSES1,
  UARTS_TREATMENT_RX_INIT_PULSES2,
  UARTS_TREATMENT_RX_INIT_PULSES3,             
}enum_uarts_treatment_rx_sm;


u16  uarts_treatement_rx_timer;
bool uarts_treatment_rx_busy;
u32  uarts_treatment_rx_addr;
s_uart_packet_system uarts_treatment_rx_packet;
s_uart_packet_system uarts_treatment_tx_packet;
void uarts_treatment_rx_go(void);
u8 uarts_treatment_rx_state = UARTS_TREATMENT_RX_INIT;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="TX treatment">
typedef enum
{
  UARTS_TX_MGMT_INIT,   
  UARTS_TX_MGMT_IDLE, 
  UARTS_TX_MGMT_WAIT_FREE_BUS,     
  UARTS_TX_MGMT_SEND_INIT,  
  UARTS_TX_MGMT_SEND_WAIT_CONFLICT,        
  UARTS_TX_MGMT_SEND_PACKET,
  UARTS_TX_MGMT_WAIT_ANSWER,
  UARTS_TX_MGMT_ERROR,
          
          
          
          
}enum_uarts_tx_mgmt_sm;

bool uarts_tx_mgmt_mutex;
bool uarts_tx_mgmt_busy;
u16  uarts_tx_mgmt_id = 0x01;

u16  uarts_tx_mgmt_timer;
u8   uarts_tx_mgmt_state;
bool uarts_tx_mgmt_error;
u8   uarts_tx_mgmt_retry;
bool uarts_tx_mgmt_wait_answer = FALSE;
bool uarts_tx_mgmt_answer_received = FALSE;
s_uart_packet_system uarts_tx_mgmt_packet_rx;
s_uart_packet_system uarts_tx_mgmt_packet_tx;

eeprom_read_event uarts_tx_eeprom_event;




// </editor-fold>


volatile u16 timer100_re_de = 0x00;

bool uarts_is_bus_free(void);
bool uarts_send_packet(s_uart_packet_system *pk);


// </editor-fold>


void uarts_init_re_de(void)
{
    UART_BOARD_RE = 0;
    __delay_us(1000);
    UART_BOARD_DE = 0;
    __delay_us(1000);
    UART_BOARD_RE = 1;
    __delay_us(1000);
    UART_BOARD_DE = 1;
    __delay_us(1000);
    UART_BOARD_RE = 0;
    __delay_us(1000);
    UART_BOARD_DE = 0;
    __delay_us(1000);
        
    UART_BOARD_RE = 0;
    UART_BOARD_DE = 0;
}
void uarts_init(void)
{
    volatile u32 uxbrg_calc = 0;

    UART_BOARD_RX_TRIS = INPUT;
    UART_BOARD_RE_TRIS = OUTPUT;
    UART_BOARD_DE_TRIS = OUTPUT;
    UART_BOARD_TX_TRIS = OUTPUT;
    
    uarts_init_re_de();

    #ifdef BOARD_RELEASE_D
    RPINR19bits.U2RXR     = 18;   // 
    RPOR1bits.RP36R       = 0x03; // 
    #endif
    
    uxbrg_calc            = ((FP) / (4 * UARTS_BAUDRATE)) -1 ; 

    U2MODEbits.UARTEN     = FALSE;
    U2MODEbits.USIDL      = FALSE;
    U2MODEbits.UEN        = 0;
    U2MODEbits.BRGH       = TRUE;
    U2BRG                 = uxbrg_calc;    
    U2MODEbits.UARTEN     = TRUE; 
    U2MODEbits.LPBACK     = FALSE;
    U2STAbits.UTXEN       = TRUE;
    
    IEC1bits.U2RXIE       = TRUE;
    IFS1bits.U2RXIF       = FALSE;
    
    uarts_it_index_tx                = 0x00;
    uarts_it_index_rx                = 0x00;
    uarts_construct_rx_busy          = FALSE;
    uarts_construct_rx_busy_src_type = 0xFF;
    uarts_construct_rx_busy_src_addr = 0xFFFFFFFF;
    uarts_construct_rx_busy_id       = 0xFF;
                
    timer1ms_register_variable((u16*)&uarts_it_timer);        
    timer1ms_register_variable((u16*)&uarts_construct_rx_timer);
    timer100ms_register_variable((u16*)&uarts_construct_rx_timer_busy);
    timer100ms_register_variable((u16*)&timer100_re_de);
    timer100_re_de = 3000;
    
    uarts_construct_rx_state = UARTS_CONSTRUCT_RX_INIT;
    uarts_construct_rx_busy = FALSE;
    
    timer1ms_register_variable((u16*)&uarts_treatement_rx_timer);
    uarts_treatment_rx_state = UARTS_TREATMENT_RX_INIT;
    uarts_treatment_rx_busy = FALSE;
    
    uarts_tx_mgmt_state = UARTS_TX_MGMT_INIT;
    uarts_tx_mgmt_mutex = TRUE;
    uarts_tx_mgmt_busy  = FALSE;
    uarts_tx_mgmt_wait_answer = FALSE;
    timer1ms_register_variable((u16*)&uarts_tx_mgmt_timer);   
}

// <editor-fold defaultstate="collapsed" desc="Low level">
void __attribute__((interrupt, auto_psv)) _U2RXInterrupt(void) 
{
    volatile u8 value = 0x00;
    volatile u8 i = 0x00;
    
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
    while(U2STAbits.URXDA)
    {
        uarts_it_timer = UARTS_BUS_FREE;
        value = U2RXREG;
        
        
        
        uarts_reset[0] = uarts_reset[1];
        uarts_reset[1] = uarts_reset[2];
        uarts_reset[2] = uarts_reset[3];
        uarts_reset[3] = uarts_reset[4];
        uarts_reset[4] = uarts_reset[5];
        uarts_reset[5] = uarts_reset[6];
        uarts_reset[6] = uarts_reset[7];
        uarts_reset[7] = uarts_reset[8];
        uarts_reset[8] = uarts_reset[9];
        uarts_reset[9] = uarts_reset[10];
        uarts_reset[10] = uarts_reset[11];
        uarts_reset[11] = uarts_reset[12];
        uarts_reset[12] = uarts_reset[13];
        uarts_reset[13] = uarts_reset[14];
        uarts_reset[14] = value;

        if(uarts_reset[0] == '*' &&
           uarts_reset[1] == '*' &&
           uarts_reset[2] == 'R' &&
           uarts_reset[3] == 'E' &&
           uarts_reset[4] == 'S' &&
           uarts_reset[5] == 'E' &&
           uarts_reset[6] == 'T' &&
           uarts_reset[7] == '*' &&
           uarts_reset[8] == 'r' &&
           uarts_reset[9] == 'e' &&
           uarts_reset[10] == 's' &&
           uarts_reset[11] == 'e' &&
           uarts_reset[12] == 't' &&
           uarts_reset[13] == '*' &&
           uarts_reset[14] == '*'     
          )
        {
            __asm__ volatile ("reset"); 
        }
               
        
        
        if(uarts_it_index_tx < UARTS_IT_BUFFER_SIZE)
        {
            
            uarts_it_buffer[uarts_it_index_tx++] = value;
        }
    }
    IFS1bits.U2RXIF  = FALSE;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
bool uarts_is_bus_free(void)
{
    if(uarts_it_timer == 0x00) return TRUE;
    else return FALSE;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uarts_it_clear(void)
{
    
    IEC1bits.U2RXIE       = FALSE;
    for(uarts_it_index_tx= 0;uarts_it_index_tx<UART_PACKET_SYSTEM_SIZE;uarts_it_index_tx++)
    {
        uarts_it_buffer[uarts_it_index_tx] = 0xFF;
    }
    uarts_it_index_tx     = 0x00;
    uarts_it_index_rx     = 0x00;
    IEC1bits.U2RXIE       = TRUE;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u16 uarts_it_get_count(void)
{
    u16 temp16 = 0x00;
    IEC1bits.U2RXIE       = FALSE;
    temp16 = (uarts_it_index_tx - uarts_it_index_rx);
    IEC1bits.U2RXIE       = TRUE;
    return temp16;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u8  uarts_it_read_byte(void)
{
    u8 temp8;
    
    if(uarts_it_get_count() > 0)
    {
        IEC1bits.U2RXIE       = FALSE;
        if(uarts_it_index_rx < UART_PACKET_SYSTEM_SIZE) temp8 =  uarts_it_buffer[uarts_it_index_rx++];
        else temp8 = 0x00;
        IEC1bits.U2RXIE       = TRUE;
        return temp8;
    }
    else return 0x00;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
bool uarts_send_packet(s_uart_packet_system *pk)
{
    u16 size;
    u16 index;
    u8 byte_tx;
    u8 byte_rx;
    
    
    
    size = uart_packet_system_get_size(pk);
    
    
    if(size < (_UART_PACKET_PACKET_ORDER+3)) return TRUE;
    
    IEC1bits.U2RXIE       = FALSE;
    
    if (IFS1bits.U2RXIF == 1)
    {
        if(U2STAbits.PERR) U2STAbits.PERR = FALSE;
        if(U2STAbits.OERR) U2STAbits.OERR = FALSE;
        if(U2STAbits.FERR) U2STAbits.FERR = FALSE;
        
        byte_rx = U2RXREG;
        IFS1bits.U2RXIF = 0;
        IEC1bits.U2RXIE = TRUE;
        return FALSE;
    }
    UART_BOARD_RE = 0;
    UART_BOARD_DE = 1;
    __delay_us(100);
   
    index = 0x00;
    do
    {
        ClrWdt(); 
        if (U2STAbits.TRMT == 1)
        {
            byte_tx = pk->buffer[index++];
            U2TXREG = byte_tx;
            while(U2STAbits.TRMT == 0x00) ClrWdt();
            __delay_us(30);
            if (IFS1bits.U2RXIF == 1)
            {
                if(U2STAbits.PERR) U2STAbits.PERR = FALSE;
                if(U2STAbits.OERR) U2STAbits.OERR = FALSE;
                if(U2STAbits.FERR) U2STAbits.FERR = FALSE;
                byte_rx = U2RXREG;
                IFS1bits.U2RXIF = 0;
                
                if(byte_rx != byte_tx)
                {
                    UART_BOARD_RE = 0;
                    UART_BOARD_DE = 0;
                    IEC1bits.U2RXIE = TRUE;
                    return FALSE;
                }
            }
            else
            {
                UART_BOARD_RE = 0;
                UART_BOARD_DE = 0;
                IEC1bits.U2RXIE = TRUE;
                return FALSE;
            }
        }
    }while(index < size);
    
    
    UART_BOARD_RE = 0;
    UART_BOARD_DE = 0;
    IEC1bits.U2RXIE = TRUE;
    return TRUE;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="RX construct">

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uarts_construct_rx_short_answer(u8 order)
{
    uart_packet_system_init((s_uart_packet_system*)&uarts_construct_rx_packet,
                             UARTS_TYPE_USB,
                             serial_number_u32,
                             uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet),
                             uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet),
                             uart_packet_system_get_id((s_uart_packet_system*)&uarts_construct_rx_packet),
                             order);
    uart_packet_system_finalise((s_uart_packet_system*)&uarts_construct_rx_packet);
}


void uarts_construct_desactive(void)
{
    uarts_it_clear();
    IEC1bits.U2RXIE = TRUE;
    UART_BOARD_RE = 0;
    UART_BOARD_DE = 0;
    uarts_construct_rx_state = UARTS_CONSTRUCT_RX_NOP;
}

void uarts_construct_active(void)
{
    uarts_construct_rx_state = UARTS_CONSTRUCT_RX_INIT;
}

void uarts_sm_construct_rx(void)
{
    volatile u8 received_byte;
    volatile u16 temp16;
    u8 next_state = uarts_construct_rx_state;

    
    if(timer100_re_de == 0x00)
    {
        timer100_re_de = 3000;
        uarts_init_re_de();
    }
    
    switch(uarts_construct_rx_state)
    {
        case UARTS_CONSTRUCT_RX_NOP:
            break;
        case UARTS_CONSTRUCT_RX_INIT:
            IEC1bits.U2RXIE = TRUE;
            UART_BOARD_RE = 0;
            UART_BOARD_DE = 0;
            uarts_it_clear();
            uarts_construct_rx_packet.buffer_index = 0x00;
            next_state = UARTS_CONSTRUCT_RX_IDLE;
            break;
            
        case UARTS_CONSTRUCT_RX_IDLE:
            if(uarts_it_get_count()>0)
            {
                received_byte = uarts_it_read_byte();
                if(received_byte == 'X')
                {
                    uarts_construct_rx_timer = UARTS_BYTE_TIMEOUT;
                    uarts_construct_rx_packet.buffer_index = 0x00;
                    uarts_construct_rx_packet.buffer[uarts_construct_rx_packet.buffer_index++] = received_byte;
                    next_state = UARTS_CONSTRUCT_RX_SIZEH;
                }
            }
            break;
            
        case UARTS_CONSTRUCT_RX_SIZEH:
            if(uarts_construct_rx_timer == 0x00)
            {
                next_state = UARTS_CONSTRUCT_RX_INIT;
            }
            else if(uarts_it_get_count()>0)
            {
                uarts_construct_rx_timer = UARTS_BYTE_TIMEOUT;
                received_byte = uarts_it_read_byte();
                uarts_construct_rx_packet.buffer[uarts_construct_rx_packet.buffer_index++] = received_byte;
                uarts_construct_rx_packet_size = received_byte;
                uarts_construct_rx_packet_size <<=8;
                next_state = UARTS_CONSTRUCT_RX_SIZEL;
            }
            break;
        
        case UARTS_CONSTRUCT_RX_SIZEL:
            if(uarts_construct_rx_timer == 0x00)
            {
                next_state = UARTS_CONSTRUCT_RX_INIT;
            }
            else if(uarts_it_get_count()>0)
            {
                uarts_construct_rx_timer = UARTS_BYTE_TIMEOUT;
                received_byte = uarts_it_read_byte();
                uarts_construct_rx_packet.buffer[uarts_construct_rx_packet.buffer_index++] = received_byte;
                uarts_construct_rx_packet_size += received_byte;
                next_state = UARTS_CONSTRUCT_RX_PACKET;
            }
            break;
            
            
        case UARTS_CONSTRUCT_RX_INIT_CHECK_BTLD:
            next_state = UARTS_CONSTRUCT_RX_INIT;
            if(uarts_construct_rx_packet.buffer_index > 10)
            {
                if(seconds_counter < 180)
                {

                    if( (uart_packet_system_get_dest_type((s_uart_packet_system*)&uarts_construct_rx_packet) == UARTS_TYPE_USB) &&
                        (uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet) >= UARTS_BTLD_ORDER_TO_USB_ERASE_M_FIRMWARE) &&
                        (uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet) <= UARTS_BTLD_ORDER_TO_USB_WRITE_S_FIRMWARE)
                      )
                    {
                        set_btldr_stop_scrolling(50);

                    }
                }
            }
            
            
            break;
            
            
        case UARTS_CONSTRUCT_RX_PACKET: 
            if(uarts_construct_rx_timer == 0x00)
            {
                next_state = UARTS_CONSTRUCT_RX_INIT_CHECK_BTLD;//UARTS_CONSTRUCT_RX_INIT;
            }
            else if(uarts_it_get_count()>0)
            {
                uarts_construct_rx_timer = UARTS_BYTE_TIMEOUT;
                received_byte = uarts_it_read_byte();
                
                if(uarts_construct_rx_packet.buffer_index < UART_PACKET_SYSTEM_SIZE)
                {
                    uarts_construct_rx_packet.buffer[uarts_construct_rx_packet.buffer_index++] = received_byte;
                    if(uarts_construct_rx_packet.buffer_index == uarts_construct_rx_packet_size)
                    {
                        // Verification du CRC
                        if(uart_packet_system_verify_crc((s_uart_packet_system*)&uarts_construct_rx_packet) == TRUE)
                        {
                            // Si le paquet est destine à un système USB
                            if (uart_packet_system_get_dest_type((s_uart_packet_system*)&uarts_construct_rx_packet) == UARTS_TYPE_USB)   
                            {
                                next_state = UARTS_CONSTRUCT_RX_ANALYSE;
                            }
                            else next_state = UARTS_CONSTRUCT_RX_INIT;
                        }
                        else
                        {
                            next_state = UARTS_CONSTRUCT_RX_INIT_CHECK_BTLD;//UARTS_CONSTRUCT_RX_INIT;
                        }
                    }
                }
                else next_state = UARTS_CONSTRUCT_RX_INIT_CHECK_BTLD;//UARTS_CONSTRUCT_RX_INIT;
            }
            break;
            
        case UARTS_CONSTRUCT_RX_ANALYSE:   
            if(uarts_tx_mgmt_wait_answer)
            {
                uarts_tx_mgmt_answer_received = TRUE;
                uart_packet_system_clone((s_uart_packet_system*)&uarts_construct_rx_packet,(s_uart_packet_system*)&uarts_tx_mgmt_packet_rx);
                next_state = UARTS_CONSTRUCT_RX_INIT;
            }
            else
            {
                // Si il s'agit d'un ordre de découverte du numéro de série.
                if( (uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet) >= UARTS_BTLD_ORDER_TO_USB_ERASE_M_FIRMWARE) &&
                    (uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet) <= UARTS_BTLD_ORDER_TO_USB_WRITE_S_FIRMWARE)
                  )
                {
                    set_btldr_stop_scrolling(50);
                    next_state = UARTS_CONSTRUCT_RX_INIT;
                }
                else if(uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet) == UARTS_FIRMWARE_ORDER_TO_USB_GET_SERIAL_AND_FIRMWARES)
                {
                    if(uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD] == usb_with_modem)
                    {   
                        if(uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+1] == 0x01)
                        {
                            global_dt_sync_ok = TRUE;
                            global_dt_year    = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+2];
                            global_dt_month   = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+3];
                            global_dt_days    = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+4];
                            global_dt_hours   = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+5];
                            global_dt_minuts  = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+6];
                            global_dt_seconds = uarts_construct_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+7];
                        }
                        
                        
                        uart_packet_system_init((s_uart_packet_system*)&uarts_construct_rx_packet,
                                                UARTS_TYPE_USB,
                                                serial_number_u32,
                                                uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet),
                                                uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet),
                                                uart_packet_system_get_id((s_uart_packet_system*)&uarts_construct_rx_packet),
                                                uart_packet_system_get_order((s_uart_packet_system*)&uarts_construct_rx_packet)); 
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,serial_number_u32>>24);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,serial_number_u32>>16);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,serial_number_u32>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,serial_number_u32 & 0x00FF);
                        
                        temp16 = get_master_firmware();
                        
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,temp16>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,temp16 & 0x00FF);
                                
                        if(slaveH_firmware == 0x0000) uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,0x00);
                        else uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,0x01);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,slaveH_firmware>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,slaveH_firmware & 0x00FF);
                        if(slaveL_firmware == 0x0000) uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,0x00);
                        else uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,0x01);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,slaveL_firmware>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_construct_rx_packet,slaveL_firmware & 0x00FF); 
                        uart_packet_system_finalise((s_uart_packet_system*)&uarts_construct_rx_packet);
                        uarts_construct_send_packet_ptr = &uarts_construct_rx_packet;
                        next_state = UARTS_CONSTRUCT_RX_SEND1;
                    }
                    else next_state = UARTS_CONSTRUCT_RX_INIT;
                }
                
                // Si l'adresse est la bonne
                else if ( (uart_packet_system_get_dest_addr((s_uart_packet_system*)&uarts_construct_rx_packet) == serial_number_u32) ||
                          (uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet) == UARTS_TYPE_TESTER)
                        )
                { 
                    if(uarts_construct_rx_busy == FALSE)
                    {
                        // Si le paquet a déjà été traité
                        if(   (uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_type) &&
                              (uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_addr) &&  
                              (uart_packet_system_get_id((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_id)  
                           )
                        {
                            uarts_construct_send_packet_ptr = &uarts_treatment_tx_packet;
                            next_state = UARTS_CONSTRUCT_RX_SEND1;
                        }
                        else
                        {
                            if(uarts_treatment_rx_busy == FALSE)
                            {
                                // Flag pour indiquer que la machine de COM est maintenant occupée
                                uarts_construct_rx_busy          = TRUE;
                                uarts_construct_rx_timer_busy    = 50;

                                // Sauvegarde des identifiants du paquet
                                uarts_construct_rx_busy_src_type = uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet);
                                uarts_construct_rx_busy_src_addr = uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet);
                                uarts_construct_rx_busy_id       = uart_packet_system_get_id((s_uart_packet_system*)&uarts_construct_rx_packet);

                                // Flag pour indiquer que la machine de traitement est maintenant busy
                                uarts_treatment_rx_busy = TRUE;
                                // Copie du paquet reçu vers la machine de traitement
                                uart_packet_system_clone((s_uart_packet_system*)&uarts_construct_rx_packet,
                                                         (s_uart_packet_system*)&uarts_treatment_rx_packet);

                                // Initialisation du compteur de temps pour la gestion des timeouts (temps de traitement)
                                if(test_mode) uarts_construct_rx_timer = (UARTS_TREATMENT_TIMEOUT*20);
                                else uarts_construct_rx_timer = UARTS_TREATMENT_TIMEOUT;

                                // Lancement de la machine de traitement
                                uarts_treatment_rx_go();
                                next_state = UARTS_CONSTRUCT_RX_WAIT_TREATMENT;
                            }
                            else
                            {
                                next_state = UARTS_CONSTRUCT_RX_INIT;
                            }
                        }
                    }
                    else
                    {
                       if(uarts_construct_rx_timer_busy == 0x00)
                       {
                            uarts_construct_rx_busy_src_type = 0xFF;
                            uarts_construct_rx_busy_src_addr = 0xFFFFFFFF;
                            uarts_construct_rx_busy_id       = 0xFF;
                            uarts_construct_rx_busy          = FALSE;
                            next_state                       = UARTS_CONSTRUCT_RX_INIT;
                       }
                       else
                       {
                           // Si le paquet reçu contient les mêmes informations que le paquet en cours de traitement
                            if(   (uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_type) &&
                                  (uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_addr) &&  
                                  (uart_packet_system_get_id((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_id)  

                               )
                            {
                                if(uarts_treatment_rx_busy == FALSE)
                                {
                                    uarts_construct_send_packet_ptr = &uarts_treatment_tx_packet;
                                    next_state = UARTS_CONSTRUCT_RX_SEND1;
                                }
                                else
                                {
                                    uarts_construct_rx_timer = 0;
                                    next_state = UARTS_CONSTRUCT_RX_WAIT_TREATMENT;
                                }
                            }
                            // Sinon
                            else // ERREUR
                            {
                                if(   (uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_type) &&
                                      (uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_construct_rx_packet) == uarts_construct_rx_busy_src_addr)) 
                                {
                                    /*uarts_construct_rx_error_mode = TRUE;    
                                    uarts_construct_rx_short_answer(UARTS_STATUS_ERROR);
                                    uarts_construct_send_packet_ptr = &uarts_construct_rx_packet;
                                    next_state = UARTS_CONSTRUCT_RX_SEND1;*/
                                    uarts_construct_rx_timer_busy    = 0xFF;
                                    uarts_construct_rx_busy_src_type = 0xFF;
                                    uarts_construct_rx_busy_src_addr = 0xFFFFFFFF;
                                    uarts_construct_rx_busy_id       = 0xFF;
                                    uarts_construct_rx_busy          = FALSE;
                                    next_state                       = UARTS_CONSTRUCT_RX_INIT;
                                }
                                else
                                {
                                    uarts_construct_rx_short_answer(UARTS_STATUS_BUSY_OTHER_SYSTEM);
                                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_construct_rx_packet);
                                    uarts_construct_send_packet_ptr = &uarts_construct_rx_packet;
                                    next_state = UARTS_CONSTRUCT_RX_SEND1; 
                                }
                            } 
                       }
                    }
                }
                else next_state = UARTS_CONSTRUCT_RX_INIT;
            }
            break;
            
        case UARTS_CONSTRUCT_RX_SEND1:        
            uarts_construct_rx_timer = UARTS_CONSTRUCT_TEMPO_TX;
            next_state = UARTS_CONSTRUCT_RX_SEND2;
            break;
                    
        case UARTS_CONSTRUCT_RX_SEND2:
            if(uarts_construct_rx_timer == 0x00)
            {
                uarts_send_packet((s_uart_packet_system*)uarts_construct_send_packet_ptr);
                if(uarts_construct_send_packet_ptr == &uarts_treatment_tx_packet)
                {
                    if(uarts_construct_rx_busy == TRUE)
                    {
                        uarts_construct_rx_timer_busy = 0x00;
                        uarts_construct_rx_busy       = FALSE;
                    }
                }
                next_state = UARTS_CONSTRUCT_RX_INIT;
            }
            break;
            
        case UARTS_CONSTRUCT_RX_WAIT_TREATMENT:
            if(uarts_construct_rx_timer == 0x00)
            {
                if(test_mode == FALSE)
                {
                   uarts_construct_rx_short_answer(UARTS_STATUS_BUSY);
                   uart_packet_system_finalise((s_uart_packet_system*)&uarts_construct_rx_packet);
                   uarts_construct_send_packet_ptr = &uarts_construct_rx_packet;
                   next_state = UARTS_CONSTRUCT_RX_SEND1;
                }
                else
                {
                    next_state = UARTS_CONSTRUCT_RX_INIT;
                }
            }
            else if(uarts_treatment_rx_busy == FALSE)
            {
                uarts_construct_send_packet_ptr = &uarts_treatment_tx_packet;
                next_state = UARTS_CONSTRUCT_RX_SEND1;
            }
            break;
            
      
            
        case UARTS_CONSTRUCT_ERROR_WAIT_TREATMENT:
            break;
    }
    uarts_construct_rx_state = next_state;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="RX treatment">
//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uarts_treatment_rx_go(void)
{
    uarts_treatment_rx_state = UARTS_TREATMENT_RX_GO;
    
}



//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uarts_sm_treatment_rx(void)
{
    i8 ret_mem;
    u8 order;
    u8 temp8;
    u16 temp16;
    u32 temp32;
    u8 next_state = uarts_treatment_rx_state;
    switch(uarts_treatment_rx_state)
    {
        case UARTS_TREATMENT_RX_INIT:
            
            if(uarts_treatment_rx_busy)
            {
               uarts_treatement_rx_timer = UARTS_TREATMENT_WAIT_MASTER;
               uarts_treatment_rx_busy = FALSE;
            }
            next_state = UARTS_TREATMENT_RX_IDLE;
            
            break;
            
        case UARTS_TREATMENT_RX_IDLE:
            
            break;
        
        case UARTS_TREATMENT_RX_GO:
            
            uart_packet_system_init((s_uart_packet_system*)&uarts_treatment_tx_packet,
                                            UARTS_TYPE_USB,
                                            serial_number_u32,
                                            uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            uart_packet_system_get_id((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            uart_packet_system_get_order((s_uart_packet_system*)&uarts_treatment_rx_packet));
            
            uarts_treatement_rx_timer = 0;
            
            order = uart_packet_system_get_order((s_uart_packet_system*)&uarts_treatment_rx_packet);
            
            switch(order)
            {
                case UARTS_FIRMWARE_ORDER_TO_USB_GET_STATUS:
                    ClrWdt();
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,usb_with_modem);

                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(serial_number_u32>>24));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(serial_number_u32>>16));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(serial_number_u32>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(serial_number_u32 & 0x00FF));

                    temp16 = get_master_firmware();
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(temp16>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(temp16 & 0x00FF));
                    ClrWdt();
                    
                    
                    

                    
                    
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(slaveH_firmware>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(slaveH_firmware & 0x00FF));

                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(slaveL_firmware>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(slaveL_firmware & 0x00FF));

                    ClrWdt();
                    temp16 = adc_ctn;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    temp16 = adc_vbat;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    

                    
                    
                    
                    temp16 = motor_status.motorh_pic_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    temp16 = motor_status.motorh_bridge_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    
                    /*uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_pulsesH>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_pulsesH & 0x00FF));

                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_pulsesL>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_pulsesL & 0x00FF));*/
                    
                    
                    
                    
                    
                    temp16 = motor_status.motorl_pic_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    temp16 = motor_status.motorl_bridge_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    ClrWdt();
                    
                    
                    /*uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_light1_state>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_light1_state & 0x00FF));

                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_light2_state>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(error_light2_state & 0x00FF));*/
                    
                    
                    

                    temp8 = door_opened;
                    temp8 <<=1;
                    temp8 += RELAY;
                    temp8 <<=1;
                    temp8 += motorh_switch;
                    temp8 <<=1;
                    temp8 += motorl_switch;
                    temp8 <<=1;
                    temp8 += cell_feature;
                    temp8 <<=1;
                    temp8 += pulses_feature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,motorh_type);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,motorl_type);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,motor_algo_mode);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(motor_auto_cycle_count>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(motor_auto_cycle_count & 0x00FF));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,motor_init_poster_count);

                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_code);

                    if(synchro_ext_mode)
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                    }
                    else
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                    }
                    
                    
                    temp8 = temporary_stop;
                    temp8 <<= 1;
                    temp8 += error_order_preauto;
                    temp8 <<= 1;
                    temp8 += motor_auto_cycle_reset;
                    temp8 <<= 1;
                    temp8 += slave_status_mcu_high_temp;
                    temp8 <<= 1;
                    temp8 += slave_status_bridge_high_temp;
                    temp8 <<= 1;
                    temp8 += adc_ctn_high_temp;
                    temp8 <<= 1;
                    temp8 += door_opened_error;
                    temp8 <<= 1;
                    temp8 += adc_low_battery;
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8); 

                    
                    
                    
                    
                    
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_light[0]);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_light[1]);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_light[2]);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_light[3]);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,error_light[4]);
                    
                    if(error_type == NO_ERROR)
                    {
                        temp8 = slave_com_authorization;
                        temp8<<=1;
                        temp8 += motor_drive_authorization;
                        temp8<<=1;
                        temp8 += slave_status_bridge_emergency_temp;
                        
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)temp8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)motor_init_state);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(0x00)); 
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(0x00));
                    }
                    else
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(error_id_u32>>24)); 
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(error_id_u32>>16)); 
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(error_id_u32>>8)); 
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(error_id_u32 & 0x00FF));
                    }
                   
                    
                    // Remontee des vitesses de compensation
                    temp8 = motor.enrh_dock_speed_incr;
                    temp8<<=4;
                    temp8 += motor.enrl_dock_speed_incr;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(temp8)); 
                    
                    
                    
                    if(error_code != ERROR_NONE)
                    {
                        temp8 = error_mode;
                        temp8<<=3;
                        temp8 += error_poster;
                        temp8<<=2;
                        temp8 += error_direction;
                        
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)temp8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)error_state);
                    
                    }
                    else if(motor_algo_mode ==  INIT_MODE)
                    {
                        temp8 = uart_motor_protocole_is_mutex_free();
                        temp8<<=1;
                        temp8 += motor_critical_drive;
                        temp8<<=1;
                        temp8 += motor_auto_scrolling;
                                
 
                        
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)temp8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)motor_init_state);
                        
                    }
                    else if(motor_algo_mode >=  PREAUTO_MODE)
                    {
                        
                        
                        temp8 = motor_auto_cycle_state;
                        temp8<<=4;
                        temp8 += motor_auto_cycle_reset;
                        temp8<<=1;
                        temp8 += motor_auto_cycle_init_param;
                        temp8<<=1;
                        temp8 += error_order_preauto;
                        temp8<<=1;
                        temp8 += uart_motor_protocole_is_mutex_free();
                                
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)temp8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)motor_auto_state);
                        
                    }
                    else
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)0x00);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)0x00);
                    }
                    //temp8<<=1;
                    //temp8+= motor_auto_scrolling;
                    
                    
                        
                    
                    
                    
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_SUPPLY_VOLTAGE:
                    temp16 = adc_vbat;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_FORCE_MOTOR_OUTPUT:
                    next_state = UARTS_TREATMENT_RX_FORCE_MOTOR1;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_MOTOR_SHUNT:
                    next_state = UARTS_TREATMENT_RX_GET_SHUNT1;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_MOTOR_SENSORS:
                    next_state = UARTS_TREATMENT_RX_GET_SENSORS1;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_TEMP:
                    temp16 = adc_ctn;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    temp16 = motor_status.motorh_bridge_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    temp16 = motor_status.motorl_bridge_temperature;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_FIRMWARES:
                        temp16 = get_master_firmware();
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp16 & 0x00FF);   
                        if(slaveH_firmware == 0x0000) uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                        else uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,slaveH_firmware>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,slaveH_firmware & 0x00FF);
                        if(slaveL_firmware == 0x0000) uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                        else uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,slaveL_firmware>>8);
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,slaveL_firmware & 0x00FF);
                        uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                        ClrWdt();
                        next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_MEMORY:
                    ret_mem = eeprom_var8_read(EEPROM_VAR8_TEST);
                    if(ret_mem == 0x01)
                    {
                        if(test_flash_var == 0x55) test_flash_var = 0xAA;
                        else test_flash_var = 0x55;
                            
                        temp8 = test_flash_var;
                        
                        ret_mem = eeprom_var8_update(EEPROM_VAR8_TEST);
                        if(ret_mem == 0x01)
                        {
                            test_flash_var+=0x1;
                            
                            ret_mem = eeprom_var8_read(EEPROM_VAR8_TEST);
                            if(ret_mem == 0x01)
                            {
                                if(temp8 == test_flash_var)
                                {
                                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                                }
                                else
                                {
                                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                                }
                            }
                            else
                            {
                                uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                            }
                        }
                        else
                        {
                            uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                        }
                    }
                    else
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                    }
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_STOP_SCROLLING:
                    set_btldr_stop_scrolling(1200);
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_MODE_ENTER:
                    test_mode = TRUE;
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_SERIAL:
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(serial_number_u32>>24));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(serial_number_u32>>16));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(serial_number_u32>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(serial_number_u32 & 0x00FF));
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
               
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_INIT_PULSES:
                    timer_pulses_set_globalH(1000);
                    timer_pulses_set_globalL(1000);
                    timer_pulses_clear();
                    /*uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;*/
                    next_state = UARTS_TREATMENT_RX_INIT_PULSES1;
                    break;
                
   
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_PULSES:
                    temp16 = timer_pulses_get_globalH();
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(temp16>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(temp16&0x00FF));
                    temp16 = timer_pulses_get_globalL();
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(temp16>>8));
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,(u8)(temp16&0x00FF));
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_SET_SERIAL:
                    temp32 = uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD];
                    temp32 <<=8;
                    temp32 += uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+1];
                    temp32 <<=8;
                    temp32 += uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+2];
                    temp32 <<=8;
                    temp32 += uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+3];
                    
                    
                    serial_number[0] = (u8)(temp32>>24);
                    serial_number[1] = (u8)(temp32>>16);
                    serial_number[2] = (u8)(temp32>>8);
                    serial_number[3] = (u8)(temp32 & 0x00FF);

                    eeprom_var8_update(EEPROM_VAR8_SERIAL0);
                    eeprom_var8_update(EEPROM_VAR8_SERIAL1);
                    eeprom_var8_update(EEPROM_VAR8_SERIAL2);
                    eeprom_var8_update(EEPROM_VAR8_SERIAL3);

                    update_serial_u32();
                    
                    if(temp32 == serial_number_u32)
                    {
                       uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01); 
                    }
                    else
                    {
                        uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                    }
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);
                    ClrWdt();
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;
                    
                case UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_IO:
                    
                    temp8 = CELLULE;
                    temp8<<=1;
                    temp8+=CAPTEUR_PORTE;
                    temp8<<=1;
                    temp8+=BIT_SYNC;
                    temp8<<=1;
                    temp8+=PPS;
                    temp8<<=1;
                    temp8+=DETECT_MODEM;
                    temp8<<=1;
                    temp8+=RELAY;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                    
                    temp8 = TELE_AUTO;
                    temp8<<=1;
                    temp8 += TELE_DEROULEMENT_HAUT;
                    temp8<<=1;
                    temp8 += TELE_ENROULEMENT_HAUT;
                    temp8<<=1;
                    temp8 += TELE_ENROULEMENT_BAS;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                    
                    temp8 = SW1;
                    temp8<<=1;
                    temp8 += SW2;
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                    
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                    next_state = UARTS_TREATMENT_RX_INIT;
                    
                    break;
                    
                    
                default:
                    uart_packet_system_init((s_uart_packet_system*)&uarts_treatment_tx_packet,
                                            UARTS_TYPE_USB,
                                            serial_number_u32,
                                            uart_packet_system_get_src_type((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            uart_packet_system_get_src_addr((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            uart_packet_system_get_id((s_uart_packet_system*)&uarts_treatment_rx_packet),
                                            UARTS_STATUS_ERROR); 
                    uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                    next_state = UARTS_TREATMENT_RX_INIT;
                    break;       
            }
            break;
       
        case UARTS_TREATMENT_RX_GET_STATUS:
            
            break;
        
            
        case UARTS_TREATMENT_RX_INIT_PULSES1:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_SENSORS_TEST_MODE);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_INIT_PULSES2;
            }
            break;
            
        case UARTS_TREATMENT_RX_INIT_PULSES2:
            if(uart_motor_protocole_is_ready())
            {
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01); 
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_SENSORS_TEST_MODE);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_INIT_PULSES3;        
            }
            break;
            
        case UARTS_TREATMENT_RX_INIT_PULSES3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01); 
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                next_state = UARTS_TREATMENT_RX_INIT;
            }
            break;      
            
        case UARTS_TREATMENT_RX_FORCE_MOTOR1:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_SET_BRIDGE_OUTPUT);
                temp8= uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD];
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,temp8);

                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_FORCE_MOTOR2;
            }
            break;
            
        case UARTS_TREATMENT_RX_FORCE_MOTOR2:
            if(uart_motor_protocole_is_ready())
            {
                

                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);  
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_SET_BRIDGE_OUTPUT);
                temp8= uarts_treatment_rx_packet.buffer[_UARTS_PACKET_PAYLOAD+1];
                com_packet_add_byte((s_com_packet*)&uart_motor_protocole_packet_tx,temp8);
                
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_FORCE_MOTOR3;
                
            }
            break;
            
        case UARTS_TREATMENT_RX_FORCE_MOTOR3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01); 
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                next_state = UARTS_TREATMENT_RX_INIT;
            }
            break;    
            
            
            
            
            
            
            
            
            
        case UARTS_TREATMENT_RX_GET_SENSORS1:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_SENSORS);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_GET_SENSORS2;
            }
            break;
            
        case UARTS_TREATMENT_RX_GET_SENSORS2:
            if(uart_motor_protocole_is_ready())
            {
                

                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                    temp8 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);

                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_SENSORS);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_GET_SENSORS3;
                
            }
            break;
            
        case UARTS_TREATMENT_RX_GET_SENSORS3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                    temp8 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                next_state = UARTS_TREATMENT_RX_INIT;
            }
            break; 
            
        case UARTS_TREATMENT_RX_GET_SHUNT1:
            if(uart_motor_protocole_is_mutex_free() == TRUE)
            {
                uart_motor_protocole_take_mutex();
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEH_ADDR,UART_MOTOR_ORDER_GET_SHUNT);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_GET_SHUNT2;
            }
            break;
            
        case UARTS_TREATMENT_RX_GET_SHUNT2:
            if(uart_motor_protocole_is_ready())
            {
                

                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                    temp8 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);

                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                
                com_packet_init((s_com_packet*)&uart_motor_protocole_packet_tx,UART_MOTOR_SLAVEL_ADDR,UART_MOTOR_ORDER_GET_SHUNT);
                com_packet_finalize((s_com_packet*)&uart_motor_protocole_packet_tx);
                uart_motor_protocole_send_packet();
                next_state = UARTS_TREATMENT_RX_GET_SHUNT3;
                
            }
            break;
            
        case UARTS_TREATMENT_RX_GET_SHUNT3:
            if(uart_motor_protocole_is_ready())
            {
                uart_motor_protocole_release_mutex();
                if(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_SUCCESS)
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x01);
                    temp8 = com_packet_get_byte((s_com_packet*)&uart_motor_protocole_packet_rx,COM_PACKET_PAYLOAD_INDEX);
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,temp8);
                }
                else
                {
                    uart_packet_system_add((s_uart_packet_system*)&uarts_treatment_tx_packet,0x00);
                }
                uart_packet_system_finalise((s_uart_packet_system*)&uarts_treatment_tx_packet);                 
                next_state = UARTS_TREATMENT_RX_INIT;
            }
            break;     
    }
    uarts_treatment_rx_state = next_state;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="TX mgmt">
void uarts_tx_mgmt_packet_tx_init(u8 dest_type,u32 dest_addr,u8 order)
{
    uarts_tx_mgmt_packet_tx.buffer_index= 0x00;
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = 'X';
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = 0x00;
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = 0x00;    
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = UARTS_TYPE_USB;
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (serial_number_u32 >> 24);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (serial_number_u32 >> 16);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (serial_number_u32 >> 8);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (serial_number_u32 & 0x00FF);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = dest_type;
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (dest_addr >> 24);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (dest_addr >> 16);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (dest_addr >> 8);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = (dest_addr & 0x00FF);
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = uarts_tx_mgmt_id;
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = order;
    if(uarts_tx_mgmt_id == 0x00) uarts_tx_mgmt_id = 0x01;
}

void uarts_tx_mgmt_packet_tx_add_byte(u8 byte)
{
    uarts_tx_mgmt_packet_tx.buffer[uarts_tx_mgmt_packet_tx.buffer_index++]  = byte;
}

void uarts_tx_mgmt_packet_tx_finalize(void)
{
    uart_packet_system_finalise((s_uart_packet_system*)&uarts_tx_mgmt_packet_tx);
}

bool uarts_tx_mgmt_is_error(void)
{
    return uarts_tx_mgmt_error;
}
bool uarts_tx_mgmt_is_busy(void)
{
    return uarts_tx_mgmt_busy;
}
bool uarts_tx_mgmt_is_mutex_free(void)
{
    return uarts_tx_mgmt_mutex;
}
void uarts_tx_mgmt_get_mutex(void)
{
    uarts_tx_mgmt_mutex = FALSE;
}
void uarts_tx_mgmt_release_mutex(void)
{
    uarts_tx_mgmt_mutex = TRUE;
}

void uarts_tx_mgmt_go(u16 timeout)
{
    uarts_tx_mgmt_error = FALSE;
    uarts_tx_mgmt_busy = TRUE;
    uarts_tx_mgmt_timer = timeout;
    uarts_tx_mgmt_state = UARTS_TX_MGMT_WAIT_FREE_BUS;
}
void uarts_tx_mgmt_sm(void)
{
    u8 next_state = uarts_tx_mgmt_state;
    switch(uarts_tx_mgmt_state)
    {
        case UARTS_TX_MGMT_INIT:
            next_state = UARTS_TX_MGMT_IDLE;
            break;
            
        case UARTS_TX_MGMT_IDLE:
            uarts_tx_mgmt_wait_answer = FALSE;
            uarts_tx_mgmt_busy        = FALSE;
            break;
        
        case UARTS_TX_MGMT_WAIT_FREE_BUS:
            // Test pour savoir si le bus est toujours occupé au bout d'un certain temps.
            if(uarts_tx_mgmt_timer == 0x00)
            {
                // Retour à l'état d'init
                next_state = UARTS_TX_MGMT_ERROR;
            }
            // Sinon si le bus est libre et si la machine de récéption est au repos
            else if(uarts_is_bus_free() == TRUE && uarts_construct_rx_busy == FALSE)
            {
                next_state = UARTS_TX_MGMT_SEND_INIT;
            }
            break;
            
        case UARTS_TX_MGMT_SEND_INIT:
            uarts_tx_mgmt_retry = 0x00;
            uarts_construct_desactive();
            next_state = UARTS_TX_MGMT_SEND_PACKET;
            break;
       
        case UARTS_TX_MGMT_SEND_WAIT_CONFLICT:
            if(uarts_tx_mgmt_timer == 0x00)
            {
                next_state = UARTS_TX_MGMT_SEND_PACKET;
            }
            else if(uarts_it_get_count()>0)
            {
                uarts_it_clear();
                uarts_tx_mgmt_timer = (serial_number[3] & 0x1F);
                uarts_tx_mgmt_timer +=UARTS_BUS_FREE;
            }
            break;
            
        case UARTS_TX_MGMT_SEND_PACKET:
            if(uarts_send_packet((s_uart_packet_system*)&uarts_tx_mgmt_packet_tx) == TRUE)
            {
                uarts_it_clear();
                uarts_construct_active();
                uarts_tx_mgmt_answer_received = FALSE;
                uarts_tx_mgmt_wait_answer = TRUE;
                uarts_tx_mgmt_timer = UARTS_ANSWER_TIMEOUT;
                next_state = UARTS_TX_MGMT_WAIT_ANSWER;
            }
            else
            {
                uarts_tx_mgmt_timer = (serial_number[3] & 0x1F);
                uarts_tx_mgmt_timer +=UARTS_BUS_FREE;
                next_state = UARTS_TX_MGMT_SEND_WAIT_CONFLICT;
            }
            break;
            
        case UARTS_TX_MGMT_WAIT_ANSWER:
            if(uarts_tx_mgmt_timer == 0x00)
            {
                uarts_it_clear();
                uarts_tx_mgmt_retry++;
                if(uarts_tx_mgmt_retry > UARTS_RETRY_MAX)
                {
                    next_state = UARTS_TX_MGMT_ERROR;
                }
                else
                {
                    next_state = UARTS_TX_MGMT_SEND_PACKET;
                }
            }
            else if(uarts_tx_mgmt_answer_received)
            {
                uarts_tx_mgmt_answer_received = FALSE;
                
                if(uarts_tx_mgmt_packet_rx.buffer[_UART_PACKET_PACKET_ORDER] == uarts_tx_mgmt_packet_tx.buffer[_UART_PACKET_PACKET_ORDER])
                {
                   next_state =  UARTS_TX_MGMT_INIT;
                }
                else if(uarts_tx_mgmt_packet_rx.buffer[_UART_PACKET_PACKET_ORDER] == UARTS_STATUS_BUSY)
                {
                    uarts_tx_mgmt_timer = UARTS_ANSWER_TIMEOUT;
                    
                    next_state = UARTS_TX_MGMT_SEND_PACKET;
                }
                else
                {
                    next_state = UARTS_TX_MGMT_ERROR;
                }
            }
            break;
            
          
        case UARTS_TX_MGMT_ERROR:
            uarts_tx_mgmt_wait_answer = FALSE;
            uarts_tx_mgmt_error       = TRUE;
            next_state                = UARTS_TX_MGMT_INIT;
            break;    
        
            
            
    }
    uarts_tx_mgmt_state = next_state;
}

// </editor-fold>
