#include <_Global_Include.h>


// Definition des états de la machine de gestion des rampes
typedef enum
{
  ADC_START, 
  ADC_PIC_TEMP,
  ADC_VBAT,
  ADC_EVENT_VBAT,        
  ADC_CTN_TEMP,
  
  ADC_STORE_TEST,
  ADC_STORE,
          
          
  ADC_MANUAL1,
  ADC_MANUAL2,
  ADC_MANUAL3,
  ADC_MANUAL4,
  ADC_MANUAL5,
  ADC_MANUAL6,
          
}enum_adc_sm;


bool adc_ctn_high_temp = FALSE;

volatile u16 adc_band_gap_ref;
volatile u16 adc_band_gap;
volatile u16 adc_band_debug;
volatile u16 adc_band_counter_event;

volatile u8  adc_band_counter;

u8  adc_state           = 0x00;
i16 ctn_temperature     = 0x00;
i16 ctn_min_temperature = 0x00;
i16 ctn_max_temperature = 0x00;
bool adc_extreme_change = FALSE;
bool adc_24v_overvoltage = FALSE;
u8   adc_24v_overvoltage_ar = 0x00;

u16  adc_low_battery_filter_cnt = 0;

volatile u16 adc_time_counter  = 0x00;
u16 adc_counter                = 0x00;
bool adc_low_battery           = FALSE;
u16 adc_vbat                   = 0x00;
#ifdef DEBUG_PRINTF_VBAT
u32 adc_counter_debug = 0x00;
#endif

u16 adc_sample_count = 0x00;
u16 adc_vbat_array[ADC_SAMPLES];
u16 adc_temp_array[ADC_SAMPLES];
u16 adc_ctn_array[ADC_SAMPLES];
i16 adc_ctn = 0x00;
u16 adc_ctn_ref[166];
i16 adc_ctn_pcb(u16 adc_value);


typedef enum
{
  ADC_KEEPALIVE_IDLE, 
  ADC_KEEPALIVE_1,
  ADC_KEEPALIVE_2,
  ADC_KEEPALIVE_3,        
  ADC_KEEPALIVE_4, 
  ADC_KEEPALIVE_5,        
  ADC_KEEPALIVE_6, 
          
}enum_adc_keepalive_sm;
u8 adc_keepalive_state;
u8 adc_keepalive_counter;

void adc_keepalive_sm(void);


