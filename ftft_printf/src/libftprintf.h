/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:56:55 by tochen            #+#    #+#             */
/*   Updated: 2024/03/06 13:56:55 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_putchar(char c);
int		ft_strlen(const char *str);
int		ft_putnbr_base(unsigned long long nbr, char *base);
int		ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);

#endif
