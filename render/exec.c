/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/05 17:00:10 by lzannis          ###   ########.fr       */
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
void	renderer(t_scene *w_d, t_line *line, t_rect *rect)
{
	(void)line;
	(void)rect;
	t_point3 o;
	t_vec3 v;
	t_camera c;
	t_sphere sp;
	
	c = w_d->camera;
	sp = w_d->sphere;
	sp = set_sphere(sp);
	c = set_camera(c);
	w_d->camera = c;
	w_d->sphere = sp;
	set_light(w_d);
	fill_frame(w_d, &o, &v);
	// draw_rect(rect, w_d);
	// ft_draw_line(line, w_d);
	// draw_circle(w_d);
}

