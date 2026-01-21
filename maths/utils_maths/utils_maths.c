/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:10 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/21 14:45:27 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	norm(double val_init, double max_init, double min_fin, double max_fin)
{
	return ((val_init / max_init) * (max_fin - min_fin) + min_fin);
}

unsigned long int	seeder(void)
{
	unsigned long int v;
	int fd;
	
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return 1;
    if (read(fd, &v, sizeof(v)) != sizeof(v))
		return 1;
    close(fd);	
    printf("%llu\n", (unsigned long long)v);
	return (v);
}

// KISS RNG by Marsaglia
// don't initialise struc to 0 or small value
// change the original value the next use
// implementation without multiplication
unsigned int	seed_kiss_no_power(t_rand r)
{
	int	t;

	r.x = seeder();
	r.y = seeder();
	r.z = seeder();
	r.w = seeder();
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

double	random_double(unsigned int seed)
{
	double x;

	x = seed / 4294967296.0;
	return (x);
}
