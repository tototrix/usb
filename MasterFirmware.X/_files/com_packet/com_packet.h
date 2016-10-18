

#ifndef COM_PACKET_H
#define	COM_PACKET_H
#include "_Typedefs.h"

typedef enum
{
 COM_PACKET_HEADER_INDEX, 
 COM_PACKET_SIZEH_INDEX,
 COM_PACKET_SIZEL_INDEX,   
 COM_PACKET_DEST_INDEX,   
 COM_PACKET_ID_INDEX,  
 COM_PACKET_ORDER_INDEX,       
 COM_PACKET_PAYLOAD_INDEX,   
}enum_com_packet;


typedef struct
{
    u8 *buffer_ptr;
    u16 buffer_size;
    u16 buffer_index;
}s_com_packet;


void com_packet_config(s_com_packet *packet,u8 *src_ptr,u16 src_size);
void com_packet_init(s_com_packet *packet,u8 addr_dest,u8 order);
void com_packet_add_byte(s_com_packet *packet,u8 byte);
void com_packet_finalize(s_com_packet *packet);
u8 com_packet_get_byte(s_com_packet *packet,u16 index);



#endif	/* COM_PACKET_H */

