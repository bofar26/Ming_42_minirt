/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/25 21:31:00 by lzannis          ###   ########.fr       */
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
	t_vec3		p;
	t_vec3		unit_direction;
	t_vec3		unit_dir_l;
	t_vec3		ray_light;
	t_vec3		ray_color;
	t_vec3		ray_final;
	t_vec3		ambient_light;
	t_sphere	*sp1;
	t_list		*temp;
	t_light		l;
	t_ambient	am;
	double		a;
	double		intensity;
	double		t;
	
	a = 0.0;
	intensity = 0.0;
	t = 0.0;
	l = s->light;
	am = s->ambient;
	temp = s->spheres;
	s->closest_so_far = s->ray_max;
	// unit_dir_l = (t_vec3){0,0,0};
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
		// n = render_color(s->closest_object, x, y);
		// return (n);
		unit_dir_l = substract_vector(p,l.pos);
		// unit_dir_l = unit_vector(unit_dir_l, -1.0);
		unit_dir_l = power_vector_to_t(unit_dir_l, -1.0);
		a = clamp(0.0, dot(unit_dir_l, n), dot(unit_dir_l, n));// == cos(angle)
		intensity = a * l.ratio;
		ray_light = render_color(l.light_color, x, y);
		ray_light = power_vector_to_t(ray_light, intensity);
		ray_color = render_color(s->closest_object, x, y);
		ambient_light = render_color(am.ambient_color, x, y);
		ambient_light = power_vector_to_t(ambient_light, am.ratio);
		ray_final.x = (ambient_light.x + ray_light.x) * ray_color.x;
		ray_final.y = (ambient_light.y + ray_light.y) * ray_color.y;
		ray_final.z = (ambient_light.z + ray_light.z) * ray_color.z;
		s->light = l;
		s->ambient = am;
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
	auto_r = (int)(255.999 * c.r) / 40000;
	auto_g = (int)(255.999 * c.g) / 40000;
	auto_b = (int)(255.999 * c.b) / 40000;
	c.pixel_color.x = (double)auto_r;
	c.pixel_color.y = (double)auto_g;
	c.pixel_color.z = (double)auto_b;
	return (c.pixel_color);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
