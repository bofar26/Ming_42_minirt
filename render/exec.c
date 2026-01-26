/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:18 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	sample_random_pixel(t_camera c, t_rand *r)
{
	*r = seed_kiss_no_power(r);
	c.offset.x = random_double(seed(r) - 0.5);
	*r = seed_kiss_no_power(r);
	c.offset.y = random_double(seed(r) - 0.5);
	c.offset.z = 0.0;
	return (c.offset);
}

t_camera	normalize_viewport(t_camera c, int i, int j)
{
	c.pixel_center.x = c.pixel00_loc.x + ((i + c.offset.x) * c.pixel_delta_u.x) + ((j + c.offset.y) * c.pixel_delta_v.x);
	c.pixel_center.y = c.pixel00_loc.y + ((i + c.offset.x) * c.pixel_delta_u.y) + ((j + c.offset.y) * c.pixel_delta_v.y);
	c.pixel_center.z = c.pixel00_loc.z + (i * c.pixel_delta_u.z) + (j * c.pixel_delta_v.z);
	c.orientation.x = c.pixel_center.x - c.viewpoint.x;
	c.orientation.y = c.pixel_center.y - c.viewpoint.y;
	c.orientation.z = c.pixel_center.z - c.viewpoint.z;
	return (c);
}
t_vec3	get_ray(t_scene *s, t_rand	*r, t_vec3 ray_sult, int x, int y)
{
	t_vec3		ray_background;
	t_vec3		temp;
	t_vec3		ray_final;
	t_camera	c;
	t_sphere	*sp1;
	
	c = s->camera;
	sp1 = s->spheres->content;
	temp = (t_vec3){0,0,0};
	ray_final = (t_vec3){0,0,0};
	c.offset = sample_random_pixel(c, r);
	c = normalize_viewport(c, x, y);
	ray_background = c.orientation;
	temp = ray_color(s, ray_background, x, y);
	ray_final = add_vector(ray_sult, temp);
	ray_sult = ray_final;
	s->camera = c;
	return (ray_final);
}
	
void	fill_frame(t_scene *s)
{
	int 	x;
	int 	y;
	int		i;
	t_color	color_sc;
	t_color	new_color_sc;
	t_rand	r;
	t_vec3	ray_sult;


	y = 0;
	ft_memset(&r, 0, sizeof(t_rand));
	r = init_seed(r);
	ray_sult = (t_vec3){0,0,0};
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = 0;
			color_sc.pixel_color = (t_vec3){0,0,0};
			while (i < s->sample_per_pixel)
			{
				new_color_sc.pixel_color = (t_vec3){0,0,0};
				new_color_sc.pixel_color = get_ray(s, &r, ray_sult, x, y);
				color_sc.pixel_color = add_vector(color_sc.pixel_color, new_color_sc.pixel_color);
				i++;
			}
			color_sc.pixel_color = power_vector_to_t(color_sc.pixel_color, s->pixel_sample_scale);
			image_pixel_put(s, x, y ,write_color(color_sc, color_sc.pixel_color.x, color_sc.pixel_color.y, color_sc.pixel_color.z));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (s->mlx_ptr, s->win_ptr, \
		s->img_ptr, 0, 0);
	s->render_time = getexacttimeofday() - s->time;
	printf("render time : %.3lf\n", s->render_time);
}

void	renderer(t_scene *w_d)
{
	t_camera c;
	t_sphere *sp1;

	c = w_d->camera;
	sp1 = (t_sphere *)w_d->spheres->content;
	c = set_camera(c);
	w_d->camera = c;
	fill_frame(w_d);
}

