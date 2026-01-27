/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:24 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 17:01:13 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	render_background(t_scene *s, t_vec3 direction)
{
	t_vec3	unit_direction;
	double	a;
	double	b;

	(void)s;
	b = dot_squared(dot(direction, direction));
	unit_direction = unit_vector(direction, b);
	a = 0.5 * (unit_direction.y + 1.0);
	unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
	unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
	unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
	return (unit_direction);
}

static double	diffuse_intensity(t_vec3 n, t_vec3 p, t_light l)
{
	t_vec3	dir_l;
	double	len;
	double	a;

	dir_l = substract_vector(l.pos, p);
	len = dot_squared(dot(dir_l, dir_l));
	if (len > 0.0)
		dir_l = unit_vector(dir_l, len);
	n = normalize_vec3(n);
	a = dot(dir_l, n);
	if (a < 0.0)
		a = 0.0;
	return (a * l.ratio);
}

static bool	hit_any_object(t_scene *s, t_vec3 direction, double max_t)
{
	t_list		*temp;
	t_vec3		n;
	double		t;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	temp = s->spheres;
	while (temp)
	{
		sp = temp->content;
		t = ray_sphere(s, direction, sp, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	temp = s->planes;
	while (temp)
	{
		pl = temp->content;
		t = ray_plane(s, direction, pl, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	temp = s->cylinders;
	while (temp)
	{
		cy = temp->content;
		t = ray_cylinder(s, direction, cy, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static bool	is_shadowed(t_scene *s, t_vec3 p, t_vec3 n)
{
	t_vec3		to_light;
	t_vec3		origin;
	t_vec3		old_origin;
	double		old_min;
	double		old_max;
	double		dist2;
	double		dist;
	bool		shadow;
	double		n_dot_l;
	const double	bias = 1e-3;

	to_light = substract_vector(s->light.pos, p);
	dist2 = dot(to_light, to_light);
	if (dist2 <= 0.0)
		return (false);
	dist = sqrt(dist2);
	n = normalize_vec3(n);
	n_dot_l = dot(n, to_light);
	if (n_dot_l < 0.0)
		n = power_vector_to_t(n, -1.0);
	origin = add_vector(p, power_vector_to_t(n, bias));
	old_origin = s->camera.viewpoint;
	old_min = s->ray_min;
	old_max = s->ray_max;
	s->camera.viewpoint = origin;
	s->ray_min = bias;
	s->ray_max = dist - bias;
	if (s->ray_max <= s->ray_min)
		shadow = false;
	else
	{
		to_light = unit_vector(to_light, dist2);
		shadow = hit_any_object(s, to_light, s->ray_max);
	}
	s->camera.viewpoint = old_origin;
	s->ray_min = old_min;
	s->ray_max = old_max;
	return (shadow);
}

static t_vec3	combine_light(t_scene *s, double intensity)
{
	t_vec3	ray_light;
	t_vec3	ray_color;
	t_vec3	ambient_light;
	t_vec3	out;

	ray_light = render_color(s->light.light_color);
	ray_light = power_vector_to_t(ray_light, intensity);
	ray_color = render_color(s->closest_object);
	ambient_light = render_color(s->ambient.ambient_color);
	ambient_light = power_vector_to_t(ambient_light, s->ambient.ratio);
	out.x = (ambient_light.x + ray_light.x) * ray_color.x;
	out.y = (ambient_light.y + ray_light.y) * ray_color.y;
	out.z = (ambient_light.z + ray_light.z) * ray_color.z;
	out.x = clamp(0.0, 1.0, out.x);
	out.y = clamp(0.0, 1.0, out.y);
	out.z = clamp(0.0, 1.0, out.z);
	return (out);
}

t_vec3	calculate_light(t_scene *s, t_vec3 n, t_vec3 p)
{
	double	intensity;

	intensity = diffuse_intensity(n, p, s->light);
	if (is_shadowed(s, p, n))
		intensity = 0.0;
	return (combine_light(s, intensity));
}
