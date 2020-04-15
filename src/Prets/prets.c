#include "../../include/prets.h"

/**
 * Structure nécessaire pour créer un prêt.
 * Elle va servir à prendre les données utiles pour manipuler les objets prétées entre utilisateurs.
 */

struct s_pret {
    Temps debut;
    Temps fin;
    int ID_objet;
    int ID_demandeur;
    int ID_pret;
};

Pret init_pret() {
    Pret p = (Pret)malloc(sizeof(struct s_pret));
    p->debut = init_temps();
    p->fin = init_temps();
    p->ID_objet = 0;
    p->ID_demandeur = 0;
    p->ID_pret = 0;
    return p;
}

Pret creer_pret(int ID_demandeur, int ID_objet) {
    Pret p = init_pret();

    set_objetPret(p, ID_objet);
    set_demandeurPret(p, ID_demandeur);
    set_IDPret(p, creer_ID_pret());

    time_t debut = time(&debut);
    Temps timeInfos = creer_temps(debut);
    set_temps_debutPret(p, timeInfos);

    FILE *fp;
	char buffer[1024];
    char lien[32]={0};
	sprintf(lien, "../Prets/Test/%d.json", ID_objet);
	struct json_object *parsed_json;
	struct json_object *delai_de_pret;
    fp = fopen(lien,"r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);
    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "delai_de_pret", &delai_de_pret);
    int delai = (int)json_object_get_int(delai_de_pret);

    time_t fin = time(&fin);
    fin = fin + delai*24*60*60;
    Temps temps_fin = creer_temps(fin);
    set_temps_finPret(p, temps_fin);

    return p;
}

Temps get_temps_debutPret(Pret pret) {
    return pret->debut;
}

Temps get_temps_finPret(Pret pret) {
    return pret->fin;
}

int get_objetPret(Pret pret) {
    return pret->ID_objet;
}

int get_demandeurPret(Pret pret) {
    return pret->ID_demandeur;
}

int get_IDPret(Pret pret) {
    return pret->ID_pret;
}

void set_temps_debutPret(Pret pret, Temps time) {
    pret->debut = time;
}

void set_temps_finPret(Pret pret, Temps time) {
    pret->fin = time;
}

void set_objetPret(Pret pret, int ID_objet) {
    pret->ID_objet = ID_objet;
}

void set_demandeurPret(Pret pret, int ID_demandeur) {
    pret->ID_demandeur = ID_demandeur;
}

void set_IDPret(Pret pret, int ID_pret) {
    pret->ID_pret = ID_pret;
}


int creer_ID_pret() {
    srand(time(NULL));
    int bon_ID = 0;
    int ID_temp = 0;
    while (isPretExist(ID_temp) || bon_ID == 0) {
        ID_temp = 3;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }
        bon_ID = ID_temp;
    }
    return bon_ID;
}                                                                    /*!< Tous les ID des objets commenceront par un 3. */

bool isPretExist(int ID_pret) {
    FILE * fichier = NULL;
    char nom[32]={0};
	sprintf(nom, "../../data/Prets/%d.json", ID_pret);
    fichier = fopen(nom, "r");

    if (fichier == NULL) {
        return false;
    }

    fclose(fichier);
    return true;
}

Pret lire_fichier_pret(char *lien) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *debut_du_pret;
	struct json_object *fin_du_pret;
	struct json_object *ID_objet;
	struct json_object *ID_demandeur;
    struct json_object *ID_pret;

    Pret p = init_pret();

	fp = fopen(lien,"r");
    if(fp == NULL) {
        return p;
    }
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "debut_du_pret", &debut_du_pret);
	json_object_object_get_ex(parsed_json, "fin_du_pret", &fin_du_pret);
	json_object_object_get_ex(parsed_json, "ID_objet", &ID_objet);
    json_object_object_get_ex(parsed_json, "ID_demandeur", &ID_demandeur);
    json_object_object_get_ex(parsed_json, "ID_pret", &ID_pret);

	long int debut = (long int)json_object_get_int(debut_du_pret);
	long int fin = (long int)json_object_get_int(fin_du_pret);
	Temps d = creer_temps(debut);
	Temps f = creer_temps(fin);

	set_temps_debutPret(p, d);
	set_temps_finPret(p, f);

	set_objetPret(p, (int)json_object_get_int(ID_objet));
	set_demandeurPret(p, (int)json_object_get_int(ID_demandeur));
	set_IDPret(p, (int)json_object_get_int(ID_pret));

    return p;
}



