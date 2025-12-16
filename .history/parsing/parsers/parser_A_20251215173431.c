/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/15 17:34:31 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

int	parser_A(char **s, t_ambient *out)
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
		return (parser_error())
	if (!parser_A(&p, &sc->ambient))
		return (parser_error(lineidx, "Parser ambient failed.\n"), 0);
	return (1);
}
