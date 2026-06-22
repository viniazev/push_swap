/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinicius <vinicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:19:15 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/22 18:43:54 by vinicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_bottom(t_stack *stack, t_node *node)
{
	if (!stack->bottom)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	stack_add_top(t_stack *stack, t_node *node)
{
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}
