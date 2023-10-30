/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:32 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 16:59:15 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_memchr(const void *s, int c, size_t n){
    unsigned char *cs=s;
    while(n>0)
    {
        if(*cs == c)
            return (cs);
        cs++;
        n--;
    }
    return (0);
}