/* 
 * File:   uart_motor_common.h
 * Author: Christophe
 *
 * Created on 10 juillet 2015, 09:18
 */

#ifndef UART_MOTOR_COMMON_H
#define	UART_MOTOR_COMMON_H
#include "_Typedefs.h"


#define UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE     32
#define UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER   1100


// La taille du buffer de stockage sur interruption est definie en fonction du plus gros buffer
#if UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE > UART_MOTOR_BUFFER_SIZE_SLAVE_TO_MASTER 
#define UART_MOTOR_ITRX_BUFFER_SIZE UART_MOTOR_BUFFER_SIZE_MASTER_TO_SLAVE
#else
#define UART_MOTOR_ITRX_BUFFER_SIZE 64
#endif



// A la fin de l'émission d'un octet l'esclave attend quelques us avant de se mettre en écoute
#define UART_MOTOR_SLAVE_TEMPO_INCR_US   10   
#define UART_MOTOR_SLAVE_WAIT_END_US    100


// Baudrate
#define UART_MOTOR_BAUDRATE       57600


// Nombre d'essais max 
#define UART_MOTOR_RETRY_COUNT           10
#define UART_MOTOR_WAIT_MS_BEFORE_RETRY  50
// Timeout max en ms entre l'envoi d'un message et la reception de la réponse
#define UART_MOTOR_TIMEOUT_MS            10    

//adresse
#define UART_MOTOR_SLAVEH_ADDR        1
#define UART_MOTOR_SLAVEL_ADDR        0
#define UART_MOTOR_MASTER_ADDR        2


// Ordres
#define UART_MOTOR_ORDER_CONTROL                     1
#define UART_MOTOR_ORDER_SET_TYPE                    2
#define UART_MOTOR_ORDER_GET_STATUS                  3
#define UART_MOTOR_ORDER_GET_SWITCH                  4
#define UART_MOTOR_ORDER_GET_SHUNT                   5
#define UART_MOTOR_ORDER_GET_FIRMWARE                6
#define UART_MOTOR_ORDER_SET_PULSES                  7
#define UART_MOTOR_ORDER_GET_SPEED                   8
#define UART_MOTOR_ORDER_GET_SENSORS                 9
#define UART_MOTOR_ORDER_SET_BRIDGE_OUTPUT          10
#define UART_MOTOR_ORDER_SET_FILTER_MODE            11
#define UART_MOTOR_ORDER_SET_SENSORS_TEST_MODE      12
#define UART_MOTOR_ORDER_CONTROL_V2                 13
#define UART_MOTOR_ORDER_ERASE                     101
#define UART_MOTOR_ORDER_WRITE                     102
#define UART_MOTOR_ORDER_GET_HALL_STATUS           110










#endif	/* UART_MOTOR_COMMON_H */

