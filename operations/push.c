/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinicius <vinicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:00 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/25 20:23:22 by vinicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->b->size == 0)
		return ;
	node = stack_pop_top(ps->b);
	stack_add_top(ps->a, node);
}

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->a->size == 0)
		return ;
	node = stack_pop_top(ps->a);
	stack_add_top(ps->b, node);
}
