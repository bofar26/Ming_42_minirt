/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 17:36:18 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*s;

	(void)argc;
	(void)argv;
	s = NULL;
	s = scene_init(s);
	parser_rt(s, "test.rt");
	if (!create_window(s))
		close_win(s);
	draw_image(s);
	close_win(s);
	return (0);
}
