#include "../../include/objet.h"

int main(int argc, char *argv[]) {
    
    Objet o = creer_objet(25570361);
    printf("Chaine: %s\n", get_nomObjet(o));
    creer_fichier_objet(o);

    return 0;
}