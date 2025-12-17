/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:31:37 by leazannis         #+#    #+#             */
/*   Updated: 2025/12/17 17:23:48 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

/* void	key_hook_color(int key_sym, t_scene *s)
{
	if (key_sym == XK_Return)
	{
		s->new_color = 0;
		write (1, "Here is a list of the different keys ", 38);
		write (1, "and there effects : Enter : RESET COLORS, ", 43);
		write (1, "R, G, B, T, Y, U, P, H, N : SHIFT COLORS", 41);
	}
	else if (key_sym == XK_b)
		s->new_color = 1;
	else if (key_sym == XK_t)
		s->new_color = 2;
	else if (key_sym == XK_r)
		s->new_color = 3;
	else if (key_sym == XK_g)
		s->new_color = 4;
	else if (key_sym == XK_n)
		s->new_color = 5;
	else if (key_sym == XK_u)
		s->new_color = 6;
	else if (key_sym == XK_p)
		s->new_color = 7;
	else if (key_sym == XK_y)
		s->new_color = 8;
	else if (key_sym == XK_h)
		s->new_color = 9;
} */

/* void	key_up_left_right_down(int key_sym, t_scene *s)
{
	if (key_sym == XK_Up)
	{
		if (s->name.fractal == 2)
		s->shift_y += 0.5 * s->zoom;
		else
		s->shift_y -= 0.5 * s->zoom;
	}
	else if (key_sym == XK_Left)
	{
		s->shift_x -= 0.5 * s->zoom;
	}
	else if (key_sym == XK_Right)
		s->shift_x += 0.5 * s->zoom;
	else if (key_sym == XK_Down)
	{
		if (s->name.fractal == 2)
			s->shift_y -= 0.5 * s->zoom;
		else
			s->shift_y += 0.5 * s->zoom;
	}
} */

int	mouse_hook(int button, int x, int y, t_scene *s)
{
	(void)x;
	(void)y;
	//s->pos.px = (norm(x, WIDTH, -2, 2));
	//s->pos.py = (norm(y, HEIGHT, 2, -2));
	//s->pos.px = (s->pos.resx * s->zoom) + s->shift_x;
	//s->pos.py = (s->pos.resy * s->zoom) + s->shift_y;
	if (button == 4)
		s->zoom *= 0.85;
	if (button == 5)
		s->zoom *= 1.15;
	if (button == 1)
		s->zoom *= 0.5;
	if (button == 3)
		s->zoom *= 2.5;
	fill_frame(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, \
		s->img_ptr, 0, 0);
	return (0);
}
