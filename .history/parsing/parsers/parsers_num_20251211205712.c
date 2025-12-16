/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:14:30 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 20:57:12 by mipang           ###   ########.fr       */
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


int	parse_int(char **s, int *out)
{
	char	*p;
	int		sign;
	int		has_digit;
	long long	result;

	has_digit = 0;
	if (!s || !*s)
		return (0);
	p = *s;
	skip_space(p);
	sign = get_sign(&p);


}

