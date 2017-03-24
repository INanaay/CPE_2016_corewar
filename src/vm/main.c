/*
** main.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 13:57:13 2017 flavian gontier
** Last update Fri Mar 24 19:06:24 2017 flavian gontier
*/

#include "virtual_machine.h"

void	my_help(const char *name)
{
  my_putstr("USAGE\n\t");
  my_putstr(name);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name");
  my_putstr("] ...\n\n");
  my_putstr("DESCRIPTION\n\t");
  my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle execution ");
  my_putstr("(if the round isn't\n\t\t");
  my_putstr("already over) with the following format: 32 bytes/line in\n\t\t");
  my_putstr("hexadecimal (A0BCDEFE1DD3...)\n\t");
  my_putstr("-n prog_number sets the next program's number.  By default, ");
  my_putstr("the first free number\n\t\tin the parameter order\n\t");
  my_putstr("-a load_address sets the next program's loading address.  When ");
  my_putstr("no address is \n\t\tspecified, optimize the addresses so that ");
  my_putstr("the processes are as far \n\t\taway from each other as possible");
  my_putstr(". The addresses are MEM_SIZE modulo\n");
}

int	main(int argc, char **argv)
{
  t_arguments	arguments;

  parse_arguments(argc, argv, &arguments);
  return (EXIT_SUCCESS);
}
