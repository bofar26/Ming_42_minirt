/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:23:12 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/15 21:31:02 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//-----EXEC-----

void	renderer(t_scene *w_d, t_line *line, t_rect *rect);

//-----SET_LIGHT-----

void	set_light(t_light *light);

# endif