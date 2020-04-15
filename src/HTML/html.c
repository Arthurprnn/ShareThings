#include "../../include/html.h"


void AfficherObjetsParType(char* type)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("../HTML/fichier.html", "w+");
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
        sprintf(commande, "sh ../HTML/NombreDeFichier.sh %s", type); 
        system(commande);
        FILE *nbFichier = NULL;
        FILE *ListedesFichiers = NULL;

        nbFichier = fopen("../HTML/NombreFichier.txt", "r");
        ListedesFichiers = fopen("../HTML/ListeFichierjson.txt", "r");

        if ((nbFichier != NULL) && (ListedesFichiers != NULL))
        {
            int nb = 0;
            fscanf(nbFichier, "%d", &nb);

            bool have = false;

            for (int i=0; i<nb; i++)
            {
                char fichierObjet[16] = {0};
                fscanf(ListedesFichiers, "%s", fichierObjet);

                char lien[64] = {0};
                sprintf(lien, "../../data/Objets/%s/%s", type, fichierObjet);

                Objet o = lire_fichier_objet(lien);
                
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

                have = true;

                free(o);  
            }

            if (!have)
            {   
                
                fprintf(FichierHTML, "\t\t<p>\n");                               
                fprintf(FichierHTML, "\t\t\t<strong>Il n'y a aucun objet de ce type !</strong>\n");
                fprintf(FichierHTML, "\t\t</p>\n");

            }

            fprintf(FichierHTML, "\t</body></html>\n");
            system("rm ../HTML/NombreFichier.txt");
            system("rm ../HTML/ListeFichierjson.txt");
            fclose(ListedesFichiers);
            fclose(nbFichier);             
        }
        else
        {
            printf("Erreur : le fichier NombreFichier.txt ou ListeFichierjson.txt n'as pas pu être ouvert !\n");
        }
        fclose(FichierHTML);    
    }
    else
    {
        printf("Erreur : le fichier html n'a pas pu être ouvert !\n");
    }

}


void afficheObjetsPersonne(Personne p)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("../HTML/afficheObjetsPersonne.html", "w+");
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

        system("sh ../HTML/liste_objet.sh");
        int NombreObjets = get_longueur_liste_objetPersonne(p);

        bool have = false;

        for (int i=0; i<NombreObjets; i++)
        {
            int ID = get_element_liste_objet(get_liste_objetPersonne(p), i);
            char lien[64] = {0};
            sprintf(lien, "../HTML/Test/%d.json", ID);
            printf("%s\n", lien);
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

                have = true;
            }
            free(o);

        }
        
        if (!have)
        {   
                
            fprintf(FichierHTML, "\t\t<p>\n");                               
            fprintf(FichierHTML, "\t\t\t<strong>Vous n'avez aucun objet !</strong>\n");
            fprintf(FichierHTML, "\t\t</p>\n");

        }

        fprintf(FichierHTML, "\t</body></html>\n");
        system("rm ../HTML/Test/*.json");
        system("rmdir ../HTML/Test");
        fclose(FichierHTML);
    }
    else
    {
        printf("Erreur : le fichier html n'a pas pu être ouvert !\n");
    }
}


