/*
** my_calloc.c for mylib in /home/nathan/projects/raytracer1/mylib/mem
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Mon Feb 13 12:18:48 2017 nathan
** Last update Mon Mar 27 00:49:00 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"
#include "mylib/define.h"

void	*my_memset(void *ptr, int c, int size)
{
  int	x;
  char	*tmp;

  tmp = ptr;
  x = 0;
  while (x != size)
    tmp[x++] = c;
  return (tmp);
}

void	*my_calloc(size_t size, int nb_elem)
{
  void	*ptr;
  int	fsize;

  fsize = size * nb_elem;
  if ((ptr = malloc(fsize)) == NULL)
    {
      my_puterr(MEM_FAIL);
      return (NULL);
    }
  ptr = my_memset(ptr, 0, fsize);
  return (ptr);
}

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*new;

  if ((new = my_calloc(sizeof(char), (size + 2))) == NULL)
    return (NULL);
  if (str == NULL)
    return (new);
  i = 0;
  while (str[i])
    {
      new[i] = str[i];
      i = i + 1;
    }
  return (new);
}
