/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:24:32 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/06 13:59:03 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//fcts to normalize 
double	dot_squared(double a)
{
	a = sqrtf(a);
	return (a);
}

double	dot(t_vec3 v, t_vec3 u)
{
	double a;

	a = v.x * u.x + v.y * u.y + v.z * u.z;
	return (a);
}

t_vec3	unit_vector(t_vec3 v, double a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	return (v);
}
