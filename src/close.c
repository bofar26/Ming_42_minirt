/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:47:04 by leazannis         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/17 17:23:19 by mipang           ###   ########.fr       */
=======
/*   Updated: 2025/12/16 22:51:52 by lzannis          ###   ########.fr       */
>>>>>>> lea
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	close_win(t_scene *w_d)
{
	mlx_destroy_image(w_d->mlx_ptr, w_d->img_ptr);
	mlx_destroy_window(w_d->mlx_ptr, w_d->win_ptr);
	mlx_destroy_display(w_d->mlx_ptr);
	free(w_d->mlx_ptr);
	free(w_d->camera->viewpoint);
	free(w_d->camera->orientation);
	free(w_d->camera);
	free(w_d->ambient->ambient_color);
	free(w_d->ambient);
	free(w_d->light->pos);
	free(w_d->light->light_color);
	free(w_d->light);	
	free(w_d);
	exit(EXIT_SUCCESS);
}

int	handle_exit(void *param, t_scene *s)
{
	(void)param;
	close_win(s);
	return (0);
}
