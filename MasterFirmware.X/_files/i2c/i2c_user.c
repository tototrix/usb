#include <_Global_Include.h>


#define EEPROM_ERROR_VERIFY_BUFFER   -50
#define EEPROM_ERROR_WRITE_BUFFER_A  -51
#define EEPROM_ERROR_WRITE_BUFFER_B  -52
#define EEPROM_ERROR_WRITE_INFO      -53
#define EEPROM_ERROR_WRITE_CODE      -54
#define EEPROM_ERROR_WRITE_INFO1     -55
#define EEPROM_ERROR_WRITE_INFO2     -55
#define EEPROM_ERROR_WRITE_INFO3     -56
#define EEPROM_ERROR_WRITE_SIZE      -60


typedef struct eeprom_info
{
    bool valid;
    u16 bloc;
    u32 idl;
    u32 idf;
    u16 ptrf;
    u16 ptrl;
    u32 cnt;
    bool active;
}eeprom_info;

u8 eeprom_ev_index = 0x00;
      
i8   eeprom_error_code      = 0x00;         // Contient le code d'erreur pour le debug.
bool eeprom_error           = FALSE;        // Indique si la fonction eeprom est en erreur (critique) ou non.
u8   eeprom_array[I2C_PACKET_PAYLOAD_SIZE]; // Buffer de travail de la fonction eeprom.


u16 eeprom_evz1_block_info;           // Bloc fat en cours d'utilisation.
u32 eeprom_evz1_idf         = 0x00;   // ID du plus ancien evenement dans la mémoire.
u32 eeprom_evz1_idl         = 0x00;   // ID du plus récent evenement dans la mémoire.
u16 eeprom_evz1_ptrf        = 0x00;   // Contient le numéro de bloc de l'évènement le plus ancien dans la mémoire.
u16 eeprom_evz1_ptrl        = 0x00;   // Contient le numéro de bloc de l'évènement le plus récent dans la mémoire.
u32 eeprom_evz1_bl_count    = 0x00;   // Compteur d'écriture dans le bloc fat en cours d'utilisation.
bool eeprom_evz1_bl_active  = FALSE;  // 

u16 eeprom_evz2_block_info;           // Bloc fat en cours d'utilisation.
u32 eeprom_evz2_idf         = 0x00;   // ID du plus ancien evenement dans la mémoire.
u32 eeprom_evz2_idl         = 0x00;   // ID du plus récent evenement dans la mémoire.
u16 eeprom_evz2_ptrf        = 0x00;   // Contient le numéro de bloc de l'évènement le plus ancien dans la mémoire.
u16 eeprom_evz2_ptrl        = 0x00;   // Contient le numéro de bloc de l'évènement le plus récent dans la mémoire.
u32 eeprom_evz2_bl_count    = 0x00;   // Compteur d'écriture dans le bloc fat en cours d'utilisation.
bool eeprom_evz2_bl_active  = FALSE;  //

i8 eeprom_ev_read_info(eeprom_info *ptr);   // Permet la lecture d'un bloc de type FAT
i8 eeprom_ev_write_info(u16 bloc,u32 idf,   // Permet l'écriture d'un bloc de type FAT
                        u32 idl,u16 ptrf,
                        u16 ptrl,u32 count,
                        bool valid);

void eeprom_set_error(i8 code);             // Permet de déclarer un defaut sur la fonction eeprom.
i8 eeprom_evz1_write_data(void);
i8 eeprom_evz2_write_data(void);



