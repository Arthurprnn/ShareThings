#include "../../include/entrees.h"

int main(int argc, char **argv) {

    int ID = creer_ID_objet();
    printf("Objet : %d\n", ID);

    ID = creer_ID_personne();
    printf("Personne : %d\n", ID);

    /*
    char * ch;
    char * mdpcrypt;
    ch = creer_mot_de_passe();
    printf("\n");
    mdpcrypt = chiffrer_mot_de_passe(ch);
    printf("%s\n", mdpcrypt);
    */

    return 0;
}