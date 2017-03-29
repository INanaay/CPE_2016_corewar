/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Wed Mar 29 23:05:57 2017 nathan
*/

/*
** for open
*/
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdlib.h>
#include "op.h"
#include "assembly.h"
#include "bytecode.h"
#include "mylib/my_string.h"
#include "mylib/my_mem.h"
#include "mylib/define.h"

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

uint8_t	check_labelexistargs(t_label **labels, char **names)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (labels[x])
    {
      while (labels[x]->args[y])
	{
	  if (labels[x]->args[y][1] == ':' &&
	      find_intab(labels[x]->args[y] + 2, names) != 0)
	    return (my_puterr84(INV_FILE));
	  else if (labels[x]->name && labels[x]->args[y][1] == ':' &&
		   my_strcmp(labels[x]->name, labels[x]->args[y] + 2) == 0)
	    return (my_puterr84(INV_FILE));
	  y++;
	}
      y = 0;
      x++;
    }
  return (SUCCESS);
}

uint8_t	check_labelexist(t_label **labels, int names_nbr)
{
  char	**names;
  int	x;
  int	y;

  x = 0;
  y = 0;
  names = malloc(sizeof(char *) * (names_nbr + 1));
  names[names_nbr] = NULL;
  while (labels[x])
    {
      if (labels[x]->name != NULL)
	names[y++] = labels[x]->name;
      x++;
    }
  if (y == 0)
    names = NULL;
  return (check_labelexistargs(labels, names));
}

uint8_t		main(int ac, char **av)
{
  int		is_help;
  char		*file_c;
  char		**file;
  t_label	**labels;
  int		len;
  int		names_nbr;
  t_instruct	**instruct;

  names_nbr = 0;
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
  len = my_strtablen(file) + 1;
  labels = malloc(sizeof(t_label *) * len);
  labels[len - 1] = NULL;
  if (parser(file, labels, &names_nbr) == FAIL)
    return (FAIL);
  if (check_labelexist(labels, names_nbr) == FAIL)
    return (FAIL);
  instruct = create_instruct(labels, len - 1);
  int	x = 0;
  int	y;
  int	fd;
  int	size;
  int	tmp;
  fd = open("testfile", O_CREAT | O_WRONLY);
  while (instruct[x] != NULL)
    {
      y = 0;
      len = my_strtablen(labels[x]->args);
      write_bytes(fd, &instruct[x]->id, sizeof(int8_t));
      write_bytes(fd, &instruct[x]->params_type, sizeof(int8_t));
      printf("%i\n", len);
      while (y < len)
	{
	  tmp = my_atoi(labels[x]->args[y] + 1);
	  printf("typesize: %d\t %d\n", get_typesize(labels[x]->args[y]), tmp);
	  write_bytes(fd, &tmp,
		      sizeof(int8_t) * get_typesize(labels[x]->args[y]));
	  y++;
	}
      if (x == 1)
	{
	  close(fd);
	  exit(0);
	}
      x++;
    }
  close(fd);
  return (SUCCESS);
}
