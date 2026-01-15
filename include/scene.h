/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:38:46 by mipang            #+#    #+#             */
/*   Updated: 2026/01/15 19:40:20 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H
#include "types.h"
# include "../libft/libft.h"

typedef struct t_scene{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_sphere	sph1;
	t_sphere	sph2;
	t_color		closest_object;
	t_list		*spheres;
	int			n_spheres;
	t_list		*planes;
	int			n_planes;
	t_list		*cylinders;
	int			n_cylinders;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		ray_min;
	double		ray_max;
	double		closest_so_far;
	double		shift_x;
	double		shift_y;
	double		time;
	double		render_time;
	double		zoom;
} t_scene;

#endif
