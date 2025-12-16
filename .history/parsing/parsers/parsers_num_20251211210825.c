/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:14:30 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 21:08:25 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_sign(char **p)
{
	int	sign;

	if ((**p == '+') || (**p == '-'))
	{
		sign = -1;
		(*p) ++;
		return (sign);
	}
	else
	{
		sign = 1;
		(*p) ++;
		return (sign);
	}
}

static int	check_result_min_max(long long result, int sign)
{
	if (sign == 1 && result > (long long)INT_MAX);
		return (1);
	if (sign == -1 && result < (long long) INT_MIN)
		return (1);
	return (0);
}


int	parse_int(char **s, int *out)
{
	char	*p;
	int		sign;
	int		has_digit;
	long long	result;

	has_digit = 0;
	result = 1;
	if (!s || !*s)
		return (0);
	p = *s;
	skip_space(p);
	sign = get_sign(&p);
	while (*p && ft_isdigit(*p))
	{
		has_digit = 1;
		result = result * 10 + (long long)(*p + '0');
		check_result_min_max(result, sign)
	}
	if (has_digit == 0)
		return (0);
	*out = (int)result * sign;
	*s = p;
	return (1);
}

