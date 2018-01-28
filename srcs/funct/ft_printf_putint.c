/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:31:29 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/28 18:38:26 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_int_write(char *n, t_arg *arg)
{
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0 && arg->pad_zero)
			ft_write('0', arg->filed_width);
		else if (arg->filed_width > 0 && arg->pad_zero == 0)
			ft_write(' ', arg->filed_width);
		if (arg->force_positive)
			write(1, &arg->force_positive, 1);
		if (arg->precision > 0)
			ft_write('0', arg->precision);
		ft_putstr(n);
	}
	else
	{
		if (arg->force_positive)
			write(1, &arg->force_positive, 1);
		if (arg->precision)
			ft_write('0', arg->precision);
		ft_putstr(n);
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
	}
	return (1);
}

int			ft_printf_putint(intmax_t num, t_arg *arg)
{
	char	*n;
	int		len;

	n = ft_printf_itoa(num);
	len = ft_strlen(n);
	arg->precision -= len;
	if (arg->precision > 0)
		arg->filed_width -= (arg->precision + len);
	else if (arg->precision <= 0)
		arg->filed_width -= len;
	if (arg->force_positive)
		arg->filed_width -= 1;
	return (ft_int_write(n, arg));
	return (0);
}
