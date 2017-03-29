/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Wed Mar 29 23:34:36 2017 nathan
*/

#include <unistd.h>
#include <stdlib.h>
#include "mylib/define.h"
#include "bytecode.h"


static void	ReverseBytes(const void *start, int size)
{
  uint8_t	*buffer;
  uint8_t	tmp;

  buffer = start;
  for(int i = 0; i < size / 2; i++) {
    tmp = buffer[i];
    buffer[i] = buffer[size - i - 1];
    buffer[size - i - 1] = tmp;
  }
}

static uint8_t		*reverse_bytes(const uint8_t *bytes, size_t n)
{
  register int	index;
  register int	count;
  uint8_t	*result;

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
  uint8_t	*tmp;

  if (fd <= 0)
    return (FAIL);
  void *e = bytes;
  ReverseBytes(e, n);
  count = write(fd, e, n);
  if (count != n)
    return (FAIL);
  return (SUCCESS);
}
