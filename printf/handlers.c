/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:57:46 by vinida-s          #+#    #+#             */
/*   Updated: 2026/07/04 22:51:10 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(t_format fmt, va_list *args)
{
	if (fmt.type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (fmt.type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (fmt.type == 'd' || fmt.type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (fmt.type == 'x')
		return (ft_puthex_lower(va_arg(*args, unsigned int)));
	if (fmt.type == 'X')
		return (ft_puthex_upper(va_arg(*args, unsigned int)));
	if (fmt.type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (fmt.type == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (fmt.type == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (fmt.type == 'l')
		return (ft_putlnbr(va_arg(*args, long)));
	return (0);
}
