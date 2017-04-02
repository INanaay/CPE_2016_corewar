/*
** my_atoi.c for mylib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sun Jan 22 04:00:42 2017 nathan
** Last update Sun Apr  2 21:07:57 2017 nathan
*/

#include <stdint.h>
#include <stdlib.h>
#include "mylib/my_string.h"
#include "mylib/my_math.h"

int	my_atoi(char *str)
{
  int	x;
  int	len;
  int	minus;
  long	result;

  x = 0;
  minus = 0;
  result = 0;
  len = my_strlen(str);
  while (str[x] && (str[x] == '+' || str[x] == '-'))
    {
      if (str[x] == '-')
	minus++;
      x++;
    }
  len = len - x - 1;
  while (len != - 1)
    result += (str[x++] - 48) * my_pow(10, len--);
  result = (minus % 2 == 0) ? result : - result;
  if (result >= INT32_MAX || result <= INT32_MIN)
    return (INT32_MAX);
  return (result);
}

int	get_nbrlen(int nbr)
{
  int	nbr_len;
  int	tmp;

  nbr_len = 0;
  tmp = nbr;
  while (tmp > 9)
    {
      tmp = tmp / 10;
      nbr_len++;
    }
  nbr_len++;
  return (nbr_len);
}

char	*my_revatoi(int nbr)
{
  int	nbr_len;
  char	*res;

  nbr_len = get_nbrlen(nbr) - 1;
  nbr_len = (nbr < 0) ? nbr_len + 1 : nbr_len;
  res = malloc(sizeof(char) * (nbr_len + 2));
  res[nbr_len + 1] = 0;
  res[0] = (nbr < 0) ? '-' : res[0];
  while (nbr > 9)
    {
      res[nbr_len--] = (nbr % 10) + 48;
      nbr = nbr / 10;
    }
  res[nbr_len--] = nbr + 48;
  return (res);
}
