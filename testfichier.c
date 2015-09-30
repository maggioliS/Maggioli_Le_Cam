#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE* fichier = NULL;
  int caractereActuel = 0;
  long pos =0;
  fichier = fopen("test.txt", "r");
 
  if (fichier != NULL)
  {
    do
    {
      caractereActuel = fgetc(fichier);
      if (caractereActuel == "")
      {
        pos = ftell(fichier);
        printf("%li", pos);
      }      
      printf("%c", caractereActuel);
      
    } while (caractereActuel != EOF); 
    fclose(fichier);
  } 
  return 0;
}
