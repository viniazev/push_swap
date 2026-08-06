/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:49 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/06 00:54:07 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_insert_position(t_stack *stack, int target)
{
	int		position;
	int		max;
	int		min;
	t_node	*node;

	node = stack->top;
	position = 0;
	max = find_max(stack);
	min = find_min(stack);
	if (target > max)
		return (0);
	if (target < min)
		return (stack->size);
	while (node && node->next)
	{
		if (target < node->index && target > node->next->index)
			return (position + 1);
		position++;
		node = node->next;
	}
	return (-1);
}

void	rotate_to_position(t_ps *ps, t_stack *stack, int position)
{
	if (position <= stack->size / 2)
	{
		while (position--)
			rotate_stack(ps, stack);
	}
	else
	{
		position = stack->size - position;
		while (position--)
			reverse_rotate_stack(ps, stack);
	}
}

void	insertion_sort(t_ps *ps)
{
	int	target;
	int	current;

	rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
	while (ps->a.size > 0)
	{
		current = ps->a.top->index; //encontrar valor mais barato, ao inves de usar o topo de A
		target = find_insert_position(&ps->b, current);
		if (target == -1)
			return (error_exit(ps));
		rotate_to_position(ps, &ps->b, target);
		pb(ps);
		rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
	}
}
/* na linha 69 tem uma segunda chamada para a funcao rotate to position, o que faz com que o stack b esteja sempre em ordem decrescente,
isso é muito ineficiente e precisa ser alterado, posso manter o stack ordenado rotativamente e entao rotacionar o stack a para encontrar
uma posicao mais favoravel.
*/

void	simple_sort(t_ps *ps)
{
	if (ps->a.size == 0)
		return (error_exit(ps));
	if (ps->a.size <= 5)
		return (small_sort(ps));
	pb(ps);
	pb(ps);
	insertion_sort(ps);
	rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
	while (ps->b.size > 0)
		pa(ps);
}
