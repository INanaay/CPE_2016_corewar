/*
** parser.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:05:13 2017 nathan
** Last update Fri Mar 31 13:34:07 2017 nathan
*/

#include <stdlib.h>
#include "mylib/define.h"
#include "mylib/my_string.h"
#include "assembly.h"
#include "op.h"

uint8_t		check_labelargs(char **args, int index)
{
  uint8_t	x;
  uint8_t	len;
  int		tmp;

  x = 0;
  if ((len = my_strtablen(args)) != g_op_tab[index].nbr_args)
    return (FAIL);
  while (x < len)
    {
      if (args[x][0] == DIRECT_CHAR && (T_DIR &
					g_op_tab[index].type[x]) != T_DIR)
	return (FAIL);
      else if (args[x][0] == 'r' &&
	       ((T_REG & g_op_tab[index].type[x]) != T_REG ||
		(tmp = my_atoi(args[x] + 1)) > REG_NUMBER || tmp < 1))
	return (FAIL);
      else if (args[x][0] <= '9' && args[x][0] >= '0' &&
	       (T_IND & g_op_tab[index].type[x]) != T_IND)
	return (FAIL);
      x++;
    }
  return (SUCCESS);
}

uint8_t		add_tolabels(t_label **labels, char *line,
			     char *name, int index)
{
  static int	count = 0;
  t_label	*new;
  int		len;

  new = malloc(sizeof(t_label));
  len = my_strlen(g_op_tab[index].mnemonique);
  new->name = name;
  new->inst = index;
  new->args = my_strtowtb_sc(line + len, SEPARATOR_CHAR);
  if (check_labelargs(new->args, index) == FAIL)
    return (FAIL);
  labels[count++] = new;
  return (SUCCESS);
}

uint8_t	find_inoptab(char *line)
{
  int		len;
  int		len2;
  uint8_t	y;

  y = 0;
  len = my_strlen(line);
  while (y < 16)
    {
      len2 = my_strlen(g_op_tab[y].mnemonique);
      if (my_strcmp(g_op_tab[y].mnemonique, line) == len - len2)
	{
	  if (line[len2] == '%' || line[len2] <= '9' && line[len2] >= '0' ||
	      line[len2] == 'r')
	  return (y);
	}
      y++;
    }
  return (y);
}

uint8_t		get_labelname(t_label **labels, char *line)
{
  int		x;
  int		len;
  uint8_t	y;

  x = 0;
  len = my_strlen(line);
  while (line[x])
    {
      if (line[x] == LABEL_CHAR)
	{
	  line[x] = 0;
	  break ;
	}
      x++;
    }
  if (x == len)
    return (my_puterr84(INV_FILE));
  if ((y = find_inoptab(line + x + 1)) == 16)
    return (my_puterr84(INV_FILE));
  if (add_tolabels(labels, line + x + 1, line, y) == FAIL)
    return (my_puterr84(INV_FILE));
  return (SUCCESS);
}

uint8_t		parser(char **file, t_label **labels, int *names_nbr)
{
  int		x;
  int		y;

  x = 2;
  while (file[x])
    {
      if (file[x][0] != 0)
	{
	  y = find_inoptab(file[x]);
	  if (y == 16)
	    {
	      if (get_labelname(labels, file[x]) == FAIL)
		return (my_puterr84(INV_FILE));
	      *names_nbr += 1;
	    }
	  else
	    {
	      if (add_tolabels(labels, file[x], NULL, y) == FAIL)
		return (my_puterr84(INV_FILE));
	    }
	}
      x++;
    }
  return (SUCCESS);
}
