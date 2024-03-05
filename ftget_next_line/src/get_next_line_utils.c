/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:42:40 by tochen            #+#    #+#             */
/*   Updated: 2024/01/28 00:14:05 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	result;

	result = ft_strlen(src);
	if (size < 1)
		return (result);
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
		return (res);
	res[0] = '\0';
	ft_strlcpy(res, s1, l1 + 1);
	ft_strlcpy(res + l1, s2, l2 + 1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	p;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (res)
	{
		p = 0;
		while (p < len)
		{
			*(res + p) = *(s + p);
			p++;
		}
		*(res + len) = '\0';
	}
	return (res);
}
