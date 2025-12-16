/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:38:42 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 21:06:17 by mipang           ###   ########.fr       */
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

void	expect_split(char **s,int c)
{
	char	*cur;

	if (!s || !*s)
		return ;
	cur = *s;
	if (*p !=)
}
