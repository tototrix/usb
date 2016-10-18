#ifndef UART_MOTOR_H
#define	UART_MOTOR_H
#include "_Typedefs.h"



void uart_printf_init(void);
void uart_motor_init(void);
void uart_motor_send_byte(u8 byte);
u16 uart_motor_get_it_count(void);
u8 uart_motor_it_read_byte(void);
void uart_motor_it_clear(void);

#endif	/* UART_MOTOR_H */

