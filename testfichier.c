#include <stdio.h>
#include <stdbool.h>
#include "fonctioncompte.h"



int main(int argc, char *argv[])
{
  int i = 0;
  int j = 0;
  int k = 0;
  bool continuer = true;
  FILE* fichier = NULL;
  int caractereActuel = 0;
  long pos = 0;


  fichier = fopen("jeu.txt", "r");

  i = compteligne(fichier,i);
  fseek(fichier,k,SEEK_SET);
  j = comptecol(fichier,j);
  fseek(fichier,0,SEEK_SET);
  printf("%d %d\n",i,j);
  int niveau[i][j];
  int lig = 0;
  int col = 0;

  while (continuer)
  {
    caractereActuel = fgetc(fichier); 
    niveau[lig][col] = caractereActuel;
    caractereActuel = fgetc(fichier);
    if (niveau[lig][col] == 10 &  caractereActuel == 10 )
    {
      continuer = false;
    }   
    printf("%c", niveau[lig][col]); 
    i++;
    if (niveau[lig-1][col] == 10 & caractereActuel != 10)
    {
      col++;
      lig=0;
    }
    fseek(fichier,-1,SEEK_CUR);
  }
  fclose(fichier);


  return 0;
}
