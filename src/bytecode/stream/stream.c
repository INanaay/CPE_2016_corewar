/*
** stream.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:14:31 2017 NANAA
** Last update Tue Mar 28 11:05:44 2017 flavian gontier
*/

#include "bytecode.h"

static void	get_stream_data(int fd, t_stream *stream)
{
  int	bytes;

  bytes = READ_SIZE;
  while (bytes == READ_SIZE)
  {
    bytes = read(fd, &stream->data[stream->data_count], READ_SIZE);
    stream->data_count += bytes;
  }
}

t_stream	*init_stream(int fd, t_stream *stream)
{
  stream = malloc(sizeof(t_stream));
  if (stream == NULL)
    return (NULL);
  stream->data_count = 0;
  stream->position = 0;
  get_stream_data(fd, stream);
  return (stream);
}
