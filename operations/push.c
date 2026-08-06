/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:00 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/05 23:51:53 by vinida-s         ###   ########.fr       */
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
	if (!ps->bench_mode)
		ft_printf("pa\n");
	else
		update_bench(ps, OP_PA);
}

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->a.size == 0)
		return ;
	node = stack_pop_top(&ps->a);
	stack_add_top(&ps->b, node);
	if (!ps->bench_mode)
		ft_printf("pb\n");
	else
		update_bench(ps, OP_PB);
}
