#ifndef __USERS_H__
#define __USERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "objet.h"

/**
 * Structure \b Personne 
 * (Pointeur vers une structure cachée)
 * 
 * Permet la manipulation d'une \a personne à l'aide des fonctions prédéfinies.
 * \struct Personne
 */

typedef struct s_personne * Personne;

/**
 * \fn Personne init_personne()
 * \brief \b Constructeur d'une personne.
 * \param void Ne prend rien en paramètre.
 * \return \b Personne La fonction a créé une \b Personne et l'a \b initialisé avant de le retourner.
 */

Personne init_personne();

/**
 * \fn char* get_nomPersonne(Personne)
 * \brief \b Getter permettant d'obtenir le nom de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b char* La fonction retourne un \b nom de type \b char*.
 */

char * get_nomPersonne(Personne);

/**
 * \fn char* get_prenomPersonne(Personne)
 * \brief \b Getter permettant d'obtenir le prénom de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b char* La fonction retourne un \b prénom de type \b char*.
 */

char * get_prenomPersonne(Personne);

/**
 * \fn int get_agePersonne(Personne)
 * \brief \b Getter permettant d'obtenir l'age de la personne.
 * \param Personne Pour extraire une donnée sur l'objet.
 * \return \b int La fonction retourne un \b age de type \b int.
 */

int get_agePersonne(Personne);

/**
 * \fn int get_IDPersonne(Personne)
 * \brief \b Getter permettant d'obtenir l'ID de la personne.
 * \param Personne Pour extraire une donnée sur l'objet.
 * \return \b int La fonction retourne un \b ID de type \b int.
 */

int get_IDPersonne(Personne);

/**
 * \fn char* get_mailPersonne(Personne)
 * \brief \b Getter permettant d'obtenir le mail de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b char* La fonction retourne un \b mail de type \b char*.
 */

char * get_mailPersonne(Personne);

/**
 * \fn Objet* get_liste_objetPersonne(Personne)
 * \brief \b Getter permettant d'obtenir la liste d'objets de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b Objet* La fonction retourne une \b liste_objet de type \b Objet*.
 */

Objet * get_liste_objetPersonne(Personne);

/**
 * \fn void set_nomPersonne(Personne, char *)
 * \brief \b Setter permettant de fixer le nom de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param char* Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_nomPersonne(Personne, char*);

/**
 * \fn void set_prenomPersonne(Personne, char *)
 * \brief \b Setter permettant de fixer le prénom de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param char* Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_prenomPersonne(Personne, char*);

/**
 * \fn void set_agePersonne(Personne, int)
 * \brief \b Setter permettant de fixer l'age de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param int Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_agePersonne(Personne, int);

/**
 * \fn void set_IDPersonne(Personne, int)
 * \brief \b Setter permettant de fixer l'identification de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param int Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_IDPersonne(Personne, int);

/**
 * \fn void set_mailPersonne(Personne, char *)
 * \brief \b Setter permettant de fixer le mail de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param char* Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_mailPersonne(Personne, char*);



#endif