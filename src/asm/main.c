/*
** main.c for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:17:11 2017 nathan
** Last update Tue Mar 28 01:09:56 2017 nathan
*/

#include <stdlib.h>
#include "op.h"
#include "assembly.h"
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

uint8_t		main(int ac, char **av)
{
  int		is_help;
  char		*file_c;
  char		**file;
  t_label	**labels;
  int		len;

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
  labels = malloc(sizeof(t_label *) * (len = my_strtablen(file) + 1));
  labels[len - 1] = NULL;
  if (parser(file, labels) == FAIL)
    return (FAIL);
  int	x = 0;
  int	y;
  while (labels[x])
    {
      y = 0;
      printf("%s\t", labels[x]->inst);
      while (y < my_strtablen(labels[x]->args))
	printf("%s\t", labels[x]->args[y++]);
      printf("\n");
      x++;
    }
  return (SUCCESS);
}
