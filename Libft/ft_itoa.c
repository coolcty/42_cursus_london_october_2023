/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:08:26 by tochen            #+#    #+#             */
/*   Updated: 2023/11/15 01:42:10 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	len = ft_intlen(n);
	result = malloc(len + 1);
	if (!result)
		return (0);
	result[len--] = 0;
	if (!n)
		result[len--] = '0';
	while (n)
	{
		result[len--] = (n % 10) * (1 - 2 * (n < 0)) + '0';
		n /= 10;
	}
	if (len == 0)
		result[0] = '-';
	return (result);
}
