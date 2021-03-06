/*
** bytecode.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
**
** Started on  Sat Mar 25 11:41:43 2017 flavian gontier
** Last update Sun Apr  2 16:26:50 2017 nathan
*/

#ifndef BYTECODE_H_
#define BYTECODE_H_

#include <stdint.h>
#include "assembly.h"
# define MAGIC_VALUE 0xea83f3
# define NAME_SIZE 128 + 3
# define COM_SIZE 2048 + 3

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
}		t_instruct;

/*
** Stream functions
*/

t_stream	*init_stream(int fd, t_stream *stream);
int8_t		write_bytes(int, void *, size_t);
int32_t		read_int32(t_stream *stream);
int16_t		read_int16(t_stream *stream);
int8_t		read_int8(t_stream *stream);
int8_t		*read_bytes(t_stream *stream, size_t n);
int		read_header(int fd, t_header *header);
int		read_instruction_id(int fd, int *id);
t_instruct	**create_instruct(t_label **, int);
int8_t		get_typesize(char *, int);
void		write_data(int, t_label **, t_instruct **, t_replacer *);
int8_t		write_header(int, t_header *);
t_header        *fill_header_struct(t_header *head, char **file, t_label **);
int		get_headersize(t_label **);

#endif
