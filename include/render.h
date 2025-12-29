/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/29 19:05:09 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

void	render_background(t_camera *c, int i, int j);
void	renderer(t_scene *w_d, t_line *line, t_rect *rect);

//-----SET_LIGHT-----

void	set_light(t_scene *s);

//-----SET_CAMERA-----

void	calculate_viewport_height(t_camera *c);
void	calculate_upper_left(t_camera *c);
void	set_camera_init(t_camera *c);
void	set_camera(t_camera *c);

# endif