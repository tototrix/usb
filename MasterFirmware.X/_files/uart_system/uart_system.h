#ifndef UARTS_H
#define	UARTS_H
#include "_Typedefs.h"
#include "uart_packet_system.h"

#define UARTS_IT_BUFFER_SIZE                  256//512

void uarts_init_re_de(void);
void uarts_init(void);
void uarts_sm_construct_rx(void);
void uarts_sm_treatment_rx(void);

// <editor-fold defaultstate="collapsed" desc="TX treatment">





extern s_uart_packet_system uarts_tx_mgmt_packet_rx;

void uarts_tx_mgmt_packet_tx_init(u8 dest_type,u32 dest_addr,u8 order);
void uarts_tx_mgmt_packet_tx_add_byte(u8 byte);
void uarts_tx_mgmt_packet_tx_finalize(void);
bool uarts_tx_mgmt_is_busy(void);
bool uarts_tx_mgmt_is_error(void);
bool uarts_tx_mgmt_is_mutex_free(void);
void uarts_tx_mgmt_get_mutex(void);
void uarts_tx_mgmt_release_mutex(void);
void uarts_tx_mgmt_go(u16 timeout);
void uarts_tx_mgmt_sm(void);

// </editor-fold>
#endif	/* UARTS_H*/

