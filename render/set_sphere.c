/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:25:45 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/30 15:44:02 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_sphere(t_sphere *s)
{
	s->sp_center.x = 0.0;
	s->sp_center.y = 0.0;
	s->sp_center.z = -1.0;
	s->sp_color.r = 245;
	s->sp_color.g = 66;
	s->sp_color.b = 233;
	s->sp_diameter = 4;
	s->sp_radius = s->sp_diameter / 2;
}
