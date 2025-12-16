/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:14:38 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 14:04:49 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_sign(char **p)
{
	int	sign;

	sign = 1;
	if ((**p == '+') || (**p == '-'))
	{
		if (**p == '-')
			sign = -1;
		(*p) ++;
	}
	return (sign);
}

int	parsers_double(char **s, double *out)
{
	char	*p;
	int		sign;
	double	fp;
	double	ip;
	double		base;
	int		has_digit;
	int		has_frac;

	if (!**s || !*s || !out)
		return (0);
	p = *s;
	skip_space(*p);
	sign = get_sign(p);
	fp = 0.0;
	ip = 0.0;
	base = 1.0;
	has_digit = 0;
	has_frac = 0;
	while (*p && ft_isdigit(*p))
	{
		has_digit = 1;
		ip = ip * 10 + (double)(*p - '0');
		p ++;
	}
	if (*p == '.')
	{
		p ++;
		while (*p && ft_isdigit(*p))
		{
			has_digit = 1;
			has_frac = 1;
			base *= 10.0;
			fp += (double)(*p - '0')/base;
			p ++;
		}
		if (!has_digit)
			return (0);
		out = ip + fp 
	}
}