void adc_init(void)
{
    u8 i;
    
    VBAT_TRIS             = INPUT;
    VBAT_AN               = 1;
    CTN_TRIS              = INPUT;
    CTN_AN                = 1;

    AD1CON1bits.ADON      = FALSE;
    AD1CON1bits.SSRC      = 0;
    AD1CON1bits.ASAM      = FALSE;
    AD1CON2bits.VCFG      = 0;
    AD1CON2bits.CHPS      = 0;
    AD1CON2bits.SMPI      = 0;    
    AD1CON3bits.ADRC      = 0;
    AD1CON3bits.ADCS      = 31;
    AD1CON3bits.SAMC      = 31;
    AD1CON1bits.AD12B     = TRUE;
    AD1CON1bits.ADON      = TRUE;
    AD1CHS0bits.CH0SA     = 1;
    AD1CHS0bits.CH0NA     = 0;
    CTMUCON1bits.CTMUEN   = FALSE;//TRUE;
    CTMUICONbits.IRNG     = 0;//2; 
    CTMUCON2bits.EDG1STAT = 0;
    CTMUCON2bits.EDG2STAT = 0;
    
    adc_keepalive_state   = ADC_KEEPALIVE_IDLE;
    adc_keepalive_counter = 0x00;
    
    adc_state             = ADC_START;
    
    timer1ms_register_variable((u16*)&adc_time_counter);
    adc_time_counter = ADC_TIMER_VALUE;
    
    adc_24v_overvoltage = FALSE;
    adc_24v_overvoltage_ar = 0x00;
    
    ctn_temperature     = 0;
    ctn_min_temperature = 10000;
    ctn_max_temperature = 0;
    adc_counter         = 0x00;
    adc_extreme_change  = FALSE;
    adc_low_battery     = FALSE;
    adc_sample_count    = 0x00;
    adc_ctn_high_temp   = FALSE;
    for(i=0;i<ADC_SAMPLES;i++)adc_vbat_array[i] = 0x00;
    for(i=0;i<ADC_SAMPLES;i++)adc_temp_array[i] = 0x00;
    
    
    
    #ifdef BOARD_RELEASE_D
    adc_ctn_ref[0] = CTN_PCB_0;
    adc_ctn_ref[1] = CTN_PCB_1;
    adc_ctn_ref[2] = CTN_PCB_2;
    adc_ctn_ref[3] = CTN_PCB_3;
    adc_ctn_ref[4] = CTN_PCB_4;
    adc_ctn_ref[5] = CTN_PCB_5;
    adc_ctn_ref[6] = CTN_PCB_6;
    adc_ctn_ref[7] = CTN_PCB_7;
    adc_ctn_ref[8] = CTN_PCB_8;
    adc_ctn_ref[9] = CTN_PCB_9;
    adc_ctn_ref[10] = CTN_PCB_10;
    adc_ctn_ref[11] = CTN_PCB_11;
    adc_ctn_ref[12] = CTN_PCB_12;
    adc_ctn_ref[13] = CTN_PCB_13;
    adc_ctn_ref[14] = CTN_PCB_14;
    adc_ctn_ref[15] = CTN_PCB_15;
    adc_ctn_ref[16] = CTN_PCB_16;
    adc_ctn_ref[17] = CTN_PCB_17;
    adc_ctn_ref[18] = CTN_PCB_18;
    adc_ctn_ref[19] = CTN_PCB_19;
    adc_ctn_ref[20] = CTN_PCB_20;
    adc_ctn_ref[21] = CTN_PCB_21;
    adc_ctn_ref[22] = CTN_PCB_22;
    adc_ctn_ref[23] = CTN_PCB_23;
    adc_ctn_ref[24] = CTN_PCB_24;
    adc_ctn_ref[25] = CTN_PCB_25;
    adc_ctn_ref[26] = CTN_PCB_26;
    adc_ctn_ref[27] = CTN_PCB_27;
    adc_ctn_ref[28] = CTN_PCB_28;
    adc_ctn_ref[29] = CTN_PCB_29;
    adc_ctn_ref[30] = CTN_PCB_30;
    adc_ctn_ref[31] = CTN_PCB_31;
    adc_ctn_ref[32] = CTN_PCB_32;
    adc_ctn_ref[33] = CTN_PCB_33;
    adc_ctn_ref[34] = CTN_PCB_34;
    adc_ctn_ref[35] = CTN_PCB_35;
    adc_ctn_ref[36] = CTN_PCB_36;
    adc_ctn_ref[37] = CTN_PCB_37;
    adc_ctn_ref[38] = CTN_PCB_38;
    adc_ctn_ref[39] = CTN_PCB_39;
    adc_ctn_ref[40] = CTN_PCB_40;
    adc_ctn_ref[41] = CTN_PCB_41;
    adc_ctn_ref[42] = CTN_PCB_42;
    adc_ctn_ref[43] = CTN_PCB_43;
    adc_ctn_ref[44] = CTN_PCB_44;
    adc_ctn_ref[45] = CTN_PCB_45;
    adc_ctn_ref[46] = CTN_PCB_46;
    adc_ctn_ref[47] = CTN_PCB_47;
    adc_ctn_ref[48] = CTN_PCB_48;
    adc_ctn_ref[49] = CTN_PCB_49;
    adc_ctn_ref[50] = CTN_PCB_50;
    adc_ctn_ref[51] = CTN_PCB_51;
    adc_ctn_ref[52] = CTN_PCB_52;
    adc_ctn_ref[53] = CTN_PCB_53;
    adc_ctn_ref[54] = CTN_PCB_54;
    adc_ctn_ref[55] = CTN_PCB_55;
    adc_ctn_ref[56] = CTN_PCB_56;
    adc_ctn_ref[57] = CTN_PCB_57;
    adc_ctn_ref[58] = CTN_PCB_58;
    adc_ctn_ref[59] = CTN_PCB_59;
    adc_ctn_ref[60] = CTN_PCB_60;
    adc_ctn_ref[61] = CTN_PCB_61;
    adc_ctn_ref[62] = CTN_PCB_62;
    adc_ctn_ref[63] = CTN_PCB_63;
    adc_ctn_ref[64] = CTN_PCB_64;
    adc_ctn_ref[65] = CTN_PCB_65;
    adc_ctn_ref[66] = CTN_PCB_66;
    adc_ctn_ref[67] = CTN_PCB_67;
    adc_ctn_ref[68] = CTN_PCB_68;
    adc_ctn_ref[69] = CTN_PCB_69;
    adc_ctn_ref[70] = CTN_PCB_70;
    adc_ctn_ref[71] = CTN_PCB_71;
    adc_ctn_ref[72] = CTN_PCB_72;
    adc_ctn_ref[73] = CTN_PCB_73;
    adc_ctn_ref[74] = CTN_PCB_74;
    adc_ctn_ref[75] = CTN_PCB_75;
    adc_ctn_ref[76] = CTN_PCB_76;
    adc_ctn_ref[77] = CTN_PCB_77;
    adc_ctn_ref[78] = CTN_PCB_78;
    adc_ctn_ref[79] = CTN_PCB_79;
    adc_ctn_ref[80] = CTN_PCB_80;
    adc_ctn_ref[81] = CTN_PCB_81;
    adc_ctn_ref[82] = CTN_PCB_82;
    adc_ctn_ref[83] = CTN_PCB_83;
    adc_ctn_ref[84] = CTN_PCB_84;
    adc_ctn_ref[85] = CTN_PCB_85;
    adc_ctn_ref[86] = CTN_PCB_86;
    adc_ctn_ref[87] = CTN_PCB_87;
    adc_ctn_ref[88] = CTN_PCB_88;
    adc_ctn_ref[89] = CTN_PCB_89;
    adc_ctn_ref[90] = CTN_PCB_90;
    adc_ctn_ref[91] = CTN_PCB_91;
    adc_ctn_ref[92] = CTN_PCB_92;
    adc_ctn_ref[93] = CTN_PCB_93;
    adc_ctn_ref[94] = CTN_PCB_94;
    adc_ctn_ref[95] = CTN_PCB_95;
    adc_ctn_ref[96] = CTN_PCB_96;
    adc_ctn_ref[97] = CTN_PCB_97;
    adc_ctn_ref[98] = CTN_PCB_98;
    adc_ctn_ref[99] = CTN_PCB_99;
    adc_ctn_ref[100] = CTN_PCB_100;
    adc_ctn_ref[101] = CTN_PCB_101;
    adc_ctn_ref[102] = CTN_PCB_102;
    adc_ctn_ref[103] = CTN_PCB_103;
    adc_ctn_ref[104] = CTN_PCB_104;
    adc_ctn_ref[105] = CTN_PCB_105;
    adc_ctn_ref[106] = CTN_PCB_106;
    adc_ctn_ref[107] = CTN_PCB_107;
    adc_ctn_ref[108] = CTN_PCB_108;
    adc_ctn_ref[109] = CTN_PCB_109;
    adc_ctn_ref[110] = CTN_PCB_110;
    adc_ctn_ref[111] = CTN_PCB_111;
    adc_ctn_ref[112] = CTN_PCB_112;
    adc_ctn_ref[113] = CTN_PCB_113;
    adc_ctn_ref[114] = CTN_PCB_114;
    adc_ctn_ref[115] = CTN_PCB_115;
    adc_ctn_ref[116] = CTN_PCB_116;
    adc_ctn_ref[117] = CTN_PCB_117;
    adc_ctn_ref[118] = CTN_PCB_118;
    adc_ctn_ref[119] = CTN_PCB_119;
    adc_ctn_ref[120] = CTN_PCB_120;
    adc_ctn_ref[121] = CTN_PCB_121;
    adc_ctn_ref[122] = CTN_PCB_122;
    adc_ctn_ref[123] = CTN_PCB_123;
    adc_ctn_ref[124] = CTN_PCB_124;
    adc_ctn_ref[125] = CTN_PCB_125;
    adc_ctn_ref[126] = CTN_PCB_126;
    adc_ctn_ref[127] = CTN_PCB_127;
    adc_ctn_ref[128] = CTN_PCB_128;
    adc_ctn_ref[129] = CTN_PCB_129;
    adc_ctn_ref[130] = CTN_PCB_130;
    adc_ctn_ref[131] = CTN_PCB_131;
    adc_ctn_ref[132] = CTN_PCB_132;
    adc_ctn_ref[133] = CTN_PCB_133;
    adc_ctn_ref[134] = CTN_PCB_134;
    adc_ctn_ref[135] = CTN_PCB_135;
    adc_ctn_ref[136] = CTN_PCB_136;
    adc_ctn_ref[137] = CTN_PCB_137;
    adc_ctn_ref[138] = CTN_PCB_138;
    adc_ctn_ref[139] = CTN_PCB_139;
    adc_ctn_ref[140] = CTN_PCB_140;
    adc_ctn_ref[141] = CTN_PCB_141;
    adc_ctn_ref[142] = CTN_PCB_142;
    adc_ctn_ref[143] = CTN_PCB_143;
    adc_ctn_ref[144] = CTN_PCB_144;
    adc_ctn_ref[145] = CTN_PCB_145;
    adc_ctn_ref[146] = CTN_PCB_146;
    adc_ctn_ref[147] = CTN_PCB_147;
    adc_ctn_ref[148] = CTN_PCB_148;
    adc_ctn_ref[149] = CTN_PCB_149;
    adc_ctn_ref[150] = CTN_PCB_150;
    adc_ctn_ref[151] = CTN_PCB_151;
    adc_ctn_ref[152] = CTN_PCB_152;
    adc_ctn_ref[153] = CTN_PCB_153;
    adc_ctn_ref[154] = CTN_PCB_154;
    adc_ctn_ref[155] = CTN_PCB_155;
    adc_ctn_ref[156] = CTN_PCB_156;
    adc_ctn_ref[157] = CTN_PCB_157;
    adc_ctn_ref[158] = CTN_PCB_158;
    adc_ctn_ref[159] = CTN_PCB_159;
    adc_ctn_ref[160] = CTN_PCB_160;
    adc_ctn_ref[161] = CTN_PCB_161;
    adc_ctn_ref[162] = CTN_PCB_162;
    adc_ctn_ref[163] = CTN_PCB_163;
    adc_ctn_ref[164] = CTN_PCB_164;
    adc_ctn_ref[165] = CTN_PCB_165;
    #endif
}

