##
## Makefile for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
##
## Made by flavian gontier
## Login   <flavian.gontier@epitech.net>
##
## Started on  Sat Jan 21 00:04:28 2017 flavian gontier
## Last update Sun Apr  2 23:08:49 2017 nathan
##

CC	=	gcc

CFLAGS	+=	-I inc

LDFLAGS	+=	-Werror -Wall -Wextra

VM_SRC	=	corewar/lib/io/my_put.c					\
		corewar/lib/io/my_putstr.c				\
		corewar/lib/io/my_puterr.c				\
		corewar/lib/io/my_putconcat.c				\
		corewar/lib/io/my_read_file.c				\
		corewar/lib/io/get_next_line.c				\
		corewar/lib/mem/my_calloc.c				\
		corewar/lib/mem/my_realloc.c				\
		corewar/lib/mem/my_memset.c				\
		corewar/lib/mem/my_memcpy.c				\
		corewar/lib/mem/my_freetab.c				\
		corewar/lib/string/my_atoi.c				\
		corewar/lib/string/my_linedup.c				\
		corewar/lib/string/my_strncmp.c				\
		corewar/lib/string/my_strcmp.c				\
		corewar/lib/string/my_strcat.c				\
		corewar/lib/string/my_strcpy.c				\
		corewar/lib/string/my_strncpy.c				\
		corewar/lib/string/my_strindex.c				\
		corewar/lib/string/my_strsplit.c				\
		corewar/lib/string/my_strcontains.c			\
		corewar/lib/string/my_strisalphanum.c			\
		corewar/lib/string/my_strisnum.c				\
		corewar/lib/string/my_strdup.c				\
		corewar/lib/string/my_strndup.c				\
		corewar/lib/string/my_len.c				\
		corewar/lib/string/my_strlen.c				\
		corewar/lib/string/my_strtab.c				\
		corewar/lib/string/my_tabdim.c				\
		corewar/lib/string/my_tabncpy.c				\
		corewar/lib/string/my_tabdup.c				\
		corewar/lib/string/my_tabelem.c				\
		corewar/lib/string/my_get_base.c				\
		corewar/lib/list/listInt32/listInt32_add.c		\
		corewar/lib/list/listInt32/listInt32_remove.c		\
		corewar/lib/list/listInt32/listInt32_insert.c		\
		corewar/lib/list/listInt32/listInt32_init.c		\
		corewar/lib/list/listInt32/listInt32_expends.c		\
		corewar/lib/list/listString/listString_add.c		\
		corewar/lib/list/listString/listString_remove.c		\
		corewar/lib/list/listString/listString_insert.c		\
		corewar/lib/list/listString/listString_init.c		\
		corewar/lib/list/listString/listString_expends.c		\
		bytecode/io/read.c					\
		bytecode/io/write.c					\
		bytecode/io/utils.c					\
		bytecode/parsing/header.c				\
		bytecode/parsing/instruction.c			\
		bytecode/parsing/params.c				\
		bytecode/stream/stream.c				\
		corewar/input/arguments.c				\
		corewar/virtual_machine/init.c				\
		corewar/virtual_machine/run.c				\
		corewar/virtual_machine/exec.c				\
		corewar/virtual_machine/utils.c				\
		corewar/virtual_machine/handlers/alive.c			\
		corewar/main.c

VM_OBJ	=	$(VM_SRC:.c=.o)

VM_NAME	=	corewar

RM	=	rm -f

all:		$(VM_NAME) asm_build

$(VM_NAME):	$(VM_OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) $(VM_OBJ) -o corewar/$(VM_NAME)

asm_build:
		$(MAKE) -C asm

clean:
		$(RM) $(VM_OBJ)
		$(MAKE) -C asm clean

fclean:		clean
		$(RM) corewar/$(VM_NAME)
		$(MAKE) -C asm fclean

re:		fclean all

.PHONY:		all clean fclean re
