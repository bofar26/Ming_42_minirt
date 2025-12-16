/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:20:48 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 20:12:11 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	vec3_zero(t_vec3 tmp)
{
	return ((tmp.x != 0) && (tmp.y != 0) && (tmp.z != 0));
}

static int	vec3_range(t_vec3 tmp)
{
	if ((tmp.x < -1) && (tmp.x > 1))
		return (0);
	if ((tmp.y < -1) && (tmp.y > 1))
		return (0);
	if ((tmp.z < -1) && (tmp.z > 1))
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
		!vec3_zero(tmp.orientation) || !vec3_range(tmp.orientation))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}
