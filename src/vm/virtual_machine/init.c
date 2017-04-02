/*
** init_virtual_machine.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 12:30:23 2017 flavian gontier
** Last update Sun Apr 02 17:12:55 2017 flavian gontier
*/

#include <stdint.h>
#include <fcntl.h>
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
  addr = process->address;
  while (bytes == READ_SIZE)
  {
    bytes = read(fd, tmp, READ_SIZE);
    virtual_machine_write(vm, addr, tmp, bytes);
    addr += bytes;
  }
}

static void	init_process(t_vm *virtual_machine, t_arguments *arguments,
			     int index, t_process *process)
{
  t_stream	*file_stream;
  int8_t	*start;
  int		addr;

  process->id = virtual_machine->last_process_id;
  addr = (index * ADDRESS_CONST) % MEM_SIZE;
  process->address = addr;
  process->cycle_to_die = CYCLE_TO_DIE;
  process->cycles_remaining = 0;
  process->binary = arguments->champions[index];
  init_file_stream(process->binary);
  start = &virtual_machine->memory[addr];
  init_stream(start, MEM_SIZE - addr, &process->stream);
  copy_process(virtual_machine, process);
  read_header(&process->stream, &process->header);
  printf("=======HEADER=======\n");
  printf("name: %s\n", process->header.name);
  printf("comment: %s\n", process->header.comment);
  printf("====================\n");
}

static void	init_processes(t_arguments *arguments, t_vm *virtual_machine)
{
  int		counter;
  int8_t	*memptr;
  t_process	*process;

  counter = 0;
  virtual_machine->process_count = arguments->champion_count;
  virtual_machine->processes = malloc(sizeof(t_process) *
				      virtual_machine->process_count);
  virtual_machine->last_process_id = 0;
  while (counter < virtual_machine->process_count)
  {
    process = &virtual_machine->processes[counter];
    init_process(virtual_machine, arguments, counter, process);
    virtual_machine->last_process_id += 1;
    counter = counter + 1;
  }
}

void	init_virtual_machine(t_arguments *arguments, t_vm *virtual_machine)
{
  virtual_machine->dump_cycles = arguments->cycle_count;
  my_memset(virtual_machine->memory, MEM_SIZE, 0);
  init_processes(arguments, virtual_machine);
}
