#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "piece.h"


liste_piece l_vide (void)
{
  return NULL;
}


liste_piece cons ( int** T, liste_piece P)
{
  liste_piece P2;
  P2 = malloc(sizeof(*P2));
  P2->tableau = T;
  P2->piece_suivante = P;
  return P2;
}


bool is_empty ( liste_piece P) 
{ 
  return P==NULL;
}


int** first ( liste_piece P) 
{ 
  if (is_empty(P)) 
  {
    printf("Calcul of first on empty list !\n");
    exit(0);
  }
  return P->tableau;
}


liste_piece rest (liste_piece P)
{
printf("OY");
  return P->piece_suivante;
}

/*void free_list (liste_piece P) 
{
  if (is_emplty(P)) 
  { 
    return;
  }
  free_tab(P->tableau);
  free_list(rest(P));
}


void free_tab(int** tableau)
{
  int i;
  for (i = 0; i < lig; i++) 
  {
    free(tableau[i]);
  }
  free(col);
}*/










