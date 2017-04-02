/*
** my_putconcat.c for mylib in /home/nathan/projects/tmptetris/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Mar 16 13:27:55 2017 nathan
** Last update Thu Mar 16 13:28:47 2017 nathan
*/

#include <unistd.h>
#include <stdarg.h>
#include "mylib/my_string.h"

void		my_putconcat(int out, int argnbr, ...)
{
  va_list	list;
  int		i;

  i = 0;
  va_start(list, argnbr);
  while (i < argnbr && list != NULL)
    {
      if (out == 1)
	my_putstr(va_arg(list, char *));
      else if (out == 2)
	my_puterr(va_arg(list, char *));
      i++;
    }
  va_end (list);
}
