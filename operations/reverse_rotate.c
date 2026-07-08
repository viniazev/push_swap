/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:43:39 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/09 00:25:09 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack_pop_bottom(&stack);
	stack_add_top(&stack, node);
}

void	rra(t_ps *ps)
{
	ps_reverse_rotate(&ps->a);
	if (ps->bench_mode == 1)
	{
		ps->bench->rra++;
		ps->bench->total++;
	}
}

void	rrb(t_ps *ps)
{
	ps_reverse_rotate(&ps->b);
	if (ps->bench_mode == 1)
	{
		ps->bench->rrb++;
		ps->bench->total++;
	}
}

void	rrr(t_ps *ps)
{
	ps_reverse_rotate(&ps->a);
	ps_reverse_rotate(&ps->b);
	if (ps->bench_mode == 1)
	{
		ps->bench->rrr++;
		ps->bench->total++;
	}
}
