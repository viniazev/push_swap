/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:59:42 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/21 16:17:05 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char str[10] = "abcdefghi";

	printf("Antes: %s\n", str);

	ft_bzero(str, 4);

	printf("Depois: %s\n", str);

	for (int i = 0; i < 10; i++)
		printf("%d ", str[i]); // ver os bytes

	return (0);
} */
