#include "../../include/users.h"
#include "../../include/objet.h"

/**
 * Structure \b s_personne 
 * (Structure cachée)
 * 
 * Permet la manipulation d'une \a personne à l'aide des fonctions prédéfinies et du pointeur \b Personne sur \b s_personne .
 * \struct s_personne
 */

struct s_personne {
    char * nom;
    char * prenom;
    int age;
    int ID; /*!< Numéro d'identification de la personne. */
    char * mail;
    int * liste_objet;
    int longueur_liste_objet;
};

Personne init_personne() {
    Personne p = (Personne)malloc(sizeof(struct s_personne));
    p->nom = (char *)malloc(sizeof(char));
    p->prenom = (char *)malloc(sizeof(char));
    p->age = 0;
    p->ID = 0;
    p->mail = (char *)malloc(sizeof(char));
    p->liste_objet = (int *)malloc(sizeof(int));
    p->longueur_liste_objet = 0;
    return p;
}

Personne creer_personne() {
    Personne p = init_personne();
    printf("Entrez votre nom : ");
    set_nomPersonne(p, creer_chaine_de_caracteres());
    printf("\nEntrez votre prénom : ");
    set_prenomPersonne(p, creer_chaine_de_caracteres());
    printf("\nEntrez une adresse mail valide: ");
    set_mailPersonne(p, creer_chaine_de_caracteres());
    
    printf("\nEntrez votre age : ");
    int age = 0;
    lire_entier(&age);

    set_agePersonne(p, age);
    set_IDPersonne(p, creer_ID_personne());

    return p;
}

char * get_nomPersonne(Personne p) {
    return p->nom;
}

char * get_prenomPersonne(Personne p) {
    return p->prenom;
}

int get_agePersonne(Personne p) {
    return p->age;
}

int get_IDPersonne(Personne p) {
    return p->ID;
}

char * get_mailPersonne(Personne p) {
    return p->mail;
}

int * get_liste_objetPersonne(Personne p) {
    return p->liste_objet;
}

int get_longueur_liste_objetPersonne(Personne p) {
    return p->longueur_liste_objet;
}

int get_element_liste_objet(int *liste, int indice) {
    return liste[indice];
}

void set_nomPersonne(Personne p, char *c) {
    p->nom = c;
}

void set_prenomPersonne(Personne p, char *c) {
    p->prenom = c;
}

void set_agePersonne(Personne p, int i) {
    p->age = i;
}

void set_IDPersonne(Personne p, int i) {
    p->ID = i;
}

void set_mailPersonne(Personne p, char *c) {
    p->mail = c;
}

void set_liste_objetPersonne(Personne p, int *liste) {
    p->liste_objet = liste;
}

void set_longueur_liste_objetPersonne(Personne p, int longueur) {
    p->longueur_liste_objet = longueur;
}

void set_element_liste_objet(int *liste, int indice, int element) {
    liste[indice] = element;
}



void add_objet_dans_liste_objet(Personne p, Objet o) {
    int *new_liste = (int*)malloc((get_longueur_liste_objetPersonne(p)+1)*sizeof(int));
    int *liste = get_liste_objetPersonne(p);

    for (int i=0; i<get_longueur_liste_objetPersonne(p); i++) {
        new_liste[i] = liste[i];
    }

    new_liste[get_longueur_liste_objetPersonne(p)] = get_ID_objetObjet(o);

    set_liste_objetPersonne(p, new_liste);
    set_longueur_liste_objetPersonne(p, get_longueur_liste_objetPersonne(p)+1);
}

int creer_ID_personne() {
    srand(time(NULL));
    int bon_ID = 0;
    int ID_temp = 0;
    while (isPersonneExist(ID_temp) || bon_ID == 0) {
        ID_temp = 2;
        for (int i=0; i<7; i++) {
            ID_temp *= 10;
            ID_temp += rand()%(9-0)+0;
        }
        bon_ID = ID_temp;
    }
    return bon_ID;
}                                                   /*!< Tous les ID des objets commenceront par un 2. */

