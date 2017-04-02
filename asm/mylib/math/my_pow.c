/*
** my_pow.c for mylib in /home/nathan/PSU_2016_minishell1/mylib/maths
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sun Jan 22 04:40:02 2017 nathan
** Last update Sun Jan 22 10:23:51 2017 nathan
*/

int	my_pow(int num, int p)
{
  if (p == 0)
    return (1);
  return (num * my_pow(num, p - 1));
}
