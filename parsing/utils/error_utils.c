/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/23 12:50:40 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

void	parser_error(t_scene *sc, int lineidx, const char *msg)
{
	ft_printf("Error\n");
	ft_printf("line no.%d : %s", lineidx, msg);
	get_next_line(-1);
	close_win(sc);
	exit(EXIT_FAILURE);
}
