/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:58:38 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/25 17:36:19 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	slen;

	slen = ft_strlen(s) + 1;
	str = malloc(slen * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, slen);
	return (str);
}
