/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_L.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:34:59 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 00:13:46 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	parser_L(char **s, t_light *out)
{
	char	*p;
	char	*save;
	t_light	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.pos))
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio < 0.0 || tmp.ratio > 1.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.light_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_L(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (parser_error(lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "L", 1))
		return (parser_error(lineidx, "invalid L identifier.\n"), 0);
	if (!parser_CL(&p, &sc->light))
		return (parser_error(lineidx, "invalid L line.\n"), 0);
	return (1);
}

