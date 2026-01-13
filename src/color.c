/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/13 15:11:52 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "maths.h"

t_vec3	hit_color(t_scene *s, t_vec3 direction, t_vec3 center, double radius, double t, int x, int y)
{
	(void)x;
	(void)y;
	t_vec3	n;
	t_vec3	ray_sp;
	t_vec3	ray_sp_final;
	double	c;
	
	ray_sp = power_vector_to_t(direction, t);
	ray_sp_final = add_vector(s->camera.viewpoint, ray_sp);
	ray_sp_final = substract_vector(center, ray_sp_final);
	ray_sp_final = unit_vector(ray_sp_final, radius);
	c = dot_squared(dot(ray_sp_final, ray_sp_final));
	n = unit_vector(ray_sp_final, c);
	n.x = 0.5 * (n.x + 1);
	n.y = 0.5 * (n.y + 1);
	n.z = 0.5 * (n.z + 1);
	// n.x = 1;
	// n.y = 0;
	// n.z = 0;
	return (n);
}

//normalisation position to int to translate color
// -0.1 >> [0,255] 
t_vec3	ray_color(t_scene *s, t_vec3 direction, t_vec3 sp_direction, int x, int y)
{
	// (void)x;
	// (void)y;
	(void)sp_direction;
	t_vec3	unit_direction;
	t_vec3	n;
	double	a;
	double	b;
	double	t;
	
	// t = ray_sphere(s, direction, s->sph1.sp_center, 0, s->sph1.sp_radius, x , y);
	// if (t > 0.0)
	// {
	// 	ray_sp = power_vector_to_t(direction, t);
	// 	ray_sp_final = add_vector(s->camera.viewpoint, ray_sp);
	// 	ray_sp_final = substract_vector(s->sph1.sp_center, ray_sp_final);
	// 	ray_sp_final = unit_vector(ray_sp_final, s->sph1.sp_radius);
	// 	c = dot_squared(dot(ray_sp_final, ray_sp_final));
	// 	n = unit_vector(ray_sp_final, c);
	// 	n.x = 0.5 * (n.x + 1);
	// 	n.y = 0.5 * (n.y + 1);
	// 	n.z = 0.5 * (n.z + 1);
	// 	return (n);
	// }
	t = ray_sphere(s, direction, s->sph1.sp_center, 0, s->sph1.sp_radius, x, y);
	if (t > 0.0)
	{
		n = hit_color(s, direction, s->sph1.sp_center, s->sph1.sp_radius, t, x, y);
		return (n);
	}
	// normalisaton
	b = dot_squared(dot(direction, direction));
	unit_direction = unit_vector(direction, b);
	//gradient blue
	a = 0.5 * (unit_direction.y + 1.0);
	unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
	unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
	unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
	// gradient black
	// unit_direction.x = (1.0 - a) * 1.0 + a * 0.0;
	// unit_direction.y = (1.0 - a) * 1.0 + a * 0.0;
	// unit_direction.z = (1.0 - a) * 1.0 + a * 0.0;
	// black
	// unit_direction.x = 0;
	// unit_direction.y = 0;
	// unit_direction.z = 0;
	return(unit_direction);
}

int	write_color(t_color c, double pixel_color_x, double pixel_color_y, double pixel_color_z)
{
	double auto_r;
	double auto_g;
	double auto_b;
	
	c.r = 0;
	c.g = 0;
	c.b = 0;
	auto_r = pixel_color_x;
	auto_g = pixel_color_y;
	auto_b = pixel_color_z;
	//printf("x %.1f y %.1f z %.1f\n", c.pixel_color.x, c.pixel_color.y, c.pixel_color.z);
	c.r = (int)(255.999 *auto_r);
	c.g = (int)(255.999 *auto_g);
	c.b = (int)(255.999 *auto_b);
	//printf("r %d g %d b %d\n", c.r, c.g, c.b);
	return (0xFF << 24 | c.r << 16 | c.g << 8 | c.b);
}

t_vec3	render_color(t_color c, int x, int y)
{
	double auto_r;
	double auto_g;
	double auto_b;
	
	auto_r = (double)x / (WIDTH - 1);
	auto_g = (double)y / (HEIGHT - 1);
	auto_b = 0.0;
	c.r = (int)(255.999 * auto_r);
	c.g = (int)(255.999 * auto_g);
	c.b = (int)(255.999 * auto_b);
	c.pixel_color.x = (double)c.r;
	c.pixel_color.y = (double)c.g;
	c.pixel_color.z = (double)c.b;
	return (c.pixel_color);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
