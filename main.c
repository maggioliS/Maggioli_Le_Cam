#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "structure.h"


int main(int argc, char *argv[])
{
  
  printf("debut\n");
  FILE *F=NULL;
  F=fopen("level.txt","r");
  piece** lvl=allocation(F);
  fseek(F,0,SEEK_SET);
  printf("j'alloue\n");
  lvl=createlvl(F,lvl);
  SDL_Surface *screen,*temp,*cube,*pie;
  SDL_Event event;
  SDL_Init(SDL_INIT_VIDEO);		// prepare SDL
  screen = SDL_SetVideoMode(800, 700, 32,SDL_HWSURFACE);
  temp = SDL_LoadBMP("gris.bmp");
  cube = SDL_DisplayFormat(temp);
  temp = SDL_LoadBMP("bleu.bmp");
  pie = SDL_DisplayFormat(temp);
  liste objet = create_list_piece(F);
  int test;
  objet=place_piece(objet,lvl);
  printf("je place bien");
  affichage (lvl ,screen,cube);
    
  
  int continuer=1;
  while ( continuer==1)
  {
    affichage (objet->elem,screen,pie);  
    if(is_empty(rest(objet))){
      continuer=0;
    }else{
      objet=rest(objet);
    }
  }
  SDL_Flip(screen);
  do 
 
  {
    if (SDL_MOUSEBUTTONDOWN){
    }
      
      
    SDL_WaitEvent(&event);
  } while ( event.type != SDL_KEYDOWN);

  SDL_Quit();
  return 0;
}


