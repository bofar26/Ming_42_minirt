/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:57:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/22 20:09:01 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	dispatch(t_scene *sc, char *line, int lineidx)
{
	char	*str;

	str = line;
	while(is_space(*str))
		str++;
	if (*str == '\0' || *str == '#')
		return (0);
	else if (str[0] == 'A' && is_space(str[1]))
		return (dispatch_A(sc, str, lineidx), 1);
	else if (str[0] == 'C' && is_space(str[1]))
		return (dispatch_C(sc, str, lineidx), 1);
	else if (str[0] == 'L' && is_space(str[1]))
		return (dispatch_L(sc, str, lineidx), 1);
	else if (str[0] == 's' && str[1] == 'p' && is_space(str[2]))
		return (dispatch_SP(sc, str, lineidx), 1);
	else if (str[0] == 'p' && str[1] == 'l' && is_space(str[2]))
		return (dispatch_PL(sc, str, lineidx), 1);
	else if (str[0] == 'c' && str[1] == 'y' && is_space(str[2]))
		return (dispatch_CY(sc, str, lineidx), 1);
	return (0);
}
