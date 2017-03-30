/*
** instruction.c for corewa in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 02:20:51 2017 flavian gontier
** Last update Thu Mar 30 11:20:44 2017 flavian gontier
*/

#include "virtual_machine.h"
#include "bytecode.h"

void	read_instruction(t_process *process, t_instruct *instruct)
{
  int	params_count;

  instruct->id = read_int8(&process->stream);
  instruct->params_type = read_int8(&process->stream);
  params_count = get_params_count(instruct->params_type);
  instruct->params = get_params(&process->stream, instruct->params_type,
				params_count); // get param attend virtual_machine à la place de stream fp
}


