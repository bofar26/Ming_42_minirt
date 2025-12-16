/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:04 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 23:05:43 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char **s, t_color *out)
{
	char	*p;
	char	*save;
	t_color	*color;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	color = malloc(sizeof(t_color));
	if (!color)
		return (0);
	color = (t_color *)ft_memset(color, 0, sizeof(t_color));
	if (!parser_int(s, &color) || color -> r > 255 || color -> r < 0)
		return (*s = save, 0);
	if (!parser_int(s, &color) || color -> g > 255 || color.g < 0)
		return (*s = save, 0);
	if (!parser_int(s, &color) || color.b > 255 || color.b < 0)
		return (*s = save, 0);
	*out = color;
	*s = p;
}
