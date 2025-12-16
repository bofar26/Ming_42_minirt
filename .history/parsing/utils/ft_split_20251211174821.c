/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:27:19 by mipang            #+#    #+#             */
/*   Updated: 2025/12/11 17:48:21 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static  int	count_words(char *str, char sep)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if ((i == 0 || str[i - 1] == sep) && str[i] != sep)
			count++;
		i++;
	}
	return (count);
}

static  char	*word_dup(char *str, int start, int end)
{
	char	*word = malloc(end - start + 1);
	int		i = 0;

	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	int		i = 0, j = 0, start = -1;
	char	**res = malloc(sizeof(char *) * (count_words(str, sep) + 1));

	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] != sep && start == -1)
			start = i;
		else if ((str[i] == sep || str[i + 1] == '\0') && start != -1)
		{
			if (str[i] == sep)
				res[j++] = word_dup(str, start, i);
			else
				res[j++] = word_dup(str, start, i + 1);
			start = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
