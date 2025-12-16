/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:53:08 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 14:56:18 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_plane	*add_plane(t_scene *sc)
{
	t_plane	obj;

	if (!sc)
		return (NULL);
	obj = (t_plane *)scene_push(sc->planes, sizeof(t_plane))
}
