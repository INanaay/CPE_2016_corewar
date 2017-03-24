/*
** binary_base.c for my_printf in /home/nathan/PSU_2016_my_printf/lib/utils
**
** Made by nathan schwarz
** Login   <nathan@epitech.net>
**
** Started on  Sat Nov 12 17:44:44 2016 nathan schwarz
** Last update Fri Nov 18 16:09:08 2016 nathan schwarz
*/

#include "my.h"

int	binary_base(unsigned int c)
{
  int	x;
  int	temp;

  x = 0;
  temp = c;
  while (temp > 1)
    {
      temp = temp / 2;
      x++;
    }
  if (c % 2 == 1)
    x++;
  while (x > - 1)
    my_put_nbr((c / my_power_rec(2, x--))% 2);
}
