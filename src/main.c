/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 18:10:05 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene		*s;
	t_line line;
	t_rect rect;
	const char	*rt_file_name;

	if (argc != 2)
		return (1);
	if (!argv || !*argv)
		return (1);
	rt_file_name = argv[1];
	s = parser_rt(rt_file_name);
	if (!s)
		return (1);
	rect.x = 100;
	rect.y = 100;
	rect.side_w = 10;
	rect.side_h = 70;
	rect.color = 0x90ee90;
	line.x1 = 0;
	line.y1 = 0;
	line.x2 = 800;
	line.y2 = 600;
	if (!create_window(s))
		close_win(s);
	draw_image(s, &line, &rect);
	close_win(s);
	return (0);
}
