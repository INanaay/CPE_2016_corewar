/*
** listString_init.c for lib in /home/flavian.gontier/projects/libmy/src/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 00:54:56 2017 flavian gontier
** Last update Sun Mar 12 18:02:44 2017 flavian gontier
*/

#include "libmy.h"

void	listString_init(listString *list)
{
  if (list == NULL)
    {
      return ;
    }
  list->count = 0;
  list->elements = malloc(sizeof(char *) * (LIST_CAPACITY + 1));
  list->capacity = DEFAULT_CAPACITY;
}
