/*
** instruction.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_bytecode/src/bytecode/parsing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 16:52:37 2017 flavian gontier
** Last update Wed Mar 29 12:15:12 2017 flavian gontier
*/

#include <stdint.h>

int	get_params_count(int8_t params_type)
{
  int		count;
  int		scale;
  int		tmp;

  count = 0;
  scale = 6;
  while (scale > 0)
  {
    tmp = (params_type & T_IND << scale);
    if (tmp == 0)
      break ;
    count += 1;
    scale -= 2;
  }
  return (count);
}

int	get_param_type(int8_t params_type, int8_t param_index)
{
  int	scale;
  int	result;

  scale = 6 - (param_index * 2);
  result = params_type & (T_IND << scale);
  result = result >> scale;
  return (result);
}

int	get_params_size(int8_t params_type)
{
  int	result;
  int	index;
  int	type;

  result = 0;
  index = 0;
  while (index < 3)
  {
    type = get_param_type(params_type, index);
    result += get_param_size(type);
    index = index + 1;
  }
  return (result);
}

int	get_param_size(int type)
{
  if (type == T_REG)
    return (REG_SIZE);
  else if (type == T_IND)
    return (IND_SIZE);
  else if (type == T_DIR)
    return (DIR_SIZE);
  return (0);
}

int8_t	*get_params(t_vm *virtual_machine, int addr, int8_t paramstype)
{
  int8_t	*result;
  int		size;

  size = get_params_size(paramstype);
  result = malloc(sizeof(int8_t) * size);
  my_memcpy(result, &virtual_machine->memory[addr], size);
  return (result);
}
