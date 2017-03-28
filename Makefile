##
## Makefile for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
##
## Made by flavian gontier
## Login   <flavian.gontier@epitech.net>
##
## Started on  Sat Jan 21 00:04:28 2017 flavian gontier
## Last update Tue Mar 28 14:53:30 2017 anatole zeyen
##

CC	=	gcc

CFLAGS	+=	-I inc

LDFLAGS	+=	-Werror -Wall -Wextra -g3

VM_SRC	=	src/vm/lib/io/my_put.c								\
			src/vm/lib/io/my_putstr.c							\
			src/vm/lib/io/my_puterr.c							\
			src/vm/lib/io/my_putconcat.c						\
			src/vm/lib/io/my_read_file.c						\
			src/vm/lib/io/get_next_line.c						\
			src/vm/lib/mem/my_calloc.c							\
			src/vm/lib/mem/my_realloc.c							\
			src/vm/lib/mem/my_memset.c							\
			src/vm/lib/mem/my_memcpy.c							\
			src/vm/lib/mem/my_freetab.c							\
			src/vm/lib/string/my_atoi.c							\
			src/vm/lib/string/my_linedup.c						\
			src/vm/lib/string/my_strncmp.c						\
			src/vm/lib/string/my_strcmp.c						\
			src/vm/lib/string/my_strcat.c						\
			src/vm/lib/string/my_strcpy.c						\
			src/vm/lib/string/my_strncpy.c						\
			src/vm/lib/string/my_strindex.c						\
			src/vm/lib/string/my_strsplit.c						\
			src/vm/lib/string/my_strcontains.c					\
			src/vm/lib/string/my_strisalphanum.c				\
			src/vm/lib/string/my_strisnum.c						\
			src/vm/lib/string/my_strdup.c						\
			src/vm/lib/string/my_strndup.c						\
			src/vm/lib/string/my_len.c							\
			src/vm/lib/string/my_strlen.c						\
			src/vm/lib/string/my_strtab.c						\
			src/vm/lib/string/my_tabdim.c						\
			src/vm/lib/string/my_tabncpy.c						\
			src/vm/lib/string/my_tabdup.c						\
			src/vm/lib/string/my_tabelem.c						\
			src/vm/lib/string/my_get_base.c						\
			src/vm/lib/list/listInt32/listInt32_add.c			\
			src/vm/lib/list/listInt32/listInt32_remove.c		\
			src/vm/lib/list/listInt32/listInt32_insert.c		\
			src/vm/lib/list/listInt32/listInt32_init.c			\
			src/vm/lib/list/listInt32/listInt32_expends.c		\
			src/vm/lib/list/listString/listString_add.c			\
			src/vm/lib/list/listString/listString_remove.c		\
			src/vm/lib/list/listString/listString_insert.c		\
			src/vm/lib/list/listString/listString_init.c		\
			src/vm/lib/list/listString/listString_expends.c		\
			src/vm/input/arguments.c							\
			src/vm/virtual_machine/init.c						\
			src/vm/virtual_machine/run.c				\
			src/vm/main.c

VM_OBJ     	=	$(VM_SRC:.c=.o)

VM_NAME    	=	corewar

RM			=	rm -f

all:		$(VM_NAME)

$(VM_NAME): 	$(VM_OBJ)
				$(CC) $(CFLAGS) $(LDFLAGS) $(VM_OBJ) -o $(VM_NAME)

clean:
			$(RM) $(VM_OBJ)

fclean:		clean
			$(RM) $(VM_NAME)

re:			fclean all

.PHONY:		all clean fclean re
