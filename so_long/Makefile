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
MLX_LINUX = ./mlx-linux/libmlx.a
HEARDERS	= -I includes -I ./libft/includes -I ./mlx
HEARDERS_LINUX	= -I includes -I ./libft/includes -I ./mlx-linux

all:
	@clear
	@make -C ./libft
	#@make -C ./mlx
	@make -C ./mlx-linux
#	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(addsuffix .c, $(SRCS)) $(addprefix $(UTILS_PATH), $(addsuffix .c, $(UTILS))) $(addprefix $(GENERATION_PATH), $(addsuffix .c, $(GENERATION))) $(addprefix $(CHECKERS_PATH), $(addsuffix .c, $(CHECKERS))) $(MLX) $(LIBFT) -o $(NAME)
	$(CC) $(FLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(addsuffix .c, $(SRCS)) $(addprefix $(UTILS_PATH), $(addsuffix .c, $(UTILS))) $(addprefix $(GENERATION_PATH), $(addsuffix .c, $(GENERATION))) $(addprefix $(CHECKERS_PATH), $(addsuffix .c, $(CHECKERS))) $(MLX_LINUX) $(LIBFT) -o $(NAME)
#	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT) $(MLX)

%.o: %.c
	#$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ $(SRCS) -o $(NAME) $(LIBFT)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@ $(SRCS) -o $(NAME) $(LIBFT)

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