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

Personne init_personne() {
    Personne p = (Personne)malloc(sizeof(struct s_personne));
    p->nom = (char *)malloc(sizeof(char));
    p->prenom = (char *)malloc(sizeof(char));
    p->age = 0;
    p->ID = 0;
    p->mail = (char *)malloc(sizeof(char));
    p->liste_objet = (Objet *)malloc(sizeof(Objet));
    return p;
}

char * get_nomPersonne(Personne p) {
    return p->nom;
}

char * get_prenomPersonne(Personne p) {
    return p->prenom;
}

int get_agePersonne(Personne p) {
    return p->age;
}

int get_IDPersonne(Personne p) {
    return p->ID;
}

char * get_mailPersonne(Personne p) {
    return p->mail;
}

Objet * get_liste_objetPersonne(Personne p) {
    return p->liste_objet;
}

void set_nomPersonne(Personne p, char *c) {
    p->nom = c;
}

void set_prenomPersonne(Personne p, char *c) {
    p->prenom = c;
}

void set_agePersonne(Personne p, int i) {
    p->age = i;
}

void set_IDPersonne(Personne p, int i) {
    p->ID = i;
}

void set_mailPersonne(Personne p, char *c) {
    p->mail = c;
}

void set_liste_objetPersonne(Personne p, Objet *o) {
    p->liste_objet = o;
}