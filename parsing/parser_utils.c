/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/02 19:26:40 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    parser_error(int lineidx, const char *msg)
{
    ft_printf("ERROR"\n);
    ft_printf("line no.%d : %s", lineidx, msg);
    exit(EXIT_FAILURE);
}

t_scene scene_init(t_scene sc)
{

}