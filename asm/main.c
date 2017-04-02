/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Sun Apr  2 20:07:26 2017 nathan
*/

#include <stdlib.h>
#include <unistd.h>
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

int8_t		next(char **file, t_label **labels, char *filename,
		     int names_nbr)
{
  t_header	*header;
  t_instruct	**instruct;
  t_replacer	*replacer;
  int		len;
  int		fd;

  header = NULL;
  len = my_strtablen(file) + 1;
  if (parser(file, labels, &names_nbr) == FAIL)
    return (FAIL);
  //printf("parser\n");
  if (check_labelexist(labels, names_nbr) == FAIL)
    return (FAIL);
  //printf("labelexist\n");
  header = fill_header_struct(header, file, labels);
  fd = create_cor_file(filename);
  instruct = create_instruct(labels, len - 1);
  replacer = replace_labels(labels, names_nbr, my_strtablen(file));
  if (write_header(fd, header) == 1)
    return (FAIL);
  write_data(fd, labels, instruct, replacer);
  close(fd);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  uint8_t	is_help;
  int		len;
  int		names_nbr;
  char		*file_c;
  char		**file;
  t_label	**labels;

  names_nbr = 0;
  if ((is_help = check_args(ac, av)) != 1)
    return (is_help);
  if (file_to_arr(av[1], (&file_c)) == FAIL)
    return (FAIL);
  //printf("fille_to_arr\n");
  if ((file = advance_fileptr(my_strtowtb_sc(file_c, '\n'))) == NULL)
    return (my_puterr84(MEM_FAIL));
  if (check_header(file) == FAIL)
    return (my_puterr84(INV_FILE));
  //printf("header\n");
  file = epur_file(file);
  len = my_strtablen(file) + 1;
  labels = malloc(sizeof(t_label *) * len);
  labels[len - 1] = NULL;
  if (next(file, labels, av[1], names_nbr) == FAIL)
    return (FAIL);
  return (SUCCESS);
}
