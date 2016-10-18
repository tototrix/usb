#include "_Global_Include.h"




u32 my_pow10(u8 i)
{
    u8 j;
    u32 result = 1;
    
    if(i==0) return result;
    
    for(j=0;j<i;j++)
    {
        result = result*10;
    }
    return result;
}


u16 calculate_crc(u8 *ptr,u16 size)
{
    volatile u16 checksum = 0xFFFF;
    volatile u16 index = 0;
    volatile u16 length;
    volatile u16 j;
    
    length = size;
    
    for (index = 0; index < (length ); index++)
    {
        checksum ^= (*(ptr + index));
        for (j = 8; j > 0; j--)
        {
            if ((checksum & 1) == 0x0001)
            {
                checksum = (checksum >> 1);
                checksum ^= 0xA001;
            }
            else checksum >>= 1;
        }
    }
    j = 0;
    return checksum;
}
