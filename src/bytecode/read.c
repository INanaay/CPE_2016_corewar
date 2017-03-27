/*
** read.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/bytecode
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 27 15:18:06 2017 flavian gontier
** Last update Mon Mar 27 15:42:49 2017 flavian gontier
*/

#include "bytecode.h"

int8_t	*reverse_bytes(int8_t *bytes, size_t n)
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

void	read_bytes(t_stream *stream, size_t n, void *dest)
{
  int8_t	*result;
  int8_t	*tmp;

  tmp = malloc(sizeof(int8_t) * n);
  my_memcpy(tmp, stream->data[stream->position], n);
  result = reverse_bytes(tmp, n);
  stream->position += n;
  free(tmp);
}

int16_t	read_int16(t_stream *stream)
{
  int16_t	result;

  read_bytes(stream, sizeof(int16_t), &result);
  return (result);
}
