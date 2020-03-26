#include "../../include/fichier.h"

Objet lire_fichier_objet(char *lien) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *nom;
	struct json_object *description;
	struct json_object *ID_obj;
	struct json_object *ID_prop;
    struct json_object *delai_de_pret;

    Objet o = init_objet();

	fp = fopen(lien,"r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "nom", &nom);
	json_object_object_get_ex(parsed_json, "description", &description);
	json_object_object_get_ex(parsed_json, "ID_obj", &ID_obj);
    json_object_object_get_ex(parsed_json, "ID_prop", &ID_prop);
    json_object_object_get_ex(parsed_json, "delai_de_pret", &delai_de_pret);

	set_nomObjet(o, (char*)json_object_get_string(nom));
	set_descriptionObjet(o, (char*)json_object_get_string(description));
	set_ID_objetObjet(o, (int)json_object_get_int(ID_obj));
	set_ID_proprietaireObjet(o, (int)json_object_get_int(ID_prop));
	set_delai_pretObjet(o, (int)json_object_get_int(delai_de_pret));

    return o;
}



void creer_fichier_objet(Objet o) {
	FILE *fichier = NULL;
	char nom[32]={0};
	sprintf(nom, "../../data/Objets/%d.json", get_ID_objetObjet(o));
	fichier = fopen(nom, "w+");

	if (fichier != NULL) {
		
		fprintf(fichier, "{\n");
		fprintf(fichier, "\t\"nom\": \"%s\",\n", get_nomObjet(o));
		fprintf(fichier, "\t\"description\": \"%s\",\n", get_descriptionObjet(o));
		fprintf(fichier, "\t\"ID_obj\": %d,\n", get_ID_objetObjet(o));
		fprintf(fichier, "\t\"ID_prop\": %d,\n", get_ID_proprietaireObjet(o));
		fprintf(fichier, "\t\"delai_de_pret\": %d\n", get_delai_pretObjet(o));
		fprintf(fichier, "}");

		fclose(fichier);
	} else {
		printf("Impossible d'ouvrir le fichier %s !\n", nom);
	}
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