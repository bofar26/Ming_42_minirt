/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:14:38 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 14:34:05 by mipang           ###   ########.fr       */
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

static double_i	*double_core(double_i *pd)
{
	if (!pd)
		return (NULL);
	while (*(pd -> p) && ft_isdigit(*(pd -> p)))
	{
		pd -> has_digit = 1;
		pd -> ip = pd -> ip * 10 + (double)(*(pd -> p) - '0');
		pd -> p ++;
	}
	if (*(pd -> p) == '.')
	{
		pd -> p ++;
		while ((*(pd -> p)) && ft_isdigit(*(pd -> p)))
		{
			pd -> has_digit = 1;
			pd -> has_frac = 1;
			pd -> base *= 10.0;
			pd -> fp += (double)(*(pd -> p) - '0')/(pd -> base);
			pd -> p ++;
		}
	}
	return (pd);
}

int	parsers_double(char **s, double *out)
{
	double_i	*pd;

	if (!*s || !out)
		return (0);
	pd = init_double_i(s);
	if (!pd)
		return (0);
	skip_space(&(pd -> p));

	*out = (ip + fp)*(double)sign;
	*s = p;
	return (1);
}
