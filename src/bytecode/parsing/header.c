/*
** header.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 22:03:49 2017 flavian gontier
** Last update Fri Mar 31 00:01:43 2017 flavian gontier
*/

#include "bytecode.h"
#include "libmy.h"

void    read_header(t_stream *stream, t_header *header)
{
  header->magic = read_int32(stream);
  read_string(stream, header->name, sizeof(header->name));
  stream->position += 5;
  read_string(stream, header->comment, sizeof(header->comment));
  header->size = read_int32(stream);
}

int8_t		write_header(int fd, const t_header *header)
{
  int8_t   error;

  error = 0;
  error |= write_bytes(fd, &header->magic, sizeof(header->magic));
  error |= write_bytes(fd, header->name, sizeof(header->name));
  error |= write_bytes(fd, header->comment, sizeof(header->comment));
  error |= write_bytes(fd, &header->size, sizeof(header->size));
  if (error == 1)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
