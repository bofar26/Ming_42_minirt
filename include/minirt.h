/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:26:21 by mipang            #+#    #+#             */
/*   Updated: 2025/11/29 12:13:50 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINI_RT_H
#define MINI_RT_H

#define WIDTH 800
#define HEIGHT 600
#define KEY_ESC 65307

// define color
# define TRGB_BLACK  0x00000000
# define TRGB_TRANSPARENT  0xFF000000
# define TRGB_RED  0x00FF0000
# define TRGB_GREEN  0x0000FF00
# define TRGB_BLUE  0x000000FF
# define TRGB_WHITE  0xFFFFFFFF

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
# include <X11/keysym.h>

typedef struct t_scene
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image_ptr;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		color;
}	t_scene;

typedef struct s_atof
{
	double	nbr;
	int		nb;
	int		sign;
	int		len;
	int		i;
}	t_atof;

//-----ATOF-----

double	ft_atof(char *str);

//----CLOSE-----

int		handle_exit(void *param, t_scene *s);
int		close_win(t_scene *w_d);

//-----WINDOW-----

int		handle_key_move(int keycode, t_scene *s);
bool	create_window(t_scene *s);
void	draw_image(t_scene *w_d);
void	image_pixel_put(t_scene *img, int x, int y, int color);
void	fill_frame(t_scene *s);

//-----KEY_HOOK-----

//void	key_hook_color(int key_sym, t_scene *w_d);
//void	key_up_left_right_down(int key_sym, t_scene *w_d);w
int		mouse_hook(int button, int x, int y, t_scene *w_d);

#endif
