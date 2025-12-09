/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/09 17:30:41 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	give_color(t_scene *w_d)
{
	// t = transparency 
	// w_d->t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->r = (int)(8 * (1 - w_d->t) * w_d->t \
				* w_d->t * w_d->t * 255);
	w_d->g = (int)(15 * (1 - w_d->t) * (1 - w_d->t) \
				* w_d->t * w_d->t * 255);
	w_d->b = (int)(5 * (1 - w_d->t) * (1 - w_d->t) \
				* (1 - w_d->t) * w_d->t * 255);
	w_d->color = 0xFF << 24 | w_d->r << 16 | w_d->g << 8 | w_d->b;
	return (w_d->color);
}
