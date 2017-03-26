/*
** init_virtual_machine.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 12:30:23 2017 flavian gontier
** Last update Sat Mar 25 13:44:12 2017 flavian gontier
*/

#include "virtual_machine.h"

void	init_virtual_machine(t_arguments *arguments, t_vm *virtual_machine)
{
  virtual_machine->dump_cycles = arguments->cycle_count;
  virtual_machine->processes = malloc(sizeof(t_process));
  if (virtual_machine->processes == NULL)
  {
    my_puterr("ERROR: Malloc error.\n");
    exit(EXIT_ERROR);
  }
  virtual_machine->process_count = 1;
  if (arguments->start_address != -1)
    virtual_machine->processes[0].start_address = arguments->start_address;
  if (s_arguments->process_id != -1)
    virtual_machine->processes[0].process_id = s_arguments->process_id;
}
