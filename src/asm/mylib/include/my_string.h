/*
** my_string.h for my_lib in /home/nathan/PSU_2016_minishell1/mylib/include
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 15:25:04 2017 nathan
** Last update Mon Mar 27 01:16:22 2017 nathan
*/

#ifndef _MY_STRING_
 #define _MY_STRING_

void	my_putstr(char *);
void	my_puterr(char *);
void	my_putchar(char);
void	wtb_merge(char **, char **, int, int);
void	my_strcpy(char *, char *);
void	my_strcat(char *, char *);
void	my_putconcat(int, int, ...);
int	my_puterr84(char *);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
int	my_strcontains_separators(char *);
int	my_strcontains(char *, char);
int	my_strisintab(char *, char **);
int	my_strtablen(char **);
int	str_isatstartof(char *, char *);
int	my_strcontains_nonalpha(char *);
int	my_strcontains_nonnum(char *);
int	my_atoi(char *);
int	get_nbrlen(int);
int	my_charlim(char, char, char);
char	*str_isafter(int, char *);
char	*my_revatoi(int);
char	*my_gnl(const int);
char	*my_getenv(char *);
char	*my_epurstr(char *);
char	*my_remove_after(char *, char);
char	**my_strtowtb_sc(char *, char);
char	**my_strtowtb(char *);
char	**wtb_alloc(int);

#endif
