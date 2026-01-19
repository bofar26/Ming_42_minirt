/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:24 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/19 16:15:50 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	render_background(t_scene *s, t_vec3 direction)
{
	(void)s;
	t_vec3		unit_direction;
	double		a;
	double		b;

	// normalisaton
    b = dot_squared(dot(direction, direction));
    unit_direction = unit_vector(direction, b);
    //gradient blue
    a = 0.5 * (unit_direction.y + 1.0);
    unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
    unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
    unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
    // gradient black
    // unit_direction.x = (1.0 - a) * 1.0 + a * 0.0;
    // unit_direction.y = (1.0 - a) * 1.0 + a * 0.0;
    // unit_direction.z = (1.0 - a) * 1.0 + a * 0.0;
    // black
    // unit_direction.x = 0;
    // unit_direction.y = 0;
    // unit_direction.z = 0;
    return(unit_direction);
}
