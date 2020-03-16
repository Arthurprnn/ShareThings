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