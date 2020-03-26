#ifndef __ENTREES_H__
#define __ENTREES_H__
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <crypt.h>


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
 * \fn char * creer_chaine_de_caracteres()
 * \brief La fonction \b réserve \b en \b mémoire un espace pour \b la \b chaine \b de \b caractères \b saisie.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractères.  
 */

char * creer_chaine_de_caracteres();

/**
 * \fn char * creer_mot_de_passe()
 * \brief Permet de \b créer un \b mot \b de \b passe \b dynamiquement en \b remplaçant les \b caractères \b saisis par le caractère \b étoile.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractères.
 */

char * creer_mot_de_passe();

/**
 * \fn char * chiffrer_mot_de_passe(char * mdp )
 * \brief Permet de \b chiffrer un \b mot \b de \b passe en utilisant la bibliothèque \a <crypt.h>. 
 * \param char* Prend comme paramètre le char* retourné par: \b char* creer_mot_de_passe(). 
 * \return \b char* La fonction rend un \b char* qui est une chaine de caractère \b chiffrée.
 */

char * chiffrer_mot_de_passe(char * mdp );

/**
 * \fn int creer_ID_objet()
 * \brief Permet de \b creer un \b ID de \b 8 chiffres \b commençant par un \b 1.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour un objet donc qui commence par 1.
 */

int creer_ID_objet();

/**
 * \fn int creer_ID_personne()
 * \brief Permet de \b creer un \b ID de \b 8 chiffres \b commençant par un \b 2.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour une personne donc qui commence par 2.
 */

int creer_ID_personne();

/**
 * \fn int creer_ID_pret()
 * \brief Permet de \b creer un \b ID de \b 8 chiffres \b commençant par un \b 3.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour un prêt donc qui commence par 3.
 */

int creer_ID_pret();

#endif