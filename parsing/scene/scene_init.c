/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:parsing/utils/parser_utils.c
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 17:36:00 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_error(int lineidx, const char *msg)
{
	ft_printf("Error\n");
	ft_printf("line no.%d : %s", lineidx, msg);
	exit(EXIT_FAILURE);
}

void	trim_space(char	*str)
{
	char	*start;
	char	*end;

	if (!str)
		return ;
	start = str;
	end = start + ft_strlen(str);
	while (*start && ((*start == ' ') || *start == '\t'))
		start ++;
	while (end > start && ((end[-1] == ' ') || (end[-1] == '\t')
		|| (end[-1] == '\n') || (end[-1] == '\r')))
		end --;
	*end = '\0';
	if (start != str)
		ft_memmove(str, start, end - start + 1);
}
=======
/*   Created: 2025/12/16 14:29:39 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 18:22:09 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
>>>>>>> origin/parser-ming:parsing/scene/scene_init.c

t_scene	*scene_init(t_scene *sc)
{
	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	sc->zoom = 1.0;
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
	if (!sc)
		return ;
	ft_lstclear(&sc -> planes, del_content);
	ft_lstclear(&sc -> spheres, del_content);
	ft_lstclear(&sc -> cylinders, del_content);
}
