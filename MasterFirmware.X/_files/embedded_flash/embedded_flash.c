#include <_Global_Include.h>


u16 Pic33EV_Read_Word(u32 address)
{
    u16 data;
    u16 TBLPAGSave;

    //Save TBLPAG register
    TBLPAGSave = TBLPAG;

    //Read a sector worth of data from the flash, and copy to the user specified "buffer".
    TBLPAG = (u8)(address >> 16);   //Load TBLPAG pointer (upper 8 bits of total address.  A sector could get split at
                                        //a 16-bit address boundary, and therefore could exist on two TBLPAG pages.
                                        //Therefore, need to reload TBLPAG every iteration of the for() loop
    data = __builtin_tblrdl((u16)(address & 0x0000FFFF));

    //Restore TBLPAG register to original value
    TBLPAG = TBLPAGSave;

    return data;
}
