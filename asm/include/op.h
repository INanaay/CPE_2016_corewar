/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sun Apr  2 16:33:53 2017 nathan
*/

#ifndef _OP_H_
# define _OP_H_

# define MAX_ARGS_NUMBER	4
# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define REG_NUMBER		16
# define REG_SIZE		1
# define IND_SIZE		2
# define DIR_SIZE		4
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define T_REG			1
# define T_DIR			2
# define T_IND			3
# define T_LAB			8

typedef char    t_args_type;

typedef struct	s_op
{
   char         *mnemonique;
   char         nbr_args;
   t_args_type  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
}		t_op;

extern  t_op    g_op_tab[];

#endif
