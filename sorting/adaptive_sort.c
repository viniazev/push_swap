/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:18:07 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/06 01:08:10 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptative_sort(t_ps *ps)
{
	if (ps->a.size <= 5)
		small_sort(ps);
	else if (ps->bench.disorder < 0.2)
		simple_sort(ps);
	else if (ps->bench.disorder >= 0.2 && ps->bench.disorder < 0.5)
		medium_sort(ps);
	else
		complex_sort(ps);
	return ;
}
