/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Wed Mar 29 11:41:19 2017 flavian gontier
*/

#include <unistd.h>
#include "libmy.h"
#include "bytecode.h"

int8_t		write_bytes(int fd, const void *bytes, size_t n)
{
  int		count;
  int8_t	*tmp;

  if (fd <= 0)
    return (EXIT_ERROR);
  tmp = reverse_bytes((int8_t *)bytes, n);
  count = write(fd, tmp, n);
  free(tmp);
  if (count != n)
    return (EXIT_ERROR);
  return (EXIT_SUCESS);
}
