/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:14:00 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/04 23:24:16 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->b.size == 0)
		return ;
	node = stack_pop_top(&ps->b);
	stack_add_top(&ps->a, node);
	if (ps->bench_mode == 1)
	{
		ps->bench->pa++;
		ps->bench->total++;
	}
}

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->a.size == 0)
		return ;
	node = stack_pop_top(&ps->a);
	stack_add_top(&ps->b, node);
	if (ps->bench_mode == 1)
	{
		ps->bench->pb++;
		ps->bench->total++;
	}
}
