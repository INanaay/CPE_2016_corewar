/*
** my_strcat.c for mylib in /home/nathan/projects/raytracer1/mylib/string
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Mon Feb 13 12:48:12 2017 nathan
** Last update Wed Mar 22 18:30:13 2017 nathan
*/

void	my_strcat(char *to, char *from)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (to[x])
    x++;
  while (from[y])
    to[x++] = from[y++];
  to[x] = 0;
}
