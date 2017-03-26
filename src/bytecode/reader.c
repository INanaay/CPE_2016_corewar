/*
** reader.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/bytecode
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 25 09:36:10 2017 flavian gontier
** Last update Sat Mar 25 12:08:16 2017 flavian gontier
*/

#include "bytecode.h"
#include "libmy.h"

int	read_header(int fd, t_header *header)
{
  int	bytes;

  if (fd < 0)
    return (EXIT_ERROR);
  if (header == NULL)
    return (EXIT_ERROR);
  bytes = read(fd, header, sizeof(header));
  if (bytes <= 0)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

int	read_instruction_id(int fd, int *id)
{
  int		bytes;

  if (fd <= 0)
    return (EXIT_ERROR);
  bytes = read(fd, id, sizeof(int8_t));
  if (bytes <= 0)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
