#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include "structure.h"
#include "gestion.h"
#include "init.h"

bool touche(piece** P,int x,int y,SDL_Event event)
{
  bool touch;
  touch=false;
  int i,j,hauteur;
  hauteur=P[0][0].hauteur;
  j=0;
  i=0;
  for(i=0;i<hauteur;i++)
  {
    while(P[i][j].type!=10)
    {
      if ( P[i][j].type==35){
        if (P[i][j].pos.x/32==x/32){
          if(P[i][j].pos.y/24==y/24){
            touch=true;
          }
        }
      }
      j=j+1; 
    }
    j=0;
  }
  return touch;
}

void deplacement(liste L,SDL_Event event,SDL_Surface* pie,SDL_Surface* screen,piece** lvl,SDL_Surface* cube,Uint32 c,SDL_Surface* bouge)
{
  int x,y;
  bool continuer;
  continuer=true;
  if ( is_empty(L)){
    continuer=false;
  }
  x=event.motion.x;
  y=event.motion.y;
  while ( continuer )
  {
    if(touche(L->elem,x,y,event)){
      L->next=L->head;
     
      deplace_piece(L->elem,event,pie,screen,L,lvl,cube,c,bouge);
      printf("touché !!!!! \n");     
    }
    if ( is_empty(rest(L))){
      continuer=false;
    }else{
      L=rest(L);
    }
  }
}

void deplace_piece(piece** P,SDL_Event event,SDL_Surface* pie,SDL_Surface* screen,liste copy,piece** lvl,SDL_Surface* cube,Uint32 c,SDL_Surface* bouge)
{
  bool continuer=true;
  int i,j,hauteur,x,y;
  hauteur=P[0][0].hauteur;
  j=0;
  i=0;
while (event.button.button == SDL_BUTTON_LEFT )
{
  x=event.motion.x;
  y=event.motion.y;
  for(i=0;i<hauteur;i++)
  {
    while(P[i][j].type!=10)
    {
      if (P[i][j].type==35){
        P[i][j].pos.x=x+(j*32);
        P[i][j].pos.y=y+(i*24);
      }
      j=j+1;
    }
    j=0;
  }
  SDL_FillRect(screen,NULL,c);
  affichage(lvl,screen,cube);
  affichage_liste(copy,screen,pie);
  SDL_Flip(screen);
  SDL_WaitEvent(&event);
}
 for(i=0;i<hauteur;i++)
  {
    while(P[i][j].type!=10)
    {
      if (P[i][j].type==35){
        P[i][j].pos.x=(x/32)*32+(j*32);
        P[i][j].pos.y=(y/24)*24+(i*24);
      }
      j=j+1;
    }
    j=0;
  }
  i=0;
  SDL_FillRect(screen,NULL,c);
  affichage(lvl,screen,cube);
  affichage_liste(copy,screen,pie);
  SDL_Flip(screen);
}

bool win(piece** lvl)
{
  bool gagner=false;
  int hauteur;
  hauteur=lvl[0][0].hauteur;
  int j,i;
  j=0;
  int cpt=0;
  int cptcouv=0;
  for (i=0;i<hauteur;i++)
  {
    while(lvl[i][j].type != 10)
    {
    
      if(lvl[i][j].couvert==true){
        cptcouv=cptcouv+1;
      }
      j=j+1;
      cpt=cpt+1;
    }
    j=0;
  }
  
  return cpt == cptcouv;
}

piece** trouver(liste L, piece ** lvl)
{
  int i,j,x,y,hauteurlvl,hauteurL;
  j=0;
  x=0;
  bool continuer=true;
  bool gagner;
  hauteurlvl=lvl[0][0].hauteur;
  for (i=0;i<hauteurlvl;i++)
  {
    while(lvl[i][j].type != 10)
    {
      lvl[i][j]=verif_case(lvl,L,i,j);
      j=j+1;
    }   
    j=0;
  }
  return lvl;
}
piece verif_case(piece** lvl,liste L,int i,int j)
{
  int x;
  int y;
  int hauteurL;
  y=0;
  x=0;
  bool continuer=true;
  while ( continuer )
  {
    hauteurL=L->elem[0][0].hauteur;
    for ( y=0;y<hauteurL;y++)
    {
      while ( L->elem[y][x].type!=10)
      {
        
        if ( L->elem[y][x].type == 35 ){
          if(L->elem[y][x].pos.x == lvl[i][j].pos.x){
            if(L->elem[y][x].pos.y == lvl[i][j].pos.y){
              lvl[i][j].couvert=true;   
             
            }
          }
        }
        x=x+1;
      }
      x=0;      
    } 
    if (is_empty(rest(L))){
      continuer=false;
    }else{
      L=rest(L); 
    }
  }
  return lvl[i][j];
}

piece** vidage(piece** lvl)
{
  int i,j,hauteur;
  hauteur=lvl[0][0].hauteur;
  i=0;
  j=0;

  for ( i=0 ; i<hauteur ; i++ )
  {
    while ( lvl[i][j].type != 10 )
    {
      if ( lvl[i][j].type == 35 ) {
        lvl[i][j].couvert=false;
      }
      if ( lvl[i][j].type == 32 ) {
        lvl[i][j].couvert=true;
      }
      j=j+1;
    }
    j=0;
  }
  return lvl;
}

void affiche_fin()
{
  TextSurface = TTF_RenderText_Blended(Font, "YOU WIN !!", TextColor);
  SDL_BlitSurface(TextSurface, NULL, screen, &DstRect);
  if ( color == 1 ) {
    TextColor.r -= 1;
    TextColor.g -= 1;
    TextColor.b -= 1;
    if ( TextColor.r < 20 ) {
      color = 0;
    } 
  }
  if ( color == 0 ){
    TextColor.r += 1;
    TextColor.g += 1;
    TextColor.b += 1;
    if ( TextColor.r > 250 ) {
      color = 1;
    } 
  } 
}
