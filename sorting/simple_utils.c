/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:25:35 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/06 02:03:09 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_rotation	get_rotation_cost(t_stack *stack, int position)
{
	t_rotation	rotation;

	rotation.position = position;
	if (position <= stack->size / 2)
	{
		rotation.cost = position;
		rotation.direction = ROTATE;
	}
	else
	{
		rotation.cost = stack->size - position;
		rotation.direction = REVERSE_ROTATE;
	}
	return (rotation);
}

int	move_cost(t_ps *ps, t_node *node)
{
}

t_node	*find_cheapest_node(t_ps *ps)
{
	t_rotation 	rotation;
	int			position;
	t_node		*node;
	
	position = 0;
	node = ps->a.top;
	while (node)
	{
		rotation = ;
	}
}
