/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 17:05:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
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
	if (!create_window(s))
		close_win(s);
	draw_image(s);
	close_win(s);
	return (0);
}
