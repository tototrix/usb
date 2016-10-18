#include <_Global_Include.h>
#include <math.h>
#define I2CACK    0
#define I2CNACK   1

volatile u8 error_case;                 // Contient l'état de la SM à l'origine du défaut (debug)

u8 I2C_Buffer_A[I2C_PACKET_TOTAL_SIZE]; // Buffer de stockage de la zone A
u8 I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE]; // Buffer de stockage de la zone B

void I2C_Reset_Bus(void);               // Permet de faire un reset sur le bus I2C

void I2C_Bus_Idle_High(void);           // NA 
void I2C_Bus_Idle_Low(void);            // NA
void I2C_Start(void);                   // Permet de générer une condition de start sur le bus
void I2C_Restart(void);                 // Permet de générer une condition de restart sur le bus
void I2C_Stop(void);                    // Permet de générer une condition de stop sur le bus

i8 I2C_Send_Byte(u8 value);             // Permet l'emission d'un octet sur le bus.
u8 I2C_Read_Byte(bool ack);             // Permet la lecture d'un octet sur le bus.


void I2C_Tempo()
{
    Nop();Nop();Nop();Nop();Nop();
}

u16 I2C_time_counter;



void i2c_init(void)
{
    u16 bloc;
    u32 addr;
    u8 value;
    u32 cycle = 0;
    I2C_SDA_TRIS = OUTPUT;
    I2C_SCL_TRIS = OUTPUT;
    I2C_SDA      = 1;
    I2C_SCL      = 1;
    
    I2C_Reset_Bus();
    timer1ms_register_variable((u16*)&I2C_time_counter);
    
    bloc  = 0x00;
    addr  = 0x00;
    cycle = 0x00;
    value = 0x00;
}
void I2C_Reset_Bus(void)
{
    volatile u8 temp8;
    ClrWdt();
    I2C_SDA_TRIS = INPUT;
    __delay_us(1);
    I2C_Stop();
    __delay_us(3);
    I2C_SDA_TRIS = INPUT;
    __delay_us(1);
    for(temp8=0;temp8<200;temp8++)
    {
        I2C_SCL_TRIS = OUTPUT;
        I2C_SCL      = 0;
        I2C_Tempo();
        I2C_SCL_TRIS = INPUT;
        I2C_Tempo();
    }
    __delay_us(1);
    I2C_Stop();
    __delay_us(3);
}

void I2C_Bus_Idle_High(void)
{
    
    
}
void I2C_Bus_Idle_Low(void) //Interrupt Maitre
{
    
}

void I2C_Start(void)
{
    __delay_us(3);
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    I2C_SDA_TRIS = INPUT;
    I2C_Tempo();
    I2C_Tempo();
    I2C_SDA_TRIS = OUTPUT;
    I2C_SDA = 0;
    I2C_Tempo();
}

void I2C_Restart(void) //Maitre
{
    __delay_us(3);
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    I2C_SDA_TRIS = INPUT;
    I2C_Tempo();
    __delay_us(3);
    I2C_Tempo();
    I2C_SDA_TRIS = OUTPUT;
    I2C_SDA = 0;
    I2C_Tempo();
}


void I2C_Stop(void) //Maitre
{
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    I2C_SDA_TRIS = OUTPUT;
    I2C_SDA = 0;
    I2C_Tempo();
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    I2C_SDA_TRIS = INPUT;
    __delay_us(1);
}




void I2C_ACK(void) //Maitre
{
    

}


