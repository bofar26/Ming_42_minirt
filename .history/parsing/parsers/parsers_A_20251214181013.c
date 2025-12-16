/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 18:10:13 by mipang           ###   ########.fr       */
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
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio > 1 || tmp.ratio < 0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.ambient_color))
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.b) || tmp.b > 255 || tmp.b < 0)
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}
