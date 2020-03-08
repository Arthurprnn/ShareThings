#include "../../include/users.h"
#include "../../include/objet.h"

/**
 * Structure \b s_personne 
 * (Structure cachée)
 * 
 * Permet la manipulation d'une \a personne à l'aide des fonctions prédéfinies et du pointeur \b Personne sur \b s_personne .
 * \struct s_personne
 */

struct s_personne {
    char * nom;
    char * prenom;
    int age;
    int ID; /*!< Numéro d'identification de la personne. */
    char * mail;
    Objet * liste_objet;
};