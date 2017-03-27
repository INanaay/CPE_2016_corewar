/*
** reverse_byte.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 16:49:59 2017 NANAA
** Last update Mon Mar 27 20:01:16 2017 NANAA
*/

#include <unistd.h>
#include "bytecode.h"

int8_t		*reverse_bytes(int8_t *bytes, size_t n)
{
  register int	index;
  register int	count;
  int8_t	*result;

  index = 0;
  count = n - 1;
  result = malloc(sizeof(int8_t) * n);
  while (index < n)
    {
      result[index] = bytes[count];
      index = index + 1;
      count = count - 1;
    }
  return (result);
}
