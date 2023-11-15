/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:19:19 by tochen            #+#    #+#             */
/*   Updated: 2023/11/15 00:05:06 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	rlen;
	size_t	i;
	char	*res;

	slen = ft_strlen(s);
	if (slen < start)
		rlen = 0;
	else
		rlen = slen - start;
	if (len < rlen)
		rlen = len;
	res = malloc(rlen + 1);
	if (!res)
		return (res);
	i = 0;
	while (i < rlen)
	{
		*(res + i) = *(s + start + i);
		i++;
	}
	*(res + i) = 0;
	return (res);
}
