/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:50:57 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/26 15:18:10 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    calculate_viewport_height(t_camera *c)
{   
    c->viewport_height = 2.0;
    c->viewport_width = c->viewport_height * (double)WIDTH / HEIGHT;
    printf("viewport_width %.1f\n", c->viewport_width);
}
void    set_camera_init(t_camera *c)
{
    c->focal_lenght = 2.0;
    c->viewpoint.x = 0;
    c->viewpoint.y = 0;
    c->viewpoint.z = 0;
    calculate_viewport_height(c);
    c->viewport_u.x =  c->viewport_width;
    c->viewport_u.y = 0;
    c->viewport_u.z = 0;
    c->viewport_v.x = 0;
    c->viewport_v.y = -c->viewport_height;
    c->viewport_v.z = 0;
    c->pixel_delta_u.x = c->viewport_u.x / WIDTH;
    c->pixel_delta_u.y = c->viewport_u.y / WIDTH;
    c->pixel_delta_u.z = c->viewport_u.z / WIDTH;
    c->pixel_delta_v.x = c->viewport_v.x / WIDTH;
    c->pixel_delta_v.y = c->viewport_v.y / WIDTH;
    c->pixel_delta_v.z = c->viewport_v.z / WIDTH;
}

double	set_camera(t_camera *c)
{
  set_camera_init(c);
  
}

