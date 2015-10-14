#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "remplir_tab.h"

int **rempliTab(FILE *fichier) {
  int l = 10 ;
  int c = 10 ;
  int i;
  int cara ;
  int cara2;
  int lig = 0;
  int col = 0;
  bool continuer = true;

  int **niveau = (int**)malloc(l * c * sizeof(int*));
  for (i = 0; i < l; i++) 
  {
    niveau[i] = (int*)malloc(l * sizeof(int));
  }

printf("PASSE 1 \n");
  while (continuer) 
  {
    cara = fgetc(fichier);
    niveau[lig][col] = cara;
    printf("%c",niveau[lig][col]);
    cara2 = fgetc(fichier);
    if (niveau[lig][col] == '\n' & cara2 == '\n') 
    {
      continuer = false;
    } 
    else
    {
      if ( niveau[lig][col] != '\n' & cara2 == '\n')
      {
	lig++;
	col = 0;
      }
      else 
      {
	if ( niveau[lig][col] != '\n' & cara2 != '\n')
        {
	  col++;
	}
      }
    }
    fseek(fichier,-1,SEEK_CUR);
  }
printf("PASSE 2\n");
  return niveau;
}
