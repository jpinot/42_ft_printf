/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:52:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/29 13:53:31 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static intmax_t	ft_int_check_length(intmax_t num, t_arg *arg, int conv)
{
	if (arg->lenght == 104104)
		num = (char)num;
	else if (arg->lenght == 108108)
		num = (long long)num;
	else if (arg->lenght == 104)
		num = (short)num;
	else if (arg->lenght == 108)
		num = (long)num;
	else if (arg->lenght == 122)
		num = (size_t)num;
	else if (arg->lenght == 116)
		num = (ptrdiff_t)num;
	else if (arg->lenght == 106)
		num = (intmax_t)num;
	else if (arg->lenght == 0 && conv != 68)
		num = (int)num;
	return (num);
}

int			conv_int(va_list ap, t_arg *arg, int conv)
{
	intmax_t	num;
	t_arg		tmp;

	if (arg->precision)
		arg->pad_zero = 0;
	num = va_arg(ap, intmax_t);
	num = ft_int_check_length(num, arg, conv);
	if (arg->force_positive && num >= 0)
		arg->force_positive = 43;
	if (num < 0)
	{
		arg->force_positive = 45;
		num = -(num);
	}
	tmp = *arg;
	return(ft_printf_putint(num, &tmp));
}
