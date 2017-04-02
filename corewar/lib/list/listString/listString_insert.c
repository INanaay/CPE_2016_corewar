/*
** listString_insert.c for lib in /home/flavian.gontier/projects/libmy/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 03:21:59 2017 flavian gontier
** Last update Sun Mar 12 19:14:29 2017 flavian gontier
*/

#include "libmy.h"

void	listString_insert(listString *list, char *elem, size_t index)
{
  char		**new;

  if (list->count == list->capacity)
    listString_expends(list);
  new = malloc(sizeof(char *) * list->capacity);
  my_tabncpy(new, list->elements, index);
  new[index] = my_strdup(elem);
  my_tabncpy(&new[index + 1], &list->elements[index], list->count - index);
  free(list->elements);
  list->elements = new;
  list->count = list->count + 1;
}
