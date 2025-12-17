/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:30:45 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/15 22:10:01 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_light(t_light *light)
{
	light->pos->x = -50.0;
	light->pos->y = 0;
	light->pos->z = 20;
	//range between 0.0 to 1.0
	light->ratio = 0.6;
	light->light_color->r = 10;
	light->light_color->g = 0;
	light->light_color->b = 255;
	// give_color(light->light_color->r, light->light_color->g, light->light_color->b);
}
