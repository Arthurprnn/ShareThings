#include "../../include/administration.h"

/**
 * Structure \b s_compte 
 * (Structure cachée)
 * 
 * Permet la manipulation d'un \a compte à l'aide des fonctions prédéfinies et du pointeur \b Compte sur \b s_compte .
 * \struct s_compte
 */

struct s_compte {
    char * nom_utilisateur;
    char * cryptmdp;
    int ID_personne;
};

Compte init_compte() {
    Compte c = (Compte)malloc(sizeof(struct s_compte));
    c->nom_utilisateur = (char*)malloc(sizeof(char));
    c->cryptmdp = (char*)malloc(sizeof(char));
    c->ID_personne = 0;
    return c;
}

int creer_compte(Compte c, Personne p) {
    printf("Bienvenue sur ShareThings !\n\n");
    char * nom_utilisateur = (char*)malloc(sizeof(char));
    nom_utilisateur = forcerNomUtilisateurCorrect();
    while (isCompteExist(nom_utilisateur)) {
        printf("Désolé, ce nom d'utilisateur est déjà pris, veuillez en choisir un autre :\n");
        nom_utilisateur = "";
        nom_utilisateur = forcerNomUtilisateurCorrect();
    }

    printf("\n");
    char * mdp = creer_mot_de_passe();
    printf("\nVeuillez entrer de nouveau votre mot de passe :\n");
    char * verif_mdp = creer_mot_de_passe();
    while (!isMemeChaine(mdp, verif_mdp) || (strlen(mdp) != 7)) {
        printf("\nErreur: vous n'avez pas entré les même mots de passe ou mot de passe ne contient pas 6 caractères !\n\nEssayez à nouveau:\n\n");
        mdp = "";
        verif_mdp = "";
        mdp = creer_mot_de_passe();
        printf("\nVeuillez saisir de nouveau votre mot de passe :\n");
        verif_mdp = creer_mot_de_passe();
    }
    char * mdpcrypt = chiffrer_mot_de_passe(mdp);
    printf("\n");

    printf("\nEntrez votre nom : ");
    set_nomPersonne(p, creer_chaine_de_caracteres());
    printf("Entrez votre prénom : ");
    set_prenomPersonne(p, creer_chaine_de_caracteres());
    printf("Entrez une adresse mail valide: ");
    set_mailPersonne(p, creer_chaine_de_caracteres());
    printf("Entrez votre age : ");
    int age = 0;
    lire_entier(&age);
    set_agePersonne(p, age);
    set_IDPersonne(p, creer_ID_personne());

    set_nom_utilisateur(c, nom_utilisateur);
    set_mdp(c, mdpcrypt);
    set_ID_personne(c, get_IDPersonne(p));

    return 0;
}

char * get_nom_utilisateur(Compte c) {
    return c->nom_utilisateur;
}

char * get_mdp(Compte c) {
    return c->cryptmdp;
}

int get_ID_personne(Compte c) {
    return c->ID_personne;
}

void set_nom_utilisateur(Compte c, char * nom_utilisateur) {
    c->nom_utilisateur = nom_utilisateur;
}

void set_mdp(Compte c, char * cryptmdp) {
    c->cryptmdp = cryptmdp;
}

void set_ID_personne(Compte c, int ID_personne) {
    c->ID_personne = ID_personne;
}


