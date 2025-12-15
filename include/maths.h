/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:30:05 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/12 22:39:44 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef struct t_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct t_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct t_ray
{
	t_point		o;
	t_vector	d;
	float		time;
	char		*medium;
	char		*material;
}	t_ray;

typedef struct s_line
{
	int    x1;
	int    y1;
	int    x2;
	int    y2;
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

int	pos(t_point *p);
int	new_pos_add(t_point *p);
int	new_pos_substract(t_point *p);

//-----VECTOR------

int	vector(t_vector *v);
int	add_vector(t_vector *v);
int	substract_vector(t_vector *v);
int	length_vector(int start, int finish, t_point *p);

//-----RAY-----

//-----GEOMETRY-----

void	draw_circle(t_scene *win_dis);
void	ft_draw_line(t_line *line, t_scene *win_dis);
void	draw_rect(t_rect *rect, t_scene *win_dis);

#endif
