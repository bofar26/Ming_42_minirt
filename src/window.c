/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:03:24 by leazannis         #+#    #+#             */
/*   Updated: 2025/12/30 21:10:58 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_key_move(int keycode, t_scene *s)
{
	if (keycode == XK_Escape)
		close_win(s);
	return (0);
}

bool	create_window(t_scene *s)
{
	s->mlx_ptr = 0;
	s->mlx_ptr = mlx_init();
	if (!s->mlx_ptr)
	{
		free(s->mlx_ptr);
		return (false);
	}
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIDTH, HEIGHT, "minirt");
	if (!s->win_ptr)
		return (false);
	s->img_ptr = mlx_new_image(s->mlx_ptr, WIDTH, HEIGHT);
	if (!s->img_ptr)
		return (false);
	s->address = mlx_get_data_addr(s->img_ptr, \
		&s->bits_per_pixel, &s->size_line, &s->endian);
	if (!s->address)
		return (false);
    return (true);
}

void	draw_image(t_scene *w_d, t_line *line, t_rect *rect)
{
	renderer(w_d, line, rect);
	mlx_put_image_to_window (w_d->mlx_ptr, w_d->win_ptr, \
		w_d->img_ptr, 0, 0);
	mlx_hook(w_d->win_ptr, 2, 1L << 0, handle_key_move, w_d);
	mlx_mouse_hook(w_d->win_ptr, mouse_hook, w_d);
	mlx_hook(w_d->win_ptr, 17, 0, close_win, w_d);
	mlx_loop(w_d->mlx_ptr);
}

void	image_pixel_put(t_scene *img, int x, int y, int color)
{
	char	*dst;

	if ((x > WIDTH) || (y > HEIGHT))
		return ;
	dst = img->address + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_frame(t_scene *s, t_point3 *o, t_vec3 *v)
{
	(void)o;
	(void)v;
	int 	x;
	int 	y;
	t_vec3	final_ray;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// to render whole window
			// image_pixel_put(s, x, y, give_color(245, 66, 233));
			//coordonate of pixel to print
            // image_pixel_put(s, 400, 300, TRGB_BLUE);
			//image_pixel_put(s, x, y, ray(s, 0.6, 2, x, y));
			//image_pixel_put(s, x, y, render_color(s->ambient.ambient_color, x, y));
			// printf("before x %.1f y %.1f z %.1f\n",s->camera.orientation.x, s->camera.orientation.y, s->camera.orientation.z);
			render_background(&s->camera, x, y);
			// printf(" after x %.1f y %.1f z %.1f\n",s->camera.orientation.x, s->camera.orientation.y, s->camera.orientation.z);
			final_ray = ray(&s->camera.viewpoint, &s->camera.orientation, s->ambient.ratio);
			s->ambient.ambient_color.pixel_color = ray_color(s, final_ray);
			image_pixel_put(s, x, y ,write_color(s->ambient.ambient_color, s->ambient.ambient_color.pixel_color.x, s->ambient.ambient_color.pixel_color.y, s->ambient.ambient_color.pixel_color.z));
			// s->ambient.ambient_color.pixel_color = render_color(s->ambient.ambient_color, x, y);
			// s->ambient.ambient_color.pixel_color.z = 0;
			// image_pixel_put(s, x, y ,write_color(s->ambient.ambient_color, s->ambient.ambient_color.pixel_color.x, s->ambient.ambient_color.pixel_color.y, s->ambient.ambient_color.pixel_color.z));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (s->mlx_ptr, s->win_ptr, \
		s->img_ptr, 0, 0);
	s->render_time = getexacttimeofday() - s->time;
	printf("render time : %.3lf\n", s->render_time);
}
