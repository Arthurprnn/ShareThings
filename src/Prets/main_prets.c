#include "../../include/prets.h"

int main(int argc, char *argv[]) {

    Pret p = creer_pret(65656565);

    Temps debut = get_temps_debutPret(p);
    Temps fin = get_temps_finPret(p);

    printf("Début du prêt : Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(debut), get_moisTemps(debut)+1, get_anneesTemps(debut)+1900, get_heuresTemps(debut), get_minutesTemps(debut), get_secondesTemps(debut));
    printf("Fin du prêt : Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(fin), get_moisTemps(fin)+1, get_anneesTemps(fin)+1900, get_heuresTemps(fin), get_minutesTemps(fin), get_secondesTemps(fin));

    printf("ID du prêt : %d\n", get_IDPret(p));

    creer_fichier_pret(p);

    return 0;
}