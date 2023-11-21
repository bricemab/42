# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 14:47:39 by bmabilla      #+#    #+#              #
#    Updated: 2023/10/11 14:47:40 by bmabilla     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SERVER = server
CLIENT = client

PRINTFNAME = libftprintf.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC_S =	server.c

OBJS = $(SRC_S:.c=.o)

PRINTTFDIR = ./ft_printf


all:
	@make -C $(PRINTTFDIR)
	@gcc $(FLAGS) $(SERVER).c -o $(SERVER) $(PRINTTFDIR)/$(PRINTFNAME)

clean:
	@rm -f $(OBJS)
	@cd $(PRINTTFDIR) && make clean

fclean: clean
	@rm -f $(SERVER)
	@cd $(PRINTTFDIR) && make fclean

re: fclean all

.PHONY: 	all clean fclean re
