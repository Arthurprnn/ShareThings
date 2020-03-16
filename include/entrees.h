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
 * \return \b Void La fonction a vidé  le \b buffer.
 */

void viderBuffer();

/**
 * \fn int getch()
 * \brief \b Lire un caractere ou une touche au clavier.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction getch() est l'abréviation de \b getchar qui permet de lire un caractère ou une touche au clavier. Cette fonction est \b bloquante jusqu'à ce que l'utilisateur appuie sur une touche. le caractère n'est \b pas \b affiché \b à \b l'écran.
 */

int getch();

/**
 * \fn char * creer_chaine_de_caracteres()
 * \brief Permet de créer une chaine de caractère dynamiquement.
 * \param void Ne prend rien en paramètre.
 * \return \b Void La fonction \b reserve \b en \b mémoire un espace pour \b la \b chaine \b de \b caractère \b saisi.
 */

char * creer_chaine_de_caracteres();

/**
 * \fn char * creer_mot_de_passe()
 * \brief Permet de \b creer un \b mot \b de \b passe \b dynamiquement en \b remplacent les \b caractères \b saisi par des \b étoiles.
 * \param void Ne prend rien en paramètre.
 * \return \b char \b * La fonction a vidé  le \b buffer.
 */

char * creer_mot_de_passe();


#endif