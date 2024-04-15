/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:14:40 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 03:56:57 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (!(lst->next))
	{
		del(lst->content);
		free(lst);
		return ;
	}
	while (lst->next->next)
	{
		lst = lst->next;
	}
	del(lst->next->content);
	free(lst->next);
	lst->next = NULL;
}
