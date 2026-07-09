/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:32 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/09 21:25:40 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_ps *ps)
{
	if (ps->a.size != 2)
		return ;
	if (ps->a.top->index > ps->a.top->next->index)
		sa(ps);
}
/* eu removi a checagem de tamanho do stack nessa funcao,
	posteriormente um novo arquivo que
chama as funcoes de small_sort sera escrito e essas funcoes de aqui serão chamadas apenas se
cumprirem os requisitos de tamanho de stack,
	sort_three por exemplo só deve ser chamado se e
somente se o stack->size = 3.
*/

void	sort_three(t_ps *ps)
{
	int	top;
	int	mid;
	int	bot;

	top = ps->a.top->index;
	mid = ps->a.top->next->index;
	bot = ps->a.bottom->index;
	if (stack_is_sorted(&ps->a))
		return ;
	else if (top > mid && mid > bot)
	{
		ra(ps);
		sa(ps);
	}
	else if (mid > top && bot > top)
	{
		rra(ps);
		sa(ps);
	}
	else if (top > mid && top > bot)
		ra(ps);
	else if (mid > top && mid > bot)
		rra(ps);
	else if (bot > top && bot > mid)
		sa(ps);
}

void	sort_four(t_ps *ps)
{
	int	position;

	position = find_position(ps, 0);
	bring_index_to_top(ps, &ps->a, 0);
	pb(ps);
	sort_three(ps);
	pa(ps);
}

void	sort_five(t_ps *ps)
{
	int	position;

	position = find_position(ps, 0);
	bring_index_to_top(ps, &ps->a, 0);
	pb(ps);
	position = find_position(ps, 1);
	bring_index_to_top(ps, &ps->a, 1);
	pb(ps);
	sort_three(ps);
	pa(ps);
	pa(ps);
}
