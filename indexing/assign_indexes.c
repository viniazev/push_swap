/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:35 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/02 22:10:09 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *a)
{
	int		count;
	t_node	*current_node;
	t_node	*other_node;
	
	current_node = a->top;
	while (current_node)
	{
		count = 0;
		other_node = a->top;
		while (other_node)
		{
			if (other_node->value < current_node->value)
				count++;
			other_node = other_node->next;
		}
		current_node->index = count;
		current_node = current_node->next;
	}
}
