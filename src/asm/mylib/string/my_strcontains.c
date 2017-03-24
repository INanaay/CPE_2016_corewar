/*
** my_strcontains.c for my_lib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 16:23:27 2017 nathan
** Last update Thu Mar 23 16:18:25 2017 nathan
*/

#include "mylib/my_string.h"

int	my_strisintab(char *str, char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    {
      if (my_strcmp(str, tab[x]) == 0)
	return (x);
      x++;
    }
  return (- 1);
}

int	my_strcontains_separators(char *str)
{
  int	x;
  int	count;

  x = 0;
  count = 0;
  while (str[x])
    {
      if (str[x] == ' ' || str[x] == '\n')
	count++;
      x++;
    }
  return (count);
}

int	my_strcontains_nonalpha(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] < '0' ||
	  str[x] > '9' && str[x] < 'A' ||
	  str[x] > 'Z' && str[x] < 'a' ||
	  str[x] > 'z')
	return (1);
      x++;
    }
  return (0);
}
int	my_strcontains_nonnum(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] < '0' || str[x] > '9' || str[x] == '-' || str[x] == '+')
	return (1);
      x++;
    }
  return (0);
}

int	my_strcontains(char *str, char c)
{
  int	x;
  int	count;

  x = 0;
  count = 0;
  while (str[x])
    {
      if (str[x] == c)
	count++;
      x++;
    }
  return (count);
}
