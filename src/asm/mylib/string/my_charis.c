/*
** my_charis.c for mylib in /home/nathan/projects/PSU_2016_navy/NS/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sat Feb  4 17:09:18 2017 nathan
** Last update Sat Feb  4 18:31:27 2017 nathan
*/

int	my_charlim(char c, char down_lim, char up_lim)
{
  if (c < down_lim || c > up_lim)
    return (1);
  return (0);
}
