/*
** alive.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_vm/src/vm/virtual_machine/handlers
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr 02 14:30:40 2017 flavian gontier
** Last update Sun Apr 02 18:30:24 2017 flavian gontier
*/

#include "libmy.h"
#include "bytecode.h"
#include "virtual_machine.h"

void	alive_handler(t_vm *virtual_machine, t_instruct *instruction)
{
  int		id;
  t_process	*process;

  my_memcpy(&id, instruction->params, DIR_SIZE);
  process = get_process_by_id(virtual_machine, id);
  if (process == NULL)
  {
    printf("that's gave me wrong id\n");
    return ;
  }
  process->cycle_to_die = CYCLE_TO_DIE;
  process->cycles_remaining = ALIVE_CYCLES;
  my_putstr(process->header.name);
  my_putstr(" is alive !\n");
}
