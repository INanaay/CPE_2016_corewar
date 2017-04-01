/*
** assembly.h for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:43:32 2017 nathan
** Last update Sat Apr  1 18:08:01 2017 nathan
*/

#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <stdint.h>
#define HELP "USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n"
#define HELP1 "\tfile_name\tfile in assembly language to be converted into "
#define HELP2 "file_name.cor, an\n\t\t\texecutable in the Virtual Machine).\n"

typedef	struct		s_label
{
  char			*name;
  uint8_t		inst;
  char			**args;
}			t_label;

typedef struct		s_replace
{
  char			*name;
  int			index;
  int			arg_nbr;
  int			label_index;
}			t_replace;

typedef struct		s_replacer
{
  t_replace		*to_replace;
  t_replace		*replacer;
  int			size_to;
  int			size_re;
}			t_replacer;

uint8_t		check_args(int, char **);
uint8_t		file_to_arr(const char *, char **);
uint8_t		check_headerspcs(int, char *);
uint8_t		check_header(char **);
uint8_t		parser(char **, t_label **, int *);
int		create_cor_file(char *);
t_replacer	*replace_labels(t_label **, int, int);

#endif
