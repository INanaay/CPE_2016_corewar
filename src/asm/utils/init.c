/*
** init.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Mon Mar 27 14:52:31 2017 nathan
** Last update Sun Apr  2 18:40:44 2017 nathan
*/

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "op.h"
#include "assembly.h"
#include "mylib/define.h"
#include "mylib/my_string.h"
#include "mylib/my_mem.h"

char		**advance_fileptr(char **file)
{
  while (*file != NULL && (**file == COMMENT_CHAR || **file == 0))
    *file++;
  return (file);
}

uint8_t	check_args(int ac, char **av)
{
  int	len;

  if (ac != 2)
    return (my_puterr84(ARG_ERR));
  else if (my_strcmp("-h", av[1]) == 0)
    {
      my_putconcat(1, 3, HELP, HELP1, HELP2);
      return (SUCCESS);
    }
  else if ((len = my_strlen(av[1])) < 3 ||
	   (av[1][len - 1] != 's' && av[1][len - 2] != '.'))
    return (my_puterr84(ARG_ERR));
  return (1);
}

uint8_t	file_to_arr(const char *path, char **file)
{
  int	fd;
  char	buff[READ_SIZE + 1];
  int	size;

  if ((*file = my_calloc(sizeof(char), READ_SIZE + 1)) == NULL)
    return (my_puterr84(MEM_FAIL));
  if ((fd = open(path, O_RDONLY)) == -1)
    return (my_puterr84(OPEN_FAIL));
  while ((size = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[size] = 0;
      if ((*file = my_realloc(*file, my_strlen(*file) + size + 1)) == NULL)
	return (my_puterr84(MEM_FAIL));
      my_strcat(*file, buff);
    }
  return (SUCCESS);
}

uint8_t check_headerspcs(int index, char *line)
{
  while (line[index] && line[index] != '"')
    {
      if (line[index] != '\t' && line[index] != ' ')
	return (FAIL);
      index++;
    }
  return (SUCCESS);
}

uint8_t	check_header(char **file)
{
  int	values[4];

  if (my_strtablen(file) < 2)
    return (FAIL);
  while (file[0][0] == ' ' || file[0][0] == '\t')
    file[0]++;
  while (file[1][0] == ' ' || file[1][0] == '\t')
    file[1]++;
  values[0] = my_strcmp(NAME_CMD_STRING, file[0]);
  values[1] = my_strlen(file[0]) - 5;
  values[2] = my_strcmp(COMMENT_CMD_STRING, file[1]);
  values[3] = my_strlen(file[1]) - 8;
  if (values[0] != values[1] || values[2] != values[3] ||
      my_strcontains(file[0], '"') != 2 || my_strcontains(file[1], '"') != 2)
    return (FAIL);
  if (check_headerspcs(5, file[0]) == FAIL)
    return (FAIL);
  if (check_headerspcs(8, file[1]) == FAIL)
    return (FAIL);
  return (SUCCESS);
}
