#include "../../include/html.h"


void AfficherObjetsParType(char* type)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("fichier.html", "w+");
    if (FichierHTML != NULL)
    {
        fprintf(FichierHTML, "<!DOCTYPE html>\n");
        fprintf(FichierHTML, "<html>\n");
        fprintf(FichierHTML, "\t<head>\n");
        fprintf(FichierHTML, "\t\t<meta charset=""utf-8"" />\n");
        fprintf(FichierHTML, "\t\t<title>Recherche d'Objets</title>\n");
        fprintf(FichierHTML, "\t</head>\n");
        fprintf(FichierHTML, "\t<body>\n");
        fprintf(FichierHTML, "\t\t<p><strong>Voici la liste des objets disponible :</strong></p>\n");

        char commande[64] = {0};
        sprintf(commande, "sh NombreDeFichier.sh %s", type); 
        system(commande);
        FILE *nbFichier = NULL;
        FILE *ListedesFichiers = NULL;

        nbFichier = fopen("NombreFichier.txt", "r");
        ListedesFichiers = fopen("ListeFichierjson.txt", "r");

        if ((nbFichier != NULL) && (nbFichier != NULL))
        {
            int nb = 0;
            fscanf(nbFichier, "%d", &nb);

            for (int i=0; i<nb; i++)
            {
                char fichierObjet[16] = {0};
                fscanf(ListedesFichiers, "%s", fichierObjet);

                char lien[64] = {0};
                sprintf(lien, "../../data/Objets/%s/%s", type, fichierObjet);

                Objet o = lire_fichier_objet(lien);
                printf("%s\n", get_nomObjet(o));
                
                fprintf(FichierHTML, "\t\t<p>\n");
                fprintf(FichierHTML, "\t\t\t%s\n", get_nomObjet(o));
                fprintf(FichierHTML, "\t\t\t%s\n", get_descriptionObjet(o));
                fprintf(FichierHTML, "\t\t\t%d\n", get_ID_objetObjet(o));
                fprintf(FichierHTML, "\t\t\t%d\n", get_delai_pretObjet(o));            
                fprintf(FichierHTML, "\t\t</p>\n");
                fprintf(FichierHTML, "\n");

                free(o);  
            }
            fprintf(FichierHTML, "\t</body>\n");
            system("rm NombreFichier.txt");
            system("rm ListeFichierjson.txt"); 
        }
        else
        {
            printf("Erreur : le fichier NombreFichier.txt ou ListeFichierjson.txt n'as pas pu être ouvert\n");
        }
    }
    else
    {
        printf("Erreur : le fichier html n'as pas pu être ouvert\n");
    }
}


void afficheObjetsPersonne(Personne p)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("afficheObjetsPersonne.html", "w+");
    if (FichierHTML != NULL)
    {
        fprintf(FichierHTML, "<!DOCTYPE html>\n");
        fprintf(FichierHTML, "<html>\n");
        fprintf(FichierHTML, "\t<head>\n");
        fprintf(FichierHTML, "\t\t<meta charset=""utf-8"" />\n");
        fprintf(FichierHTML, "\t\t<title>Ma liste d'Objets</title>\n");
        fprintf(FichierHTML, "\t</head>\n");
        fprintf(FichierHTML, "\t<body>\n");
        fprintf(FichierHTML, "\t\t<p><h1> Voici la liste de vos objets : </h1></p>\n");

        system("sh liste_objet.sh");
        int NombreObjets = get_longueur_liste_objetPersonne(p);
        for (int i=0; i<NombreObjets; i++)
        {
            int ID = get_element_liste_objet(get_liste_objetPersonne(p), i);
            char lien[64] = {0};
            sprintf(lien, "./Test/%d.json", ID);
            
            Objet o = lire_fichier_objet(lien);
            
            if (get_ID_objetObjet(o) != 0)
            {
                fprintf(FichierHTML, "\t\t<p>\n");
                fprintf(FichierHTML, "\t\t<p>\n");                               
                fprintf(FichierHTML, "\t\t\t<strong>Nom de l'objet : </strong>%s\n", get_nomObjet(o));
                fprintf(FichierHTML, "\t\t</p>\n");
                fprintf(FichierHTML, "\t\t<p>\n");
                fprintf(FichierHTML, "\t\t\t<strong>Description de l'objet : </strong>%s\n", get_descriptionObjet(o));
                fprintf(FichierHTML, "\t\t</p>\n");
                fprintf(FichierHTML, "\t\t<p>\n");
                fprintf(FichierHTML, "\t\t\t<strong>ID de l'objet : </strong>%d\n", get_ID_objetObjet(o));
                fprintf(FichierHTML, "\t\t</p>\n");
                fprintf(FichierHTML, "\t\t<p>\n");   
                fprintf(FichierHTML, "\t\t\t<strong>Nombre de jours disponible : </strong>%d\n", get_delai_pretObjet(o));
                fprintf(FichierHTML, "\t\t</p>\n");                            
                fprintf(FichierHTML, "---------------------------------------------------------------------------------------\n");             
                fprintf(FichierHTML, "\n");
                fprintf(FichierHTML, "\t\t</p>\n");
            }
            free(o);

        }
        fprintf(FichierHTML, "\t</body>\n");
        system("rm ./Test/*.json");
        system("rmdir ./Test");
    }
    else
    {
        printf("Erreur : le fichier html n'as pas pu être ouvert\n");
    }
}