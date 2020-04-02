#include "../../include/main.h"

int main(int argc, char* argv[])
{
    SDL_Window *window;

    SDL_Surface *screen;
    SDL_Surface *image;

    SDL_Rect positionClic;

    SDL_bool program_launched = SDL_TRUE;
    SDL_Event event;

    /*!< Booleen pour pouvoir changer de \a boucles */
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
                    program_launched = SDL_FALSE;
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
                                program_launched = SDL_FALSE;                                             
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
    program_launched = SDL_TRUE;


    /*!< chargement de l'image et vérification de son bon chargement. */
    image = SDL_LoadBMP("../Images/menuConnection.bmp");
    if (image == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image ");
    }

    /*!< \b Blit la \a surface sur la \a fenetre, \b liberation de la \a surface puis mise à jour de la \a fenetre. */
    Blit(image, screen, window);



    /*!< La fenètre reste ouverte tant que \a l'utilisateur ne la ferme pas. */
    while (program_launched)
    {   
        /*!< Boucle pour gérer la \a connection et \a l'inscription de l'utilisateur. */                                                     
        while (program_launched && (isLogin == false))
        {   
            /*!< On détecte les \a evenements qui se passent sur la fenètre */                     
            while (SDL_PollEvent(&event) && continuer)
            {                                        
                switch(event.type)
                {
                    /*!< Détecte si \a l'utilisateur ferme la \a fenètre. */
                    case SDL_QUIT :                                                         
                        program_launched = SDL_FALSE;
                        break;

                    /*!< Détecte si \a l'utilisateur appuie sur le \b bouton \a Connection ou \a Inscription puis arrete la boucle. */ 
                    case SDL_MOUSEBUTTONUP :                                                     
                        switch(event.button.button){

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
                                //    continuer = false;
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


                                    Personne p = init_personne();
                                    Compte c = init_compte();
                                    creer_compte(c,p);
                                    creer_fichier_compte(c);
                                    creer_fichier_personne(p);
                                    continuer = false;
                                    isLogin = true;
                                    isAdmin = false;                                    
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

        while (program_launched && (isLogin == true))
        {
            if (isAdmin)
            {
                while (SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        case SDL_QUIT :                                                         
                            program_launched = SDL_FALSE;
                            break;
                        /*
                        fonction :
                                -isAdmin == True : Gestion des demendeurs/preteurs + administration (basique + poussée) + reste
                        */
                
                        default :
                            break;

                    }
                }
            }

            if (isAdmin == false)
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

                while (SDL_PollEvent(&event))
                {             
                    switch(event.type)
                    {
                        case SDL_QUIT :                                                         
                            program_launched = SDL_FALSE;
                            break;
                        /*
                        fonction :
                                -isAdmin == False : reste = recherche + gestion des ressources + administration (basique)
                        */
                
                        default :
                            break;

                    }
                }
            }
        }                                                    
    }

    //On libere la mémoire et on quitte SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}


//Permet d'afficher un message d'erreur, et de quitter SDL
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void Blit(SDL_Surface *image, SDL_Surface *screen, SDL_Window *window)
{
    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_FreeSurface(image);
    SDL_UpdateWindowSurface(window); 
}