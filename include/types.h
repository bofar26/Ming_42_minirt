/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:17:19 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 17:59:21 by lzannis          ###   ########.fr       */
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
	t_vec3	*viewpoint;
	t_vec3	*orientation;
	int		fov;
	int		set;
}	t_camera;

typedef struct t_ambient
{
	double	ratio;
	t_color	*ambient_color;
	int		set;
}	t_ambient;

typedef struct t_light
{
	t_vec3	*pos;
	t_color	*light_color;
	double	ratio;
	int		set;
}	t_light;

typedef struct t_sphere
{
	t_vec3	sp_center;
	double	sp_diameter;
	t_color	sp_color;
} t_sphere;

typedef struct t_plane
{
	t_vec3	pl_point;
	t_vec3	pl_vector;
	t_color	pl_color;
} t_plane;

typedef struct t_cylinder
{
	t_vec3	cy_center;
	t_vec3	cy_vector;
	double	cy_diameter;
	double	cy_height;
	t_color	cy_color;
} t_cylinder;

#endif
