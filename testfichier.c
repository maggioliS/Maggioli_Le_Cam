#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  bool continuer = true;
  int i = 0;
  int j = 0;
  FILE* fichier = NULL;
  int caractereActuel = 0;
  long pos =0;
  fichier = fopen("jeu.txt", "r");
  int niveau[20][20];
  while (continuer)
  {
    caractereActuel = fgetc(fichier); 
    niveau[i][j] = caractereActuel;
    caractereActuel = fgetc(fichier);
    if (niveau[i][j] == 10 &  caractereActuel == 10 )
    {
      continuer = false;
    }   
    printf("%c", niveau[i][j]); 
    i++;
    if (niveau[i-1][j] == 10 & caractereActuel != 10)
    {
      j++;
      i=0;
    }
    fseek(fichier,-1,SEEK_CUR);
  }
  fclose(fichier);


  //printf("%d%d%d\n",tab[44],tab[45],tab[46]);
  return 0;
}
