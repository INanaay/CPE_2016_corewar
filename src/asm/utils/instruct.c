/*
** instruct.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 29 20:12:18 2017 nathan
** Last update Fri Mar 31 14:09:54 2017 nathan
*/

#include <stdint.h>
#include <stdlib.h>
#include "op.h"
#include "bytecode.h"
#include "mylib/my_string.h"

int8_t		get_typesize(char *arg)
{
  if (arg[0] == 'r')
    return (REG_SIZE);
  else if (arg[0] == DIRECT_CHAR)
    return (DIR_SIZE);
  else
    return (IND_SIZE);
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

int	get_headersize(t_label **labels)
{
  int	size;
  int	x;
  int	y;
  int	tmp;

  x = 0;
  y = 0;
  size = 0;
  while (labels[x] != NULL)
    {
      size += 1;
      while (labels[x]->args[y] != NULL)
	{
	  tmp = 0;
	  tmp += get_typesize(labels[x]->args[y++]);
	  if (labels[x]->inst == 10 ||
	      labels[x]->inst == 11 || labels[x]->inst == 14)
	    tmp = tmp / 2;
	}
      size += tmp;
      y = 0;
      x++;
    }
  printf("%i\n", size);
  return (size);
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
