/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:40:12 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 03:59:33 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t slen)
{
	size_t	len;
	size_t	blen;
	size_t	position;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	if (!slen)
		return (0);
	blen = ft_strlen(big);
	if (slen < blen)
		blen = slen;
	position = 0;
	if (len > slen)
		return (0);
	while (position + len <= blen)
	{
		if (!ft_strncmp(big + position, little, len))
			return ((char *)(big + position));
		position++;
	}
	return (0);
}
