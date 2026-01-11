/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:30:45 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/09 17:39:38 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_light(t_light l)
{
	l.pos.x = -1;
	l.pos.y = -1;
	l.pos.z = 1;
	
	printf("lightx %.1f light y %.1f light z %.1f \n", l.pos.x, l.pos.y, l.pos.z);
}
