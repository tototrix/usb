#include "com_packet.h"
#include "tools.h"


u8 com_packet_id = 0x01;

u16 com_packet_calc_crc(u8 *ptr, u16 size);

void com_packet_config(s_com_packet *packet,u8 *src_ptr,u16 src_size)
{
    packet->buffer_index = 0x00;
    packet->buffer_ptr = src_ptr;
    packet->buffer_size = src_size;
}
void com_packet_init(s_com_packet *packet,u8 addr_dest,u8 order)
{
   packet->buffer_index = 0x00;
   *(packet->buffer_ptr + COM_PACKET_HEADER_INDEX) = 'X';
   *(packet->buffer_ptr + COM_PACKET_SIZEH_INDEX)   = 0x00;
   *(packet->buffer_ptr + COM_PACKET_SIZEL_INDEX)   = 0x00;
   *(packet->buffer_ptr + COM_PACKET_DEST_INDEX)   = addr_dest;
   *(packet->buffer_ptr + COM_PACKET_ID_INDEX) = com_packet_id++;
   *(packet->buffer_ptr + COM_PACKET_ORDER_INDEX)  = order;
   packet->buffer_index = COM_PACKET_PAYLOAD_INDEX;
   if(com_packet_id >= 255) com_packet_id = 0x01;
   if(com_packet_id == 0x00) com_packet_id = 0x01;
}

void com_packet_add_byte(s_com_packet *packet,u8 byte)
{
    if(packet->buffer_index >= packet->buffer_size) return;
    *(packet->buffer_ptr + packet->buffer_index++) = byte;  
}

u8 com_packet_get_byte(s_com_packet *packet,u16 index)
{
  return *(packet->buffer_ptr + index); 
}
void com_packet_finalize(s_com_packet *packet)
{
   u16 crc16 = 0x00;
   u16 size = packet->buffer_index+2;
   *(packet->buffer_ptr + COM_PACKET_SIZEH_INDEX) = (size>>8); 
   *(packet->buffer_ptr + COM_PACKET_SIZEL_INDEX) = (size & 0x00FF);
   crc16 = calculate_crc(packet->buffer_ptr,packet->buffer_index);
   *(packet->buffer_ptr + packet->buffer_index++) = (crc16>>8);
   *(packet->buffer_ptr + packet->buffer_index++) = (crc16 & 0x00FF);
}
