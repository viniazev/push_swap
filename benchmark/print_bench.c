/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:15:19 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/13 19:59:32 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_bench(t_ps *ps)
{
	ft_printf("Benchmark Results:\n");
	ft_printf("----------------------\n");
	ft_printf("Total Operations: %l\n", ps->bench.total);
	ft_printf("Strategy: %d\n", ps->strategy);
	ft_printf("Disorder: %d %%\n", (float)ps->bench.disorder * 10);
	ft_printf("sa: %l\n", ps->bench.sa);
	ft_printf("sb: %l\n", ps->bench.sb);
	ft_printf("ss: %l\n", ps->bench.ss);
	ft_printf("pa: %l\n", ps->bench.pa);
	ft_printf("pb: %l\n", ps->bench.pb);
	ft_printf("ra: %l\n", ps->bench.ra);
	ft_printf("rb: %l\n", ps->bench.rb);
	ft_printf("rr: %l\n", ps->bench.rr);
	ft_printf("rra: %l\n", ps->bench.rra);
	ft_printf("rrb: %l\n", ps->bench.rrb);
	ft_printf("rrr: %l\n", ps->bench.rrr);
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
	else if (op == OP_RB)
		ps->bench.rb++;
	else if (op == OP_RRR)
		ps->bench.rrr++;
	ps->bench.total++;
}
