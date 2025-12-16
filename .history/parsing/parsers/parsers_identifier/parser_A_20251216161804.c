/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 16:18:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	parser_A(char **s, t_ambient *out)
{
	char	*p;
	char	*save;
	t_ambient	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio > 1.0 || tmp.ratio < 0.0)
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

int	dispatch_A(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (parser_error(lineidx, "internal: scene is NULL."), 0);
	if (sc->ambient.set)
		return (parser_error(lineidx, "duplicate ambient (A) not allowed.\n"), 0);
	if (!parser_A(&p, &sc->ambient))
		return (parser_error(lineidx, "invalid A line."), 0);
	return (1);
}
