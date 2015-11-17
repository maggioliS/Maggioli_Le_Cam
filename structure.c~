#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include "structure.h"

liste l_vide ( void );
liste cons(piece** tab,liste L);
bool is_empty (liste L);
piece ** first( liste L);
liste rest ( liste L );
piece ** createlvl(FILE* F,piece** tab);
int comptehauteur (FILE *F);
piece** allocation(FILE *F);
void affichage ( piece** lvl,SDL_Surface *screen , SDL_Surface *cube) ;
liste create_list_piece(FILE *F);
void affichage ( piece** lvl ,SDL_Surface *screen, SDL_Surface *cube) ;
liste create_piece(liste L,FILE *F);


liste l_vide ( void )
{
  return NULL ;
}

liste cons(piece** tab,liste L)
{
  liste M;
  M = malloc (sizeof(*M));
  M->elem=tab;
  M->next = L ;
  return M ;
}

bool is_empty (liste L)
{
  return L== NULL ;
}

piece ** first( liste L)
{
  if ( is_empty (L)){
    printf("list empty, calcul impossible\n");
    exit(0);
  }
  return L->elem;
}

liste rest ( liste L )
{
  return L->next;
}

piece** allocation(FILE *F)
{
  int hauteur = comptehauteur(F);
  piece **tab = (piece **)malloc(sizeof(piece*)*hauteur);
  piece *tab2 = (piece *)malloc(sizeof(piece)*30*hauteur);
  for (int i=0;i<hauteur;i++)
  {
    tab[i] = &tab2[i*30];
  }
  return tab;
}

piece **createlvl(FILE* F,piece** tab)
{
  long position = ftell(F);
  if (F==NULL){
    printf("erreur fichier vide");
    return 0 ;
  }
  char chaine[30] = "";
  int carac;
  int i,j,tmp;
  i=0;
  j=0;
  tmp=0;
  fseek(F,position,SEEK_SET);
  int hauteur = comptehauteur(F);
  fseek(F,position,SEEK_SET);
  fgets(chaine,30,F);
  for (tmp=0;tmp < hauteur;tmp++)
  {
    carac=chaine[j];
    while (carac !=10) 
    {
      tab[tmp][j].hauteur=hauteur;
      tab[tmp][j].carac=carac;
      tab[tmp][j].pos.x=j*32;
      printf("x: %d --- ",tab[tmp][j].pos.x);
      tab[tmp][j].pos.y=tmp*24;
      printf("y: %d --- ",tab[tmp][j].pos.y);
      tab[tmp][j].posbmp.x=0;
      tab[tmp][j].posbmp.y=0;
      tab[tmp][j].couvert=0;
      tab[tmp][j].visible=1;
      if (carac == 35 ) {
        tab[tmp][j].type=35;
      }
      if (carac == 32 ) {
        tab[tmp][j].type=32;
      }      
      printf("type: %d \n",tab[tmp][j].type);
      j=j+1;
      carac = chaine[j] ;
      if (carac== 10){
        tab[tmp][j].type=10;
      }
    }
    fgets(chaine,30,F);
    j=0;
  }

  return tab ;
}

int comptehauteur (FILE *F)
{
  int tmp;
  char chaine[30]= "";
  if (F==NULL){
    return 0;
  }
  fgets(chaine,30,F);
  if (chaine[0] == 10){
    return 0 ;
  }
  tmp=1;
  while ( chaine[0] !=10 )
  {
    tmp=tmp+1;
    fgets(chaine,30,F);
  }
  printf("%d\n",tmp);
  return tmp-1 ;
}

void affichage ( piece** lvl ,SDL_Surface *screen, SDL_Surface *cube) 
{
  int i,j,hauteur;
  hauteur = lvl[0][0].hauteur ;
  i=0;
  j=0;
  for (i=0;i<hauteur;i++)
  {
    while (lvl[i][j].type != 10)
    {
      if (lvl[i][j].type==35){
        SDL_BlitSurface(cube,NULL,screen,&lvl[i][j].pos);
      }
      printf("je passe : %d\n",i);
      j=j+1;
    }
  j=0;
  }
}
liste create_piece(liste L,FILE *F)
{
  piece** tab ;
  long position = ftell(F) ; 
  tab=allocation(F) ;
  fseek(F,position,SEEK_SET);
  tab=createlvl(F,tab);
  L=cons(tab,L);
  
  return L;
}
liste create_list_piece(FILE *F)
{
  liste L;
  L=l_vide();

  int caractereActuel;
  caractereActuel=fgetc(F);
  fseek(F,-1,SEEK_CUR);
  while (caractereActuel != EOF )
  {   
    L=create_piece(L,F);
    caractereActuel=fgetc(F);
    fseek(F,-1,SEEK_CUR);
  }
  return L;
}
int longueurmax(piece** P)
{
  int L=0;
  int hauteur = P[0][0].hauteur ;
  int i=0;
  int j=0;

  for (i=0;i<hauteur;i++)
  {
    while (P[i][j].type != 10)
    {
      j=j+1;
    }
    if (L<j){
      L=j;
    }
    
    j=0;
  } 
  return L;
}
liste place_piece(liste L,piece** lvl)
{
  liste Lcopy ;
  int longueurlvl,hauteurmax;
  int hauteurlvl = 0;
  int i,j;
  int hauteur;
  longueurlvl= longueurmax(lvl)+1;
  hauteur = L->elem[0][0].hauteur;
  int continuer=1;
  hauteurmax=0;
  if (is_empty(L)){
    continuer=0;
  }
  while (continuer==1)
  {
    if (((longueurlvl+longueurmax(L->elem))*32)>790){
      longueurlvl = longueurmax(lvl);
      hauteurlvl =  hauteurlvl+hauteurmax+1 ;
      if (hauteurlvl>lvl[0][0].hauteur){
        longueurlvl=0;
      }
    }
    for (i=0;i<hauteur;i++)
    {
      while (L->elem[i][j].type != 10)
      {
        L->elem[i][j].pos.x=(longueurlvl+j)*32;
        L->elem[i][j].pos.y=(hauteurlvl+i)*24;
        j=j+1;
      }
      j=0;
    }
    Lcopy=cons(L->elem,Lcopy);
    longueurlvl=longueurlvl+longueurmax(L->elem)+1;
    if(is_empty(rest(L))){
      continuer = 0 ;
    }else {
      L=rest(L);
      hauteur=L->elem[0][0].hauteur ;
      if (hauteurmax < L->elem[0][0].hauteur){
        hauteurmax=L->elem[0][0].hauteur ;
      }
    }
    
  }  
  return Lcopy;
}
