/*
** my_strcpy.c for mylib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Jan 25 12:36:38 2017 nathan
** Last update Wed Jan 25 12:38:56 2017 nathan
*/

#include <stdlib.h>

void	my_strcpy(char *from, char *to)
{
  int	x;

  x = 0;
  while (from != NULL && from[x])
    {
      to[x] = from[x];
      x++;
    }
}
