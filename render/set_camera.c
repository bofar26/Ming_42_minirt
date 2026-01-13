/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:50:57 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/13 14:42:13 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double  degrees_to_radians(double fov)
{
  return (fov * PI / 180.0);
}

t_camera	calculate_viewport_height(t_camera c)
{   
    c.viewport_height = 2.0;
    c.viewport_width = c.viewport_height * (double)WIDTH / HEIGHT;
    printf("viewport_width %.1f\n", c.viewport_width);
    return (c);
}

t_camera	calculate_upper_left(t_camera c)
{
  c.viewport_upper_left.x = c.viewpoint.x - c.viewport_u.x / 2 - c.viewport_v.x / 2;
  c.viewport_upper_left.y = c.viewpoint.y - c.viewport_u.y / 2 - c.viewport_v.y / 2;
  c.viewport_upper_left.z = c.viewpoint.z - c.focal_lenght - c.viewport_u.z / 2 - c.viewport_v.z / 2;
  c.pixel00_loc.x = c.viewport_upper_left.x + 0.5 * (c.pixel_delta_u.x + c.pixel_delta_v.x);
  c.pixel00_loc.y = c.viewport_upper_left.y + 0.5 * (c.pixel_delta_u.y + c.pixel_delta_v.y);
  c.pixel00_loc.z = c.viewport_upper_left.z + 0.5 * (c.pixel_delta_u.z + c.pixel_delta_v.z);
  return (c);

}

t_camera	set_camera_init(t_camera c)
{
  c.focal_lenght = 1.0;
  c.viewpoint.x = 0;
  c.viewpoint.y = 0;
  c.viewpoint.z = 1.9;
  c.orientation.x = 0;
  c.orientation.y = 0;
  c.orientation.z = -1;
  c = calculate_viewport_height(c);
  c.viewport_u.x = c.viewport_width;
  c.viewport_u.y = 0;
  c.viewport_u.z = 0;
  c.viewport_v.x = 0;
  c.viewport_v.y = -c.viewport_height;
  c.viewport_v.z = 0;
  c.pixel_delta_u.x = c.viewport_u.x / WIDTH;
  c.pixel_delta_u.y = c.viewport_u.y / WIDTH;
  c.pixel_delta_u.z = c.viewport_u.z / WIDTH;
  c.pixel_delta_v.x = c.viewport_v.x / HEIGHT;
  c.pixel_delta_v.y = c.viewport_v.y / HEIGHT;
  c.pixel_delta_v.z = c.viewport_v.z / HEIGHT;
  return (c);
}

t_camera	set_camera(t_camera c)
{
  c = set_camera_init(c);
  c = calculate_upper_left(c);
  return (c);
}

