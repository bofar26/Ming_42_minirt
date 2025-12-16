/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:38:42 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 17:59:18 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	skip_space(char *str)
{
	while (*str && is_space(*str))
		str ++;
}

int	expect_split(char **s, char c)
{
	char	*cur;

	if (!s || !*s)
		return (0);
	cur = *s;
	skip_space(&cur);
	if (*cur != c)
		return (0);
	cur ++;
	*s = cur;
	return (1);
}

int	ensure_e