void eeprom_ev_init(void)
{
    i8 ret;
    eeprom_info info_bl1_z1;
    eeprom_info info_bl2_z1;
    eeprom_info info_bl3_z1;
    eeprom_info info_bl1_z2;
    eeprom_info info_bl2_z2;
    eeprom_info info_bl3_z2;
    
    // ZONE1
    eeprom_evz1_block_info = I2C_EVENT_INFO_BLOCK1_Z1;
    
    info_bl1_z1.valid = FALSE;
    info_bl1_z1.bloc = I2C_EVENT_INFO_BLOCK1_Z1;
    
    info_bl2_z1.valid = FALSE;
    info_bl2_z1.bloc = I2C_EVENT_INFO_BLOCK2_Z1;
    
    info_bl3_z1.valid = FALSE;
    info_bl3_z1.bloc = I2C_EVENT_INFO_BLOCK3_Z1;
    
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl1_z1);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl2_z1);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl3_z1);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }

    if(info_bl3_z1.valid &&  info_bl3_z1.active)
    {
        eeprom_evz1_block_info = info_bl3_z1.bloc;
        eeprom_evz1_idf        = info_bl3_z1.idf;
        eeprom_evz1_idl        = info_bl3_z1.idl;       
        eeprom_evz1_ptrf       = info_bl3_z1.ptrf;
        eeprom_evz1_ptrl       = info_bl3_z1.ptrl;
        eeprom_evz1_bl_count   = info_bl3_z1.cnt;
        eeprom_evz1_bl_active  = info_bl3_z1.active;
    }
    else if(info_bl2_z1.valid &&  info_bl2_z1.active)
    {
        eeprom_evz1_block_info = info_bl2_z1.bloc;
        eeprom_evz1_idf        = info_bl2_z1.idf;
        eeprom_evz1_idl        = info_bl2_z1.idl;       
        eeprom_evz1_ptrf       = info_bl2_z1.ptrf;
        eeprom_evz1_ptrl       = info_bl2_z1.ptrl;
        eeprom_evz1_bl_count   = info_bl2_z1.cnt;
        eeprom_evz1_bl_active  = info_bl2_z1.active;
    }
    else if(info_bl1_z1.valid &&  info_bl1_z1.active)
    {
        eeprom_evz1_block_info = info_bl1_z1.bloc;
        eeprom_evz1_idf        = info_bl1_z1.idf;
        eeprom_evz1_idl        = info_bl1_z1.idl;       
        eeprom_evz1_ptrf       = info_bl1_z1.ptrf;
        eeprom_evz1_ptrl       = info_bl1_z1.ptrl;
        eeprom_evz1_bl_count   = info_bl1_z1.cnt;
        eeprom_evz1_bl_active  = info_bl1_z1.active;
    }
    else
    {
        eeprom_evz1_block_info = info_bl1_z1.bloc;
        eeprom_evz1_idf = 0x00;
        eeprom_evz1_idl = 0x00;
        eeprom_evz1_ptrf = I2C_EVENT_BLOCK_START_Z1;
        eeprom_evz1_ptrl = I2C_EVENT_BLOCK_START_Z1;
        eeprom_evz1_bl_count = 0x00;
        eeprom_evz1_bl_active = TRUE;
        ret = eeprom_ev_write_info(eeprom_evz1_block_info,  
                                   eeprom_evz1_idf,
                                   eeprom_evz1_idl,
                                   eeprom_evz1_ptrf,
                                   eeprom_evz1_ptrl,
                                   eeprom_evz1_bl_count,
                                   eeprom_evz1_bl_active);
        if(ret <= 0) 
        {
            eeprom_error = TRUE;
            return;
        }
    }
    
    

    // ZONE2
    eeprom_evz2_block_info = I2C_EVENT_INFO_BLOCK1_Z2;
    
    info_bl1_z2.valid = FALSE;
    info_bl1_z2.bloc = I2C_EVENT_INFO_BLOCK1_Z2;
    
    info_bl2_z2.valid = FALSE;
    info_bl2_z2.bloc = I2C_EVENT_INFO_BLOCK2_Z2;
    
    info_bl3_z2.valid = FALSE;
    info_bl3_z2.bloc = I2C_EVENT_INFO_BLOCK3_Z2;
    
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl1_z2);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl2_z2);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }
    ret = eeprom_ev_read_info((eeprom_info*)&info_bl3_z2);
    if(ret < 0)
    {
        eeprom_error = TRUE;
        return;
    }

    if(info_bl3_z2.valid &&  info_bl3_z2.active)
    {
        eeprom_evz2_block_info = info_bl3_z2.bloc;
        eeprom_evz2_idf        = info_bl3_z2.idf;
        eeprom_evz2_idl        = info_bl3_z2.idl;       
        eeprom_evz2_ptrf       = info_bl3_z2.ptrf;
        eeprom_evz2_ptrl       = info_bl3_z2.ptrl;
        eeprom_evz2_bl_count   = info_bl3_z2.cnt;
        eeprom_evz2_bl_active  = info_bl3_z2.active;
    }
    else if(info_bl2_z2.valid &&  info_bl2_z2.active)
    {
        eeprom_evz2_block_info = info_bl2_z2.bloc;
        eeprom_evz2_idf        = info_bl2_z2.idf;
        eeprom_evz2_idl        = info_bl2_z2.idl;       
        eeprom_evz2_ptrf       = info_bl2_z2.ptrf;
        eeprom_evz2_ptrl       = info_bl2_z2.ptrl;
        eeprom_evz2_bl_count   = info_bl2_z2.cnt;
        eeprom_evz2_bl_active  = info_bl2_z2.active;
    }
    else if(info_bl1_z2.valid &&  info_bl1_z2.active)
    {
        eeprom_evz2_block_info = info_bl1_z2.bloc;
        eeprom_evz2_idf        = info_bl1_z2.idf;
        eeprom_evz2_idl        = info_bl1_z2.idl;       
        eeprom_evz2_ptrf       = info_bl1_z2.ptrf;
        eeprom_evz2_ptrl       = info_bl1_z2.ptrl;
        eeprom_evz2_bl_count   = info_bl1_z2.cnt;
        eeprom_evz2_bl_active  = info_bl1_z2.active;
    }
    else
    {
        eeprom_evz2_block_info = info_bl1_z2.bloc;
        eeprom_evz2_idf = 0x00;
        eeprom_evz2_idl = 0x00;
        eeprom_evz2_ptrf = I2C_EVENT_BLOCK_START_Z2;
        eeprom_evz2_ptrl = I2C_EVENT_BLOCK_START_Z2;
        eeprom_evz2_bl_count = 0x00;
        eeprom_evz2_bl_active = TRUE;
        ret = eeprom_ev_write_info(eeprom_evz2_block_info,  
                                   eeprom_evz2_idf,
                                   eeprom_evz2_idl,
                                   eeprom_evz2_ptrf,
                                   eeprom_evz2_ptrl,
                                   eeprom_evz2_bl_count,
                                   eeprom_evz2_bl_active);
        if(ret <= 0) 
        {
            eeprom_error = TRUE;
            return;
        }
    }  
}



