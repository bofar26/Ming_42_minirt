/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:26:21 by mipang            #+#    #+#             */
/*   Updated: 2025/12/29 21:12:45 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT 600
# define KEY_ESC 65307
# define PI 3.14

// define color
# define TRGB_BLACK  0x00000000
# define TRGB_TRANSPARENT  0xFF000000
# define TRGB_RED  0x00FF0000
# define TRGB_GREEN  0x0000FF00
# define TRGB_BLUE  0x000000FF
# define TRGB_WHITE  0xFFFFFFFF

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "scene.h"
# include "parsing.h"
# include "types.h"
# include "maths.h"
# include "render.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <X11/keysym.h>
# include <sys/time.h>

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
// void	draw_image(t_scene *w_d);
void	draw_image(t_scene *w_d, t_line *line, t_rect *rect);
void	image_pixel_put(t_scene *img, int x, int y, int color);
void	fill_frame(t_scene *s, t_point3 *o, t_vec3 *v);

//-----KEY_HOOK-----

//void	key_hook_color(int key_sym, t_scene *w_d);
//void	key_up_left_right_down(int key_sym, t_scene *w_d);w
int		mouse_hook(int button, int x, int y, t_scene *s);

//-----COLOR-----

t_vec3	ray_color(t_vec3 direction);
int		write_color(t_color c, double pixel_color_x, double pixel_color_y, double pixel_color_z);
t_vec3	render_color(t_color c, int x, int y);
int		give_color(int r, int g, int b);

//-----TIME-----

int		getexacttimeofday(void);

#endif
