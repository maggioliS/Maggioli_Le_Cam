#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>


typedef struct list_piece *liste_piece;
struct list_piece {
  int **tableau;
  liste_piece piece_suivante;
};
  

liste_piece l_vide (void);
liste_piece cons ( int **, liste_piece);
bool is_empty ( liste_piece );
int** first (liste_piece);
liste_piece rest (liste_piece);
/*void free_list (liste_piece);
void free_tab(int**);*/
#endif
