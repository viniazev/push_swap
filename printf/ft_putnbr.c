/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:08:09 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/05 16:49:07 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	num;
	int			total;

	num = n;
	total = 0;
	if (num < 0)
	{
		total += ft_putchar('-');
		num *= -1;
	}
	if (num <= 9)
		total += ft_putchar(num + '0');
	else
	{
		total += ft_putnbr(num / 10);
		total += ft_putchar((num % 10) + '0');
	}
	return (total);
}

long	ft_putlnbr(long n)
{
	long int	num;
	long		total;

	num = n;
	total = 0;
	if (num < 0)
	{
		total += ft_putchar('-');
		num *= -1;
	}
	if (num <= 9)
		total += ft_putchar(num + '0');
	else
	{
		total += ft_putnbr(num / 10);
		total += ft_putchar((num % 10) + '0');
	}
	return (total);
}

void	ft_print_double(double n)
{
	int	i;
	int	f;

	n *= 100;
	i = (int)n;
	f = (int)((n - i) * 100);
	ft_putnbr(i);
	ft_putchar('.');
	if (f < 10)
		ft_putchar('0');
	ft_putnbr(f);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int n = INT_MAX;
// 	int	num;
// 	long l = LONG_MAX;
// 	long lon;
// 	num = ft_putnbr(n);
// 	printf("\n%d\n", num);
// 	lon = ft_putlnbr(l);
// 	printf("\n%ld\n",lon);
// 	return (0);
// }