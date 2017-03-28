/*
** init_virtual_machine.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 12:30:23 2017 flavian gontier
** Last update Tue Mar 28 14:38:46 2017 anatole zeyen
*/

#include <stdint.h>
#include "virtual_machine.h"
#include "libmy.h"

static void	copy_process(t_vm *vm, t_process *process)
{
  int		fd;
  int		addr;
  int		bytes;
  int8_t	tmp[READ_SIZE];

  fd = open(process->binary, O_RDONLY);
  bytes = READ_SIZE;
  addr = process->addr;
  while (bytes == READ_SIZE)
  {
    bytes = read(fd, tmp, READ_SIZE);
    virtual_machine_write(vm, addr, tmp, bytes);
    addr += bytes;
  }
}

static void	init_processes(t_arguments *arguments, t_vm *virtual_machine)
{
  int		counter;
  t_process	*process;

  counter = 0;
  virtual_machine->process_count = arguments->champion_count;
  virtual_machine->processes = malloc(sizeof(t_process) *
				      virtual_machine->process_count);
  virtual_machine->last_process_id = 0;
  while (counter < virtual_machine->process_count)
  {
    process = &virtual_machine->processes[counter];
    process->id = virtual_machine->last_process_id;
    process->address = (counter + 1) * ADDRESS_CONST % MEM_SIZE;
    process->binary = arguments->champions[counter];
    virtual_machine->last_process_id += 1;
    counter = counter + 1;
    copy_process(virtual_machine, t_process *process);
  }
}

void	init_virtual_machine(t_arguments *arguments, t_vm *virtual_machine)
{
  virtual_machine->dump_cycles = arguments->cycle_count;
  virtual_machine->processes = malloc(sizeof(t_process));
  if (virtual_machine->processes == NULL)
  {
    my_puterr("ERROR: Malloc error.\n");
    exit(EXIT_ERROR);
  }
  init_processes(arguments, virtual_machine);
}
