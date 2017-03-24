/*
** assembly.h for corewar in /home/nathan/projects/CPE_2016_corewar/assembly
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Wed Mar 22 13:43:32 2017 nathan
** Last update Fri Mar 24 16:25:28 2017 nathan
*/

#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#define HELP "USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n"
#define HELP1 "\tfile_name\tfile in assembly language to be converted into "
#define HELP2 "file_name.cor, an\n\t\t\texecutable in the Virtual Machine).\n"

typedef	struct	s_label
{
  char		*name;
  char		*inst;
  char		**args;
  int		size;
}		t_label;

#endif
