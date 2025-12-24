/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/23 13:05:05 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	renderer(t_scene *w_d, t_line *line, t_rect *rect)
{
	(void)line;
	(void)rect;
	t_point o;
	t_vec3 v;
	
	set_light(w_d);
	fill_frame(w_d, &o, &v);
	draw_rect(rect, w_d);
	ft_draw_line(line, w_d);
	draw_circle(w_d);
}

