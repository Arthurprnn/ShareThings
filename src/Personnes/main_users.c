#include "../../include/users.h"

int main(int argc, char *argv[]) {

    Personne p = creer_personne();
    printf("%s\n", get_mailPersonne(p));
    
    return 0;
}