/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:13:27 by mipang            #+#    #+#             */
/*   Updated: 2025/12/02 19:27:37 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene parser_rt(const char  *rt_file_name)
{
    int		fd;
    char	*line;
	int		lineidx;

	t_scene	sc;
	lineidx = 0;
	fd = open(rt_file_name, O_RONLY);
	sc = scene_init();
	if (fd < 0)
		parser_error(0, "Can not open .rt file\n");
	while (line = get_next_line(fd) != NULL)
	{
		lineidx ++;
		trim_inplace(line);
		if (*line != '\0')
			dispatch(&sc, line, lineidx);
		free(line);
	}
	if (clese(fd) < 0)
		parser_error(0, "Close fd failure.\n");
	rt_final_check(&sc);
	return (sc);
}