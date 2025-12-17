# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipang <mipang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2025/12/17 16:53:47 by mipang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx

SRCS = src/main.c \
		src/atof.c \
		src/close.c \
		src/window.c \
		src/key_hook.c \
		src/color.c
MATH = math/point.c \
		math/vector.c \
		math/ray.c
PARSING = parsing/utils/dispatch_utils.c \
			parsing/utils/parser_utils.c \
			parsing/dispatch.c \
			parsing/parser.c
		
FILES = $(SRCS) $(MATH) $(PARSING)
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


