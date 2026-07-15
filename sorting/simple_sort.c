/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/15 02:07:51 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insertion_sort(t_ps *ps)
{
	int		target;
	int		pos;
	int		current;
	t_node	*node;

	node = ps->a.top;
	while (ps->a.size > 0)
	{
		current = node->index;
		target = find_insert_position(&ps->b, current);
		node = node->next;
		if (!node)
			break ;
	}
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
