#include <stdio.h>
#include "fonctioncompte.h"
int compteligne(FILE*fichier, int i) 
{
 
  int caract = fgetc(fichier);
  while ( caract != 10 & fgetc(fichier) != 10) 
  {
    fseek(fichier,-1,SEEK_CUR);
    while ( caract != 10 ) 
    {
      caract = fgetc(fichier);
      printf("OUI  ");
    }
    if ( caract == 10 ) 
    {
      printf("NON  ");
      i = i + 1;
      caract = fgetc(fichier);
    }
  }
return i;
}


int comptecol(FILE*fichier, int j) 
{
  int mem = 0;
  int caract = fgetc(fichier);
  while ( caract != 10 & fgetc(fichier) != 10) 
  {
    fseek(fichier,-1,SEEK_CUR);
  
    while ( caract != 10 ) 
    {
      j = j + 1;
      caract = fgetc(fichier);
      printf("OUI  ");
    }
    if ( caract == 10 ) 
    {
      if (j >= mem) 
      {
        mem = j;
      }
      j = 0;
      printf("NON  ");
      caract = fgetc(fichier);
    }
  }
  j = mem;
  return j;
}
