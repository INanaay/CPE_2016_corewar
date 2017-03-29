/*
** bytecode.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 11:41:43 2017 flavian gontier
** Last update Wed Mar 29 11:36:04 2017 flavian gontier
*/

#include <stdint.h>
#include <stdlib.h>

# define MAGIC_VALUE 0xea83f3
# define NAME_SIZE 128
# define COM_SIZE 2048

/*
** paramaters size
*/
# define IND_SIZE 2
# define DIR_SIZE 4
# define REG_SIZE DIR_SIZE

/*
** parameters masks
*/
# define T_REG 1
# define T_DIR 2
# define T_IND 3

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
int8_t		*reverse_bytes(int8_t *bytes, size_t n);
int32_t		read_int32(t_stream *stream);
int16_t		read_int16(t_stream *stream);
int8_t		read_int8(t_stream *stream);
int		read_header(int fd, t_header *header);
int		read_instruction_id(int fd, int *id);
