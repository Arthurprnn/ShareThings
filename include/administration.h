#ifndef __ADMINISTRATION_H__
#define __ADMINISTRATION_H__
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <crypt.h>
#include "entrees.h"
#include "users.h"


/**
 * Structure \b Compte 
 * (Pointeur vers une structure cachée)
 * 
 * Permet la manipulation d'un \a compte à l'aide des fonctions prédéfinies.
 * \struct Compte
 */

typedef struct s_compte * Compte;

/**
 * \fn Compte init_compte()
 * \brief \b Initialisateur du compte.
 * \param void Ne prend rien en paramètre.
 * \return \b Compte La fonction a initialisé un \b compte avant de le retourner.
 */

Compte init_compte();

/**
 * \fn int creer_compte(Compte, Personne)
 * \brief \b Constructeur d'un compte'.
 * \param Compte La fonction prend en paramètre un \b compte qui sera le compte créé.
 * \param Personne La fonction prend en paramètre une \b personne qui sera celle attachée au compte.
 * \return \b int La fonction retourne un entier 0 si tous fonctionne.
 */

int creer_compte(Compte, Personne);

/**
 * \fn char* get_nom_utilisateur(Compte)
 * \brief \b Getter permettant d'obtenir le nom d'utilisateur du compte.
 * \param Compte Pour extraire une donnée sur le compte.
 * \return \b char* La fonction retourne un \b nom de type \b char*.
 */

char * get_nom_utilisateur(Compte);

/**
 * \fn char* get_mdp(Compte)
 * \brief \b Getter permettant d'obtenir le mot de passe crypté du compte.
 * \param Compte Pour extraire une donnée sur le compte.
 * \return \b char* La fonction retourne un \b mot \b de \b passe de type \b char*.
 */

char * get_mdp(Compte);

/**
 * \fn int get_ID_personne(Compte)
 * \brief \b Getter permettant d'obtenir l'ID de l'utilisateur du compte.
 * \param Compte Pour extraire une donnée sur le compte.
 * \return \b int La fonction retourne un \b ID de type \b int.
 */

int get_ID_personne(Compte);

/**
 * \fn void set_nom_utilisateur(Compte, char *)
 * \brief \b Setter permettant de fixer le nom d'utilisateur d'un compte.
 * \param Compte Pour fixer une donnée sur le compte.
 * \param char* Donnée à écrire dans le compte.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le compte.
 */

void set_nom_utilisateur(Compte, char *);

/**
 * \fn void set_mdp(Compte, char *)
 * \brief \b Setter permettant de fixer le mot de passe d'un compte.
 * \param Compte Pour fixer une donnée sur le compte.
 * \param char* Donnée à écrire dans le compte.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le compte.
 */

void set_mdp(Compte, char *);

/**
 * \fn void set_ID_personne(Compte, int)
 * \brief \b Setter permettant de fixer l'ID de l'utilisateur d'un compte.
 * \param Compte Pour fixer une donnée sur le compte.
 * \param int Donnée à écrire dans le compte.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le compte.
 */

void set_ID_personne(Compte, int);


/**
 * \fn void viderBuffer()
 * \brief Vide le \b buffer.
 * \param void Ne prend rien en paramètre.
 * \return \b Void La fonction a vidé le \b buffer.
 */

void viderBuffer();

/**
 * \fn int getch()
 * \brief La fonction \b getch() est l'abréviation de \b getchar qui permet de lire un caractère ou une touche au clavier. Cette fonction est \b bloquante jusqu'à ce que l'utilisateur appuie sur une touche. Le caractère n'est \b pas \b affiché \b à \b l'écran.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction retourne l'encodage du caractère récupéré.
 */

int getch();

/**
 * \fn char * creer_mot_de_passe()
 * \brief Permet de \b créer un \b mot \b de \b passe \b dynamiquement en \b remplaçant les \b caractères \b saisis par le caractère \b étoile.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractères.
 */

char * creer_mot_de_passe();

/**
 * \fn char * chiffrer_mot_de_passe(char *)
 * \brief Permet de \b chiffrer un \b mot \b de \b passe en utilisant la bibliothèque \a <crypt.h>. 
 * \param char* Prend comme paramètre le char* retourné par: \b char* creer_mot_de_passe(). 
 * \return \b char* La fonction rend un \b char* qui est une chaine de caractère \b chiffrée.
 */

char * chiffrer_mot_de_passe(char *);

/**
 * \fn bool isCompteExist(char *)
 * \brief Permet de \b vérifier si le nom de l'utilisateur existe déjà.
 * \param char* Prend le nom de l'utilisateur à vérifier.
 * \return \b bool La fonction renvoie \b false si l'objet n'existe pas, \b true sinon.
 */

bool isCompteExist(char *);

Compte lire_fichier_compte(char *);

void creer_fichier_compte(Compte);

#endif