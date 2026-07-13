/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:01:58 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/22 19:47:29 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char str[] = "ABCDEFGd";
	const int chars[] = {'D', 'd'};
	for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
	{
		const int c = chars[i];
		const char *ps = ft_memchr(str, c, strlen(str));
		ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)
			: printf ("character '%c'(%i) not found\n", c, c);
	}
	return (0);
}*/
