#include "../../include/objet.h"

/**
 * Structure :
 * \struct s_objet "va servir à prendre les données utiles pour manipuler les objets qui pourront être prétés."
 */

struct s_objet {
    char nom[64];
    char description[256];
    int ID_obj; /*!< De l'objet */
    int ID_prop; /*!< Du propriétaire */
    int delai_de_pret; /*!< En jours */
};