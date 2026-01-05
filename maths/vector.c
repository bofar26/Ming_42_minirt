/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:28:31 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/05 18:34:12 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	add_vector(t_vec3 *v, double x, double y, double z)
{
	x += v->x;
	y += v->y;
	z += v->z;
	return (*v);
}

t_vec3	substract_vector(t_vec3 p, t_vec3 c)
{
	t_vec3	r;
	r.x = c.x - p.x;
	r.y = c.y - p.y;
	r.z = c.z - p.z;
	return (r);
}

t_vec3	power_vector_to_itself(t_vec3 *v)
{
    v->x *= v->x;
    v->y *= v->y;
    v->z *= v->z;
    return (*v);
}

double	length_vector(double start, double finish)
{
    double length;
    
    length = finish - start;
    return (length);
}


