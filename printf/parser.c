/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:00:42 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/25 21:56:06 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_format(t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->space = 0;
	f->hash = 0;
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
	f->type = 0;
}

static void	parse_flags(const char *s, int *i, t_format *f)
{
	while (s[*i] == '-' || s[*i] == '0' || s[*i] == ' ' || s[*i] == '#')
	{
		if (s[*i] == '-')
			f->minus = 1;
		if (s[*i] == '0')
			f->zero = 1;
		if (s[*i] == ' ')
			f->space = 1;
		if (s[*i] == '#')
			f->hash = 1;
		(*i)++;
	}
}

static void	parse_width(const char *s, int *i, t_format *f)
{
	while (ft_isdigit(s[*i]))
	{
		f->width = f->width * 10 + (s[*i] - '0');
		(*i)++;
	}
}

static void	parse_precision(const char *s, int *i, t_format *f)
{
	if (s[*i] == '.')
	{
		f->dot = 1;
		(*i)++;
		while (ft_isdigit(s[*i]))
		{
			f->precision = f->precision * 10 + (s[*i] - '0');
			(*i)++;
		}
	}
}

int	parse_format(const char *s, int *i, t_format *fmt)
{
	init_format(fmt);
	parse_flags(s, i, fmt);
	parse_width(s, i, fmt);
	parse_precision(s, i, fmt);
	fmt->type = s[*i];
	return (*i);
}
