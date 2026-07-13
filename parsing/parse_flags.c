/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:13:08 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/12 01:37:04 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse_flags(int argc, char **argv, t_ps *ps)
{
	int	i;

	i = 1;
	ps->bench_mode = 1;
	ps->index = 0;
	ps->strategy = ADAPTIVE;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			ps->strategy = SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			ps->strategy = MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			ps->strategy = COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			ps->strategy = ADAPTIVE;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0)
			ps->bench_mode = 1;
		else
			return (write(2, "Error.", 6), 0);
		i++;
	}
	if (i == argc)
		return (write(2, "Error.", 6), 0);
	return (ps->index = i, i);
}
