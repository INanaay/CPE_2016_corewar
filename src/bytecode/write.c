/*
** write.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/bytecode
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 27 17:02:20 2017 NANAA
** Last update Mon Mar 27 18:57:32 2017 NANAA
*/

int8_t		write_bytes( int fd, const int8_t *bytes, size_t n)
{
  if (fd == -1)
    return (1);
  if (write(fd, bytes, n) == -1)
    return (1);
  return (0);
}