i8 I2C_Send_Byte(u8 value)
{
    u8 i = 0;
    u8 data = value;
    bool ack  = FALSE;

    I2C_Tempo();
    
    do
    {
        I2C_SCL_TRIS = OUTPUT;
        I2C_SCL = 0;
        if(data & 0x80) I2C_SDA_TRIS = INPUT;
        else
        {
            I2C_SDA_TRIS = OUTPUT;
            I2C_SDA = 0;
        }
        data<<=1;
        I2C_SCL_TRIS = INPUT;
        I2C_Tempo();
        i++;
    }while(i<8);
    
    
    I2C_SCL_TRIS = OUTPUT;
    I2C_SCL = 0;
    I2C_Tempo();
    I2C_SDA_TRIS = INPUT;
    I2C_Tempo();
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    ack = I2C_SDA_IN;
    I2C_SCL_TRIS = OUTPUT;
    I2C_SCL = 0;
    I2C_Tempo();

    I2C_SDA_TRIS = OUTPUT;
    I2C_SDA = 0;
    I2C_Tempo();
    
    return ack; 
}

u8 I2C_Read_Byte(bool ack)
{
    u8 data = 0x00;
    u8 i=0;
    
    I2C_SDA_TRIS = INPUT;
    I2C_Tempo();
    do
    {
        data<<=1;
        I2C_SCL_TRIS = OUTPUT;
        I2C_SCL = 0;
        I2C_Tempo();
        
        data += I2C_SDA_IN;
        
        
        I2C_SCL_TRIS = INPUT;
        I2C_Tempo();
        
        //data += I2C_SDA_IN;
        //data<<=1;
        //if(I2C_SDA_IN) data+=0x80;
        //data>>=1;
        
        i++;
    }while(i<8);
    
    I2C_SCL_TRIS = OUTPUT;
    I2C_SCL = 0;
    I2C_Tempo();
    
    if(ack)
    {
        I2C_SDA_TRIS = INPUT;
    }
    else
    {
        I2C_SDA_TRIS = OUTPUT;
        I2C_SDA = 0;
    }
    I2C_Tempo();
    I2C_SCL_TRIS = INPUT;
    I2C_Tempo();
    I2C_SCL_TRIS = OUTPUT;
    I2C_SCL = 0;
    I2C_Tempo();
    I2C_SDA_TRIS = OUTPUT;
    I2C_SDA = 0;
    I2C_Tempo(); 
   
    //I2C_SDA_TRIS = INPUT;
    //I2C_Tempo(); 
    return data; 
}


i8 I2C_Write_ll(u32 addr,u8 *ptr,u16 cnt)
{
    volatile u32 phy_addr = addr;
    volatile u8 state = 0x00;
    volatile u8 count = 0x00;
    volatile u16 i=0;
    volatile i8 ack;
    volatile u8 adr_chip = 0xAC;
    volatile u8 read_polling;
    
    while(1)
    {
        ClrWdt();
        switch(state)
        {
            case 0:
                __delay_us(50);
                I2C_Bus_Idle_Low();
                I2C_Start();
                I2C_Bus_Idle_High();
                if(phy_addr & 0x10000) adr_chip += 2;
                ack = I2C_Send_Byte(adr_chip);
                if(ack != 0x00) 
                {
                    error_case = 100;
                    I2C_Stop();
                    state = 100;
                }
                else state = 1;
                break;
                
            case 1:
                I2C_Bus_Idle_High();
                phy_addr = addr;
                phy_addr >>=8;
                phy_addr = phy_addr & 0x00FF;
                
                ack = I2C_Send_Byte((u8)(phy_addr));
                if(ack != 0x00) 
                {
                    error_case = 101;
                    I2C_Stop();
                    state = 100;
                }
                else state = 2;
                break;
                
            case 2:
                I2C_Bus_Idle_High();
                phy_addr = addr;
                phy_addr = phy_addr & 0x00FF;
                ack = I2C_Send_Byte((u8)(phy_addr & 0x00FF));
                if(ack != 0x00) 
                {
                    error_case = 102;
                    I2C_Stop();
                    state = 100;
                }
                else
                {
                    i = 0x00;
                    I2C_Bus_Idle_High();
                    state = 3;
                }
                break;
                
            case 3:
                ack = I2C_Send_Byte(*(ptr+i));
                if(ack != 0x00) 
                {
                    error_case = 103;
                    I2C_Stop();
                    state = 100;
                }
                else
                {
                    i++;
                    if(i>=cnt)
                    {
                        I2C_Stop();
                       
                        I2C_time_counter = 30;
                        state = 4;
                    }
                }
                break;
                
            case 4:
                 __delay_us(100);
                 //I2C_Bus_Idle_High();
                ack = I2C_Read_ll(addr,(u8*)&read_polling,1);
                
                if(ack == 0x00)
                {
                    I2C_Stop();
                    
                   
                    return 0;
                }
                else if(I2C_time_counter == 0x00)
                {
                    error_case = 104;
                    state = 100;
                }
                break;
                
            case 100:
                I2C_Reset_Bus();
                count++;
                if(count < 20)
                {
                    state = 0;
                }
                else
                {
                    I2C_Stop();
                    return -1;
                }
                break;
        }
    }
    
    return 0;
}

