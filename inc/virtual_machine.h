/*
** virtual_machine.h for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/inc
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 15:39:16 2017 flavian gontier
** Last update Fri Mar 24 15:48:17 2017 flavian gontier
*/

#include <stdint.h>

typedef struct	s_arguments
{
  char		*name;
  uint32_t	cycle_count;
  uint32_t	process_id;
  uint32_t	start_address;
}		t_arguments;
