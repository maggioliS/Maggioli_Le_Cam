#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL/SDL_ttf.h>

  SDL_Surface *TextSurface ;
  SDL_Color TextColor;
  SDL_Rect DstRect;
  TTF_Font *Font ;
  FILE *F;
  piece** lvl;
  SDL_Surface *screen,*temp,*cube,*pie,*bouge;
  SDL_Event event;
  liste objet;
  bool continuer;
  Uint32 c;
bool gagner;
int color;
void initialisation(void);

#endif
