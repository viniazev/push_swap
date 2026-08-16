/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:02 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/17 00:12:09 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	third = second->next;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (third)
		third->prev = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_ps *ps)
{
	swap_top_two(&ps->a);
	ft_putstr_fd("sa\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_SA);
}

void	sb(t_ps *ps)
{
	swap_top_two(&ps->b);
	ft_putstr_fd("sb\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_SB);
}

void	ss(t_ps *ps)
{
	swap_top_two(&ps->a);
	swap_top_two(&ps->b);
	ft_putstr_fd("ss\n", 1);
	if (ps->bench_mode)
		update_bench(ps, OP_SS);
}
