/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:55:00 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/25 21:56:18 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;
	t_format	fmt;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parse_format(format, &i, &fmt);
			count += handle_format(fmt, &args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
