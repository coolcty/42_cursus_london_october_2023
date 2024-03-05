/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:18:09 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 03:57:48 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_firstposition(char const *s1, unsigned char *charset_map)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && charset_map[(unsigned char)*(s1 + i)])
		i++;
	return (i);
}

static size_t	ft_lastposition(char const *s1, unsigned char *charset_map)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (*(s1 + i))
	{
		if (!charset_map[(unsigned char)*(s1 + i)])
			res = i;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	charset_map[256];
	int				i;
	int				j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (i < 256)
		charset_map[i++] = 0;
	while (*set)
		charset_map[(unsigned char)*(set++)] = 1;
	i = ft_firstposition(s1, charset_map);
	j = ft_lastposition(s1, charset_map);
	if (i <= j)
		return (ft_substr(s1, i, j - i + 1));
	else
		return (ft_substr(s1, 0, 0));
}
