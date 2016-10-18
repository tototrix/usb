/* 
 * File:   adc.h
 * Author: Christophe
 *
 * Created on 18 août 2015, 13:47
 */

#ifndef ADC_H
#define	ADC_H

#define ADC_TIMER_VALUE              250    // 1000ms
#define ADC_TIMER_VALUE_MANUAL         1    // 10ms
#define ADC_SAMPLES                    8 // 8 echantillons sont utilises pour faire la moyenne 
#define ADC_STORE_CYCLE_COUNT        120 // 120 * 1000ms = 120 secondes

#define ADC_LOW_BATT_2M2           2250
#define ADC_LOW_BATT_8M2           2050


#define ADC_BATT_OK_THRESHOLD      2500
#define ADC_LOW_BATT_FILTER         200




#ifdef BOARD_RELEASE_D
// Tableau de definition pour la CTN 10K NCP21XV103J03RA
/*#define CTN_PCB_0   3975
#define CTN_PCB_1   3967
#define CTN_PCB_2   3959
#define CTN_PCB_3   3950
#define CTN_PCB_4   3940
#define CTN_PCB_5   3930
#define CTN_PCB_6   3920
#define CTN_PCB_7   3909
#define CTN_PCB_8   3897
#define CTN_PCB_9   3885
#define CTN_PCB_10   3872
#define CTN_PCB_11   3859
#define CTN_PCB_12   3845
#define CTN_PCB_13   3830
#define CTN_PCB_14   3815
#define CTN_PCB_15   3799
#define CTN_PCB_16   3782
#define CTN_PCB_17   3764
#define CTN_PCB_18   3746
#define CTN_PCB_19   3727
#define CTN_PCB_20   3707
#define CTN_PCB_21   3686
#define CTN_PCB_22   3665
#define CTN_PCB_23   3642
#define CTN_PCB_24   3619
#define CTN_PCB_25   3595
#define CTN_PCB_26   3570
#define CTN_PCB_27   3544
#define CTN_PCB_28   3518
#define CTN_PCB_29   3490
#define CTN_PCB_30   3462
#define CTN_PCB_31   3432
#define CTN_PCB_32   3402
#define CTN_PCB_33   3371
#define CTN_PCB_34   3338
#define CTN_PCB_35   3305
#define CTN_PCB_36   3272
#define CTN_PCB_37   3237
#define CTN_PCB_38   3202
#define CTN_PCB_39   3165
#define CTN_PCB_40   3128
#define CTN_PCB_41   3091
#define CTN_PCB_42   3052
#define CTN_PCB_43   3013
#define CTN_PCB_44   2973
#define CTN_PCB_45   2932
#define CTN_PCB_46   2891
#define CTN_PCB_47   2849
#define CTN_PCB_48   2807
#define CTN_PCB_49   2764
#define CTN_PCB_50   2721
#define CTN_PCB_51   2677
#define CTN_PCB_52   2633
#define CTN_PCB_53   2589
#define CTN_PCB_54   2544
#define CTN_PCB_55   2499
#define CTN_PCB_56   2454
#define CTN_PCB_57   2409
#define CTN_PCB_58   2364
#define CTN_PCB_59   2318
#define CTN_PCB_60   2273
#define CTN_PCB_61   2228
#define CTN_PCB_62   2183
#define CTN_PCB_63   2137
#define CTN_PCB_64   2093
#define CTN_PCB_65   2048
#define CTN_PCB_66   2004
#define CTN_PCB_67   1960
#define CTN_PCB_68   1916
#define CTN_PCB_69   1872
#define CTN_PCB_70   1830
#define CTN_PCB_71   1787
#define CTN_PCB_72   1745
#define CTN_PCB_73   1703
#define CTN_PCB_74   1662
#define CTN_PCB_75   1622
#define CTN_PCB_76   1582
#define CTN_PCB_77   1543
#define CTN_PCB_78   1504
#define CTN_PCB_79   1466
#define CTN_PCB_80   1429
#define CTN_PCB_81   1392
#define CTN_PCB_82   1356
#define CTN_PCB_83   1320
#define CTN_PCB_84   1286
#define CTN_PCB_85   1252
#define CTN_PCB_86   1218
#define CTN_PCB_87   1186
#define CTN_PCB_88   1154
#define CTN_PCB_89   1123
#define CTN_PCB_90   1092
#define CTN_PCB_91   1062
#define CTN_PCB_92   1033
#define CTN_PCB_93   1005
#define CTN_PCB_94   977
#define CTN_PCB_95   950
#define CTN_PCB_96   923
#define CTN_PCB_97   898
#define CTN_PCB_98   873
#define CTN_PCB_99   848
#define CTN_PCB_100   825
#define CTN_PCB_101   801
#define CTN_PCB_102   779
#define CTN_PCB_103   757
#define CTN_PCB_104   736
#define CTN_PCB_105   715
#define CTN_PCB_106   695
#define CTN_PCB_107   675
#define CTN_PCB_108   656
#define CTN_PCB_109   637
#define CTN_PCB_110   619
#define CTN_PCB_111   602
#define CTN_PCB_112   585
#define CTN_PCB_113   568
#define CTN_PCB_114   553
#define CTN_PCB_115   537
#define CTN_PCB_116   522
#define CTN_PCB_117   507
#define CTN_PCB_118   493
#define CTN_PCB_119   479
#define CTN_PCB_120   466
#define CTN_PCB_121   453
#define CTN_PCB_122   440
#define CTN_PCB_123   428
#define CTN_PCB_124   416
#define CTN_PCB_125   405
#define CTN_PCB_126   394
#define CTN_PCB_127   383
#define CTN_PCB_128   372
#define CTN_PCB_129   362
#define CTN_PCB_130   352
#define CTN_PCB_131   343
#define CTN_PCB_132   333
#define CTN_PCB_133   324
#define CTN_PCB_134   315
#define CTN_PCB_135   307
#define CTN_PCB_136   299
#define CTN_PCB_137   291
#define CTN_PCB_138   283
#define CTN_PCB_139   275
#define CTN_PCB_140   268
#define CTN_PCB_141   261
#define CTN_PCB_142   254
#define CTN_PCB_143   247
#define CTN_PCB_144   241
#define CTN_PCB_145   235
#define CTN_PCB_146   229
#define CTN_PCB_147   223
#define CTN_PCB_148   217
#define CTN_PCB_149   211
#define CTN_PCB_150   206
#define CTN_PCB_151   201
#define CTN_PCB_152   196
#define CTN_PCB_153   191
#define CTN_PCB_154   186
#define CTN_PCB_155   181
#define CTN_PCB_156   177
#define CTN_PCB_157   172
#define CTN_PCB_158   168
#define CTN_PCB_159   164
#define CTN_PCB_160   160
#define CTN_PCB_161   156
#define CTN_PCB_162   152
#define CTN_PCB_163   149
#define CTN_PCB_164   145
#define CTN_PCB_165   141*/

