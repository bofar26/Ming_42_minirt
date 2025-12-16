/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_CY.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:58:36 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 21:59:18 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

int	parser_CY(char **s, t_sphere *out)
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
