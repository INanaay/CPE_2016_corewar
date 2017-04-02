/*
** my_strcompare.c for my_lib in /home/nathan/PSU_2016_minishell1
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 18:03:22 2017 nathan
** Last update Tue Mar 28 13:21:38 2017 nathan
*/

#include <unistd.h>
#include "mylib/my_string.h"

int	my_strcmp(char *model, char *comparor)
{
  int	x;
  int	y;
  int	len_m;
  int	len_c;
  int	count;

  x = 0;
  y = 0;
  if (model == NULL)
    return (my_strlen(comparor));
  if (comparor == NULL)
    return (my_strlen(model));
  len_m = my_strlen(model);
  len_c = my_strlen(comparor);
  count = (len_m <= len_c) ? len_c - len_m : len_m - len_c;
  while (model[x] && comparor[y])
    {
      if (model[x] != comparor[y])
	count++;
      x++;
      y++;
    }
  return (count);
}
