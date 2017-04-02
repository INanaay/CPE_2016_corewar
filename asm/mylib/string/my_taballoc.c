/*
** my_taballoc.c for mylib in /home/nathan/PSU_2016_minishell1/commands
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Jan 20 16:41:31 2017 nathan
** Last update Sat Jan 21 08:01:48 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"

void		wtb_merge(char **from, char **to, int from_len, int total_len)
{
  static int	len = 0;
  int		x;

  x = 0;
  while (x < from_len)
      to[len++] = from[x++];
  if (len == total_len)
    len = 0;
}

char	**wtb_alloc(int len)
{
  char	**wtb;

  if ((wtb = malloc(sizeof(char *) * (len + 1))) == NULL)
      return (NULL);
  wtb[len] = 0;
  return (wtb);
}
