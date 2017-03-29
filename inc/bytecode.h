/*
** bytecode.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 11:41:43 2017 flavian gontier
** Last update Wed Mar 29 12:27:30 2017 flavian gontier
*/

#ifndef BYTECODE_H_
# define BYTECODE_H_

#include "virtual_machine.h"
#include <stdint.h>

# define MAGIC_VALUE 0xea83f3
# define NAME_SIZE 128
# define COM_SIZE 2048

typedef struct	s_header
{
  int32_t	magic;
  int8_t	name[NAME_SIZE + 1];
  int32_t	size;
  int8_t	comment[COM_SIZE + 1];
}		t_header;

typedef struct	s_stream
{
  int8_t	*data;
  int32_t	data_count;
  int32_t	position;
}		t_stream;

typedef struct	s_instruct
{
  int8_t	id;
  int8_t	params_type;
  int8_t	*params;
}

/*
** Stream functions
*/
t_stream	*init_stream(int fd, t_stream *stream);
int8_t		*reverse_bytes(int8_t *bytes, size_t n);
int32_t		read_int32(t_stream *stream);
int16_t		read_int16(t_stream *stream);
int8_t		read_int8(t_stream *stream);
void		read_bytes(t_stream *stream, void *dest, size_t n);
void		read_header(t_stream *stream, t_header *header);
int		read_instruction_id(int fd, int *id);

/*
** Params functions
*/
int		get_params_count(int8_t params_type);
int		get_param_type(int8_t params_type, int8_t param_index);
int		get_params_size(int8_t params_type);
int8_t		get_params(t_vm *virtual_machine, int addr, int8_t params_type);

#endif
