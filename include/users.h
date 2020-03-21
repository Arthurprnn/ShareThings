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
 * \brief \b Initialisateur d'une personne.
 * \param void Ne prend rien en paramètre.
 * \return \b Personne La fonction a créé une \b Personne et l'a \b initialisé avant de le retourner.
 */

Personne init_personne();

/**
 * \fn Personne creer_personne()
 * \brief \b Constructeur de la personne.
 * \param void La fonction ne prend rien en paramètre.
 * \return \b Personne La fonction a créé une \b personne , l'a \b initialisée puis \b complétée avant de la retourner.
 */

Personne creer_personne();

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
 * \fn int* get_liste_objetPersonne(Personne)
 * \brief \b Getter permettant d'obtenir la liste d'ID d'objets de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b int* La fonction retourne une \b liste \b d'ID \b d'objets chacun de type \b int .
 */

int * get_liste_objetPersonne(Personne);

/**
 * \fn int get_longueur_liste_objetPersonne(Personne)
 * \brief \b Getter permettant d'obtenir la longueur de la liste d'ID d'objets de la personne.
 * \param Personne Pour extraire une information sur la personne.
 * \return \b int La fonction retourne une \b longueur de type \b int .
 */

int get_longueur_liste_objetPersonne(Personne);

/**
 * \fn int get_element_liste_objet(int *, int)
 * \brief \b Getter permettant d'obtenir un ID de la liste d'ID d'objets de la personne.
 * \param int* Pour extraire une information sur la liste d'objets.
 * \param int Pour l'indice de l'élément à extraire de la liste d'objets.
 * \return \b int La fonction retourne un \b élément de type \b int .
 */

int get_element_liste_objet(int *, int);

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

/**
 * \fn void set_liste_objetPersonne(Personne, int*)
 * \brief \b Setter permettant de fixer la liste d'ID d'objets de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param int* Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_liste_objetPersonne(Personne, int*);

/**
 * \fn void set_longueur_liste_objetPersonne(Personne, int)
 * \brief \b Setter permettant de fixer la longueur de la liste d'ID d'objets de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param int Information à écrire dans la description de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description de la personne.
 */

void set_longueur_liste_objetPersonne(Personne, int);

/**
 * \fn void set_element_liste_objet(int*, int, int)
 * \brief \b Setter permettant de rentrer un ID dans la liste d'objets de la personne.
 * \param int* Pour écrire un ID dans la liste d'objets.
 * \param int Indice de l'information à écrire dans la liste d'objets de la personne.
 * \param int ID à écrire dans la liste d'objets de la personne.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la liste d'objets de la personne.
 */

void set_element_liste_objet(int *, int, int);

/**
 * \fn void add_objet_dans_liste_objet(Personne, Objet)
 * \brief \b Ajouteur permettant d'ajouter l'ID d'un objet dans la liste d'objets de la personne.
 * \param Personne Pour fixer une information sur la personne.
 * \param Objet Information à écrire dans la liste d'objets de la personne (juste l'ID).
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la liste d'objets de la personne.
 */

void add_objet_dans_liste_objet(Personne, Objet);

#endif