NAME	= libftprintf.a

CC	= gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM	= rm -rf

FILES = ft_printf.c ft_printhexa.c ft_printnbr.c ft_print_utils.c ft_print_unsigned.c \

OBJS	= ${FILES:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

all:	${NAME}

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus