#include <SDL.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <crypt.h>
#include <json-c/json.h>
#include <string.h>
#include <ctype.h>

#include "../../include/administration.h"
#include "../../include/entrees.h"
#include "../../include/objet.h"
#include "../../include/prets.h"
#include "../../include/temps.h"
#include "../../include/users.h"
#include "../../include/html.h"

#define LARGEUR_FENETRE 1260
#define HAUTEUR_FENETRE 720


/*!< Permet d'afficher un message d'erreur, et de quitter SDL. */
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/*!< Permet d'afficher un message d'erreur, et de quitter TTF. */
void TTF_ExitWithError(const char *message)
{
    printf("ERREUR : %s > %s\n", message, TTF_GetError());
    TTF_Quit();
    exit(EXIT_FAILURE);
}

/*!< Permet de blit une surface sur une autre surface, de librer de liberer la premiere surface, puis de mettre à jour la fenêtre. */
void Blit(SDL_Surface *image, SDL_Surface *screen, SDL_Window *window)
{
    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_FreeSurface(image);
    SDL_UpdateWindowSurface(window); 
}



int main(int argc, char* argv[])
{   
    /*!< Variables pour sdl */
    SDL_Window *window;

    SDL_Surface *screen;
    SDL_Surface *image;

    SDL_Rect positionClic;

    SDL_bool program_launched = SDL_TRUE;
    SDL_Event event;

    /*!< Varaible pour ttf */
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 255, 255};

    SDL_Rect Nom;
    SDL_Rect ID;

    SDL_Surface *texteNom;
    SDL_Surface *texteID;

    Nom.x = 142;
    Nom.y = 183;
    Nom.w = 130;
    Nom.h = 37;

    ID.x = 130;
    ID.y = 211;
    ID.w = 130;
    ID.h = 20;

    /*!< Booleen pour pouvoir changer et choisir de \a boucles */
    bool continuer = true;
    bool isLogin = false;
    bool isAdmin = false;


    /*!< On initialise un compte et une id. */
    Compte c;
    int IDPersonne;

    char lienPersonne[64] = {0};


    /*!< Lancement de \a SDL et vérification de sa bonne initialisation. */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_ExitWithError("Initialisation SDL");
    }

    /*!< Initialisation de la \a fentre et vérification de sa bonne initialisation. */
    window = SDL_CreateWindow("ShareThings", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0);
    if (window == NULL)
    {
        SDL_ExitWithError("Impossible de créer la fenetre");
    }

    /*!< Initialisation de la police et verification de sa bonne initialisation. */
    if (TTF_Init() == -1)
    {
       TTF_ExitWithError("Impossible d'initialiser la police"); 
    }

    /*!< Chargement de la police et vérification de son bon chargement. */
    police = TTF_OpenFont("../Images/arial.ttf", 16);
    if (!police)
    {
        TTF_ExitWithError("Impossible de charger la police");
    }


    /*!< Associer la surface \a screen à la fenètre \a window. */
    screen = SDL_GetWindowSurface(window);

    SDL_Surface* iconSurface;
    iconSurface = SDL_LoadBMP("../Images/Tokimori.bmp");
    SDL_SetWindowIcon(window, iconSurface);

    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/information.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }

    /*!< \b Blit la \a surface sur la \a fenêtre, \b liberation de la \a surface puis mise à jour de la \a fenêtre. */
    Blit(image, screen, window);

    /*!< On détecte les \a evenements qui se passent sur la \a fenêtre tant que l'on ne clic pas sur la \b flèche. */                     
    while (program_launched)
    {
        while (SDL_PollEvent(&event))
        {                                       
            switch(event.type)
            {
                /*!< Détecte si \a l'utilisateur ferme la \a fenètre. */
                case SDL_QUIT :                                                         
                    goto Fin;
                    break;

                /*!< Détecte si \a l'utilisateur appuie sur la \b fleche. */ 
                case SDL_MOUSEBUTTONUP :                                                     
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT :

                            positionClic.x = event.button.x;
                            positionClic.y = event.button.y;

                            if ((positionClic.x >1010 && positionClic.x < 1065) && (positionClic.y > 590) && (positionClic.y < 630))
                            {
                                goto MenuConnection;                                             
                            }                   
                            continue;

                        default :
                            continue;
                    }

                default :
                    break;
            }
        }
    }
    

    MenuConnection :
    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/menuConnection.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }

    /*!< \b Blit la \a surface sur la \a fenetre, \b liberation de la \a surface puis mise à jour de la \a fenetre. */
    Blit(image, screen, window);

    /*!< Boucle pour gérer la \a connection et \a l'inscription de l'utilisateur. */                                                     
    while (program_launched)
    {   
        /*!< On détecte les \a evenements qui se passent sur la fenètre */                     
        while (SDL_PollEvent(&event) && continuer)
        {                                        
            switch(event.type)
            {
                /*!< Détecte si \a l'utilisateur ferme la \a fenètre. */
                case SDL_QUIT :
                    goto Fin;                                                                             
                    break;

                /*!< Détecte si \a l'utilisateur appuie sur le \b bouton \a Connection ou \a Inscription puis arrete la boucle. */ 
                case SDL_MOUSEBUTTONUP :                                                     
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT :

                            positionClic.x = event.button.x;
                            positionClic.y = event.button.y;

                            /*!< Affiche l'onglet de \a connection. */
                            if ((positionClic.x >210 && positionClic.x < 425) && (positionClic.y > 514) && (positionClic.y < 549))
                            {
                                /*!< Afficher l'image. */                
                                image = SDL_LoadBMP("../Images/connection.bmp");
                                if (image == NULL)
                                {
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                }
                                Blit(image, screen, window);   
                                
                                /*!< Gere la \b connection. */
                                c = init_compte();

                                printf("Nom d'utilisateur : /!\\ Caractères autorisés : {[a-z],[A-Z],[0-9],[_]}\nChaine : ");
                                char * nom_utilisateur = creer_chaine_de_caracteres();
                                char * mdp = creer_mot_de_passe();
                                printf("\n");
                                char * cryptmdp = chiffrer_mot_de_passe(mdp);
                                bool isConnexionReussie = false;
                                if (isCompteExist(nom_utilisateur)) {
                                    char lien[64] = {0};
                                    sprintf(lien, "../../data/Comptes/%s.json", nom_utilisateur);
                                    c = lire_fichier_compte(lien);
                                    if (strcmp(cryptmdp, get_mdp(c)) == 0) {
                                        isConnexionReussie = true;
                                    }
                                }
                                /*!< Si la \a connection ne \b réussit \b pas, on renvoie l'utilisateur au menue \b d'accueil. */
                                if (isConnexionReussie == false) {
                                    system("clear");
                                    goto Deconnection;
                                }
                                /*!< On vérifie si le compte connecté \b est un \b compte \a admin ou \a non. */
                                if (get_ID_personne(c) == 0) {
                                    isAdmin = true;
                                } else {
                                    isAdmin = false;
                                }

                                continuer = false;
                                isLogin = true;

                                char lien[64] = {0};
                                sprintf(lien, "../../data/Users/%d.json", get_ID_personne(c));
                                Personne personne = lire_fichier_personne(lien);

                                while (!verifieDatePret(get_ID_personne(c)))
                                {
                                    rendre_objet(personne);
                                }

                                /*!< Redirige l'utilisateur vers l'onglet \a Admin ou l'onglet \a NonAdmin. */
                                if ((isAdmin == false) && isLogin == true)
                                {
                                    system("clear");
                                    goto MenuNonAdmin; 
                                }
                                else
                                {
                                    system("clear");
                                    goto MenuAdmin;
                                }
                            }


                            /*!< Affiche l'onglet \a d'inscription. */
                            if ((positionClic.x >847 && positionClic.x < 1060) && (positionClic.y > 514) && (positionClic.y < 549))
                            {
                                image = SDL_LoadBMP("../Images/inscription.bmp");
                                if (image == NULL)
                                {
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image ");
                                }
                                Blit(image, screen, window);

                                
                                /*!< Appel des \b fonctions pour \a inscrire une \a personne. */

                                printf("Bienvenue sur ShareThings !\n\n");
                                c = init_compte();
                                Personne p = init_personne();
                                creer_compte(c,p);
                                creer_fichier_compte(c);
                                creer_fichier_personne(p);
                            
                                continuer = false;
                                isLogin = true;
                                isAdmin = false;  
                                system("clear");                                                              
                                goto MenuNonAdmin; 
                                                                                        
                            }                   
                            continue;
                        default :
                            continue;
                    }
                    continue;

                default :
                    break;
            }
        }
    }


    MenuAdmin :
    continuer = true;
    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/menuAdmin.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }

    /*!< \b Blit la \a surface sur la \a fenetre, \b liberation de la \a surface puis mise à jour de la \a fenetre. */
    Blit(image, screen, window);

    /*!< Boucle pour gérer la \a connection et \a l'inscription de l'utilisateur. */                                                     
    while (program_launched)
    {   
        /*!< On détecte les \a evenements qui se passent sur la fenètre */                     
        while (SDL_PollEvent(&event) && continuer)
        {                                        
            switch(event.type)
            {
                /*!< Détecte si \a l'utilisateur ferme la \a fenètre. */
                case SDL_QUIT :
                    goto Fin;                                                                             
                    break;

                /*!< Détecte si \a l'utilisateur appuie sur le \b bouton \a Connection ou \a Inscription puis arrete la boucle. */ 
                case SDL_MOUSEBUTTONUP :                                                     
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT :

                            positionClic.x = event.button.x;
                            positionClic.y = event.button.y;

                            /*!< \a Déconnexion. */
                            if ((positionClic.x > 884 && positionClic.x < 1211) && (positionClic.y > 39) && (positionClic.y < 86))
                            {
                                system("clear");
                                goto MenuConnection;                            
                            }

                            /*!< \a Liste \a des \a demendeurs. */
                            if ((positionClic.x > 168 && positionClic.x < 510) && (positionClic.y > 239) && (positionClic.y < 310))
                            {
                                afficheUsers(); 
                                system("x-www-browser ../HTML/afficheUtilisateurs.html");
                                system("clear");
                            }

                            /*!< \a Modifier \a les \a données \a des \a demandeurs. */
                            if ((positionClic.x > 168 && positionClic.x < 510) && (positionClic.y > 376) && (positionClic.y < 448))
                            {
                                system("clear");
                                goto ModifierDonneesAdmin;
                            }                             

                            /*!< \a Changer \a le \a mot \a de \a passe \a des \a demandeurs. */
                            if ((positionClic.x > 168 && positionClic.x < 510) && (positionClic.y > 513) && (positionClic.y < 585))
                            {
                                changer_mot_de_passe();
                                system("clear");
                            }

                            /*!< \a Doxygen. */
                            if ((positionClic.x > 804 && positionClic.x < 1147) && (positionClic.y > 376) && (positionClic.y < 448))
                            {
                                system("x-www-browser ../../doc/Doxygen/html/index.html");
                                system("clear");
                            } 

                            continue;
                        default :
                            continue;
                    }
                    continue;

                default :
                    break;
            }
        }
    }


    ModifierDonneesAdmin :
    continuer = true;
    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/modifierDonneesAdmin.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }

    /*!< \b Blit la \a surface sur la \a fenetre, \b liberation de la \a surface puis mise à jour de la \a fenetre. */
    Blit(image, screen, window);

    /*!< Boucle pour gérer la \a connection et \a l'inscription de l'utilisateur. */                                                     
    while (program_launched)
    {   
        /*!< On détecte les \a evenements qui se passent sur la fenètre */                     
        while (SDL_PollEvent(&event) && continuer)
        {                                        
            switch(event.type)
            {
                /*!< Détecte si \a l'utilisateur ferme la \a fenètre. */
                case SDL_QUIT :
                    goto Fin;                                                                             
                    break;

                /*!< Détecte si \a l'utilisateur appuie sur le \b bouton \a Connection ou \a Inscription puis arrete la boucle. */ 
                case SDL_MOUSEBUTTONUP :                                                     
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT :

                            positionClic.x = event.button.x;
                            positionClic.y = event.button.y;

                            /*!< Détecte si l'utilisateur appuie sur la fleche, et reviens au menu Admin. */
                            if ((positionClic.x > 410 && positionClic.x < 477) && (positionClic.y > 590) && (positionClic.y < 644))
                            {
                                system("clear");
                                goto MenuAdmin;                            
                            }

                            /*!< Nom. */
                            if ((positionClic.x > 394 && positionClic.x < 864) && (positionClic.y > 306) && (positionClic.y < 362))
                            {
                                changer_donnees_utilisateur(0);
                                system("clear");                                
                            }                             

                            /*!< Prenom. */
                            if ((positionClic.x > 394 && positionClic.x < 864) && (positionClic.y > 378) && (positionClic.y < 434))
                            {
                                changer_donnees_utilisateur(1);
                                system("clear"); 
                            }

                            /*!< Mail. */
                            if ((positionClic.x > 394 && positionClic.x < 864) && (positionClic.y > 451) && (positionClic.y < 505))
                            {
                                changer_donnees_utilisateur(2);
                                system("clear"); 
                            }

                            /*!< Age. */
                            if ((positionClic.x > 394 && positionClic.x < 864) && (positionClic.y > 523) && (positionClic.y < 578))
                            {
                                changer_donnees_utilisateur(3);
                                system("clear"); 
                            } 
                            continue;
                        default :
                            continue;
                    }
                    continue;

                default :
                    break;
            }
        }
    }


    MenuNonAdmin :
    continuer = true;
    while (program_launched && (isLogin == true))
    {

    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/menuNonAdmin.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }
    /*!< \b Blit la \a surface sur la \a fenêtre, \b liberation de la \a surface puis mise à jour de la \a fenêtre. */
    Blit(image, screen, window); 

    /*!< Affiche ID et Nom sur le menuNonAdmin de l'utilisateur. */
    IDPersonne = get_ID_personne(c);
    char IDChar[9];
    sprintf(IDChar, "%d", IDPersonne);
    texteID = TTF_RenderText_Blended(police, IDChar, couleurNoire);
    SDL_BlitSurface(texteID, NULL, screen, &ID);
    SDL_FreeSurface(texteID);
    SDL_UpdateWindowSurface(window);

    char *NomUtilisateur = get_nom_utilisateur(c);
    texteNom = TTF_RenderText_Blended(police, NomUtilisateur, couleurNoire);
    SDL_BlitSurface(texteNom, NULL, screen, &Nom);
    SDL_FreeSurface(texteNom);
    SDL_UpdateWindowSurface(window);
                
    while (program_launched && continuer)
    {
        while (SDL_PollEvent(&event))
        {             
            switch(event.type)
            {
                case SDL_QUIT :                                                         
                    goto Fin;
                    break;

                /*!< Permet de \a choisir entre toutes les \b options du \a menu. */
                case SDL_MOUSEBUTTONUP :                                                     
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT :

                            positionClic.x = event.button.x;
                            positionClic.y = event.button.y;

                            /*!< Affiche l'onglet \b Rechercher \b des \b objtes. */
                            if ((positionClic.x >83 && positionClic.x < 425) && (positionClic.y > 478) && (positionClic.y < 550))
                            {                                 
                                goto RechercheObjet;                                            
                            }

                            /*!< Affiche l'onglet \b Liste \b des \b prets. */
                            if ((positionClic.x >465 && positionClic.x < 808) && (positionClic.y > 478) && (positionClic.y < 514))
                            {                                                
                                goto ListePrets;

                            }

                            /*!< Affiche l'onglet \b Liste \b des \b demandes. */
                            if ((positionClic.x >465&& positionClic.x < 808) && (positionClic.y > 515) && (positionClic.y < 550))
                            {                                
                                goto ListeDemandes; 

                            }

                            /*!< Affiche l'onglet Objet. */
                            if ((positionClic.x >847 && positionClic.x < 1190) && (positionClic.y > 478) && (positionClic.y < 550))
                            {                                        
                                goto Objets;
                            }                

                            /*!< Affiche l'onglet \b Déconnexion. */
                            if ((positionClic.x >931 && positionClic.x < 1190) && (positionClic.y > 67) && (positionClic.y < 101))
                            {                                                                                
                                goto Deconnection;
                            }

                            /*!< Affiche l'onglet \b Profil. */
                            if ((positionClic.x >889 && positionClic.x < 1190) && (positionClic.y > 102) && (positionClic.y < 139))
                            {                                           
                                goto Profil;
                            }

                            /*!< Demander un \a Objet. */
                            if ((positionClic.x >82 && positionClic.x < 596) && (positionClic.y > 580) && (positionClic.y < 618))
                            {
                                char lienPersonne[64] = {0};
                                sprintf(lienPersonne, "../../data/Users/%d.json", get_ID_personne(c));
                                Personne p = lire_fichier_personne(lienPersonne);
                                            
                                demander_objet(p);
                                SDL_Delay(2000);
                                system("clear");
                            }

                            /*!< Rendre un \a Objet. */
                            if ((positionClic.x >676 && positionClic.x < 1189) && (positionClic.y > 580) && (positionClic.y < 618))
                            {
                                char lienPersonne[64] = {0};
                                sprintf(lienPersonne, "../../data/Users/%d.json", get_ID_personne(c));
                                Personne p = lire_fichier_personne(lienPersonne);            
                                
                                rendre_objet(p);
                                SDL_Delay(2000);
                                system("clear");
                            }
                            continue;                            
                
                        default :
                            break;
                    }
                    continue;

                default :
                    break;
            }
        }
    }
    }


    RechercheObjet :
    image = SDL_LoadBMP("../Images/rechercheObjets.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }       
    Blit(image, screen, window);                                                                                

    while (program_launched && (isLogin == true))
    {    
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT :                                                         
                goto Fin;
                    break;

            case SDL_MOUSEBUTTONUP :                                                     
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT :

                        positionClic.x = event.button.x;
                        positionClic.y = event.button.y;

                        /*!< Détecte si l'utilisateur appuie sur la fleche et renvoie au menu */
                        if ((positionClic.x >95 && positionClic.x < 150) && (positionClic.y > 600) && (positionClic.y < 645))
                        { 
                            goto MenuNonAdmin;                          
                        }

                        /*!< Rechercher un objet par ID */
                        if ((positionClic.x >634 && positionClic.x < 1147) && (positionClic.y > 597) && (positionClic.y < 634))
                        { 
                            if (RechercherParID())
                            {
                                system("x-www-browser ../HTML/afficheRecherID.html");
                            }
                            
                            system("clear");
                            goto RechercheObjet;                          
                        }

                        /*!< Affiche la listes des objets disponibles dans les 20 catégories differentes. */

                        /*!< Aliment */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            AfficherObjetsParType("Aliment");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                         
                        }

                        /*!< Cosmétique */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                            AfficherObjetsParType("Cosmétique");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                         
                        }

                        /*!< Cuisine */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                            AfficherObjetsParType("Cuisine");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Décoration */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                            AfficherObjetsParType("Décoration");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Divertissement */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                            AfficherObjetsParType("Divertissement");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Electrique */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            AfficherObjetsParType("Electrique");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Electronique */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 307) && (positionClic.y < 345))
                        {
                            AfficherObjetsParType("Electronique");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet; 
                                                  
                        }

                        /*!< Fourniture */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                            AfficherObjetsParType("Fourniture");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                      
                        }

                        /*!< Internet */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                            AfficherObjetsParType("Internet");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                      
                        }

                        /*!< Jouet */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                            AfficherObjetsParType("Jouet");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                      
                        }

                        /*!< Matériau */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            AfficherObjetsParType("Matériau");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                     
                        }

                        /*!< Mobilier */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                            AfficherObjetsParType("Mobilier");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                     
                        }

                        /*!< Musique */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                            AfficherObjetsParType("Musique");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                         
                        }

                        /*!< Nature */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                            AfficherObjetsParType("Nature");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Outil */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 513) && (positionClic.y < 550))
                        {    
                            AfficherObjetsParType("Outil");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Pharmaceutique */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            AfficherObjetsParType("Pharmaceutique");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Produit ménager */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                            AfficherObjetsParType("Produit_ménager");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Véhicule */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                            AfficherObjetsParType("Véhicule");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                         
                        }

                        /*!< Vêtement */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                            AfficherObjetsParType("Vêtement");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        /*!< Autres */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                            AfficherObjetsParType("Autres");
                            system("x-www-browser ../HTML/fichier.html");
                            goto RechercheObjet;                          
                        }

                        continue;

                    default :
                        continue;
                }               

            default :
                break;
        }
    }
    }


    ListePrets :
    sprintf(lienPersonne, "../../data/Users/%d.json", IDPersonne);
    Personne p = lire_fichier_personne(lienPersonne);
    listePret(p);
    system("x-www-browser ../HTML/affichePret.html");
    system("clear");
    goto MenuNonAdmin;



    ListeDemandes : 
    sprintf(lienPersonne, "../../data/Users/%d.json", IDPersonne);
    p = lire_fichier_personne(lienPersonne);
    listeDemande(p);
    system("x-www-browser ../HTML/afficheDemande.html");
    system("clear");
    goto MenuNonAdmin;


    Objets :
    image = SDL_LoadBMP("../Images/objets.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }       
    Blit(image, screen, window);                                                                                

    while (program_launched && (isLogin == true))
    {    
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT :                                                         
                goto Fin;
                    break;

            case SDL_MOUSEBUTTONUP :                                                     
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT :

                        positionClic.x = event.button.x;
                        positionClic.y = event.button.y;

                        /*!< Détecte si l'utilisateur appuie sur la fleche et renvoie au menu */
                        if ((positionClic.x >393 && positionClic.x < 460) && (positionClic.y > 586) && (positionClic.y < 640))
                        { 
                            goto MenuNonAdmin;                          
                        }

                        /*!< Ajouter un objet */
                        if ((positionClic.x >394 && positionClic.x < 866) && (positionClic.y > 176) && (positionClic.y < 232))
                        {
                            image = SDL_LoadBMP("../Images/ajouterObjet.bmp");
                            if (image == NULL)
                            {
                                SDL_DestroyWindow(window);
                                SDL_ExitWithError("Impossible de charger l'image");
                            }       
                            Blit(image, screen, window);
                            
                            Objet o = creer_objet(IDPersonne);
                            creer_fichier_objet(o);
                            char lien[64] = {0};
                            sprintf(lien, "../../data/Users/%d.json", IDPersonne);
                            Personne p = lire_fichier_personne(lien);
                            add_objet_dans_liste_objet(p, o);
                            creer_fichier_personne(p);

                            system("clear");
                            goto Objets;  
                                                    
                        }

                        /*!< Supprimer un objet */
                        if ((positionClic.x >394 && positionClic.x < 866) && (positionClic.y > 515) && (positionClic.y < 571))
                        { 
                            printf("\nVeuillez rentrer l'ID de l'objet à supprimer: Attention vous ne pouvez supprimer un objet que s'il est dans votre liste d'objets et seulement s'il vous appartient !\nID: ");
                            int ID_obj = 0;
                            lire_entier(&ID_obj);
                            if ((ID_obj>=10000000) && (ID_obj<=19999999)) {
                                char commande[64] = {0};
                                sprintf(commande, "sh ../Personnes/liste_objet.sh");
                                printf("\nCommande: %s\n", commande);
                                system(commande);


                                char lien[64] = {0};
                                sprintf(lien, "./Test/%d.json", ID_obj);
                                
                                FILE *fichier = NULL;
                                fichier = fopen(lien, "r");

                                if (fichier != NULL) {
                                    Objet o = lire_fichier_objet(lien);

                                    if (get_ID_proprietaireObjet(o) == IDPersonne) {
                                        char lienPersonne[64] = {0};
                                        sprintf(lienPersonne, "../../data/Users/%d.json", get_ID_proprietaireObjet(o));
                                        Personne p = lire_fichier_personne(lienPersonne);
                                        bool isInListe = false;
                                        int *liste = get_liste_objetPersonne(p);

                                        for (int i=0; i<get_longueur_liste_objetPersonne(p); i++) {
                                            if (liste[i] == ID_obj) {
                                                isInListe = true;
                                            }
                                        }

                                        if (isInListe) {
                                            delete_objet_dans_liste_objet(p, ID_obj);
                                            char commandeObjet[64] = {0};
                                            sprintf(commandeObjet, "rm ../../data/Objets/%s/%d.json", get_typeObjet(o), ID_obj);
                                            system(commandeObjet);
                                            creer_fichier_personne(p);
                                        } else {
                                            printf("L'objet existe bien mais n'est pas dans votre liste d'objet, vous ne pouvez pas le supprimer !\n");
                                        }
                                        
                                    } else {
                                        printf("\nVous n'êtes pas le propriétaire de cet objet !\n");
                                    }
                                } else {
                                    printf("\nCet ID n'existe pas, il n'y a pas d'objets portant cet ID !\n");
                                }
                                system("rm ./Test/*.json");
                                system("rmdir Test");
                            } else {
                                printf("\nL'entier entré n'est pas un ID d'objet !\n");
                            }

                            system("clear");
                            goto Objets;
                        }

                        /*!< Voir ses objets */
                        if ((positionClic.x >536 && positionClic.x < 864) && (positionClic.y > 584) && (positionClic.y < 623))
                        {
                            
                            char lienPersonne[64] = {0};
                            sprintf(lienPersonne, "../../data/Users/%d.json", get_ID_personne(c));
                            Personne p = lire_fichier_personne(lienPersonne); 
                            printf("%s\n",lienPersonne);
                            afficheObjetsPersonne(p); 
                            system("x-www-browser ../HTML/afficheObjetsPersonne.html");
                            
                            system("clear");
                            goto Objets;                         
                        }
                        
                        continue;

                    default :
                        continue;
                }
                continue;               

            default :
                break;
        }
    }
    }


    Profil :
    image = SDL_LoadBMP("../Images/modifierProfil.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }       
    Blit(image, screen, window);                                                                                

    while (program_launched && (isLogin == true))
    {    
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT :                                                         
                goto Fin;
                    break;

            case SDL_MOUSEBUTTONUP :                                                     
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT :

                        positionClic.x = event.button.x;
                        positionClic.y = event.button.y;

                        /*!< Détecte si l'utilisateur appuie sur la fleche et renvoie au menu */
                        if ((positionClic.x >406 && positionClic.x < 473) && (positionClic.y > 586) && (positionClic.y < 631))
                        { 
                            goto MenuNonAdmin;                          
                        }

                        /*!< Modifier Profil */
                        if ((positionClic.x >396 && positionClic.x < 868) && (positionClic.y > 204) && (positionClic.y < 258))
                        { 
                            image = SDL_LoadBMP("../Images/modificationProfil.bmp");
                            if (image == NULL)
                            {
                                SDL_DestroyWindow(window);
                                SDL_ExitWithError("Impossible de charger l'image");
                            }       
                            Blit(image, screen, window);

                            printf("\n");
                            Personne p = init_personne();                            
                            char commandeRMCompte[64] = {0};                            
                            sprintf(commandeRMCompte, "rm ../../data/Comptes/%s.json", get_nom_utilisateur(c)); 
                            system(commandeRMCompte);
                            creer_compte(c, p);
                            set_ID_personne(c, IDPersonne);
                            set_IDPersonne(p, IDPersonne);
                            creer_fichier_compte(c);
                            creer_fichier_personne(p);

                            system("clear");
                            goto Profil;                         
                        }

                        /*!< Supprimer Profil */
                        if ((positionClic.x >394 && positionClic.x < 866) && (positionClic.y > 505) && (positionClic.y < 560))
                        { 
                            if (!supprimer_compte(c))
                            {
                                printf("Votre compte ne peut être supprimé.\n");
                            }
                            else
                            {
                                if (isSur() == 0) {

                                    char lienPers[64] = {0};
                                    sprintf(lienPers, "../../data/Users/%d.json", IDPersonne);

                                    Personne pers = lire_fichier_personne(lienPers);

                                    supprimerObjetPourCompteSupprime(pers);

                                    char commandeCompte[64] = {0};
                                    sprintf(commandeCompte, "rm ../../data/Comptes/%s.json", get_nom_utilisateur(c));
                                    system(commandeCompte);

                                    char commandeUsers[64] = {0};
                                    sprintf(commandeUsers, "rm ../../data/Users/%d.json", get_ID_personne(c));
                                    system(commandeUsers);

                                    system("clear");
                                    printf("Le compte \"%s\" à été supprimé avec succès, merci d'avoir utilisé ShareThings !\n", get_nom_utilisateur(c));
                                
                                    goto MenuConnection;

                                } else {
                                    system("clear");
                                    printf("Vous n'avez pas supprimé votre compte.\n");
                                    goto Profil;
                                }
                            }
                            
                            goto Profil;                                 
                        }                                                
                        continue;

                    default :
                        continue;
                }
                continue;               

            default :
                break;
        }
    }
    }


    Deconnection :
    goto MenuConnection;


    Fin:
    /*!< On libere la mémoire et on quitte SDL. */
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}