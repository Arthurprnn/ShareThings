#include "../../include/objet.h"

int main(int argc, char *argv[]) {

    Objet o = init_objet();
    char *nom = (char *)malloc(sizeof(char));

    printf("Entrer un nom pour votre objet : ");
    scanf("%s", nom);
    set_nomObjet(o, nom);
    printf("Nom de l'objet : %s\n", get_nomObjet(o));

    int ID;
    printf("Entrer un ID pour l'objet : ");
    scanf("%d", &ID);
    set_ID_objetObjet(o, ID);
    printf("ID de l'objet = %d\n", get_ID_objetObjet(o));

    return 0;
}