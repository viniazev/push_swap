/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:33:21 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/31 23:10:08 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps			ps;
	t_node			*node;
	
	if (argc < 2)
		return (write(2, "Error.", 6));
	stack_init(&ps);
	if (!parse_args(argc, argv, &ps))
		return (error_exit(&ps), 0);
	/*já que a estrategia foi selecionada no parse args,
		devo agr iniciar a ordenacao*/
	ft_printf("Strategy selected: %d\n", ps.strategy);
	ft_printf("Bench mode: %d\n", ps.bench_mode);
	if (stack_is_sorted(&ps.a))
		return (error_exit(&ps), printf("stack sorted\n"));
	if (ps.strategy == ADAPTIVE)
		adaptative_sort(&ps);
	else if (ps.strategy == SIMPLE)
		simple_sort(&ps);
	else if (ps.strategy == MEDIUM)
		return (0);
	else
		return (0);
	/*caso bench seja selecionado,
		imprimir o bench ao final e nao imprimir as operacoes*/
	if (ps.bench_mode == 1)
		print_bench(&ps);
	//	imprimir o stack para testes, remover antes de entregar
	if (ps.a.top || ps.b.top)
	{
	node = ps.a.top;
	while (node->next != NULL)
	{
		printf("%i\n", node->index);
		node = node->next;
	}
	printf("%i\n", node->index);
	}
	if (ps.a.top || ps.b.top)
		free_all(&ps);
	return (0);
}
