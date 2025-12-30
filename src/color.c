/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/30 22:05:00 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "maths.h"

// int	give_color(t_color *c)
// {
// 	// t = transparency 
// 	// c->t = ((double)c->count / (double)c->max_iteration);
// 	// c->t = 0.1;
// 	c->r = (int)(8 * (1 - c->t) * c->t * c->t * c->t * 255);
// 	c->g = (int)(15 * (1 - c->t) * (1 - c->t) * c->t * c->t * 255);
// 	c->b = (int)(5 * (1 - c->t) * (1 - c->t) * (1 - c->t) * c->t * 255);
// 	c->color = 0xFF << 24 | c->r << 16 | c->g << 8 | c->b;
// 	return (c->color);
// }

//normalisation position to int to translate color
// -0.1 >> [0,255] 
t_vec3	ray_color(t_scene *s, t_vec3 direction)
{
	(void)s;
	t_vec3	unit_direction;
	double a;
	double b;
	
	b = length(length_squared(&direction));
	unit_direction = unit_vector(&direction, b);
	if (ray_sphere(s, &direction, 0, 2))
	{
		direction.x = 1;
		direction.y = 0;
		direction.z = 0;
		return(direction);
	}
	a = 0.5 * (unit_direction.y + 1.0);
	unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
	unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
	unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
	return (unit_direction);
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
