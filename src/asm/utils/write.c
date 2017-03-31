/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Fri Mar 31 13:09:40 2017 NANAA
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "mylib/my_string.h"
#include "mylib/define.h"
#include "assembly.h"
#include "bytecode.h"

static void	reverse_bytes(void *byte, int size)
{
  uint8_t	*buffer;
  uint8_t	tmp;
  int		i;

  buffer = byte;
  i = 0;
  while (i < size / 2)
    {
      tmp = buffer[i];
      buffer[i] = buffer[size - i - 1];
      buffer[size - i - 1] = tmp;
      i++;
    }
}

int8_t		write_bytes(int fd, void *bytes, size_t n)
{
  int		count;
  uint8_t	*tmp;
  void		*e;

  if (fd <= 0)
    return (FAIL);
  e = bytes;
  reverse_bytes(e, n);
  count = write(fd, e, n);
  if (count != n)
    return (FAIL);
  return (SUCCESS);
}

uint8_t		write_data(int fd, t_label **labels, t_instruct **instruct)
{
  int	x;
  int	y;
  int	size;
  int	tmp;
  int	len;

  x = 0;
  while (instruct[x] != NULL)
    {
      y = 0;
      len = my_strtablen(labels[x]->args);
      write_bytes(fd, &instruct[x]->id, sizeof(int8_t));
      write_bytes(fd, &instruct[x]->params_type, sizeof(int8_t));
      while (y < len)
	{
	  tmp = my_atoi(labels[x]->args[y] + 1);
	  write_bytes(fd, &tmp,
		      sizeof(int8_t) * get_typesize(labels[x]->args[y]));
	  y++;
	}
      x++;
    }
  close(fd);
  return (SUCCESS);
}

int8_t		write_header(int fd, t_header *header)
{
  int8_t	error;

  error = 0;
  reverse_bytes(header->name, sizeof(header->name));
  reverse_bytes(header->comment, sizeof(header->comment));
  error |= write_bytes(fd, &header->magic, sizeof(header->magic));
  error |= write_bytes(fd, header->name, sizeof(header->name));
  error |= write_bytes(fd, &header->size, sizeof(int32_t));
  error |= write_bytes(fd, header->comment, sizeof(header->comment));
  if (error == 1)
    return (1);
  return (0);
}
