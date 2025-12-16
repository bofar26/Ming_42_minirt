/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:39 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 15:43:59 by mipang           ###   ########.fr       */
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

static void	*xmalloc_zero(size_t sz)
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
	t_list	*node;

	obj = xmalloc_zero(obj_size);
	if (!obj)
		return (NULL);
	node = ft_lstnew(obj);
	if (!node)
	{
		free(obj);
		return (NULL);
	}
	ft_lstadd_back(lst, node);
	return (obj);
}

static void	del_content(void *content)
{
	free(content);
}
void	scene_free(t_scene *sc)
{
	ft_lstclear(&sc -> planes, del_content);
	ft_lstclear(&sc -> planes, del_content);
	ft_lstclear(&sc -> spheres, del_content);
	ft_lstclear(&sc -> cylinders, del_content);
}
