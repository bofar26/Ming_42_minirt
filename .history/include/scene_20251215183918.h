/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:38:46 by mipang            #+#    #+#             */
/*   Updated: 2025/12/15 18:39:18 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

typedef struct t_scene{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_list	*spheres;
	int n_spheres;
	t_list	*planes;
	int n_planes;
	t_list	*cylinders;
	int n_cylinders;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
} t_scene;
