/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:29 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 04:33:14 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strlen_sep(char const *str, char c)
{
	int	result;

	result = 0;
	while (*str && !(*str == c))
	{
		result++;
		str++;
	}
	return (result);
}

static int	ft_count_size(char const *str, char c)
{
	int	result;

	if (!str)
		return (0);
	result = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && !(*str == c))
			result++;
		while (*str && !(*str == c))
			str++;
	}
	return (result);
}

static char	**ft_free(char **result, int i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	result = 0;
	return (result);
}

static char	**ft_fill_array(char **result, char const *str, char c, int ar_sz)
{
	int	i;
	int	sz;

	i = 0;
	while (i < ar_sz)
	{
		while (*str && (*str == c))
			str++;
		sz = ft_strlen_sep(str, c);
		result[i] = malloc(sizeof(char) * (sz + 1));
		if (!result[i])
			return (ft_free(result, i));
		ft_strlcpy(result[i], str, sz + 1);
		str += sz;
		i++;
	}
	return (result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		ar_sz;

	if (!str)
		return (0);
	ar_sz = ft_count_size(str, c);
	result = malloc(sizeof(char *) * (ar_sz + 1));
	if (!result)
		return (result);
	result[ar_sz] = 0;
	return (ft_fill_array(result, str, c, ar_sz));
}