void eeprom_set_error(i8 code)
{
    if(eeprom_error == FALSE)
    {
       eeprom_error_code = code;
       eeprom_error = TRUE;
       error(ERROR_EEPROM);
    }
}

u32 eeprom_evz1_get_idf(void)
{
    return eeprom_evz1_idf;
}

u32 eeprom_evz1_get_idl(void)
{
    return eeprom_evz1_idl;
}

u16 eeprom_evz1_get_count(void)
{   
    if(eeprom_evz1_idl == eeprom_evz1_idf) return 0;
    else if(eeprom_evz1_idl > eeprom_evz1_idf)
    {
        return (eeprom_evz1_idl-eeprom_evz1_idf);
    }
    else if(eeprom_evz1_idf > eeprom_evz1_idl)
    {
        return (I2C_EVENT_MAX_COUNT_Z1 -1);
    }
    else return 0;
}



u32 eeprom_evz2_get_idf(void)
{
    return eeprom_evz2_idf;
}

u32 eeprom_evz2_get_idl(void)
{
    return eeprom_evz2_idl;
}

u16 eeprom_evz2_get_count(void)
{   
    if(eeprom_evz2_idl == eeprom_evz2_idf) return 0;
    else if(eeprom_evz2_idl > eeprom_evz2_idf)
    {
        return (eeprom_evz2_idl-eeprom_evz2_idf);
    }
    else if(eeprom_evz2_idf > eeprom_evz2_idl)
    {
        return (I2C_EVENT_MAX_COUNT_Z2 -1);
    }
    else return 0;
}


i8 eeprom_evz1_read(u32 id,eeprom_read_event *ptr)
{
   i8 ret;
   u16 block;
   u32 addr;
   u16 temp16_1; 
   u16 temp16_2;
   u32 temp32;
   
   u8 array[I2C_PACKET_PAYLOAD_SIZE];
   
   if(id < eeprom_evz1_idf) return 0;
   if(id > eeprom_evz1_idl) return 0;
   
   if(eeprom_evz1_ptrl>eeprom_evz1_ptrf)
   {
       block = eeprom_evz1_ptrf+(id-eeprom_evz1_idf);
   }
   else
   {
       if((id-eeprom_evz1_idf)<=(I2C_EVENT_BLOCK_STOP_Z1-eeprom_evz1_ptrf))
       {
           block = eeprom_evz1_ptrf+(id-eeprom_evz1_idf);
       }
       else
       {
           temp16_1 = id - eeprom_evz1_idf;
           temp16_2 = I2C_EVENT_BLOCK_STOP_Z1 - eeprom_evz1_ptrf+1;
           block = I2C_EVENT_BLOCK_START_Z1+(temp16_1-temp16_2);
       }
   }
   
   addr = block;
   addr = addr * I2C_PACKET_PAYLOAD_SIZE; 
   ret = eeprom_read(addr,(u8*)&array[0],I2C_PACKET_PAYLOAD_SIZE);
   
   if(ret<=0)
   {
       return ret;
   }
   else
   {
       // ID
       temp32 = array[0];temp32<<=8;
       temp32 += array[1];temp32<<=8;
       temp32 += array[2];temp32<<=8;
       temp32 += array[3];
       ptr->id = temp32;
       // ALIVE COUNTER
       temp32 = array[4];temp32<<=8;
       temp32 += array[5];temp32<<=8;
       temp32 += array[6];temp32<<=8;
       temp32 += array[7];
       ptr->alive_counter = temp32;
       
       ptr->ts_year = array[8];
       ptr->ts_month = array[9];
       ptr->ts_day = array[10];
       ptr->ts_hour = array[11];
       ptr->ts_minuts = array[12];
       ptr->ts_seconds = array[13];
       
       temp16_2 = 0x00;
       for(temp16_1=14;temp16_1<I2C_PACKET_PAYLOAD_SIZE;temp16_1++)
       {
           ptr->payload[temp16_2++] = array[temp16_1];
       }
       return 1;
   }
}


