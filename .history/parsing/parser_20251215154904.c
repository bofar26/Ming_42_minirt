/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:13:27 by mipang            #+#    #+#             */
/*   Updated: 2025/12/15 15:49:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_scene	*scene_init(void)
{
	t_scene *sc;

	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	return (sc);
}

static void	trim_space(char	*str)
{
	char	*start;
	char	*end;

	if (!str)
		return ;
	start = str;
	end = start + ft_strlen(str);
	while (*start && ((*start == ' ') || *start == '\t'))
		start ++;
	while (end > start && ((end[-1] == ' ') || (end[-1] == '\t')
		|| (end[-1] == '\n') || (end[-1] == '\r')))
		end --;
	*end = '\0';
	if (start != str)
		ft_memmove(str, start, end - start + 1);
}

t_scene *parser_rt(const char  *rt_file_name)
{
    int		fd;
    char	*line;
	int		lineidx;
	t_scene	*sc;

	lineidx = 0;
	fd = open(rt_file_name, O_RDONLY);
	sc = scene_init();
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
	//rt_final_check(sc);
	return (sc);
}
