/*
** my_strsplit.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
**
** Started on  Tue Mar 14 12:27:21 2017 flavian gontier
** Last update Mon Mar 20 16:03:37 2017 nathan
*/

#include "libmy.h"

static int	element_count(char *str, char c)
{
  register int	index;
  int		length;
  int		count;

  index = 0;
  count = 0;
  while (*str == c)
    str++;
  length = my_strlen(str);
  while (str[length - 1] == c)
    str[--length] = 0;
  while (str[index] != 0)
  {
    if (str[index] == c && str[index + 1] == 0)
      break ;
    if (str[index] == c && str[index + 1] != c && str[index + 1] != 0)
      count = count + 1;
    index = index + 1;
  }
  return (count == 0 ? count : count + 1);
}

static void	split(char *str, char c, char **tab)
{
  register int	index;
  size_t	len;
  size_t	line;

  line = 0;
  index = 0;
  while (str[index] != 0)
  {
    while (str[index] == c)
      index = index + 1;
    if (str[index] == 0)
      break ;
    len = my_len(&str[index], c);
    tab[line] = my_strndup(&str[index], len);
    index = index + len;
    line = line + 1;
    while (str[index] != c && str[index] != 0)
      index = index + 1;
  }
  tab[line] = 0;
}

char		**my_strsplit(char *str, char c)
{
  char		*tmp;
  char		**result;
  int		size;

  tmp = my_strdup(str);
  size = element_count(tmp, c);
  result = malloc(sizeof(char *) * (size + 1));
  split(tmp, c, result);
  free(tmp);
  return (result);
}