i8 eeprom_evz2_read(u32 id,eeprom_read_event *ptr)
{
   i8 ret;
   u16 block;
   u32 addr;
   u16 temp16_1; 
   u16 temp16_2;
   u32 temp32;
   
   u8 array[I2C_PACKET_PAYLOAD_SIZE];
   
   if(id < eeprom_evz2_idf) return 0;
   if(id > eeprom_evz2_idl) return 0;
   
   if(eeprom_evz2_ptrl>eeprom_evz2_ptrf)
   {
       block = eeprom_evz2_ptrf+(id-eeprom_evz2_idf);
   }
   else
   {
       if((id-eeprom_evz2_idf)<=(I2C_EVENT_BLOCK_STOP_Z2-eeprom_evz2_ptrf))
       {
           block = eeprom_evz2_ptrf+(id-eeprom_evz2_idf);
       }
       else
       {
           temp16_1 = id - eeprom_evz2_idf;
           temp16_2 = I2C_EVENT_BLOCK_STOP_Z2 - eeprom_evz2_ptrf+1;
           block = I2C_EVENT_BLOCK_START_Z2+(temp16_1-temp16_2);
       }
   }
   
   addr = block;
   addr = addr * I2C_PACKET_PAYLOAD_SIZE; 
   ret = eeprom_read(addr,(u8*)&array[0],I2C_PACKET_PAYLOAD_SIZE);
   
   if(ret<=0)
   {
       return ret;
   }
   else
   {
       // ID
       temp32 = array[0];temp32<<=8;
       temp32 += array[1];temp32<<=8;
       temp32 += array[2];temp32<<=8;
       temp32 += array[3];
       ptr->id = temp32;
       // ALIVE COUNTER
       temp32 = array[4];temp32<<=8;
       temp32 += array[5];temp32<<=8;
       temp32 += array[6];temp32<<=8;
       temp32 += array[7];
       ptr->alive_counter = temp32;
       
       ptr->ts_year = array[8];
       ptr->ts_month = array[9];
       ptr->ts_day = array[10];
       ptr->ts_hour = array[11];
       ptr->ts_minuts = array[12];
       ptr->ts_seconds = array[13];
       
       temp16_2 = 0x00;
       for(temp16_1=14;temp16_1<I2C_PACKET_PAYLOAD_SIZE;temp16_1++)
       {
           ptr->payload[temp16_2++] = array[temp16_1];
       }
       return 1;
   }
}


i8 eeprom_evz1_write_data(void)
{
    ClrWdt();
    i8 ret;
    u32 addr;
    u16 new_info_block = 0x00;
    addr = eeprom_evz1_ptrl;
    addr = addr * I2C_PACKET_PAYLOAD_SIZE;
    ret = eeprom_write(addr,(u8*)&eeprom_array[0],I2C_PACKET_PAYLOAD_SIZE); 
    if(ret <= 0)
    {
        eeprom_set_error(EEPROM_ERROR_WRITE_CODE);
        return ret;
    }
    else
    {
        eeprom_evz1_idl++;
        eeprom_evz1_ptrl++;
        if(eeprom_evz1_ptrl > I2C_EVENT_BLOCK_STOP_Z1) 
        {
            eeprom_evz1_ptrl = I2C_EVENT_BLOCK_START_Z1; 
        }
        if(eeprom_evz1_ptrl == eeprom_evz1_ptrf)
        {
            eeprom_evz1_idf++;
            eeprom_evz1_ptrf++;
            if(eeprom_evz1_ptrf > I2C_EVENT_BLOCK_STOP_Z1) 
            {
               eeprom_evz1_ptrf = I2C_EVENT_BLOCK_START_Z1; 
            }
        }
        
        
        
        
        eeprom_evz1_bl_count++;
        
        if((eeprom_evz1_bl_count >= I2C_EVENT_INFO_MAX_COUNT) && (eeprom_evz1_block_info != I2C_EVENT_INFO_BLOCK3_Z1))
        {
            if(eeprom_evz1_block_info == I2C_EVENT_INFO_BLOCK1_Z1) new_info_block = I2C_EVENT_INFO_BLOCK2_Z1;
            else if(eeprom_evz1_block_info == I2C_EVENT_INFO_BLOCK2_Z1) new_info_block = I2C_EVENT_INFO_BLOCK3_Z1;
            
            
            ret = eeprom_ev_write_info(new_info_block,eeprom_evz1_idf,eeprom_evz1_idl,eeprom_evz1_ptrf,eeprom_evz1_ptrl,0x00,TRUE);
            if(ret <= 0)
            {
                eeprom_set_error(EEPROM_ERROR_WRITE_INFO1);
                return ret;
            }
            else
            {
                ret = eeprom_ev_write_info(eeprom_evz1_block_info,eeprom_evz1_idf,eeprom_evz1_idl,eeprom_evz1_ptrf,eeprom_evz1_ptrl,eeprom_evz1_bl_count,FALSE);
                if(ret <= 0)
                {
                    eeprom_set_error(EEPROM_ERROR_WRITE_INFO2);
                    return ret;
                }
                else
                {

                    eeprom_evz1_bl_count   = 0x00;
                    eeprom_evz1_block_info = new_info_block;
                    return ret;
                } 
            }
        }
        else
        {
            ret = eeprom_ev_write_info(eeprom_evz1_block_info,eeprom_evz1_idf,eeprom_evz1_idl,eeprom_evz1_ptrf,eeprom_evz1_ptrl,eeprom_evz1_bl_count,TRUE);
            if(ret <= 0)
            {
                eeprom_set_error(EEPROM_ERROR_WRITE_INFO3);
                return ret;
            }
            else
            {
                return ret;
            }
        }  
    }
}

