# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2025/12/16 22:52:17 by lzannis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx

SRCS = src/utils_src/atof.c \
		src/utils_src/time.c \
		src/utils_src/init.c \
		src/main.c \
		src/close.c \
		src/window.c \
		src/key_hook.c \
		src/color.c
MATHS = maths/utils_maths/utils_maths.c \
		maths/point.c \
		maths/vector.c \
		maths/ray.c \
		maths/geometry.c 
PARSING = parsing/utils/dispatch_utils.c \
			parsing/utils/parser_utils.c \
			parsing/dispatch.c \
			parsing/parser.c
RENDER = render/exec.c \
			render/set_light.c

FILES = $(SRCS) $(MATHS) $(PARSING) $(RENDER)
OBJS =$(FILES:.c=.o)

LIBFT_DIR = libft
LIBFT =$(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all:$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)

$(NAME):$(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean:clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean

re:fclean all

.PHONY: clean fclean all re

