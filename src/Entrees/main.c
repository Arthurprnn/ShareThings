#include "chaines.h"

//main
int main(int argc, char *argv[]) {

    char *chaine = malloc(sizeof(char));
    printf("Entrer une chaine de caractères : ");
    lire_chaine(chaine);
    printf("Vous avez entré : %s\n", chaine);

    return 0;
}