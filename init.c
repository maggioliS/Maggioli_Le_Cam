#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "structure.h"
#include "init.h"


void initialisation(void)
{ 
  TTF_Init();
  SDL_Init(SDL_INIT_VIDEO);
  Font = TTF_OpenFont("fontest.ttf", 70);
  TextColor.r = 255;
  TextColor.g = 255;
  TextColor.b = 255;
  TextSurface = TTF_RenderText_Blended(Font, "YOU WIN !!", TextColor);
  DstRect.x = 200;
  DstRect.y = 300;
  DstRect.w = TextSurface->w;
  DstRect.h = TextSurface->h;
  
  color=1;
  gagner=false;
  F=NULL;
  F=fopen("level.txt","r");
  lvl=allocation(F);
  fseek(F,0,SEEK_SET);
  printf("j'alloue\n");
  lvl=createlvl(F,lvl);
		// prepare SDL
  screen = SDL_SetVideoMode(800, 700, 32,SDL_HWSURFACE);
  temp = SDL_LoadBMP("gris.bmp");
  cube = SDL_DisplayFormat(temp);
  temp = SDL_LoadBMP("bleu.bmp");
  pie = SDL_DisplayFormat(temp);
  temp = SDL_LoadBMP("bleu.bmp");
  bouge = SDL_DisplayFormat(temp);
  objet = create_list_piece(F);
  objet = place_piece(objet,lvl);
  continuer=true;
  c = SDL_MapRGB(screen->format,0,0,0);
  fseek(F,0,SEEK_SET);

}
