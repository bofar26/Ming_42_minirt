/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:30:05 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/30 22:05:14 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
#include "minirt.h"
#include <stdbool.h>

typedef struct t_point3
{
	double	x;
	double	y;
	double	z;
}	t_point3;

typedef struct t_ray
{
	t_point3	o;
	t_vec3		d;
	float		time;
	char		*medium;
	char		*material;
}	t_ray;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}      t_line;

typedef struct s_rect
{
    int    x;
    int    y;
	int    side_w;
    int    side_h;
    int    color;
}      t_rect;

//-----POINT-----

int		pos(t_point3 *p);
int		new_pos_add(t_point3 *p);
int		new_pos_substract(t_point3 *p);

//-----VECTOR------

t_vec3	add_vector(t_vec3 *v, double x, double y, double z);
t_vec3	substract_vector(t_vec3 *p, t_vec3 *c);
t_vec3	power_vector_to_itself(t_vec3 *v);
double	length_vector(double start, double finish);
double	length(double a);
double	length_squared(t_vec3 *v);
t_vec3	unit_vector(t_vec3 *v, double a);

//-----RAY-----

int		did_it_hit(int i, int j, int k, int r);
bool	ray_sphere(t_scene *s, t_vec3 *direction, float t, int r);
t_vec3	ray(t_vec3 *origin, t_vec3 *direction, double t);

//-----GEOMETRY-----

void	draw_circle(t_scene *win_dis);
void	ft_draw_line(t_line *line, t_scene *win_dis);
void	draw_rect(t_rect *rect, t_scene *win_dis);

//-----UTILS_MATHS-----

double	norm(double val_init, double max_init, double min_fin, double max_fin);

#endif
