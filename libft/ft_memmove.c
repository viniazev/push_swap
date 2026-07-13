/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:38:54 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/25 16:56:18 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destine;
	const unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	destine = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (destine > source)
	{
		i = n;
		while (i > 0)
		{
			i--;
			destine[i] = source[i];
		}
	}
	else
		ft_memcpy(destine, source, n);
	return (dest);
}
