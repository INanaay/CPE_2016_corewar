/*
** arguments.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/vm/src/input
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 22:33:07 2017 flavian gontier
** Last update Fri Mar 24 19:41:55 2017 flavian gontier
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

static void	get_help(int argc, char **argv, int index)
{
  if (my_strcmp("-h", argv[index]) != 0)
    return ;
  my_putstr("USAGE\n\t");
  my_putstr(argv[index]);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name");
  my_putstr("] ...\n\nDESCRIPTION\n\t");
  my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle execution ");
  my_putstr("(if the round isn't\n\t\t");
  my_putstr("\talready over) with the following format: 32 bytes/line in\n\t\t");
  my_putstr("\thexadecimal (A0BCDEFE1DD3...)\n\t");
  my_putstr("-n prog_number \tsets the next program's number.  By default, ");
  my_putstr("the first free number\n\t\t\tin the parameter order\n\t-a ");
  my_putstr("load_address sets the next program's loading address.  When no");
  my_putstr(" address is \n\t\t\tspecified, optimize the addresses so that ");
  my_putstr("the processes are as far \n\t\t\taway from each other as possible");
  my_putstr(". The addresses are MEM_SIZE modulo\n");
  exit(EXIT_SUCCESS);
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
  arguments->name = argv[index];
}
