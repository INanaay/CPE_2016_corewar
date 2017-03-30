/*
** utils.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 16:49:59 2017 NANAA
** Last update Thu Mar 30 19:16:23 2017 flavian gontier
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
  int tmp;
  memcpy(&tmp, bytes, n);
  printf("before reverse: %d\n", tmp);
  while (index < count)
    {
      result[index] = bytes[count];
      index = index + 1;
      count = count - 1;
    }
  printf("after reverse: %d\n", result);
  return (result);
}
