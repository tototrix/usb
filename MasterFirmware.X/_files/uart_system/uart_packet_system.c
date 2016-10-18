#include <_Global_Include.h>

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uart_packet_system_init(s_uart_packet_system *pk,u8 src_type,u32 src_addr, u8 dest_type,u32 dest_addr,u8 id,u8 order)
{
    pk->buffer_index = 0x00;
    pk->buffer[pk->buffer_index++]  = 'X';
    pk->buffer[pk->buffer_index++]  = 0x00;
    pk->buffer[pk->buffer_index++]  = 0x00;    
    pk->buffer[pk->buffer_index++]  = src_type;
    pk->buffer[pk->buffer_index++]  = (src_addr >> 24);
    pk->buffer[pk->buffer_index++]  = (src_addr >> 16);
    pk->buffer[pk->buffer_index++]  = (src_addr >> 8);
    pk->buffer[pk->buffer_index++]  = (src_addr & 0x00FF);
    pk->buffer[pk->buffer_index++]  = dest_type;
    pk->buffer[pk->buffer_index++]  = (dest_addr >> 24);
    pk->buffer[pk->buffer_index++]  = (dest_addr >> 16);
    pk->buffer[pk->buffer_index++]  = (dest_addr >> 8);
    pk->buffer[pk->buffer_index++]  = (dest_addr & 0x00FF);
    pk->buffer[pk->buffer_index++]  = id;
    pk->buffer[pk->buffer_index++]  = order;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uart_packet_system_add(s_uart_packet_system *pk,u8 byte)
{
    if(pk->buffer_index < (UART_PACKET_SYSTEM_SIZE-1))
    {
        pk->buffer[pk->buffer_index++]  = byte;
    }
}


//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uart_packet_system_finalise(s_uart_packet_system *pk)
{  
    u16 length = 0x00;
    u16 crc16;
    
    pk->buffer_index+=2;
    length = pk->buffer_index;
    
    pk->buffer[_UART_PACKET_SYSTEM_SIZEH] = (length>>8);
    pk->buffer[_UART_PACKET_SYSTEM_SIZEL] = (length & 0x00FF);
    crc16 = calculate_crc((u8*)pk->buffer,(length-2));
    pk->buffer[length-2] = (crc16>>8);
    pk->buffer[length-1] = (crc16 & 0x00FF);
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
bool uart_packet_system_verify_crc(s_uart_packet_system *pk)
{
    u16 crc16_calc;
    u16 crc16;
    
    u16 length = pk->buffer_index;
    crc16 = pk->buffer[length-2];
    crc16 <<=8;
    crc16 += pk->buffer[length-1];
    
    crc16_calc = calculate_crc((u8*)pk->buffer,(length-2));
    
    if(crc16_calc == crc16) return TRUE;
    else return FALSE;   
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u8  uart_packet_system_get_src_type(s_uart_packet_system *pk)
{
    return pk->buffer[_UART_PACKET_SYSTEM_SRC_TYPE];
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u32 uart_packet_system_get_src_addr(s_uart_packet_system *pk)
{
    u32 temp32;
    temp32 = pk->buffer[_UART_PACKET_SYSTEM_SRC_ADDR3];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_SRC_ADDR2];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_SRC_ADDR1];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_SRC_ADDR0];
    return temp32;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u8  uart_packet_system_get_dest_type(s_uart_packet_system *pk)
{
    return pk->buffer[_UART_PACKET_SYSTEM_DEST_TYPE];
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u32 uart_packet_system_get_dest_addr(s_uart_packet_system *pk)
{
    u32 temp32;
    temp32 = pk->buffer[_UART_PACKET_SYSTEM_DEST_ADDR3];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_DEST_ADDR2];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_DEST_ADDR1];
    temp32 <<=8;
    temp32 += pk->buffer[_UART_PACKET_SYSTEM_DEST_ADDR0];
    return temp32;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u8  uart_packet_system_get_order(s_uart_packet_system *pk)
{
    return pk->buffer[_UART_PACKET_PACKET_ORDER];
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u8  uart_packet_system_get_id(s_uart_packet_system *pk)
{
    return pk->buffer[_UART_PACKET_SYSTEM_ID];
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
u16 uart_packet_system_get_size(s_uart_packet_system *pk)
{
    u16 temp16;
    temp16 = pk->buffer[_UART_PACKET_SYSTEM_SIZEH];
    temp16 <<=8;
    temp16 += pk->buffer[_UART_PACKET_SYSTEM_SIZEL];
    return temp16;
}

//=========================================================================
// Function : 
// Input(s) : - 
// Output   : -
//=========================================================================
void uart_packet_system_clone(s_uart_packet_system *pk_src,s_uart_packet_system *pk_dest)
{
    u16 temp16;
    
    for(temp16=0;temp16<pk_src->buffer_index;temp16++)
    {
        pk_dest->buffer[temp16] = pk_src->buffer[temp16];
    }
    pk_dest->buffer_index = pk_src->buffer_index;
}


