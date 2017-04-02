CC	= 	gcc

CFLAGS	=	-I include

SRC	=	utils/op.c				\
		utils/write.c				\
		utils/init.c				\
		utils/parser.c				\
		utils/instruct.c			\
		utils/create_cor_file.c			\
		utils/replace_labels.c			\
		utils/header.c				\
		mylib/string/my_put.c			\
		mylib/string/my_strlen.c		\
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
		mylib/math/my_fabs.c			\
		main.c

OBJS	=	$(SRC:.c=.o)

NAME	=	asm

all:		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		clean all

.PHONY:		clean fclean re all
