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
    int * liste_objet;
    int longueur_liste_objet;
};

Personne init_personne() {
    Personne p = (Personne)malloc(sizeof(struct s_personne));
    p->nom = (char *)malloc(sizeof(char));
    p->prenom = (char *)malloc(sizeof(char));
    p->age = 0;
    p->ID = 0;
    p->mail = (char *)malloc(sizeof(char));
    p->liste_objet = (int *)malloc(sizeof(int));
    p->longueur_liste_objet = 0;
    return p;
}

Personne creer_personne() {
    Personne p = init_personne();
    printf("Entrez votre nom : ");
    set_nomPersonne(p, creer_chaine_de_caracteres());
    printf("\nEntrez votre prénom : ");
    set_prenomPersonne(p, creer_chaine_de_caracteres());
    printf("\nEntrez votre mail : ");
    set_mailPersonne(p, creer_chaine_de_caracteres());
    
    int age=0;
    printf("\nEntrez votre age : ");
    scanf("%d", &age);
    set_agePersonne(p, age);
    
    set_IDPersonne(p, creer_ID_personne());

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

int * get_liste_objetPersonne(Personne p) {
    return p->liste_objet;
}

int get_longueur_liste_objetPersonne(Personne p) {
    return p->longueur_liste_objet;
}

int get_element_liste_objet(int *liste, int indice) {
    return liste[indice];
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

void set_liste_objetPersonne(Personne p, int *liste) {
    p->liste_objet = liste;
}

void set_longueur_liste_objetPersonne(Personne p, int longueur) {
    p->longueur_liste_objet = longueur;
}

void set_element_liste_objet(int *liste, int indice, int element) {
    liste[indice] = element;
}



void add_objet_dans_liste_objet(Personne p, Objet o) {
    
    int *new_liste = (int*)malloc((get_longueur_liste_objetPersonne(p)+1)*sizeof(int));
    int *liste = get_liste_objetPersonne(p);

    for (int i=0; i<get_longueur_liste_objetPersonne(p); i++) {
        new_liste[i] = liste[i];
    }

    new_liste[get_longueur_liste_objetPersonne(p)] = get_ID_objetObjet(o);

    set_liste_objetPersonne(p, new_liste);
    set_longueur_liste_objetPersonne(p, get_longueur_liste_objetPersonne(p)+1);
}

int creer_ID_personne() {
    srand(time(NULL));
    FILE *fichier = NULL;
    int bon_ID = 0;

    do {
        int ID_temp = 2;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }

        char nom[32]={0};
	    sprintf(nom, "../../data/Users/%d.json", ID_temp);
        fichier = fopen(nom, "r");
        
        bon_ID = ID_temp;
    } while (fichier != NULL);
    return bon_ID;
}                                                   /*!< Tous les ID des objets commenceront par un 2. */