/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:13:27 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 16:57:19 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene *parser_rt(t_scene *sc, const char *rt_file_name)
{
    int		fd;
    char	*line;
	int		lineidx;

	lineidx = 0;
	fd = open(rt_file_name, O_RDONLY);
	if (fd < 0)
		parser_error(0, "Can not open .rt file\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		lineidx ++;
		trim_space(line);
		if (*line != '\0')
			dispatch(sc, line, lineidx);
		free(line);
	}
	if (close(fd) < 0)
		parser_error(0, "Close fd failure.\n");
	// rt_final_check(sc);
	return (sc);
}