bool isPersonneExist(int ID_personne) {
    FILE * fichier = NULL;
    char nom[32]={0};
	sprintf(nom, "../../data/Users/%d.json", ID_personne);
    fichier = fopen(nom, "r");

    if (fichier == NULL) {
        return false;
    }
    return true;
}


Personne lire_fichier_personne(char *lien) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *nom;
	struct json_object *prenom;
	struct json_object *age;
	struct json_object *ID;
    struct json_object *mail;
	struct json_object *liste_objet;
	struct json_object *longueur_liste_objet;

	struct json_object *listeObjet;

	size_t n_liste_objet;
	size_t i;

    Personne p = init_personne();

	fp = fopen(lien,"r");
    if(fp == NULL) {
        return p;
    }
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "nom", &nom);
	json_object_object_get_ex(parsed_json, "prenom", &prenom);
	json_object_object_get_ex(parsed_json, "age", &age);
    json_object_object_get_ex(parsed_json, "ID", &ID);
    json_object_object_get_ex(parsed_json, "mail", &mail);
	json_object_object_get_ex(parsed_json, "liste_objet", &liste_objet);
	json_object_object_get_ex(parsed_json, "longueur_liste_objet", &longueur_liste_objet);

	set_nomPersonne(p, (char*)json_object_get_string(nom));
	set_prenomPersonne(p, (char*)json_object_get_string(prenom));
	set_agePersonne(p, (int)json_object_get_int(age));
	set_IDPersonne(p, (int)json_object_get_int(ID));
	set_mailPersonne(p, (char*)json_object_get_string(mail));
	set_longueur_liste_objetPersonne(p, (int)json_object_get_int(longueur_liste_objet));

	n_liste_objet = json_object_array_length(liste_objet);
	int * liste = (int *)malloc(sizeof(int));

	for (i=0; i<n_liste_objet; i++) {
		int ID;
		listeObjet = json_object_array_get_idx(liste_objet, i);
		ID = (int)json_object_get_int(listeObjet);
		set_element_liste_objet(liste, i, ID);
	}

	set_liste_objetPersonne(p, liste);
    return p;
}



void creer_fichier_personne(Personne p) {
	FILE *fichier = NULL;
	char nom[32]={0};
	sprintf(nom, "../../data/Users/%d.json", get_IDPersonne(p));
	fichier = fopen(nom, "w+");

	if (fichier != NULL) {
		
		fprintf(fichier, "{\n");
		fprintf(fichier, "\t\"nom\": \"%s\",\n", get_nomPersonne(p));
		fprintf(fichier, "\t\"prenom\": \"%s\",\n", get_prenomPersonne(p));
		fprintf(fichier, "\t\"age\": %d,\n", get_agePersonne(p));
		fprintf(fichier, "\t\"ID\": %d,\n", get_IDPersonne(p));
		fprintf(fichier, "\t\"mail\": \"%s\",\n", get_mailPersonne(p));
		fprintf(fichier, "\t\"liste_objet\": [");

		if (get_longueur_liste_objetPersonne(p) > 0) {
			
			for (int i=0; i<get_longueur_liste_objetPersonne(p)-1; i++) {
				fprintf(fichier, "%d, ", get_element_liste_objet(get_liste_objetPersonne(p), i));
			}
			fprintf(fichier, "%d],\n", get_element_liste_objet(get_liste_objetPersonne(p), get_longueur_liste_objetPersonne(p)-1));

		} else {
			fprintf(fichier, "],\n");
		}
		fprintf(fichier, "\t\"longueur_liste_objet\": %d\n", get_longueur_liste_objetPersonne(p));
		fprintf(fichier, "}");

		fclose(fichier);
	} else {
		printf("Impossible d'ouvrir le fichier %s !\n", nom);
	}
}