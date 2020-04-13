#include "../../include/html.h"

int main()
{
    AfficherObjetsParType("Outil");
    //system("sh NombreDeFichier.sh Fourniture");
    Personne p = lire_fichier_personne("../../data/Users/28605078.json");
    afficheObjetsPersonne(p);
    system("x-www-browser afficheObjetsPersonne.html");
    return 0;
}