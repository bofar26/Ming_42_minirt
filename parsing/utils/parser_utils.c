/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/03 16:47:58 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    parser_error(int lineidx, const char *msg)
{
    ft_printf("Error"\n);
    ft_printf("line no.%d : %s", lineidx, msg);
    exit(EXIT_FAILURE);
}

t_scene scene_init(t_scene sc)
{

}