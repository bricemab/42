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

NAME = libftprintf.a

LIBFTNAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC =	ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_percent.c \
		ft_print_ptr.c ft_print_str.c ft_print_unsigned.c ft_printf.c

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
