/*
** listInt32_init.c for lib in /home/flavian.gontier/projects/libmy/src/list/listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 00:54:56 2017 flavian gontier
** Last update Sun Feb 12 16:44:27 2017 flavian gontier
*/

#include "libmy.h"

void	listInt32_init(listInt32 *list)
{
  if (list == NULL)
    {
      return ;
    }
  list->count = 0;
  list->elements = malloc(sizeof(int32_t) * (DEFAULT_CAPACITY + 1));
  if (list->elements == NULL)
    {
      return ;
    }
  list->capacity = DEFAULT_CAPACITY;
}
