/*
** utils.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_vm/src/vm/virtual_machine
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr 02 15:39:13 2017 flavian gontier
** Last update Sun Apr 02 16:36:51 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

t_process	*get_process_by_id(t_vm *virtual_machine, int id)
{
  int		index;

  index = 0;
  while (index < virtual_machine->process_count)
  {
    if (virtual_machine->processes[index].id == id)
      return (&virtual_machine->processes[index]);
    index += 1;
  }
  return (NULL);
}

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
