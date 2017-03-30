/*
** run.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 27 14:10:53 2017 flavian gontier
** Last update Thu Mar 30 15:11:01 2017 flavian gontier
*/

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "virtual_machine.h"
#include "bytecode.h"
#include "libmy.h"

void	virtual_machine_write(t_vm *machine, int32_t address,
			      int8_t *data, size_t n)
{
  int	tmp;
  int	count;

  if (address > MEM_SIZE)
    address = address % MEM_SIZE;
  tmp = address + n;
  if (tmp > MEM_SIZE)
  {
    count = MEM_SIZE - address;
    my_memcpy(&machine->memory[address], data, count);
    my_memcpy(&machine->memory[0], data + count, n - count);
  }
  else
  {
    my_memcpy(&machine->memory[address], data, n);
  }
}

void	run_virtual_machine(t_vm *virtual_machine)
{
  t_instruct	instruction;
  t_process	*process;
  int		index;

  index = 0;
  while (index < virtual_machine->process_count)
  {
    process = &virtual_machine->processes[index];
    read_instruction(&virtual_machine, process, &instruction);
    /*
    exec_instruction(process, &instruction);
    */
    index = index + 1;
  }
}
