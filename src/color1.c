/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:24 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 21:45:35 by lzannis          ###   ########.fr       */
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

int is_in_shadow(t_scene *s, t_vec3 n, t_vec3 p, t_vec3 unit_dir_l, t_sphere *sp1)
{
    (void)s;
	t_vec3  origin;
	t_vec3  dir;
    double  dist_light;
	t_list	*temp;
	double  t;
    
	t = 0.0;
	temp = s->spheres;
    n = power_vector_to_t(n, 0.0001);
    origin = add_vector(p, n);
    dist_light = dot_squared(dot(unit_dir_l, unit_dir_l));
    dir = normalize_vec3(unit_dir_l);
    while (temp)
	{
		sp1 = temp->content;
        t = ray_sphere(s, dir, sp1->sp_center, sp1->sp_radius, origin);
        if (t > 0.0001 && t < dist_light)
            return (1);
		temp = temp->next;
	}
    return (0);
}

t_vec3  calculate_light(t_scene *s, t_vec3 n, t_vec3 p, t_sphere *sp1)
{
    t_vec3		unit_dir_l;
	t_vec3		ray_light;
	t_vec3		ray_color;
	t_vec3		ray_final;
	t_vec3		ambient_light;
    t_light		l;
	t_ambient	am;
	double		a;
    int         d;
	double		intensity;
    
    a = 0.0;
    d = 0;
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
    d = is_in_shadow(s, n, p, unit_dir_l, sp1);
    if (d)
    {    
        ray_final.x = ambient_light.x * ray_color.x;
        ray_final.y = ambient_light.y * ray_color.y;
        ray_final.z = ambient_light.z * ray_color.z;
    }
    else
    {      
        ray_final.x = (ambient_light.x + ray_light.x) * ray_color.x;
        ray_final.y = (ambient_light.y + ray_light.y) * ray_color.y;
        ray_final.z = (ambient_light.z + ray_light.z) * ray_color.z;
    }
    ray_final.x = clamp(0.0, ray_color.x, ray_final.x);
    ray_final.y = clamp(0.0, ray_color.y, ray_final.y);
    ray_final.z = clamp(0.0, ray_color.z, ray_final.z);
	s->light = l;
	s->ambient = am;
	return (ray_final);
}
