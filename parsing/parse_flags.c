/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:13:08 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/29 16:53:15 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(int argc, char **argv, t_ps *ps)
{
	int	i;

	i = 1;
	ps->bench_mode = 0;
	ps->strategy = ADAPTIVE;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			ps->strategy = SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			ps->strategy = MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			ps->strategy = COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			ps->strategy = ADAPTIVE;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			ps->bench_mode = 1;
		else
			break ;
		i++;
	}
	return (i);
}
