#ifndef __PRETS_H__
#define __PRETS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../../include/users.h"
#include "../../include/objet.h"

/**
 * Structure \b Pret
 * (Pointeur vers une structure cachée)
 * 
 * Permet la manipulation d'un \a prêt à l'aide des fonctions prédéfinies.
 * \struct Pret
 */

typedef struct s_pret * Pret;


/**
 * \fn Pret init_pret()
 * \brief \b Constructeur d'un prêt.
 * \param void Ne prend rien en paramètre.
 * \return \b Pret La fonction a créé un \b Prêt et l'a \b initialisé avant de le retourner.
 */

Pret init_pret();


/**
 * \fn struct tm get_temps_debutPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de début du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b struct \b tm La fonction retourne un \b temps de type \b struct \b tm.
 */

struct tm get_temps_debutPret(Pret);

/**
 * \fn struct tm get_temps_finPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de fin du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b struct \b tm La fonction retourne un \b temps de type \b struct \b tm.
 */

struct tm get_temps_finPret(Pret);

/**
 * \fn Objet get_objetPret(Pret)
 * \brief \b Getter permettant d'obtenir l'objet prêté.
 * \param Pret Pour extraire une donnée sur le prêt.
 * \return \b Objet La fonction retourne un \b objet de type \b Objet.
 */

Objet get_objetPret(Pret);

/**
 * \fn Personne get_demandeurPret(Pret)
 * \brief \b Getter permettant d'obtenir la personne demandant le prêt.
 * \param Pret Pour extraire une donnée sur le prêt.
 * \return \b Personne La fonction retourne une \b personne de type \b Personne.
 */

Personne get_demandeurPret(Pret);


/**
 * \fn void set_temps_debutPret(Pret, struct tm)
 * \brief \b Setter permettant de fixer le temps de début du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param struct tm Donnée sur le temps à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_temps_debutPret(Pret, struct tm);

/**
 * \fn void set_temps_finPret(Pret, struct tm)
 * \brief \b Setter permettant de fixer le temps de fin du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param struct tm Donnée sur le temps à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_temps_finPret(Pret, struct tm);

/**
 * \fn void set_objetPret(Pret, Objet)
 * \brief \b Setter permettant de fixer l'objet du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param Objet Donnée à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_objetPret(Pret, Objet);

/**
 * \fn void set_demandeurPret(Pret, Personne)
 * \brief \b Setter permettant de fixer la personne demandant le prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param Personne Donnée à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_demandeurPret(Pret, Personne);



#endif