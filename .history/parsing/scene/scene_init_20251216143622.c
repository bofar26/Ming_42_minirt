/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:39 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 14:36:22 by mipang           ###   ########.fr       */
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
	void	*p;

	p = malloc(sz);
	if (!p)
		return (NULL);
	ft_bzero(p, sz);
	return (p);
}

void	*scene_push(t_list **lst, size_t obj_size)
{
	void	*obj;
	
}
