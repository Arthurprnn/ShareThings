#include "chaines.h"

//fonctions sur les chaines en entrée
int lire_fin_ligne() {  
    int cpt=0;
    char c;
    c=getchar();
    while ((c!=EOF) && (c!='\n')) {
        
        if (!isspace(c)) {
            cpt+=1;
        }
        c=getchar();
    }
    return cpt;
}


int lire_chaine(char *chaine) {
    lit_format("%s", chaine);
    return 0;
}


void lit_format(char * format , void * a) {
    int nbLus;
    int nbJetes; 
    do {
        nbLus=scanf(format, a);
        nbJetes=lire_fin_ligne();
    } while ((nbLus!=1) || (nbJetes!=0));
}

//fonctions supplémentaires sur d'autres entrées

int lire_entier(int *entier) {
    lit_format("%d", entier);
    return 0;
}


int lire_decimal(float *decimal) {
    lit_format("%f", decimal);
    return 0;
}


int lire_long_decimal(double *long_decimal) {
    lit_format("%lf", long_decimal);
    return 0;
}

int lire_entier_positif(int *entier_positif) {
    do {
        lire_entier(entier_positif);
    } while ((*entier_positif) < 0) ;
    return 0;
}


int lire_long_decimal_positif(double *long_decimal_positif) {
    do {
        lire_long_decimal(long_decimal_positif);
    } while ((*long_decimal_positif) < 0) ;
    return 0;
}