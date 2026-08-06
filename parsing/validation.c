/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:45:05 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/06 18:42:35 by vinida-s         ###   ########.fr       */
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
	int	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && ft_isdigit(str[1]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next != NULL)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}
