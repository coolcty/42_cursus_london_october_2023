/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:51 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 16:57:52 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *dc;
    unsigned char *sc;
    int incre;

    *dc = dest;
    *sc = src;
    if (dest > src)
    {
        dc += n;
        sc += n;
        incre = -1;
    }
    else if (dest < src)
        incre = 1;
    while (n > 0 && dest != src)
    {
        *dc = *sc;
        dc += incre;
        sc += incre;
        n--;
    }
    return (dest);
}
