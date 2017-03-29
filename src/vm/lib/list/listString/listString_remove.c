/*
** listString_remove.c for lib in /home/flavian.gontier/projects/libmy/src/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:22:50 2017 flavian gontier
** Last update Sun Mar 12 18:03:06 2017 flavian gontier
*/

#include "libmy.h"

/*
** remove the first element encountered from the beginning
*/
void		listString_remove(listString *list, char *elem)
{
  register int	index;
  char		*temp;
  int		count;

  index = 0;
  while (index < list->count)
    {
      temp = list->elements[index];
      if (my_strcmp(temp, elem) == 0)
	break ;
      index = index + 1;
    }
  count = (list->count - index) - 1;
  while (index < count)
  {
    my_strcpy(list->elements[index], list->elements[index + 1]);
    index = index + 1;
  }
  list->count = list->count - 1;
}
