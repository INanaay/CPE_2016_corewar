/*
** my_strtowtb.c for my_lib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 16:17:59 2017 nathan
** Last update Thu Mar 23 16:19:27 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"

void	my_strform(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] == '\n' || str[x] == ' ')
	str[x] = 0;
      x++;
    }
}

char	**my_strtowtb(char *str)
{
  int	nb_sp;
  int	x;
  char	**tab;

  x = 0;
  nb_sp = my_strcontains_separators(str);
  if ((tab = malloc(sizeof(char *) * (nb_sp + 2))) == NULL)
    return (NULL);
  tab[nb_sp + 1] = 0;
  my_strform(str);
  while (x < nb_sp + 1)
    {
      tab[x++] = str;
      str += my_strlen(str) + 1;
    }
  return (tab);
}

void	my_strformchar(char *str, char c)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] == c)
	str[x] = 0;
      x++;
    }
}

char	**my_strtowtb_sc(char *str, char c)
{
  int	nb_sp;
  int	x;
  char	**tab;

  x = 0;
  nb_sp = my_strcontains(str, c);
  if ((tab = malloc(sizeof(char *) * (nb_sp + 2))) == NULL)
    return (NULL);
  tab[nb_sp + 1] = 0;
  my_strformchar(str, c);
  while (x < nb_sp + 1)
    {
      tab[x++] = str;
      str += my_strlen(str) + 1;
    }
  return (tab);
}
