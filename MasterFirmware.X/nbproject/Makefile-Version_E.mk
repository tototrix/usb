#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Version_E.mk)" "nbproject/Makefile-local-Version_E.mk"
include nbproject/Makefile-local-Version_E.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Version_E
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=_files/adc/adc.c _files/cellule/cellule.c _files/com_packet/com_packet.c _files/door/door_security.c _files/eeprom/eeprom_events.c _files/eeprom/eeprom_variables.c _files/embedded_flash/embedded_flash.c _files/errors/errors.c _files/flash/flash.c _files/force_keepalive/force_keepalive.c _files/gsm/gsm.c _files/i2c/i2c.c _files/i2c/i2c_user.c _files/motor/motor.c _files/motor/motor_auto.c _files/motor/motor_init.c _files/motor/motor_manu.c _files/poster/poster.c _files/slave_status/slave_status.c _files/synchro_ext/synchro_ext.c _files/telecommand/telecommande.c _files/temporary_stop/temporary_stop.c _files/timers/timer_100ms.c _files/timers/timer_1ms.c _files/timers/timer_pulses.c _files/tools/tools.c _files/uart_motor/uart_motor.c _files/uart_motor/uart_motor_protocole.c _files/uart_system/uart_system.c _files/uart_system/uart_packet_system.c _files/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_files/adc/adc.o ${OBJECTDIR}/_files/cellule/cellule.o ${OBJECTDIR}/_files/com_packet/com_packet.o ${OBJECTDIR}/_files/door/door_security.o ${OBJECTDIR}/_files/eeprom/eeprom_events.o ${OBJECTDIR}/_files/eeprom/eeprom_variables.o ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o ${OBJECTDIR}/_files/errors/errors.o ${OBJECTDIR}/_files/flash/flash.o ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o ${OBJECTDIR}/_files/gsm/gsm.o ${OBJECTDIR}/_files/i2c/i2c.o ${OBJECTDIR}/_files/i2c/i2c_user.o ${OBJECTDIR}/_files/motor/motor.o ${OBJECTDIR}/_files/motor/motor_auto.o ${OBJECTDIR}/_files/motor/motor_init.o ${OBJECTDIR}/_files/motor/motor_manu.o ${OBJECTDIR}/_files/poster/poster.o ${OBJECTDIR}/_files/slave_status/slave_status.o ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o ${OBJECTDIR}/_files/telecommand/telecommande.o ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o ${OBJECTDIR}/_files/timers/timer_100ms.o ${OBJECTDIR}/_files/timers/timer_1ms.o ${OBJECTDIR}/_files/timers/timer_pulses.o ${OBJECTDIR}/_files/tools/tools.o ${OBJECTDIR}/_files/uart_motor/uart_motor.o ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o ${OBJECTDIR}/_files/uart_system/uart_system.o ${OBJECTDIR}/_files/uart_system/uart_packet_system.o ${OBJECTDIR}/_files/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_files/adc/adc.o.d ${OBJECTDIR}/_files/cellule/cellule.o.d ${OBJECTDIR}/_files/com_packet/com_packet.o.d ${OBJECTDIR}/_files/door/door_security.o.d ${OBJECTDIR}/_files/eeprom/eeprom_events.o.d ${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d ${OBJECTDIR}/_files/errors/errors.o.d ${OBJECTDIR}/_files/flash/flash.o.d ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d ${OBJECTDIR}/_files/gsm/gsm.o.d ${OBJECTDIR}/_files/i2c/i2c.o.d ${OBJECTDIR}/_files/i2c/i2c_user.o.d ${OBJECTDIR}/_files/motor/motor.o.d ${OBJECTDIR}/_files/motor/motor_auto.o.d ${OBJECTDIR}/_files/motor/motor_init.o.d ${OBJECTDIR}/_files/motor/motor_manu.o.d ${OBJECTDIR}/_files/poster/poster.o.d ${OBJECTDIR}/_files/slave_status/slave_status.o.d ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d ${OBJECTDIR}/_files/telecommand/telecommande.o.d ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d ${OBJECTDIR}/_files/timers/timer_100ms.o.d ${OBJECTDIR}/_files/timers/timer_1ms.o.d ${OBJECTDIR}/_files/timers/timer_pulses.o.d ${OBJECTDIR}/_files/tools/tools.o.d ${OBJECTDIR}/_files/uart_motor/uart_motor.o.d ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d ${OBJECTDIR}/_files/uart_system/uart_system.o.d ${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d ${OBJECTDIR}/_files/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_files/adc/adc.o ${OBJECTDIR}/_files/cellule/cellule.o ${OBJECTDIR}/_files/com_packet/com_packet.o ${OBJECTDIR}/_files/door/door_security.o ${OBJECTDIR}/_files/eeprom/eeprom_events.o ${OBJECTDIR}/_files/eeprom/eeprom_variables.o ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o ${OBJECTDIR}/_files/errors/errors.o ${OBJECTDIR}/_files/flash/flash.o ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o ${OBJECTDIR}/_files/gsm/gsm.o ${OBJECTDIR}/_files/i2c/i2c.o ${OBJECTDIR}/_files/i2c/i2c_user.o ${OBJECTDIR}/_files/motor/motor.o ${OBJECTDIR}/_files/motor/motor_auto.o ${OBJECTDIR}/_files/motor/motor_init.o ${OBJECTDIR}/_files/motor/motor_manu.o ${OBJECTDIR}/_files/poster/poster.o ${OBJECTDIR}/_files/slave_status/slave_status.o ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o ${OBJECTDIR}/_files/telecommand/telecommande.o ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o ${OBJECTDIR}/_files/timers/timer_100ms.o ${OBJECTDIR}/_files/timers/timer_1ms.o ${OBJECTDIR}/_files/timers/timer_pulses.o ${OBJECTDIR}/_files/tools/tools.o ${OBJECTDIR}/_files/uart_motor/uart_motor.o ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o ${OBJECTDIR}/_files/uart_system/uart_system.o ${OBJECTDIR}/_files/uart_system/uart_packet_system.o ${OBJECTDIR}/_files/main.o

# Source Files
SOURCEFILES=_files/adc/adc.c _files/cellule/cellule.c _files/com_packet/com_packet.c _files/door/door_security.c _files/eeprom/eeprom_events.c _files/eeprom/eeprom_variables.c _files/embedded_flash/embedded_flash.c _files/errors/errors.c _files/flash/flash.c _files/force_keepalive/force_keepalive.c _files/gsm/gsm.c _files/i2c/i2c.c _files/i2c/i2c_user.c _files/motor/motor.c _files/motor/motor_auto.c _files/motor/motor_init.c _files/motor/motor_manu.c _files/poster/poster.c _files/slave_status/slave_status.c _files/synchro_ext/synchro_ext.c _files/telecommand/telecommande.c _files/temporary_stop/temporary_stop.c _files/timers/timer_100ms.c _files/timers/timer_1ms.c _files/timers/timer_pulses.c _files/tools/tools.c _files/uart_motor/uart_motor.c _files/uart_motor/uart_motor_protocole.c _files/uart_system/uart_system.c _files/uart_system/uart_packet_system.c _files/main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Version_E.mk dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EV128GM004
MP_LINKER_FILE_OPTION=,--script=linker/p33EV128GM004.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_files/adc/adc.o: _files/adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/adc" 
	@${RM} ${OBJECTDIR}/_files/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/_files/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/adc/adc.c  -o ${OBJECTDIR}/_files/adc/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/adc/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/adc/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/cellule/cellule.o: _files/cellule/cellule.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/cellule" 
	@${RM} ${OBJECTDIR}/_files/cellule/cellule.o.d 
	@${RM} ${OBJECTDIR}/_files/cellule/cellule.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/cellule/cellule.c  -o ${OBJECTDIR}/_files/cellule/cellule.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/cellule/cellule.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/cellule/cellule.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/com_packet/com_packet.o: _files/com_packet/com_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/com_packet" 
	@${RM} ${OBJECTDIR}/_files/com_packet/com_packet.o.d 
	@${RM} ${OBJECTDIR}/_files/com_packet/com_packet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/com_packet/com_packet.c  -o ${OBJECTDIR}/_files/com_packet/com_packet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/com_packet/com_packet.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/com_packet/com_packet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/door/door_security.o: _files/door/door_security.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/door" 
	@${RM} ${OBJECTDIR}/_files/door/door_security.o.d 
	@${RM} ${OBJECTDIR}/_files/door/door_security.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/door/door_security.c  -o ${OBJECTDIR}/_files/door/door_security.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/door/door_security.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/door/door_security.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/eeprom/eeprom_events.o: _files/eeprom/eeprom_events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/eeprom" 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_events.o.d 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/eeprom/eeprom_events.c  -o ${OBJECTDIR}/_files/eeprom/eeprom_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/eeprom/eeprom_events.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/eeprom/eeprom_events.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/eeprom/eeprom_variables.o: _files/eeprom/eeprom_variables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/eeprom" 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_variables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/eeprom/eeprom_variables.c  -o ${OBJECTDIR}/_files/eeprom/eeprom_variables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/embedded_flash/embedded_flash.o: _files/embedded_flash/embedded_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/embedded_flash" 
	@${RM} ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d 
	@${RM} ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/embedded_flash/embedded_flash.c  -o ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/errors/errors.o: _files/errors/errors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/errors" 
	@${RM} ${OBJECTDIR}/_files/errors/errors.o.d 
	@${RM} ${OBJECTDIR}/_files/errors/errors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/errors/errors.c  -o ${OBJECTDIR}/_files/errors/errors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/errors/errors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/errors/errors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/flash/flash.o: _files/flash/flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/flash" 
	@${RM} ${OBJECTDIR}/_files/flash/flash.o.d 
	@${RM} ${OBJECTDIR}/_files/flash/flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/flash/flash.c  -o ${OBJECTDIR}/_files/flash/flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/flash/flash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/flash/flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/force_keepalive/force_keepalive.o: _files/force_keepalive/force_keepalive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/force_keepalive" 
	@${RM} ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d 
	@${RM} ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/force_keepalive/force_keepalive.c  -o ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/gsm/gsm.o: _files/gsm/gsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/gsm" 
	@${RM} ${OBJECTDIR}/_files/gsm/gsm.o.d 
	@${RM} ${OBJECTDIR}/_files/gsm/gsm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/gsm/gsm.c  -o ${OBJECTDIR}/_files/gsm/gsm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/gsm/gsm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/gsm/gsm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/i2c/i2c.o: _files/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/i2c" 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c.o.d 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/i2c/i2c.c  -o ${OBJECTDIR}/_files/i2c/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/i2c/i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/i2c/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/i2c/i2c_user.o: _files/i2c/i2c_user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/i2c" 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c_user.o.d 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c_user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/i2c/i2c_user.c  -o ${OBJECTDIR}/_files/i2c/i2c_user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/i2c/i2c_user.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/i2c/i2c_user.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor.o: _files/motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor.c  -o ${OBJECTDIR}/_files/motor/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_auto.o: _files/motor/motor_auto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_auto.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_auto.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_auto.c  -o ${OBJECTDIR}/_files/motor/motor_auto.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_auto.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_auto.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_init.o: _files/motor/motor_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_init.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_init.c  -o ${OBJECTDIR}/_files/motor/motor_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_manu.o: _files/motor/motor_manu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_manu.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_manu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_manu.c  -o ${OBJECTDIR}/_files/motor/motor_manu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_manu.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_manu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/poster/poster.o: _files/poster/poster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/poster" 
	@${RM} ${OBJECTDIR}/_files/poster/poster.o.d 
	@${RM} ${OBJECTDIR}/_files/poster/poster.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/poster/poster.c  -o ${OBJECTDIR}/_files/poster/poster.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/poster/poster.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/poster/poster.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/slave_status/slave_status.o: _files/slave_status/slave_status.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/slave_status" 
	@${RM} ${OBJECTDIR}/_files/slave_status/slave_status.o.d 
	@${RM} ${OBJECTDIR}/_files/slave_status/slave_status.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/slave_status/slave_status.c  -o ${OBJECTDIR}/_files/slave_status/slave_status.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/slave_status/slave_status.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/slave_status/slave_status.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/synchro_ext/synchro_ext.o: _files/synchro_ext/synchro_ext.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/synchro_ext" 
	@${RM} ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d 
	@${RM} ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/synchro_ext/synchro_ext.c  -o ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/telecommand/telecommande.o: _files/telecommand/telecommande.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/telecommand" 
	@${RM} ${OBJECTDIR}/_files/telecommand/telecommande.o.d 
	@${RM} ${OBJECTDIR}/_files/telecommand/telecommande.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/telecommand/telecommande.c  -o ${OBJECTDIR}/_files/telecommand/telecommande.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/telecommand/telecommande.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/telecommand/telecommande.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/temporary_stop/temporary_stop.o: _files/temporary_stop/temporary_stop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/temporary_stop" 
	@${RM} ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d 
	@${RM} ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/temporary_stop/temporary_stop.c  -o ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_100ms.o: _files/timers/timer_100ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_100ms.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_100ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_100ms.c  -o ${OBJECTDIR}/_files/timers/timer_100ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_100ms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_100ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_1ms.o: _files/timers/timer_1ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_1ms.c  -o ${OBJECTDIR}/_files/timers/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_1ms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_1ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_pulses.o: _files/timers/timer_pulses.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_pulses.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_pulses.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_pulses.c  -o ${OBJECTDIR}/_files/timers/timer_pulses.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_pulses.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_pulses.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/tools/tools.o: _files/tools/tools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/tools" 
	@${RM} ${OBJECTDIR}/_files/tools/tools.o.d 
	@${RM} ${OBJECTDIR}/_files/tools/tools.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/tools/tools.c  -o ${OBJECTDIR}/_files/tools/tools.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/tools/tools.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/tools/tools.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_motor/uart_motor.o: _files/uart_motor/uart_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_motor" 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_motor/uart_motor.c  -o ${OBJECTDIR}/_files/uart_motor/uart_motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_motor/uart_motor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_motor/uart_motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o: _files/uart_motor/uart_motor_protocole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_motor" 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_motor/uart_motor_protocole.c  -o ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_system/uart_system.o: _files/uart_system/uart_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_system" 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_system.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_system/uart_system.c  -o ${OBJECTDIR}/_files/uart_system/uart_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_system/uart_system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_system/uart_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_system/uart_packet_system.o: _files/uart_system/uart_packet_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_system" 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_packet_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_system/uart_packet_system.c  -o ${OBJECTDIR}/_files/uart_system/uart_packet_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/main.o: _files/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files" 
	@${RM} ${OBJECTDIR}/_files/main.o.d 
	@${RM} ${OBJECTDIR}/_files/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/main.c  -o ${OBJECTDIR}/_files/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_files/adc/adc.o: _files/adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/adc" 
	@${RM} ${OBJECTDIR}/_files/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/_files/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/adc/adc.c  -o ${OBJECTDIR}/_files/adc/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/adc/adc.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/adc/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/cellule/cellule.o: _files/cellule/cellule.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/cellule" 
	@${RM} ${OBJECTDIR}/_files/cellule/cellule.o.d 
	@${RM} ${OBJECTDIR}/_files/cellule/cellule.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/cellule/cellule.c  -o ${OBJECTDIR}/_files/cellule/cellule.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/cellule/cellule.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/cellule/cellule.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/com_packet/com_packet.o: _files/com_packet/com_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/com_packet" 
	@${RM} ${OBJECTDIR}/_files/com_packet/com_packet.o.d 
	@${RM} ${OBJECTDIR}/_files/com_packet/com_packet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/com_packet/com_packet.c  -o ${OBJECTDIR}/_files/com_packet/com_packet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/com_packet/com_packet.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/com_packet/com_packet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/door/door_security.o: _files/door/door_security.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/door" 
	@${RM} ${OBJECTDIR}/_files/door/door_security.o.d 
	@${RM} ${OBJECTDIR}/_files/door/door_security.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/door/door_security.c  -o ${OBJECTDIR}/_files/door/door_security.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/door/door_security.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/door/door_security.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/eeprom/eeprom_events.o: _files/eeprom/eeprom_events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/eeprom" 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_events.o.d 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/eeprom/eeprom_events.c  -o ${OBJECTDIR}/_files/eeprom/eeprom_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/eeprom/eeprom_events.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/eeprom/eeprom_events.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/eeprom/eeprom_variables.o: _files/eeprom/eeprom_variables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/eeprom" 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d 
	@${RM} ${OBJECTDIR}/_files/eeprom/eeprom_variables.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/eeprom/eeprom_variables.c  -o ${OBJECTDIR}/_files/eeprom/eeprom_variables.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/eeprom/eeprom_variables.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/embedded_flash/embedded_flash.o: _files/embedded_flash/embedded_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/embedded_flash" 
	@${RM} ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d 
	@${RM} ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/embedded_flash/embedded_flash.c  -o ${OBJECTDIR}/_files/embedded_flash/embedded_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/embedded_flash/embedded_flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/errors/errors.o: _files/errors/errors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/errors" 
	@${RM} ${OBJECTDIR}/_files/errors/errors.o.d 
	@${RM} ${OBJECTDIR}/_files/errors/errors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/errors/errors.c  -o ${OBJECTDIR}/_files/errors/errors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/errors/errors.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/errors/errors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/flash/flash.o: _files/flash/flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/flash" 
	@${RM} ${OBJECTDIR}/_files/flash/flash.o.d 
	@${RM} ${OBJECTDIR}/_files/flash/flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/flash/flash.c  -o ${OBJECTDIR}/_files/flash/flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/flash/flash.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/flash/flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/force_keepalive/force_keepalive.o: _files/force_keepalive/force_keepalive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/force_keepalive" 
	@${RM} ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d 
	@${RM} ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/force_keepalive/force_keepalive.c  -o ${OBJECTDIR}/_files/force_keepalive/force_keepalive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/force_keepalive/force_keepalive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/gsm/gsm.o: _files/gsm/gsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/gsm" 
	@${RM} ${OBJECTDIR}/_files/gsm/gsm.o.d 
	@${RM} ${OBJECTDIR}/_files/gsm/gsm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/gsm/gsm.c  -o ${OBJECTDIR}/_files/gsm/gsm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/gsm/gsm.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/gsm/gsm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/i2c/i2c.o: _files/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/i2c" 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c.o.d 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/i2c/i2c.c  -o ${OBJECTDIR}/_files/i2c/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/i2c/i2c.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/i2c/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/i2c/i2c_user.o: _files/i2c/i2c_user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/i2c" 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c_user.o.d 
	@${RM} ${OBJECTDIR}/_files/i2c/i2c_user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/i2c/i2c_user.c  -o ${OBJECTDIR}/_files/i2c/i2c_user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/i2c/i2c_user.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/i2c/i2c_user.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor.o: _files/motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor.c  -o ${OBJECTDIR}/_files/motor/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_auto.o: _files/motor/motor_auto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_auto.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_auto.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_auto.c  -o ${OBJECTDIR}/_files/motor/motor_auto.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_auto.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_auto.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_init.o: _files/motor/motor_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_init.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_init.c  -o ${OBJECTDIR}/_files/motor/motor_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_init.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/motor/motor_manu.o: _files/motor/motor_manu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/motor" 
	@${RM} ${OBJECTDIR}/_files/motor/motor_manu.o.d 
	@${RM} ${OBJECTDIR}/_files/motor/motor_manu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/motor/motor_manu.c  -o ${OBJECTDIR}/_files/motor/motor_manu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/motor/motor_manu.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/motor/motor_manu.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/poster/poster.o: _files/poster/poster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/poster" 
	@${RM} ${OBJECTDIR}/_files/poster/poster.o.d 
	@${RM} ${OBJECTDIR}/_files/poster/poster.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/poster/poster.c  -o ${OBJECTDIR}/_files/poster/poster.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/poster/poster.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/poster/poster.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/slave_status/slave_status.o: _files/slave_status/slave_status.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/slave_status" 
	@${RM} ${OBJECTDIR}/_files/slave_status/slave_status.o.d 
	@${RM} ${OBJECTDIR}/_files/slave_status/slave_status.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/slave_status/slave_status.c  -o ${OBJECTDIR}/_files/slave_status/slave_status.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/slave_status/slave_status.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/slave_status/slave_status.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/synchro_ext/synchro_ext.o: _files/synchro_ext/synchro_ext.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/synchro_ext" 
	@${RM} ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d 
	@${RM} ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/synchro_ext/synchro_ext.c  -o ${OBJECTDIR}/_files/synchro_ext/synchro_ext.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/synchro_ext/synchro_ext.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/telecommand/telecommande.o: _files/telecommand/telecommande.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/telecommand" 
	@${RM} ${OBJECTDIR}/_files/telecommand/telecommande.o.d 
	@${RM} ${OBJECTDIR}/_files/telecommand/telecommande.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/telecommand/telecommande.c  -o ${OBJECTDIR}/_files/telecommand/telecommande.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/telecommand/telecommande.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/telecommand/telecommande.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/temporary_stop/temporary_stop.o: _files/temporary_stop/temporary_stop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/temporary_stop" 
	@${RM} ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d 
	@${RM} ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/temporary_stop/temporary_stop.c  -o ${OBJECTDIR}/_files/temporary_stop/temporary_stop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/temporary_stop/temporary_stop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_100ms.o: _files/timers/timer_100ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_100ms.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_100ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_100ms.c  -o ${OBJECTDIR}/_files/timers/timer_100ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_100ms.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_100ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_1ms.o: _files/timers/timer_1ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_1ms.c  -o ${OBJECTDIR}/_files/timers/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_1ms.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_1ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/timers/timer_pulses.o: _files/timers/timer_pulses.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/timers" 
	@${RM} ${OBJECTDIR}/_files/timers/timer_pulses.o.d 
	@${RM} ${OBJECTDIR}/_files/timers/timer_pulses.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/timers/timer_pulses.c  -o ${OBJECTDIR}/_files/timers/timer_pulses.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/timers/timer_pulses.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/timers/timer_pulses.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/tools/tools.o: _files/tools/tools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/tools" 
	@${RM} ${OBJECTDIR}/_files/tools/tools.o.d 
	@${RM} ${OBJECTDIR}/_files/tools/tools.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/tools/tools.c  -o ${OBJECTDIR}/_files/tools/tools.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/tools/tools.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/tools/tools.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_motor/uart_motor.o: _files/uart_motor/uart_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_motor" 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_motor/uart_motor.c  -o ${OBJECTDIR}/_files/uart_motor/uart_motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_motor/uart_motor.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_motor/uart_motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o: _files/uart_motor/uart_motor_protocole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_motor" 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_motor/uart_motor_protocole.c  -o ${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_motor/uart_motor_protocole.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_system/uart_system.o: _files/uart_system/uart_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_system" 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_system.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_system/uart_system.c  -o ${OBJECTDIR}/_files/uart_system/uart_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_system/uart_system.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_system/uart_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/uart_system/uart_packet_system.o: _files/uart_system/uart_packet_system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files/uart_system" 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d 
	@${RM} ${OBJECTDIR}/_files/uart_system/uart_packet_system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/uart_system/uart_packet_system.c  -o ${OBJECTDIR}/_files/uart_system/uart_packet_system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/uart_system/uart_packet_system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_files/main.o: _files/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_files" 
	@${RM} ${OBJECTDIR}/_files/main.o.d 
	@${RM} ${OBJECTDIR}/_files/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  _files/main.c  -o ${OBJECTDIR}/_files/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_files/main.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -mlarge-data -O0 -I"../../common" -I"../../common/com_packet" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_files/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    linker/p33EV128GM004.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive"  -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   linker/p33EV128GM004.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -I"_files" -I"_files/adc" -I"_files/cellule" -I"_files/com_packet" -I"_files/door" -I"_files/errors" -I"_files/flash" -I"_files/motor" -I"_files/motor_parameters" -I"_files/poster" -I"_files/slave_status" -I"_files/slave_status" -I"_files/synchro_ext" -I"_files/telecommand" -I"_files/timers" -I"_files/uart_motor" -I"_files/i2c" -I"_files/tools" -I"_files/temporary_stop" -I"_files/eeprom" -I"_files/motor" -I"_files/embedded_flash" -I"_files/uart_system" -I"_files/gsm" -I"_files/force_keepalive" -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
	@echo Normalizing hex file
	@"C:/Program Files (x86)/Microchip/MPLABX/v3.30/mplab_ide/mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files (x86)/Microchip/MPLABX/v3.30/mplab_ide/mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/R041_MasterFirmware.X.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Version_E
	${RM} -r dist/Version_E

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
