/*
** header.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 22:03:49 2017 flavian gontier
** Last update Wed Mar 29 19:17:09 2017 NANAA
*/

#include "bytecode.h"

void    read_header(t_stream *stream, t_header *header)
{
  header->magic = read_int32(stream);
  read_bytes(stream, header->name, sizeof(header->name));
  header->size = read_int32(stream);
  read_bytes(stream, header->comment, sizeof(header->comment));
}

int8_t	write_header(int fd, const t_header *header)
{
  if (write_bytes(fd, &header->magic, sizeof(header->magic))
      == EXIT_ERROR ||
      write_bytes(fd, header->name, sizeof(header->name)) == EXIT_ERROR ||
      write_bytes(fd, header->comment, sizeof(header->comment)) == EXIT_ERROR ||
      write_bytes(fd, &header->size, sizeof(header->size)) == EXIT_ERROR)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
