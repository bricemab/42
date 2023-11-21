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

NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
		ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
		ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_putstr.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_putchar.c \
        ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_putnbr.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

$(OBJ):
			$(CC) $(FLAGS) -c $(SRC)

clean:
			rm -f $(OBJ) $(BONUS_OBJS)

fclean: 	clean
			rm -f $(NAME)

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

re:			fclean all

.PHONY: 	all clean fclean re bonus