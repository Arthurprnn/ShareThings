#include "../../include/users.h"

int main(int argc, char *argv[]) {

    //Personne p = creer_personne();
    
    int ID = forcerIDCorrect();
    while (!isPersonneExist(ID)) {
        printf("L'ID sélectionné n'existe pas !\n");
        ID = forcerIDCorrect();
    }

    char lien[64];
    sprintf(lien, "../../data/Users/%d.json", ID);

    Personne p = lire_fichier_personne(lien);
    Objet o = creer_objet(ID);
    creer_fichier_objet(o);

    add_objet_dans_liste_objet(p, o);
    creer_fichier_personne(p);

    return 0;
}