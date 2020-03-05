#include "../../include/prets.h"
#include "../../include/users.h"
#include "../../include/objet.h"

/*  Structure :
 *  
 *  La structure s_pret va servir à prendre les données utiles
 *  pour manipuler les objets prétées entre utilisateurs
 * 
 */

struct s_pret {
    struct tm debut;
    struct tm fin;
    Objet objet;
    Personne demandeur;
};