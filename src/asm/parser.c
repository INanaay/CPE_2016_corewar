/*
** parser.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:05:13 2017 nathan
** Last update Mon Mar 27 01:46:17 2017 nathan
*/

#include "mylib/define.h"
#include "mylib/my_string.h"
#include "assembly.h"
#include "op.h"

uint8_t	parser(char **file)
{
  int	x;
  int	y;
  int	len;
  int	len2;

  x = 2;
  while (file[x])
    {
      if (file[x][0] == COMMENT_CHAR || file[x][0] == 0)
	x++;
      else
	{
	  y = 0;
	  len = my_strlen(file[x]);
	  while (y < 16)
	    {
	      len2 = my_strlen(op_tab[y].mnemonique);
	      if (my_strcmp(op_tab[y].mnemonique, file[x]) == len - len2)
		printf("%s\n", op_tab[y].mnemonique);
	      y++;
	    }
	  if (y == 15)
	    printf("%s\n", file[x]);
	  x++;
	}
    }
  return (SUCCESS);
}
