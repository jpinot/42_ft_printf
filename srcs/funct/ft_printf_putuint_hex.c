/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuint_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:57:42 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/28 14:26:17 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_putuint_hex(uintmax_t num, t_arg *arg, int conv)
{
	char	*n;
	int		len;

	n = ft_printf_itoa_hex(num, conv);
	len = ft_strlen(n);

	if (arg->precision)
		arg->precision -= len;
	arg->filed_width -= (arg->precision + len);
	if (arg->force_positive == 32)
		arg->filed_width -= 1;
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
	return (0);
}
