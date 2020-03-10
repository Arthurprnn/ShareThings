#ifndef __TEMPS_H__
#define __TEMPS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * Structure \b Temps
 * (Pointeur vers une structure cachée)
 * 
 * Permet la manipulation du \a temps à l'aide des fonctions prédéfinies.
 * \struct Temps
 */

typedef struct tm Temps;

/**
 * \fn Temps init_temps()
 * \brief Permettant d'initialiser un Temps.
 * \param Void Ne prend rien en paramètre. 
 * \return \b Temps La fonction retourne un \b Temps de type \b Temps.
 */

Temps init_temps();


/**
 * \fn int get_secondesTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre de secondes de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_secondesTemps(Temps);

/**
 * \fn int get_minutesTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre de minutes de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_minutesTemps(Temps);

/**
 * \fn int get_heuresTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre d'heures de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_heuresTemps(Temps);

/**
 * \fn int get_joursTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre de jours de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_joursTemps(Temps);

/**
 * \fn int get_moisTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre de mois de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_moisTemps(Temps);

/**
 * \fn int get_anneesTemps(Temps)
 * \brief \b Getter permettant d'obtenir le nombre d'années de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_anneesTemps(Temps);

/**
 * \fn int get_jour_semaineTemps(Temps)
 * \brief \b Getter permettant d'obtenir l'indice \b [0;6] du jour de la semaine de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_jour_semaineTemps(Temps);

/**
 * \fn int get_jour_anneeTemps(Temps)
 * \brief \b Getter permettant d'obtenir l'indice \b [0;365] du jour de l'année de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_jour_anneeTemps(Temps);

/**
 * \fn int get_isdstTemps(Temps)
 * \brief \b Getter permettant de savoir le décalage \b heure \b d'été \b / \b heure \b d'hiver de Temps.
 * \param Temps Pour extraire une information sur le Temps.
 * \return \b int La fonction retourne un \b int.
 */

int get_isdstTemps(Temps);


/**
 * \fn void set_secondesTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en secondes.
 * \param int Nombre de secondes.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_secondesTemps(Temps, int);

/**
 * \fn void set_minutesTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en minutes.
 * \param int Nombre de minutes.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_minutesTemps(Temps, int);

/**
 * \fn void set_heuresTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en heures.
 * \param int Nombre d'heures.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_heuresTemps(Temps, int);

/**
 * \fn void set_joursTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en jours.
 * \param int Nombre de jours.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_joursTemps(Temps, int);

/**
 * \fn void set_moisTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en mois.
 * \param int Nombre de mois.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_moisTemps(Temps, int);

/**
 * \fn void set_anneesTemps(Temps, int)
 * \brief \b Setter permettant de fixer le Temps en années.
 * \param int Nombre d'années.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_anneesTemps(Temps, int);

/**
 * \fn void set_jour_semaineTemps(Temps, int)
 * \brief \b Setter Permet de fixer l'indice du jour de la semaine \b [0;6] de Temps.
 * \param int Indice du jour de la semaine.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_jour_semaineTemps(Temps, int);

/**
 * \fn void set_jour_anneeTemps(Temps, int)
 * \brief \b Setter Permet de fixer l'indice du jour de l'année \b [0;365] de Temps.
 * \param int Indice du jour de l'année.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_jour_anneeTemps(Temps, int);

/**
 * \fn void set_isdstTemps(Temps, int)
 * \brief \b Setter Permet de fixer le décalage heure d'été / heure d'hiver \b [-1,0,1] de Temps.
 * \param int Indice du décalage.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans le Temps.
 */

void set_isdstTemps(Temps, int);

#endif