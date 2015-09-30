#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  bool continuer = true;
  int i = 0;
  FILE* fichier = NULL;
  int caractereActuel = 0;
  long pos =0;
  fichier = fopen("jeu.txt", "r");
  int niveau[46];
  while (continuer)
  {
    caractereActuel = fgetc(fichier); 
    niveau[i] = caractereActuel;
    caractereActuel = fgetc(fichier);
    if (niveau[i] == 10 &  caractereActuel == 10 )
    {
      continuer = false;
    }   
    fseek(fichier,-1,SEEK_CUR);
    printf("%c", niveau[i]); 
    i++;
  }
  fclose(fichier);


  //printf("%d%d%d\n",tab[44],tab[45],tab[46]);
  return 0;
}
