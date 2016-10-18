
#ifndef I2C_H
#define	I2C_H


#define I2C_PHY_BLOCK_COUNT           512
#define I2C_PHY_BLOCK_SIZE            256
#define I2C_PHY_TOTAL_SPACE          (I2C_PHY_BLOCK_COUNT*I2C_PHY_BLOCK_SIZE)


//#define I2C_PACKET_SIGNATURE          0x1234
#define I2C_PACKET_TOTAL_SIZE         32
#define I2C_PACKET_CRC_SIZE           2


#define I2C_PACKET_PAYLOAD_SIZE      (I2C_PACKET_TOTAL_SIZE-I2C_PACKET_CRC_SIZE)
#define I2C_LOG_BLOCK_PER_PHY_BLOCK  (I2C_PHY_BLOCK_SIZE/I2C_PACKET_TOTAL_SIZE)
#define I2C_LOG_BLOCK_COUNT          (I2C_LOG_BLOCK_PER_PHY_BLOCK*I2C_PHY_BLOCK_COUNT)
#define I2C_LOG_COUNT_APP            (I2C_LOG_BLOCK_COUNT/2)
#define I2C_LOG_ADDR_MAX             (I2C_LOG_COUNT_APP*I2C_PACKET_PAYLOAD_SIZE)

extern u8 I2C_Buffer_A[I2C_PACKET_TOTAL_SIZE];
extern u8 I2C_Buffer_B[I2C_PACKET_TOTAL_SIZE];

void i2c_init(void);
i8 I2C_Verify_Buffer(u32 addr);
i8 I2C_Read_ll(u32 addr,u8 *ptr,u16 cnt);
i8 I2C_Write_ll(u32 addr,u8 *ptr,u16 cnt);

#endif	/* I2C_H */

