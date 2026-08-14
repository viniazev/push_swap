/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:17:47 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/14 01:16:51 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
		i++;
	return (i - 1);
}

int	ft_max_number(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	find_max_in_chunk(t_stack *stack, int start, int end)
{
	t_node	*node;
	int		max;

	node = stack->top;
	max = -1;
	while (node)
	{
		if (node->index >= start && node->index <= end)
		{
			if (node->index > max)
				max = node->index;
		}
		node = node->next;
	}
	return (max);
}
