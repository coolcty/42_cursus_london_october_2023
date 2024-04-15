/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:19:19 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 03:55:48 by tochen           ###   ########.fr       */
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

	if (!s)
		return (0);
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
