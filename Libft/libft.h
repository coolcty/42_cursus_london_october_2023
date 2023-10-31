/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:01:48 by tochen            #+#    #+#             */
/*   Updated: 2023/10/30 12:01:52 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	ft_bzero(void *s, size_t n);

int	ft_isdigit(int c);
int ft_isascii(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
size_t ft_strlen(const char *s);
int strncmp(const char *s1, const char *s2, size_t n);
char *strrchr(const char *s, int c);