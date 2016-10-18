/* 
 * File:   uart_packet_system.h
 * Author: Christophe
 *
 * Created on 23 octobre 2015, 10:19
 */

#ifndef UART_PACKET_SYSTEM_H
#define	UART_PACKET_SYSTEM_H


#define UART_PACKET_SYSTEM_SIZE  256//512  // Taille maximum d'une trame sur le bus systeme.

typedef enum
{
  _UART_PACKET_SYSTEM_HEADER,         // Octet d'en-tête
  _UART_PACKET_SYSTEM_SIZEH,          // Taille du paquet crc compris (poids forts)
  _UART_PACKET_SYSTEM_SIZEL,          // Taille du paquet crc compris (poids faibles)
  _UART_PACKET_SYSTEM_SRC_TYPE,       // Type d'equipement à l'origine du message (USB, modem , etc...) 
  _UART_PACKET_SYSTEM_SRC_ADDR3,      // Adresse de l'equipement à l'origine du message (24-->31)
  _UART_PACKET_SYSTEM_SRC_ADDR2,      // Adresse de l'equipement à l'origine du message (16-->23)
  _UART_PACKET_SYSTEM_SRC_ADDR1,      // Adresse de l'equipement à l'origine du message (8-->15)        
  _UART_PACKET_SYSTEM_SRC_ADDR0,      // Adresse de l'equipement à l'origine du message (0-->7)
  _UART_PACKET_SYSTEM_DEST_TYPE,      // Type d'equipement destinataire du message (USB, modem , etc...) 
  _UART_PACKET_SYSTEM_DEST_ADDR3,     // Adresse de l'equipement destinataire du message (24-->31)
  _UART_PACKET_SYSTEM_DEST_ADDR2,     // Adresse de l'equipement destinataire du message (16-->23)
  _UART_PACKET_SYSTEM_DEST_ADDR1,     // Adresse de l'equipement destinataire du message (8-->15)
  _UART_PACKET_SYSTEM_DEST_ADDR0,     // Adresse de l'equipement destinataire du message (0-->7)  
  _UART_PACKET_SYSTEM_ID,             // ID du message 
  _UART_PACKET_PACKET_ORDER,          // Code d'ordre du message (type de message))
  _UARTS_PACKET_PAYLOAD,        // Premier octet de la charge utile
}enum_uart_packet_system;


typedef struct
{
    u8 buffer[UART_PACKET_SYSTEM_SIZE];
    u16 buffer_index;
}s_uart_packet_system;



void uart_packet_system_init(s_uart_packet_system *pk,u8 src_type,u32 src_addr, u8 dest_type,u32 dest_addr,u8 id,u8 order);
void uart_packet_system_add(s_uart_packet_system *pk,u8 byte);
void uart_packet_system_finalise(s_uart_packet_system *pk);
bool uart_packet_system_verify_crc(s_uart_packet_system *pk);
u8  uart_packet_system_get_src_type(s_uart_packet_system *pk);
u32 uart_packet_system_get_src_addr(s_uart_packet_system *pk);
u8  uart_packet_system_get_dest_type(s_uart_packet_system *pk);
u32 uart_packet_system_get_dest_addr(s_uart_packet_system *pk);
u8  uart_packet_system_get_order(s_uart_packet_system *pk);
u8  uart_packet_system_get_id(s_uart_packet_system *pk);
u16 uart_packet_system_get_size(s_uart_packet_system *pk);
void uart_packet_system_clone(s_uart_packet_system *pk_src,s_uart_packet_system *pk_dest);


#endif	/* UART_PACKET_SYSTEM_H */

