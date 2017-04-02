/*
** my_strlen.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 16:53:46 2016 flavian gontier
** Last update Mon Jan 23 17:05:20 2017 flavian gontier
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  register int	iterator;

  iterator = 0;
  if (str == NULL)
    return (0);
  while (str[iterator] != 0)
    {
      iterator = iterator + 1;
    }
  return (iterator);
}
