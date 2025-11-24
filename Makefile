# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipang <mipang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2025/11/24 22:36:34 by mipang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -Iminilibx
SRCS = src/main.c

OBJS =$(SRCS:.c=.o)

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

