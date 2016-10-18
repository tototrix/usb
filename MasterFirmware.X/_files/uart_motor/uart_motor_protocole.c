#include <_Global_Include.h>





u8 uart_motor_protocole_mutex;
u8 uart_motor_protocole_status;
volatile u16 uart_motor_protocole_timer_1ms;

s_com_packet uart_motor_protocole_packet_tx;
s_com_packet uart_motor_protocole_packet_rx;

u8 uart_motor_protocole_buffer_tx[UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE];
u8 uart_motor_protocole_buffer_rx[UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER];
u16 uart_motor_protocole_buffer_rx_index;


typedef enum
{
  UART_MOTOR_PROTOCOLE_SM_IDLE,
  UART_MOTOR_PROTOCOLE_SM_TX,
  UART_MOTOR_PROTOCOLE_SM_TX2,
  UART_MOTOR_PROTOCOLE_SM_RX_HEADER,
  UART_MOTOR_PROTOCOLE_SM_RX_SIZEH,
  UART_MOTOR_PROTOCOLE_SM_RX_SIZEL,
  UART_MOTOR_PROTOCOLE_SM_RX_PACKET        
}enum_uart_motor_protocole_sm;


u8 uart_motor_protocole_sm_state;
u8 uart_motor_protocole_sm_retry;
u16 uart_motor_protocole_sm_tx_size;
u16 uart_motor_protocole_sm_rx_size;



void uart_motor_protocole_init(void)
{
    u16 i;
    uart_motor_protocole_mutex    = TRUE;
    uart_motor_protocole_status   = UART_MOTOR_PROTOCOLE_ERROR;//UART_MOTOR_PROTOCOLE_IDLE;
    
    for(i=0;i<UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE;i++) uart_motor_protocole_buffer_tx[i] = 0x00;
    for(i=0;i<UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER;i++) uart_motor_protocole_buffer_rx[i] = 0x00;
    com_packet_config((s_com_packet*)&uart_motor_protocole_packet_tx,(u8 *)&uart_motor_protocole_buffer_tx[0],UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE);
    com_packet_config((s_com_packet*)&uart_motor_protocole_packet_rx,(u8 *)&uart_motor_protocole_buffer_rx[0],UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER);

    
    
    
    timer1ms_register_variable((u16*)&uart_motor_protocole_timer_1ms);
    
    uart_motor_protocole_buffer_rx_index = 0x00;
    uart_motor_protocole_sm_state        = UART_MOTOR_PROTOCOLE_SM_IDLE;
}



bool uart_motor_protocole_is_ready(void)
{
    if(uart_motor_protocole_status != UART_MOTOR_PROTOCOLE_IN_PROGRESS) return TRUE;
    else return FALSE;
}
u8 uart_motor_protocole_get_status(void)
{
    return uart_motor_protocole_status;
}


bool uart_motor_protocole_is_mutex_free(void)
{
    return uart_motor_protocole_mutex;
}
void uart_motor_protocole_take_mutex(void)
{
    uart_motor_protocole_mutex = FALSE;
}

void uart_motor_protocole_release_mutex(void)
{
    uart_motor_protocole_mutex = TRUE;
}



