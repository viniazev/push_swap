/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:01 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/11 19:28:11 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_stack *a)
{
	double	mistakes;
	double	total_pairs;
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
