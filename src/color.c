/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/12 19:39:04 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	give_color(t_color *c)
// {
// 	// t = transparency 
// 	// c->t = ((double)c->count / (double)c->max_iteration);
// 	// c->t = 0.1;
// 	c->r = (int)(8 * (1 - c->t) * c->t \
// 				* c->t * c->t * 255);
// 	c->g = (int)(15 * (1 - c->t) * (1 - c->t) \
// 				* c->t * c->t * 255);
// 	c->b = (int)(5 * (1 - c->t) * (1 - c->t) \
// 				* (1 - c->t) * c->t * 255);
// 	c->color = 0xFF << 24 | c->r << 16 | c->g << 8 | c->b;
// 	return (c->color);
// }
int	give_color(t_color *c, int r, int g, int b)
{
	// t = transparency 
	// c->t = ((double)c->count / (double)c->max_iteration);
	// c->t = 0.1;
	// r = (int)(8 * (1 - c->t) * c->t \
	// 			* c->t * c->t * 255);
	// g = (int)(15 * (1 - c->t) * (1 - c->t) \
	// 			* c->t * c->t * 255);
	// b = (int)(5 * (1 - c->t) * (1 - c->t) \
	// 			* (1 - c->t) * c->t * 255);
	c->color = 0xFF << 24 | r << 16 | g << 8 | b;
	return (c->color);
}