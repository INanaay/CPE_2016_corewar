/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Fri Mar 31 18:53:01 2017 nathan
*/

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

char		**advance_fileptr(char **file)
{
  while (*file != NULL && **file == COMMENT_CHAR)
      *file++;
  return (file);
}

uint8_t		main(int ac, char **av)
{
  uint8_t	is_help;
  int		len;
  int		names_nbr;
  int		fd;
  char		*file_c;
  char		**file;
  t_label	**labels;
  t_instruct	**instruct;
  t_header	*header;

  names_nbr = 0;
  if ((is_help = check_args(ac, av)) != 1)
    return (is_help);
  if (file_to_arr(av[1], (&file_c)) == FAIL)
    return (FAIL);
  if ((file = advance_fileptr(my_strtowtb_sc(file_c, '\n'))) == NULL)
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
  header = fill_header_struct(header, file, labels);
  fd = create_core_file(av[1]);
  instruct = create_instruct(labels, len - 1);
  if (write_header(fd, header) == 1)
    return (FAIL);
  write_data(fd, labels, instruct);
  return (SUCCESS);
}
