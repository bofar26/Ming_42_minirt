/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:parsing/utils/dispatch_utils.c
/*   Created: 2025/12/09 18:16:52 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 15:37:58 by lzannis          ###   ########.fr       */
=======
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 17:49:29 by mipang           ###   ########.fr       */
>>>>>>> origin/parser-ming:parsing/utils/error_utils.c
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parser_error(int lineidx, const char *msg)
{
	ft_printf("Error\n");
	ft_printf("line no.%d : %s", lineidx, msg);
	exit(EXIT_FAILURE);
}
