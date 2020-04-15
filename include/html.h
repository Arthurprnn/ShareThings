#ifndef __HTML_H__
#define __HTML_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "users.h"
#include "prets.h"
#include "temps.h"


void AfficherObjetsParType(char*);
void afficheObjetsPersonne(Personne);
void listeDemande(Personne);
void listePret(Personne);
bool RechercherParID(void);
#endif