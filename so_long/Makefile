# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmabilla <bmabilla>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:21:24 by bmabilla          #+#    #+#              #
#    Updated: 2023/12/06 12:04:11 by bmabilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= main
GENERATION = generate_map
GENERATION_PATH = srcs/generation/
CHECKERS_PATH = srcs/checkers/
CHECKERS = checker_args checker_map checker_map_build checker_pathfinding
UTILS_PATH = srcs/utils/
UTILS	= utils clear_mem
LIBFT	= ./libft/libft.a
MLX		= ./mlx/libmlx.a
HEARDERS	= -I includes -I ./libft/includes -I ./mlx

all:
	@clear
	@make -C ./libft
	@make -C ./mlx
	$(CC) $(FLAGS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit $(addsuffix .c, $(SRCS)) $(addprefix $(UTILS_PATH), $(addsuffix .c, $(UTILS))) $(addprefix $(GENERATION_PATH), $(addsuffix .c, $(GENERATION))) $(addprefix $(CHECKERS_PATH), $(addsuffix .c, $(CHECKERS))) $(MLX) $(LIBFT) -o $(NAME)

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