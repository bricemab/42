# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 14:47:39 by bmabilla          #+#    #+#              #
#    Updated: 2023/10/11 14:47:40 by bmabilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap

PUSHSWAP = libft.a

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

SRC =	ft_*.c

OBJS = $(SRC:.c=.o)

LIBFTDIR = ./libft


all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME):	makelibft $(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: 	all clean fclean re
