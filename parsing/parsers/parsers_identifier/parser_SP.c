/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_SP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:44:57 by mipang            #+#    #+#             */
/*   Updated: 2026/01/13 18:06:16 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		return (parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "sp", 2))
		return (parser_error(sc, lineidx, "invalid SP identifier.\n"), 0);
	dst = add_sphere(sc);
	if (!dst)
		return (parser_error(sc, lineidx, "sphere allocation failed.\n"), 0);
	if (!parser_SP(&p, dst))
		return (parser_error(sc, lineidx, "invalid SP line.\n"), 0);
	printf("dst.sp_diameter %.1f\n", dst->sp_diameter);
	return (1);
}