#ifdef BOARD_RELEASE_D
i16 adc_ctn_pcb(u16 adc_value)
{
  u8 index = 0x00;
  
  while(1)
  {
    if(adc_value > adc_ctn_ref[index])
    {
        if(index == 0)
        {
            return -40;
        }
        else
        {
            return (index-40-1);
        }
    }
    index++;
    if(index == 166) return 125;  
  }
}
#endif


void adc_keepalive_sm(void)
{
    u8 next_state = adc_keepalive_state;
    switch(adc_keepalive_state)
    {
        case ADC_KEEPALIVE_IDLE:
            if(adc_low_battery == TRUE)
            {
              
                adc_keepalive_counter++;
                if(adc_keepalive_counter >= 60)
                {
                    adc_keepalive_counter = 0x00;
                    next_state = ADC_KEEPALIVE_1;
                }
            }
            else
            {
                adc_keepalive_counter = 0x00;
            }
            break;
            
        case ADC_KEEPALIVE_1:
            if((adc_low_battery ==FALSE) || (motor_algo_mode == MANUAL_MODE))
            {
                next_state = ADC_KEEPALIVE_IDLE;
            }
            else if(uarts_tx_mgmt_is_mutex_free() == TRUE)
            {
                uarts_tx_mgmt_get_mutex();
                uarts_tx_mgmt_packet_tx_init(UARTS_TYPE_MODEM,0x00,UARTS_FIRMWARE_ORDER_TO_MODEM_FORCE_KEEPALIVE);
                uarts_tx_mgmt_packet_tx_add_byte(usb_with_modem);
                uarts_tx_mgmt_packet_tx_finalize();
                uarts_tx_mgmt_go(3000);
                next_state = ADC_KEEPALIVE_2;
            }
            break;
            
        case ADC_KEEPALIVE_2:
            if(uarts_tx_mgmt_is_busy() == FALSE)
            {
                uarts_tx_mgmt_release_mutex();
          
                if(uarts_tx_mgmt_is_error() == TRUE)
                {
                   adc_keepalive_counter++;
                   if(adc_keepalive_counter < 4)
                   {
                       next_state = ADC_KEEPALIVE_1;
                   }
                   else
                   {
                       next_state = ADC_KEEPALIVE_IDLE;
                   }
                   
                }
                else
                {
                    adc_keepalive_counter = 0x00;
                    next_state = ADC_KEEPALIVE_3;
                }   
            }
            break;
            
        case ADC_KEEPALIVE_3:
            
                if(motor_algo_mode == MANUAL_MODE) next_state = ADC_KEEPALIVE_IDLE;
                else if(adc_low_battery ==FALSE)
                {
                    adc_keepalive_counter++;
                    if(adc_keepalive_counter >= 30)
                    {
                        
                        adc_keepalive_counter = 0x00;
                        next_state = ADC_KEEPALIVE_4;
                    }
                }
            
            break;
            
         case ADC_KEEPALIVE_4:
             if(motor_algo_mode == MANUAL_MODE) next_state = ADC_KEEPALIVE_IDLE;
             else if((adc_low_battery ==TRUE) )
             {
                next_state = ADC_KEEPALIVE_3;
             }
             else if(uarts_tx_mgmt_is_mutex_free() == TRUE)
             {
                uarts_tx_mgmt_get_mutex();
                uarts_tx_mgmt_packet_tx_init(UARTS_TYPE_MODEM,0x00,UARTS_FIRMWARE_ORDER_TO_MODEM_FORCE_KEEPALIVE);
                uarts_tx_mgmt_packet_tx_add_byte(usb_with_modem);
                uarts_tx_mgmt_packet_tx_finalize();
                uarts_tx_mgmt_go(3000);
                next_state = ADC_KEEPALIVE_5;
             }
            break;
            
        case ADC_KEEPALIVE_5:
            if(uarts_tx_mgmt_is_busy() == FALSE)
            {
                uarts_tx_mgmt_release_mutex();
          
                if(uarts_tx_mgmt_is_error() == TRUE)
                {
                   adc_keepalive_counter++;
                   if(adc_keepalive_counter < 4)
                   {
                       next_state = ADC_KEEPALIVE_4;
                   }
                   else
                   {
                       next_state = ADC_KEEPALIVE_IDLE;
                   }
                   
                }
                else
                {
                    next_state = ADC_KEEPALIVE_IDLE;
                }   
            }
            break;   
            
    }
    adc_keepalive_state = next_state;
}
void adc_sm(void)
{
    volatile double d = 0.0;
    u16 temp16;
    
    u8 i;
    volatile u8 next_state = adc_state;
    
    //adc_keepalive_sm();
    
    switch(adc_state)
    {
        case ADC_START:
            
            next_state = ADC_PIC_TEMP;
            break;
            
      
            
        case ADC_PIC_TEMP:
            if(adc_time_counter == 0x00)
            {
                next_state = ADC_VBAT;
            }
            break;
           
        case ADC_VBAT:
          
            AD1CHS0bits.CH0SA = 3; // VBAT
            __delay_us(20);
            AD1CON1bits.SAMP = 1;
            __delay_us(20);
            AD1CON1bits.SAMP = 0;
            while(!AD1CON1bits.DONE);
            temp16 = ADC1BUF0;
            
            
            
            d = (temp16 * 5.0) / 4096.0;
            d = d*600.0;
            
            for(i=1;i<ADC_SAMPLES;i++)adc_vbat_array[i-1] = adc_vbat_array[i];
            adc_vbat_array[ADC_SAMPLES-1] = d;
            
            next_state = ADC_CTN_TEMP;
            
            if(adc_sample_count >= ADC_SAMPLES)
            {
                adc_vbat = 0x00;
                for(i=0;i<ADC_SAMPLES;i++) adc_vbat += adc_vbat_array[i];
                adc_vbat = (adc_vbat/ADC_SAMPLES);

                
                if(panel_size != PANEL_SIZE_UNKNOWN)
                {
                    if( (adc_low_battery == FALSE) && 
                        (
                          (panel_size == PANEL_SIZE_2M2 && adc_vbat < ADC_LOW_BATT_2M2) ||
                          (panel_size == PANEL_SIZE_8M2 && adc_vbat < ADC_LOW_BATT_8M2)
                        )
                      )
                    {
                        if(adc_low_battery_filter_cnt < ADC_LOW_BATT_FILTER)
                        {
                            adc_low_battery_filter_cnt++;
                        }
                        else
                        {
                            adc_low_battery = TRUE;
                        }
                    }
                    else if(adc_vbat > ADC_BATT_OK_THRESHOLD && adc_low_battery == TRUE)
                    {
                        if(adc_low_battery_filter_cnt>0)
                        {
                            adc_low_battery_filter_cnt--;
                        }
                        else
                        {
                            adc_low_battery = FALSE;
                        }
                    }
                    else if(adc_low_battery == FALSE &&
                            ((panel_size == PANEL_SIZE_2M2 && adc_vbat > ADC_LOW_BATT_2M2) ||
                             (panel_size == PANEL_SIZE_8M2 && adc_vbat > ADC_LOW_BATT_8M2))
                            )
                    {
                        if(adc_low_battery_filter_cnt>0)
                        {
                            adc_low_battery_filter_cnt--;
                        }
                    }
                }
                
            }
            break;
        
            
            
        case ADC_EVENT_VBAT:
            if(motor_auto_scrolling == 0x00)
            {
                if(adc_low_battery == TRUE)
                {
                    eeprom_ev_write1(EEPROM_EV_LOW_BATTERY);
                }
                else
                {
                    eeprom_ev_write1(EEPROM_EV_BATTERY_OK);
                }
                next_state = ADC_CTN_TEMP;
            }      
            break;
            
    
        case ADC_CTN_TEMP:
            AD1CHS0bits.CH0SA = 31; // CTN
            __delay_us(20);
            AD1CON1bits.SAMP = 1;
            __delay_us(30);
            AD1CON1bits.SAMP = 0;
            while(!AD1CON1bits.DONE);
            temp16 = ADC1BUF0;
            
            d = temp16;
                        
            for(i=1;i<ADC_SAMPLES;i++)adc_ctn_array[i-1] = adc_ctn_array[i];
            adc_ctn_array[ADC_SAMPLES-1] = d;
            
            if(adc_sample_count >= ADC_SAMPLES)
            {
                temp16 = 0x00;
                for(i=0;i<ADC_SAMPLES;i++) temp16 += adc_ctn_array[i];
                temp16 = (temp16/ADC_SAMPLES);
                adc_ctn = adc_ctn_pcb(temp16);  
                
                if(seconds_counter > 15)
                {
                    if(adc_ctn < ctn_min_temperature)
                    {
                        ctn_min_temperature = adc_ctn;
                        adc_extreme_change  = TRUE;
                    }
                    if(adc_ctn > ctn_max_temperature)
                    {
                        ctn_max_temperature = adc_ctn;
                        adc_extreme_change  = TRUE;
                    }
                } 
            }
            else adc_sample_count++;
            
            //if(motor_algo_mode != MANUAL_MODE) adc_time_counter = ADC_TIMER_VALUE;
            //else adc_time_counter = ADC_TIMER_VALUE_MANUAL;
            adc_time_counter = ADC_TIMER_VALUE;
            
            next_state = ADC_START; 
               
            break;
     
            
            
        case ADC_STORE_TEST:
            adc_counter++;
            if(adc_counter >= ADC_STORE_CYCLE_COUNT)
            {
                adc_counter = 0x00;
                
                
                #ifdef DEBUG_PRINTF_STATUS
                printf("      MASTER MCU TEMP   : MIN %4d  MAX %4d\n",  mcu_min_temperature,mcu_max_temperature);
                printf("      SH MCU TEMP       : MIN %4d  MAX %4d\n",  motor_status.motorh_pic_min_temperature,motor_status.motorh_pic_max_temperature);
                printf("      SH BRIDGE TEMP    : MIN %4d  MAX %4d\n",  motor_status.motorh_bridge_min_temperature,motor_status.motorh_bridge_max_temperature);
                printf("      SH BRIDGE CURRENT : MIN %4d  MAX %4d\n",  motor_status.motorh_bridge_min_current,motor_status.motorh_bridge_max_current);
                printf("      SL MCU TEMP       : MIN %4d  MAX %4d\n",  motor_status.motorl_pic_min_temperature,motor_status.motorl_pic_max_temperature);
                printf("      SL BRIDGE TEMP    : MIN %4d  MAX %4d\n",  motor_status.motorl_bridge_min_temperature,motor_status.motorl_bridge_max_temperature);
                printf("      SL BRIDGE CURRENT : MIN %4d  MAX %4d\n",  motor_status.motorl_bridge_min_current,motor_status.motorl_bridge_max_current);
                #endif    

                    
                if(adc_extreme_change || slave_status_extreme_change)
                {
                    next_state = ADC_STORE;  
                }
                else
                {
                    adc_time_counter = ADC_TIMER_VALUE;
                    next_state = ADC_START;
                }
            }
            else
            {
               adc_time_counter = ADC_TIMER_VALUE;
               next_state = ADC_START; 
            }
            break;
            
        case ADC_STORE:
            
            if( (motor_algo_mode ==  MANUAL_MODE) ||
                (motor_auto_scrolling == 0)     
               )
            {
                    #ifdef DEBUG_PRINTF_STATUS
                    printf("      STORE STATUS\n");
                    #endif
                    next_state       = ADC_START;
                    adc_time_counter = ADC_TIMER_VALUE;
            
                    
                    if(adc_extreme_change)
                    {
                        adc_extreme_change = FALSE;
                        
                        eeprom_var16_update(EEPROM_VAR16_CTN_MIN_TEMPERATURE);
                        eeprom_var16_update(EEPROM_VAR16_CTN_MAX_TEMPERATURE);
                        
                    }
                    
                    if(slave_status_extreme_change)
                    {
                        slave_status_extreme_change = FALSE;
                    }
                    
                    
                    
                    
                    
                    /*flash_maj_adc(  mcu_min_temperature,
                                    mcu_max_temperature,
                            
                                    motor_status.motorh_pic_min_temperature,
                                    motor_status.motorh_pic_max_temperature,
                                    motor_status.motorh_bridge_min_temperature,
                                    motor_status.motorh_bridge_max_temperature,
                                    motor_status.motorh_bridge_min_current,
                                    motor_status.motorh_bridge_max_current,
                            
                                    motor_status.motorl_pic_min_temperature,
                                    motor_status.motorl_pic_max_temperature,
                                    motor_status.motorl_bridge_min_temperature,
                                    motor_status.motorl_bridge_max_temperature,
                                    motor_status.motorl_bridge_min_current,
                                    motor_status.motorl_bridge_max_current
                                 );*/
                    
            }
                    
            break;
    }
    adc_state = next_state;
    
    
    
    if(adc_ctn > SLAVE_STATUS_MCU_HIGH_TEMP)
    {
        if(adc_ctn_high_temp == FALSE && motor_auto_scrolling == 0x00)
        {
            eeprom_ev_write3(EEPROM_EV_MSTR_MCU_HIGH_TEMP,
                             (u8)(adc_ctn>>8),
                             (u8)(adc_ctn & 0x00FF));
            adc_ctn_high_temp = TRUE;
        }
    }
    
    if(adc_ctn_high_temp == TRUE)
    {
        if(adc_ctn < SLAVE_STATUS_MCU_LOW_TEMP_THRESHOLD && motor_auto_scrolling == 0x00)
        {
            eeprom_ev_write3(EEPROM_EV_MSTR_MCU_TEMP_OK,
                             (u8)(adc_ctn>>8),
                             (u8)(adc_ctn & 0x00FF));
            adc_ctn_high_temp = FALSE;
        }
    }
    
    
    temporary_stop_process();
    
}





