#ifndef __ENTREES_H__
#define __ENTREES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * \fn char * creer_chaine_de_caracteres()
 * \brief La fonction \b réserve \b en \b mémoire un espace pour \b la \b chaine \b de \b caractères \b saisie.
 * \param void Ne prend rien en paramètre.
 * \return \b char* La fonction rend un \b char* qui est une \b chaine \b de \b caractères.  
 */

char * creer_chaine_de_caracteres();

/**
 * \fn void afficheMessageErreurSaisieString(char *)
 * \brief La fonction \b affiche un message d'erreur pour une chaine de caractères.
 * \param char* Prend une chaine de caractères en paramètre qui contient tous les caractères qu'on ne voulait pas et les affiche à l'écran.
 * \return \b void La fonction ne renvoie rien. Elle affiche seulement.
 */

void afficheMessageErreurSaisieString(char *);

/**
 * \fn bool isSpecialCaractere(char *, char *)
 * \brief La fonction \b test s'il y a des caractères spéciaux (le seul accepté est \b _ ) dans une chaine de caractères pouvant contenir des espaces.
 * \param char* Prend une chaine de caractères en paramètre qui est celle qu'on test.
 * \param char* Prend une chaine de caractères en paramètre qui va contenir tous les caractères qu'on ne veut pas lors du test.
 * \return \b bool La fonction renvoie un \b booléen, \b true si il n'y a pas de caractères spéciaux, \b false sinon.
 */

bool isSpecialCaractere(char *, char *);

/**
 * \fn char * forcerNomUtilisateurCorrect()
 * \brief La fonction \b force l'utilisateur à entrer un nom d'utilisateur \b correct.
 * \param void La fonctione ne prend rien en paramètre.
 * \return \b char* La fonction renvoie une \b chaine \b de \b caractères qui est le nom d'utilisateur correct.
 */

char * forcerNomUtilisateurCorrect();

/**
 * \fn int lire_fin_ligne()
 * \brief La fonction permet de voir si un utilisateur a donné trop d'élément lors d'une saisie d'une chaine de caractères.
 * \param void La fonctione ne prend rien en paramètre.
 * \return \b int La fonction \b renvoie le nombre de caractères jetés lors d'une saisie par l'utilisateur.
 */

int lire_fin_ligne();

/**
 * \fn void lit_format(char *, void *)
 * \brief La fonction permet de lire le format que l'on passe en paramètres à l'aide d'un \b scanf, si il y a erreur lors de la saisie, l'utilisateur est obligé de recommencer.
 * \param char* Ce paramètre est le format de la lecture, ex: %d, %f, %lf...
 * \param void* Ce paramètre est l'adresse de la variable où on va stocker la saisie de l'utilisateur. ( \b void car on ne sait pas le type de l'objet qui va être saisie)
 * \return \b void La fonction ne renvoie rien, elle stock juste la saisie dans le 2ème paramètre.
 */

void lit_format(char *, void *);

/**
 * \fn int lire_entier(int *)
 * \brief La fonction utilise la fonction \b lit_format, qui va donner automatiquement le format \b %d au scanf.
 * \param int* Adresse où on doit stocker la valeur entrée par l'utilisateur.
 * \return \b int La fonction renvoie \b 0 si la lecture s'est bien déroulée.
 */

int lire_entier(int *);

/**
 * \fn int lire_decimal(float *)
 * \brief La fonction utilise la fonction \b lit_format, qui va donner automatiquement le format \b %f au scanf.
 * \param float* Adresse où on doit stocker la valeur entrée par l'utilisateur.
 * \return \b int La fonction renvoie \b 0 si la lecture s'est bien déroulée.
 */

int lire_decimal(float *);

/**
 * \fn int forcerIDCorrect()
 * \brief La fonction \b force l'utilisateur à entrer un \b ID d'objet, de personne ou de prêt correct. (i.e. l'ID fait 8 chiffres et commence par 1, 2 ou 3)
 * \param void La fonction ne prend rien en paramètre.
 * \return \b int La fonction renvoie l'ID correct entré par l'utilisateur.
 */

int forcerIDCorrect();

/**
 * \fn bool isSur()
 * \brief La fonction \b demande à l'utilisateur un oui = 0 sinon non.
 * \param void La fonction ne prend rien en paramètre.
 * \return \b bool La fonction renvoie true ou false.
 */

bool isSur();

/**
 * \fn bool isMemeChaine(char *, char *)
 * \brief La fonction \b compare si deux chaines de caractères sont les mêmes.
 * \param char* Prend la première chaine à comparer.
 * \param char* Prend la deuxième chaine à comparer.
 * \return \b bool La fonction renvoie true si ce sont les mêmes chaines sinon false.
 */

bool isMemeChaine(char *, char *);

#endif