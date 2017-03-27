/*
** parser.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:05:13 2017 nathan
** Last update Mon Mar 27 12:16:44 2017 nathan
*/

#include <stdlib.h>
#include "mylib/define.h"
#include "mylib/my_string.h"
#include "assembly.h"
#include "op.h"

uint8_t		add_tolabels(t_label **labels, char *line, int index)
{
  static int	count = 0;
  t_label	*new;
  int		len;

  new = malloc(sizeof(t_label));
  len = my_strlen(op_tab[index].mnemonique);
  new->name = NULL;
  new->inst = op_tab[index].mnemonique;
  new->args = my_strtowtb_sc(line + len, SEPARATOR_CHAR);
  new->size = 0;
  labels[count++] = new;
  return (SUCCESS);
}

uint8_t		parser(char **file, t_label **labels)
{
  int		x;
  int		y;
  int		len;
  int		len2;

  x = 2;
  while (file[x])
    {
      if (file[x][0] != 0)
	{
	  y = 0;
	  len = my_strlen(file[x]);
	  while (y < 16)
	    {
	      len2 = my_strlen(op_tab[y].mnemonique);
	      if (my_strcmp(op_tab[y].mnemonique, file[x]) == len - len2)
		{
		  //printf("%s\n", op_tab[y].mnemonique);
		  if (add_tolabels(labels, file[x], y) == FAIL)
		    return (my_puterr84(INV_FILE));
		  break;
		}
	      y++;
	    }
	  if (y == 16)
	    printf("%s\n", file[x]);
	}
      x++;
    }
  return (SUCCESS);
}