void creer_fichier_pret(Pret p) {
	long int debut = creer_secondes_depuis_1970(get_temps_debutPret(p));
	long int fin = creer_secondes_depuis_1970(get_temps_finPret(p));
	FILE *fichier = NULL;
	char nom[32]={0};
	sprintf(nom, "../../data/Prets/%d.json", get_IDPret(p));
	fichier = fopen(nom, "w+");

	if (fichier != NULL) {
		
		fprintf(fichier, "{\n");
		fprintf(fichier, "\t\"debut_du_pret\": %ld,\n", debut);
		fprintf(fichier, "\t\"fin_du_pret\": %ld,\n", fin);
		fprintf(fichier, "\t\"ID_objet\": %d,\n", get_objetPret(p));
		fprintf(fichier, "\t\"ID_demandeur\": %d,\n", get_demandeurPret(p));
		fprintf(fichier, "\t\"ID_pret\": %d\n", get_IDPret(p));
		fprintf(fichier, "}");

		fclose(fichier);
	} else {
		printf("Impossible d'ouvrir le fichier %s !\n", nom);
	}
}

void demander_objet(Personne p)
{
    int ID = 0; 
    printf("Veuiller renseigner l'ID de l'objet recherché : ");
    lire_entier(&ID);
    if ((ID>=10000000) && (ID<=19999999)) 
    {
        system("sh ../Prets/liste_objets.sh");

        char lien[64] = {0};
        sprintf(lien, "../Prets/Test/%d.json", ID);

        Objet o = lire_fichier_objet(lien);

        if (get_ID_objetObjet(o) != 0)
        {
            if (get_ID_proprietaireObjet(o) != get_IDPersonne(p))
            {
                bool isInList = false;           
                int *liste = get_liste_objetPersonne(p);
                
                for (int i=0; i<get_longueur_liste_objetPersonne(p); i-=-1)
                {
                    if (liste[i] == ID)
                    {
                        isInList = true;
                    }
                }
                if (!isInList)
                {
                    system("sh ../Prets/liste_pret.sh");
                    
                    FILE * NombreFichierPret = NULL;
                    FILE * ListeFichierPret = NULL;
                    NombreFichierPret = fopen("../Prets/NombreFichierPret.txt", "r");
                    ListeFichierPret = fopen("../Prets/ListeFichierPret.txt", "r");

                    if ((NombreFichierPret != NULL) && (ListeFichierPret != NULL))
                    {
                        int nb = 0;
                        fscanf(NombreFichierPret, "%d", &nb);

                        bool isPrete = false;

                        for (int i=0; i<nb; i++)
                        {
                            char fichierPret[16] = {0};
                            fscanf(ListeFichierPret, "%s", fichierPret);

                            char lien[64] = {0};
                            sprintf(lien, "../../data/Prets/%s", fichierPret);

                            Pret pret = lire_fichier_pret(lien);

                            if (get_objetPret(pret) == ID)
                            {
                                isPrete = true;
                            }
                            
                        }

                        if (!isPrete)
                        {
                            char lienPreteur[64] = {0};
                            sprintf(lienPreteur, "../../data/Users/%d.json", get_ID_proprietaireObjet(o));

                            Personne preteur = lire_fichier_personne(lienPreteur);
                            swap(p, preteur, o);
                            creer_fichier_personne(p);
                            creer_fichier_personne(preteur);

                            Pret truePret = creer_pret(get_IDPersonne(p), ID);
                            creer_fichier_pret(truePret);

                            printf("La transaction %d de l'objet %d est effectuée !\n", get_IDPret(truePret), ID);


                        }
                        else
                        {
                            printf("Attention : l'objet est déjà prêté !\n");
                        }
                        
                        fclose(NombreFichierPret);
                        fclose(ListeFichierPret);
                    }
                    else
                    {
                        printf("Erreur : impossible d'ouvrir NombreFichierPret.txt ou ListeFichierPret.txt !\n");
                    }
                }
                else
                {
                    printf("Attention : vous avez déjà emprunté l'objet !\n");
                }
            }   
            else 
            {
                printf("Attention : l'objet vous appartient, vous ne pouvez pas l'emprunter !\n");
            }
        }
        else
        {
            printf("Erreur : l'ID ne correspond pas à un objet existant !\n");
        }

        system("rm ../Prets/Test/*.json");
        system("rmdir ../Prets/Test");
    }
    else
    {
        printf("Erreur : l'entier entré n'est pas un ID ou l'ID ne correspond pas à un objet existant !\n");
    }
}

