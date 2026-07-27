/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/27 19:02:30 by vinida-s         ###   ########.fr       */
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
	int		pivot;
	t_node	*node;

	node = ps->b.top;
	current = ps->a.top->index;
	target = 0;
	pivot = 0;
	while (node->next != NULL)
	{

	}
	while (ps->b.size > 0)
		pa(ps);
}

void	simple_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return (error_exit(ps));
	if (ps->a.size <= 5)
		return (sort_five(ps));
	pb(ps);
	insertion_sort(ps);
}
