/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:01 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 20:08:34 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *strdup(const char *s)
{
    char *res;
    size_t len;
    size_t p;

    len = ft_strlen(s);
    res = malloc(len);

    if (res)
    {
        p = 0;
        while (p < len)
        {
            *(res + p) = *(s + p);
            p++;
        }
    }
    return (res);
}
