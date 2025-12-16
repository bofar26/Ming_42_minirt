/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_L.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:34:59 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 20:42:18 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

int	parser_L(char **s, t_light *out)
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
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio < 0.0 || tmp.ratio > 1)
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

