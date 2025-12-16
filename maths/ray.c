/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:39:43 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/16 20:29:54 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// b^2 - r^2ac
int	did_it_hit(int i, int j, int k, int r)
{
    int hit;

    hit = 0;
	hit = j * j - ((r * r) * i * k);
	printf("hit = %d\n", hit);
	return (hit);
}

// (bx^2 + by^2 + bz^2)t^2 + (2(axbx + ayby + azbz)t + (ax^2 + ay^2 + az^2 - r^2) = 0
// a = ray origin
// b = ray direction
// r = radius
// t = hit distance
float	ray(t_scene *s, t_point *o, t_vec3 *v, float t, int r, int x, int y)
{
	(void)t;
	(void)s;
	double a;
	double b;
	double c;
	double discriminant;
	
	o->x = 0;
	o->y = 0;
	o->z = 2;
	v->x = x;
	v->y = y;
	v->z = 1;
	// s->pt.c1 = (norm(x, WIDTH, -2, 2) * s->zoom) + s->shift_x;
	// s->pt.c2 = (norm(y, HEIGHT, -2, 2) * s->zoom) + s->shift_y;

	a = v->x * v->x + v->y * v->y + v->z * v->z;
	b = 2 * (o->x * v->x + o->y * v->y + o->z * v->z);
	c = (o->x * o->x + o->y * o->y + o->z * o->z) - r * r;
	discriminant = did_it_hit(a, b, c, r);
	if (discriminant >= 0.0)
		return (give_color(245, 66, 233));
	else
		return(TRGB_BLACK);
}


// a = o->x + v->x * t;
// b = o->y + v->y * t;