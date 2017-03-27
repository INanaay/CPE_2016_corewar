/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Mon Mar 27 12:14:58 2017 nathan
*/

#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "op.h"
#include "assembly.h"
#include "mylib/my_string.h"
#include "mylib/my_mem.h"
#include "mylib/define.h"

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
	   av[1][len - 1] != 's' && av[1][len - 2] != '.')
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
  if (line[index + 1] == '"')
    return (FAIL);
  return (SUCCESS);
}

uint8_t	check_header(char **file)
{
  int	values[4];

  if (my_strtablen(file) < 2)
    return (FAIL);
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

char		**epur_file(char **file)
{
  int		x;

  x = 2;
  while (file[x] != NULL)
    {
      file[x] = my_epurstr(file[x]);
      file[x] = my_remove_after(file[x], COMMENT_CHAR);
      x++;
    }
  return (file);
}

uint8_t		main(int ac, char **av)
{
  int		is_help;
  char		*file_c;
  char		**file;
  t_label	**labels;
  int		len;

  is_help = check_args(ac, av);
  if (is_help != 1)
    return (is_help);
  if (file_to_arr(av[1], (&file_c)) == FAIL)
    return (FAIL);
  if ((file = my_strtowtb_sc(file_c, '\n')) == NULL)
    return (my_puterr84(MEM_FAIL));
  if (check_header(file) == FAIL)
    return (my_puterr84(INV_FILE));
  file = epur_file(file);
  labels = malloc(sizeof(t_label *) * (len = my_strtablen(file) + 1));
  labels[len - 1] = NULL;
  parser(file, labels);
  int	x = 0;
  while (labels[x])
    {
      printf("%s\n", labels[x++]->inst);
    }
  return (SUCCESS);
}
