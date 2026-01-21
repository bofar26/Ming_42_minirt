/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/21 17:34:30 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	normalize_viewport(t_camera c, int i, int j)
{
	c.pixel_center.x = c.pixel00_loc.x + (i * c.pixel_delta_u.x) + (j * c.pixel_delta_v.x);
	c.pixel_center.y = c.pixel00_loc.y + (i * c.pixel_delta_u.y) + (j * c.pixel_delta_v.y);
	c.pixel_center.z = c.pixel00_loc.z + (i * c.pixel_delta_u.z) + (j * c.pixel_delta_v.z);
	c.orientation.x = c.pixel_center.x - c.viewpoint.x;
	c.orientation.y = c.pixel_center.y - c.viewpoint.y;
	c.orientation.z = c.pixel_center.z - c.viewpoint.z;
	return (c);
} 
void	renderer(t_scene *w_d)
{
	t_point3 o;
	t_vec3 v;
	t_camera c;
	t_sphere *sp1;

	c = w_d->camera;
	sp1 = (t_sphere *)w_d->spheres->content;
	// sp2 = w_d->sph2;
	// sp1 = set_sph1(sp1);
	// sp2 = set_sph2(sp2);
	printf("spheres.z %.1f spheres.diameter %.1f \n", sp1->sp_center.z, sp1->sp_diameter);
	c = set_camera(c);
	w_d->camera = c;
	// w_d->sph1 = sp1;
	// w_d->sph2 = sp2;
	set_light(w_d->light);
	fill_frame(w_d, &o, &v);
}

