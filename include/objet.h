#ifndef __OBJET_H__
#define __OBJET_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "entrees.h"

/**
 * Structure \b Objet 
 * (Pointeur vers une structure cachée)
 * 
 * Permet la manipulation d'un \a objet à l'aide des fonctions prédéfinies.
 * \struct Objet
 */

typedef struct s_objet * Objet;


/**
 * \fn Objet init_objet()
 * \brief \b Initialisateur de l'objet.
 * \param void Ne prend rien en paramètre.
 * \return \b Objet La fonction a initialisé un \b objet avant de le retourner.
 */

Objet init_objet();

/**
 * \fn Objet creer_objet(int)
 * \brief \b Constructeur de l'objet.
 * \param int La fonction prend en paramètre un \b int qui est l' \b ID de celui qui a créé l'objet.
 * \return \b Objet La fonction a créé un \b objet , l'a \b initialisé puis \b complété avant de le retourner.
 */

Objet creer_objet(int);

/**
 * \fn char* get_nomObjet(Objet)
 * \brief \b Getter permettant d'obtenir le nom de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b char* La fonction retourne un \b nom de type \b char*.
 */

char * get_nomObjet(Objet);

/**
 * \fn char* get_descriptionObjet(Objet)
 * \brief \b Getter permettant d'obtenir la description de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b char* La fonction retourne une \b description de type \b char*.
 */

char * get_descriptionObjet(Objet);

/**
 * \fn int get_ID_objetObjet(Objet)
 * \brief \b Getter permettant d'obtenir l'ID de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b int La fonction retourne un \b ID de type \b int.
 */

int get_ID_objetObjet(Objet);

/**
 * \fn int get_ID_proprietaireObjet(Objet)
 * \brief \b Getter permettant d'obtenir l'ID du propriétaire de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b int La fonction retourne un \b ID de type \b int.
 */

int get_ID_proprietaireObjet(Objet);

/**
 * \fn int get_delai_pretObjet(Objet)
 * \brief \b Getter permettant d'obtenir le delai de prêt de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b int La fonction retourne un \b délai de type \b int.
 */

int get_delai_pretObjet(Objet);

/**
 * \fn void set_nomObjet(Objet, char *)
 * \brief \b Setter permettant de fixer le nom de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param char* Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_nomObjet(Objet, char *);

/**
 * \fn void set_descriptionObjet(Objet, char *)
 * \brief \b Setter permettant de fixer la description de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param char* Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_descriptionObjet(Objet, char *);

/**
 * \fn void set_ID_objetObjet(Objet, int)
 * \brief \b Setter permettant de fixer le nom de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param int Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_ID_objetObjet(Objet, int);

/**
 * \fn void set_ID_proprietaireObjet(Objet, int)
 * \brief \b Setter permettant de fixer le nom de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param int Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_ID_proprietaireObjet(Objet, int);

/**
 * \fn void set_delai_pretObjet(Objet, int)
 * \brief \b Setter permettant de fixer le nom de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param int Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_delai_pretObjet(Objet, int);

bool existe_objet(int);

#endif