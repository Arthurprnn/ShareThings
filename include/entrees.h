#ifndef __ENTREES_H__
#define __ENTREES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>


/**
 * \fn void viderBuffer()
 * \brief Vide le \b buffer.
 * \param void Ne prend rien en paramètre.
 * \return \b Void La fonction a vidé le \b buffer.
 */

void viderBuffer();

/**
 * \fn int getch()
 * \brief La fonction \b getch() est l'abréviation de \b getchar qui permet de lire un caractère ou une touche au clavier. Cette fonction est \b bloquante jusqu'à ce que l'utilisateur appuie sur une touche. le caractère n'est \b pas \b affiché \b à \b l'écran.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction retourne l'encodage du caractere récupéré.
 */

int getch();

/**
 * \fn char * creer_chaine_de_caracteres()
 * \brief La fonction \b réserve \b en \b mémoire un espace pour \b la \b chaine \b de \b caractère \b saisie.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractère.  
 */

char * creer_chaine_de_caracteres();

/**
 * \fn char * creer_mot_de_passe()
 * \brief Permet de \b creer un \b mot \b de \b passe \b dynamiquement en \b remplaçant les \b caractères \b saisis par le caractère \b étoile.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractère.
 */

char * creer_mot_de_passe();


#endif