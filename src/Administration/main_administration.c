#include "../../include/administration.h"

int main(int argc, char **argv) {

    /*
    char * ch;
    char * mdpcrypt;
    ch = creer_mot_de_passe();
    printf("\n");
    mdpcrypt = chiffrer_mot_de_passe(ch);
    printf("%s\n", mdpcrypt);
    */

    /*
    Personne p = init_personne();
    Compte c = init_compte();
    if (creer_compte(c, p) == 0) {
        printf("Ca a marché!\n");
        printf("Nom: %s\nPrénom: %s\nAge: %d\nMail: %s\n", get_nomPersonne(p), get_prenomPersonne(p), get_agePersonne(p), get_mailPersonne(p));
        printf("Nom_utilisateur: %s\nMDP: %s\nID: %d\n", get_nom_utilisateur(c), get_mdp(c), get_ID_personne(c));
    }
    */

    /*
    Personne p =init_personne();
    Compte c = init_compte();
    creer_compte(c, p);
    creer_fichier_compte(c);
    */

    Personne p = init_personne();
    Compte c = init_compte();
    creer_compte(c, p);

    creer_fichier_compte(c);
    creer_fichier_personne(p);

    printf("Pseudo : %s\nMdp : %s\nID : %d\n", get_nom_utilisateur(c), get_mdp(c), get_ID_personne(c));

    return 0;
}