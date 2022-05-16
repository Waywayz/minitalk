# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 16:17:34 by rovillar          #+#    #+#              #
#    Updated: 2022/04/15 16:17:35 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_PATH = ft_printf

PRINTF = libftprintf.a

FT_PRINTF = ft_printf/libftprintf.a

SRCS = minitalk_utils.c

SRCS_B = minitalk_utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SERVER = server

SERVER_BONUS = server_bonus

CLIENT = client

CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT) $(PRINTF)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(PRINTF)

$(SERVER_BONUS):$(OBJS_B) minitalk_bonus.h $(PRINTF)
		$(CC) $(CFLAGS) server_bonus.c $(OBJS_BONUS) $(FT_PRINTF) -o $(SERVER_BONUS)
$(CLIENT_BONUS):$(OBJS_B) minitalk_bonus.h $(PRINTF)
		$(CC) $(CFLAGS) client_bonus.c $(OBJS_BONUS) $(FT_PRINTF) -o $(CLIENT_BONUS)

$(SERVER):$(OBJS) minitalk.h $(PRINTF)
		$(CC) $(CFLAGS) server.c $(OBJS) $(FT_PRINTF) -o $(SERVER)
$(CLIENT):$(OBJS) minitalk.h $(PRINTF)
		$(CC) $(CFLAGS) client.c $(OBJS) $(FT_PRINTF) -o $(CLIENT)

$(PRINTF):
		(cd $(PRINTF_PATH) && $(MAKE))
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS) $(OBJS_B)
fclean:	clean
	rm -rf $(CLIENT) $(SERVER) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)
	cd $(PRINTF_PATH) && $(MAKE) $@
re:	fclean all

.PHONY:	all clean fclean re
