/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:10 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/16 18:07:42 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	norm(double val_init, double max_init, double min_fin, double max_fin)
{
	return ((val_init / max_init) * (max_fin - min_fin) + min_fin);
}
