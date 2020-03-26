#include "../../include/entrees.h"

void viderBuffer(){                                                      /*!< Permet de vider le buffer */
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

int getch(){                                                             /*!< Permet de recuperer un caractère rentré au clavier sans avoir à appuyer sur entrée. */
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char * creer_chaine_de_caracteres() {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    for (int i=0; i<strlen(temp); i++) {
        if (temp[i] == '\n') {
            temp[i] = '\0';
        }
    }                                                                   /*!< Permet d'enlever le '\n' à la fin de la chaine et le remplace par '\0'. */
    char *c = (char *)malloc(strlen(temp)*sizeof(char));
    for (int i=0; i<strlen(temp); i++) {
        c[i]=temp[i];
    }
    return c;
}

char * creer_mot_de_passe(){
    char mdp[32], ch;
    printf("Veuillez saisir votre mot de passe : ");
    int i=0;

    do {
        ch = getch();                                                   /*!< On récupere un caractère saisie, sans que l'itilisateur ait appuyé sur entrée. */
        mdp[i] = ch;                                                    
        ch = '*' ;                                                      /*!< On remplace le caractère saisie par une étoile.*/
        printf("%c", ch);                                               /*!< Et on afiche l'étoile.*/
        i++;
    } while ((i<32) && (mdp[i-1] != '\n'));                             /*!< Tant que le mot de passe est inferieur à 32 et que l'on ne détecte pas que l'utilisateur appuie sur entrée. */

    char *c = (char *)malloc(strlen(mdp)*sizeof(char));                 /*!< On réserve en mémoire une taille adapté à la longeur du mot de passe. */
    for (int j=0; j<strlen(mdp); j++) {                                 
        c[j]=mdp[j];
    }
    return c;
}

char * chiffrer_mot_de_passe(char * mdp ){
    int nbsegment= strlen(mdp)/8+1;                                     /*!< Nombre de séquences nécessaire. */
    char salt[]="lagrossemoula";                                        /*!< Permet d'orienter le chiffrement. */
    char tempon[9] = "" ;
    char * cryptmdp = (char *)malloc((nbsegment*13)*sizeof(char));      /*!< On réserve l'éspace nécessaire en mémoire pour le mot de passe chiffré. */ 
    int j = 0;

    for (int i=0; i<strlen(mdp); i++) {                                 /*!< On enlève le "\n" et on le remplace par "\0". */ 
        if (mdp[i] == '\n') {
            mdp[i] = '\0';
        }
    }

    for (int i=0; i<strlen(mdp); i++){                                            /*!< On parcours le mot de passe en claire, on le chiffre par 8 caractères que l'on concatène dans cryptmdp. */
        if ((i%8 == 0) && (i!=0)){                                      /*!< On parcours et récolte 8 caractères avant de les chiffrer, puis de recommencer.*/
            j=0;
            cryptmdp = strcat(cryptmdp, crypt(tempon, salt));            
        }
        tempon[j] = mdp[i];
        j++;
    } 
    cryptmdp = strcat(cryptmdp, crypt(tempon, salt));                   /*!< Pour chiffrer les derniers caractères présent. */
    return cryptmdp;                                                    /*!< On return le tableau contenant le mot de passe chiffré. */
}   

int creer_ID_objet() {
    srand(time(NULL));
    FILE *fichier = NULL;
    int bon_ID = 0;

    do {
        int ID_temp = 1;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }

        char nom[32]={0};
	    sprintf(nom, "../../data/Objets/%d.json", ID_temp);
        fichier = fopen(nom, "r");

        bon_ID = ID_temp;
    } while (fichier != NULL);
    return bon_ID;
}                                                                       /*!< Tous les ID des objets commenceront par un 1. */

int creer_ID_personne() {
    srand(time(NULL));
    FILE *fichier = NULL;
    int bon_ID = 0;

    do {
        int ID_temp = 2;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }

        char nom[32]={0};
	    sprintf(nom, "../../data/Users/%d.json", ID_temp);
        fichier = fopen(nom, "r");
        
        bon_ID = ID_temp;
    } while (fichier != NULL);
    return bon_ID;
}                                                                      /*!< Tous les ID des personnes commenceront par un 2. */

int creer_ID_pret() {
    srand(time(NULL));
    FILE *fichier = NULL;
    int bon_ID = 0;

    do {
        int ID_temp = 3;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }

        char nom[32]={0};
	    sprintf(nom, "../../data/Prets/%d.json", ID_temp);
        fichier = fopen(nom, "r");
        
        bon_ID = ID_temp;
    } while (fichier != NULL);
    return bon_ID;
}