void rendre_objet(Personne p)
{
    int ID = 0; 
    printf("Veuiller renseigner l'ID de l'objet à rendre : ");
    lire_entier(&ID);
    if ((ID>=10000000) && (ID<=19999999)) 
    {
        int *liste = get_liste_objetPersonne(p);
        bool isInList = false;

        for (int i=0; i<get_longueur_liste_objetPersonne(p); i++)
        {
            if (liste[i] == ID)
            {
                isInList = true;
            }
        }
        if (isInList)
        {
            system("sh ../Prets/liste_objets.sh");

            char lien[64] = {0};
            sprintf(lien, "../Prets/Test/%d.json", ID);

            Objet o = lire_fichier_objet(lien);

            if (get_ID_proprietaireObjet(o) != get_IDPersonne(p))
            {
                system("sh ../Prets/liste_pret.sh");
                    
                FILE * NombreFichierPret = NULL;
                FILE * ListeFichierPret = NULL;
                NombreFichierPret = fopen("../Prets/NombreFichierPret.txt", "r");
                ListeFichierPret = fopen("../Prets/ListeFichierPret.txt", "r");

                if ((NombreFichierPret != NULL) && (ListeFichierPret != NULL))
                {
                    int nb = 0;
                    fscanf(NombreFichierPret, "%d", &nb);

                    int IDpret = 0;

                    for (int i=0; i<nb; i++)
                    {
                        char fichierPret[16] = {0};
                        fscanf(ListeFichierPret, "%s", fichierPret);

                        char lien[64] = {0};
                        sprintf(lien, "../../data/Prets/%s", fichierPret);

                        Pret pret = lire_fichier_pret(lien);

                        if (get_objetPret(pret) == ID)
                        {
                            IDpret = get_IDPret(pret);
                        }
                            
                    }

                    char lienProp[64] = {0};
                    sprintf(lienProp, "../../data/Users/%d.json", get_ID_proprietaireObjet(o));
                    Personne proprietaire = lire_fichier_personne(lienProp);
                    swap(proprietaire, p, o);

                    creer_fichier_personne(p);
                    creer_fichier_personne(proprietaire);

                    char commande[64] = {0};
                    sprintf(commande, "rm ../../data/Prets/%d.json", IDpret);
                    system(commande);

                    printf("L'objet a été rendu avec succes !\n");

                    fclose(NombreFichierPret);
                    fclose(ListeFichierPret);
                }
                else
                {
                    printf("Erreur : impossible d'ouvrir NombreFichierPret.txt ou ListeFichierPret.txt !\n");
                }
                
            }
            else
            {
                printf("Attention : cet objet vous appartient, vous ne pouvez pas le rendre !\n");
            }
            


            system("rm ../Prets/Test/*.json");
            system("rmdir ../Prets/Test");
        }
        else
        {
            printf("Attention : vous n'avez pas emprunté cet objet !\n");
        }
    
    }
    else
    {
        printf("Erreur : l'entier entré n'est pas un ID ou l'ID ne correspond pas à un objet existant !\n");
    }
}