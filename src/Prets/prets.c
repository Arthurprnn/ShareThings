#include "../../include/prets.h"

/**
 * Structure nécessaire pour créer un prêt.
 * Elle va servir à prendre les données utiles pour manipuler les objets prétées entre utilisateurs.
 */

struct s_pret {
    Temps debut;
    Temps fin;
    Objet objet;
    Personne demandeur;
};

Pret init_pret() {
    Pret p = (Pret)malloc(sizeof(struct s_pret));
    p->debut = init_temps();
    p->fin = init_temps();
    p->objet = init_objet();
    p->demandeur = init_personne();
    return p;
}

Temps get_temps_debutPret(Pret pret) {
    return pret->debut;
}

Temps get_temps_finPret(Pret pret) {
    return pret->fin;
}

Objet get_objetPret(Pret pret) {
    return pret->objet;
}

Personne get_demandeurPret(Pret pret) {
    return pret->demandeur;
}

void set_temps_debutPret(Pret pret, Temps time) {
    pret->debut = time;
}

void set_temps_finPret(Pret pret, Temps time) {
    pret->fin = time;
}

void set_objetPret(Pret pret, Objet objet) {
    pret->objet = objet;
}

void set_demandeurPret(Pret pret, Personne personne) {
    pret->demandeur = personne;
}