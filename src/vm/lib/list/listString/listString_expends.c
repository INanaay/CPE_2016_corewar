/*
** listString_expends.c for lib in /home/flavian.gontier/projects/libmy/src/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 02:45:03 2017 flavian gontier
** Last update Sun Mar 12 12:47:04 2017 flavian gontier
*/

#include "libmy.h"

void		listString_expends(listString *list)
{
  char		**new;

  new = malloc(sizeof(char *) * (list->capacity * 2));
  my_memcpy(new, list->elements, list->count * sizeof(char *));
  free(list->elements);
  list->elements = new;
  list->capacity = list->capacity * 2;
}
