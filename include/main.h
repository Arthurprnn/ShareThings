#ifndef __MAIN_H__
#define __MAIN_H__

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <crypt.h>
#include <json-c/json.h>
#include <string.h>
#include <ctype.h>
#include "administration.h"
#include "entrees.h"
#include "objet.h"
#include "prets.h"
#include "temps.h"
#include "users.h"

#define LARGEUR_FENETRE 1260
#define HAUTEUR_FENETRE 720

/**
 * \fn void SDL_ExitWithError(const char *message)
 * \brief Permet d'afficher un \b message, de \b recuperer \b le \b message \b d'erreur de la \a SDL et de quitter la \a SDL en cas de \b disfonctionnement.
 * \param constchar* Le message à afficher. 
 * \return \b void La fonction ne retourne rien.
 */

void SDL_ExitWithError(const char *message);

/**
 * \fn void Blit(SDL_Surface *image, SDL_Surface *screen, SDL_Window *window)
 * \brief Permet de \b blit une \a surface sur une \b autre \a surface \b associé à une \a fenêtre, de \b liberer la première \a surface puis de \b mettre \b à \b jour la \a fenêtre.
 * \param SDL_Surface L'image que l'on veut \b blit sur une \a surface.
 * \param SDL_Surface La \a surface sur laquelle l'image va être \b blit.
 * \param SDL_Window Pour pouvoir \b mettre \b à \b jour la \a fenêtre.
 * \return \b void La fonction ne retourne rien.
 */

void Blit(SDL_Surface *image, SDL_Surface *screen, SDL_Window *window);

#endif