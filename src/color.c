/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 16:59:54 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "maths.h"

//assign color to pixel depending on their posistion on the screen
t_vec3	ray_color(t_scene *s, t_vec3 direction)
{
	t_vec3		n;
	t_vec3		p;
	t_vec3		unit_direction;
	t_vec3		ray_final;
	t_sphere	*sp1;
	t_list		*temp;
	double		t;
	
	t = 0.0;
	temp = s->spheres;
	s->closest_so_far = s->ray_max;
	while (temp)
	{
		sp1 = temp->content;
		t = ray_sphere(s, direction, sp1->sp_center, sp1->sp_radius);
		if (t > 0.0 && t < s->closest_so_far)
		{
			p = calculate_impact_point_sphere(s, direction, sp1->sp_center, sp1->sp_radius, t);
			n = calculate_normal(s, direction, p);
			s->closest_so_far = t;
			s->closest_object = sp1->sp_color;
		}
		temp = temp->next;
	}
	if (s->closest_so_far < s->ray_max)
	{	
		ray_final = calculate_light(s, n, p);
		return (ray_final);
	}
	unit_direction = render_background(s, direction);
	return(unit_direction);
}
 
//normalisation position to int to translate color
// -0.1 >> [0,255] 
int	write_color(t_color c, double pixel_color_x, double pixel_color_y, double pixel_color_z)
{
	double	auto_r;
	double	auto_g;
	double	auto_b;
	double	min;
	double	max;
	
	c.r = 0;
	c.g = 0;
	c.b = 0;
	min = 0.000;
	max = 0.999;
	auto_r = pixel_color_x;
	auto_g = pixel_color_y;
	auto_b = pixel_color_z;
	c.r = (int)(255.999 * clamp(min, max, auto_r));
	c.g = (int)(255.999 * clamp(min, max, auto_g));
	c.b = (int)(255.999 * clamp(min, max, auto_b));
	return (0xFF << 24 | c.r << 16 | c.g << 8 | c.b);
}

// take original color in int [0,255] translate them in double
// assign them to a position (x,y,z)
t_vec3	render_color(t_color c)
{
	double auto_r;	
	double auto_g;
	double auto_b;
	
	auto_r = 0.0;
	auto_g = 0.0;
	auto_b = 0.0;
	auto_r = (int)(c.r) / 255.999;
	auto_g = (int)(c.g) / 255.999;
	auto_b = (int)(c.b) / 255.999;
	c.pixel_color.x = (double)auto_r;
	c.pixel_color.y = (double)auto_g;
	c.pixel_color.z = (double)auto_b;
	return (c.pixel_color);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
