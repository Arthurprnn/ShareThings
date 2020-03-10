#include "../../include/prets.h"
#include "../../include/users.h"
#include "../../include/objet.h"

/**
 * Structure nécessaire pour créer un prêt.
 * Elle va servir à prendre les données utiles pour manipuler les objets prétées entre utilisateurs.
 */

struct s_pret {
    struct tm debut;
    struct tm fin;
    Objet objet;
    Personne demandeur;
};

Pret init_pret() {
    Pret p = (Pret)malloc(sizeof(struct s_pret));
    p->debut = malloc(sizeof(struct tm));
    p->fin = malloc(sizeof(struct tm));
    p->objet = init_objet();
    p->demandeur = init_personne();
    return p;
}

struct tm get_temps_debutPret(Pret pret) {

}

struct tm get_temps_finPret(Pret pret) {

}

Objet get_objetPret(Pret pret) {

}

Personne get_demandeurPret(Pret pret) {

}

void set_temps_debutPret(Pret pret, struct tm time) {

}

void set_temps_finPret(Pret pret, struct tm time) {

}

void set_objetPret(Pret pret, Objet objet) {

}

void set_demandeurPret(Pret pret, Personne personne) {

}