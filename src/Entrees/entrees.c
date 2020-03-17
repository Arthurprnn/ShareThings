#include "../../include/entrees.h"

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

int getch(){
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
    } /*!< Permet d'enlever le '\n' à la fin de la chaine et le remplace par '\0'. */
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
        ch = getch();
        mdp[i] = ch;
        ch = '*' ;
        printf("%c", ch);
        i++;
    } while ((i<32) && (mdp[i-1] != '\n'));

    char *c = (char *)malloc(strlen(mdp)*sizeof(char));
    for (int j=0; j<strlen(mdp); j++) {
        c[j]=mdp[j];
    }
    return c;
}

int creer_ID_objet() {
    srand(time(NULL));
    int ID = 1;
    for (int i=0; i<7; i++) {
        ID *= 10;
        ID += rand()%(9-0)+0;
    }
    return ID;
} /*!< Tous les ID des objets commenceront par un 1. */

int creer_ID_personne() {
    srand(time(NULL));
    int ID = 2;
    for (int i=0; i<7; i++) {
        ID *= 10;
        ID += rand()%(9-0)+0;
    }
    return ID;
} /*!< Tous les ID des personnes commenceront par un 2. */