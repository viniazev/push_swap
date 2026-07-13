/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:12:52 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/13 17:28:51 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_ps *ps)
{
	ps->a.top = NULL;
	ps->a.bottom = NULL;
	ps->a.size = 0;
	ps->b.top = NULL;
	ps->b.bottom = NULL;
	ps->b.size = 0;
	ps->strategy = ADAPTIVE;
	ps->index = 0;
	ps->bench_mode = 0;
	ps->bench.total = 0;
	ps->bench.sa = 0;
	ps->bench.sb = 0;
	ps->bench.ss = 0;
	ps->bench.pa = 0;
	ps->bench.pb = 0;
	ps->bench.ra = 0;
	ps->bench.rb = 0;
	ps->bench.rr = 0;
	ps->bench.rra = 0;
	ps->bench.rrb = 0;
	ps->bench.rrr = 0;
}

int	parse_number(char *token, t_ps *ps)
{
	long	value;
	t_node	*node;

	if (!is_valid_int(token))
		return (0);
	value = ft_atol_ps(token);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	node = node_new((int)value);
	if (!node)
		return (0);
	stack_add_bottom(&ps->a, node);
	return (1);
}

int	parse_args(int argc, char **argv, t_ps *ps)
{
	int		i;
	int		j;
	char	**tokens;

	i = parse_flags(argc, argv, ps);
	j = -1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			tokens = ft_split(argv[i], ' ');
			while (tokens[++j])
				if (!parse_number(tokens[j], ps))
					break ;
			ft_freeall(tokens, j);
		}
		else
			parse_number(argv[i], ps);
		i++;
	}
	if (has_duplicates(&ps->a))
		return (0);
	assign_indices(&ps->a);
	ps->bench.disorder = compute_disorder(&ps->a);
	return (1);
}
/*
	retornar erro e free se necessario quando a funcao falhar e retornar 0


*/