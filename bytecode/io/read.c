/*
** read.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/bytecode
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
**
** Started on  Mon Mar 27 15:18:06 2017 flavian gontier
** Last update Sun Apr  2 23:16:12 2017 nathan
*/

#include <stdlib.h>
#include "bytecode.h"
#include "libmy.h"

void	read_string(t_stream *stream, int8_t *ptr, size_t n)
{
  my_memcpy(ptr, &stream->data[stream->position], n);
  stream->position += n;
}

void	read_bytes(t_stream *stream, void *ptr, size_t n)
{
  int8_t	*tmp;

  tmp = malloc(sizeof(int8_t) * n);
  my_memcpy(tmp, &stream->data[stream->position], n);
  reverse_bytes(tmp, n);
  my_memcpy(ptr, tmp, n);
  stream->position += n;
  free(tmp);
}

int8_t		read_int8(t_stream *stream)
{
  int8_t	result;

  read_bytes(stream, &result, sizeof(int8_t));
  return (result);
}

int16_t		read_int16(t_stream *stream)
{
  int16_t	result;

  read_bytes(stream, &result, sizeof(int16_t));
  return (result);
}

int32_t		read_int32(t_stream *stream)
{
  int32_t	result;

  read_bytes(stream, &result, sizeof(int32_t));
  return (result);
}
