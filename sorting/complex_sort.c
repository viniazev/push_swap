/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:17:38 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/14 21:28:42 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex_sort(t_ps *ps)
{
	if (ps->a.size <= 5)
		small_sort(ps);
	//   error_exit(ps);
	else
		return ;
}
