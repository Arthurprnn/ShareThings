#include "../../include/objet.h"

/**
 * Structure \b s_objet 
 * (Structure cachée)
 * 
 * Permet la manipulation d'un \a objet à l'aide des fonctions prédéfinies et du pointeur \b Objet sur \b s_objet .
 * \struct s_objet
 */

struct s_objet {
    char * nom;
    char * description;
    int ID_obj; /*!< ID de l'objet. */
    int ID_prop; /*!< ID du propriétaire. */
    int delai_de_pret; /*!< Exprimé en jours. */
};

Objet init_objet() {
    Objet o = (Objet)malloc(sizeof(struct s_objet));
    o->nom = (char *)malloc(sizeof(char));
    o->description = (char *)malloc(sizeof(char));
    o->ID_obj = 0;
    o->ID_prop = 0;
    o->delai_de_pret = 0;
    return o;
}

char * get_nomObjet(Objet o) {
    return o->nom;
}

char * get_descriptionObjet(Objet o) {
    return o->description;
}

int get_ID_objetObjet(Objet o) {
    return o->ID_obj;
}

int get_ID_proprietaireObjet(Objet o) {
    return o->ID_prop;
}

int get_delai_pretObjet(Objet o) {
    return o->delai_de_pret;
}

void set_nomObjet(Objet o, char *c) {
    o->nom = c;
}

void set_descriptionObjet(Objet o, char *c) {
    o->description = c;
}

void set_ID_objetObjet(Objet o, int i) {
    o->ID_obj = i;
}

void set_ID_proprietaireObjet(Objet o, int i) {
    o->ID_prop = i;
}

void set_delai_pretObjet(Objet o, int i) {
    o->delai_de_pret = i;
}