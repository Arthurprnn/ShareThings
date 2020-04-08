#ifndef __OBJET_H__
#define __OBJET_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <json-c/json.h>
#include <string.h>

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
 * \fn void init_objet(Objet)
 * \brief \b Initialisateur d'un objet.
 * \param Objet Prend en paramètre l'objet a initialiser.
 * \return \b void La fonction ne retourne rien.
 */

void init_objet(Objet);

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
 * \fn char* get_typeObjet(Objet)
 * \brief \b Getter permettant d'obtenir la description de l'objet.
 * \param Objet Pour extraire une donnée sur l'objet.
 * \return \b char* La fonction retourne un \b type \b d'objet de type \b char*.
 */

char * get_typeObjet(Objet);

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
 * \fn void set_typeObjet(Objet, char *)
 * \brief \b Setter permettant de fixer le type de l'objet.
 * \param Objet Pour fixer une donnée sur l'objet.
 * \param char* Donnée à écrire dans l'objet.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans l'objet.
 */

void set_typeObjet(Objet, char *);

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

/**
 * \fn char * BonType(char *)
 * \brief Permet de vérifier si le type en paramètre est un type du logiciel, aucune erreur d'orthographe n'est permise, par défaut: Autres.
 * \param char* La fonction prend en paramètre le type de l'objet à vérifier.
 * \return \b char* La fonction rend une chaine de caractères correspondant au bon type de l'objet.
 */

char * BonType(char *);

/**
 * \fn bool isObjetExist(int, char *)
 * \brief Permet de \b vérifier si l'ID de l'objet existe déjà.
 * \param int Prend l'ID à vérifier.
 * \param char* Prend le type de l'objet, pour rechercher dans le bon répertoire de data.
 * \return \b bool La fonction renvoie \b false si l'objet n'existe pas, \b true sinon.
 */

bool isObjetExist(int, char *);

/**
 * \fn int creer_ID_objet(char *)
 * \brief Permet de \b créer un \b ID de \b 8 chiffres \b commençant par un \b 1.
 * \param char* La fonction prend en paramètre le type de l'objet.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour un objet donc qui commence par 1.
 */

int creer_ID_objet(char *);

/**
 * \fn Objet lire_fichier_objet(char *)
 * \brief Cette fonction prend les \b données d'un \a objet d'un fichier au format \b JSON et les sauvegarde dans un Objet.
 * \param char* Prend en paramètre une chaine de caractère qui est le \b lien d'un fichier \b JSON .
 * \return \b Objet La fonction renvoie un \b objet avec les données du fichier JSON qui y sont stockées.
 */

Objet lire_fichier_objet(char *);

/**
 * \fn void creer_fichier_objet(Objet)
 * \brief Cette fonction prend les \b données d'un \a objet et les sauvegarde dans un fichier au format \b JSON au nom de l'ID de l'objet.
 * \param Objet Prend en paramètre un \a objet qui sera sauvegardé dans un fichier \b JSON .
 * \return \b void La fonction ne renvoie rien, elle sauvegarde juste.
 */

void creer_fichier_objet(Objet);

#endif