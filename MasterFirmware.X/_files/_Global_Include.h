#ifndef _GLOBAL_INCLUDE_H
#define	_GLOBAL_INCLUDE_H

#define BOARD_RELEASE_D

#include <p33EV128GM004.h>

#include <math.h>

#include "_Typedefs.h"
#include "_Hardware_Profile_System.h"
#include "_Hardware_Profile_IO.h"
#include <libpic30.h>
#include "main.h"
#include "timer_1ms.h"
#include "timer_100ms.h"
#include "timer_pulses.h"
#include "com_packet.h"
#include "tools.h"
#include "uart_system.h" 
#include "uart_system_parameters.h" 
#include "uart_packet_system.h"
#include "uart_motor_common.h"
#include "uart_motor.h"
#include "uart_motor_protocole.h"
#include "errors.h"
#include "cellule.h"
#include "poster.h"
#include "force_keepalive.h"
#include "motor_struct_parameters.h"
#include "motor_common.h"




#include "motor.h"
#include "motor_manu.h"
#include "motor_init.h"
#include "motor_auto.h"
#include "synchro_ext.h"
#include "door_security.h"
#include "slave_status.h"
#include "adc.h"
#include "telecommande.h"
#include "flash.h"
#include "embedded_flash.h"
#include "tools.h"
#include "i2c.h"
#include "i2c_user.h"
#include "eeprom_events.h"
#include "eeprom_variables.h"
#include "temporary_stop.h"
#include "gsm.h"

#ifdef BOARD_RELEASE_D
//#include "flash2.h"
#endif





#endif

