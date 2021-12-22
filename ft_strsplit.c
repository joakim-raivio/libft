/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:49 by msilen            #+#    #+#             */
/*   Updated: 2021/11/29 16:18:58 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_counter(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			count++;
			i++;
		}
		else if (*s == c && i == 1)
			i = 0;
		s++;
	}
	return (count);
}

static char	*allocate_str(char const *s, char c)
{
	int		total_len;
	void	*str;

	total_len = 0;
	while (s[total_len] != c && s[total_len])
		total_len++;
	str = ft_strnew(total_len);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, total_len);
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = word_counter(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		result[i] = allocate_str(s, c);
		s += ft_strlen(result[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
