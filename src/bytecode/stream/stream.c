/*
** stream.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:14:31 2017 NANAA
** Last update Sun Apr 02 17:12:33 2017 flavian gontier
*/

#include "bytecode.h"
#include "libmy.h"

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

void	init_stream(int8_t *data, size_t n, t_stream *stream)
{
  if (stream == NULL)
    return ;
  stream->data_count = n;
  stream->position = 0;
  stream->data = data;
}

void	init_file_stream(char *filepath, t_stream *stream)
{
  int	fd;

  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return ;
  if (stream == NULL)
    return ;
  stream->data_count = 0;
  stream->position = 0;
  get_stream_data(fd, stream);
}
