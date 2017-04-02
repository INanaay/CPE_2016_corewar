/*
** my_tabelem.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell1
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Thu Jan 19 22:53:57 2017 flavian gontier
** Last update Sat Jan 21 00:25:07 2017 flavian gontier
*/

#include <stdlib.h>
#include "libmy.h"

char		*my_tabelem(char **tab, char *name)
{
  register int	index;
  int		len;

  len = my_strlen(name);
  index = 0;
  while (tab[index] != 0)
    {
      if (my_strncmp(tab[index], name, len) == 0)
	return (&tab[index][len]);
      index = index + 1;
    }
  return (NULL);
}
