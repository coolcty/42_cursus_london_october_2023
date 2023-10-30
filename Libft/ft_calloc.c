/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:39 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 18:32:20 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *res;
    res = malloc(nmemb * size);
    if (res)
        ft_bzero(res, nmemb * size);
    return res;
}