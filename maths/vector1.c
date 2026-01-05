/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:24:32 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/05 18:23:49 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//fcts to normalize 
double	dot_squared(double a)
{
	a = sqrtf(a);
	return (a);
}

double	dot(t_vec3 v)
{
	double a;

	a = v.x * v.x + v.y * v.y + v.z * v.z;
	return (a);
}

t_vec3	unit_vector(t_vec3 v, double a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	return (v);
}
