#include "../../include/users.h"
#include "../../include/objet.h"

/** 
 * Structure :
 * \struct s_personne "va servir à prendre les données utiles pour manipuler les utilisateurs."
 */

struct s_personne {
    char nom[32];
    char prenom[32];
    int age;
    int ID; /*!< Numéro d'identification */
    char mail[64];
    Objet * liste_objet;
};