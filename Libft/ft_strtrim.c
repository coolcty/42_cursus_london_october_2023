/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:18:09 by tochen            #+#    #+#             */
/*   Updated: 2023/11/15 00:08:17 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	charset_map[256];
	int				i;
	int				len;
	char			*res;

	i = 0;
	while (i < 256)
		charset_map[i++] = 0;
	while (*set)
		charset_map[(unsigned char)*(set++)] = 1;
	i = 0;
	len = 0;
	while (*(s1 + i++))
		if (!charset_map[(unsigned char)*(s1 + i - 1)])
			len++;
	res = malloc(len + 1);
	if (!res)
		return (res);
	len = 0;
	while (*(s1++))
		if (!charset_map[(unsigned char)*(s1 - 1)])
			*(res + len++) = *(s1 - 1);
	*(res + len) = 0;
	return (res);
}
