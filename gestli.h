/*******************************************/
/* MAGGIOLI Steve                          */
/* LE CAM Doriane                          */			   
/*******************************************/

#ifndef GESTLI_H
#define GESTLI_H
#include "SDL.h"
#include "sprite.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list *s_list_ptr ;
struct s_list {
  s_sprite_t object ;
  s_list_ptr next ;
} ;

/***************************/
/*  Function prototypes    */
/***************************/
s_list_ptr l_vide (void) ;
s_list_ptr cons (s_sprite_t , s_list_ptr) ;
bool is_empty (s_list_ptr) ;
s_sprite_t first (s_list_ptr) ;
s_list_ptr rest (s_list_ptr) ;
void free_list (s_list_ptr) ;
s_list_ptr del(s_list_ptr);

#endif /*GESTLI_H */
