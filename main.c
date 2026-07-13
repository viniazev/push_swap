/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:33:21 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/12 01:31:17 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps			ps;

	if (argc < 2)
		return (write(1, "Error.", 6));
	if (!parse_args(argc - 1, argv + 1, &ps))
		return (error_exit(&ps), 0);
	/*já que a estrategia foi selecionada no parse args,
		devo agr iniciar a ordenacao*/
	if (ps.strategy == ADAPTIVE)
		adaptative_sort(&ps);
	else if (ps.strategy == SIMPLE)
		return (0);
	else if (ps.strategy == MEDIUM)
		return (0);
	else
		return (0);
	/*caso bench seja selecionado,
		imprimir o bench ao final e nao imprimir as operacoes*/
	if (ps.bench_mode == 1)
		print_bench(&ps);
	return (0);
}
