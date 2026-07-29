/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:30:32 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/29 19:52:00 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*node;

	node = stack->top;
	min = node->index;
	while (node)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*node;

	node = stack->top;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

int	find_position(t_stack *stack, int index)
{
	t_node	*node;
	int		position;

	node = stack->top;
	position = 0;
	while (node)
	{
		if (node->index == index)
			return (position);
		position++;
		node = node->next;
	}
	return (-1);
}

void	bring_index_to_top(t_ps *ps, t_stack *stack, int target_index)
{
	int	position;

	position = find_position(stack, target_index);
	if (position == -1)
		return ;
	if (position <= stack->size / 2)
	{
		while (position != 0)
		{
			rotate_stack(ps, stack);
			position = find_position(stack, target_index);
		}
	}
	else
	{
		while (position != 0)
		{
			reverse_rotate_stack(ps, stack);
			position = find_position(stack, target_index);
		}
	}
}
