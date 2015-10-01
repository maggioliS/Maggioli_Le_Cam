/*******************************************/
/* MAGGIOLI Steve                          */
/* LE CAM Doriane                          */
/* gestli.c                                */
/*                     			   */
/*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* prototypes */
s_list_ptr l_vide (void) ;
s_list_ptr cons (s_sprite_t x, s_list_ptr L) ;
bool is_empty (s_list_ptr L) ;
s_sprite_t first (s_list_ptr L) ;
s_list_ptr rest (s_list_ptr L) ;
void free_list (s_list_ptr L) ;
s_list_ptr del(s_list_ptr L);

/* Constructors */
/*******************************************/
/* l_vide                                  */
/*******************************************/
s_list_ptr l_vide (void)
{
  return NULL ;
}
/*******************************************/
/* cons 				   */
/*******************************************/
s_list_ptr cons (s_sprite_t x, s_list_ptr L)
{
  s_list_ptr M ;
/* Réservation de la place mémoire nécessaire pour une case */
  M = malloc (sizeof (*M)) ;
  M->object = x ;
  M->next = L ;
  return M ;
}
/* Accès */
/*******************************************/
/* is empty				   */
/*******************************************/
bool is_empty (s_list_ptr L)
{
  return L == NULL ;
}
/*******************************************/
/* first				   */
/*******************************************/
s_sprite_t first (s_list_ptr L)
{
  if ( is_empty (L) ) {
      printf ("Calcul of first on empty list !\n") ;
      exit (0) ;
  }
  return L->object ;
}
/*******************************************/
/* rest					   */
/*******************************************/
s_list_ptr rest (s_list_ptr L)
{
  return L->next ;
}
/*******************************************/
/* free list 				   */
/*******************************************/
void free_list (s_list_ptr L)
{
  if ( is_empty (L) ) {
    return ;
  }
  free_list (rest (L)) ;
}
/*******************************************/
/* del					   */
/*******************************************/
s_list_ptr del(s_list_ptr L) 
{ 
/* empty list, nothing to delete */
  if (L == NULL) {
    return NULL;
  }
/* If object had to be delete */
  if(L->object.life == 0) {
/* Delete and save next */
    s_list_ptr tmp = L->next;
    free(L);
    tmp = del(tmp);
    return tmp;
  } else {
    L->next = del(L->next);
    return L;
  }
}

}
