/*
** arguments.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/vm/src/input
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 22:33:07 2017 flavian gontier
** Last update Fri Mar 24 17:10:30 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

static int	get_cycles(char **args, t_arguments *arguments)
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
  arguments->cycle_count = my_atoi(args[1]);
  if (arguments->cycle_count < 0)
  {
    my_puterr("The cycle count must be a positiv number.\n");
    exit(EXIT_ERROR);
  }
  return (index);
}

static int	get_process(char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-n") != 0)
  {
    arguments->process_id = -1;
    return (index);
  }
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

static int	get_address(char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-a") != 0)
  {
    arguments->start_address = -1;
    return (index);
  }
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

static int	get_name(char **argv, t_arguments *arguments)
{
  int	index;

  index = 1;
  arguments->name = argv[0];
  return (index);
}

void	parse_arguments(int argc, char **argv, t_arguments *arguments)
{
  int	index;

  index = 1;
  //printf("Getting cycles...\n");
  index += get_cycles(&argv[index], arguments);
  //printf("index: %d\n", index);
  //printf("Getting process...\n");
  index += get_process(&argv[index], arguments);
  //printf("Getting address...\n");
  index += get_address(&argv[index], arguments);
  //printf("Getting name...\n");
  index += get_name(&argv[index], arguments);
  printf("============ARGS DEBUG============\n");
  printf("Name: %s\n", arguments->name);
  printf("Cycles: %d\n", arguments->cycle_count);
  printf("Process id: %d\n", arguments->process_id);
  printf("Address: %d\n", arguments->start_address);
  printf("===================================\n");
}
