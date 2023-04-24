# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2023/04/24 20:40:12 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h

SRC	= ft_isalpha.c		ft_isdigit.c	ft_isalnum.c	\
	  ft_isascii.c		ft_isprint.c	ft_strlen.c		\
	  ft_memset.c		ft_bzero.c		ft_memcpy.c		\
	  ft_memmove.c		ft_strlcpy.c	ft_strlcat.c	\
	  ft_toupper.c		ft_tolower.c 	ft_strchr.c 	\
	  ft_strrchr.c		ft_strncmp.c 	ft_memchr.c 	\
	  ft_memcmp.c		ft_strnstr.c	ft_atoi.c 		\
	  ft_calloc.c 		ft_strdup.c		ft_substr.c 	\
	  ft_strjoin.c		ft_strtrim.c	ft_split.c		\
	  ft_itoa.c			ft_strmapi.c 	ft_striteri.c 	\
	  ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
	  ft_putnbr_fd.c

OBJ = $(SRC:%.c=%.o)

SRC_BONUS = ft_lstnew_bonus.c 	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c	ft_lstiter_bonus.c		ft_lstmap_bonus.c

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library has been created"

bonus: $(OBJ) $(OBJ_BONUS) $(HDR)
	@$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)
	@echo "Library has been created including bonus functions"

clean :
	rm -f $(OBJ) $(OBJ_BONUS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

