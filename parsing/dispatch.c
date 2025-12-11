/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:57:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 17:15:56 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	dispatch(t_scene *sc, char *line, int lineidx)
{
	char	*str;
	(void)sc;

	str = line;
	while(is_space(*str))
		str++;
	if (*str == '\0' || *str == '#')
		return (1);
	else if (str[0] == 'A' && is_space(str[1]))
	{
		ft_printf("A\n");
		// return (parser_A(sc, str + 1, lineidx));
	}
	else if (str[0] == 'C' && is_space(str[1]))
	{
		ft_printf("C\n");
		// return (parser_C(sc, str + 1, lineidx));
	}
	else if (str[0] == 'L' && is_space(str[1]))
	{
		ft_printf("L\n");
		// return (parser_L(sc, str + 1, lineidx));
	}
	else if (str[0] == 's' && str[1] == 'p' && is_space(str[2]))
	{
		ft_printf("sp\n");
		// return (parser_sp(sc, str + 2, lineidx));
	}
	else if (str[0] == 'p' && str[1] == 'l' && is_space(str[2]))
	{
		ft_printf("pl\n");
		// return (parser_pl(sc, str + 2, lineidx));
	}
	else if (str[0] == 'c' && str[1] == 'y' && is_space(str[2]))
	{
		ft_printf("cy\n");
		// return (parser_cy(sc, str + 2, lineidx));
	}
	else
		parser_error(lineidx, "Dispatch failure. Unknown identifier or missing space after identifier\n");
	return (0);
}
