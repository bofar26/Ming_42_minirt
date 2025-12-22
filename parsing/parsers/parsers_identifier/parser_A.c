/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/22 20:19:08 by leazannis        ###   ########.fr       */
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
		return (parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "A", 1))
		return (parser_error(sc, lineidx, "invalid A identifier.\n"), 0);
	if (sc->ambient.set)
		return (parser_error(sc, lineidx, "duplicate ambient (A) not allowed.\n"), 0);
	if (!parser_A(&p, &sc->ambient))
		return (parser_error(sc, lineidx, "invalid A line.\n"), 0);
	return (1);
}
