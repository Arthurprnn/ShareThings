#include "../../include/entrees.h"

int main(int argc, char **argv) {

    char *c = creer_chaine_de_caracteres();
    printf("Chaine de caractere : %s\n", c);

    viderBuffer();

    char * ch;
    ch = creer_mot_de_passe();

    printf("\nLe mot de passe est : ");
    for (int i=0; i<strlen(ch); i++){
        char j;
        j = ch[i];
        printf("%c", j);
    }
    printf("\n");


    return 0;
}