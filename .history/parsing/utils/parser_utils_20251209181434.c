/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/09 18:14:35 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_error(int lineidx, const char *msg)
{
	ft_printf("Error"\n);
	ft_printf("line no.%d : %s", lineidx, msg);
	exit(EXIT_FAILURE);
}

void	trim_space(char	*str)
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

t_scene	*scene_init(void)
{
	t_scene *sc;

	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	return (sc);
}
