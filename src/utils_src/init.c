/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:32:03 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/16 22:51:09 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_init(t_camera *camera)
{
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	ft_memset(camera, 0, sizeof(t_camera));
	camera->viewpoint = malloc(sizeof(t_vec3));
	if (!camera->viewpoint)
		return (NULL);
	ft_memset(camera->viewpoint, 0, sizeof(t_vec3));
	camera->orientation = malloc(sizeof(t_vec3));
	if (!camera->orientation)
		return (NULL);
	ft_memset(camera->orientation, 0, sizeof(t_vec3));
	return (camera);
}

t_ambient	*ambient_init(t_ambient *ambient)
{
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ft_memset(ambient, 0, sizeof(t_ambient));
	ambient->ambient_color = malloc(sizeof(t_color));
	if (!ambient->ambient_color)
		return (NULL);
	ft_memset(ambient->ambient_color, 0, sizeof(t_color));
	return (ambient);
}

t_light	*light_init(t_light *light)
{
	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	ft_memset(light, 0, sizeof(t_light));
	light->pos = malloc(sizeof(t_vec3));
	if (!light->pos)
		return (NULL);
	ft_memset(light->pos, 0, sizeof(t_vec3));
	light->light_color = malloc(sizeof(t_color));
	if (!light->light_color)
		return (NULL);
	ft_memset(light->light_color, 0, sizeof(t_color));
	return (light);
}

t_scene	*scene_init(t_scene *sc)
{
	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	sc->camera = camera_init(sc->camera);
	sc->ambient = ambient_init(sc->ambient);
	sc->light = light_init(sc->light);
	sc->zoom = 1.0;
	sc->time = getexacttimeofday();
	return (sc);
}
