/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:30:05 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/26 14:34:47 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
#include "minirt.h"

typedef struct t_point3
{
	double	x;
	double	y;
	double	z;
}	t_point3;

typedef struct t_ray
{
	t_point3	o;
	t_vec3	d;
	float	time;
	char	*medium;
	char	*material;
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
t_vec3	substract_vector(t_vec3 *v, double x, double y, double z);
t_vec3	power_vector(t_vec3 *v, double t);
double	length_vector(double start, double finish, t_point3 *p);

//-----RAY-----

int		did_it_hit(int i, int j, int k, int r);
float	ray(t_scene *s, float t, int r, int x, int y);

//-----GEOMETRY-----

void	draw_circle(t_scene *win_dis);
void	ft_draw_line(t_line *line, t_scene *win_dis);
void	draw_rect(t_rect *rect, t_scene *win_dis);

//-----UTILS_MATHS-----

double	norm(double val_init, double max_init, double min_fin, double max_fin);

#endif
