#include "../../include/users.h"
#include "../../include/objet.h"

/*  Structure :
 *  
 *  La structure s_personne va servir à prendre les données utiles
 *  pour manipuler les utilisateurs
 * 
 */

struct s_personne {
    char nom[32];
    char prenom[32];
    int age;
    int ID; //numéro d'identification
    char mail[64];
    Objet * liste_objet;
};