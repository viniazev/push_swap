/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:02 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/26 15:13:44 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	swap_top_two(ps->a);
}

void	sb(t_ps *ps)
{
	swap_top_two(ps->b);
}

void	ss(t_ps *ps)
{
	swap_top_two(ps->a);
	swap_top_two(ps->b);
}