i8 eeprom_evz2_write_data(void)
{
    ClrWdt();
    i8 ret;
    u32 addr;
    u16 new_info_block = 0x00;
    addr = eeprom_evz2_ptrl;
    addr = addr * I2C_PACKET_PAYLOAD_SIZE;
    ret = eeprom_write(addr,(u8*)&eeprom_array[0],I2C_PACKET_PAYLOAD_SIZE); 
    if(ret <= 0)
    {
        eeprom_set_error(EEPROM_ERROR_WRITE_CODE);
        return ret;
    }
    else
    {
        eeprom_evz2_idl++;
        eeprom_evz2_ptrl++;
        if(eeprom_evz2_ptrl > I2C_EVENT_BLOCK_STOP_Z2) 
        {
            eeprom_evz2_ptrl = I2C_EVENT_BLOCK_START_Z2; 
        }
        if(eeprom_evz2_ptrl == eeprom_evz2_ptrf)
        {
            eeprom_evz2_idf++;
            eeprom_evz2_ptrf++;
            if(eeprom_evz2_ptrf > I2C_EVENT_BLOCK_STOP_Z2) 
            {
               eeprom_evz2_ptrf = I2C_EVENT_BLOCK_START_Z2; 
            }
        }
        
        
        
        
        eeprom_evz2_bl_count++;
        
        if((eeprom_evz2_bl_count >= I2C_EVENT_INFO_MAX_COUNT) && (eeprom_evz2_block_info != I2C_EVENT_INFO_BLOCK3_Z2))
        {
            if(eeprom_evz2_block_info == I2C_EVENT_INFO_BLOCK1_Z2) new_info_block = I2C_EVENT_INFO_BLOCK2_Z2;
            else if(eeprom_evz2_block_info == I2C_EVENT_INFO_BLOCK2_Z2) new_info_block = I2C_EVENT_INFO_BLOCK3_Z2;
            
            
            ret = eeprom_ev_write_info(new_info_block,eeprom_evz2_idf,eeprom_evz2_idl,eeprom_evz2_ptrf,eeprom_evz2_ptrl,0x00,TRUE);
            if(ret <= 0)
            {
                eeprom_set_error(EEPROM_ERROR_WRITE_INFO1);
                return ret;
            }
            else
            {
                ret = eeprom_ev_write_info(eeprom_evz2_block_info,eeprom_evz2_idf,eeprom_evz2_idl,eeprom_evz2_ptrf,eeprom_evz2_ptrl,eeprom_evz2_bl_count,FALSE);
                if(ret <= 0)
                {
                    eeprom_set_error(EEPROM_ERROR_WRITE_INFO2);
                    return ret;
                }
                else
                {

                    eeprom_evz2_bl_count   = 0x00;
                    eeprom_evz2_block_info = new_info_block;
                    return ret;
                } 
            }
        }
        else
        {
            ret = eeprom_ev_write_info(eeprom_evz2_block_info,eeprom_evz2_idf,eeprom_evz2_idl,eeprom_evz2_ptrf,eeprom_evz2_ptrl,eeprom_evz2_bl_count,TRUE);
            if(ret <= 0)
            {
                eeprom_set_error(EEPROM_ERROR_WRITE_INFO3);
                return ret;
            }
            else
            {
                return ret;
            }
        }  
    }
}

