/*
** my_tabdim.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 17:38:06 2016 flavian gontier
** Last update Fri Feb 17 12:31:18 2017 flavian gontier
*/

#include "libmy.h"

t_coord		my_tabdim(char **tab)
{
  register int	line;
  register int	column;
  t_coord	result;
  int		temp;

  line = 0;
  column = 0;
  temp = 0;
  while (*tab[line] != 0)
    {
      column = 0;
      while (tab[line][column] != 0)
	{
	  column = column + 1;
	}
      if (column > temp)
	temp = column;
      line = line + 1;
    }
  result.x = temp;
  result.y = line;
  return (result);
}
