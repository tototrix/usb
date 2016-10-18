#ifndef UARTS_PARAMETERS_H
#define	UARTS_PARAMETERS_H

#define UARTS_BAUDRATE                           57600
#define UARTS_BYTE_TIMEOUT                          10   // Temps max entre la reception de deux octets d'une même trame
#define UARTS_CONSTRUCT_TEMPO_TX                     2   // Temporisation en ms avant d'envoyer la reponse
#define UARTS_TREATMENT_TIMEOUT                     20   // Temps d'attente de traitement avant d'envoyer une reponse  
#define UARTS_BUS_FREE                             100   // Le bus doit être libre pendant 100ms avant qu'un maitre initie une communication.
#define UARTS_ANSWER_TIMEOUT                        60
#define UARTS_RETRY_MAX                             10


#define UARTS_TYPE_MODEM                           0x01  // Adresse du modem sur le bus
#define UARTS_TYPE_USB                             0x02  // Adresse des USB sur le bus
#define UARTS_TYPE_FAN_HEATER                      0x03  // Adresse de la carte chaufferette sur le bus
#define UARTS_TYPE_LIGHT                           0x04  // Adresse de la carte eclairage sur le bus
#define UARTS_TYPE_GPS                             0x05  // Adresse de la carte GPS sur le bus
#define UARTS_TYPE_TESTER                          0x06  // Adresse du banc de test sur le bus


//=======================================================================================================
//=======================================================================================================
//=======================================================================================================
//=======================================================================================================
// ORDER
//=======================================================================================================
//=======================================================================================================
//=======================================================================================================
//=======================================================================================================


//-------------------------------------------------------------------------------------------------------
// USB ORDER
//-------------------------------------------------------------------------------------------------------
// ORDRES BTLDR
#define UARTS_BTLD_ORDER_TO_USB_GET_SERIAL                   0x81  // 
#define UARTS_BTLD_ORDER_TO_USB_GET_M_FIRMWARE               0x83  // Ordre de recuperation de la version firmware du pic maitre
#define UARTS_BTLD_ORDER_TO_USB_ERASE_M_FIRMWARE             0x84  // Ordre d'effacement du firmware du pic maitre
#define UARTS_BTLD_ORDER_TO_USB_WRITE_M_FIRMWARE             0x85  // Ordre d'enregistrement d'une ligne de programme dans le pic maitre
#define UARTS_BTLD_ORDER_TO_USB_GET_S_FIRMWARE               0x86  // Ordre de recuperation de la version firmware des pics esclaves 
#define UARTS_BTLD_ORDER_TO_USB_ERASE_S_FIRMWARE             0x87  // Ordre d'effacement d'un pic esclave
#define UARTS_BTLD_ORDER_TO_USB_WRITE_S_FIRMWARE             0x88  // Ordre d'enregistrement d'une ligne de programme dans un pic esclave
#define UARTS_BTLD_ORDER_TO_USB_GET_SERIAL_AND_FIRMWARES     0x89  //  
// ORDRES FIRMWARE
#define UARTS_FIRMWARE_ORDER_TO_USB_GET_SERIAL_AND_FIRMWARES 0x20  // 
#define UARTS_FIRMWARE_ORDER_TO_USB_GET_STATUS               0x21  //
#define UARTS_FIRMWARE_ORDER_TO_USB_STOP_SCROLLING           0x22  //
#define UARTS_FIRMWARE_ORDER_TO_USB_GET_EVENT                0x23  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_MODE_ENTER          0x24  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_IO              0x25  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_SERIAL          0x26  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_SET_SERIAL          0x27  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_MEMORY              0x28  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_FIRMWARES       0x29  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_TEMP            0x2A  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_SUPPLY_VOLTAGE  0x2B  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_MOTOR_SENSORS   0x2C  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_MOTOR_SHUNT     0x2D  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_GET_PULSES          0x2E  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_FORCE_MOTOR_OUTPUT  0x2F  //
#define UARTS_FIRMWARE_ORDER_TO_USB_TEST_INIT_PULSES         0x30  //
















//-------------------------------------------------------------------------------------------------------
// MODEM ORDER
//-------------------------------------------------------------------------------------------------------
#define UARTS_FIRMWARE_ORDER_TO_MODEM_FORCE_KEEPALIVE        0xD0
#define UARTS_FIRMWARE_ORDER_TO_MODEM_TEST_MODE              0xD1
#define UARTS_FIRMWARE_ORDER_TO_MODEM_GET_IMEI_CCID          0xD2
#define UARTS_FIRMWARE_ORDER_TO_MODEM_GET_SUBSCRIBER         0xD3
#define UARTS_FIRMWARE_ORDER_TO_MODEM_GET_VOLTAGE            0xD4
#define UARTS_FIRMWARE_ORDER_TO_MODEM_TEST_FLASH             0xD5








#define UARTS_STATUS_BUSY                          0xFF  // Code de reponse du type "cible occupee"
#define UARTS_STATUS_BUSY_OTHER_SYSTEM             0xFE  // Code de reponse du type "cible occupee avec un autre systeme"
#define UARTS_STATUS_ERROR                         0xFD  // Code de reponse du type "erreur"

#define UARTS_TREATMENT_WAIT_MASTER                1000  // Temps maximum d'attente pour que l'expediteur vienne chercher la reponse.

#endif