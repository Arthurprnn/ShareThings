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

    while (rester == true) {
        printf("Entrez l'ID de l'objet que vous voulez emprunter : ");
        scanf("%d", &ID_objet);
        if (existe_objet(ID_objet) == true) {
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
	sprintf(lien, "../../data/Objets/%d.json", ID_objet);
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
}                                                                    /*!< Tous les ID des objets commenceront par un 3. */