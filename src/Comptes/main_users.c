#include "users.h"

int main(int argc, char *argv[]) {

    Personne p;
    char nom[32];

    printf("Entrez votre nom : ");
    scanf("%s", nom);
    printf("%s\n", nom);

    return 0;
}