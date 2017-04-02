/*
** my_sqrt.c for mylib in /home/nathan/projects/raytracer1/mylib/math
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sun Feb 12 01:56:52 2017 nathan
** Last update Sun Apr  2 16:40:15 2017 nathan
*/

#include "mylib/my_math.h"

float	my_sqrt(float nbr, int index)
{
  float	result;

  if (nbr <= 0)
    return (0);
  result = nbr - my_pow(index, 2);
  if (result >= 0)
    return (my_sqrt(nbr, index + 1));
  return (index);
}
