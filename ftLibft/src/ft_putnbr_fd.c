/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:30:20 by tochen            #+#    #+#             */
/*   Updated: 2023/11/16 04:14:06 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;

	ln = (long long)n;
	if (ln == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln / 10)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(ln % 10 * (1 - 2 * (ln < 0)) + '0', fd);
}
