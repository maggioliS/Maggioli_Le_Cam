#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "piece.h"

int **rempliTab(FILE *fichier);

int main(int argc, char *argv[]) {
  FILE *fichier = NULL;
  fichier = fopen("jeu.txt","r");
  fseek(fichier,0,SEEK_SET);

  int **niv;
  niv = rempliTab(fichier);

  liste_piece pieces;
  pieces = l_vide();

  while (fichier != NULL) 
  { 
    printf("OK\n");
    pieces->tableau = rempliTab(fichier);
    printf("YE\n");
    if (is_empty(rest(pieces))) {
      printf("VIDE");
    }
    pieces = rest(pieces);
  }

  fclose(fichier);

  //free;
  return 0;
}






