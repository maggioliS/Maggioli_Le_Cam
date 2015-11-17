#ifndef GESTION_H
#define GESTION_H

#include <SDL.h>


void deplace_piece(piece** P,SDL_Event event,SDL_Surface* pie, SDL_Surface* screen,liste copy,piece** lvl,SDL_Surface* cube,Uint32 c,SDL_Surface* bouge);

void deplacement(liste L,SDL_Event event,SDL_Surface* pie,SDL_Surface* screen,piece** lvl,SDL_Surface* cube,Uint32 c,SDL_Surface* bouge);
piece** deplace(piece** P,SDL_Event event);

bool touche(piece** P,int x,int y,SDL_Event event);

bool win(piece** lvl);

piece** trouver(liste L, piece ** lvl);

piece verif_case(piece** lvl,liste L,int i,int j);

piece** vidage(piece** lvl);

#endif
