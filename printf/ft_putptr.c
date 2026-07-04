/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:14:35 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/25 21:21:51 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	return ((write(1, "0x", 2)) + (ft_puthex_lower((unsigned long)ptr)));
}

// #include <stdio.h>

// int main(void)
// {
//     int     total;
//     int     *ptr;
//     int     *ptr2;

//     total = ft_putptr(ptr);
//     printf("\n%d\n", total);
//     total = ft_putptr(ptr2);
//     printf("\n%d\n", total);
//     return (0);
// }