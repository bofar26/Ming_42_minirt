/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:25:45 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/13 17:38:38 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	set_sph1(t_sphere sp1)
{
	sp1.sp_center.x = 0.0;
	sp1.sp_center.y = 0.0;
	sp1.sp_center.z = 3.5;
	sp1.sp_color.r = 75;
	sp1.sp_color.g = 245;
	sp1.sp_color.b = 66;
	sp1.sp_diameter = 0.5;
	sp1.sp_radius = sp1.sp_diameter / 2;
	return (sp1);
}

t_sphere	set_sph2(t_sphere sp2)
{
	sp2.sp_center.x = 0.0;
	sp2.sp_center.y = 100.5;
	sp2.sp_center.z = 25.0;
	sp2.sp_color.r = 245;
	sp2.sp_color.g = 66;
	sp2.sp_color.b = 233;
	sp2.sp_diameter = 100;
	sp2.sp_radius = sp2.sp_diameter / 2;
	return (sp2);
}