/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/22 17:01:26 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

t_vec3		sample_random_pixel(t_camera c, t_rand *r);
t_camera	normalize_viewport(t_camera c, int i, int j);
void		fill_frame(t_scene *s);
void		renderer(t_scene *w_d);

//-----SET_LIGHT-----

void		set_light(t_light l);

//-----SET_CAMERA-----

double  	degrees_to_radians(double fov);
t_camera	calculate_viewport_height(t_camera c);
t_camera	calculate_upper_left(t_camera c);
t_camera	set_camera_init(t_camera c);
t_camera	set_camera(t_camera c);

# endif
