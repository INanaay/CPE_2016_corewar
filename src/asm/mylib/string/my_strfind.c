/*
** my_strfind.c for mylib in /home/nathan/PSU_2016_minishell1/commands
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Jan 20 11:51:53 2017 nathan
** Last update Tue Mar 28 13:02:52 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"
#include "mylib/define.h"

int	str_isatstartof(char *find, char *in)
{
  int	x;

  if (find == NULL || in == NULL)
    return (- 1);
  x = 0;
  if (my_strlen(in) < my_strlen(find))
    return (- 1);
  while (find[x])
    {
      if (find[x] != in[x])
	return (- 1);
      x++;
    }
  return (x);
}

uint8_t	find_intab(char *str, char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    {
      if (my_strcmp(str, tab[x]) == 0)
	return (SUCCESS);
      x++;
    }
  return (FAIL);
}

char	*str_isafter(int pos, char *in)
{
  char	*result;
  if (in == NULL)
    return (NULL);
  if (my_strlen(in) >= (pos))
    result = in + pos;
  else
    result = NULL;
  return (result);
}
