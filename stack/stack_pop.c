/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:19:27 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/11 19:30:53 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	if (stack->top == stack->bottom)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->bottom)
		return (NULL);
	node = stack->bottom;
	if (stack->top == stack->bottom)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
