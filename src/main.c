/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/11/29 12:17:34 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_innit(t_scene *s)
{
	s->shift_x = 0.0;
	s->shift_y = 0.0;
	s->zoom = 1.0;
}

int	main(int argc, char **argv)
{
	t_scene	s;

	(void)argc;
	(void)argv;
	ft_memset(&s, 0, sizeof(t_scene));
	if (!create_window(&s))
		close_win(&s);
	draw_image(&s);
	return (0);
}
