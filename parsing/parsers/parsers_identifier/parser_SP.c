/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_SP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:44:57 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 16:37:49 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	parser_SP(char **s, t_sphere *out)
{
	char	*p;
	char	*save;
	t_sphere	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.sp_center))
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.sp_diameter) || tmp.sp_diameter <= 0.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.sp_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_SP(t_scene *sc, char *p, int lineidx)
{
	t_sphere	*dst;

	if (!sc)
		return (parser_error(lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "sp", 2))
		return (parser_error(lineidx, "invalid SP identifier.\n"), 0);
	dst = add_sphere(sc);
	if (!dst)
		return (parser_error(lineidx, "sphere allocation failed.\n"), 0);
	if (!parser_SP(&p, dst))
		return (parser_error(lineidx, "invalid SP line.\n"), 0);
	return (1);
}
