/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:30:05 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/17 17:23:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
#include "minirt.h"

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct t_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct t_ray
{
	t_point		o;
	t_vector	d;
	float		time;
	char		*medium;
	char		*material;
}	t_ray;

//-----POINT-----

int	pos(t_point *p);
int	new_pos_add(t_point *p);
int	new_pos_substract(t_point *p);

//-----VECTOR------

int	vector(t_vector *v);
int	add_vector(t_vector *v);
int	substract_vector(t_vector *v);
int	qlength_vector(int start, int finish, t_point *p);

#endif
