/*
** my_getenv.c for mylib in /home/nathan/projects/mylib/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sat Mar 18 13:54:50 2017 nathan
** Last update Wed Mar 22 13:23:05 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"

char		*my_getenv(char *find)
{
  extern char	**environ;
  int		x;

  x = 0;
  while (environ[x] != NULL)
    {
      if (str_isatstartof(find, environ[x]) != -1)
	return (environ[x]);
      x++;
    }
  return (NULL);
}
