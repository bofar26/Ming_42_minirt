/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:10 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/20 21:06:49 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	norm(double val_init, double max_init, double min_fin, double max_fin)
{
	return ((val_init / max_init) * (max_fin - min_fin) + min_fin);
}

//write a random number generator using gettimeofday()
/* double	rand_numb_gen()
{
	int	starttime;

	starttime = getexacttimeofday();
	return (getexacttimeofday() / (RAND_MAX + 1.0));
} */

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

// implementation without multiplication
unsigned int	seed_kiss_no_power(t_rand r)
{
	int	t;

	r.x = 134679852;
	r.y = 471547000;
	r.z = 310187518;
	r.w = 7654321;
	r.c = 0;
	t = 0;
	r.y ^= (r.y << 5);
	r.y ^= (r.y >> 7);
	r.y ^= (r.y << 22);
	t = r.z +r.w + r.c;
	r.z = r.w;
	r.c = t < 0;
	r.w = t&214783647;
	r.x += 1411392427;
	return (r.x + r.y + r.w);
}