i8 I2C_Read_ll(u32 addr,u8 *ptr,u16 cnt)
{
    volatile u32 phy_addr = addr;
    volatile u8 state = 0x00;
    volatile u8 count = 0x00;
    volatile u16 i=0;
    volatile i8 ack;
    volatile u8 adr_chip = 0xAC;//0xAC;
    volatile u8 send_adr_chip;
    while(1)
    {
        ClrWdt();
        switch(state)
        {
            case 0:
                __delay_us(50);
                I2C_Bus_Idle_Low();
                I2C_Start();
                I2C_Bus_Idle_High();    
                send_adr_chip = adr_chip;
                if(phy_addr & 0x10000) adr_chip += 2;
                ack = I2C_Send_Byte(adr_chip);
                if(ack != 0x00) 
                {
                    error_case = 0;
                    I2C_Stop();
                    state = 100;
                }
                else state = 1;
                break;
                
            case 1:
                I2C_Bus_Idle_High();
                phy_addr = addr;
                phy_addr >>=8;
                phy_addr = phy_addr & 0x00FF;
                ack = I2C_Send_Byte((u8)(phy_addr));
                if(ack != 0x00) 
                {
                    error_case = 1;
                    I2C_Stop();
                    state = 100;
                }
                else state = 2;
                break;
            
            case 2:
                I2C_Bus_Idle_High();
                phy_addr = addr;
                phy_addr = phy_addr & 0x00FF;
                
                ack = I2C_Send_Byte((u8)(phy_addr & 0x00FF));
                if(ack != 0x00) 
                {
                    error_case = 2;
                    I2C_Stop();
                    state = 100;
                }
                else state = 3;
                break;
                
            case 3:
                I2C_Bus_Idle_High();
                I2C_Restart();
                send_adr_chip = adr_chip;
                ack = I2C_Send_Byte(adr_chip+1);
                //ack = I2C_Send_Byte(0x54);
                if(ack != 0x00) 
                {
                    
                    error_case = 3;
                    I2C_Stop();
                    state=100;
                }
                else
                {
                    
                    I2C_Bus_Idle_High();
                    i = 0x00;
                    state = 4;
                }
                
                break;
                
            case 4:
                if(i == (cnt-1)) 
                {
                    *(ptr+i) = I2C_Read_Byte(I2CNACK); 
                }
                else
                {
                    *(ptr+i) = I2C_Read_Byte(I2CACK); 
                }
                
                i++;
                if(i>=cnt)
                {
                    I2C_Stop();
                    
                    
                    return 0;
                }
                
                break;
                
            case 100:
                I2C_Reset_Bus();
                count++;
                if(count < 20)
                {
                    state = 0;
                }
                else
                {
                    I2C_Stop();
                    return -1;
                }
                break;
        }
    }
    
    return 0;
}

