/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:36 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 01:52:30 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *ss1, const char *ss2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)ss1;
	s2 = (unsigned char *)ss2;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n > 1)
	{
		if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
		s1++;
		s2++;
		n--;
	}
	return ((int)*s1 - (int)*s2);
}
