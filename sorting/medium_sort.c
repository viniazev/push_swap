/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:17:25 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/14 17:59:18 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_move	find_cheapest_in_chunk(t_ps *ps, t_chunk chunk)
{
	t_node	*node;
	t_move	best;
	t_move	atual;

	node = ps->a.top;
	best.node = NULL;
	while (node)
	{
		if (node->index >= chunk.start && node->index <= chunk.end)
		{
			atual = move_cost(ps, node);
			if (best.node == NULL)
				best = atual;
			else if (atual.total_cost < best.total_cost)
				best = atual;
		}
		node = node->next;
	}
	return (best);
}

void	chunk_sort(t_ps *ps, t_chunk *chunk)
{
	t_move	move;

	while (ps->a.size > 0)
	{
		move = find_cheapest_in_chunk(ps, *chunk);
		if (move.node != NULL)
		{
			execute_rotation(ps, move);
			pb(ps);
		}
		else
		{
			(*chunk).start += (*chunk).size;
			(*chunk).end += (*chunk).size;
		}
	}
	rotate_to_position(ps, &ps->b, find_position(&ps->b, find_max(&ps->b)));
}

void	medium_sort(t_ps *ps)
{
	t_chunk	chunk;
	int		total_chunks;

	if (ps->a.size == 0)
		return ;
	if (ps->a.size <= 5)
		return (small_sort(ps));
	total_chunks = (ft_sqrt(ps->a.size) - 1) * 16; // TODO: encontrar proporcao ideal.
	chunk.size = total_chunks;
	if (ps->a.size % total_chunks != 0)
		chunk.size++;
	chunk.start = 0;
	chunk.end = chunk.size - 1;
	chunk_sort(ps, &chunk);
	while (ps->b.size > 0)
		pa(ps);
}

/*
versao de testes, estava tentando otimizar,
	mas como estava tomando muito trabalho decidi reverter para a versao anterior
e deixar essa comentada, se der tempo tentarei seguir com a comentada.

t_rotation	get_b_rotation(t_chunk chunk, int index)
{
	t_rotation	rotation;
	int			middle;

	middle = (chunk.start + chunk.end) / 2;
	rotation.cost = 0;
	rotation.position = 0;
	rotation.direction = ROTATE;
	if (index <= middle)
		rotation.cost = 1;
	return (rotation);
}

t_move	chunk_move_cost(t_ps *ps, t_node *node, t_chunk chunk)
{
	t_move	move;
	int		position_a;

	move.node = node;
	position_a = find_position(&ps->a, node->index);
	move.a = get_rotation_cost(&ps->a, position_a);
	move.b = get_b_rotation(chunk, node->index);
	move.total_cost = move.a.cost + move.b.cost;
	return (move);
}

t_move	find_cheapest_in_chunk(t_ps *ps, t_chunk chunk)
{
	t_node	*node;
	t_move	best;
	t_move	atual;

	node = ps->a.top;
	best.node = NULL;
	while (node)
	{
		if (node->index >= chunk.start && node->index <= chunk.end)
		{
			atual = chunk_move_cost(ps, node, chunk);
			if (best.node == NULL)
				best = atual;
			else if (atual.total_cost < best.total_cost)
				best = atual;
		}
		node = node->next;
	}
	return (best);
}

void	chunk_sort(t_ps *ps, t_chunk chunk)
{
	t_move	move;

	// int		chunk_atual;
	// chunk_atual = 0;
	while (ps->a.size > 0)
	{
		move = find_cheapest_in_chunk(ps, chunk);
		if (move.node != NULL)
		{
			execute_rotation_a(ps, &ps->a, move.a);
			pb(ps);
			// if (move.b.cost)
			// 	rb(ps);
		}
		else
		{
			// printf("chunk %i: \n", chunk_atual);
			// print_stack(ps, ps->b);
			chunk.start += chunk.size;
			chunk.end += chunk.size;
			// chunk_atual++;
		}
	}
}

void	medium_sort(t_ps *ps)
{
	int			max;
	t_chunk		chunk;
	int			total_chunks;
	t_rotation	rotation_b;
	int			position;

	if (ps->a.size == 0)
		return ;
	if (ps->a.size <= 5)
		return (small_sort(ps));
	total_chunks = ft_sqrt(ps->a.size);
	chunk.size = ps->a.size / total_chunks;
	chunk.start = 0;
	chunk.end = chunk.size - 1;
	chunk_sort(ps, chunk);
	while (ps->b.size > 0)
	{
		max = find_max_in_chunk(&ps->b, chunk.start, chunk.end);
		if (max == -1)
		{
			chunk.start -= chunk.size;
			chunk.end -= chunk.size;
			continue ;
		}
		position = find_position(&ps->b, max);
		rotation_b = get_rotation_cost(&ps->b, position);
		execute_rotation_a(ps, &ps->b, rotation_b);
		pa(ps);
	}
}
*/