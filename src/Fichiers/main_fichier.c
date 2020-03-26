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

    /*
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
    */

    /*
    Pret p = creer_pret(25570361);
    creer_fichier_pret(p);
    */

    int ID=0;
    printf("Entrer l'ID' d'un fichier prêt : ");
    scanf("%d", &ID);

    char lien[64]={0};
	sprintf(lien, "../../data/Prets/%d.json", ID);
    printf("Lien : %s\n", lien);

    Pret p = lire_fichier_pret(lien);
    printf("ID de l'objet : %d\nID du demandeur : %d\nID du prêt : %d\n", get_objetPret(p), get_demandeurPret(p), get_IDPret(p));
    printf("Temps : Le %02d/%02d/%4d à %02d:%02d:%02d\n", get_joursTemps(get_temps_debutPret(p)), get_moisTemps(get_temps_debutPret(p))+1, get_anneesTemps(get_temps_debutPret(p))+1900, get_heuresTemps(get_temps_debutPret(p)), get_minutesTemps(get_temps_debutPret(p)), get_secondesTemps(get_temps_debutPret(p)));

    return 0;
}