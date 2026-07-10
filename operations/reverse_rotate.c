/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:43:39 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/10 21:29:40 by vinida-s         ###   ########.fr       */
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
	if (!ps->bench_mode)
		ft_printf("rra\n");
	else
		update_bench(ps, OP_RRA);
}

void	rrb(t_ps *ps)
{
	ps_reverse_rotate(&ps->b);
	if (!ps->bench_mode)
		ft_printf("rrb\n");
	else
		update_bench(ps, OP_RRB);
}

void	rrr(t_ps *ps)
{
	ps_reverse_rotate(&ps->a);
	ps_reverse_rotate(&ps->b);
	if (!ps->bench_mode)
		ft_printf("rrr\n");
	else
		update_bench(ps, OP_RRR);
}

void	reverse_rotate_stack(t_ps *ps, t_stack *stack)
{
	if (stack == &ps->a)
		rra(ps);
	else
		rrb(ps);
}
