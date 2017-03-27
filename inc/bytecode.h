/*
** bytecode.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 11:41:43 2017 flavian gontier
** Last update Mon Mar 27 14:40:56 2017 flavian gontier
*/

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
}

typedef struct	s_instruct
{
  int8_t	id;
  int8_t	param_type;
  int8_t	params[REG_SIZE * 4];
}		t_instruct;

int	read_header(int fd, t_header *header);
int	read_instruction_id(int fd, int *id);