void viderBuffer(){                                                      /*!< Permet de vider le buffer */
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

int getch(){                                                             /*!< Permet de recuperer un caractère rentré au clavier sans avoir à appuyer sur entrée. */
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char * creer_mot_de_passe(){
    char mdp[32], ch;
    printf("Veuillez saisir votre mot de passe : Attention le mot de passe doit contenir 6 caractères !\nMdp: ");
    int i=0;

    do {
        ch = getch();                                                   /*!< On récupère un caractère saisie, sans que l'itilisateur ait appuyé sur entrée. */
        mdp[i] = ch;                                                    
        ch = '*' ;                                                      /*!< On remplace le caractère saisie par une étoile.*/
        printf("%c", ch);                                               /*!< Et on affiche l'étoile.*/
        i++;
    } while ((i<32) && (mdp[i-1] != '\n'));                             /*!< Tant que le mot de passe est inférieur à 32 et que l'on ne détecte pas que l'utilisateur appuie sur entrée. */

    char *c = (char *)malloc(strlen(mdp)*sizeof(char));                 /*!< On réserve en mémoire une taille adaptée à la longueur du mot de passe. */
    strcpy(c, mdp);
    return c;
}

char * chiffrer_mot_de_passe(char * mdp ){                                   /*!< Nombre de séquences nécessaires. */
    char salt[]="la";
    char * cryptmdp = (char*)malloc(22*sizeof(char));
    cryptmdp = crypt(mdp, salt);
    return cryptmdp;                                                    /*!< On return le tableau contenant le mot de passe chiffré. */
}

void changer_mot_de_passe(void)
{
    printf("\nVeuillez rentrer un ");
    char * nomUtilisateur = forcerNomUtilisateurCorrect();
    char lienCompte[64] = {0};
    sprintf(lienCompte, "../../data/Comptes/%s.json", nomUtilisateur);

    Compte c = lire_fichier_compte(lienCompte);
    if (get_ID_personne(c) != 0)
    {
        char * mdp = creer_mot_de_passe();
        printf("\nVeuillez entrer de nouveau votre mot de passe :\n");
        char * verif_mdp = creer_mot_de_passe();
        while (!isMemeChaine(mdp, verif_mdp) || (strlen(mdp) != 7)) 
        {
            printf("\nErreur: vous n'avez pas entré les même mots de passe ou mot de passe ne contient pas 6 caractères !\n\nEssayez à nouveau:\n\n");
            mdp = "";
            verif_mdp = "";
            mdp = creer_mot_de_passe();
            printf("\nVeuillez saisir de nouveau votre mot de passe :\n");
            verif_mdp = creer_mot_de_passe();
        }
        char * mdpcrypt = chiffrer_mot_de_passe(mdp);
        printf("\n");

        set_mdp(c, mdpcrypt);
        creer_fichier_compte(c);
    }
    else
    {
        printf("Erreur : impossible d'ouvrir le compte au nom \"%s\" !\n", nomUtilisateur);
    }
}

void changer_donnees_utilisateur(int donnees)
{
    printf("\nVeuillez rentrer l'ID de la personne à modifier : ");
    int ID = 0;
    lire_entier(&ID);
    if ((ID>=20000000) && (ID<=29999999)) 
    {
        char lien[64] = {0};
        sprintf(lien, "../../data/Users/%d.json", ID);

        Personne p = lire_fichier_personne(lien);
        if (get_IDPersonne(p) != 0)
        {
            char * nom;
            char * prenom;
            char * mail;
            int age = 0;
            switch(donnees)
            {
                /*!< Nom */
                case 0 :
                    printf("Veuillez entrer le nouveau nom : ");
                    nom = creer_chaine_de_caracteres();
                    set_nomPersonne(p, nom);
                    break;

                /*!< Prenom */
                case 1 :
                    printf("Veuillez entrer le nouveau prenom : ");
                    prenom = creer_chaine_de_caracteres();
                    set_prenomPersonne(p, prenom);
                    break;

                /*!< Mail */
                case 2 :
                    printf("Veuillez entrer le nouveau mail : ");
                    mail = creer_chaine_de_caracteres();
                    set_mailPersonne(p, mail);
                    break;

                /*!< Age */
                case 3 :
                    printf("Veuillez entrer le nouvel âge : ");               
                    lire_entier(&age);
                    set_agePersonne(p, age);        
                    break;

                default :
                    break;
            }
            printf("\n");
            creer_fichier_personne(p);
        }
        else
        {
            printf("\nErreur : l'ID entré n'existe pas !\n");
        }
                                
    } 
    else 
    {
        printf("\nL'entier entré n'est pas un ID de personne !\n");
    }
}

bool isCompteExist(char * nom_utilisateur) {
    FILE *fichier = NULL;
	char nom[64]={0};
	sprintf(nom, "../../data/Comptes/%s.json", nom_utilisateur);
	fichier = fopen(nom, "r");

	if (fichier != NULL) {
        fclose(fichier);
        return true;
    }
    return false;
}


Compte lire_fichier_compte(char *lien) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *nom_utilisateur;
	struct json_object *mdp;
	struct json_object *ID;

    Compte c = init_compte();

	fp = fopen(lien,"r");

    if(fp == NULL) {
        return c;
    }
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "nom_utilisateur", &nom_utilisateur);
	json_object_object_get_ex(parsed_json, "mdp", &mdp);
	json_object_object_get_ex(parsed_json, "ID", &ID);

	set_nom_utilisateur(c, (char*)json_object_get_string(nom_utilisateur));
	set_mdp(c, (char*)json_object_get_string(mdp));
	set_ID_personne(c, (int)json_object_get_int(ID));

    return c;
}

