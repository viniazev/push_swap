/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:18:07 by vinicius          #+#    #+#             */
/*   Updated: 2026/07/11 17:05:59 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptative_sort(t_ps *ps)
{
	if (ps->a.size <= 5)
		small_sort(ps);
	else if (ps->bench.disorder < 0.10)
		return ;
	else if (ps->a.size < 150)
		return ;
	else
		return ;
}
