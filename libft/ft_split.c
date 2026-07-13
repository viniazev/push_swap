/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:42:14 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/13 16:40:17 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_getstrs(char const *s, size_t *i, char c)
{
	size_t	start;
	char	*str;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	str = ft_substr(s, start, *i - start);
	if (!str)
		return (NULL);
	return (str);
}

void	ft_freeall(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static int	ft_separate(char const *s, char c, char **arrstrs, size_t *j)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arrstrs[*j] = ft_getstrs(s, &i, c);
			if (!arrstrs[*j])
			{
				ft_freeall(arrstrs, *j);
				return (0);
			}
			(*j)++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arrstrs;
	size_t	j;

	if (!s)
		return (NULL);
	arrstrs = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!arrstrs)
		return (NULL);
	j = 0;
	if (!ft_separate(s, c, arrstrs, &j))
		return (NULL);
	arrstrs[j] = NULL;
	return (arrstrs);
}
