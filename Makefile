# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 12:56:27 by mtoof             #+#    #+#              #
#    Updated: 2023/01/28 18:25:54 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC = client.c
SRCS = server.c
HEADER = minitalk.h
FLAGS = -Wextra -Wall -Werror

all: start server client

start:
		make -C ./libft && cp ./libft/libft.a .
server:
		gcc $(FLAGS) $(SRCS) -I$(HEADER) libft.a -o $@
client:
		gcc $(FLAGS) $(SRCC) -I$(HEADER) libft.a -o $@
clean:
		make clean -C ./libft
fclean: clean
		make fclean -C ./libft
		/bin/rm -f server client libft.a
re:		fclean	all