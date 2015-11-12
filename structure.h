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
  int couvert;
  int visible;
  char type;

} piece ;

struct Liste {

  piece** elem;
  liste next;  

};

liste l_vide ( void );
liste cons(piece** tab,liste L);
bool is_empty (liste L);
piece ** first( liste L);
liste rest ( liste L );
piece ** createlvl(FILE* F,piece** tab);
int comptehauteur (FILE *F);
piece** allocation(FILE *F);

#endif
