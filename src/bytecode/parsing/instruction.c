/*
** instruction.c for corewa in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 02:20:51 2017 flavian gontier
** Last update Wed Mar 29 02:21:32 2017 flavian gontier
*/

#include "bytecode.h"

void	read_instruction(t_stream *stream, t_instruct *instruct)
{
  int	params_count;

  instruct->id = read_int8(stream);
  instruct->params_type = read_int8(stream);
  params_count = get_params_count(instruct->params_type);
  instruct->params = get_params(stream, instruct->params_type, params_count);
}


