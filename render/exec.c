/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/26 15:13:23 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	renderer(t_scene *w_d, t_line *line, t_rect *rect)
{
	(void)line;
	(void)rect;
	t_point3 o;
	t_vec3 v;
	
	set_light(w_d);
	set_camera(&w_d->camera);
	fill_frame(w_d, &o, &v);
	draw_rect(rect, w_d);
	ft_draw_line(line, w_d);
	draw_circle(w_d);
}

