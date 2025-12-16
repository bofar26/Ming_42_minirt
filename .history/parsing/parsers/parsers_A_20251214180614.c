/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 18:06:14 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parser_A(char **s, t_color *out)
{
	char	*p;
	char	*save;
	t_color	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_int(&p, &tmp.r) || tmp.r > 255 || tmp.r < 0)
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.g) || tmp.g > 255 || tmp.g < 0)
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.b) || tmp.b > 255 || tmp.b < 0)
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}
