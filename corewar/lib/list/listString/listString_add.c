/*
** listString_add.c for lib in /home/flavian.gontier/projects/libmy/src/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:11:02 2017 flavian gontier
** Last update Mon Mar 13 23:44:57 2017 flavian gontier
*/

#include "libmy.h"

void	listString_add(listString *list, char *elem)
{
  if (list->count == list->capacity)
    {
      listString_expends(list);
    }
  list->elements[list->count] = elem;
  list->count = list->count + 1;
}
