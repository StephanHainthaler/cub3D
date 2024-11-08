# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juitz <juitz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 09:18:50 by shaintha          #+#    #+#              #
#    Updated: 2024/11/08 16:17:37 by juitz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror -g
MLXFLAGS := -lmlx -lXext -lX11 -lm

SRC_DIR := sources
OBJ_DIR := objects
LIBFT_DIR := libft
MAIN_DIR := main

SRCS := $(SRC_DIR)/main.c \
	$(SRC_DIR)/initialize.c \
	$(SRC_DIR)/map.c \
	$(SRC_DIR)/image.c \
	$(SRC_DIR)/cube.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/player.c \
	$(SRC_DIR)/parser.c

OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cd $(LIBFT_DIR) && make -s
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/libft.a

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make -s clean

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFT_DIR) && make -s fclean

re: fclean all

.PHONY: all clean fclean re
