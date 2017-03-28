/*
** run.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 27 14:10:53 2017 flavian gontier
** Last update Tue Mar 28 13:35:51 2017 flavian gontier
*/

#include "virtual_machine.h"
#include "libmy.h"

void	virtual_machine_write(t_vm *machine, int32_t address,
			      int8_t *data, size_t n)
{
  int	tmp;
  int	count;

  if (address > MEM_SIZE)
    address = adress % MEM_SIZE;
  tmp = address + n;
  if (tmp > MEM_SIZE)
  {
    count = machine->memory - address;
    my_memcpy(&machine->memory[address], data, count);
    tmp = n - count;
    my_memcpy(&machine->memory[0], data + count, n - count);
  }
  else
  {
    my_memcpy(&machine->memory[address], data, n);
  }
}

void	run_virtual_machine(t_vm *virtual_machine)
{
}
