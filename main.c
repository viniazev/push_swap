/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:33:21 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/17 00:25:32 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_ps *ps, t_stack stack)
{
	t_node	*node;

	if (ps->a.top || ps->b.top)
	{
		node = stack.top;
		while (node->next != NULL)
		{
			printf("%i\n", node->index);
			node = node->next;
		}
		printf("%i\n", node->index);
		printf("fim da impressao\n");
	}
}

void	strategy_chooser(t_ps *ps)
{
	if (ps->strategy == ADAPTIVE)
		adaptive_sort(ps);
	else if (ps->strategy == SIMPLE)
		simple_sort(ps);
	else if (ps->strategy == MEDIUM)
		medium_sort(ps);
	else if (ps->strategy == COMPLEX)
		complex_sort(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	stack_init(&ps);
	if (!parse_args(argc, argv, &ps))
		return (error_exit(&ps));
	if (!stack_is_sorted(&ps.a))
	{
		strategy_chooser(&ps);
		if (ps.a.size == 1)
			return (0);
	}
	if (ps.bench_mode == 1 && ps.a.top)
		print_bench(&ps);
	//	imprimir o stack para testes, remover antes de entregar
	// print_stack(&ps, ps.a);
	if (ps.a.top || ps.b.top)
		free_all(&ps);
	return (0);
}
