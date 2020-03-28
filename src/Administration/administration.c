#include "../../include/administration.h"

/**
 * Structure \b s_compte 
 * (Structure cachée)
 * 
 * Permet la manipulation d'un \a compte à l'aide des fonctions prédéfinies et du pointeur \b Compte sur \b s_compte .
 * \struct s_compte
 */

struct s_compte {
    char * nom_utilisateur;
    char * cryptmdp;
    int ID_personne;
};

Compte init_compte() {
    Compte c = (Compte)malloc(sizeof(struct s_compte));
    c->nom_utilisateur = (char*)malloc(sizeof(char));
    c->cryptmdp = (char*)malloc(sizeof(char));
    c->ID_personne = 0;
    return c;
}

char * get_nom_utilisateur(Compte c) {
    return c->nom_utilisateur;
}

char * get_mdp(Compte c) {
    return c->cryptmdp;
}

int get_ID_personne(Compte c) {
    return c->ID_personne;
}

void set_nom_utilisateur(Compte c, char * nom_utilisateur) {
    c->nom_utilisateur = nom_utilisateur;
}

void set_mdp(Compte c, char * cryptmdp) {
    c->cryptmdp = cryptmdp;
}

void set_ID_personne(Compte c, int ID_personne) {
    c->ID_personne = ID_personne;
}


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