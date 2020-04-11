#include "../../include/objet.h"

/**
 * Structure \b s_objet 
 * (Structure cachée)
 * 
 * Permet la manipulation d'un \a objet à l'aide des fonctions prédéfinies et du pointeur \b Objet sur \b s_objet .
 * \struct s_objet
 */

struct s_objet {
    char * nom;
    char * description;
    char * type; /*!< Type de l'objet permettant de le catégoriser. */
    int ID_obj; /*!< ID de l'objet. */
    int ID_prop; /*!< ID du propriétaire. */
    int delai_de_pret; /*!< Exprimé en jours. */
};

void init_objet(Objet o) {
    o->nom = (char *)malloc(sizeof(char));
    o->description = (char *)malloc(sizeof(char));
    o->type = (char *)malloc(sizeof(char));
    o->ID_obj = 0;
    o->ID_prop = 0;
    o->delai_de_pret = 0;
}

Objet creer_objet(int ID_prop) {
    Objet o = (Objet)malloc(sizeof(struct s_objet));
    init_objet(o);
    printf("Entrer le nom que vous voulez donner à votre objet : ");
    char * ch = creer_chaine_de_caracteres();
    

    printf("\nEntrer une description pour votre objet: ");
    set_descriptionObjet(o, creer_chaine_de_caracteres());

    printf("\nEntrer le type d'objet: Attention ! Si le type entré n'existe pas ou est mal orthographié, le type sera automatiquement Autres\n");
    char * type = creer_chaine_de_caracteres();
    set_typeObjet(o, BonType(type));

    set_ID_objetObjet(o, creer_ID_objet(get_typeObjet(o)));
    set_ID_proprietaireObjet(o, ID_prop);

    printf("\nEntrer le délai (en jours) que vous voulez donner aux futurs demandeurs pour vous rendre cet objet : ");
    int delai = 0;
    lire_entier(&delai);
    set_delai_pretObjet(o, delai);
    set_nomObjet(o, ch);

    return o;
}

char * get_nomObjet(Objet o) {
    return o->nom;
}

char * get_descriptionObjet(Objet o) {
    return o->description;
}

char * get_typeObjet(Objet o) {
    return o->type;
}

int get_ID_objetObjet(Objet o) {
    return o->ID_obj;
}

int get_ID_proprietaireObjet(Objet o) {
    return o->ID_prop;
}

int get_delai_pretObjet(Objet o) {
    return o->delai_de_pret;
}

void set_nomObjet(Objet o, char *c) {
    strcpy(o->nom, c);
}

void set_descriptionObjet(Objet o, char *c) {
    strcpy(o->description, c);
}

void set_typeObjet(Objet o, char * type) {
    strcpy(o->type, type);
}

void set_ID_objetObjet(Objet o, int i) {
    o->ID_obj = i;
}

void set_ID_proprietaireObjet(Objet o, int i) {
    o->ID_prop = i;
}

void set_delai_pretObjet(Objet o, int i) {
    o->delai_de_pret = i;
}


char * BonType(char * type) {
    char ** tab = (char **)malloc(20*sizeof(char *));
    for (int i=0; i<20; i++) {
        tab[i] = (char *)malloc(sizeof(char));
    }
    tab[0] = "Outil";
    tab[1] = "Electronique";
    tab[2] = "Véhicule";
    tab[3] = "Musique";
    tab[4] = "Mobilier";
    tab[5] = "Nature";
    tab[6] = "Vêtement";
    tab[7] = "Jouet";
    tab[8] = "Cuisine";
    tab[9] = "Fourniture";
    tab[10] = "Produit_ménager";
    tab[11] = "Aliment";
    tab[12] = "Matériau";
    tab[13] = "Décoration";
    tab[14] = "Electrique";
    tab[15] = "Divertissement";
    tab[16] = "Pharmaceutique";
    tab[17] = "Cosmétique";
    tab[18] = "Internet";
    tab[19] = "Autres";

    int bon_indice = 19;
    for (int i=0; i<20; i++) {
        if (strcmp(type, tab[i]) == 0) {
            bon_indice = i;
        }
    }

    return tab[bon_indice];
}


bool isObjetExist(int ID_objet, char * type) {
    FILE * fichier = NULL;
    char nom[64]={0};
	sprintf(nom, "../../data/Objets/%s/%d.json", type, ID_objet);
    fichier = fopen(nom, "r");

    if (fichier == NULL) {
        return false;
    }
    return true;
}

int creer_ID_objet(char * type) {
    srand(time(NULL));
    int bon_ID = 0;
    int ID_temp = 0;
    while (isObjetExist(bon_ID, type) || bon_ID == 0) {
        ID_temp = 1;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }
        bon_ID = ID_temp;
    }
    return bon_ID;
}                                                                       /*!< Tous les ID des objets commenceront par un 1. */      


Objet lire_fichier_objet(char *lien) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *nom;
	struct json_object *description;
    struct json_object *type;
	struct json_object *ID_obj;
	struct json_object *ID_prop;
    struct json_object *delai_de_pret;

    Objet o = malloc(sizeof(Objet));
    init_objet(o);

	fp = fopen(lien,"r");
    if(fp == NULL) {
        return o;
    }
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "nom", &nom);
	json_object_object_get_ex(parsed_json, "description", &description);
    json_object_object_get_ex(parsed_json, "type", &type);
	json_object_object_get_ex(parsed_json, "ID_obj", &ID_obj);
    json_object_object_get_ex(parsed_json, "ID_prop", &ID_prop);
    json_object_object_get_ex(parsed_json, "delai_de_pret", &delai_de_pret);

	set_nomObjet(o, (char*)json_object_get_string(nom));
	set_descriptionObjet(o, (char*)json_object_get_string(description));
    set_typeObjet(o, (char*)json_object_get_string(type));
	set_ID_objetObjet(o, (int)json_object_get_int(ID_obj));
	set_ID_proprietaireObjet(o, (int)json_object_get_int(ID_prop));
	set_delai_pretObjet(o, (int)json_object_get_int(delai_de_pret));

    return o;
}



void creer_fichier_objet(Objet o) {
	FILE *fichier = NULL;
	char nom[64]={0};
	sprintf(nom, "../../data/Objets/%s/%d.json", get_typeObjet(o) ,get_ID_objetObjet(o));
	fichier = fopen(nom, "w+");

	if (fichier != NULL) {
		
		fprintf(fichier, "{\n");
		fprintf(fichier, "\t\"nom\": \"%s\",\n", get_nomObjet(o));
		fprintf(fichier, "\t\"description\": \"%s\",\n", get_descriptionObjet(o));
        fprintf(fichier, "\t\"type\": \"%s\",\n", get_typeObjet(o));
		fprintf(fichier, "\t\"ID_obj\": %d,\n", get_ID_objetObjet(o));
		fprintf(fichier, "\t\"ID_prop\": %d,\n", get_ID_proprietaireObjet(o));
		fprintf(fichier, "\t\"delai_de_pret\": %d\n", get_delai_pretObjet(o));
		fprintf(fichier, "}");

		fclose(fichier);
	} else {
		printf("Impossible d'ouvrir le fichier %s !\n", nom);
	}
}