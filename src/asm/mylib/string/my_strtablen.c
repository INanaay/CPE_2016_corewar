/*
** my_strtablen.c for my_lib in /home/nathan/PSU_2016_minishell1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 19:59:16 2017 nathan
** Last update Thu Jan 19 19:59:44 2017 nathan
*/

int	my_strtablen(char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    x++;
  return (x);
}
