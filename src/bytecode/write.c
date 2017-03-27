/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Mon Mar 27 19:18:44 2017 NANAA
*/

int8_t		write_bytes(int fd, const void *bytes, size_t n)
{
  int		count;
  int8_t	*tmp;

  if (fd <= 0)
    return (EXIT_ERROR);
  tmp = reverse_bytes(bytes, n);
  count = write(fd, tmp, n);
  free(tmp);
  if (count != n)
    return (EXIT_ERROR);
  return (EXIT_SUCESS);
}
