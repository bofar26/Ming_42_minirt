/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:14:38 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 13:56:09 by mipang           ###   ########.fr       */
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
	int		has_digit;
	int		has_frac;

	if (!**s || !*s || !out)
		return (0);
	p = *s;
	sign = 1;
	fp = 0.0;
	ip=
}
