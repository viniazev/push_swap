/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:48:20 by vinida-s          #+#    #+#             */
/*   Updated: 2026/08/10 22:48:32 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		plus;
	int		space;
	int		hash;
	char	type;
}			t_format;

typedef struct s_map
{
	char	type;
	int		(*f)(va_list *);
}			t_map;

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putnbr(int n);
long		ft_putlnbr(long n);
int			ft_putstr(char *s);
int			ft_puthex_lower(unsigned long n);
int			ft_puthex_upper(unsigned long n);
int			ft_putunsigned(unsigned int n);
void		ft_print_double(double n);
int			ft_putptr(void *ptr);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			parse_format(const char *s, int *i, t_format *fmt);
int			handle_format(t_format fmt, va_list *args);
#endif