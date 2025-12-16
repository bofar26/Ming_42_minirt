/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:17:19 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 21:24:03 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#include "minirt.h"

typedef struct t_vec3{
	double	x;
	double	y;
	double	z;
} t_vec3;

typedef struct	t_color{
	int r;
	int g;
	int b;
} t_color;

typedef struct	t_camera{
	t_vec3	viewpoint;
	t_vec3	orientation;
	int		fov;
	int		set;
} t_camera;

typedef struct	t_ambient{
	double	ratio;
	t_color	ambient_color;
	int		set;
} t_ambient;

typedef struct	t_light{
	t_vec3	pos;
	double ratio;
	t_color	light_color;
	int		set;
} t_light;

typedef struct t_scene{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
} t_scene;

typedef struct t_sphere
{
	t_vec3	sp_center;
	double	sp_diameter;
	t_color	sp_color;
} t_sphere;

typedef struct t_plane
{
	t_vec3	point;
	t_vec3	pl_vector;
	t_color	pl_color;
}

typedef struct t_cylinder
{
	t_vec3	cy_center;
	t_vec3	cy_vector;
	double	cy_diameter;
	double	cy_heigh
}

#endif
