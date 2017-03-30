/*
** my_freetab.c for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sat Jan 21 14:12:37 2017 flavian gontier
** Last update Sun Jan 22 05:39:16 2017 flavian gontier
*/

#include <stdlib.h>

void	my_freetab(char **tab)
{
  register int	index;

  index = 0;
  while (tab[index] != 0)
    {
      free(tab[index]);
      index = index + 1;
    }
  free(tab);
}
