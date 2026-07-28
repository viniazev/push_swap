/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/28 20:28:10 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_insert_position(t_stack *stack, int target)
{
	int		position;
	int		max;
	int		min;
	t_node	*node;

	node = stack->top;
	position = 0;
	max = find_max(stack);
	min = find_min(stack);
	if (target > max || target < min)
		return (find_position(stack, max));
	while (node && node->next)
	{
		if (target < node->index && target > node->next->index)
			return (position + 1);
		position++;
		node = node->next;
	}
	return (-1);
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
	int	target;
	int	current;

	while (ps->a.size > 0)
	{
		current = ps->a.top->index;
		target = find_insert_position(&ps->b, current);
		if (target == -1)
		{
			printf("find_insertion_sort retornou: %i", target);
			return ;
		}
		rotate_to_position(ps, &ps->b, target);
		pb(ps);
	}
}

void	simple_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return (error_exit(ps));
	if (ps->a.size <= 5)
		return (sort_five(ps));
	pb(ps);
	pb(ps);
	insertion_sort(ps);
	rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
	while (ps->b.size > 0)
		pa(ps);
}
