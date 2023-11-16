/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:19:51 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 03:57:01 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_lstclear_recursion(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_lstclear_recursion(lst->next, del);
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	ft_lstclear_recursion(*lst, del);
	*lst = NULL;
}
