/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:19:19 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 20:32:07 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t slen;
    size_t rlen;
    char *res;
    
    slen=ft_strlen(s);
    if(slen<=start)
        return (0);
    rlen=slen-start;
    if(len<rlen)
        rlen=len;
    res=malloc(rlen+1);
    
}