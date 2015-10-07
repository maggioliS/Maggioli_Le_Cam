#include <stdio.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{
  bool continuer = true;
  FILE* fichier = NULL;
  int caractereActuel = 0;
  long pos = 0;

  fichier = fopen("jeu.txt", "r");
  fseek(fichier,0,SEEK_SET);
  int niveau[50][50] = {0};
  int lig = 0;
  int col = 0;

  while (continuer == true)
  { 
    caractereActuel = fgetc(fichier);
    niveau[lig][col] = caractereActuel;
    printf("%c", niveau[lig][col]);
    caractereActuel = fgetc(fichier);
    if (niveau[lig][col] == '\n' & caractereActuel == '\n' )
    {
      continuer = false;
    }   
    else 
    {
     if  (niveau[lig][col] != '\n' & caractereActuel == '\n')
      {
        lig++;
        col=0;
      }
      else
      { 
        if (niveau[lig][col] != 10 & caractereActuel != 10)
        {
          col++; 
        }
      }         
    }
    fseek(fichier,-1,SEEK_CUR);
  }
  fclose(fichier);

  return 0;
}
