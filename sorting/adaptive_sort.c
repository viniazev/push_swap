/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:18:07 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/13 21:11:01 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptative_sort(t_ps *ps)
{
	if (stack_is_sorted(&ps->a))
		error_exit(ps);
	if (ps->a.size <= 5)
		small_sort(ps);
	else if (ps->bench.disorder < 0.10)
		return ;
	else if (ps->a.size < 150)
		return ;
	else
		return ;
	return ;
}
