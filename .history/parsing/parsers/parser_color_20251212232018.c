/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:04 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 23:20:18 by mipang           ###   ########.fr       */
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
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(s, &tmp.g) || tmp.g > 255 || tmp.g < 0)
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(s, &tmp.b) || tmp.b > 255 || tmp.b < 0)
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}
