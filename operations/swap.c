/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:02 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/11 19:29:32 by vinida-s         ###   ########.fr       */
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
	if (!ps->bench_mode)
		ft_printf("sa\n");
	else
		update_bench(ps, OP_SA);
}

void	sb(t_ps *ps)
{
	swap_top_two(&ps->b);
	if (!ps->bench_mode)
		ft_printf("sb\n");
	else
		update_bench(ps, OP_SB);
}

void	ss(t_ps *ps)
{
	swap_top_two(&ps->a);
	swap_top_two(&ps->b);
	if (!ps->bench_mode)
		ft_printf("ss\n");
	else
		update_bench(ps, OP_SS);
}
