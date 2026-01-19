/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:39:43 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/18 21:05:54 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// determinate if the ray is facing front face or not
bool	is_front_face(t_vec3 direction,t_vec3 normal)
{
	double	a;
	
	a = 0.0;
	a = dot(direction, normal);
	if (a > 0.0)
		return (false);
	else
		return (true);
}

//normal = vector perpendicular to a surface 
t_vec3	calculate_normal_sphere(t_scene *s, t_vec3 direction, t_vec3 center, double radius, double t, int x, int y)
{
	(void)x;
	(void)y;
	(void)radius;
	t_vec3	n;
	t_vec3	ray_sp;
	t_vec3	ray_sp_final;
	double	c;
	
	c = 0.0;
	ray_sp = power_vector_to_t(direction, t);
	ray_sp_final = add_vector(s->camera.viewpoint, ray_sp);
	ray_sp_final = substract_vector(center, ray_sp_final);
	ray_sp_final = unit_vector(ray_sp_final, radius);
	c = dot(ray_sp_final, ray_sp_final);
	c = dot_squared(c);
	n = unit_vector(ray_sp_final, c);
	if (!is_front_face(direction, n))
	{
		n = unit_vector(n, -1);
		return (n);
	}
	return (n);
}

//calcul quadrature to know if the ray hit the object or not
// b^2 - r^2ac
//calcul to know if the ray hit the sphere:
// x^2 + y^2 + z^2 + = r^2 >> point is on the surface of the sphere
// x^2 + y^2 + z^2 + < r^2 >> point is inside the sphere
// x^2 + y^2 + z^2 + > r^2 >> point is outside the sphere
// (bx^2 + by^2 + bz^2)t^2 + (2(axbx + ayby + azbz)t + (ax^2 + ay^2 + az^2 - r^2) = 0
// a = ray origin
// b = ray direction
// r = radius
// t = hit distance
double	ray_sphere(t_scene *s, t_vec3 direction, t_vec3 center, double r, t_vec3 *n, int x, int y)
{
	(void)x;
	(void)y;
	t_vec3	oc;
	double t;

	t = 0.0;
	oc = substract_vector(s->camera.viewpoint, center);
	s->a = dot(direction, direction);
	s->b = dot(oc, direction);
	s->c = (dot(oc, oc)) - (r * r);
	s->discriminant = s->b * s->b - (s->a * s->c);
	if (s->discriminant < 0.0)
		return (-1.0);
	t = (s->b - sqrt(s->discriminant)) / (s->a);
	if (t <= s->ray_min || t >= s->ray_max)
	{
		t = (s->b + sqrt(s->discriminant)) / (s->a);
		if (t <= s->ray_min || t >= s->ray_max)
			return (-1.0);
		*n = calculate_normal_sphere(s, direction, center, r, t, x, y);
		return (t);
	}
	else
	{
		*n = calculate_normal_sphere(s, direction, center, r, t, x, y);
		return (t);
	}
}

//fct ray :
//P(t) = a + tb;
// a = o->x + v->x * t;
// b = o->y + v->y * t;
t_vec3	ray(t_vec3 origin, t_vec3 direction)
{
	t_vec3	ray_final;

	ray_final.x = origin.x + direction.x;
	ray_final.y = origin.y + direction.y;
	ray_final.z = origin.z + direction.z;
	// printf("x  %.1f y %.1f z %.1f\n", ray_final.x, ray_final.y, ray_final.z);
	return (ray_final);
}
