/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:26:21 by mipang            #+#    #+#             */
/*   Updated: 2025/11/28 22:33:04 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINI_RT_H
#define MINI_RT_H
#define WIDTH 800
#define HEIGHT 600
#define KEY_ESC 65307

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <errno.h>
# include <X11/keysym.h>

typedef struct t_scene{
	void	*mlx_ptr;
	void	*win_ptr;
} t_scene;

typedef struct s_atof
{
	double	nbr;
	int		nb;
	int		sign;
	int		len;
	int		i;
}	t_atof;

//-----ATOF-----

double	ft_atof(char *str);


#endif
