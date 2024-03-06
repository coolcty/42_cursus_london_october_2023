/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:01 by tochen            #+#    #+#             */
/*   Updated: 2024/03/06 13:59:01 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (str && *str)
	{
		result++;
		str++;
	}
	return (result);
}

static int	ft_put_pos_nbr_base(unsigned long long nb, char *base, int lbase)
{
	int	res;

	res = 0;
	if (nb == 0)
	{
		ft_putchar(base[0]);
		res++;
	}
	else
	{
		if (nb / lbase != 0)
			res += ft_put_pos_nbr_base(nb / lbase, base, lbase);
		ft_putchar(base[nb % lbase]);
		res++;
	}
	return (res);
}

static int	ft_valid_base(char *str)
{
	char	stat[256];
	int		i;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (i < 256)
	{
		stat[i] = 0;
		i++;
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		if (*str == ' ' || (*str <= 13 && *str >= 9))
			return (0);
		if (stat[(unsigned char)*str] == 1)
			return (0);
		stat[(unsigned char)*str] = 1;
		str++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					lbase;
	unsigned long long	llnbr;

	if (!ft_valid_base(base))
		return (0);
	lbase = ft_strlen(base);
	llnbr = nbr;
	return (ft_put_pos_nbr_base(llnbr, base, lbase));
}

int	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			res;

	res = 0;
	ln = (long long)n;
	if (ln == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		res++;
		ln *= -1;
	}
	if (ln / 10)
		res += ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(ln % 10 * (1 - 2 * (ln < 0)) + '0', fd);
	res++;
	return (res);
}
