/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 00:39:44 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	handle_key_move(int keycode)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	const char	*rt_file_name;
	t_scene	*s;

	if (argc < 2)
		return (1);
	if (!argv || !*argv)
		return (1);
	s = parser_rt((const char) argv[1]);
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH,
			HEIGHT, "minirt");
	s->mlx_ptr = mlx;
	s->win_ptr = window;
	mlx_hook(window, 17, 0, handle_exit, &s);
	mlx_key_hook(window, handle_key_move, &s);
	mlx_loop(mlx);
	return (0);
}
