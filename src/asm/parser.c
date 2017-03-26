/*
** parser.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 24 17:05:13 2017 nathan
** Last update Mon Mar 27 01:12:13 2017 nathan
*/

#include "mylib/define.h"
#include "assembly.h"
#include "op.h"

uint8_t	parser(char **file)
{
  int	x;

  x = 2;
  while (file[x])
    {
      if (file[x][0] == COMMENT_CHAR || file[x][0] == 0)
	x++;
      else
	printf("%s\n", file[x++]);
    }
  return (SUCCESS);
}
