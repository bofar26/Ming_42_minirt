/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:39:43 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/30 22:17:29 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//calcul quadrature to know if the ray hit the object or not
// b^2 - r^2ac
int	did_it_hit(int i, int j, int k, int r)
{
	(void)r;
    int hit;

    hit = 0;
	hit = j * j - (4 * i * k);
	//printf("hit = %d\n", hit);
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
bool	ray_sphere(t_scene *s, t_vec3 *direction, float t, int r)
{
	(void)t;
	(void)direction;
	t_vec3 oc;
	double a;
	double b;
	double c;
	// double d;
	double discriminant;
	
	a = 0.0;
	oc = substract_vector(&s->camera.viewpoint, &s->sphere.sp_center);
	// d = length(length_squared(&oc));
	// oc = unit_vector(&oc, d);
	a = length_squared(direction);
	b = 2 * (oc.x * direction->x + oc.y * direction->y + oc.z * direction->z);
	c = (length_squared(&oc)) - r * r;
	printf("a %.1f, b %.1f, c %.1f\n", a, b, c);
	discriminant = did_it_hit(a, b, c, r);
	return (discriminant >= 0.0);
}

//fct ray :
//P(t) = a + tb; 
// a = o->x + v->x * t;
// b = o->y + v->y * t;
t_vec3	ray(t_vec3 *origin, t_vec3 *direction, double t)
{
	t_vec3	ray_final;

	ray_final.x = origin->x + t * direction->x;
	ray_final.y = origin->y + t * direction->y;
	ray_final.z = origin->z + t * direction->z;
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
// 	discriminant = did_it_hit(a, b, c, r);
// 	if (discriminant >= 0.0)
// 		return (give_color(245, 66, 233));
// 	// else
// 	// 	return(TRGB_BLACK);
// }