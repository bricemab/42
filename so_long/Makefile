# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmabilla <bmabilla>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:21:24 by bmabilla          #+#    #+#              #
#    Updated: 2023/11/30 14:38:01 by bmabilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= main checker_args checker_map utils checker_map_build clear_mem
LIBFT	= ./libft/libft.a
MLX		= ./mlx/libmlx.a
HEARDERS	= -I includes -I ./libft/includes -I ./mlx

all:
	@clear
	@make -C ./libft
	@make -C ./mlx
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(addsuffix .c, $(SRCS)) $(MLX) $(LIBFT) -o $(NAME)
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
	
re:	fclean all
	
.PHONY: 	all clean fclean re