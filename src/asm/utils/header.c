/*
** header.c for Project-Master in /home/NANAA/Projets/CPE_2016_corewar/src/asm
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Wed Mar 29 15:16:53 2017 NANAA
** Last update Fri Mar 31 13:47:36 2017 nathan
*/

#include <unistd.h>
#include "assembly.h"
#include "op.h"
#include "bytecode.h"

/* tu donne la ligne ou il y a le .name*/

static t_header       	*fill_header_prog_name(t_header *head, char *str)
{
  int			i;
  int			len;
  int			pos;

  i = 0;
  len = 0;
  while (str[i] && str[i] != '"')
    i++;
  pos = i + 1;
  i++;
  len = 0;
  while (str[i] && str[i] != '"')
    {
      i++;
      len++;
    }
  if (len > PROG_NAME_LENGTH)
    return (NULL);
  len = 0;
  while (str[pos] && str[pos] != '"')
    head->name[len++] = str[pos++];
  return (head);
}

static t_header	*fill_header_comment(t_header *head, char *str)
{
  int		i;
  int		len;
  int		pos;
  int		j;

  j = 0;
  i = 0;
  len = 0;
  while (j < COM_SIZE + 1)
    head->comment[j++] = 0;
  while (str[i] && str[i] != '"')
    i++;
  pos = i + 1;
  i++;
  len = 0;
  while (str[i] && str[i] != '"')
    {
      i++;
      len++;
    }
  if (len > COMMENT_LENGTH)
    return (NULL);
  len = 0;
  while (str[pos] && str[pos] != '"')
    head->comment[len++] = str[pos++];
  return (head);
}

t_header	*fill_header_struct(t_header *head, char **file,
				    t_label **labels)
{
  if ((head = malloc(sizeof(t_header))) == NULL)
    return (NULL);
  head->magic = MAGIC_VALUE;
  if ((head = fill_header_prog_name(head, file[0])) == NULL)
    return (NULL);
  if ((head = fill_header_comment(head, file[1])) == NULL)
    return (NULL);
  head->size = get_headersize(labels);
  return (head);
}
