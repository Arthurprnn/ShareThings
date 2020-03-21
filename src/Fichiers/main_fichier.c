#include "../../include/fichier.h"

int main(int argc, char *argv[]) {

    /*
    Objet o = creer_objet(creer_ID_personne());
    creer_fichier_objet(o);

    viderBuffer();
    */

    /*
    Personne p = creer_personne();
    creer_fichier_personne(p);
    */

    int ID=0;
    printf("Entrer l'ID' d'un fichier personne : ");
    scanf("%d", &ID);

    char lien[64]={0};
	sprintf(lien, "../../data/Users/%d.json", ID);
    printf("Lien : %s\n", lien);
    Personne p = lire_fichier_personne(lien);

    viderBuffer();

    Objet o = creer_objet(get_IDPersonne(p));
    creer_fichier_objet(o);

    add_objet_dans_liste_objet(p, o);

    printf("Longueur : %d\n", get_longueur_liste_objetPersonne(p));
    printf("ID : %d\n", get_element_liste_objet(get_liste_objetPersonne(p), 0));

    viderBuffer();
    
    creer_fichier_personne(p);

    return 0;
}