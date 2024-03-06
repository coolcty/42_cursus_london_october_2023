/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:01 by tochen            #+#    #+#             */
/*   Updated: 2024/03/06 13:59:01 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	handle_pointer(va_list args)
{
	void				*p;
	unsigned long long	llp;

	p = va_arg (args, void *);
	llp = (unsigned long long)p;
	if (p)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base(llp, "0123456789abcdef") + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}

static int	handle_str(va_list args)
{
	const char	*s;

	s = va_arg (args, const char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	if (ft_strlen(s))
		return (ft_strlen(s));
	else
		return (-1);
}

static int	format_recognition(const char *ptr, va_list args)
{
	if (*ptr == 'c')
		return (ft_putchar((const unsigned char)(va_arg(args, int))));
	else if (*ptr == 's')
		return (handle_str(args));
	else if (*ptr == 'p')
		return (handle_pointer(args));
	else if (*ptr == 'd' || *ptr == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (*ptr == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (*ptr == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*ptr == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*ptr == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;	
	int			i;
	int			count;
	const char	*ptr;

	va_start(args, format);
	count = 0;
	ptr = format;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			i = format_recognition(ptr + 1, args);
			count += i * (i > 0);
			if (i != 0)
			{
				ptr += 2;
				continue ;
			}
		}
		count += ft_putchar(*(ptr++));
	}
	va_end(args);
	return (count);
}
