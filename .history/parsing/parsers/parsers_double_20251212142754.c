/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:14:38 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 14:27:54 by mipang           ###   ########.fr       */
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

typedef struct double_i
{
	char	*p;
	int		sign;
	double	fp;
	double	ip;
	double	base;
	int		has_digit;
	int		has_frac;
}double_i;

double_i	*init_double_i(char **s)
{
	double_i	*pd;

	pd -> p = *s;
	pd -> sign = get_sign(&(pd -> p));
	pd -> fp = 0.0;
	pd -> ip = 0.0;
	pd -> base = 10;
	pd -> has_digit = 0;
	pd -> has_frac = 0;
}

static int	double_core(double_i *pd)
{
	while (*(pd -> p) && ft_isdigit(*(pd -> p)))
	{
		pd -> has_digit = 1;
		pd -> ip = pd -> ip * 10 + (double)(*(pd -> ip)) - '0');
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
	}
	if (!has_digit)
		return (0);
	else
		return (1);
}

int	parsers_double(char **s, double *out)
{
	double_i	pd;

	if (!*s || !out)
		return (0);
	p = *s;
	skip_space(*p);
	init_parameters(p, sign, fp, ip, base, has_digit, has_frac);
	double_core(p, sign, fp, ip, base, has_digit, has_frac);
	*out = (ip + fp)*(double)sign;
	*s = p;
	return (1);
}
