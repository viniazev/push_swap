/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:45:05 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/11 19:29:54 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	if (!a || a->size == 0)
		return (0);
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_valid_int(const char *str)
{
	long	i;

	i = ft_atol_ps(str);
	return (i);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->index < node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}
