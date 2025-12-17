/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/17 17:05:59 by mipang           ###   ########.fr       */
=======
/*   Updated: 2025/12/15 20:41:27 by lzannis          ###   ########.fr       */
>>>>>>> lea
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_scene		*s;
	const char	*rt_file_name;


	if (argc != 2)
		return (1);
	if (!argv || !*argv)
		return (1);
	rt_file_name = argv[1];
	s = parser_rt(rt_file_name);
	if (!s)
		return (1);
=======
	t_scene	*s;
	t_line line;
	t_rect rect;

	(void)argc;
	(void)argv;
	s = NULL;
	rect.x = 100;
	rect.y = 100;
	rect.side_w = 10;
	rect.side_h = 70;
	rect.color = 0x90ee90;
	line.x1 = 0;
	line.y1 = 0;
	line.x2 = 800;
	line.y2 = 600;
	
	s = scene_init(s);
	parser_rt(s, "test.rt");
>>>>>>> lea
	if (!create_window(s))
		close_win(s);
	draw_image(s, &line, &rect);
	close_win(s);
	return (0);
}
