/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:43:39 by vinida-s          #+#    #+#             */
/*   Updated: 2026/06/26 15:16:40 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->a->size < 2)
		return ;
	node = stack_pop_bottom(ps->a);
	stack_add_top(ps->a, node);
}

void	rrb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->b->size < 2)
		return ;
	node = stack_pop_bottom(ps->b);
	stack_add_top(ps->b, node);
}

void	rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
}