void creer_fichier_compte(Compte c) {
	FILE *fichier = NULL;
	char nom[32]={0};
	sprintf(nom, "../../data/Comptes/%s.json", get_nom_utilisateur(c));
	fichier = fopen(nom, "w+");

	if (fichier != NULL) {
		
		fprintf(fichier, "{\n");
		fprintf(fichier, "\t\"nom_utilisateur\": \"%s\",\n", get_nom_utilisateur(c));
		fprintf(fichier, "\t\"mdp\": \"%s\",\n", get_mdp(c));
		fprintf(fichier, "\t\"ID\": %d\n", get_ID_personne(c));
		fprintf(fichier, "}");

		fclose(fichier);
	} else {
		printf("Impossible d'ouvrir le fichier %s !\n", nom);
	}
}

bool supprimer_compte(Compte c) {
    system("sh ../Administration/liste_objets.sh");
    char lienPersonne[64] = {0};
    sprintf(lienPersonne, "../../data/Users/%d.json", get_ID_personne(c));
    Personne p = lire_fichier_personne(lienPersonne);
    int *liste = get_liste_objetPersonne(p);
    int longueur = get_longueur_liste_objetPersonne(p);
    bool canRMcompte = true;
    
    for (int i=0; i<longueur; i++)
    {
        char lien[64] = {0};
        sprintf(lien, "../Administration/Fichierjson/%d.json", liste[i]);
        
        Objet o = lire_fichier_objet(lien);
        if (get_ID_proprietaireObjet(o) != get_ID_personne(c))
        {
            canRMcompte = false;    
        }
    }
    if (canRMcompte == false)
    {
        printf("Attention : vous n'avez pas rendu tous les objets que vous avez emprunté !\n");
        return false;
    }
    else
    {
        system("sh ../Administration/fichierPret.sh");
        FILE *Fichierlongueur = NULL;
        FILE *FichierPret = NULL;
        Fichierlongueur = fopen("../Administration/NombreFichierPrets.txt", "r");
        FichierPret = fopen("../Administration/ListeFichierPretsjson.txt", "r");
        if ((Fichierlongueur != NULL ) && (FichierPret != NULL))
        {
            fscanf(Fichierlongueur, "%d", &longueur);
            for (int i=0; i<longueur; i++)
            {
                char nomPret[16] = {0};
                fscanf(FichierPret, "%s", nomPret);
                char lienPret[64] = {0};
                sprintf(lienPret, "../../data/Prets/%s", nomPret);

                Pret p = lire_fichier_pret(lienPret);

                char lienObjet[64] = {0};
                sprintf(lienObjet, "../Administration/Fichierjson/%d.json", get_objetPret(p));
                Objet o = lire_fichier_objet(lienObjet);
                if (get_ID_proprietaireObjet(o) == get_ID_personne(c))
                {
                    printf("Attention : l'objet %d est toujours emprunté !\n", get_ID_proprietaireObjet(o));
                    canRMcompte = false;
                }
                free(o);
                free(p);   
            }
            system("rm ../Administration/Fichierjson/*.json");
            system("rmdir ../Administration/Fichierjson");
            fclose(Fichierlongueur);
            fclose(FichierPret);
        } 
        else
        {
            printf("Erreur : le fichier NombreFichierPrets.txt ou le fichier ListeFichierPretsjson.txt n'a pas pu s'ouvrir\n");
            canRMcompte = false;
        }
        
    }
    return canRMcompte;
    
}