i8 I2C_Verify_Buffer(u32 addr)
{
    i8 ret;
    u8 temp8;
    u8 count;
    u16 crc_calc;
    u16 crc_read;

    
    u32 phy_addrA = 0x00;
    u32 phy_addrB = 0x00;
    u16 phy_block = 0x00;
    u16 phy_offset = 0x00;
    bool crc_bufferA_ok = FALSE;
    bool crc_bufferB_ok = FALSE;
    bool same_content = TRUE;
    
    // Calcul du bloc logique A et de l'offset A
    phy_block = (addr / I2C_PACKET_PAYLOAD_SIZE);
    phy_offset = (addr % I2C_PACKET_PAYLOAD_SIZE);
    phy_addrA = phy_block * I2C_PACKET_TOTAL_SIZE;
    phy_addrB = (phy_block+I2C_LOG_COUNT_APP);
    phy_addrB = phy_addrB * I2C_PACKET_TOTAL_SIZE;
    crc_calc = I2C_LOG_COUNT_APP;
    
    
    
    
    count = 0x00;
    do{
        

        
        ret = I2C_Read_ll(phy_addrA,(u8*)&I2C_Buffer_A[0],I2C_PACKET_TOTAL_SIZE);
        if(ret >=0)
        {
            
            
           crc_read = I2C_Buffer_A[I2C_PACKET_TOTAL_SIZE-2];
           crc_read <<=8;
           crc_read += I2C_Buffer_A[I2C_PACKET_TOTAL_SIZE-1];
           crc_calc = calculate_crc((u8*)&I2C_Buffer_A[0],I2C_PACKET_PAYLOAD_SIZE);
           if(crc_read == crc_calc)
           {
              crc_bufferA_ok = TRUE;
           }
           else crc_bufferA_ok = FALSE;
        }
        if(ret < 0) return ret;
        

        ret = I2C_Read_ll(phy_addrB,(u8*)&I2C_Buffer_B[0],I2C_PACKET_TOTAL_SIZE);
        //ret = I2C_Read_ll(phy_addrB,(u8*)&I2C_Buffer_B[0],5);
        if(ret >=0)
        {
           crc_read = I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-2];
           crc_read <<=8;
           crc_read += I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE-1];

           crc_calc = calculate_crc((u8*)&I2C_Buffer_B[0],I2C_PACKET_PAYLOAD_SIZE);

           if(crc_read == crc_calc)
           {
              crc_bufferB_ok = TRUE;
           }
           else crc_bufferA_ok = FALSE;
        }
        if(ret < 0) return ret;
        

        // on verifie si les packets ont le même contenu
        same_content = TRUE;
        for(temp8=0;temp8<I2C_PACKET_TOTAL_SIZE;temp8++)
        {
           if(I2C_Buffer_A[temp8] != I2C_Buffer_B[temp8])  same_content = FALSE;    
        }

        if(crc_bufferA_ok == TRUE && crc_bufferA_ok == TRUE && same_content == TRUE) return 1;
        if(crc_bufferA_ok == FALSE && crc_bufferA_ok == FALSE) return 0;

        temp8 = 0x00;

        if(crc_bufferA_ok == TRUE && crc_bufferB_ok == TRUE && same_content == FALSE)
        {
            ret = I2C_Write_ll(phy_addrA,(u8*)&I2C_Buffer_B[0],I2C_PACKET_TOTAL_SIZE);  
            if(ret < 0) return ret;
            count++;
        }
        
        if(crc_bufferA_ok == TRUE && crc_bufferB_ok == FALSE)
        {
            ret = I2C_Write_ll(phy_addrB,(u8*)&I2C_Buffer_A[0],I2C_PACKET_TOTAL_SIZE);  
            if(ret < 0) return ret;
            count++;
        }
    
        if(crc_bufferA_ok == FALSE && crc_bufferB_ok == TRUE)
        {
            ret = I2C_Write_ll(phy_addrA,(u8*)&I2C_Buffer_B[0],I2C_PACKET_TOTAL_SIZE);  
            if(ret < 0) return ret;
            count++;
        }    
    }while(count<10);
    
    return -1;
}


