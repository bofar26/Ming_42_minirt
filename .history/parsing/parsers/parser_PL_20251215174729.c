/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_PL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:38:40 by mipang            #+#    #+#             */
/*   Updated: 2025/12/15 17:47:29 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	vec3_non_zero(t_vec3 tmp)
{
	return ((tmp.x != 0) || (tmp.y != 0) || (tmp.z != 0));
}

static int	vec3_range(t_vec3 tmp, double min, double max)
{
	if ((tmp.x < min) || (tmp.x > max))
		return (0);
	if ((tmp.y < min) || (tmp.y > max))
		return (0);
	if ((tmp.z < min) || (tmp.z > max))
		return (0);
	return (1);
}

int	parser_PL(char **s, t_plane *out)
{
	char	*p;
	char	*save;
	t_plane	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.pl_point))
		return (*s = save, 0);
	if (!parser_vec3(&p, &tmp.pl_vector) ||
		!vec3_non_zero(tmp.pl_vector) ||
		!vec3_range(tmp.pl_vector, -1, 1))
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.pl_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_PL(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (parser_error(lineidx, "internal: scene is NULL."), 0);
	if (!parser_CY(&p, &sc->ambient))
		return (parser_error(lineidx, "invalid PL line."), 0);
	return (1);
}
