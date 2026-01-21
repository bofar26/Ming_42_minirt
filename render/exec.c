/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/21 19:44:21 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	renderer(t_scene *w_d)
{
	t_point3 o;
	t_vec3 v;
	t_camera c;
	t_sphere *sp1;

	c = w_d->camera;
	sp1 = (t_sphere *)w_d->spheres->content;
	printf("spheres.z %.1f spheres.diameter %.1f \n", sp1->sp_center.z, sp1->sp_diameter);
	c = set_camera(c);
	w_d->camera = c;
	set_light(w_d->light);
	fill_frame(w_d, &o, &v);
}

