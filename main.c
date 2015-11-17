#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "structure.h"
#include "init.h"
#include "gestion.h"
#include <SDL/SDL_ttf.h>

int main(int argc, char *argv[])
{
  initialisation();
  verif_fichier(F);
  affichage (lvl ,screen,cube);
  affichage_liste(objet,screen,pie);
  SDL_Flip(screen);

  while (continuer)
  {
    if(event.button.button==SDL_BUTTON_LEFT)
    {
      if(event.type == SDL_MOUSEBUTTONDOWN){
        deplacement(objet,event,pie,screen,lvl,cube,c,bouge);
        SDL_Flip(screen);
      }
    }
    lvl=vidage(lvl);
    lvl=trouver(objet,lvl);
    if(win(lvl)){
      continuer=false;
      printf(" Partie gagné !!!!!\n");
      gagner=true;
    }
    if(event.type == SDL_KEYDOWN){
      continuer=false;
    } 
    SDL_WaitEvent(&event);
  }

  SDL_FillRect(screen,NULL,c);

  while (gagner)
  {    
    affiche_fin();
    SDL_Flip(screen);
    if ( event.type == SDL_KEYDOWN ){
      gagner=false;
    }
    SDL_Delay(4);
    SDL_PollEvent(&event);   
  }

  SDL_FreeSurface(cube);
  SDL_FreeSurface(pie);
  SDL_FreeSurface(screen);
  SDL_FreeSurface(bouge);
  free(lvl);
  free(objet);
  SDL_Quit();
  return 0;
}


