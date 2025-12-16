/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 14:52:27 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H
#include "minirt.h"
#include "types.h"
#include <limits.h>

void	parser_error(int lineidx, const char *msg);
void	skip_space(char **str);
void	*scene_push(t_list **lst, size_t obj_size)
int		dispatch(t_scene *sc, char *line, int lineidx);
int		is_space(char c);
int		check_ratio(double r);
int		check_rgb(int c);
int		parser_int(char **s, int *out);
int		parser_A(char **s, t_ambient *out);
int		parser_C(char **s, t_camera *out);
int		parser_L(char **s, t_light *out);
int		parser_SP(char **s, t_sphere *out);
int		parser_PL(char **s, t_plane *out);
int		parser_CY(char **s, t_cylinder *out);
int		parser_color(char **s, t_color *out);
int		parser_double(char **s, double *out);
int		parser_vec3(char **s, t_vec3 *out);
int		expect_split(char **s, char c);
int		ensure_eol(char *p);
void	*xmalloc_zero(size_t sz);

t_scene *parser_rt(const char  *rt_file_name);

#endif
