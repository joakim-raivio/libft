/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:49 by jraivio           #+#    #+#             */
/*   Updated: 2021/11/29 14:25:28 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearray(char ***result, int j)
{
	while (j >= 0)
		ft_strdel(&(result[0][j--]));
	free(*result);
	return (NULL);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c == '\0')
		return (NULL);
	result = (char **)malloc(sizeof(char **) * (size_t)(ft_cntwords(s, c) + 1));
	if (!result || sizeof(result) == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_get_delim_str(s, c, i);
			if (!result[j])
				return (freearray(&result, j - 1));
			i += ft_strlen(result[j++]);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
