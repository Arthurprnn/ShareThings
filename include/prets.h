#ifndef __PRETS_H__
#define __PRETS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <json-c/json.h>
#include "temps.h"
#include "users.h"
#include "objet.h"

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
 * \brief \b Initialisateur d'un prêt.
 * \param void Ne prend rien en paramètre.
 * \return \b Pret La fonction a créé un \b Prêt et l'a \b initialisé avant de le retourner.
 */

Pret init_pret();

/**
 * \fn Pret creer_pret(int)
 * \brief \b Constructeur d'un prêt.
 * \param int Prend l'ID du demandeur pour l'enregistrer dans le prêt.
 * \return \b Pret La fonction a créé un \b Prêt et l'a \b initialisé avant de le retourner.
 */

Pret creer_pret(int);


/**
 * \fn Temps get_temps_debutPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de début du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b struct \b tm La fonction retourne un \b temps de type \b struct \b tm.
 */

Temps get_temps_debutPret(Pret);

/**
 * \fn Temps get_temps_finPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de fin du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b struct \b tm La fonction retourne un \b temps de type \b struct \b tm.
 */

Temps get_temps_finPret(Pret);

/**
 * \fn int get_objetPret(Pret)
 * \brief \b Getter permettant d'obtenir l'objet prêté.
 * \param Pret Pour extraire une donnée sur le prêt.
 * \return \b int La fonction retourne un \b ID_objet de type \b int.
 */

int get_objetPret(Pret);

/**
 * \fn int get_demandeurPret(Pret)
 * \brief \b Getter permettant d'obtenir la personne demandant le prêt.
 * \param Pret Pour extraire une donnée sur le prêt.
 * \return \b int La fonction retourne un \b ID_personne de type \b int.
 */

int get_demandeurPret(Pret);

/**
 * \fn int get_IDPret(Pret)
 * \brief \b Getter permettant d'obtenir le prêt demandé.
 * \param Pret Pour extraire une donnée sur le prêt.
 * \return \b int La fonction retourne un \b ID_pret de type \b int.
 */

int get_IDPret(Pret);


/**
 * \fn void set_temps_debutPret(Pret, Temps)
 * \brief \b Setter permettant de fixer le temps de début du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param Temps Donnée sur le temps à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_temps_debutPret(Pret, Temps);

/**
 * \fn void set_temps_finPret(Pret, Temps)
 * \brief \b Setter permettant de fixer le temps de fin du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param Temps Donnée sur le temps à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_temps_finPret(Pret, Temps);

/**
 * \fn void set_objetPret(Pret, int)
 * \brief \b Setter permettant de fixer l'objet du prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param int Donnée à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_objetPret(Pret, int);

/**
 * \fn void set_demandeurPret(Pret, int)
 * \brief \b Setter permettant de fixer la personne demandant le prêt.
 * \param Pret Pour fixer une information sur le prêt.
 * \param int Donnée à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_demandeurPret(Pret, int);

/**
 * \fn void set_IDPret(Pret, int)
 * \brief \b Setter permettant de fixer le prêt demandé.
 * \param Pret Pour fixer une information sur le prêt.
 * \param int Donnée à écrire dans le prêt.
 * \return \b void La fonction ne retourne rien. Elle écrit simplement dans la description du prêt.
 */

void set_IDPret(Pret, int);

/**
 * \fn int creer_ID_pret()
 * \brief Permet de \b creer un \b ID de \b 8 chiffres \b commençant par un \b 3.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour un prêt donc qui commence par 3.
 */

int creer_ID_pret();

#endif