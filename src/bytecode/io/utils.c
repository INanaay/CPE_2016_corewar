/*
** utils.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 16:49:59 2017 NANAA
** Last update Thu Mar 30 21:07:33 2017 flavian gontier
*/

#include <unistd.h>
#include "bytecode.h"

int8_t	*reverse_bytes(int8_t *bytes, size_t n)
{
  register int	index;
  uint8_t	*buffer;
  uint8_t	tmp;

  index = 0;
  buffer = bytes;
  while (index < n / 2)
  {
    tmp = buffer[index];
    buffer[index] = buffer[n - index - 1];
    buffer[n - index - 1] =  tmp;
    index = index + 1;
  }
  return (buffer);
}
