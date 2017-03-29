/*
** my_strdup.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Wed Dec 21 17:43:24 2016 flavian gontier
** Last update Mon Mar 20 15:56:37 2017 nathan
*/
#include <unistd.h>
#include "libmy.h"

char		*my_strdup(char *str)
{
  register int	index;
  char		*result;
  int		len;

  len = my_strlen(str);
  if (len == 0)
    return (NULL);
  result = my_calloc(sizeof(char) * (len + 1));
  if (result == NULL)
    return (NULL);
  index = 0;
  while (index != len)
    {
      result[index] = str[index];
      index = index + 1;
    }
  result[index] = 0;
  return (result);
}
