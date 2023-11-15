/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:32 by tochen            #+#    #+#             */
/*   Updated: 2023/11/13 20:56:56 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cs;
	unsigned char uc;
	
	uc = (unsigned char)c;
	cs = (unsigned char *)s;
	while (n > 0)
	{
		if (*cs == uc)
			return (cs);
		cs++;
		n--;
	}
	return (0);
}