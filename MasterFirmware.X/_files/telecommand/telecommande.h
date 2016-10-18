#ifndef TELECOMMANDE_H
#define	TELECOMMANDE_H
#include "_Typedefs.h"


extern bool tele_auto;
extern bool tele_deroulement_haut;
extern bool tele_enroulement_haut;
extern bool tele_enroulement_bas;


void init_telecommande(void);
void telecommande_AR(void);
u8   telecommande_byte(void);


#endif	/* TELECOMMANDE_H */

