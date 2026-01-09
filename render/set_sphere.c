/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:25:45 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/09 16:27:19 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	set_sphere(t_sphere sp)
{
	sp.sp_center.x = 0.0;
	sp.sp_center.y = 0.0;
	sp.sp_center.z = 10.0;
	sp.sp_color.r = 245;
	sp.sp_color.g = 66;
	sp.sp_color.b = 233;
	sp.sp_diameter = 1;
	sp.sp_radius = sp.sp_diameter / 2;
	return (sp);
}
