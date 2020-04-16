#ifndef __HTML_H__
#define __HTML_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "users.h"
#include "prets.h"
#include "temps.h"

/**
 * \fn void AfficherObjetsParType(char*)
 * \brief Permet \b d'afficher les objets d'un \b certain \b type grâce à une page html.
 * \param char* La fonction prend en paramètre un \b char* qui correspond à la catégorie demandé.
 * \return \b void La fonction ne renvoie rien.
 */

void AfficherObjetsParType(char*);

/**
 * \fn void afficheObjetsPersonne(Personne)
 * \brief Permet \b d'afficher les \a objets d'un \a utilisateur sur une page html.
 * \param Personne La fonction prend en paramètre une \b Personne qui est la personne à qui appartient les objets affichés.
 * \return \b void La fonction ne renvoie rien.
 */

void afficheObjetsPersonne(Personne);

/**
 * \fn void listeDemande(Personne)
 * \brief Permet \b d'afficher les \a emprunts réalisé par un \a utilisateur sur une page html.
 * \param Personne La fonction  prend en paramètre une \b Personne qui est la personne qui a réalisé les \a emprunts \b affichés.
 * \return \b void La fonction ne renvoie rien.
 */

void listeDemande(Personne);

/**
 * \fn void listePret(Personne)
 * \brief Affiche sur une \a page \a html la liste des \b prêts \b effectué par une \a personne.
 * \param Personne La fonction prend en paramètre une \b Personne qui est la personne à qui \b appartient les \a prêts.
 * \return \b void La fonction ne renvoie rien.
 */

void listePret(Personne);

/**
 * \fn bool RechercherParID(void)
 * \brief \b Permet de savoir si un objet avec une certaine \a ID \b existe et de \b l'afficher sur une \a page \a html.
 * \param void La fonction ne prend \b aucun paramètre.
 * \return \b bool La fonction return \b true si l'objet \a existe et \b false si l'objet \a n'existe \a pas.
 */

bool RechercherParID(void);

/**
 * \fn void afficheUsers(void)
 * \brief \b Permet d'afficher tout \a les \a utilisateurs sur une \a page \a html.
 * \param void La fonction ne prend \b aucun paramètre.
 * \return La fonction ne renvoie rien.
 */

void afficheUsers(void);
#endif