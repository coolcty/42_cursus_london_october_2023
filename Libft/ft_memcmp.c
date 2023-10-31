/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:42 by tochen            #+#    #+#             */
/*   Updated: 2023/10/31 23:49:31 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_c1;
	unsigned char	*p_c2;

	p_c1 = (unsigned char *)s1;
	p_c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p_c1 != *p_c2)
			return ((int)(*p_c1) - (int)(*p_c2));
		p_c1++;
		p_c2++;
		n--;
	}
	return (0);
}
