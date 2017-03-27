/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Mon Mar 27 17:13:35 2017 NANAA
*/

int8_t		write_bytes(const int8_t fd, t_stream *stream)
{
  write(fd, stream->data, stream->data_count);
}
