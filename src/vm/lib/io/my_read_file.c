/*
** my_read_file.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils/io
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 18:16:52 2016 flavian gontier
** Last update Sat Jan 21 00:21:28 2017 flavian gontier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmy.h"

# define SIZE 1024 * 1024

char	*my_read_file(char *path)
{
  int	fd;
  int	bytes;
  char	temp[SIZE + 1];
  char	*result;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (NULL);
  bytes = read(fd, temp, SIZE);
  if (bytes == -1)
    return (NULL);
  if (temp[bytes] != '\n')
    {
      temp[bytes] = '\n';
      temp[bytes + 1] = 0;
    }
  else
    temp[bytes] = 0;
  result = my_strdup(temp);
  return (result);
}
