/*
** create_cor_file.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/asm
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Tue Mar 28 14:44:57 2017 NANAA
** Last update Sat Apr  1 18:16:50 2017 nathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "assembly.h"
#include "bytecode.h"
#include "mylib/define.h"
#include "mylib/my_string.h"
#include "mylib/my_mem.h"

static char	*create_cor_name(char *name)
{
  int	i;

  i = 0;
  while (my_strcontains(name, '/') >= 1)
    name++;
  while (name[i] && name[i] != '.')
    i++;
  name[i + 1] = 0;
  if ((name = my_realloc(name, my_strlen(name) + my_strlen("cor"))) == NULL)
    return (NULL);
  my_strcat(name, "cor");
  return (name);
}

int	create_cor_file(char *path)
{
  int	fd;
  char	*name;

  name = create_cor_name(path);
  fd = open(name, O_CREAT | O_RDWR, 0666);
  if (fd == -1)
    return (1);
  return (fd);
}
