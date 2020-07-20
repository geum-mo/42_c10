# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 09:30:41 by gekang            #+#    #+#              #
#    Updated: 2020/07/20 11:30:36 by gekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= ./srcs/main.c
OFILES	= ${CFILES:.c=.o}
TARGET	= ft_display_file
INCL 	= includes
CC		= gcc
REMOVE		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCL}

${TARGET}: ${OFILES} # ${Varname} --> use variable
	${CC} ${CFLAGS} ${OFILES} -o ${TARGET}

all: ${TARGET}

clean:
	${REMOVE} ${OFILES}

fclean: clean
	${REMOVE} ${TARGET}

re: fclean all

.PHONY: all clean fclean re .c.o
