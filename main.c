/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:33:21 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/09 19:08:22 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (write(1, "Error.", 6));
	if(!parse_args(&ps, argc, argv))
        return (write(2, "Error.", 6));
    if (ps.bench_mode == 1)
        

	return (0);
}
