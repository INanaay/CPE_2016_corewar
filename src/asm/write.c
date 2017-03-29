/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Wed Mar 29 19:19:48 2017 nathan
*/

#include <unistd.h>
#include <stdlib.h>
#include "mylib/define.h"
#include "bytecode.h"

int8_t		*reverse_bytes(int8_t *bytes, size_t n)
{
  register int	index;
  register int	count;
  int8_t	*result;

  index = 0;
  count = n - 1;
  result = malloc(sizeof(int8_t) * n);
  while (index <= count)
    {
      result[index] = bytes[count];
      index = index + 1;
      count = count - 1;
    }
  return (result);
}

int8_t		write_bytes(int fd, const void *bytes, size_t n)
{
  int		count;
  int8_t	*tmp;
  int8_t	a;

  if (fd <= 0)
    return (FAIL);
  a = *((int8_t *)bytes);
  printf("bytes[0] : %d\n", a);
  tmp = reverse_bytes((int8_t *)bytes, n);
  printf("tmp[%d] : %d\n", n - 1, tmp[n - 1]);
  count = write(fd, tmp, n);
  free(tmp);
  if (count != n)
    return (FAIL);
  return (SUCCESS);
}
