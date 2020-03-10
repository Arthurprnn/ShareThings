#include "../../include/entrees.h"



char * creer_chaine_de_caracteres() {
    char temp[256];
    printf("Entree une chaine de caractere : ");
    scanf("%s", temp);
    char *c = (char *)malloc(strlen(temp)*sizeof(char));
    for (int i=0; i<strlen(temp); i++) {
        c[i]=temp[i];
    }
    return c;
}



int main(int argc, char **argv) {

    char *c = creer_chaine_de_caracteres();
    printf("%s\n", c);

    return 0;
}