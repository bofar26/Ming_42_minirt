/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 23:20:07 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H
#include "minirt.h"
#include "types.h"
#include <limits.h>

void	parser_error(int lineidx, const char *msg);
char	**ft_split(char *str, char sep);
void	skip_space(char **str);
int		dispatch(t_scene *sc, char *line, int lineidx);
int		is_space(char c);
int		check_ratio(double r);
int		check_rgb(int c);
int		parse_int(char **s, int *out);
int	expect_split(char **s, char c);
t_scene	*scene_init(void);
t_scene *parser_rt(const char  *rt_file_name);

#endif
