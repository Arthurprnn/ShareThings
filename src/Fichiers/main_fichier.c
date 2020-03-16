#include "../../include/fichier.h"

int main(int argc, char *argv[]) {

    Objet o = init_objet();
    o = lire_fichier_objet("test.json");
    printf("Nom : %s\n", get_nomObjet(o));
    printf("Description : %s\n", get_descriptionObjet(o));
    printf("ID_obj : %d\n", get_ID_objetObjet(o));
    printf("ID_prop : %d\n", get_ID_proprietaireObjet(o));
    printf("Délai de prêt : %d\n", get_delai_pretObjet(o));

    return 0;
}