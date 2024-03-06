/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:01 by tochen            #+#    #+#             */
/*   Updated: 2024/03/06 13:59:01 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	i;

	i = write(fd, &c, 1);
	(void)i;
}

void	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	i;

	if (s)
	{
		i = write(fd, s, ft_strlen(s));
		(void)i;
	}
}
