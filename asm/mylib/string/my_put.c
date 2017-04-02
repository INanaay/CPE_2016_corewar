/*
** my_put.c for my_lib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 15:20:41 2017 nathan
** Last update Thu Mar 16 12:11:37 2017 nathan
*/

#include <unistd.h>
#include "mylib/my_string.h"

void	my_put(int output, char *str, int len)
{
  write(output, str, len);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  my_put(1, str, my_strlen(str));
}

void	my_puterr(char *str)
{
  my_put(2, str, my_strlen(str));
}

int	my_puterr84(char *str)
{
  my_puterr(str);
  return (84);
}
