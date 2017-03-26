/*
** main.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 13:57:13 2017 flavian gontier
** Last update Sun Mar 26 21:15:07 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

int	main(int argc, char **argv)
{
  t_arguments	arguments;
  t_vm		virtual_machine;

  parse_arguments(argc, argv, &arguments);
  init_virtual_machine(&arguments, &virtual_machine);
  run_virtual_machine(&virtual_machine);
  return (EXIT_SUCCESS);
}
