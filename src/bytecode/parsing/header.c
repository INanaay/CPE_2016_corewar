/*
** header.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 22:03:49 2017 flavian gontier
** Last update Tue Mar 28 22:04:06 2017 flavian gontier
*/

void    read_header(t_stream *stream, t_header *header)
{
  header->magic = read_int32(stream);
  header->name = read_bytes(stream, sizeof(header->name));
  header->size = read_int32(stream);
  header->comment = read_bytes(stream, sizeof(header->comment));
}

