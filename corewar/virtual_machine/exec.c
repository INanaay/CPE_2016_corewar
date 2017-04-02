/*
** exec.c for corewa in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_vm/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 31 12:50:40 2017 flavian gontier
** Last update Sun Apr 02 16:35:34 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"
#include "bytecode.h"
#include <stdlib.h>

static const t_keyvalue	handlers[] =
{
  {1, &alive_handler},
  /*
     {2, &ld_handler},
     {3, &st_handler},
     {4, &add_handler},
     {5, &sub_handler},
     {6, &and_handler},
     {7, &or_handler},
     {8, &xor_handler},
     {9, &zjump_handler},
     {10, &ldi_handler},
     {11, &sti_handler},
     {12, &fork_handler},
     {13, &lld_handler},
     {14, &lldi_handler},
     {15, &lfork_handler},
     {16, &aff_handler}
   */
  {0, NULL}
};

t_handler get_handler(int instruct_id)
{
  int		index;

  index = 0;
  while (handlers[index].key != 0)
  {
    if (handlers[index].key == instruct_id)
      return (handlers[index].value);
    index = index + 1;
  }
  return (NULL);
}

int	remains_cycle(int cycles_remaining)
{
  return (cycles_remaining > 0);
}

void	exec_instruction(t_process *process, t_vm *vm, t_instruct *instruction)
{
  int		index;
  t_handler	handler;

  if (remains_cycle(process->cycles_remaining))
    return ;
  handler = get_handler(instruction->id);
  if (handler != NULL)
    handler(vm, instruction);
}
