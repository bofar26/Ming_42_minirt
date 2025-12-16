/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:17 by mipang            #+#    #+#             */
/*   Updated: 2025/12/16 22:51:22 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "types.h"

void	parser_error(int lineidx, const char *msg);
// char	**ft_split(char *str, char sep);
void	trim_space(char	*str);
int		dispatch(t_scene *sc, char *line, int lineidx);
int		is_space(char c);
t_scene	*parser_rt(t_scene *sc, const char *rt_file_name);

#endif
