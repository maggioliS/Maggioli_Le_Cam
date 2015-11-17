#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <SDL.h>

typedef struct Liste *liste;

typedef struct {

  SDL_Rect pos;
  SDL_Rect posbmp;
  int hauteur;
  int longueur;
  char carac;
  bool couvert;
  int visible;
  char type;

} piece ;

struct Liste {

  piece** elem;
  liste next;
  liste head;  

};

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
liste create_piece(liste L,FILE *F);
int longueurmax(piece** P);
liste place_piece(liste L,piece** lvl);
void affichage_liste ( liste objet ,SDL_Surface *screen, SDL_Surface *pie);
void verif_fichier(FILE *F);
void free_list (liste L);


#endif
