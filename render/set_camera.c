/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:50:57 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/29 21:26:06 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calculate_viewport_height(t_camera *c)
{   
    c->viewport_height = 10.0;
    c->viewport_width = c->viewport_height * (double)WIDTH / HEIGHT;
    printf("viewport_width %.1f\n", c->viewport_width);
}

void	calculate_upper_left(t_camera *c)
{
  c->viewport_upper_left.x = c->viewpoint.x - c->viewport_u.x / 2 - c->viewport_v.x / 2;
  c->viewport_upper_left.y = c->viewpoint.y - c->viewport_u.y / 2 - c->viewport_v.y / 2;
  c->viewport_upper_left.z = c->viewpoint.z - c->focal_lenght - c->viewport_u.z / 2 - c->viewport_v.z / 2;
  c->pixel00_loc.x = c->viewport_upper_left.x + 0.5 * (c->pixel_delta_u.x + c->pixel_delta_v.x);
  c->pixel00_loc.y = c->viewport_upper_left.y + 0.5 * (c->pixel_delta_u.y + c->pixel_delta_v.y);
  c->pixel00_loc.z = c->viewport_upper_left.z + 0.5 * (c->pixel_delta_u.z + c->pixel_delta_v.z);
}

void	set_camera_init(t_camera *c)
{
    c->focal_lenght = 1.0;
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
    c->pixel_delta_v.x = c->viewport_v.x / HEIGHT;
    c->pixel_delta_v.y = c->viewport_v.y / HEIGHT;
    c->pixel_delta_v.z = c->viewport_v.z / HEIGHT;
    calculate_upper_left(c);
}

void	set_camera(t_camera *c)
{
  set_camera_init(c);
}

