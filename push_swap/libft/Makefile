# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 10:09:28 by lgaume            #+#    #+#              #
#    Updated: 2023/11/21 16:42:11 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc
NAME 		= 	libft.a
INCS			=	include/
FLAGS 		= 	-Wall -Wextra -Werror -I
RM			=	rm -f
AR			=	ar rcs

SRC_PATH	=	src/
OBJ_PATH	=	obj/


ALLOC_DIR		=	$(SRC_PATH)ft_alloc/ft_bzero.c \
					$(SRC_PATH)ft_alloc/ft_calloc.c

ATOI_DIR		=	$(SRC_PATH)ft_atoi/ft_atoi.c \
					$(SRC_PATH)ft_atoi/ft_itoa.c \
					$(SRC_PATH)ft_atoi/ft_unsigned_itoa.c

IS_DIR			=	$(SRC_PATH)ft_is/ft_isalnum.c \
					$(SRC_PATH)ft_is/ft_isalpha.c \
					$(SRC_PATH)ft_is/ft_isascii.c \
					$(SRC_PATH)ft_is/ft_isdigit.c \
					$(SRC_PATH)ft_is/ft_isprint.c \
					$(SRC_PATH)ft_is/ft_isspace.c \
					$(SRC_PATH)ft_is/ft_issign.c 

LST_DIR			=	$(SRC_PATH)ft_lst/ft_lstadd_back.c \
					$(SRC_PATH)ft_lst/ft_lstadd_front.c \
					$(SRC_PATH)ft_lst/ft_lstclear.c \
					$(SRC_PATH)ft_lst/ft_lstdelone.c \
					$(SRC_PATH)ft_lst/ft_lstiter.c \
					$(SRC_PATH)ft_lst/ft_lstlast.c \
					$(SRC_PATH)ft_lst/ft_lstmap.c \
					$(SRC_PATH)ft_lst/ft_lstnew.c \
					$(SRC_PATH)ft_lst/ft_lstsize.c

MEM_DIR			=	$(SRC_PATH)ft_mem/ft_memchr.c \
					$(SRC_PATH)ft_mem/ft_memcmp.c \
					$(SRC_PATH)ft_mem/ft_memcpy.c \
					$(SRC_PATH)ft_mem/ft_memmove.c \
					$(SRC_PATH)ft_mem/ft_memset.c

PRINTF_DIR		=	$(SRC_PATH)ft_printf/ft_print_char.c \
					$(SRC_PATH)ft_printf/ft_print_hex.c \
					$(SRC_PATH)ft_printf/ft_print_ptr.c \
					$(SRC_PATH)ft_printf/ft_print_unsigned.c \
					$(SRC_PATH)ft_printf/ft_printf.c \
					$(SRC_PATH)ft_printf/ft_printnbr.c \
					$(SRC_PATH)ft_printf/ft_printstr.c \
					$(SRC_PATH)ft_printf/ft_print_stderr.c

PUT_DIR			=	$(SRC_PATH)ft_put/ft_putchar_fd.c \
					$(SRC_PATH)ft_put/ft_putendl_fd.c \
					$(SRC_PATH)ft_put/ft_putnbr_fd.c \
					$(SRC_PATH)ft_put/ft_putstr_fd.c

STR_DIR			=	$(SRC_PATH)ft_str/ft_strchr.c \
					$(SRC_PATH)ft_str/ft_strdup.c \
					$(SRC_PATH)ft_str/ft_striteri.c \
					$(SRC_PATH)ft_str/ft_strjoin.c \
					$(SRC_PATH)ft_str/ft_strlcat.c \
					$(SRC_PATH)ft_str/ft_strlcpy.c \
					$(SRC_PATH)ft_str/ft_strlen.c \
					$(SRC_PATH)ft_str/ft_strmapi.c \
					$(SRC_PATH)ft_str/ft_strncat.c \
					$(SRC_PATH)ft_str/ft_strncmp.c \
					$(SRC_PATH)ft_str/ft_strnew.c \
					$(SRC_PATH)ft_str/ft_strnstr.c \
					$(SRC_PATH)ft_str/ft_strrchr.c \
					$(SRC_PATH)ft_str/ft_strtrim.c \
					$(SRC_PATH)ft_str/ft_substr.c \
					$(SRC_PATH)ft_str/ft_strcmp.c

TO_DIR			=	$(SRC_PATH)ft_to/ft_tolower.c \
					$(SRC_PATH)ft_to/ft_toupper.c

UTILS_DIR		=	$(SRC_PATH)ft_utils/ft_split.c \
					$(SRC_PATH)ft_utils/ft_free_ptrstr.c

GNL_DIR			=	$(SRC_PATH)GNL/get_next_line.c \
					$(SRC_PATH)GNL/get_next_line_utils.c

SRC 			=	$(ALLOC_DIR) $(ATOI_DIR) $(IS_DIR) $(LST_DIR) $(MEM_DIR) $(PRINTF_DIR) $(PUT_DIR) $(STR_DIR) $(TO_DIR) $(UTILS_DIR) $(GNL_DIR)

OBJ				= 	$(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRC))

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(@D)
				@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_PATH)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
