/*
** init_stream.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:14:31 2017 NANAA
** Last update Mon Mar 27 19:53:23 2017 NANAA
*/

#include "bytecode.h"

t_stream	*init_stream(t_stream *stream, int8_t *data, size_t n)
{
  if ((stream = malloc(sizeof (stream))) == NULL)
    return (NULL);
  stream->data = data;
  stream->data_count = n;
  stream->position = 0;
  return (stream);
}
