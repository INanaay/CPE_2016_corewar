/*
** parser.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:05:13 2017 nathan
** Last update Mon Mar 27 15:25:26 2017 nathan
*/

#include <stdlib.h>
#include "mylib/define.h"
#include "mylib/my_string.h"
#include "assembly.h"
#include "op.h"

uint8_t		add_tolabels(t_label **labels, char *line,
			     char *name, int index)
{
  static int	count = 0;
  t_label	*new;
  int		len;

  new = malloc(sizeof(t_label));
  len = my_strlen(op_tab[index].mnemonique);
  new->name = name;
  new->inst = op_tab[index].mnemonique;
  new->args = my_strtowtb_sc(line + len, SEPARATOR_CHAR);
  new->size = 0;
  labels[count++] = new;
  return (SUCCESS);
}

uint8_t	find_inoptab(char *line)
{
  int		len;
  int		len2;
  int		y;

  y = 0;
  len = my_strlen(line);
  while (y < 16)
    {
      len2 = my_strlen(op_tab[y].mnemonique);
      if (my_strcmp(op_tab[y].mnemonique, line) == len - len2)
	return (y);
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
      if (line[x] == ':')
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

uint8_t		parser(char **file, t_label **labels)
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
	    get_labelname(labels, file[x]);
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
