/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:13:57 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/09 21:01:02 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack_pop_top(stack);
	stack_add_bottom(stack, node);
}

void	ra(t_ps *ps)
{
	ps_rotate(&ps->a);
	if (ps->bench_mode == 1)
	{
		ps->bench->ra++;
		ps->bench->total++;
	}
}

void	rb(t_ps *ps)
{
	ps_rotate(&ps->b);
	if (ps->bench_mode == 1)
	{
		ps->bench->rb++;
		ps->bench->total++;
	}
}

void	rr(t_ps *ps)
{
	ps_rotate(&ps->a);
	ps_rotate(&ps->b);
	if (ps->bench_mode == 1)
	{
		ps->bench->rr++;
		ps->bench->total++;
	}
}

void	rotate_stack(t_ps *ps, t_stack *stack)
{

	if (stack == &ps->a)
		ra(ps);
	else
		rb(ps);
}
