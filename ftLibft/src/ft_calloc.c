/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:39 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 04:00:53 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (!nmemb || !size)
		return (malloc(1));
	if ((size_t)(-1) / nmemb < size)
		return (0);
	res = malloc(nmemb * size);
	if (res)
		ft_bzero(res, nmemb * size);
	return (res);
}
