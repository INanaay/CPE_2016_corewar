/*
** libmy.h for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Fri Jan 20 20:32:15 2017 flavian gontier
** Last update Mon Mar 27 13:59:54 2017 flavian gontier
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "list.h"

# define EXIT_SUCCESS 0
# define EXIT_ERROR 84
# define READ_SIZE 512
# define LIST_CAPACITY 4
# define HEXA_BASE "0123456789ABCDEF"
# define HEXA_SUFFIX "0x"

# define my_isup(x) (x >= 'A' && x <= 'Z')
# define my_islow(x) (x >= 'a' && x <= 'z')
# define my_isalpha(x) (my_islow(x) || my_isup(x))
# define my_isnum(x) (x >= '0' && x <= '9')
# define my_isalphanum(x) (my_isalpha(x) || my_isnum(x))

typedef struct  s_coord
{
  int   x;
  int   y;
}               t_coord;

void                    my_put(int fd, char *str);
void			my_putchar(char c);
void                    my_puterr(char *str);
void                    my_putstr(char *str);
void			my_putnbr(int nb);
int                     my_atoi(char *str);
char			*my_revatoi(int);
/*
** string
*/
int			my_strisalphanum(char *str);
int                     my_strcontains(char *str, char c);
int			my_strisnum(char *str);
int			my_len(char *str, char c);
int                     my_strlen(char *str);
char			*my_strcpy(char *dest, char *src);
int			my_strcat(char *dest, char *src);
char			*my_strncpy(char *dest, char *src, size_t n);
int			my_strindex(char *str, char c);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int n);
char                    *my_strdup(char *str);
char			*my_strndup(char *str, size_t n);
char			*my_tabelem(char **, char *name);
char                    *my_linedup(char *str);
char			**my_strsplit(char *str, char c);
char                    **my_tabdup(char **);
char			**my_tabncpy(char **dest, char **src, size_t n);
char			*my_get_hexadecimal(int nb);
int			my_get_decimal(char *hexadecimal);
t_coord                 my_tabdim(char **);
/*
** memory
*/
void                    *my_calloc(size_t size);
void			*my_realloc(void *ptr, size_t size);
void                    *my_memset(char *ptr, int len, int value);
void			*my_memcpy(void *src, void *dest, size_t len);
void			my_freetab(char **);
/*
** i/o
*/
char			*get_next_line(int fd);
char			*my_read_file(char *file);
void			my_putconcat(int, int, ...);
int			my_put84(char *);

#endif
