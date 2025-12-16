/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:53:08 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 15:04:06 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_plane	*add_plane(t_scene *sc)
{
	t_plane	*obj;

	if (!sc)
		return (NULL);
	obj = (t_plane *)scene_push(&sc->planes, sizeof(t_plane));
	if (!obj)
		return (NULL);
	else
		sc -> n_planes ++;
	return (obj);
}

t_sphere	*add_sphere(t_scene *sc)
{
	t_sphere	*obj;

	if (!sc)
		return (NULL);
	obj = (t_sphere *)scene_push(&sc->spheres, sizeof(t_sphere));
	if (!obj)
		return (NULL);
	else
		sc -> n_planes ++;
	return (obj);
}

t_plane	*add_plane(t_scene *sc)
{
	t_plane	*obj;

	if (!sc)
		return (NULL);
	obj = (t_plane *)scene_push(&sc->planes, sizeof(t_plane));
	if (!obj)
		return (NULL);
	else
		sc -> n_planes ++;
	return (obj);
}