void eeprom_ev_write_init_code(u8 code)
{
    u8 i;
    ClrWdt();
    for(i=0;i<I2C_PACKET_PAYLOAD_SIZE;i++) eeprom_array[i] = 0xFF;
    
    eeprom_array[4] = (seconds_counter>>24);
    eeprom_array[5] = (seconds_counter>>16);
    eeprom_array[6] = (seconds_counter>>8);
    eeprom_array[7] = (seconds_counter & 0x00FF);       
    eeprom_array[8] = global_dt_year;
    eeprom_array[9] = global_dt_month;
    eeprom_array[10] = global_dt_days;
    eeprom_array[11] = global_dt_hours;
    eeprom_array[12] = global_dt_minuts;
    eeprom_array[13] = global_dt_seconds;
    eeprom_array[14] = code;
    eeprom_ev_index = 15;
    
}
void eeprom_ev_write_add_byte(u8 b)
{
    if(eeprom_ev_index < (I2C_PACKET_PAYLOAD_SIZE-1))
    {
        eeprom_array[eeprom_ev_index++] = b;
    }
}

i8 eeprom_ev_write(void)
{
    return 1;
    i8 ret;
    if(event_list[eeprom_array[14]].zone1 == TRUE)
    {
        ret = eeprom_evz1_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    
    if(event_list[eeprom_array[14]].zone2 == TRUE)
    {
        ret = eeprom_evz1_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    
    return 1;
}
i8 eeprom_ev_write1(u8 code)
{
    return 1;
    
    u8 i;
    i8 ret;
    ClrWdt();
    for(i=0;i<I2C_PACKET_PAYLOAD_SIZE;i++) eeprom_array[i] = 0xFF;
    
    eeprom_array[4] = (seconds_counter>>24);
    eeprom_array[5] = (seconds_counter>>16);
    eeprom_array[6] = (seconds_counter>>8);
    eeprom_array[7] = (seconds_counter & 0x00FF);       
    eeprom_array[8] = global_dt_year;
    eeprom_array[9] = global_dt_month;
    eeprom_array[10] = global_dt_days;
    eeprom_array[11] = global_dt_hours;
    eeprom_array[12] = global_dt_minuts;
    eeprom_array[13] = global_dt_seconds;
    eeprom_array[14] = code;
        
    if(event_list[code].zone1 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz1_idl >>24);
        eeprom_array[1] = (eeprom_evz1_idl>>16);
        eeprom_array[2] = (eeprom_evz1_idl>>8);
        eeprom_array[3] = (eeprom_evz1_idl & 0x00FF);
        ret = eeprom_evz1_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    
    if(event_list[code].zone2 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz2_idl >>24);
        eeprom_array[1] = (eeprom_evz2_idl>>16);
        eeprom_array[2] = (eeprom_evz2_idl>>8);
        eeprom_array[3] = (eeprom_evz2_idl & 0x00FF);
        ret = eeprom_evz2_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    return 1; 
}

i8 eeprom_ev_write2(u8 code,u8 val1)
{
    return 1;
    u8 i;
    i8 ret;
    ClrWdt();
    for(i=0;i<I2C_PACKET_PAYLOAD_SIZE;i++) eeprom_array[i] = 0xFF;
    
    eeprom_array[4] = (seconds_counter>>24);
    eeprom_array[5] = (seconds_counter>>16);
    eeprom_array[6] = (seconds_counter>>8);
    eeprom_array[7] = (seconds_counter & 0x00FF);       
    eeprom_array[8] = global_dt_year;
    eeprom_array[9] = global_dt_month;
    eeprom_array[10] = global_dt_days;
    eeprom_array[11] = global_dt_hours;
    eeprom_array[12] = global_dt_minuts;
    eeprom_array[13] = global_dt_seconds;
    eeprom_array[14] = code;
    eeprom_array[15] = val1;
        
    if(event_list[code].zone1 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz1_idl >>24);
        eeprom_array[1] = (eeprom_evz1_idl>>16);
        eeprom_array[2] = (eeprom_evz1_idl>>8);
        eeprom_array[3] = (eeprom_evz1_idl & 0x00FF);
        ret = eeprom_evz1_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    
    if(event_list[code].zone2 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz2_idl >>24);
        eeprom_array[1] = (eeprom_evz2_idl>>16);
        eeprom_array[2] = (eeprom_evz2_idl>>8);
        eeprom_array[3] = (eeprom_evz2_idl & 0x00FF);
        ret = eeprom_evz2_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    return 1; 
}

i8 eeprom_ev_write3(u8 code,u8 val1,u8 val2)
{
    return 1;
    u8 i;
    i8 ret;
    ClrWdt();
    for(i=0;i<I2C_PACKET_PAYLOAD_SIZE;i++) eeprom_array[i] = 0xFF;
    
    eeprom_array[4] = (seconds_counter>>24);
    eeprom_array[5] = (seconds_counter>>16);
    eeprom_array[6] = (seconds_counter>>8);
    eeprom_array[7] = (seconds_counter & 0x00FF);       
    eeprom_array[8] = global_dt_year;
    eeprom_array[9] = global_dt_month;
    eeprom_array[10] = global_dt_days;
    eeprom_array[11] = global_dt_hours;
    eeprom_array[12] = global_dt_minuts;
    eeprom_array[13] = global_dt_seconds;
    eeprom_array[14] = code;
    eeprom_array[15] = val1;
    eeprom_array[16] = val2;
    
        
    if(event_list[code].zone1 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz1_idl >>24);
        eeprom_array[1] = (eeprom_evz1_idl>>16);
        eeprom_array[2] = (eeprom_evz1_idl>>8);
        eeprom_array[3] = (eeprom_evz1_idl & 0x00FF);
        ret = eeprom_evz1_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    
    if(event_list[code].zone2 == TRUE)
    {
        eeprom_array[0] = (eeprom_evz2_idl >>24);
        eeprom_array[1] = (eeprom_evz2_idl>>16);
        eeprom_array[2] = (eeprom_evz2_idl>>8);
        eeprom_array[3] = (eeprom_evz2_idl & 0x00FF);
        ret = eeprom_evz2_write_data();
        if(ret<=0)
        {
            return ret;
        }
    }
    return 1; 
}

i8 eeprom_ev_write_info(u16 bloc,u32 idf,u32 idl,u16 ptrf,u16 ptrl,u32 count,bool valid)
{
    
    u32 addr;
    i8 ret;
    u8 array[30];
    addr = (bloc);
    addr = addr * I2C_PACKET_PAYLOAD_SIZE;
    
    array[0] = (idf>>24);
    array[1] = (idf>>16);
    array[2] = (idf>>8);
    array[3] = (idf & 0x00FF);
    
    array[4] = (idl>>24);
    array[5] = (idl>>16);
    array[6] = (idl>>8);
    array[7] = (idl & 0x00FF);
    
    array[8] = (ptrf>>8);
    array[9] = (ptrf & 0x00FF);
    
    array[10] = (ptrl>>8);
    array[11] = (ptrl & 0x00FF);
    
    array[12] = (count>>24);
    array[13] = (count>>16);
    array[14] = (count>>8);
    array[15] = (count & 0x00FF);
    
    array[16] = valid;
    
    array[28] = (I2C_EVENT_INFO_SIGNATURE>>8);
    array[29] = (I2C_EVENT_INFO_SIGNATURE & 0x00FF);
    
    ret= eeprom_write(addr,(u8*)&array[0],30);
    
    if(ret>0) 
    {
        
    }
    else
    {
        eeprom_set_error(EEPROM_ERROR_WRITE_INFO);
    }
    return ret;  
}


i8 eeprom_ev_read_info(eeprom_info *ptr)
{
    u16 signature;
    u32 addr;
    i8 ret;
    u32 loc_idf;
    u32 loc_idl;
   
    u16 loc_ptrl;
    u16 loc_ptrf;
    u32 loc_count;
    bool loc_active;
    
    addr = (ptr->bloc);
    addr = addr * I2C_PACKET_PAYLOAD_SIZE;
    ret = I2C_Verify_Buffer(addr);
    if(ret < 0)
    {
        eeprom_set_error(EEPROM_ERROR_VERIFY_BUFFER);
        ptr->valid = FALSE;
        return -1;
    }
    else if(ret == 0)
    {   
        ptr->valid = FALSE;
        return 0;
    }
    else // ret>0
    {
        
        signature = I2C_Buffer_A[28];
        signature <<=8;
        signature += I2C_Buffer_A[29];
        
        if(signature != I2C_EVENT_INFO_SIGNATURE)
        {
            ptr->valid = FALSE;
            return 0;
        }
        ptr->valid = TRUE;
        
        
        // Récuperation de l'IDF
        loc_idf = I2C_Buffer_A[0];
        loc_idf<<=8;
        loc_idf += I2C_Buffer_A[1];
        loc_idf<<=8;
        loc_idf += I2C_Buffer_A[2];
        loc_idf<<=8;
        loc_idf += I2C_Buffer_A[3];
        
        // Récuperation de l'IDF
        loc_idl = I2C_Buffer_A[4];
        loc_idl<<=8;
        loc_idl += I2C_Buffer_A[5];
        loc_idl<<=8;
        loc_idl += I2C_Buffer_A[6];
        loc_idl<<=8;
        loc_idl += I2C_Buffer_A[7];
        
        // Récuperation du pointeur vers le bloc le plus ancien
        loc_ptrf = I2C_Buffer_A[8];
        loc_ptrf<<=8;
        loc_ptrf += I2C_Buffer_A[9];
        
        // Récupération du pointeur vers le bloc le plus récent
        loc_ptrl = I2C_Buffer_A[10];
        loc_ptrl<<=8;
        loc_ptrl += I2C_Buffer_A[11];
        
        
        // Récupération du compteur d'écriture dans le bloc info
        loc_count =  I2C_Buffer_A[12];
        loc_count<<=8;
        loc_count +=  I2C_Buffer_A[13];
        loc_count<<=8;
        loc_count +=  I2C_Buffer_A[14];
        loc_count<<=8;
        loc_count +=  I2C_Buffer_A[15];
       
        
        // Récuperation du flag indiquant si le bloc est deprecié ou non
        loc_active =  I2C_Buffer_A[16];
        
        
        ptr->idf = loc_idf;
        ptr->idl = loc_idl;
        ptr->ptrf = loc_ptrf;
        ptr->ptrl = loc_ptrl;
        ptr->cnt = loc_count;
        ptr->active = loc_active;
        
        return 1;
    }    
    
}



i8 eeprom_write(u32 addr,u8 *ptr,u8 count)
{
    i8 ret;
    u8 temp8;
    u16 crc;
    u32 phy_addrA = 0x00;
    u32 phy_addrB = 0x00;
    u16 bloc_start = 0x00;
    u16 block_stop = 0x00;
    u16 bloc_offset;

    if(eeprom_error == TRUE) return -2;
    
    // Calcul du bloc logique A et de l'offset A
    bloc_start = (addr / I2C_PACKET_PAYLOAD_SIZE);
    block_stop = ((addr+count-1)/I2C_PACKET_PAYLOAD_SIZE);
    if(bloc_start != block_stop) return 0;
    
    phy_addrA = bloc_start * I2C_PACKET_TOTAL_SIZE;
    phy_addrB = (bloc_start+I2C_LOG_COUNT_APP);
    phy_addrB = phy_addrB * I2C_PACKET_TOTAL_SIZE;
    
    
    ret = I2C_Verify_Buffer(addr);
    if(ret<0)
    {
        eeprom_set_error(EEPROM_ERROR_VERIFY_BUFFER);
        return ret;
    }
    bloc_offset = (addr % I2C_PACKET_PAYLOAD_SIZE);
    
    for(temp8=0;temp8<count;temp8++)
    {
       I2C_Buffer_B[bloc_offset+temp8] = *(ptr+temp8);
    }
    /*I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-4] = (I2C_PACKET_SIGNATURE>>8);
    I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-3] = (I2C_PACKET_SIGNATURE & 0x00FF);*/
    
    crc = calculate_crc((u8*) &I2C_Buffer_B[0],I2C_PACKET_PAYLOAD_SIZE);
    I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-2] = (crc>>8);
    I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-1] = (crc & 0x00FF);
    
            
    
    ret = I2C_Write_ll(phy_addrB,(u8*)&I2C_Buffer_B[0],I2C_PACKET_TOTAL_SIZE);  
    if(ret < 0)
    {
        eeprom_set_error(EEPROM_ERROR_WRITE_BUFFER_B);
        return ret;
    }
    ret = I2C_Write_ll(phy_addrA,(u8*)&I2C_Buffer_B[0],I2C_PACKET_TOTAL_SIZE);  
    if(ret < 0)
    {
        eeprom_set_error(EEPROM_ERROR_WRITE_BUFFER_A);
        return ret;
    }
    ret = I2C_Verify_Buffer(addr); 
    if(ret <=0)
    {
        eeprom_set_error(EEPROM_ERROR_VERIFY_BUFFER);
    }
    return ret;
    
}


i8 eeprom_read(u32 addr,u8 *ptr,u8 count)
{
    i8 ret;
    u8 temp8;
    
    u16 bloc_start = 0x00;
    u16 block_stop = 0x00;
    u16 bloc_offset;

    if(eeprom_error == TRUE) return -2;
    
    // Calcul du bloc logique A et de l'offset A
    bloc_start = (addr / I2C_PACKET_PAYLOAD_SIZE);
    block_stop = ((addr+count-1)/I2C_PACKET_PAYLOAD_SIZE);
    if(bloc_start != block_stop) return 0;
    

    ret = I2C_Verify_Buffer(addr);
    if(ret<0)
    {
        eeprom_set_error(EEPROM_ERROR_VERIFY_BUFFER);
        return ret;
    }
    if(ret == 0x00) return 0;

    bloc_offset = (addr % I2C_PACKET_PAYLOAD_SIZE);
    
    for(temp8=0;temp8<count;temp8++)
    {
        *(ptr+temp8) = I2C_Buffer_A[bloc_offset+temp8];
    }
    return 1;
}

