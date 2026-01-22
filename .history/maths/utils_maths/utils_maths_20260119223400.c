/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:10 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/19 22:34:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	norm(double val_init, double max_init, double min_fin, double max_fin)
{
	return ((val_init / max_init) * (max_fin - min_fin) + min_fin);
}

//write a random number generator using gettimeofday()
double	rand_numb_gen()
{
	int	starttime;

	starttime = getexacttimeofday();
	return (starttime / (RAND_MAX + 1.0));
}

// KISS RNG by Marsaglia
// don't initialise struc to 0 or small value
// change the original value the next use
unsigned int	kiss_seed(t_rand r)
{
	unsigned long long	t;
	unsigned long long	a;

	r.x = 134679852;
	r.y = 471547000;
	r.z = 310187518;
	r.c = 7654321;
	t = 0;
	a = 698769069;
	r.x = 69096 * r.x + 12345;
	r.y ^= (r.y << 13);
	r.y = (r.y >> 17);
	r.y = (r.y << 5);
	t = a * r.z + r.c;
	r.c = (t >> 32);
	r.z = t;
	return (r.x + r.y + r.z);
}
