/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:08:36 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 17:25:40 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parser_vec3(char **s, t_vec3 *out)
{
	char	*p;
	char	*save;
	t_vec3	tmp;

	if (!s || !*s || !out)
		return (0);
	save = *s;
	p = *s;
	if (!parser_double(&))
}
