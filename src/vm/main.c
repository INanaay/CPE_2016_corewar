/*
** main.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 13:57:13 2017 flavian gontier
** Last update Fri Mar 24 19:20:12 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

int	main(int argc, char **argv)
{
  t_arguments	arguments;

  parse_arguments(argc, argv, &arguments);
  return (EXIT_SUCCESS);
}
