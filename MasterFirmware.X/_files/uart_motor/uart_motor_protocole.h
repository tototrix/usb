#ifndef UART_MOTOR_PROTOCOLE_H
#define	UART_MOTOR_PROTOCOLE_H
#include "_Typedefs.h"



typedef enum
{
    UART_MOTOR_PROTOCOLE_IDLE,
    UART_MOTOR_PROTOCOLE_IN_PROGRESS,
    UART_MOTOR_PROTOCOLE_SUCCESS,
    UART_MOTOR_PROTOCOLE_ERROR,            
}enum_uart_motor_protocole_status;


extern s_com_packet uart_motor_protocole_packet_tx;
extern s_com_packet uart_motor_protocole_packet_rx;

        
void uart_motor_protocole_init(void);
bool uart_motor_protocole_is_ready(void);
u8   uart_motor_protocole_get_status(void);
bool uart_motor_protocole_is_mutex_free(void);
void uart_motor_protocole_take_mutex(void);
void uart_motor_protocole_release_mutex(void);


void uart_motor_protocole_send_packet(void);
u8 uart_motor_protocole_send_packet_blocking(void);

void uart_motor_protocole_sm(void);



#endif	/* UART_MOTOR_PROTOCOLE_H */

