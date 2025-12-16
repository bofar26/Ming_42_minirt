/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:20:48 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 19:47:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	vec3_zero(t_camera *tmp)
{
	return ()
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
	if (!parser_vec3(&p, &tmp.viewpoint) || tmp.viewpoint > 1 || tmp.ratio < 0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.ambient_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}
