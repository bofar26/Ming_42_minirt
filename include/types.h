/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:17:19 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 20:37:37 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct t_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct t_color
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;
}	t_color;

typedef struct t_camera
{
	t_vec3	viewpoint;
	t_vec3	orientation;
	int		fov;
	int		set;
}	t_camera;

typedef struct t_ambient
{
	double	ratio;
	t_color	ambient_color;
	int		set;
}	t_ambient;

typedef struct t_light
{
	t_vec3	pos;
	t_color	light_color;
	double	ratio;
	int		set;
}	t_light;

typedef struct t_scene
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		shift_x;
	double		shift_y;
	double		time;
	double		render_time;
	double		zoom;
}	t_scene;

#endif