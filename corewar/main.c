/*
** main.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 13:57:13 2017 flavian gontier
** Last update Sun Apr 02 23:34:26 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

void	get_help(int argc, char **argv, int index)
{
  if (my_strcmp("-h", argv[index]) != 0)
    return ;
  my_putstr("USAGE\n\t");
  my_putstr(argv[index]);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name");
  my_putstr("] ...\n\nDESCRIPTION\n\t");
  my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle execution ");
  my_putstr("(if the round isn't\n\t\t");
  my_putstr("\talready over) with the following format: ");
  my_putstr("32 bytes/line in\n\t\t");
  my_putstr("\thexadecimal (A0BCDEFE1DD3...)\n\t");
  my_putstr("-n prog_number \tsets the next program's number.  By default, ");
  my_putstr("the first free number\n\t\t\tin the parameter order\n\t-a ");
  my_putstr("load_address sets the next program's loading address.  When no");
  my_putstr(" address is \n\t\t\tspecified, optimize the addresses so that ");
  my_putstr("the processes are as far \n\t\t\taway ");
  my_putstr("from each other as possible");
  my_putstr(". The addresses are MEM_SIZE modulo\n");
  exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
  t_arguments	arguments;
  t_vm		virtual_machine;

  parse_arguments(argc, argv, &arguments);
  init_virtual_machine(&arguments, &virtual_machine);
  run_virtual_machine(&virtual_machine);
  return (EXIT_SUCCESS);
}
