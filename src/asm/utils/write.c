/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Thu Mar 30 01:23:57 2017 nathan
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

static void	reverse_bytes(const void *byte, int size)
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

int8_t		write_bytes(int fd, const void *bytes, size_t n)
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

uint8_t		write_data(t_label **labels, t_instruct **instruct)
{
  int	x;
  int	y;
  int	fd;
  int	size;
  int	tmp;
  int	len;

  x = 0;
  fd = open("testfile", O_CREAT | O_WRONLY);
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
