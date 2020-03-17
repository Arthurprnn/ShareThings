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