void listeDemande(Personne p)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("../HTML/afficheDemande.html", "w+");
    if (FichierHTML != NULL)
    {
        fprintf(FichierHTML, "<!DOCTYPE html>\n");
        fprintf(FichierHTML, "<html>\n");
        fprintf(FichierHTML, "\t<head>\n");
        fprintf(FichierHTML, "\t\t<meta charset=""utf-8"" />\n");
        fprintf(FichierHTML, "\t\t<title>Ma liste de Demandes</title>\n");
        fprintf(FichierHTML, "\t</head>\n");
        fprintf(FichierHTML, "\t<body>\n");
        fprintf(FichierHTML, "\t\t<p><h1> Voici la liste de vos emprunts : </h1></p>\n");

        system("sh ../HTML/liste_pret.sh");

        FILE *nbFichierPret = NULL;
        FILE *ListeFichiersPret = NULL;

        nbFichierPret = fopen("../HTML/NombreFichierPret.txt", "r");
        ListeFichiersPret = fopen("../HTML/ListeFichierPret.txt", "r");

        if ((nbFichierPret != NULL) && (ListeFichiersPret != NULL))
        {
            int nb = 0;
            fscanf(nbFichierPret, "%d", &nb);

            bool have = false;

            for (int i=0; i<nb; i++)
            {
                char fichierPret[16] = {0};
                fscanf(ListeFichiersPret, "%s", fichierPret);

                char lien[64] = {0};
                sprintf(lien, "../../data/Prets/%s", fichierPret);

                Pret pret = lire_fichier_pret(lien);
                bool isDemande = false;

                if (get_demandeurPret(pret) == get_IDPersonne(p))
                {
                    isDemande = true;
                }

                if (isDemande == true)
                {
                    
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");                               
                    fprintf(FichierHTML, "\t\t\t<strong>Prêt numéro : %d</strong>\n", get_IDPret(pret));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>ID de l'Objet : </strong>%d\n",get_objetPret(pret));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>Début du prêt : </strong>Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(get_temps_debutPret(pret)), get_moisTemps(get_temps_debutPret(pret))+1, get_anneesTemps(get_temps_debutPret(pret))+1900, get_heuresTemps(get_temps_debutPret(pret)), get_minutesTemps(get_temps_debutPret(pret)), get_secondesTemps(get_temps_debutPret(pret)));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>Fin du prêt : </strong>Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(get_temps_finPret(pret)), get_moisTemps(get_temps_finPret(pret))+1, get_anneesTemps(get_temps_finPret(pret))+1900, get_heuresTemps(get_temps_finPret(pret)), get_minutesTemps(get_temps_finPret(pret)), get_secondesTemps(get_temps_finPret(pret)));   
                    fprintf(FichierHTML, "\t\t</p>\n");                            
                    fprintf(FichierHTML, "---------------------------------------------------------------------------------------\n");             
                    fprintf(FichierHTML, "\n");
                    fprintf(FichierHTML, "\t\t</p>\n");

                    have = true;

                }
            }

            if (!have)
            {   
                
                fprintf(FichierHTML, "\t\t<p>\n");                               
                fprintf(FichierHTML, "\t\t\t<strong>Vous n'avez aucun emprunt.</strong>\n");
                fprintf(FichierHTML, "\t\t</p>\n");

            }

            fclose(ListeFichiersPret);
            fclose(nbFichierPret);
        }
        else
        {
            printf("Erreur : le fichier NombreFichierPret.txt ou ListeFichierPret.txt n'as pas pu être ouvert !\n");
        }

        system("rm ../HTML/NombreFichierPret.txt");
        system("rm ../HTML/ListeFichierPret.txt");

        fprintf(FichierHTML, "\t</body></html>\n");
        fclose(FichierHTML);
    }
    else
    {
        printf("Erreur : le fichier html n'a pas pu être ouvert !\n");
    }
}


