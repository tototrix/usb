/* 
 * File:   door_security.h
 * Author: Christophe
 *
 * Created on 7 août 2015, 15:35
 */

#ifndef DOOR_SECURITY_H
#define	DOOR_SECURITY_H

#define DOOR_ACTIVE_LEVEL      1
#define DOOR_INACTIVE_LEVEL    0

extern u8 door_opened;

extern bool door_opened_error;



void door_security_sm(void);
void door_security_init(void);

#endif	/* DOOR_SECURITY_H */

