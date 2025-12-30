/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/30 15:52:39 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_background(t_camera *c, int i, int j)
{
	c->pixel_center.x = c->pixel00_loc.x + (i * c->pixel_delta_u.x) + (j * c->pixel_delta_v.x);
	c->pixel_center.y = c->pixel00_loc.y + (i * c->pixel_delta_u.y) + (j * c->pixel_delta_v.y);
	c->pixel_center.z = c->pixel00_loc.z + (i * c->pixel_delta_u.z) + (j * c->pixel_delta_v.z);
	c->orientation.x = c->pixel_center.x - c->viewpoint.x;
	c->orientation.y = c->pixel_center.y - c->viewpoint.y;
	c->orientation.z = c->pixel_center.z - c->viewpoint.z;
}
void	renderer(t_scene *w_d, t_line *line, t_rect *rect)
{
	(void)line;
	(void)rect;
	t_point3 o;
	t_vec3 v;
	
	set_sphere(&w_d->sphere);
	set_light(w_d);
	set_camera(&w_d->camera);
	fill_frame(w_d, &o, &v);
	// draw_rect(rect, w_d);
	// ft_draw_line(line, w_d);
	// draw_circle(w_d);
}

