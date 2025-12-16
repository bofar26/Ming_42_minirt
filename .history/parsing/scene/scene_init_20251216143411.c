/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:39 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 14:34:11 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_scene	*scene_init(void)
{
	t_scene *sc;

	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	return (sc);
}

void	*xmalloc_zero(size_t sz)
{
	void	
}
