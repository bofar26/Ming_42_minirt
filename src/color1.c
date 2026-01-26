/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:24 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 17:01:13 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	render_background(t_scene *s, t_vec3 direction)
{
	(void)s;
	t_vec3		unit_direction;
	double		a;
	double		b;

	// normalisaton
    b = dot_squared(dot(direction, direction));
    unit_direction = unit_vector(direction, b);
    //gradient blue
    a = 0.5 * (unit_direction.y + 1.0);
    unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
    unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
    unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
    // gradient black
    // unit_direction.x = (1.0 - a) * 1.0 + a * 0.0;
    // unit_direction.y = (1.0 - a) * 1.0 + a * 0.0;
    // unit_direction.z = (1.0 - a) * 1.0 + a * 0.0;
    // black
    // unit_direction.x = 0;
    // unit_direction.y = 0;
    // unit_direction.z = 0;
    return(unit_direction);
}

// t_vec3	is_in_shadow()
// {
	
// }

t_vec3  calculate_light(t_scene *s, t_vec3 n, t_vec3 p)
{
    t_vec3		unit_dir_l;
	t_vec3		ray_light;
	t_vec3		ray_color;
	t_vec3		ray_final;
	t_vec3		ambient_light;
    t_light		l;
	t_ambient	am;
	double		a;
	double		intensity;
    
    a = 0.0;
	intensity = 0.0;
    l = s->light;
	am = s->ambient;
	unit_dir_l = substract_vector(p,l.pos);
	unit_dir_l = power_vector_to_t(unit_dir_l, -1.0);
	a = dot(unit_dir_l, n);// == cos(angle)
	if (a < 0.0)
		a = 0.0;
	intensity = a * l.ratio;
	ray_light = render_color(l.light_color);
	ray_light = power_vector_to_t(ray_light, intensity);
	ray_color = render_color(s->closest_object);
	ambient_light = render_color(am.ambient_color);
	ambient_light = power_vector_to_t(ambient_light, am.ratio);
	ray_final.x = (ambient_light.x + ray_light.x) * ray_color.x;
	ray_final.y = (ambient_light.y + ray_light.y) * ray_color.y;
	ray_final.z = (ambient_light.z + ray_light.z) * ray_color.z;
	ray_final.x = clamp(0.0, ray_color.x, ray_final.x);
	ray_final.y = clamp(0.0, ray_color.y, ray_final.y);
	ray_final.z = clamp(0.0, ray_color.z, ray_final.z);
	s->light = l;
	s->ambient = am;
	return (ray_final);
}
