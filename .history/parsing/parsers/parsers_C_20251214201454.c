/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:20:48 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 20:14:54 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	vec3_zero(t_vec3 tmp)
{
	return ((tmp.x != 0) && (tmp.y != 0) && (tmp.z != 0));
}

static int	vec3_range(t_vec3 tmp, double max, double min)
{
	if ((tmp.x < min) && (tmp.x > max))
		return (0);
	if ((tmp.y < min) && (tmp.y > max))
		return (0);
	if ((tmp.z < min) && (tmp.z > max))
		return (0);
	return (1);
}

int	parser_C(char **s, t_camera *out)
{
	char	*p;
	char	*save;
	t_camera	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.viewpoint))
		return (*s = save, 0);
	if (!parser_vec3(&p, &tmp.orientation) ||
		!vec3_zero(tmp.orientation) || !vec3_range(tmp.orientation, 1, -1))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.fov) || !vec3_range(tmp.orientation, 0))
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}
