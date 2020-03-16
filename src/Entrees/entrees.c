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
    printf("Entree une chaine de caractere : ");
    scanf("%s", temp);
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
    }
    while ((i<32) && (mdp[i-1] != '\n'));
    char *c = (char *)malloc(strlen(mdp)*sizeof(char));
    for (int i=0; i<strlen(mdp); i++) {
        c[i]=mdp[i];
    }
    return c;
}