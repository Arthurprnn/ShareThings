#include "../../include/fichier.h"

int main(int argc, char *argv[]) {

    Objet o = init_objet();
    o = lire_fichier_objet("test.json");

    creer_fichier_objet(o);

    return 0;
}