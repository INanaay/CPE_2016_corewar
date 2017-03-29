/*
** create_cor_file.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/asm
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Tue Mar 28 14:44:57 2017 NANAA
** Last update Thu Mar 30 01:17:20 2017 nathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define EXIT_ERROR 1

char	*create_cor_name(char *name)
{
  int	i;

  i = 0;
  while (name[i] && name[i] != '.')
    i++;
  name[i + 1] = 0;
  if ((name = my_realloc(my_strlen(name) + 3)) == NULL);
  return (NULL);
  if ((name = my_strcat(name, "cor")) == NULL)
    return (NULL);
  return (name);
}

int	create_core_file(char *path)
{
  int	fd;

  fd = open(path, O_CREAT | O_RDWR, 0666);
  if (fd == -1)
    return (EXIT_ERROR);
  return (fd);
}
