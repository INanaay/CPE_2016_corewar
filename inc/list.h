/*
** my_list.h for lib in /home/flavian.gontier/projects/libmy/list
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 00:33:08 2017 flavian gontier
** Last update Tue Mar 28 14:41:34 2017 anatole zeyen
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

#include <stdint.h>
#include <stdlib.h>

# define DEFAULT_CAPACITY 4

typedef struct	s_listInt32
{
  int32_t	count;
  int32_t	*elements;
  int32_t	capacity;
}		listInt32;

typedef struct	s_listString
{
  int32_t	count;
  char		**elements;
  int32_t	capacity;
}		listString;

void		listInt32_init(listInt32 *list);
void		listInt32_add(listInt32 *list, int32_t elem);
void		listInt32_expends(listInt32 *list);
void		listInt32_remove(listInt32 *list, int32_t elem);
void		listInt32_insert(listInt32 *list, int32_t elem, size_t index);

void		listString_init(listString *list);
void		listString_add(listString *list, char *elem);
void		listString_expends(listString *list);
void		listString_remove(listString *list, char *elem);
void		listString_insert(listString *list, char *elem, size_t index);
#endif
