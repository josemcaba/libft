# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2024/08/17 14:22:16 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libft.a

# Rutas de los archivos fuente
SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Rutas de los archivos objeto
OBJ_DIR = .
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Opciones del compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regla para construir todo
all: $(NAME)

# Regla principal para construir la biblioteca
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

# Regla para construir los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJ_FILES)

# Regla para limpiar los archivos objeto y la biblioteca
fclean: clean
	rm -f $(NAME)

# Regla para reconstruir todo
re: fclean all

.PHONY: all clean fclean re
