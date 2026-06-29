/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:13:57 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/26 15:47:22 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_node	*node;

	if (!ps->a || ps->a->size < 2)
		return ;
	node = stack_pop_top(ps->a);
	stack_add_bottom(ps->a, node);
}

void	rb(t_ps *ps)
{
	t_node	*node;

	if (!ps->b || ps->b->size < 2)
		return ;
	node = stack_pop_top(ps->b);
	stack_add_bottom(ps->b, node);
}

void	rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}
