/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:19 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/14 22:53:21 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_strategy(int strategy)
{
	if (strategy == 0)
		ft_printf("[bench] strategy: Simple / O(n2)\n");
	else if (strategy == 1)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (strategy == 2)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	else
		ft_printf("[bench] strategy: Adaptative / O(n log n)\n");
}

void	print_bench(t_ps *ps) //TODO: imprimir o bench no stderr ao inves do stdin
{
	ft_printf("[bench] disorder: %f%%\n", ps->bench.disorder);
	print_strategy(ps->strategy); // TODO: IMPRIMIR A STRATEGY DE ACORDO COM O SUBJECT
	ft_printf("[bench] total_ops: %l\n", ps->bench.total);
	ft_printf("[bench] sa:  %l  sb:  %l  ss:  %l  pa:  %l  pb:  %l\n",
		ps->bench.sa, ps->bench.sb, ps->bench.ss, ps->bench.pa, ps->bench.pb);
	ft_printf("[bench] ra:  %l  rb:  %l  rr:  %l  rra: %l  rrb: %l  rrr: %l\n",
		ps->bench.ra, ps->bench.rb, ps->bench.rr, ps->bench.rra, ps->bench.rrb,
		ps->bench.rrr);
}

void	update_bench(t_ps *ps, t_op op)
{
	if (op == OP_PA)
		ps->bench.pa++;
	else if (op == OP_PB)
		ps->bench.pb++;
	else if (op == OP_SA)
		ps->bench.sa++;
	else if (op == OP_SB)
		ps->bench.sb++;
	else if (op == OP_SS)
		ps->bench.ss++;
	else if (op == OP_RA)
		ps->bench.ra++;
	else if (op == OP_RB)
		ps->bench.rb++;
	else if (op == OP_RR)
		ps->bench.rr++;
	else if (op == OP_RRA)
		ps->bench.rra++;
	else if (op == OP_RRB)
		ps->bench.rrb++;
	else if (op == OP_RRR)
		ps->bench.rrr++;
	ps->bench.total++;
}
