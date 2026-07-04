/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:12:46 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/18 16:49:38 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	total;

	total = 0;
	if (n <= 9)
		total += ft_putchar(n + '0');
	if (n > 9)
	{
		total += ft_putunsigned(n / 10);
		total += ft_putchar((n % 10) + '0');
	}
	return (total);
}
// #include <stdio.h>

// int main(void)
// {
//     unsigned int num = 52515342;
//     int n;
//     n = ft_putunsigned(num);
//     printf("\n%d", n);
//     return (0);
// }