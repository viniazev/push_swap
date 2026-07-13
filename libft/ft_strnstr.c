/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:07:41 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/24 21:09:39 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char *)big);
	while (*big != '\0' && len >= lenlittle)
	{
		if (ft_memcmp(big, little, lenlittle) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*texto = "Olá, isto é um teste simples";
	const char	*busca = "um";
	size_t		limite;
	char		*resultado_ft;

	limite = 25;
	resultado_ft = ft_strnstr(texto, busca, limite);
	if (resultado_ft)
		printf("ft_strnstr encontrou: %s\n", resultado_ft);
	else
		printf("ft_strnstr não encontrou nada.\n");
	return (0);
} */
