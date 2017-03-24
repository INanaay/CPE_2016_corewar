/*
** arguments.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/vm/src/input
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 22:33:07 2017 flavian gontier
** Last update Fri Mar 24 15:22:46 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

static int	get_cycles(const char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-dump") != 0)
  {
    my_puterr("You have to define a cycle count.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  if (my_strisnum(args[1]) == 0)
  {
    my_puterr("The cycle count must be a valid number.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  arguments->cycles = my_atoi(args[1]);
  if (arguments->cycles < 0)
  {
    my_puterr("The cycle count must be a positiv number.\n");
    exit(EXIT_ERROR);
  }
}

static int	get_process(const char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-n") != 0)
    return (index);
  index = index + 1;
  if (my_strisnum(args[1]) == 0)
  {
    my_puterr("The process's id must be valid.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  arguments->process_id = my_atoi(args[1]);
  if (arguments->process_id < 0)
  {
    my_puterr("The process's id must be positiv.\n");
    exit(EXIT_ERROR);
  }
  return (index);
}

static int	get_address(const char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-a") != 0)
    return (index);
  index = index + 1;
  if (my_strisnum(args[1]) == 0)
  {
    my_puterr("The address must be a valid address.\n");
    exit(EXIT_ERROR);
  }
  arguments->start_address = my_atoi(args[1]);
  index = index + 1;
  if (arguments->start_address < 0)
  {
    my_puterr("The address must be positiv.\n");
    exit(EXIT_ERROR);
  }
  return (index);
}

static int	get_name(const char **argv, t_arguments *arguments)
{
  arguments->name = argv[0];
}

void	parse_arguments(int argc, char **argv, t_arguments *arguments)
{
  int	index;

  index = 1;
  index += get_cycles(&argv[index], arguments);
  index += get_process(&argv[index], arguments);
  index += get_address(&argv[index], arguments);
  index += get_name(&argv[index], arguments);
  printf("=======PARSE_ARGUMENTS DEBUG=======\n");
  printf("Name: %s\n", arguments->name);
  printf("Cycles: %d\n", arguments->cycles);
  printf("Process id: %d\n", argument->process_id);
  printf("Address: %d\n", argument->start_address);
  printf("===================================\n");
}
