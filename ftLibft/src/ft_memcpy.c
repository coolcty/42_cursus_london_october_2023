/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:54 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 04:04:18 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dc;
	unsigned char	*sc;

	if (!dest && !src)
		return (0);
	dc = (unsigned char *)dest;
	sc = (unsigned char *)src;
	while (n > 0)
	{
		*dc = *sc;
		dc++;
		sc++;
		n--;
	}
	return (dest);
}
