/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/23 13:12:56 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

void	renderer(t_scene *w_d, t_line *line, t_rect *rect);

//-----SET_LIGHT-----

void	set_light(t_scene *s);

# endif