/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:39:43 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/15 21:15:22 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//calcul quadrature to know if the ray hit the object or not
// b^2 - r^2ac
int	did_it_hit(int i, int j, int k)
{
    int hit;

    hit = 0;
	hit = j * j - (i * k);
	// printf("hit = %d\n", hit);
	return (hit);
}

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
	s->a = 0.0;
	s->b = 0.0;
	s->c = 0.0;
	s->discriminant = 0.0;
	oc = substract_vector(s->camera.viewpoint, center);
	s->a = dot(direction, direction);
	s->b = dot(oc, direction);
	s->c = (dot(oc, oc)) - (r * r);
	s->discriminant = s->b * s->b - (s->a * s->c);
	if (s->discriminant < 0.0)
		return (-1.0);
	t = (s->b + sqrt(s->discriminant)) / (s->a);
	if (t <= s->ray_min || t >= s->ray_max)
	{
		t = (s->b - sqrt(s->discriminant)) / (s->a);
		if (t <= s->ray_min || t >= s->ray_max)
			return (-1.0);
		*n = calculate_normal(s, direction, center, r, t, x, y);
		return (t);
	}
	else
	{
		*n = calculate_normal(s, direction, center, r, t, x, y);
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

// float	ray_sphere(t_scene *s, float t, int r, int x, int y)
// {
// 	(void)t;
// 	(void)x;
// 	(void)y;
// 	double a;
// 	double b;
// 	double c;
// 	double discriminant;
	
// 	// s->camera.viewpoint.x = 0;
// 	// s->camera.viewpoint.y = 0;
// 	// s->camera.viewpoint.z = 2;
// 	// s->camera.orientation.x = ;
// 	// s->camera.orientation.y = ;
// 	// s->camera.orientation.z = 1;

// 	a = s->camera.orientation.x * s->camera.orientation.x + s->camera.orientation.y \
// 	* s->camera.orientation.y + s->camera.orientation.z * s->camera.orientation.z;
// 	b = 2 * (s->camera.viewpoint.x * s->camera.orientation.x + s->camera.viewpoint.y \
// 		* s->camera.orientation.y + s->camera.viewpoint.z * s->camera.orientation.z);
// 	c = (s->camera.viewpoint.x * s->camera.viewpoint.x + s->camera.viewpoint.y \
// 		* s->camera.viewpoint.y + s->camera.viewpoint.z * s->camera.viewpoint.z) - r * r;
// 	discriminant = did_it_hit(a, b, c);
// 	if (discriminant >= 0.0)
// 		return (give_color(245, 66, 233));
// 	// else
// 	// 	return(TRGB_BLACK);
// }