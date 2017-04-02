/*
** arguments.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/vm/src/input
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 22:33:07 2017 flavian gontier
** Last update Sun Apr 02 23:32:50 2017 flavian gontier
*/

#include "libmy.h"
#include "virtual_machine.h"

static int	get_cycles(char **args, t_arguments *arguments)
{
  int	index;

  index = 0;
  if (my_strcmp(args[0], "-dump") != 0)
  {
    my_puterr("ERROR: You have to define a cycle count.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  if (my_strisnum(args[1]) == 0)
  {
    my_puterr("ERROR: The cycle count must be a valid number.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  arguments->cycle_count = my_atoi(args[1]);
  if (arguments->cycle_count < 0)
  {
    my_puterr("ERROR: The cycle count must be a positiv number.\n");
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
    my_puterr("ERROR: The process's id must be valid.\n");
    exit(EXIT_ERROR);
  }
  index = index + 1;
  arguments->process_id = my_atoi(args[1]);
  if (arguments->process_id < 0)
  {
    my_puterr("ERROR: The process's id must be positiv.\n");
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
    my_puterr("ERROR: The address must be a valid address.\n");
    exit(EXIT_ERROR);
  }
  arguments->start_address = my_atoi(args[1]);
  index = index + 1;
  if (arguments->start_address < 0)
  {
    my_puterr("ERROR: The address must be positiv.\n");
    exit(EXIT_ERROR);
  }
  return (index);
}

void	get_champions(int argc, char **argv, int index,  t_arguments *arguments)
{
  int	tmp;
  int	count;

  tmp = 0;
  count = argc - index;
  if (count == 0)
  {
    my_puterr("ERROR: no champion given.\n");
    exit(EXIT_ERROR);
  }
  arguments->champions = my_calloc(sizeof(char *) * (count + 1));
  arguments->champion_count = count;
  while (index < argc)
  {
    arguments->champions[tmp] = my_strdup(argv[index]);
    tmp = tmp + 1;
    index = index + 1;
  }
}

void	parse_arguments(int argc, char **argv, t_arguments *arguments)
{
  int	index;

  index = 1;
  if (argc == 1)
  {
    my_puterr("ERROR: No argument.\n");
    exit(EXIT_ERROR);
  }
  get_help(argc, argv, index);
  index += get_cycles(&argv[index], arguments);
  index += get_process(&argv[index], arguments);
  index += get_address(&argv[index], arguments);
  get_champions(argc, argv, index, arguments);
}
