/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:00 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/17 00:10:53 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->b.size == 0)
		return ;
	node = stack_pop_top(&ps->b);
	stack_add_top(&ps->a, node);
	ft_putstr_fd("pa\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_PA);
}

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->a.size == 0)
		return ;
	node = stack_pop_top(&ps->a);
	stack_add_top(&ps->b, node);
	ft_putstr_fd("pb\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_PB);
}
