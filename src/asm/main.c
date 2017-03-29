/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Wed Mar 29 19:54:09 2017 nathan
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

int8_t		get_type(char *arg)
{
  if (arg[0] == 'r')
    return (T_REG);
  else if (arg[0] == DIRECT_CHAR)
    return (T_DIR);
  else
    return (T_IND);
}

int8_t		set_paramsbits(int args_nbr, char **args)
{
  int8_t	byte;
  uint8_t	scale;
  uint8_t	x;
  uint8_t	index;
  int8_t	type;

  byte = 0;
  x = 0;
  type = 0;
  while (x < args_nbr)
    {
      index = 0;
      type = get_type(args[x]);
      scale =  6 - (x * 2);
      byte = byte ^ (type << scale);
      x++;
    }
  return (byte);
}

t_instruct	**create_instruct(t_label **labels, int len)
{
  t_instruct	**instruct;
  t_instruct	*tmp;
  int		x;
  int		move;
  uint8_t	tab_len;

  x = 0;
  instruct = malloc(sizeof(t_instruct *) * (len + 1));
  instruct[len] = NULL;
  while (labels[x])
    {
      tmp = malloc(sizeof(t_instruct));
      move = 0;
      tab_len = my_strtablen(labels[x]->args);
      tmp->id = g_op_tab[labels[x]->inst].code;
      tmp->params_type = set_paramsbits(tab_len, labels[x]->args);
      tmp->params = NULL;
      if (tab_len == 0)
	tmp = NULL;
      instruct[x] = tmp;
      x++;
    }
  return (instruct);
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
  int	fd;
  fd = open("testfile", O_CREAT | O_WRONLY);
  while (instruct[x] != NULL)
    {
      write_bytes(fd, &instruct[x]->params_type, sizeof(int8_t));
      x++;
    }
  close(fd);
  return (SUCCESS);
}
