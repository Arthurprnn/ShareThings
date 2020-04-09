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

#define LARGEUR_FENETRE 1260
#define HAUTEUR_FENETRE 720


//Permet d'afficher un message d'erreur, et de quitter SDL
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

//Permet d'afficher un message d'erreur, et de quitter TTF
void TTF_ExitWithError(const char *message)
{
    printf("ERREUR : %s > %s\n", message, TTF_GetError());
    TTF_Quit();
    exit(EXIT_FAILURE);
}

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
    SDL_Color couleurNoire = {0, 0, 0};

    SDL_Rect Nom;
    SDL_Rect ID;

    SDL_Surface *texteNom;
    SDL_Surface *texteID;

    Nom.x = 140;
    Nom.y = 186;
    Nom.w = 130;
    Nom.h = 37;

    ID.x = 140;
    ID.y = 213;
    ID.w = 130;
    ID.h = 20;

    /*!< Booleen pour pouvoir changer et choisir de \a boucles */
    bool continuer = true;
    bool isLogin = false;
    bool isAdmin = false;



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
    police = TTF_OpenFont("../Images/arial.ttf", 11);
    if (!police)
    {
        TTF_ExitWithError("Impossible de charger la police");
    }


    /*!< Associer la surface \a screen à la fenètre \a window. */
    screen = SDL_GetWindowSurface(window);



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
                                                
                                image = SDL_LoadBMP("../Images/connection.bmp");
                                if (image == NULL)
                                {
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                }
                                Blit(image, screen, window);

                                if (connexion() == false) {
                                    goto Deconnection;
                                }

                                continuer = false;
                                isLogin = true;
                                isAdmin = false;
                                if ((isAdmin == false) && isLogin == true)
                                {
                                    goto MenuNonAdmin; 
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

                                SDL_Delay(2000);
                                /*!< Appel des \b fonctions pour \a inscrire une \a personne. */
                            
                                Personne p = init_personne();
                                Compte c = init_compte();
                                creer_compte(c,p);
                                creer_fichier_compte(c);
                                creer_fichier_personne(p);
                            
                                continuer = false;
                                isLogin = true;
                                isAdmin = false;
                                if ((isAdmin == false) && isLogin == true)
                                {
                                    goto MenuNonAdmin; 
                                }                                                        
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
                                                
                                image = SDL_LoadBMP("../Images/connection.bmp");
                                if (image == NULL)
                                {
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                }
                                Blit(image, screen, window);

                            }

                            /*!< Affiche l'onglet \b Liste \b des \b demandes. */
                            if ((positionClic.x >465&& positionClic.x < 808) && (positionClic.y > 515) && (positionClic.y < 550))
                            {
                                                
                                image = SDL_LoadBMP("../Images/connection.bmp");
                                if (image == NULL)
                                {
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                }
                                Blit(image, screen, window);

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

                        /*!< Aliment */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            printf("a\n");                         
                        }

                        /*!< Cosmétique */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                            printf("b\n");                          
                        }

                        /*!< Cuisine */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                            printf("c\n");                          
                        }

                        /*!< Décoration */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                            printf("d\n");                          
                        }

                        /*!< Divertissement */
                        if ((positionClic.x >83 && positionClic.x < 298) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                            printf("e\n");                          
                        }

                        /*!< Electrique */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                            printf("f\n");                          
                        }

                        /*!< Electronique */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                                                  
                        }

                        /*!< Fourniture */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                                                  
                        }

                        /*!< Internet */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                                                  
                        }

                        /*!< Jouet */
                        if ((positionClic.x >380 && positionClic.x < 596) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                                                  
                        }

                        /*!< Matériau */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                                                  
                        }

                        /*!< Mobilier */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                                                  
                        }

                        /*!< Musique */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                                                  
                        }

                        /*!< Nature */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                                                  
                        }

                        /*!< Outil */
                        if ((positionClic.x >676 && positionClic.x < 893) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                                                  
                        }

                        /*!< Pharmaceutique */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 238) && (positionClic.y < 276))
                        { 
                                                  
                        }

                        /*!< Produit ménager */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 307) && (positionClic.y < 345))
                        { 
                                                  
                        }

                        /*!< Véhicule */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 376) && (positionClic.y < 412))
                        { 
                                                  
                        }

                        /*!< Vêtement */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 444) && (positionClic.y < 481))
                        { 
                                                  
                        }

                        /*!< Autres */
                        if ((positionClic.x >973 && positionClic.x < 1190) && (positionClic.y > 513) && (positionClic.y < 550))
                        { 
                                                  
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

/*
    ListePrets :
    //code html
*/

/*
    ListeDemandes :
*/


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
                            
                            Objet o = creer_objet(21702301);
                            Personne p = lire_fichier_personne("../../data/Users/21702301.json");
                            creer_fichier_objet(o);
                            add_objet_dans_liste_objet(p, o);

                            goto Objets;  
                                                    
                        }

                        /*!< Supprimer un objet */
                        if ((positionClic.x >394 && positionClic.x < 866) && (positionClic.y > 515) && (positionClic.y < 571))
                        { 
                            printf("b\n");                          
                        }

                        /*!< Voir ses objets */
                        if ((positionClic.x >536 && positionClic.x < 864) && (positionClic.y > 584) && (positionClic.y < 623))
                        { 
                            printf("c\n");                          
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
                            SDL_Delay(2000);
                            goto Profil;                         
                        }

                        /*!< Supprimer Profil */
                        if ((positionClic.x >394 && positionClic.x < 866) && (positionClic.y > 505) && (positionClic.y < 560))
                        { 
                            printf("b\n");                          
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
    //Deconnection
    goto MenuConnection;


    Fin:
    //On libere la mémoire et on quitte SDL
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}


/*            
            if (isAdmin)
            {
                while (SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        case SDL_QUIT :                                                         
                            program_launched = SDL_FALSE;
                            break;
                
                        default :
                            break;

                    }
                }
            }
*/