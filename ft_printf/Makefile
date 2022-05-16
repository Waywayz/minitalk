# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:09:05 by rovillar          #+#    #+#              #
#    Updated: 2021/12/16 19:13:54 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c srcs/print_s.c srcs/print_i.c srcs/print_u.c srcs/print_x.c srcs/print_p.c

HEADER = ./includes

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
								${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} -I${HEADER}

${NAME}: ${OBJS}
						${MAKE} bonus -C ./libft
						cp libft/libft.a ${NAME}
						ar rc ${NAME} ${OBJS}
						ranlib ${NAME}

all	:	${NAME}

clean	:
								${MAKE} clean -C ./libft
								-rm -rf ${OBJS}
fclean	:	clean
								${MAKE} fclean -C ./libft
								-rm -rf ${NAME}
re	:		fclean all

.PHONY	:	all clean fclean re
