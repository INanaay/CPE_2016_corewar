##
## Makefile for navy in /home/nathan/projects/PSU_2016_navy/NS
##
## Made by nathan
## Login   <nathan.schwarz@epitech.eu@epitech.net>
##
## Started on  Thu Feb  2 20:38:34 2017 nathan
## Last update Wed Mar 29 15:27:13 2017 nathan
##

CC	= 		gcc -g3

CFLAGS	+=		-I include

SRC	=		utils/op.c				\
			write.c					\
			init.c					\
			parser.c				\
			main.c

MYLBSRC	=		mylib/string/my_strlen.c		\
			mylib/string/my_put.c			\
			mylib/string/my_strcontains.c		\
			mylib/string/my_strtowtb.c		\
			mylib/string/my_strcompare.c		\
			mylib/string/my_strtablen.c		\
			mylib/string/my_strfind.c		\
			mylib/string/my_taballoc.c		\
			mylib/string/my_atoi.c			\
			mylib/string/my_strcpy.c		\
			mylib/string/my_charis.c		\
			mylib/string/my_gnl.c			\
			mylib/string/my_strcat.c		\
			mylib/string/my_putconcat.c		\
			mylib/string/my_getenv.c		\
			mylib/string/epurstr.c			\
			mylib/mem/my_calloc.c			\
			mylib/math/my_pow.c			\
			mylib/math/my_sqrt.c			\
			mylib/math/my_fabs.c

NAME	=		asm

$(NAME):	 	$(SRC)
			$(CC) $(SRC) $(MYLBSRC) $(CFLAGS) -o $(NAME)

all:			$(NAME)

clean:
			rm -f $(NAME)

fclean:			clean

re:			clean all

.PHONY:			clean fclean re all
