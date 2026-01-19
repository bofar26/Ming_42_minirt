/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/18 17:23:58 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "maths.h"

//assign color to pixel depending on their posistion on the screen
t_vec3	ray_color(t_scene *s, t_vec3 direction, int x, int y)
{
	// (void)x;
	// (void)y;
	t_vec3		n;
	t_vec3		unit_direction;
	// t_vec3		unit_dir_l;
	t_sphere	*sp1;
	t_list		*temp;
	t_light		l;
	double		a;
	double		b;
	double		t;
	
	a = 0.0;
	b = 0.0;
	t = 0.0;
	l = s->light;
	temp = s->spheres;
	s->closest_so_far = s->ray_max;
	while (temp)
	{
		sp1 = temp->content;
		t = ray_sphere(s, direction, sp1->sp_center, sp1->sp_radius, &n, x, y);
		if (t > 0.0 && t < s->closest_so_far)
		{
			s->closest_so_far = t;
			s->closest_object = sp1->sp_color;
		}
		temp = temp->next;
	}
	if (s->closest_so_far < s->ray_max)
	{	
		n = render_color(s->closest_object, x, y);
		// n.x = 0.5 * (n.x + 1);
		// n.y = 0.5 * (n.y + 1);
		// n.z = 0.5 * (n.z + 1);
		// b = dot_squared(dot(l.pos, l.pos));
		// unit_dir_l = unit_vector(l.pos, b);
		// unit_dir_l = power_vector_to_t(unit_dir_l, -1);
		// a = fmax(dot(unit_dir_l, n), 0.0);// == cos(angle)
		// n.x = n.x * a;
		// n.y = n.y * a;
		// n.z = n.z * a;
		return (n);
	}
	unit_direction = render_background(s, direction);
	return(unit_direction);
}

//normalisation position to int to translate color
// -0.1 >> [0,255] 
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
// take original color in int [0,255] translate them in double
// assign them to a position (x,y,z)
t_vec3	render_color(t_color c, int x, int y)
{
	(void)x;
	(void)y;
	double auto_r;	
	double auto_g;
	double auto_b;
	
	auto_r = 0.0;
	auto_g = 0.0;
	auto_b = 0.0;
	auto_r = (int)(255.999 * c.r) / 50000;
	auto_g = (int)(255.999 * c.g) / 50000;
	auto_b = (int)(255.999 * c.b) / 50000;
	c.pixel_color.x = (double)auto_r;
	c.pixel_color.y = (double)auto_g;
	c.pixel_color.z = (double)auto_b;
	return (c.pixel_color);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
