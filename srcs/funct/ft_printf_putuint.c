/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:32:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 11:12:25 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_uint_write_nonjust(char *n, t_arg *arg)
{
	if (arg->prefix == 'x' || arg->prefix == 'X')
		arg->filed_width -= 2;
	if (arg->filed_width > 0 && arg->pad_zero)
		ft_write('0', arg->filed_width);
	else if (arg->filed_width > 0 && arg->pad_zero == 0)
		ft_write(' ', arg->filed_width);
	if (arg->prefix > 0)
	write(1, "0", 1);
	if (arg->prefix == 'x' || arg->prefix == 'X')
		write(1, &arg->prefix, 1);
	if (arg->force_positive)
		write(1, &arg->force_positive, 1);
	if (arg->precision > 0)
		ft_write('0', arg->precision);
	ft_putstr(n);
	return (1);
}

static int	ft_uint_write_just(char *n, t_arg *arg)
{
	if (arg->prefix == 'x' || arg->prefix == 'X')
		arg->filed_width -= 2;
	if (arg->prefix > 0)
		write(1, "0", 1);
	if (arg->prefix == 'x' || arg->prefix == 'X')
		write(1, &arg->prefix, 1);
	if (arg->force_positive)
		write(1, &arg->force_positive, 1);
	if (arg->precision)
		ft_write('0', arg->precision);
	ft_putstr(n);
	if (arg->filed_width > 0)
		ft_write(' ', arg->filed_width);
	return (1);
}

int			ft_printf_putuint(uintmax_t num, t_arg *arg, int conv)
{
	char	*n;
	int		len;

	if (conv == 'x' || conv == 'X')
		n = ft_printf_itoa_hex(num, conv);
	else if (conv == 'o')
		n = ft_printf_itoa_oct(num);
	else
		n = ft_printf_itoa(num);
	len = ft_strlen(n);
	arg->precision -= len;
	if (arg->precision > 0)
		arg->filed_width -= (arg->precision + len);
	else if (arg->precision <= 0)
		arg->filed_width -= len;
	if (arg->force_positive == 32)
		arg->filed_width -= 1;
	if (arg->precision <= 0 && arg->prefix == '0')
		arg->filed_width -= 1;
	else if (arg->prefix == '0' && arg->precision > 0)
		arg->prefix = 0;
	if (arg->left_justify == 0)
		return (ft_uint_write_nonjust(n, arg));
	else
		return (ft_uint_write_just(n, arg));
	return (0);
}
