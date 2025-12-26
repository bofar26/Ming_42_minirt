/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/26 14:46:26 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

void	renderer(t_scene *w_d, t_line *line, t_rect *rect);

//-----SET_LIGHT-----

void	set_light(t_scene *s);

//-----SET_CAMERA-----

void    calculate_viewport_height(t_camera *c);
double  set_camera(t_camera *c);




# endif