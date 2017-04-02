/*
** reverse_int.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Mar 25 14:05:18 2017 NANAA
** Last update Sun Apr  2 11:55:10 2017 anatole zeyen
*/
#include <fcntl.h>

unsigned int		my_reverse_int(unsigned int nb)
{
  unsigned char		c1;
  unsigned char		c2;
  unsigned char		c3;
  unsigned char		c4;

  c1 = nb & 255;
  c2 = (nb >> 8) & 255;
  c3 = (nb >> 16) & 255;
  c4 = (nb >> 24) & 255;
  return ((c1 << 24) + (c2 << 16) + (c3 << 8) + c4);
}

unsigned short		my_reverse_short(unsigned short nb)
{
  unsigned char		c1;
  unsigned char		c2;

  c1 = nb & 255;
  c2 = (s >> 8) & 255;
  return ((c1 << 8) + c2);
}
