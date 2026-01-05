/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/05 17:01:24 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

t_camera	normalize_viewport(t_camera c, int i, int j);
void		renderer(t_scene *w_d, t_line *line, t_rect *rect);

//-----SET_LIGHT-----

void		set_light(t_scene *s);

//-----SET_CAMERA-----

t_camera	calculate_viewport_height(t_camera c);
t_camera	calculate_upper_left(t_camera c);
t_camera	set_camera_init(t_camera c);
t_camera	set_camera(t_camera c);

//-----SET_SPHERE-----

t_sphere	set_sphere(t_sphere sp);

# endif
