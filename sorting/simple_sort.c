/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/18 00:40:56 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_find_pivot(t_stack *stack)
{
	int	min;
	int	max;

	min = find_min(stack);
	max = find_max(stack);
	return ((min + (max - min) / 2));
}

void	insertion_sort(t_ps *ps)
{
	int		target;
	int		current;
	t_node	*node;
	int		max;

	node = ps->a.top;
	current = ps->a.top->index;
	while (ps->a.size > 0)
	{
		current = node->index;
		target = find_insert_position(&ps->b, current);
		bring_index_to_top(ps, &ps->b, target);
		pb(ps);
		node = node->next;
		if (!node)
			break ;
	}
	max = find_max(&ps->b);
	bring_index_to_top(ps, &ps->b, max);
	while (ps->b.size > 0)
		pa(ps);
}

void	simple_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return ;
	if (ps->a.size <= 5)
		return (sort_five(ps));
	pb(ps);
	insertion_sort(ps);
}
