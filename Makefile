# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 17:19:51 by jaisanch          #+#    #+#              #
#    Updated: 2023/06/28 17:20:31 by jaisanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM	= rm -rf

FILES = ft_printf.c ft_printf_ptr.c ft_printf_nbr.c ft_printf_utils.c ft_printf_unsigned.c  ft_printf_hexa.c \

OBJS	= ${FILES:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

all:	${NAME}

clean:
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus