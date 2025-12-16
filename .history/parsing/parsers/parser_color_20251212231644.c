/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:04 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 23:16:44 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char **s, t_color *out)
{
	char	*p;
	char	*save;
	t_color	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_int(s, &tmp.r) || tmp.r > 255 || tmp.r < 0)
		return (*s = save, 0);
	expect_split(p, ',');
	if (!parser_int(s, &tmp.r) || tmp.r > 255 || tmp.r < 0)
		return (*s = save, 0);
	expect_split(p, ',');
	if (!parser_int(s, &tmp.r) || tmp.r > 255 || tmp.r < 0)
		return (*s = save, 0);
	out = color;
	*s = p;
}
