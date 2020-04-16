#include "../../include/entrees.h"

char * creer_chaine_de_caracteres() {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    for (int i=0; i<strlen(temp); i++) {
        if ((temp[i] == '\n') || (temp[i] == '\r')) {
            temp[i] = '\0';
        }
    }                                                                   /*!< Permet d'enlever le '\n' à la fin de la chaine et le remplace par '\0'. */
    char *c = (char *)malloc(strlen(temp)*sizeof(char));
    strcpy(c, temp);
    return c;
}

void afficheMessageErreurSaisieString(char * caractSpec) {
    int longueur = strlen(caractSpec)-1;
        printf("\nWarning: String contains these characters which are not allowed [");
        for (int i=0; i<longueur; i++) {
            printf("%c ", caractSpec[i]);
        }
        printf("%c]\n", caractSpec[longueur]);
}


bool isSpecialCaractere(char * c, char * caractSpec) {
    bool c_isBon = true;
    int j = 0;
    int longueur_chaine = strlen(c);
    for (int i=0; i<longueur_chaine; i++) {

        /*!< On regarde s'il y a des caractères autres que : {[a-z],[A-Z],[0-9],[_]} */
        if ((isalnum(c[i]) == false) && (isspace(c[i]) == false) && (c[i] != '_')) {
            c_isBon = false;
            caractSpec[j] = c[i];
            j++;
        }
    }
    return c_isBon;
}


char * forcerNomUtilisateurCorrect() {
    printf("Nom d'utilisateur : /!\\ Caractères autorisés : {[a-z],[A-Z],[0-9],[_]}\nChaine : ");
    char * chaine = (char*)malloc(sizeof(char));
    chaine = creer_chaine_de_caracteres();
    char * caractSpec = (char *)malloc(sizeof(char));

    while (!isSpecialCaractere(chaine, caractSpec)) {
        afficheMessageErreurSaisieString(caractSpec);
        printf("Nom d'utilisateur : /!\\ Caractères autorisés : {[a-z],[A-Z],[0-9],[_]}\nChaine : ");
        chaine = "";
        caractSpec = "";
        chaine = creer_chaine_de_caracteres();
    }

    return chaine;
}


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

void lit_format(char * format , void * a) {
    int nbLus = 0;
    int nbJetes = 0;

    nbLus=scanf(format, a);
    nbJetes=lire_fin_ligne();
    while ((nbLus!=1) || (nbJetes!=0)) {
        printf("Warning: Object entered isn't the one requested !\n");
        nbLus=scanf(format, a);
        nbJetes=lire_fin_ligne();
    }
}

int lire_entier(int *entier) {
    lit_format("%d", entier);
    return 0;
}

int lire_decimal(float *decimal) {
    lit_format("%f", decimal);
    return 0;
}

int forcerIDCorrect() {
    int type = 0;
    printf("Type de l'ID à entrer (1 chiffre): Caractères autorisés {[1=objet,2=personne,3=pret]}\nEntier: ");
    lire_entier(&type);
    while ((type < 1) || (type > 3)) {
        printf("Un entier à un seul chiffre est demandé: Caractères autorisés {[1=objet,2=personne,3=pret]}\nEntier: ");
        lire_entier(&type);
    }
    
    int ID = 0;
    printf("ID à entrer (8 chiffres commençant par %d): Caractères autorisés {[0-9]}\nID : ", type);
    lire_entier(&ID);
    switch(type) {
        case 1:
            while ((ID < 10000000) || (ID > 19999999)) {
                printf("Un entier commençant par 1 et à 8 chiffres est attendu: Caractères autorisés {[0-9]}\nID : ");
                lire_entier(&ID);
            }
            break;
        case 2:
            while ((ID < 20000000) || (ID > 29999999)) {
                printf("Un entier commençant par 2 et à 8 chiffres est attendu: Caractères autorisés {[0-9]}\nID : ");
                lire_entier(&ID);
            }
            break;
        case 3:
            while ((ID < 30000000) || (ID > 39999999)) {
                printf("Un entier commençant par 3 et à 8 chiffres est attendu: Caractères autorisés {[0-9]}\nID : ");
                lire_entier(&ID);
            }
            break;
    }
    return ID;
}

int isSur() {
    printf("Êtes vous vraiment sûr ? (0 = oui; 1 = non) : ");
    int sur = 0;
    lire_entier(&sur);
    printf("\n");
    while ((sur < 0) || (sur > 1)) {
        printf("\nAttention : vous devez entrer soit 1 soit 0 !\n");
        printf("\nÊtes vous vraiment sûr ? (0 = oui; 1 = non) : ");
        lire_entier(&sur);
        printf("\n");
    }
    return sur;
}

bool isMemeChaine(char * chaine_1, char * chaine_2) {
    if (strlen(chaine_1) != strlen(chaine_2)) {
        return false;
    } else {
        bool is_bon = true;
        for (int i=0; i<strlen(chaine_1); i++) {
            if (chaine_1[i] != chaine_2[i]) {
                is_bon = false;
            }
        }
        return is_bon;
    }
}