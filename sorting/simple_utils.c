/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:25:35 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/07 02:50:18 by vinida-s         ###   ########.fr       */
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

int	calculate_total_cost(int cost_a, int cost_b)
{
	if (cost_a >= cost_b)
		return (cost_a);
	else
		return (cost_b);
}

t_move	move_cost(t_ps *ps, t_node *node)
{
	t_move	move;
	int		position_a;
	int		position_b;

	move.node = node;
	position_a = find_position(&ps->a, node->index);
	move.a = get_rotation_cost(&ps->a, position_a);
	position_b = find_insert_position(&ps->b, node->index);
	move.b = get_rotation_cost(&ps->b, position_b);
	if (move.a.direction == move.b.direction)
		move.total_cost = calculate_total_cost(move.a.cost, move.b.cost);
	else
		move.total_cost = move.a.cost + move.b.cost;
	return (move);
}

t_move	find_cheapest_node(t_ps *ps)
{
	t_node	*node;
	t_move	best;
	t_move	atual;

	node = ps->a.top;
	best = move_cost(ps, node);
	while (node)
	{
		atual = move_cost(ps, node);
		if (atual.total_cost < best.total_cost)
			best = atual;
		node = node->next;
	}
	return (best);
}
/*
void	execute_rotation(t_ps *ps, t_stack *stack, t_rotation rotation)
{
	int	cost;

	cost = rotation.cost;
	while (cost > 0)
	{
		if (rotation.direction == ROTATE)
			rotate_stack(ps, stack);
		else
			reverse_rotate_stack(ps, stack);
		cost--;
	}
}
*/

void	rotate_or_reverse(t_ps *ps, t_move move)
{
	if (move.a.direction == ROTATE && move.b.direction == ROTATE)
		rr(ps);
	else
		rrr(ps);
}