void listePret(Personne p)
{
    FILE *FichierHTML = NULL;
    FichierHTML = fopen("../HTML/affichePret.html", "w+");
    if (FichierHTML != NULL)
    {
        fprintf(FichierHTML, "<!DOCTYPE html>\n");
        fprintf(FichierHTML, "<html>\n");
        fprintf(FichierHTML, "\t<head>\n");
        fprintf(FichierHTML, "\t\t<meta charset=""utf-8"" />\n");
        fprintf(FichierHTML, "\t\t<title>Ma liste de Prêts</title>\n");
        fprintf(FichierHTML, "\t</head>\n");
        fprintf(FichierHTML, "\t<body>\n");
        fprintf(FichierHTML, "\t\t<p><h1> Voici la liste de vos prêts : </h1></p>\n");

        system("sh ../HTML/liste_pret.sh");

        FILE *nbFichierPret = NULL;
        FILE *ListeFichiersPret = NULL;

        nbFichierPret = fopen("../HTML/NombreFichierPret.txt", "r");
        ListeFichiersPret = fopen("../HTML/ListeFichierPret.txt", "r");

        if ((nbFichierPret != NULL) && (ListeFichiersPret != NULL))
        {
            int nb = 0;
            fscanf(nbFichierPret, "%d", &nb);
        
            bool have = false;

            for (int i=0; i<nb; i++)
            {
                char fichierPret[16] = {0};
                fscanf(ListeFichiersPret, "%s", fichierPret);

                char lien[64] = {0};
                sprintf(lien, "../../data/Prets/%s", fichierPret);

                Pret pret = lire_fichier_pret(lien);
                
                system("sh ../HTML/liste_objet.sh");

                char lienObjet[64] = {0};
                sprintf(lienObjet, "../HTML/Test/%d.json", get_objetPret(pret));

                Objet o = lire_fichier_objet(lienObjet);

                if (get_ID_proprietaireObjet(o) == get_IDPersonne(p))
                {

                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");                               
                    fprintf(FichierHTML, "\t\t\t<strong>Prêt numéro : %d</strong>\n", get_IDPret(pret));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>ID de l'Objet : </strong>%d\n",get_objetPret(pret));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>Début du prêt : </strong>Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(get_temps_debutPret(pret)), get_moisTemps(get_temps_debutPret(pret))+1, get_anneesTemps(get_temps_debutPret(pret))+1900, get_heuresTemps(get_temps_debutPret(pret)), get_minutesTemps(get_temps_debutPret(pret)), get_secondesTemps(get_temps_debutPret(pret)));
                    fprintf(FichierHTML, "\t\t</p>\n");
                    fprintf(FichierHTML, "\t\t<p>\n");
                    fprintf(FichierHTML, "\t\t\t<strong>Fin du prêt : </strong>Le %02d/%02d/%4d à %d:%d:%d\n", get_joursTemps(get_temps_finPret(pret)), get_moisTemps(get_temps_finPret(pret))+1, get_anneesTemps(get_temps_finPret(pret))+1900, get_heuresTemps(get_temps_finPret(pret)), get_minutesTemps(get_temps_finPret(pret)), get_secondesTemps(get_temps_finPret(pret)));   
                    fprintf(FichierHTML, "\t\t</p>\n");                            
                    fprintf(FichierHTML, "---------------------------------------------------------------------------------------\n");             
                    fprintf(FichierHTML, "\n");
                    fprintf(FichierHTML, "\t\t</p>\n");

                    have = true;
                    
                }

            }
            if (!have)
            {   
                
                fprintf(FichierHTML, "\t\t<p>\n");                               
                fprintf(FichierHTML, "\t\t\t<strong>Vous n'avez aucun prêt.</strong>\n");
                fprintf(FichierHTML, "\t\t</p>\n");

            }

            fclose(ListeFichiersPret);
            fclose(nbFichierPret);
        }
        else
        {
            printf("Erreur : le fichier NombreFichierPret.txt ou ListeFichierPret.txt n'as pas pu être ouvert !\n");
        }

        system("rm ../HTML/NombreFichierPret.txt");
        system("rm ../HTML/ListeFichierPret.txt");

        fprintf(FichierHTML, "\t</body></html>\n");
        fclose(FichierHTML);
    }
    else
    {
        printf("Erreur : le fichier html n'a pas pu être ouvert !\n");
    }
}

bool RechercherParID(void)
{
    int ID = 0; 
    printf("Veuiller renseigner l'ID de l'objet recherché : ");
    lire_entier(&ID);
    if ((ID>=10000000) && (ID<=19999999)) 
    {

        FILE *FichierHTML = NULL;
        FichierHTML = fopen("../HTML/afficheRecherID.html", "w+");
    
        if (FichierHTML != NULL)
        {
            fprintf(FichierHTML, "<!DOCTYPE html>\n");
            fprintf(FichierHTML, "<html>\n");
            fprintf(FichierHTML, "\t<head>\n");
            fprintf(FichierHTML, "\t\t<meta charset=""utf-8"" />\n");
            fprintf(FichierHTML, "\t\t<title>Recher d'Objets par ID</title>\n");
            fprintf(FichierHTML, "\t</head>\n");
            fprintf(FichierHTML, "\t<body>\n");
            fprintf(FichierHTML, "\t\t<p><h1> Voici l'objets recherché : </h1></p>\n");

            system("sh ../HTML/liste_objet.sh");

            bool have = false;


            char lien[64] = {0};
            sprintf(lien, "../HTML/Test/%d.json", ID);

            Objet o = lire_fichier_objet(lien);

            if (get_ID_objetObjet(o) == ID)
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

                have = true;
                    
            }
            if (!have)
            {   
                
                fprintf(FichierHTML, "\t\t<p>\n");                               
                fprintf(FichierHTML, "\t\t\t<strong>Aucun objet ne correspond a cet ID !</strong>\n");
                fprintf(FichierHTML, "\t\t</p>\n");

            }

            fprintf(FichierHTML, "\t</body></html>\n");
            system("rm ../HTML/Test/*.json");
            system("rmdir ../HTML/Test");
            fclose(FichierHTML);
            return true;
        }
        else
        {
            printf("Erreur : le fichier html n'a pas pu être ouvert !\n");
            return false;
        }
    }
    else
    {
        printf("Erreur : l'entier entré n'est pas un ID ou l'ID ne correspond pas à un objet existant !\n");
        return false;
    }
}