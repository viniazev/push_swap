/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:12:52 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/02 20:30:50 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_number(char *token, t_ps *ps)
{
	long	value;
	t_node	*node;

	if (!is_valid_int(token))
		return (ps->strategy = ERROR, 0);
	value = ft_atol_ps(token);
	if (value > INT_MAX || value < INT_MIN)
		return (ps->strategy = ERROR, 0);
	node = node_new((int)value);
	if (!node)
		return (ps->strategy = ERROR, 0);
	stack_add_bottom(&ps->a, node);
	return (1);
}

int	parse_args(t_ps *ps, int argc, char **argv)
{
	int		i;
	int		j;
	char	**tokens;

	i = parse_flags(ps, argc, argv);
	j = -1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			tokens = ft_split(argv[i], ' ');
			while (tokens[++j])
				if (!parse_number(tokens[j], ps))
					return (ps->strategy = ERROR, 0);
			free(tokens);
		}
		else
			parse_number(argv[i], ps);
		i++;
	}
	if (has_duplicates(&ps->a))
		return (ps->strategy = ERROR, 0);
	assign_indices(&ps->a);
	ps->bench->disorder = compute_disorder(&ps->a);
	return (1);
}