void uart_motor_protocole_sm(void)
{
    u16 crc_received = 0x00;
    
    u16 temp16     = 0x00;
    u8  temp8      = 0x00;
    u8  next_state = uart_motor_protocole_sm_state;
    
    switch(uart_motor_protocole_sm_state)
    {
        case UART_MOTOR_PROTOCOLE_SM_IDLE:
            uart_motor_protocole_timer_1ms = 0x00;
            break;
            
        case UART_MOTOR_PROTOCOLE_SM_TX:
            uart_motor_protocole_status     =  UART_MOTOR_PROTOCOLE_IN_PROGRESS;
            uart_motor_protocole_sm_tx_size =  uart_motor_protocole_buffer_tx[COM_PACKET_SIZEH_INDEX];
            uart_motor_protocole_sm_tx_size <<=8;
            uart_motor_protocole_sm_tx_size +=  uart_motor_protocole_buffer_tx[COM_PACKET_SIZEL_INDEX];
            

            
            if(uart_motor_protocole_sm_tx_size > UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE)
            {
                uart_motor_protocole_status = UART_MOTOR_PROTOCOLE_ERROR;
                next_state = UART_MOTOR_PROTOCOLE_SM_IDLE;
            }
            else
            {
                uart_motor_protocole_sm_retry = 0x00;
                next_state = UART_MOTOR_PROTOCOLE_SM_TX2;              
            }
            break;
        
        case UART_MOTOR_PROTOCOLE_SM_TX2:
            if(uart_motor_protocole_timer_1ms == 0x00)
            {
                uart_motor_it_clear();
                uart_motor_protocole_buffer_rx_index = 0x00;
                
                for(temp16=0;temp16<uart_motor_protocole_sm_tx_size;temp16++)
                {
                    uart_motor_send_byte(uart_motor_protocole_buffer_tx[temp16]); 
                }
               
                
                if(uart_motor_protocole_buffer_tx[COM_PACKET_ORDER_INDEX] == UART_MOTOR_ORDER_SET_TYPE)
                {
                    uart_motor_protocole_timer_1ms = 5*UART_MOTOR_TIMEOUT_MS;
                }
                else uart_motor_protocole_timer_1ms = UART_MOTOR_TIMEOUT_MS;
                
                next_state = UART_MOTOR_PROTOCOLE_SM_RX_HEADER;
            }
            break;
        
            
            
            
        case UART_MOTOR_PROTOCOLE_SM_RX_HEADER:
            if(uart_motor_protocole_timer_1ms == 0x00)
            {

                uart_motor_protocole_sm_retry++;
                if(uart_motor_protocole_sm_retry >= UART_MOTOR_RETRY_COUNT)
                {       
                  uart_motor_protocole_status = UART_MOTOR_PROTOCOLE_ERROR;
                  next_state = UART_MOTOR_PROTOCOLE_SM_IDLE;
                }
                else
                {
                   
                   uart_motor_protocole_timer_1ms = UART_MOTOR_WAIT_MS_BEFORE_RETRY; 
                   next_state =  UART_MOTOR_PROTOCOLE_SM_TX2;
                }
            }
            else if(uart_motor_get_it_count() >0)
            {
                uart_motor_protocole_timer_1ms = UART_MOTOR_TIMEOUT_MS;
                temp8 = uart_motor_it_read_byte();
                
                switch(uart_motor_protocole_buffer_rx_index)
                {
                    
                    case COM_PACKET_HEADER_INDEX:
                        if(temp8 == 'X')
                        {
                            uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index++] = temp8;
                        }
                        break;
                        
                    case COM_PACKET_SIZEH_INDEX:
                        uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index++] = temp8;
                        uart_motor_protocole_sm_rx_size = temp8;
                        uart_motor_protocole_sm_rx_size <<=8;
                        break;
                 
                    case COM_PACKET_SIZEL_INDEX:
                        uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index++] = temp8;
                        uart_motor_protocole_sm_rx_size += temp8;
                        break;
                        
                    default:
                        if(uart_motor_protocole_buffer_rx_index < UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER)
                        {
                            uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index++] = temp8;
                            if(uart_motor_protocole_buffer_rx_index >= uart_motor_protocole_sm_rx_size)
                            {
                                crc_received = uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index-2];
                                crc_received <<=8;
                                crc_received += uart_motor_protocole_buffer_rx[uart_motor_protocole_buffer_rx_index-1];

                                temp16 = calculate_crc((u8*)&uart_motor_protocole_buffer_rx[0],uart_motor_protocole_buffer_rx_index-2);

                                // traitement du packet
                                if(crc_received == temp16) // Test du CRC
                                {
                                    uart_motor_protocole_status = UART_MOTOR_PROTOCOLE_SUCCESS;
                                    next_state = UART_MOTOR_PROTOCOLE_SM_IDLE;  
                                }
                                else
                                {
                                    uart_motor_protocole_sm_retry++;
                                    if(uart_motor_protocole_sm_retry >= UART_MOTOR_RETRY_COUNT)
                                    {       
                                      uart_motor_protocole_status = UART_MOTOR_PROTOCOLE_ERROR;
                                      next_state = UART_MOTOR_PROTOCOLE_SM_IDLE;
                                    }
                                    else
                                    {
                                      uart_motor_protocole_timer_1ms = UART_MOTOR_WAIT_MS_BEFORE_RETRY;   
                                      next_state =  UART_MOTOR_PROTOCOLE_SM_TX2;
                                    }

                                }
                            }
                        }
                        break;  
                } 
            }
            break;
    }
    uart_motor_protocole_sm_state = next_state;
}




void uart_motor_protocole_send_packet(void)
{
    uart_motor_protocole_status     =  UART_MOTOR_PROTOCOLE_IN_PROGRESS;
    uart_motor_protocole_sm_state  = UART_MOTOR_PROTOCOLE_SM_TX;
    uart_motor_protocole_timer_1ms = 0x00;
}

u8 uart_motor_protocole_send_packet_blocking(void)
{
    uart_motor_protocole_send_packet();
    do
    {
        uart_motor_protocole_sm();
    }
    while(uart_motor_protocole_get_status() == UART_MOTOR_PROTOCOLE_IN_PROGRESS);
    return uart_motor_protocole_get_status();
}

