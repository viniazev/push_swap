/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:33:21 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/10 21:55:22 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps			ps;

	if (argc < 2)
		return (write(1, "Error.", 6));
	if (!parse_args(&ps, argc, argv))
		return (error_exit(&ps), 0);
	/*já que a estrategia foi selecionada no parse args,
		devo agr iniciar a ordenacao*/
	if (ps.strategy == ADAPTIVE)
		adaptative_sort(&ps);
	else if (ps.strategy == SIMPLE)
		return ;
	else if (ps.strategy == MEDIUM)
		return ;
	else
		return ;
	/*caso bench seja selecionado,
		imprimir o bench ao final e nao imprimir as operacoes*/
	if (ps.bench_mode == 1)
		print_bench(&ps);
	return (0);
}
