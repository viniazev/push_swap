/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:13:57 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/17 00:13:44 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_putstr_fd("ra\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_RA);
}

void	rb(t_ps *ps)
{
	ps_rotate(&ps->b);
	ft_putstr_fd("rb\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_RB);
}

void	rr(t_ps *ps)
{
	ps_rotate(&ps->a);
	ps_rotate(&ps->b);
	ft_putstr_fd("rr\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_RR);
}

void	rotate_stack(t_ps *ps, t_stack *stack)
{
	if (stack == &ps->a)
		ra(ps);
	else
		rb(ps);
}
