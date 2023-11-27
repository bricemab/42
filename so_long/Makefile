# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmabilla <bmabilla>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:21:24 by bmabilla          #+#    #+#              #
#    Updated: 2023/11/27 14:24:39 by bmabilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= main.c
LIBFT	= ./libft/libft.a
MLX		= ./mlx/libmlx.a
HEARDERS	= -I includes -I ./libft/includes -I ./mlx

all:
	@clear
	@make -C ./libft
	@make -C ./mlx
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -g $(HEADERS) $(SRCS) $(MLX) $(LIBFT) -o $(NAME)
#	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ $(SRCS) -o $(NAME) $(LIBFT)

clean:
	@clear
	@rm -rf $(NAME)
	@cd ./libft && make clean
	@cd ./mlx && make clean
	
fclean:
	@clear
	@rm -rf $(NAME)
	@cd ./libft && make fclean
	@cd ./mlx && make clean
	
re:	fclean all
	
.PHONY: 	all clean fclean re