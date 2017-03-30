/*
** header.h for  in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar_vm
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Mar 29 19:56:03 2017 flavian gontier
** Last update Wed Mar 29 20:07:22 2017 flavian gontier
*/

#ifndef HEADER_H_
# define HEADER_H_

#include <stdint.h>
#include "bytecode.h"
#include "virtual_machine.h"

# define NAME_SIZE 128
# define COM_SIZE 2048

typedef struct	s_header
{
  int32_t	magic;
  int8_t	name[NAME_SIZE + 1];
  int32_t	size;
  int8_t	comment[COM_SIZE + 1];
}		t_header;

#endif /* !HEADER_H */
