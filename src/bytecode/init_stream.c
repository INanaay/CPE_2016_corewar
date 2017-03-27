/*
** init_stream.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:14:31 2017 NANAA
** Last update Mon Mar 27 17:20:54 2017 NANAA
*/

t_stream	*init_stream(t_stream *stream, int8_t *data)
{
  if ((stream = malloc(sizeof (stream))) == NULL)
    return (NULL);
  stream->data = data;
  stream->data_count = my_strlen(data);
  stream->position = 0;
  return (stream);
}
