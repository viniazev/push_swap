/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:25:56 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/25 20:08:29 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	size_t	lenstrs;

	if (!s1 || !s2)
		return (NULL);
	lenstrs = ft_strlen(s1) + ft_strlen(s2) + 1;
	catstr = malloc(lenstrs);
	if (!catstr)
		return (NULL);
	catstr[0] = '\0';
	ft_strlcat(catstr, s1, lenstrs);
	ft_strlcat(catstr, s2, lenstrs);
	return (catstr);
}
