#ifndef __PRETS_H__
#define __PRETS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <json-c/json.h>
#include <string.h>
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
 * \fn Pret init_pret(void)
 * \brief \b Initialisateur d'un prêt.
 * \param void Ne prend rien en paramètre.
 * \return \b Pret La fonction a créé un \b Prêt et l'a \b initialisé avant de le retourner.
 */

Pret init_pret(void);

/**
 * \fn Pret creer_pret(int, int)
 * \brief \b Créateur d'un prêt.
 * \param int L'ID du demandeur du prêt.
 * \param int L'ID de l'objet.
 * \return \b Pret La fonction a créé le \b Prêt et l'a retourné.
 */

Pret creer_pret(int, int);


/**
 * \fn Temps get_temps_debutPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de début du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b Struct \b tm La fonction retourne un \b temps de type \b Struct \b tm.
 */

Temps get_temps_debutPret(Pret);

/**
 * \fn Temps get_temps_finPret(Pret)
 * \brief \b Getter permettant d'obtenir le temps de fin du prêt.
 * \param Pret Pour extraire une information sur le prêt.
 * \return \b struct \b tm La fonction retourne un \b temps de type \b Struct \b tm.
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
 * \fn int creer_ID_pret(void)
 * \brief Permet de \b creer un \b ID de \b 8 chiffres \b commençant par un \b 3.
 * \param void Ne prend rien en paramètre.
 * \return \b int La fonction rend un \b ID qui est un \b int de \b 8 \b caractères pour un prêt donc qui commence par 3.
 */

int creer_ID_pret(void);

/**
 * \fn bool isPretExist(int)
 * \brief Permet de \b vérifier si l'ID du prêt existe déjà.
 * \param int Prend l'ID à vérifier.
 * \return \b bool La fonction renvoie \b false si le prêt n'existe pas, \b true sinon.
 */

bool isPretExist(int);

/**
 * \fn Pret lire_fichier_pret(char *)
 * \brief Cette fonction prend les \b données d'un \a prêt d'un fichier au format \b JSON et les sauvegarde dans un Pret.
 * \param char* Prend en paramètre une chaine de caractère qui est le \b lien d'un fichier \b JSON .
 * \return \b Pret La fonction renvoie une \b prêt avec les données du fichier JSON qui y sont stockées.
 */

Pret lire_fichier_pret(char *);

/**
 * \fn void creer_fichier_pret(Pret)
 * \brief Cette fonction prend les \b données d'un \a prêt et les sauvegarde dans un fichier au format \b JSON au nom de l'ID du prêt.
 * \param Pret Prend en paramètre un \a prêt qui sera sauvegardé dans un fichier \b JSON .
 * \return \b void La fonction ne renvoie rien, elle sauvegarde juste.
 */

void creer_fichier_pret(Pret);

/**
 * \fn void demander_objet(Personne)
 * \brief Cette fonction vérifie si \a l'utilisateur \b peut \b emprunter l'objet qu'il demande et \a effectue le prêt si il \b peut \b bien l'emprunter. 
 * \param Personne Prend en paramètre la \a personne qui \b demande \a l'objet.
 * \return \b void La fonction ne renvoie rien.
 */

void demander_objet(Personne);

/**
 * \fn void rendre_objet(Personne)
 * \brief Cette fonction vérifie si \a l'utilisateur \b peut rendre l'objet qu'il a renseigné et \b rend l'objet à son \a propriétaire. 
 * \param Personne Prend en paramètre la \a personne qui rend l'objet \b emprunté.
 * \return \b void La fonction ne renvoie rien.
 */

void rendre_objet(Personne);

/**
 * \fn bool verifieDatePret(int)
 * \brief Cette fonction vérifie si \a l'utilisateur possede des \a prêts \b en \b retard et l'avertie si il doit rendre un prêt dans \b moins \b de \b 23 heures.
 * \param int Prend en paramètre \b l'ID de la personne pour \a vérifier \a ses \a prêts.
 * \return \b bool La fonction renvoie \b true si \a l'utilisateur ne possède pas de \b prêt \b en \b retard, false sinon.
 */

bool verifieDatePret(int);

#endif