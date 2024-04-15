/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:59:37 by tochen            #+#    #+#             */
/*   Updated: 2023/11/15 00:05:55 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned char	uc;

	uc = (unsigned char)c;
	res = 0;
	while (*s)
	{
		if (*s == uc)
			res = (char *)s;
		s++;
	}
	if (uc == 0)
		res = (char *)s;
	return (res);
}
