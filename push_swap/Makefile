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

NAME = push_swap

PRINTF = libftprintf.a

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

SRC =	main.c args_checker.c error.c push.c reverse.c rotate.c swap.c \
		s_lstadd_back.c s_lstnew.c s_lstlast.c

OBJS = $(SRC:.c=.o)

FTPRINTFDIR = ./ft_printf

all: $(NAME)

makeftprintf:
	@make -C $(FTPRINTFDIR)
	@cp $(FTPRINTFDIR)/$(PRINTF) .
	@mv $(PRINTF) $(NAME)

# $(NAME):	makeftprintf $(OBJS)
#			@ar rc $(NAME) $(OBJS)
#			@ranlib $(NAME)
#			@chmod +x $(NAME)

$(NAME):	makeftprintf
			$(CC) $(FLAGS) $(SRC) $(FTPRINTFDIR)/$(PRINTF) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@cd $(FTPRINTFDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(FTPRINTFDIR) && make fclean

re: fclean all

.PHONY: 	all clean fclean re
