/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Mon Mar 27 20:30:53 2017 NANAA
*/

#include <unistd.h>
#include "bytecode.h"

int8_t		write_bytes(int fd, const void *bytes, size_t n)
{
  int		count;
  int8_t	*tmp;

  if (fd <= 0)
    return (EXIT_ERROR);
  tmp = reverse_bytes((int8_t *)bytes, n);
  count = write(fd, tmp, n);
printf("wrote: %d\n", count);
  free(tmp);
  if (count != n)
    return (EXIT_ERROR);
  return (EXIT_SUCESS);
}
