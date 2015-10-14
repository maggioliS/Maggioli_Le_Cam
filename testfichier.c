#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int **rempliTab(FILE *fichier);

int main(int argc, char *argv[]) {
  FILE *fichier = NULL;
  fichier = fopen("jeu.txt","r");
  fseek(fichier,0,SEEK_SET);
  int **niv;
  niv = rempliTab(fichier);
  fclose(fichier);
  printf("%d ",niv[0][0]);
  printf("%d ",niv[0][1]);
  printf("%d ",niv[0][2]);
  printf("%d\n",niv[0][3]);

  printf("%d ",niv[1][0]);
  printf("%d ",niv[1][1]);
  printf("%d ",niv[1][2]);
  printf("%d\n",niv[1][3]);

  printf("%d ",niv[2][0]);
  printf("%d ",niv[2][1]);
  printf("%d ",niv[2][2]);
  printf("%d\n",niv[2][3]);

  printf("%d ",niv[3][0]);
  printf("%d ",niv[3][1]);
  printf("%d ",niv[3][2]);
  printf("%d\n",niv[3][3]);

  printf("%d ",niv[4][0]);
  printf("%d ",niv[4][1]);
  printf("%d ",niv[4][2]);
  printf("%d\n",niv[4][3]);
  free(niv);
  return 0;
}

int **rempliTab(FILE *fichier) {
  int l = 5 ;
  int c = 4 ;
  int i;
  int **niveau = (int**)malloc(l * c * sizeof(int*));
  for (i = 0; i < l; i++) 
  {
    niveau[i] = (int*)malloc(l * sizeof(int));
  }
  int cara ;
  int cara2;
  int lig = 0;
  int col = 0;
  bool continuer = true;
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
  return &*niveau;
}


/*void free(lig, tableau ) {
  int i;
  for (i = 0; i < lig; i++) 
  {
    free(tableau[i]);
  }
  free(m);
}*/

