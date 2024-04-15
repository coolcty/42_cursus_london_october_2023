/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:51:54 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 04:52:59 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	result;
	size_t	l_dest;
	size_t	l_src;

	if (!dest && !size)
		return (0);
	result = 0;
	l_dest = 0;
	l_src = ft_strlen(src);
	while (*(dest) && result < size)
	{
		dest++;
		result++;
		l_dest++;
	}
	if (*dest)
		return (l_dest + l_src);
	while (*src && result + 1 < size--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (l_dest + l_src);
}
