/*
** my_tabdup.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 17:25:43 2016 flavian gontier
** Last update Sat Jan 21 00:24:54 2017 flavian gontier
*/

#include "libmy.h"

char	**my_tabdup(char **tab)
{
  char		**result;
  t_coord	dim;
  register int	line;

  dim = my_tabdim(tab);
  result = my_calloc(sizeof(char *) * (dim.y + 1));
  if (result == NULL)
    return (NULL);
  line = 0;
  while (line < dim.y)
    {
      result[line] = my_strdup(tab[line]);
      line = line + 1;
    }
  return (result);
}
