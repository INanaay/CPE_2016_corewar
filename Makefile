##
## Makefile for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
##
## Made by flavian gontier
## Login   <flavian.gontier@epitech.net>
##
## Started on  Sat Jan 21 00:04:28 2017 flavian gontier
## Last update Fri Mar 24 15:31:08 2017 flavian gontier
##

CC	=	gcc

CFLAGS	+=	-I inc

LDFLAGS	+=	-Wall -Wextra -g3

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
			src/vm/lib/string/my_strdup.c						\
			src/vm/lib/string/my_strndup.c						\
			src/vm/lib/string/my_len.c							\
			src/vm/lib/string/my_strlen.c						\
			src/vm/lib/string/my_strtab.c						\
			src/vm/lib/string/my_tabdim.c						\
			src/vm/lib/string/my_tabncpy.c						\
			src/vm/lib/string/my_tabdup.c						\
			src/vm/lib/string/my_tabelem.c						\
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
			src/input/arguments.h								\
			src/main.c

OBJ     =	$(SRC:.c=.o)

RM      =       rm -rf

NAME    =       tetris

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
