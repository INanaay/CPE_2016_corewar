/*
** epurstr.c for mylib in /home/nathan/projects/CPE_2016_corewar/src/asm/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:45:05 2017 nathan
** Last update Fri Mar 24 19:54:39 2017 nathan
*/
#include <stdlib.h>
#include "mylib/my_mem.h"
#include "mylib/my_string.h"

char	*my_epurstr(char *str)
{
  int	x;
  int	y;
  int	spaces;
  char	*new_str;

  x = 0;
  y = 0;
  if (str == NULL)
    return (NULL);
  spaces = my_strcontains(str, ' ');
  spaces += my_strcontains(str, '\t');
  new_str = my_calloc(sizeof(char), my_strlen(str) - spaces + 1);
  if (new_str == NULL)
    return (NULL);
  while (str[x])
    {
      if (str[x] != ' ' && str[x] != '\t')
	new_str[y++] = str[x];
      x++;
    }
  free(str);
  return (new_str);
}
