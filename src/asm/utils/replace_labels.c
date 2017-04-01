/*
** replace_labels.c for corewar in /home/nathan/projects/CPE_2016_corewar/src/asm
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Fri Mar 31 23:13:16 2017 nathan
** Last update Sat Apr  1 19:30:58 2017 nathan
*/

#include <stdlib.h>
#include "mylib/my_string.h"
#include "mylib/define.h"
#include "bytecode.h"
#include "assembly.h"

uint8_t	fill_to_replace(t_label *label, t_replace *to_replace, int size, int z)
{
  int	y;
  int	len;

  y = 0;
  len = my_strtablen(label->args);
  while (y < len)
    {
      if (label->args[y][0] == '%' && label->args[y][1] == ':')
	{
	  to_replace->name = label->args[y] + 2;
	  to_replace->index = size;
	  to_replace->arg_nbr = y;
	  to_replace->label_index = z;
	  return (z + 1);
	}
      y++;
    }
  return (z);
}

int		get_size_line(t_label *label)
{
  int		size;
  int		y;
  int		len;

  len = my_strtablen(label->args);
  size = 0;
  y = 0;
  if (label->inst == 0 || label->inst == 8 ||
      label->inst == 11 || label->inst == 14)
    size += 1;
  else
    size += 2;
  while (y < len)
    size += get_typesize(label->args[y++], label->inst);
  return (size);
}

int		find_toreplacenbr(t_label **labels)
{
  int		x;
  int		y;
  int		count;
  int		len;

  x = 0;
  count = 0;
  while (labels[x])
    {
      len = my_strtablen(labels[x]->args);
      while (y < len)
	{
	  if (my_strcontains(labels[x]->args[y], ':') == 1)
	    count++;
	  y++;
	}
      y = 0;
      x++;
    }
  return (count + 1);
}

t_replacer	*replace_labels(t_label **labels, int name_nbr, int tablen)
{
  t_replacer	*replacement;
  t_replace	*to_replace;
  t_replace	*replacer;
  int		x;
  int		y;
  int		z;
  int		tore_len;
  int		size;

  replacement = malloc(sizeof(t_replacer));
  to_replace = malloc(sizeof(t_replace) * (tore_len = find_toreplacenbr(labels)));
  replacer = malloc(sizeof(t_replace) * (name_nbr + 1));
  replacement->size_to = tore_len;
  replacement->size_re = name_nbr;
  x = 0;
  y = 0;
  size = 0;
  z = 0;
  while (labels[x])
    {
      if (labels[x]->name != NULL)
	{
	  replacer[y].name = labels[x]->name;
	  replacer[y].index = size;
	  y++;
	}
      z = fill_to_replace(labels[x], &to_replace[z], size, z);
      size += get_size_line(labels[x]);
      x++;
    }
  replacement->to_replace = to_replace;
  replacement->replacer = replacer;
  return (replacement);
}
