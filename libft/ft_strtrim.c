/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:10:36 by vinida-s          #+#    #+#             */
/*   Updated: 2026/04/29 19:22:05 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totrim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	lenstr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_totrim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_totrim(s1[end - 1], set))
		end--;
	lenstr = end - start;
	str = malloc(lenstr * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], lenstr + 1);
	return (str);
}
