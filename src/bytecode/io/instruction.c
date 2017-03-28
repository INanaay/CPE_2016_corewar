/*
** instruction.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/io
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 13:05:08 2017 flavian gontier
** Last update Tue Mar 28 13:30:08 2017 flavian gontier
*/

#include "bytecode.h"
#include "libmy.h"

void	read_header(t_stream *stream, t_header *header)
{
  header->magic = read_int32(stream);
  header->name = read_bytes(stream, sizeof(header->name));
  header->size = read_int32(stream);
  header->comment = read_bytes(stream, sizeof(header->comment));
}

static void	read_params(t_instruct *instruct, t_stream *stream)
{

}

void	read_instruction(t_stream *stream, t_header *instruct)
{
  instruct->id = read_int8(stream);
  instruct->params_type = read_int8(stream);
  instruct->params = read_params(stream);
}
