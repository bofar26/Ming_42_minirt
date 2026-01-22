/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/20 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	cylinder_side_root(t_scene *s, t_vec3 direction, t_vec3 axis,
	t_vec3 oc, double t, double half_h, t_vec3 *n)
{
	t_vec3	p;
	t_vec3	normal;
	double	y;
	double	len;

	if (t <= s->ray_min || t >= s->ray_max)
		return (-1.0);
	y = dot(oc, axis) + dot(direction, axis) * t;
	if (fabs(y) > half_h)
		return (-1.0);
	if (n)
	{
		p = add_vector(oc, power_vector_to_t(direction, t));
		normal = substract_vector(power_vector_to_t(axis, dot(p, axis)), p);
		len = dot_squared(dot(normal, normal));
		if (len == 0.0)
			return (-1.0);
		normal = unit_vector(normal, len);
		*n = normal;
	}
	return (t);
}

static void	update_hit(double t, t_vec3 hit_n, double *best, t_vec3 *n)
{
	if (t > 0.0 && (*best < 0.0 || t < *best))
	{
		*best = t;
		if (n)
			*n = hit_n;
	}
}

static double	cylinder_side(t_scene *s, t_vec3 direction, t_vec3 axis,
	t_vec3 oc, double radius, double half_h, t_vec3 *n)
{
	t_vec3	d_perp, oc_perp, tmp_n;
	double	a, b, c, disc, best, t;

	d_perp = substract_vector(power_vector_to_t(axis, dot(direction, axis)),
			direction);
	oc_perp = substract_vector(power_vector_to_t(axis, dot(oc, axis)), oc);
	a = dot(d_perp, d_perp);
	b = 2.0 * dot(d_perp, oc_perp);
	c = dot(oc_perp, oc_perp) - (radius * radius);
	disc = b * b - 4.0 * a * c;
	if (fabs(a) < 1e-6 || disc < 0.0)
		return (-1.0);
	best = -1.0;
	t = (-b - sqrt(disc)) / (2.0 * a);
	update_hit(cylinder_side_root(s, direction, axis, oc, t, half_h, &tmp_n),
		tmp_n, &best, n);
	t = (-b + sqrt(disc)) / (2.0 * a);
	update_hit(cylinder_side_root(s, direction, axis, oc, t, half_h, &tmp_n),
		tmp_n, &best, n);
	return (best);
}

static double	cylinder_cap(t_scene *s, t_vec3 direction, t_vec3 axis,
	t_vec3 oc, double radius, double half_h, double sign, t_vec3 *n)
{
	const double	eps = 1e-6;
	t_vec3			p, p_perp;
	double			d_dot_v, oc_dot_v, t, dist2;

	d_dot_v = dot(direction, axis);
	if (fabs(d_dot_v) < eps)
		return (-1.0);
	oc_dot_v = dot(oc, axis);
	t = (sign * half_h - oc_dot_v) / d_dot_v;
	if (t <= s->ray_min || t >= s->ray_max)
		return (-1.0);
	p = add_vector(oc, power_vector_to_t(direction, t));
	p_perp = substract_vector(power_vector_to_t(axis, dot(p, axis)), p);
	dist2 = dot(p_perp, p_perp);
	if (dist2 > radius * radius)
		return (-1.0);
	if (n)
		*n = power_vector_to_t(axis, sign);
	return (t);
}

double	ray_cylinder(t_scene *s, t_vec3 direction, t_cylinder *cy, t_vec3 *n)
{
	t_vec3	axis, oc, tmp_n;
	double	len, radius, half_h, best;

	axis = cy->cy_vector;
	len = dot_squared(dot(axis, axis));
	if (len == 0.0)
		return (-1.0);
	axis = unit_vector(axis, len);
	radius = cy->cy_diameter * 0.5;
	half_h = cy->cy_height * 0.5;
	oc = substract_vector(cy->cy_center, s->camera.viewpoint);
	best = -1.0;
	update_hit(cylinder_side(s, direction, axis, oc, radius, half_h, &tmp_n),
		tmp_n, &best, n);
	update_hit(cylinder_cap(s, direction, axis, oc, radius, half_h, 1.0, &tmp_n),
		tmp_n, &best, n);
	update_hit(cylinder_cap(s, direction, axis, oc, radius, half_h, -1.0, &tmp_n),
		tmp_n, &best, n);
	return (best);
}
