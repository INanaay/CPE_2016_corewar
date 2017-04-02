/*
** virtual_machine.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 15:39:16 2017 flavian gontier
** Last update Sun Apr 02 22:15:12 2017 flavian gontier
*/

#ifndef VIRTUAL_MACHINE_H_
# define VIRTUAL_MACHINE_H_

#include <stdint.h>
#include <stdlib.h>
#include "bytecode.h"

# define ADDRESS_CONST 0x65f
# define MAX_CODE_SIZE 8192
# define MEM_SIZE MAX_CODE_SIZE * 5
# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 4

typedef struct	s_arguments
{
  char		**champions;
  int32_t	champion_count;
  uint32_t	cycle_count;
  int32_t	process_id;
  int32_t	start_address;
}		t_arguments;

typedef struct	s_process
{
  int32_t	id;
  int32_t	address;
  int32_t	cycle_to_die;
  int32_t	cycles_remaining;
  char		*binary;
  t_stream	stream;
  t_header	header;
}		t_process;

typedef struct	s_vm
{
  int32_t	dump_cycles;
  int32_t	last_process_id;
  size_t	process_count;
  t_process	*processes;
  int8_t	memory[MEM_SIZE];
}		t_vm;

typedef	void (*t_handler)(t_vm *, t_instruct *);

typedef struct	s_keyvalue
{
  int		key;
  t_handler	value;
}		t_keyvalue;

/*
** Virtual machine functions
*/
void		exec_instruction(t_process *proc, t_vm *vm, t_instruct *ins);
void		parse_arguments(int argc, char **argv, t_arguments *arguments);
void		virtual_machine_write(t_vm *machine, int32_t address,
				      int8_t *data, size_t n);
void		run_virtual_machine(t_vm *virtual_machine);
void		init_virtual_machine(t_arguments *arguments,
				     t_vm *virtual_machine);
t_process	*get_process_by_id(t_vm *virtual_machine, int id);
int8_t		*get_params(t_stream *stream, int8_t paramstype);

/*
** Handlers
*/
# define ALIVE_CYCLES 5

void		alive_handler(t_vm *virtual_machine, t_instruct *instruction);

#endif
