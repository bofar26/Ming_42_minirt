/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/22 18:37:18 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	give_color(t_color *c)
// {
// 	// t = transparency 
// 	// c->t = ((double)c->count / (double)c->max_iteration);
// 	// c->t = 0.1;
// 	c->r = (int)(8 * (1 - c->t) * c->t * c->t * c->t * 255);
// 	c->g = (int)(15 * (1 - c->t) * (1 - c->t) * c->t * c->t * 255);
// 	c->b = (int)(5 * (1 - c->t) * (1 - c->t) * (1 - c->t) * c->t * 255);
// 	c->color = 0xFF << 24 | c->r << 16 | c->g << 8 | c->b;
// 	return (c->color);
// }

int	render_color(t_color c, int x, int y)
{
	double auto_r;
	double auto_g;
	double auto_b;
	
	auto_r = (double)x / (WIDTH - 1);
	auto_g = (double)y / (HEIGHT - 1);
	auto_b = 0.0;
	
	c.r = (int)(255.999 * auto_r);
	c.g = (int)(255.999 * auto_g);
	c.b = (int)(255.999 * auto_b);

	return (0xFF << 24 | c.r << 16 | c.g << 8 | c.b);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
