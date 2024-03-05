/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:01 by tochen            #+#    #+#             */
/*   Updated: 2023/11/15 00:09:48 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
