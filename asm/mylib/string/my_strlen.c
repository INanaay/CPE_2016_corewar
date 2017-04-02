/*
** my_strlen.c for my_lib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 15:23:56 2017 nathan
** Last update Wed Jan 25 12:45:09 2017 nathan
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  if (str == NULL)
    return (0);
  while (str[x])
    x++;
  return (x);
}
