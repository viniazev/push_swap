/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:30:32 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/10 19:50:38 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
