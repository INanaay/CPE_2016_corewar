/*
** header.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 22:03:49 2017 flavian gontier
** Last update Wed Mar 29 11:50:49 2017 flavian gontier
*/

#include "bytecode.h"

void    read_header(t_stream *stream, t_header *header)
{
  header->magic = read_int32(stream);
  read_bytes(stream, header->name, sizeof(header->name));
  header->size = read_int32(stream);
  read_bytes(stream, header->comment, sizeof(header->comment));
}

