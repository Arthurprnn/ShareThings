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

Pret creer_pret(int ID_demandeur) {
    Pret p = init_pret();
    int ID_objet = 0;
    bool rester = true;
    char * type;

    while (rester == true) {
        printf("Entrez l'ID de l'objet que vous voulez emprunter : ");
        lire_entier(&ID_objet);
        printf("Entrez le type de l'objet a emprunter: Attention, si le type est incorrect, l'objet sera recherché dans le type Autres !\nType : ");
        type = creer_chaine_de_caracteres();
        if (isObjetExist(ID_objet, BonType(type)) == true) {
            rester = false;
        } else {
            printf("Attention: l'ID \"%d\" n'existe pas ! Veuillez saisir un ID d'objet existant.\n", ID_objet);
        }
    }

    set_objetPret(p, ID_objet);
    set_demandeurPret(p, ID_demandeur);
    set_IDPret(p, creer_ID_pret());

    time_t debut = time(&debut);
    Temps timeInfos = creer_temps(debut);
    set_temps_debutPret(p, timeInfos);

    FILE *fp;
	char buffer[1024];
    char lien[32]={0};
	sprintf(lien, "../../data/Objets/%s/%d.json", BonType(type), ID_objet);
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