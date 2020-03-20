#include "../../include/fichier.h"

int main(int argc, char *argv[]) {

    /*
    Objet o = creer_objet(69696969);
    creer_fichier_objet(o);
    */

    Personne p = creer_personne();
    creer_fichier_personne(p);

    return 0;
}