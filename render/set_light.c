/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:30:45 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/23 20:14:18 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_light(t_scene *s)
{
	printf("s->camera.orientation.x %.1f s->camera.orientation.y %.1f s->camera.orientation.z %.1f fov %d\n", s->camera.orientation.x, s->camera.orientation.y, s->camera.orientation.z, s->camera.fov);
	printf("s->ambient.ambient_color.r %d, s->ambient.ambient_color.g %d, s->ambient.ambient_color.b %d, ratio %.1f\n", s->ambient.ambient_color.r, s->ambient.ambient_color.g, s->ambient.ambient_color.b, s->ambient.ratio);
	printf("s->light.pos.x %.1f, s->light.pos.y %.1f, s->light.pos.z %.1f, s->light.light_color.r %d, s->light.light_color.g %d, s->light.light_color.b %d, ratio %.1f\n", s->light.pos.x, s->light.pos.y, s->light.pos.z, s->light.light_color.r, s->light.light_color.g, s->light.light_color.b, s->light.ratio);
	printf("s->planes->content %p\n", s->planes->content);
}
