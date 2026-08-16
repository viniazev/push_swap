/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:17:38 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/16 23:27:24 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->size - 1;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_bit(t_ps *ps, int bit, int size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		if (((ps->a.top->index >> bit) & 1) == 0)
			pb(ps);
		else
			ra(ps);
		count++;
	}
	while (ps->b.size > 0)
		pa(ps);
}

void	radix_sort(t_ps *ps)
{
	int	bit;
	int	size;
	int	maxbits;

	maxbits = get_max_bits(&ps->a);
	bit = 0;
	size = ps->a.size;
	while (bit < maxbits)
	{
		if (stack_is_sorted(&ps->a))
			return ;
		radix_bit(ps, bit, size);
		bit++;
	}
}

void	complex_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return ;
	if (ps->a.size <= 5)
		return (small_sort(ps));
	radix_sort(ps);
	return ;
}
