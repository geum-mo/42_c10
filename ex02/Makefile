# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 09:30:41 by gekang            #+#    #+#              #
#    Updated: 2020/07/20 16:02:11 by gekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= ./srcs/main.c ./srcs/error_handling.c ./srcs/file_io.c ./srcs/ft_get.c ./srcs/utils.c
OFILES	= ${CFILES:.c=.o}
TARGET	= ft_tail
INCL 	= includes
CC		= gcc
REMOVE		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCL}

${TARGET}: ${OFILES}
	${CC} ${CFLAGS} ${OFILES} -o ${TARGET}

all: ${TARGET}

clean:
	${REMOVE} ${OFILES}

fclean: clean
	${REMOVE} ${TARGET}

re: fclean all

.PHONY: all clean fclean re .c.o