#define CTN_PCB_0 3975
#define CTN_PCB_1 3968
#define CTN_PCB_2 3961
#define CTN_PCB_3 3952
#define CTN_PCB_4 3942
#define CTN_PCB_5 3930
#define CTN_PCB_6 3921
#define CTN_PCB_7 3911
#define CTN_PCB_8 3900
#define CTN_PCB_9 3887
#define CTN_PCB_10 3872
#define CTN_PCB_11 3861
#define CTN_PCB_12 3848
#define CTN_PCB_13 3833
#define CTN_PCB_14 3817
#define CTN_PCB_15 3799
#define CTN_PCB_16 3784
#define CTN_PCB_17 3768
#define CTN_PCB_18 3750
#define CTN_PCB_19 3730
#define CTN_PCB_20 3707
#define CTN_PCB_21 3689
#define CTN_PCB_22 3669
#define CTN_PCB_23 3647
#define CTN_PCB_24 3622
#define CTN_PCB_25 3595
#define CTN_PCB_26 3573
#define CTN_PCB_27 3549
#define CTN_PCB_28 3523
#define CTN_PCB_29 3494
#define CTN_PCB_30 3462
#define CTN_PCB_31 3436
#define CTN_PCB_32 3407
#define CTN_PCB_33 3376
#define CTN_PCB_34 3343
#define CTN_PCB_35 3305
#define CTN_PCB_36 3275
#define CTN_PCB_37 3243
#define CTN_PCB_38 3208
#define CTN_PCB_39 3170
#define CTN_PCB_40 3128
#define CTN_PCB_41 3095
#define CTN_PCB_42 3058
#define CTN_PCB_43 3019
#define CTN_PCB_44 2978
#define CTN_PCB_45 2932
#define CTN_PCB_46 2895
#define CTN_PCB_47 2856
#define CTN_PCB_48 2814
#define CTN_PCB_49 2769
#define CTN_PCB_50 2721
#define CTN_PCB_51 2682
#define CTN_PCB_52 2640
#define CTN_PCB_53 2596
#define CTN_PCB_54 2549
#define CTN_PCB_55 2499
#define CTN_PCB_56 2459
#define CTN_PCB_57 2416
#define CTN_PCB_58 2371
#define CTN_PCB_59 2323
#define CTN_PCB_60 2273
#define CTN_PCB_61 2232
#define CTN_PCB_62 2189
#define CTN_PCB_63 2144
#define CTN_PCB_64 2097
#define CTN_PCB_65 2048
#define CTN_PCB_66 2008
#define CTN_PCB_67 1966
#define CTN_PCB_68 1922
#define CTN_PCB_69 1877
#define CTN_PCB_70 1830
#define CTN_PCB_71 1791
#define CTN_PCB_72 1751
#define CTN_PCB_73 1709
#define CTN_PCB_74 1666
#define CTN_PCB_75 1622
#define CTN_PCB_76 1586
#define CTN_PCB_77 1548
#define CTN_PCB_78 1509
#define CTN_PCB_79 1470
#define CTN_PCB_80 1429
#define CTN_PCB_81 1395
#define CTN_PCB_82 1361
#define CTN_PCB_83 1325
#define CTN_PCB_84 1289
#define CTN_PCB_85 1252
#define CTN_PCB_86 1221
#define CTN_PCB_87 1190
#define CTN_PCB_88 1158
#define CTN_PCB_89 1125
#define CTN_PCB_90 1092
#define CTN_PCB_91 1065
#define CTN_PCB_92 1037
#define CTN_PCB_93 1008
#define CTN_PCB_94 979
#define CTN_PCB_95 950
#define CTN_PCB_96 926
#define CTN_PCB_97 901
#define CTN_PCB_98 876
#define CTN_PCB_99 851
#define CTN_PCB_100 825
#define CTN_PCB_101 803
#define CTN_PCB_102 782
#define CTN_PCB_103 760
#define CTN_PCB_104 738
#define CTN_PCB_105 715
#define CTN_PCB_106 696
#define CTN_PCB_107 677
#define CTN_PCB_108 658
#define CTN_PCB_109 639
#define CTN_PCB_110 619
#define CTN_PCB_111 603
#define CTN_PCB_112 587
#define CTN_PCB_113 570
#define CTN_PCB_114 554
#define CTN_PCB_115 537
#define CTN_PCB_116 523
#define CTN_PCB_117 509
#define CTN_PCB_118 495
#define CTN_PCB_119 480
#define CTN_PCB_120 466
#define CTN_PCB_121 454
#define CTN_PCB_122 442
#define CTN_PCB_123 430
#define CTN_PCB_124 417
#define CTN_PCB_125 405
#define CTN_PCB_126 395
#define CTN_PCB_127 384
#define CTN_PCB_128 374
#define CTN_PCB_129 363
#define CTN_PCB_130 352
#define CTN_PCB_131 343
#define CTN_PCB_132 334
#define CTN_PCB_133 325
#define CTN_PCB_134 316
#define CTN_PCB_135 307
#define CTN_PCB_136 299
#define CTN_PCB_137 292
#define CTN_PCB_138 284
#define CTN_PCB_139 276
#define CTN_PCB_140 268
#define CTN_PCB_141 262
#define CTN_PCB_142 255
#define CTN_PCB_143 248
#define CTN_PCB_144 242
#define CTN_PCB_145 235
#define CTN_PCB_146 229
#define CTN_PCB_147 223
#define CTN_PCB_148 218
#define CTN_PCB_149 212
#define CTN_PCB_150 206
#define CTN_PCB_151 201
#define CTN_PCB_152 196
#define CTN_PCB_153 191
#define CTN_PCB_154 186
#define CTN_PCB_155 181
#define CTN_PCB_156 177
#define CTN_PCB_157 173
#define CTN_PCB_158 168
#define CTN_PCB_159 164
#define CTN_PCB_160 160
#define CTN_PCB_161 156
#define CTN_PCB_162 153
#define CTN_PCB_163 149
#define CTN_PCB_164 145
#define CTN_PCB_165 142




#endif

#define ADC_24V_OVERVOLTAGE_REG_VALUE 3500//3500//4020
#define ADC_24V_OVERVOLTAGE_AR_VALUE     5



extern bool adc_ctn_high_temp;

extern i16 ctn_temperature;
extern i16 ctn_min_temperature;
extern i16 ctn_max_temperature;
extern u16 adc_vbat;

#ifdef BOARD_RELEASE_D
extern i16 adc_ctn;
#endif

extern bool adc_low_battery;
extern bool adc_24v_overvoltage;

void adc_init(void);
void adc_sm(void);

#endif	/* ADC_H */

