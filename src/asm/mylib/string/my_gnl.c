/*
** get_next_line.c for get_next_line  in /home/nathan/done/CPE/CPE_2016_getnextline
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Jan 18 22:46:56 2017 nathan
** Last update Mon Feb 13 13:53:36 2017 nathan
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mylib/my_string.h"
#include "mylib/define.h"
#include "mylib/my_mem.h"

#define BREAK '\n'

void	new_save(char *buff, int read)
{
  int	new_read;

  new_read = 0;
  while (buff[read])
    buff[new_read++] = buff[read++];
  buff[new_read] = 0;
}

char		*get_line(char *buff)
{
  char		*line;
  int		i;

  i = 0;
  while (buff[i] != BREAK && buff[i])
    i++;
  buff[i] = 0;
  line = my_calloc(sizeof(char), (i + 1));
  i = 0;
  while (buff[i] && buff[i] != BREAK)
    {
      line[i] = buff[i];
      i++;
    }
  line[i] = 0;
  new_save(buff, i + 1);
  return (line);
}

char		*my_gnl(const int fd)
{
  char		tmp[READ_SIZE + 1];
  static char	*buff;
  char		*res;
  int		bits;

  bits = 1;
  buff = (buff == NULL) ? my_calloc(sizeof(char), (8092)) : buff;
  if (buff == NULL || fd < 0)
    return (NULL);
  while (my_strcontains(buff, BREAK) == 0)
    {
      bits = read(fd, tmp, READ_SIZE);
      if (bits < 0)
	return (NULL);
      tmp[bits] = 0;
      if (bits == 0)
	break;
      my_strcat(buff, tmp);
    }
  res = get_line(buff);
  if (*buff == 0 && bits == 0 && *res == 0)
    return (NULL);
  return (res);
}
