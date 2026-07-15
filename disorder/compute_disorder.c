/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:01 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/15 00:01:43 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_node	*current_node;
	t_node	*other_node;

	total_pairs = 0;
	mistakes = 0;
	current_node = a->top;
	while (current_node)
	{
		other_node = current_node->next;
		while (other_node)
		{
			total_pairs++;
			if (current_node->index > other_node->index)
				mistakes++;
			other_node = other_node->next;
		}
		current_node = current_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}
