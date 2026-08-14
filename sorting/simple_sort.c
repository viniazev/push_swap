/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/10 23:09:58 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_rotation(t_ps *ps, t_move move)
{
	while ((move.a.direction == move.b.direction) && move.a.cost > 0
		&& move.b.cost > 0)
	{
		rotate_or_reverse(ps, move);
		move.a.cost--;
		move.b.cost--;
	}
	while (move.a.cost)
	{
		if (move.a.direction == ROTATE)
			rotate_stack(ps, &ps->a);
		else
			reverse_rotate_stack(ps, &ps->a);
		move.a.cost--;
	}
	while (move.b.cost)
	{
		if (move.b.direction == ROTATE)
			rotate_stack(ps, &ps->b);
		else
			reverse_rotate_stack(ps, &ps->b);
		move.b.cost--;
	}
}

int	find_insert_position(t_stack *stack, int target)
{
	int		position;
	t_node	*current;
	t_node	*next;

	position = 0;
	current = stack->top;
	if (stack->size <= 1)
		return (position);
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = stack->top;
		if ((current->index > next->index && target < current->index
				&& target > next->index) || (current->index < next->index
				&& (target > next->index || target < current->index)))
			return (position + 1);
		current = current->next;
		position++;
	}
	return (0);
}

void	rotate_to_position(t_ps *ps, t_stack *stack, int position)
{
	if (position <= stack->size / 2)
	{
		while (position--)
			rotate_stack(ps, stack);
	}
	else
	{
		position = stack->size - position;
		while (position--)
			reverse_rotate_stack(ps, stack);
	}
}

void	insertion_sort(t_ps *ps)
{
	t_move	move;

	pb(ps);
	pb(ps);
	if (ps->b.top->index < ps->b.top->next->index)
		sb(ps);
	while (ps->a.size > 0)
	{
		move = find_cheapest_node(ps);
		execute_rotation(ps, move);
		pb(ps);
	}
	rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
}

void	simple_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return ;
	if (ps->a.size <= 5)
		return (small_sort(ps));
	insertion_sort(ps);
	while (ps->b.size > 0)
		pa(ps);
}
