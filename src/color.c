/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/24 12:24:43 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	printf("x %.1f y %.1f z %.1f\n", c.pixel_color.x, c.pixel_color.y, c.pixel_color.z);
	c.r = (int)(auto_r);
	c.g = (int)(auto_g);
	c.b = (int)(auto_b);
	printf("r %d g %d b %d\n", c.r, c.g, c.b);
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
