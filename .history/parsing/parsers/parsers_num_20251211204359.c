/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:14:30 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 20:43:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_sign(int c)
{
	return ((c == '+') || (c == '-'));
}


int	parse_int(char **s, int *out)
{
	char	*p;
	int		sign;
	int		has_digit;
	long long	result;

	p = *s;
	sign = 1;
	has_digit = 0;
	if (!s || !*s)
		return (0);
	skip_space(s);
	if (is_sign())
}

