#ifndef __FICHIER_H__
#define __FICHIER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <json-c/json.h>
#include <string.h>
#include "objet.h"

/**
 * \fn Objet lire_fichier_objet(char *)
 * \brief Cette fonction prend les \b données d'un \a objet d'un fichier au format \b JSON et les sauvegarde dans un Objet.
 * \param char* Prend en paramètre une chaine de caractère qui est le \b lien d'un fichier \b JSON .
 * \return \b Objet La fonction renvoie un \b Objet avec les données du fichier JSON qui y sont stockées.
 */

Objet lire_fichier_objet(char *);

/**
 * \fn void creer_fichier_objet(Objet)
 * \brief Cette fonction prend les \b données d'un \a objet et les sauvegarde dans un fichier au format \b JSON au nom de l'ID de l'objet.
 * \param Objet Prend en paramètre un \a Objet qui sera sauvegardé dans un fichier \b JSON .
 * \return \b void La fonction ne renvoie rien, elle sauvegarde juste.
 */

void creer_fichier_objet(Objet);

#endif