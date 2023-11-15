/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:27:18 by tochen            #+#    #+#             */
/*   Updated: 2023/11/01 02:44:34 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	size_t l1, l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
		return (res);
	ft_memcpy(res, s1, l1);
	ft_memcpy(res + l1, s2, l2 + 1);
	return (res);
}