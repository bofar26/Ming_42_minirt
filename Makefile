# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2025/12/17 17:59:48 by lzannis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx

SRCS_WINDOW = \
		src/atof.c \
		src/close.c \
		src/window.c \
		src/key_hook.c \
		src/color.c

SRC_PARSING_CORE = \
	parsing/core/parser.c \
	parsing/core/dispatch.c

SRC_PARSING_IDENTIFIERS = \
	parsing/parsers/parsers_identifier/parser_A.c \
	parsing/parsers/parsers_identifier/parser_C.c \
	parsing/parsers/parsers_identifier/parser_L.c \
	parsing/parsers/parsers_identifier/parser_SP.c \
	parsing/parsers/parsers_identifier/parser_PL.c \
	parsing/parsers/parsers_identifier/parser_CY.c

SRC_PARSING_VALUES = \
	parsing/parsers/parser_color.c \
	parsing/parsers/parser_vec3.c \
	parsing/parsers/parser_int.c \
	parsing/parsers/parser_double.c

SRC_SCENE = \
	parsing/scene/scene_add.c \
	parsing/scene/scene_init.c

SRC_UTILS = \
	parsing/utils/check_utils.c \
	parsing/utils/error_utils.c \
	parsing/utils/token_utils.c

SRC_MAIN = \
	src/main.c

SRCS = \
	$(SRC_PARSING_CORE) \
	$(SRC_PARSING_IDENTIFIERS) \
	$(SRC_PARSING_VALUES) \
	$(SRC_SCENE) \
	$(SRC_UTILS) \
	$(SRC_MAIN)
	
FILES = $(SRCS) $(SRCS_WINDOW) 
OBJS =$(FILES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re


