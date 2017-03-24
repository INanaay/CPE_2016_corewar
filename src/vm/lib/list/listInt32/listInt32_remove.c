/*
** listInt32_remove.c for lib in /home/flavian.gontier/projects/libmy/src/list/listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:22:50 2017 flavian gontier
** Last update Sun Feb 12 16:49:29 2017 flavian gontier
*/

#include "libmy.h"

/* remove the first element encountered from the beginning */
void		listInt32_remove(listInt32 *list, int32_t elem)
{
  register int	index;
  int		count;

  index = 0;
  while (index < list->count)
    {
      if (list->elements[index] == elem)
	break ;
      index = index + 1;
    }
  count = (list->count - index);
  if (index != list->count - 1)
    my_memcpy(&list->elements[index], &list->elements[index + 1], count);
  list->count = list->count - 1;
}
