/*
** instruction.c for corewa in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 02:20:51 2017 flavian gontier
** Last update Thu Mar 30 19:10:12 2017 flavian gontier
*/

#include "virtual_machine.h"
#include "bytecode.h"

void	read_instruction(t_stream *stream, t_instruct *instruct)
{
  instruct->id = read_int8(stream);
  instruct->params_type = read_int8(stream);
  instruct->params = get_params(stream, instruct->params_type);
}


