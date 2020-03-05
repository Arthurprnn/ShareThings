#include "../../include/objet.h"

/*  Structure :
 *  
 *  La structure s_objet va servir à prendre les données utiles
 *  pour manipuler les objets qui pourront être prétés
 * 
 */

struct s_objet {
    char nom[64];
    char description[256];
    int ID_obj; //de l'objet
    int ID_prop; //du propriétaire
    int delai_de_pret; //en jours
};